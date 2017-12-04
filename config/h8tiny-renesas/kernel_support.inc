;
;  TOPPERS Automotive Kernel
;      Toyohashi Open Platform for Embedded Real-Time Systems
;      Automotive Kernel
; 
;  Copyright (C) 2006 by Embedded and Real-Time Systems Laboratory
;              Graduate School of Information Science, Nagoya Univ., JAPAN    
; 
;  ��L���쌠�҂́C�ȉ��� (1)�`(4) �̏������CFree Software Foundation 
;  �ɂ���Č��\����Ă��� GNU General Public License �� Version 2 �ɋL
;  �q����Ă�������𖞂����ꍇ�Ɍ���C�{�\�t�g�E�F�A�i�{�\�t�g�E�F�A
;  �����ς������̂��܂ށD�ȉ������j���g�p�E�����E���ρE�Ĕz�z�i�ȉ��C
;  ���p�ƌĂԁj���邱�Ƃ𖳏��ŋ�������D
;  (1) �{�\�t�g�E�F�A���\�[�X�R�[�h�̌`�ŗ��p����ꍇ�ɂ́C��L�̒���
;      ���\���C���̗��p��������щ��L�̖��ۏ؋K�肪�C���̂܂܂̌`�Ń\�[
;      �X�R�[�h���Ɋ܂܂�Ă��邱�ƁD
;  (2) �{�\�t�g�E�F�A���C���C�u�����`���ȂǁC���̃\�t�g�E�F�A�J���Ɏg
;      �p�ł���`�ōĔz�z����ꍇ�ɂ́C�Ĕz�z�ɔ����h�L�������g�i���p
;      �҃}�j���A���Ȃǁj�ɁC��L�̒��쌠�\���C���̗��p��������щ��L
;      �̖��ۏ؋K����f�ڂ��邱�ƁD
;  (3) �{�\�t�g�E�F�A���C�@��ɑg�ݍ��ނȂǁC���̃\�t�g�E�F�A�J���Ɏg
;      �p�ł��Ȃ��`�ōĔz�z����ꍇ�ɂ́C���̂����ꂩ�̏����𖞂�����
;      �ƁD
;    (a) �Ĕz�z�ɔ����h�L�������g�i���p�҃}�j���A���Ȃǁj�ɁC��L�̒�
;        �쌠�\���C���̗��p��������щ��L�̖��ۏ؋K����f�ڂ��邱�ƁD
;    (b) �Ĕz�z�̌`�Ԃ��C�ʂɒ�߂���@�ɂ���āCTOPPERS�v���W�F�N�g��
;        �񍐂��邱�ƁD
;  (4) �{�\�t�g�E�F�A�̗��p�ɂ�蒼�ړI�܂��͊ԐړI�ɐ����邢���Ȃ鑹
;      �Q������C��L����҂����TOPPERS�v���W�F�N�g��Ɛӂ��邱�ƁD
; 
;  �{�\�t�g�E�F�A�́C���ۏ؂Œ񋟂���Ă�����̂ł���D��L���쌠�҂�
;  ���TOPPERS�v���W�F�N�g�́C�{�\�t�g�E�F�A�Ɋւ��āC���̓K�p�\����
;  �܂߂āC�����Ȃ�ۏ؂��s��Ȃ��D�܂��C�{�\�t�g�E�F�A�̗��p�ɂ�蒼
;  �ړI�܂��͊ԐړI�ɐ����������Ȃ鑹�Q�Ɋւ��Ă��C���̐ӔC�𕉂�Ȃ��D
;

;
; SG�ɂ�萶�������x�N�^�[�e�[�u���t�@�C��(kernel_support.src)����
; �C���N���[�h�����t�@�C��
;

 .AIFDEF _KERNEL_SUPPORT_INC_
 .AELSE

_KERNEL_SUPPORT_INC_: .DEFINE ""

	.INCLUDE	"cpu_defs.inc"
	.IMPORT	_start
	.IMPORT _unused_interrupt
	.IMPORT _common_interrupt_process

;
;   �x�N�^�e�[�u���o�^���e�����}�N��
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
;  �����݃n���h���̓��o���̐����}�N��
;

;
;  ISR1�p
;  Renesas���̃R���p�C����#pragram interrupt ��p����ƃx�N�^�[�e�[�u��
;  ���쐬���Ă��܂����߁AISR1���J�[�l�����œ��o�����[�`����p�ӂ���B
;  �X�N���b�`���W�X�^��er0,er1

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
; ISR2�p
;

 .MACRO ISR2_ENTRY ISR, ISRID
	.IMPORT  _ISRMain\ISR'
_\ISR'_entry:
	push.l	er0
	push.l	er1
	push.l	er2
	push.l	er3
	mov.w	#_ISRMain\ISR',r3			; �����݂̃n���h���̃A�h���X��r3��
	mov.b	#\ISRID', r1l				; �������������݂�ID��r0l��
	jmp		@_common_interrupt_process
 .ENDM

;
; �t�b�N���[�`��NULL�V���{�������}�N��
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