/*
 *  TOPPERS Automotive Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 *      Automotive Kernel
 *
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2004 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 *  Copyright (C) 2004-2006 by Witz Corporation, JAPAN
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
 *	TOPPERS Automotive Kernel 標準インクルードファイル
 *
 *  このインクルードファイルは，カーネルを構成するプログラムのソースファ
 *  イルで必ずインクルードするべき標準インクルードファイルである．
 *
 *  アセンブリ言語のソースファイルやシステムコンフィギュレーションファ
 *  イルからこのファイルをインクルードする時は，_MACRO_ONLY を定義して
 *  おくことで，マクロ定義以外の記述を除くことができる．
 */

#ifndef _OSEK_KERNEL_H_
#define _OSEK_KERNEL_H_

/*
 *  カーネル内部共通のインクルードファイル
 */
#include <kernel.h>

/*
 *  Definition of data types to be used in the kernel
 */
#ifndef _MACRO_ONLY
typedef void		*VP;			/* Pointer to a type whose type is not fixed */
typedef void(*FP)(void);	        /* Program start address (pointer) */
typedef UINT8		Priority;		/* Priority (Task, ISR) */
typedef	UINT8		IPL;			/* Interrupt priority level */
#endif /* _MACRO_ONLY */

/*
 *  Definition of conformance class dependent information
 */
#include <osek_kernel_cc.h>

/*
 *  Definition of general constants
 */
#define	NULL			((void *) 0)		/* Invalid pointer */

/*
 *  Definition of priority value
 */
#define TPRI_MINTASK	((Priority) 0)		/* Minimum task priority */
#define TPRI_MAXTASK	((Priority)(TNUM_PRIORITY - 1))
                                            /* Maximum task priority */
#define TPRI_SCHEDULER	((Priority) 127)	/* Scheduler priority */
#define TPRI_MINISR		((Priority) 128)	/* Minimum interrupt priority */
#define TPRI_NULL		((Priority) UINT8_INVALID)
                                            /* Invalid priority */

/*
 *  Definition of event mask value
 */
#define EVTMASK_NONE	((EventMaskType) 0)	/* No event */

/*
 *  Definition of application mode value
 */
#define APPMODE_NONE	((AppModeType) 0)	/* No mode */

/*
 *  Definition of IPL value
 */
#define IPL_ENA_ALL	((IPL) 0)		/* Allow all interrupts */

/*
 *  Definition of value of running context (callevel)
 */
#define TCL_NULL		((UINT8) 0x00)	/* It can not call a service call */
#define TCL_TASK		((UINT8) 0x01)	/* TASK */
#define TCL_ISR2		((UINT8) 0x02)	/* Category 2 ISR */
#define TCL_ERROR		((UINT8) 0x04)	/* ErrorHook */
#define TCL_PREPOST		((UINT8) 0x08)	/* PreTaskHook，PostTaskHook */
#define TCL_STARTUP		((UINT8) 0x10)	/* StartupHook */
#define TCL_SHUTDOWN	((UINT8) 0x20)	/* ShutdownHook */

/*
 *  Definition of target dependency information
 */
#include <t_config.h>

#ifndef _MACRO_ONLY
/*
 *  Variable for OS execution control（osctl.c）
 */
extern UINT8		callevel;	/* Running context */
extern AppModeType	appmode;	/* Application mode */

/*
 *  Critical section operation function in OS
 */
Inline void	lock_cpu(void);		/* Start critical section */
Inline void	unlock_cpu(void);	/* Critical section end */

Inline void
lock_cpu(void)
{
    disable_int();
}

Inline void
unlock_cpu(void)
{
    enable_int();
}

/*
 *  Declaration for error hook call (osctl.c)
 *
 *  サービスコール内でエラーが発生した場合には，サービスコールへのパラ
 *  メータを _errorhook_par1～3 に設定した後，call_errorhook を呼び出す．
 *  call_errorhook へは，エラーコードとサービスコールのIDを渡す．
 */
extern void	call_errorhook(StatusType ercd, OSServiceIdType svcid);

/*
 *  Declaration for Post Task Hook / Pre-task Hook Call (osctl.c)
 */
extern void	call_posttaskhook(void);
extern void	call_pretaskhook(void);

/*
 *  Initialization of each module (kernel_cfg.c)
 */
extern void	object_initialize(void);

#endif /* _MACRO_ONLY */

/*
 *  Standard extended status
 */
#ifndef BASIC_STATUS
#define EXTENDED_STATUS
#endif /* BASIC_STATUS */

#endif /* _OSEK_KERNEL_H_ */
