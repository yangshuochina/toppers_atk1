/*
 *  TOPPERS Automotive Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 *      Automotive Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2003 by Naoki Saito
 *             Nagoya Municipal Industrial Research Institute, JAPAN
 *  Copyright (C) 2004 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 *  Copyright (C) 2004-2006 by Witz Corporation, JAPAN
 * 
 *  上記著作権者は，以下の (1)〜(4) の条件か，Free Software Foundation 
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
 *  プロセッサ依存モジュール（M32C用）
 */


#ifndef	_CPU_CONFIG_H_
#define	_CPU_CONFIG_H_


#ifndef _MACRO_ONLY
#include "cpu_insn.h"
#endif /* _MACRO_ONLY */

#ifndef _MACRO_ONLY
/* インライン関数プロトタイプ宣言	*/
Inline void set_ipl(UINT8 ipl);
Inline UINT8 current_ipl(void);


/*
 *  本OSカーネルでは割込み制御をIフラグ及びIPLの双方を用いて行う
 *  ことを前提とする．本CPUでは上記条件を満たしているため不足機能を
 *  ソフトウェアで補う必要はない．
 */

/*
 *  割込み優先度レベル設定
 */
Inline void set_ipl(UINT8 ipl)
{
	volatile UINT16 flg_reg;
	UINT16 flg_temp;
	asm("	stc flg, $$[FB]", flg_reg);
	flg_reg &= (UINT16)0x00FF;
	flg_temp = (UINT16)ipl;
	flg_temp <<= 12;
	flg_reg |= flg_temp;
	asm("	ldc $$[FB], flg", flg_reg);
}


/*
 *  割込み優先度レベル取得
 */
Inline UINT8 current_ipl(void)
{
	volatile UINT16 flg_reg;
	asm("	stc flg, $$[FB]", flg_reg);
	flg_reg >>= 12;
	return((UINT8)flg_reg);
}


/*参照プロトタイプ*/
/*
 *  プロセッサ依存の初期化(cpu_config.c)
 */
extern void	cpu_initialize(void);

/*
 *  プロセッサ依存の終了時処理(cpu_config.c)
 */
extern void	cpu_terminate(void);

#define DEFINE_CTXB(tnum) ¥
FP tcxb_pc[tnum]; ¥
VP tcxb_sp[tnum];

extern FP tcxb_pc[];
extern VP tcxb_sp[];

/*
 *  ディスパッチ周りのアセンブラ関数プロトタイプ宣言
 *  (activate_rは共通部から直接参照しないためここには記載しない)
 */
extern void  dispatch(void);
extern void  exit_and_dispatch(void);
extern void  start_dispatch(void);


/*
 *  ISR1生成マクロ
 *
 *  ISR1の全ての処理をユーザが記述する場合は，cpu_defs.h にある無効化マクロ
 *  「OMIT_ISR1_ENTRY」の定義を有効にすること．
 */

/* ベクタテーブルからの外部参照宣言生成マクロ	*/
/*
 *  割込み入り口実態とベクタテーブルを別ファイルに生成する場合に必要となる．
 *  現状M32Cの全てのシステムで，同一ファイル出力となっているため本マクロは
 *  使用されたいない可能性もある．
 *  別ファイル出力を行う場合を考慮し，記載は残しておく．
 */
#if defined(OMIT_ISR1_ENTRY)
#define	ISR1_EXTERNAL(isr)		asm("	.glb	_" #isr )
#else	/* OMIT_ISR1_ENTRY	*/
#define	ISR1_EXTERNAL(isr)		asm("	.glb	_" #isr "_entry")
#endif	/* OMIT_ISR1_ENTRY	*/

/* ベクタテーブル登録シンボル生成マクロ	*/
#if defined(OMIT_ISR1_ENTRY)
#define	ISR1_SYMBOL(isr)		asm("	.lword	_" #isr )
#else	/* OMIT_ISR1_ENTRY	*/
#define	ISR1_SYMBOL(isr)		asm("	.lword	_" #isr "_entry")
#endif	/* OMIT_ISR1_ENTRY	*/

/* 入口処理の生成マクロ	*/
#if defined(OMIT_ISR1_ENTRY)
#define ISR1_ENTRY(isr)
#else	/* OMIT_ISR1_ENTRY	*/
#define ISR1_ENTRY(isr)¥
asm("	.glb _" #isr "					");¥
asm("	.section program, code, align	");¥
asm("_" #isr "_entry:					");¥
asm("	push.w	r0				; スクラッチレジスタをタスクスタックへ退避");¥
asm("	jsr	_" #isr );¥
asm("	pop.w	r0				; スクラッチレジスタをタスクスタックから復帰");¥
asm("	reit	");
#endif	/* OMIT_ISR1_ENTRY	*/


/*
 *  ISR2生成マクロ
 */

/* ベクタテーブルからの外部参照宣言生成マクロ	*/
/*
 *  割込み入り口実態とベクタテーブルを別ファイルに生成する場合に必要となる．
 *  現状M32Cの全てのシステムで，同一ファイル出力となっているため本マクロは
 *  使用されたいない可能性もある．
 *  別ファイル出力を行う場合を考慮し，記載は残しておく．
 */
#define	ISR2_EXTERNAL(isr)		asm("	.glb	_" #isr "_entry")

/* ベクタテーブル登録シンボル生成マクロ	*/
#define	ISR2_SYMBOL(isr)		asm("	.lword	_" #isr "_entry")

/* 入口処理の生成マクロ	*/
#define ISR2_ENTRY(isr, isrid)¥
asm("	.glb _runisr					");¥
asm("	.glb _ISRMain" #isr "			");¥
asm("	.glb _interrupt					");¥
asm("	.section program, code, align	");¥
asm("_" #isr "_entry:					");¥
asm("	pushm	r0,r1,r3,a0				; レジスタをタスクスタックへ退避");¥
asm("	mov.l	#_ISRMain" #isr ", a0	; 割込みハンドラのアドレスをa0へ");¥
asm("	mov.b	_runisr, r0l			; 前の実行中割込みIDを保持");¥
asm("	mov.b	#" #isrid ", _runisr	; 今回の実行中割込みIDを設定");¥
asm("	jmp	_interrupt					; 割込み処理ルーチン後半へ	");


/*
 *  未使用割込み生成マクロ
 */

/* ベクタテーブルからの外部参照宣言生成マクロ	*/
#define	UNUSED_INT_EXTERNAL()	asm("	.glb	_unused_interrupt")

/* ベクタテーブル登録シンボル生成マクロ	*/
#define	UNUSED_INT_SYMBOL()		asm("	.lword	_unused_interrupt")


/*
 *  フックルーチンNULLシンボル生成マクロ
 */
#define	NULL_ERRORHOOK ¥
asm(".glb	$ErrorHook");¥
asm("$ErrorHook .equ 0");

#define	NULL_STARTUPHOOK ¥
asm(".glb	_StartupHook"); ¥
asm("_StartupHook .equ 0");

#define	NULL_SHUTDOWNHOOK ¥
asm(".glb	$ShutdownHook"); ¥
asm("$ShutdownHook .equ 0");

#define	NULL_PRETASKHOOK ¥
asm(".glb	_PreTaskHook"); ¥
asm("_PreTaskHook .equ 0");

#define	NULL_POSTTASKHOOK ¥
asm(".glb	_PostTaskHook"); ¥
asm("_PostTaskHook .equ 0");


#endif /* _MACRO_ONLY */
#endif	/* _CPU_CONFIG_H_	*/

