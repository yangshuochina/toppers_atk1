/*
 *  TOPPERS Automotive Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 *      Automotive Kernel
 *
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2004 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 *  Copyright (C) 2004-2007 by Witz Corporation, JAPAN
 *
 *  上記著作権者は，以下の (1)～(4) の条件か，Free Software Foundation
 *  によって公表されている GNU General Public License の Version 2 に記
 *  述されている条件を満たす場合に限り，本ソフトウェア（本ソフトウェア
 *  を改変したものを含む．以下同じ）を使用・複製・改変・再配布（以下，
 *  利用と呼ぶ）することを無償で許諾する．
 *  (1) 本ソフトウェアをソースコードの形で利用する場合には，上記の著作
 *      権表示，この利用条件および下記の無保証規定が，そのままの形でソー
 *      スコード中に含まれていること．
 *  (2) 本ソフトウェアを，ライブラリ形式など，他のソフトウェア開発に使
 *      用できる形で再配布する場合には，再配布に伴うドキュメント（利用
 *      者マニュアルなど）に，上記の著作権表示，この利用条件および下記
 *      の無保証規定を掲載すること．
 *  (3) 本ソフトウェアを，機器に組み込むなど，他のソフトウェア開発に使
 *      用できない形で再配布する場合には，次のいずれかの条件を満たすこ
 *      と．
 *    (a) 再配布に伴うドキュメント（利用者マニュアルなど）に，上記の著
 *        作権表示，この利用条件および下記の無保証規定を掲載すること．
 *    (b) 再配布の形態を，別に定める方法によって，TOPPERSプロジェクトに
 *        報告すること．
 *  (4) 本ソフトウェアの利用により直接的または間接的に生じるいかなる損
 *      害からも，上記著作権者およびTOPPERSプロジェクトを免責すること．
 *
 *  本ソフトウェアは，無保証で提供されているものである．上記著作権者お
 *  よびTOPPERSプロジェクトは，本ソフトウェアに関して，その適用可能性も
 *  含めて，いかなる保証も行わない．また，本ソフトウェアの利用により直
 *  接的または間接的に生じたいかなる損害に関しても，その責任を負わない．
 *
 */

/*
 *	Interrupt management function (ECC 2)
 */

#include "osek_kernel.h"
#include "interrupt.h"

/*
 *  Running ISR (category 2)
 */
IsrType		runisr;

/*
 *  Interrupt management function Definition of internal variables
 */

/*
 *  Number of nesting of SuspendAllInterrupts
 *
 *  This variable may be changed only with disable_int().
 */
UINT8		sus_all_cnt;

/*
 *  Number of nesting of SuspendOSInterrupts
 *
 *  This variable may be changed only when set_ipl (ipl_maxisr2) is set.
 *  Even if you set_ipl (ipl_maxisr 2), the category 1 ISR comes in,
 *  but if you return it after returning to the original value,
 *  there is no problem.
 */
static UINT8	sus_os_cnt;

/*
 *  Interrupt priority level before SuspendOSInterrupts
 *
 *  This variable may be changed only when set_ipl (ipl_maxisr2) is set.
 *  Also, keep sus_os_cnt non-zero while using this variable.
 *  Even if you set_ipl (ipl_maxisr2), the ISR of category 1 comes in,
 *  but by setting sus_os_cnt to non-zero, this variable will not be changed
 *  in category 1 ISR.
 */
static IPL	saved_ipl;

/*
 *  Execution context before SuspendAllInterrupts / SuspendOSInterrupts
 *
 *  This variable may be changed only with disable_int or set_ipl (ipl_maxisr2).
 *  Also, keep sus_all_cnt or sus_os_cnt non-zero while using this variable.
 *  Even with set_ipl (ipl_maxisr2), the ISR of category 1 will come in,
 *  but if sus_os_cnt is non-zero, this variable will not be changed
 *  in Category 1 ISR.
 */
static UINT8	saved_callevel;

