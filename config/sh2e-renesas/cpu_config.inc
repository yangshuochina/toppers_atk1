;*
;*  TOPPERS Automotive Kernel
;*      Toyohashi Open Platform for Embedded Real-Time Systems
;*      Automotive Kernel
;* 
;*  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
;*                              Toyohashi Univ. of Technology, JAPAN
;*  Copyright (C) 2004 by Embedded and Real-Time Systems Laboratory
;*              Graduate School of Information Science, Nagoya Univ., JAPAN
;*  Copyright (C) 2006 by Witz Corporation, JAPAN
;*  Copyright (C) 2006-2008 by Hitachi,Ltd., Automotive Systems, JAPAN
;*  Copyright (C) 2006-2008 by Hitachi Information & Control Solutions,Ltd., JAPAN
;* 
;*  上記著作権者は，以下の (1)〜(4) の条件か，Free Software Foundation 
;*  によって公表されている GNU General Public License の Version 2 に記
;*  述されている条件を満たす場合に限り，本ソフトウェア（本ソフトウェア
;*  を改変したものを含む．以下同じ）を使用・複製・改変・再配布（以下，
;*  利用と呼ぶ）することを無償で許諾する．
;*  (1) 本ソフトウェアをソースコードの形で利用する場合には，上記の著作
;*      権表示，この利用条件および下記の無保証規定が，そのままの形でソー
;*      スコード中に含まれていること．
;*  (2) 本ソフトウェアを，ライブラリ形式など，他のソフトウェア開発に使
;*      用できる形で再配布する場合には，再配布に伴うドキュメント（利用
;*      者マニュアルなど）に，上記の著作権表示，この利用条件および下記
;*      の無保証規定を掲載すること．
;*  (3) 本ソフトウェアを，機器に組み込むなど，他のソフトウェア開発に使
;*      用できない形で再配布する場合には，次のいずれかの条件を満たすこ
;*      と．
;*    (a) 再配布に伴うドキュメント（利用者マニュアルなど）に，上記の著
;*        作権表示，この利用条件および下記の無保証規定を掲載すること．
;*    (b) 再配布の形態を，別に定める方法によって，TOPPERSプロジェクトに
;*        報告すること．
;*  (4) 本ソフトウェアの利用により直接的または間接的に生じるいかなる損
;*      害からも，上記著作権者およびTOPPERSプロジェクトを免責すること．
;* 
;*  本ソフトウェアは，無保証で提供されているものである．上記著作権者お
;*  よびTOPPERSプロジェクトは，本ソフトウェアに関して，その適用可能性も
;*  含めて，いかなる保証も行わない．また，本ソフトウェアの利用により直
;*  接的または間接的に生じたいかなる損害に関しても，その責任を負わない．
;* 
;*
 
 .AIFDEF	_CPU_CONFIG_INC_
 .AELSE
_CPU_CONFIG_INC_:	.DEFINE	""


MAX_IPM:	.EQU	15				; 割禁時に SR に設定する割込みマスクレベル
ENABLE_COMMON_STACK:	.ASSIGNA 1	; 基本タスクでスタックを共有する
									; 0: 共有しない
									; 1: 基本タスクでスタックを共有する
ENABLE_BCC_DEFINES:		.ASSIGNA 0	; BCC 設定時にダミー変数を定義する。
									; 0: ECC 設定
									; 1: BCC 設定
									
;
;  外部参照宣言生成マクロ
;
 .AIFDEF OMIT_ISR1_ENTRY
 	.MACRO	ISR1_EXTERNAL	isr
 	.GLOBAL	_¥isr
 	.ENDM
 .AELSE
	.MACRO	ISR1_EXTERNAL	isr
	.GLOBAL	_¥isr'_entry
 	.ENDM
 .AENDI
	
;
; ベクタテーブル登録シンボル生成マクロ
;
 .AIFDEF OMIT_ISR1_ENTRY
 	.MACRO	ISR1_SYMBOL	isr
 	.DATA.L	_¥isr
 	.ENDM
 .AELSE
	.MACRO	ISR1_SYMBOL	isr
	.DATA.L	_¥isr'_entry
 	.ENDM
 .AENDI

;
;	外部参照宣言生成マクロ
;
 	.MACRO	ISR2_EXTERNAL	isr
	.GLOBAL	_¥isr'_entry
 	.ENDM

