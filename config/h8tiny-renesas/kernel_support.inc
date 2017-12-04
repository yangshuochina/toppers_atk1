;
;  TOPPERS Automotive Kernel
;      Toyohashi Open Platform for Embedded Real-Time Systems
;      Automotive Kernel
; 
;  Copyright (C) 2006 by Embedded and Real-Time Systems Laboratory
;              Graduate School of Information Science, Nagoya Univ., JAPAN    
; 
;  上記著作権者は，以下の (1)～(4) の条件か，Free Software Foundation 
;  によって公表されている GNU General Public License の Version 2 に記
;  述されている条件を満たす場合に限り，本ソフトウェア（本ソフトウェア
;  を改変したものを含む．以下同じ）を使用・複製・改変・再配布（以下，
;  利用と呼ぶ）することを無償で許諾する．
;  (1) 本ソフトウェアをソースコードの形で利用する場合には，上記の著作
;      権表示，この利用条件および下記の無保証規定が，そのままの形でソー
;      スコード中に含まれていること．
;  (2) 本ソフトウェアを，ライブラリ形式など，他のソフトウェア開発に使
;      用できる形で再配布する場合には，再配布に伴うドキュメント（利用
;      者マニュアルなど）に，上記の著作権表示，この利用条件および下記
;      の無保証規定を掲載すること．
;  (3) 本ソフトウェアを，機器に組み込むなど，他のソフトウェア開発に使
;      用できない形で再配布する場合には，次のいずれかの条件を満たすこ
;      と．
;    (a) 再配布に伴うドキュメント（利用者マニュアルなど）に，上記の著
;        作権表示，この利用条件および下記の無保証規定を掲載すること．
;    (b) 再配布の形態を，別に定める方法によって，TOPPERSプロジェクトに
;        報告すること．
;  (4) 本ソフトウェアの利用により直接的または間接的に生じるいかなる損
;      害からも，上記著作者およびTOPPERSプロジェクトを免責すること．
; 
;  本ソフトウェアは，無保証で提供されているものである．上記著作権者お
;  よびTOPPERSプロジェクトは，本ソフトウェアに関して，その適用可能性も
;  含めて，いかなる保証も行わない．また，本ソフトウェアの利用により直
;  接的または間接的に生じたいかなる損害に関しても，その責任を負わない．
;

;
; SGにより生成されるベクターテーブルファイル(kernel_support.src)から
; インクルードされるファイル
;

 .AIFDEF _KERNEL_SUPPORT_INC_
 .AELSE

_KERNEL_SUPPORT_INC_: .DEFINE ""

	.INCLUDE	"cpu_defs.inc"
	.IMPORT	_start
	.IMPORT _unused_interrupt
	.IMPORT _common_interrupt_process

;
;   ベクタテーブル登録内容生成マクロ
;

 .MACRO	ISR1_SYMBOL ISR
	.data.w		_\ISR'_entry
 .ENDM


 .MACRO	ISR2_SYMBOL ISR
	.data.w		_\ISR'_entry
 .ENDM

 .MACRO	UNUSED_INT_SYMBOL
	.data.w		_unused_interrupt
 .ENDM


;
;  割込みハンドラの入出口の生成マクロ
;

;
;  ISR1用
;  Renesas製のコンパイラの#pragram interrupt を用いるとベクターテーブル
;  を作成してしまうため、ISR1もカーネル側で入出口ルーチンを用意する。
;  スクラッチレジスタはer0,er1

 .MACRO ISR1_ENTRY ISR
	.GLOBAL _\ISR'_entry
	.IMPORT _\ISR'
_\ISR'_entry:
	push.l	er0
	push.l	er1
	jsr		@_\ISR'
	pop.l	er1
	pop.l	er0
	rte
 .ENDM 	


;
; ISR2用
;

 .MACRO ISR2_ENTRY ISR, ISRID
	.IMPORT  _ISRMain\ISR'
_\ISR'_entry:
	push.l	er0
	push.l	er1
	push.l	er2
	push.l	er3
	mov.w	#_ISRMain\ISR',r3			; 割込みのハンドラのアドレスをr3へ
	mov.b	#\ISRID', r1l				; 発生した割込みのIDをr0lに
	jmp		@_common_interrupt_process
 .ENDM

;
; フックルーチンNULLシンボル生成マクロ
;	

 .MACRO	NULL_ERRORHOOK
	.global		_ErrorHook
	_ErrorHook:		.equ	0
 .ENDM

 .MACRO	NULL_STARTUPHOOK
	.global		_StartupHook
	_StartupHook:	.equ	0
 .ENDM

 .MACRO	NULL_SHUTDOWNHOOK
	.global		_ShutdownHook
	_ShutdownHook:	.equ	0
 .ENDM

 .MACRO	NULL_PRETASKHOOK
	.global		_PreTaskHook
	_PreTaskHook:	.equ	0
 .ENDM

 .MACRO	NULL_POSTTASKHOOK
	.global		_PostTaskHook
	_PostTaskHook:	.equ	0
 .ENDM


 .AENDI ; _KERNEL_SUPPORT_INC_
