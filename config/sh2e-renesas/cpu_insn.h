/*
 *  TOPPERS Automotive Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 *      Automotive Kernel
 *
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2003 by Industrial Technology Institute,
 *                              Miyagi Prefectural Government, JAPAN
 *  Copyright (C) 2006 by Witz Corporation, JAPAN
 *  Copyright (C) 2006 by Hitachi,Ltd., Automotive Systems, JAPAN
 *  Copyright (C) 2006 by Hitachi Information & Control Solutions,Ltd., JAPAN
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
 *  Low level processor operation routine (for SH2)
 */

#ifndef	_CPU_INSN_H_
#define	_CPU_INSN_H_

/*
 *  Inline function prototype declaration
 */
#pragma inline(disable_int)
static void disable_int(void);
#pragma inline(enable_int)
static void enable_int(void);
#pragma inline_asm(nop)
static void nop(void);
#pragma inline_asm(set_sr)
static void set_sr(UINT32 sr);
#pragma inline_asm(current_sr)
static UINT32 current_sr(void);

extern UINT32 int_ena_flag;
extern UINT32 int_ena_level;

/*
 *  Interrupt mask level bit of status register (SR) mask level
 */
#define IPM_MASK_BIT (0x000000f0u)

/*
 *  Changing the current value of the status register (SR)
 */
static void
set_sr(UINT32 sr)
{
    ldc R4, SR
}

/*
 *  Reading the current value of the status register (SR)
 */
static UINT32
current_sr(void)
{
    stc sr, R0
}

/*
 *  All external interrupts prohibited
 */
static void
disable_int(void)
{
    UINT32 int_ena_level_temp;

    /*
     * ここでローカル変数にSRレジスタの値を保存しているのは、
     * SRレジスタの読み出しと実際に割込み禁止の間に割り込みが入った場合に、
     * 割り込みハンドラ内で割り込み禁止を実行するとint_ena_level値が
     * 書き換わってしまうためである
     */

    /* 多重に disable_int がコールされても、int_ena_levelが破壊されないようにする。 */
    if (int_ena_flag != 0) {
        int_ena_level_temp = current_sr() & IPM_MASK_BIT;
        set_sr((current_sr() & ~IPM_MASK_BIT) | (MAX_IPM << 4));
        int_ena_level = int_ena_level_temp;
        int_ena_flag = 0;
    }
}

/*
 *  External interrupt all disable cancel
 */
static void
enable_int(void)
{
    if (int_ena_flag == 0) {
        int_ena_flag = 1;
        set_sr((current_sr() & ~IPM_MASK_BIT) | int_ena_level);
    }
}

/*
 *  Execution of nop instruction
 */
static void nop()
{
    nop
}
#endif /* _CPU_INSN_H_ */