;
; ベクタテーブル登録シンボル生成マクロ
;
	.MACRO	ISR2_SYMBOL	isr
	.DATA.L	_¥isr'_entry
 	.ENDM

;
;  未使用割込み生成マクロ
;

; ベクタテーブルからの外部参照宣言生成マクロ
	.MACRO	UNUSED_INT_EXTERNAL
	.IMPORT _unused_interrupt
 	.ENDM


; ベクタテーブル登録シンボル生成マクロ
	.MACRO	UNUSED_INT_SYMBOL
	.DATA.L	_unused_interrupt
	.ENDM
	
; /* ISR1 入口処理の生成マクロ	*/
 .AIFDEF OMIT_ISR1_ENTRY
 	.MACRO	ISR1_ENTRY	isr
 	.ENDM
 .AELSE
	.MACRO	ISR1_ENTRY	isr
	.IMPORT _¥isr
	.SECTION	P,CODE,ALIGN=4 
	
_¥isr'_entry:
	mov.l	r0 , @-r15	
	mov.l	r1 , @-r15	
	mov.l	r2 , @-r15	
	mov.l	r3 , @-r15	
	mov.l	r4 , @-r15	
	mov.l	r5 , @-r15	
	mov.l	r6 , @-r15	
	mov.l	r7 , @-r15	
	sts.l	pr , @-r15	
	sts.l	macl , @-r15	
	sts.l	mach , @-r15	
	stc.l	gbr , @-r15	
	mov.l	_¥isr'_adr , r0	
	jsr @r0	
	nop	
	ldc.l	@r15+ , gbr	
	lds.l	@r15+ , mach	
	lds.l	@r15+ , macl	
	lds.l	@r15+ , pr	
	mov.l	@r15+ , r7	
	mov.l	@r15+ , r6	
	mov.l	@r15+ , r5	
	mov.l	@r15+ , r4	
	mov.l	@r15+ , r3	
	mov.l	@r15+ , r2	
	mov.l	@r15+ , r1	
	mov.l	@r15+ , r0	
	rte		
	nop	
	.ALIGN	4	
_¥isr'_adr:	
	.DATA.L	_¥isr'
	.ENDM
 .AENDI		; OMIT_ISR1_ENTRY

; /* ISR2 入口処理の生成マクロ	*/

	.MACRO	ISR2_ENTRY	isr, isrid
    .SECTION    P,CODE,ALIGN=4 

	.IMPORT _ISRMain¥isr'
	
_¥isr'_entry:
	mov.l	r0 , @-r15
	mov.l	r1 , @-r15
	mov.l	r2 , @-r15
	stc		sr , r2
	mov.l	_MAX_IPM_¥isr'_adr, r1	
	ldc 	r1 , sr
	mov.l	r3 , @-r15
	mov.l	_runisr_¥isr'_adr, r3
	mov.b	@r3 , r1
	mov		#¥isrid' , r0
	mov.b	r0 , @r3
	mov.l	_ISRMain¥isr'_adr , r0
	mov.l	_interrupt_¥isr'_adr , r3
	jmp	@r3
	nop
      	
	.ALIGN	4
_interrupt_¥isr'_adr:
	.DATA.L	_interrupt
_runisr_¥isr'_adr:
	.DATA.L	_runisr
_ISRMain¥isr'_adr:
	.DATA.L	_ISRMain¥isr'
_MAX_IPM_¥isr'_adr:
	.DATA.L	MAX_IPM << 4
	.ENDM

;  フックルーチンNULLシンボル生成マクロ

	.MACRO	NULL_ERRORHOOK
	.EXPORT	_ErrorHook
_ErrorHook:	.EQU	0
	.ENDM
	
	.MACRO	NULL_STARTUPHOOK
	.EXPORT	_StartupHook
_StartupHook:	.EQU	0
	.ENDM

	.MACRO	NULL_SHUTDOWNHOOK
	.EXPORT	_ShutdownHook
_ShutdownHook:	.EQU	0
	.ENDM

	.MACRO	NULL_PRETASKHOOK
	.EXPORT	_PreTaskHook
_PreTaskHook:	.EQU	0
	.ENDM

	.MACRO	NULL_POSTTASKHOOK
	.EXPORT	_PostTaskHook
_PostTaskHook:	.EQU	0
	.ENDM

 .AENDI		; _CPU_CONFIG_INC_