/*
 *  Initialization of interrupt management function
 */
void
interrupt_initialize(void)
{
    IsrType		isrid;

    runisr = ISRID_NULL;
    isrid = ISRID_NULL;
    sus_all_cnt = 0u;
    sus_os_cnt = 0u;

    for (isrid = 0; isrid < tnum_isr2; isrid++) {
        isrcb_lastres[isrid] = 0u;
    }
}

/*
 *  Disable all interrupts (high-speed simplified version)
 */
void
DisableAllInterrupts(void)
{
    LOG_DISINT_ENTER();
    disable_int();
    LOG_DISINT_LEAVE();
}

/*
 *  Enable all interrupts (high-speed simplified version)
 */
void
EnableAllInterrupts(void)
{
    LOG_ENAINT_ENTER();
    enable_int();
    LOG_ENAINT_LEAVE();
}

/*
 *  Disable all interrupts
 */
void
SuspendAllInterrupts(void)
{
    LOG_SUSALL_ENTER();
    if (sus_all_cnt == UINT8_INVALID) {
        /*
         *  SuspendAllInterrupts を繰り返し呼んだ場合の対策
         *  （何もせずに抜ける）
         */
    }
    else if (sus_all_cnt == 0) {
        disable_int();
        sus_all_cnt++;
        if (sus_os_cnt == 0) {
            saved_callevel = callevel;
            callevel = TCL_NULL;
        }
    }
    else {
        sus_all_cnt++;
    }
    LOG_SUSALL_LEAVE();
}

/*
 *  Allow all interrupts
 */
void
ResumeAllInterrupts(void)
{
    LOG_RSMALL_ENTER();
    if (sus_all_cnt == 0) {
        /*
         *  SuspendAllInterrupts を呼ばずに，ResumeAllInterrupts
         *  を呼んだ場合の対策（何もせずに抜ける）
         */
    }
    else if (sus_all_cnt == 1) {
        if (sus_os_cnt == 0) {
            callevel = saved_callevel;
        }
        sus_all_cnt--;
        enable_int();
    }
    else {
        sus_all_cnt--;
    }
    LOG_RSMALL_LEAVE();
}

/*
 *  Category 2 interrupt prohibition
 */
void
SuspendOSInterrupts(void)
{
    IPL	ipl;

    LOG_SUSOSI_ENTER();
    if (sus_os_cnt == UINT8_INVALID) {
        /*
         *  SuspendOSInterrupts を繰り返し呼んだ場合の対策
         *  （何もせずに抜ける）
         */
    }
    else if (sus_os_cnt == 0) {
        ipl = current_ipl();

        /*
         *  すでに ISR2 が禁止されている時は何もしない．
         */
        if (ipl < ipl_maxisr2) {
            set_ipl(ipl_maxisr2);
        }
        sus_os_cnt++;
        saved_ipl = ipl;
        if (sus_all_cnt == 0) {
            saved_callevel = callevel;
            callevel = TCL_NULL;
        }
    }
    else {
        sus_os_cnt++;
    }
    LOG_SUSOSI_LEAVE();
}

/*
 *  Allow Category 2 interrupt
 */
void
ResumeOSInterrupts(void)
{
    LOG_RSMOSI_ENTER();
    if (sus_os_cnt == 0) {
        /*
         *  SuspendOSInterrupts を呼ばずに，ResumeOSInterrupts
         *  を呼んだ場合の対策（何もせずに抜ける）
         */
    }
    else if (sus_os_cnt == 1) {
        if (sus_all_cnt == 0) {
            callevel = saved_callevel;
        }
        sus_os_cnt--;

        /*
         *  もともと ISR2 が禁止されていた時は何もしない．
         */
        if (saved_ipl < ipl_maxisr2) {
            set_ipl(saved_ipl);
        }
    }
    else {
        sus_os_cnt--;
    }
    LOG_RSMOSI_LEAVE();
}
