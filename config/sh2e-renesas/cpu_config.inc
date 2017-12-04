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
;*  ��L���쌠�҂́C�ȉ��� (1)�`(4) �̏������CFree Software Foundation 
;*  �ɂ���Č��\����Ă��� GNU General Public License �� Version 2 �ɋL
;*  �q����Ă�������𖞂����ꍇ�Ɍ���C�{�\�t�g�E�F�A�i�{�\�t�g�E�F�A
;*  �����ς������̂��܂ށD�ȉ������j���g�p�E�����E���ρE�Ĕz�z�i�ȉ��C
;*  ���p�ƌĂԁj���邱�Ƃ𖳏��ŋ�������D
;*  (1) �{�\�t�g�E�F�A���\�[�X�R�[�h�̌`�ŗ��p����ꍇ�ɂ́C��L�̒���
;*      ���\���C���̗��p��������щ��L�̖��ۏ؋K�肪�C���̂܂܂̌`�Ń\�[
;*      �X�R�[�h���Ɋ܂܂�Ă��邱�ƁD
;*  (2) �{�\�t�g�E�F�A���C���C�u�����`���ȂǁC���̃\�t�g�E�F�A�J���Ɏg
;*      �p�ł���`�ōĔz�z����ꍇ�ɂ́C�Ĕz�z�ɔ����h�L�������g�i���p
;*      �҃}�j���A���Ȃǁj�ɁC��L�̒��쌠�\���C���̗��p��������щ��L
;*      �̖��ۏ؋K����f�ڂ��邱�ƁD
;*  (3) �{�\�t�g�E�F�A���C�@��ɑg�ݍ��ނȂǁC���̃\�t�g�E�F�A�J���Ɏg
;*      �p�ł��Ȃ��`�ōĔz�z����ꍇ�ɂ́C���̂����ꂩ�̏����𖞂�����
;*      �ƁD
;*    (a) �Ĕz�z�ɔ����h�L�������g�i���p�҃}�j���A���Ȃǁj�ɁC��L�̒�
;*        �쌠�\���C���̗��p��������щ��L�̖��ۏ؋K����f�ڂ��邱�ƁD
;*    (b) �Ĕz�z�̌`�Ԃ��C�ʂɒ�߂���@�ɂ���āCTOPPERS�v���W�F�N�g��
;*        �񍐂��邱�ƁD
;*  (4) �{�\�t�g�E�F�A�̗��p�ɂ�蒼�ړI�܂��͊ԐړI�ɐ����邢���Ȃ鑹
;*      �Q������C��L���쌠�҂����TOPPERS�v���W�F�N�g��Ɛӂ��邱�ƁD
;* 
;*  �{�\�t�g�E�F�A�́C���ۏ؂Œ񋟂���Ă�����̂ł���D��L���쌠�҂�
;*  ���TOPPERS�v���W�F�N�g�́C�{�\�t�g�E�F�A�Ɋւ��āC���̓K�p�\����
;*  �܂߂āC�����Ȃ�ۏ؂��s��Ȃ��D�܂��C�{�\�t�g�E�F�A�̗��p�ɂ�蒼
;*  �ړI�܂��͊ԐړI�ɐ����������Ȃ鑹�Q�Ɋւ��Ă��C���̐ӔC�𕉂�Ȃ��D
;* 
;*
 
 .AIFDEF	_CPU_CONFIG_INC_
 .AELSE
_CPU_CONFIG_INC_:	.DEFINE	""


MAX_IPM:	.EQU	15				; ���֎��� SR �ɐݒ肷�銄���݃}�X�N���x��
ENABLE_COMMON_STACK:	.ASSIGNA 1	; ��{�^�X�N�ŃX�^�b�N�����L����
									; 0: ���L���Ȃ�
									; 1: ��{�^�X�N�ŃX�^�b�N�����L����
ENABLE_BCC_DEFINES:		.ASSIGNA 0	; BCC �ݒ莞�Ƀ_�~�[�ϐ����`����B
									; 0: ECC �ݒ�
									; 1: BCC �ݒ�
									
;
;  �O���Q�Ɛ錾�����}�N��
;
 .AIFDEF OMIT_ISR1_ENTRY
 	.MACRO	ISR1_EXTERNAL	isr
 	.GLOBAL	_\isr
 	.ENDM
 .AELSE
	.MACRO	ISR1_EXTERNAL	isr
	.GLOBAL	_\isr'_entry
 	.ENDM
 .AENDI
	
;
; �x�N�^�e�[�u���o�^�V���{�������}�N��
;
 .AIFDEF OMIT_ISR1_ENTRY
 	.MACRO	ISR1_SYMBOL	isr
 	.DATA.L	_\isr
 	.ENDM
 .AELSE
	.MACRO	ISR1_SYMBOL	isr
	.DATA.L	_\isr'_entry
 	.ENDM
 .AENDI

;
;	�O���Q�Ɛ錾�����}�N��
;
 	.MACRO	ISR2_EXTERNAL	isr
	.GLOBAL	_\isr'_entry
 	.ENDM

;
; �x�N�^�e�[�u���o�^�V���{�������}�N��
;
	.MACRO	ISR2_SYMBOL	isr
	.DATA.L	_\isr'_entry
 	.ENDM

;
;  ���g�p�����ݐ����}�N��
;

; �x�N�^�e�[�u������̊O���Q�Ɛ錾�����}�N��
	.MACRO	UNUSED_INT_EXTERNAL
	.IMPORT _unused_interrupt
 	.ENDM


; �x�N�^�e�[�u���o�^�V���{�������}�N��
	.MACRO	UNUSED_INT_SYMBOL
	.DATA.L	_unused_interrupt
	.ENDM
	
; /* ISR1 ���������̐����}�N��	*/
 .AIFDEF OMIT_ISR1_ENTRY
 	.MACRO	ISR1_ENTRY	isr
 	.ENDM
 .AELSE
	.MACRO	ISR1_ENTRY	isr
	.IMPORT _\isr
	.SECTION	P,CODE,ALIGN=4 
	
_\isr'_entry:
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
	mov.l	_\isr'_adr , r0	
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
_\isr'_adr:	
	.DATA.L	_\isr'
	.ENDM
 .AENDI		; OMIT_ISR1_ENTRY

; /* ISR2 ���������̐����}�N��	*/

	.MACRO	ISR2_ENTRY	isr, isrid
    .SECTION    P,CODE,ALIGN=4 

	.IMPORT _ISRMain\isr'
	
_\isr'_entry:
	mov.l	r0 , @-r15
	mov.l	r1 , @-r15
	mov.l	r2 , @-r15
	stc		sr , r2
	mov.l	_MAX_IPM_\isr'_adr, r1	
	ldc 	r1 , sr
	mov.l	r3 , @-r15
	mov.l	_runisr_\isr'_adr, r3
	mov.b	@r3 , r1
	mov		#\isrid' , r0
	mov.b	r0 , @r3
	mov.l	_ISRMain\isr'_adr , r0
	mov.l	_interrupt_\isr'_adr , r3
	jmp	@r3
	nop
      	
	.ALIGN	4
_interrupt_\isr'_adr:
	.DATA.L	_interrupt
_runisr_\isr'_adr:
	.DATA.L	_runisr
_ISRMain\isr'_adr:
	.DATA.L	_ISRMain\isr'
_MAX_IPM_\isr'_adr:
	.DATA.L	MAX_IPM << 4
	.ENDM

;  �t�b�N���[�`��NULL�V���{�������}�N��

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