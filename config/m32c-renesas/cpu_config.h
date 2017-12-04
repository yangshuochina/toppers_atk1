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
 *  ��L���쌠�҂́C�ȉ��� (1)�`(4) �̏������CFree Software Foundation 
 *  �ɂ���Č��\����Ă��� GNU General Public License �� Version 2 �ɋL
 *  �q����Ă�������𖞂����ꍇ�Ɍ���C�{�\�t�g�E�F�A�i�{�\�t�g�E�F�A
 *  �����ς������̂��܂ށD�ȉ������j���g�p�E�����E���ρE�Ĕz�z�i�ȉ��C
 *  ���p�ƌĂԁj���邱�Ƃ𖳏��ŋ�������D
 *  (1) �{�\�t�g�E�F�A���\�[�X�R�[�h�̌`�ŗ��p����ꍇ�ɂ́C��L�̒���
 *      ���\���C���̗��p��������щ��L�̖��ۏ؋K�肪�C���̂܂܂̌`�Ń\�[
 *      �X�R�[�h���Ɋ܂܂�Ă��邱�ƁD
 *  (2) �{�\�t�g�E�F�A���C���C�u�����`���ȂǁC���̃\�t�g�E�F�A�J���Ɏg
 *      �p�ł���`�ōĔz�z����ꍇ�ɂ́C�Ĕz�z�ɔ����h�L�������g�i���p
 *      �҃}�j���A���Ȃǁj�ɁC��L�̒��쌠�\���C���̗��p��������щ��L
 *      �̖��ۏ؋K����f�ڂ��邱�ƁD
 *  (3) �{�\�t�g�E�F�A���C�@��ɑg�ݍ��ނȂǁC���̃\�t�g�E�F�A�J���Ɏg
 *      �p�ł��Ȃ��`�ōĔz�z����ꍇ�ɂ́C���̂����ꂩ�̏����𖞂�����
 *      �ƁD
 *    (a) �Ĕz�z�ɔ����h�L�������g�i���p�҃}�j���A���Ȃǁj�ɁC��L�̒�
 *        �쌠�\���C���̗��p��������щ��L�̖��ۏ؋K����f�ڂ��邱�ƁD
 *    (b) �Ĕz�z�̌`�Ԃ��C�ʂɒ�߂���@�ɂ���āCTOPPERS�v���W�F�N�g��
 *        �񍐂��邱�ƁD
 *  (4) �{�\�t�g�E�F�A�̗��p�ɂ�蒼�ړI�܂��͊ԐړI�ɐ����邢���Ȃ鑹
 *      �Q������C��L���쌠�҂����TOPPERS�v���W�F�N�g��Ɛӂ��邱�ƁD
 * 
 *  �{�\�t�g�E�F�A�́C���ۏ؂Œ񋟂���Ă�����̂ł���D��L���쌠�҂�
 *  ���TOPPERS�v���W�F�N�g�́C�{�\�t�g�E�F�A�Ɋւ��āC���̓K�p�\����
 *  �܂߂āC�����Ȃ�ۏ؂��s��Ȃ��D�܂��C�{�\�t�g�E�F�A�̗��p�ɂ�蒼
 *  �ړI�܂��͊ԐړI�ɐ����������Ȃ鑹�Q�Ɋւ��Ă��C���̐ӔC�𕉂�Ȃ��D
 * 
 */

/*
 *  �v���Z�b�T�ˑ����W���[���iM32C�p�j
 */


#ifndef	_CPU_CONFIG_H_
#define	_CPU_CONFIG_H_


#ifndef _MACRO_ONLY
#include "cpu_insn.h"
#endif /* _MACRO_ONLY */

#ifndef _MACRO_ONLY
/* �C�����C���֐��v���g�^�C�v�錾	*/
Inline void set_ipl(UINT8 ipl);
Inline UINT8 current_ipl(void);


/*
 *  �{OS�J�[�l���ł͊����ݐ����I�t���O�y��IPL�̑o����p���čs��
 *  ���Ƃ�O��Ƃ���D�{CPU�ł͏�L�����𖞂����Ă��邽�ߕs���@�\��
 *  �\�t�g�E�F�A�ŕ₤�K�v�͂Ȃ��D
 */

/*
 *  �����ݗD��x���x���ݒ�
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
 *  �����ݗD��x���x���擾
 */
Inline UINT8 current_ipl(void)
{
	volatile UINT16 flg_reg;
	asm("	stc flg, $$[FB]", flg_reg);
	flg_reg >>= 12;
	return((UINT8)flg_reg);
}


/*�Q�ƃv���g�^�C�v*/
/*
 *  �v���Z�b�T�ˑ��̏�����(cpu_config.c)
 */
extern void	cpu_initialize(void);

/*
 *  �v���Z�b�T�ˑ��̏I��������(cpu_config.c)
 */
extern void	cpu_terminate(void);

#define DEFINE_CTXB(tnum) \
FP tcxb_pc[tnum]; \
VP tcxb_sp[tnum];

extern FP tcxb_pc[];
extern VP tcxb_sp[];

/*
 *  �f�B�X�p�b�`����̃A�Z���u���֐��v���g�^�C�v�錾
 *  (activate_r�͋��ʕ����璼�ڎQ�Ƃ��Ȃ����߂����ɂ͋L�ڂ��Ȃ�)
 */
extern void  dispatch(void);
extern void  exit_and_dispatch(void);
extern void  start_dispatch(void);


/*
 *  ISR1�����}�N��
 *
 *  ISR1�̑S�Ă̏��������[�U���L�q����ꍇ�́Ccpu_defs.h �ɂ��閳�����}�N��
 *  �uOMIT_ISR1_ENTRY�v�̒�`��L���ɂ��邱�ƁD
 */

/* �x�N�^�e�[�u������̊O���Q�Ɛ錾�����}�N��	*/
/*
 *  �����ݓ�������Ԃƃx�N�^�e�[�u����ʃt�@�C���ɐ�������ꍇ�ɕK�v�ƂȂ�D
 *  ����M32C�̑S�ẴV�X�e���ŁC����t�@�C���o�͂ƂȂ��Ă��邽�ߖ{�}�N����
 *  �g�p���ꂽ���Ȃ��\��������D
 *  �ʃt�@�C���o�͂��s���ꍇ���l�����C�L�ڂ͎c���Ă����D
 */
#if defined(OMIT_ISR1_ENTRY)
#define	ISR1_EXTERNAL(isr)		asm("	.glb	_" #isr )
#else	/* OMIT_ISR1_ENTRY	*/
#define	ISR1_EXTERNAL(isr)		asm("	.glb	_" #isr "_entry")
#endif	/* OMIT_ISR1_ENTRY	*/

/* �x�N�^�e�[�u���o�^�V���{�������}�N��	*/
#if defined(OMIT_ISR1_ENTRY)
#define	ISR1_SYMBOL(isr)		asm("	.lword	_" #isr )
#else	/* OMIT_ISR1_ENTRY	*/
#define	ISR1_SYMBOL(isr)		asm("	.lword	_" #isr "_entry")
#endif	/* OMIT_ISR1_ENTRY	*/

/* ���������̐����}�N��	*/
#if defined(OMIT_ISR1_ENTRY)
#define ISR1_ENTRY(isr)
#else	/* OMIT_ISR1_ENTRY	*/
#define ISR1_ENTRY(isr)\
asm("	.glb _" #isr "					");\
asm("	.section program, code, align	");\
asm("_" #isr "_entry:					");\
asm("	push.w	r0				; �X�N���b�`���W�X�^���^�X�N�X�^�b�N�֑ޔ�");\
asm("	jsr	_" #isr );\
asm("	pop.w	r0				; �X�N���b�`���W�X�^���^�X�N�X�^�b�N���畜�A");\
asm("	reit	");
#endif	/* OMIT_ISR1_ENTRY	*/


/*
 *  ISR2�����}�N��
 */

/* �x�N�^�e�[�u������̊O���Q�Ɛ錾�����}�N��	*/
/*
 *  �����ݓ�������Ԃƃx�N�^�e�[�u����ʃt�@�C���ɐ�������ꍇ�ɕK�v�ƂȂ�D
 *  ����M32C�̑S�ẴV�X�e���ŁC����t�@�C���o�͂ƂȂ��Ă��邽�ߖ{�}�N����
 *  �g�p���ꂽ���Ȃ��\��������D
 *  �ʃt�@�C���o�͂��s���ꍇ���l�����C�L�ڂ͎c���Ă����D
 */
#define	ISR2_EXTERNAL(isr)		asm("	.glb	_" #isr "_entry")

/* �x�N�^�e�[�u���o�^�V���{�������}�N��	*/
#define	ISR2_SYMBOL(isr)		asm("	.lword	_" #isr "_entry")

/* ���������̐����}�N��	*/
#define ISR2_ENTRY(isr, isrid)\
asm("	.glb _runisr					");\
asm("	.glb _ISRMain" #isr "			");\
asm("	.glb _interrupt					");\
asm("	.section program, code, align	");\
asm("_" #isr "_entry:					");\
asm("	pushm	r0,r1,r3,a0				; ���W�X�^���^�X�N�X�^�b�N�֑ޔ�");\
asm("	mov.l	#_ISRMain" #isr ", a0	; �����݃n���h���̃A�h���X��a0��");\
asm("	mov.b	_runisr, r0l			; �O�̎��s��������ID��ێ�");\
asm("	mov.b	#" #isrid ", _runisr	; ����̎��s��������ID��ݒ�");\
asm("	jmp	_interrupt					; �����ݏ������[�`���㔼��	");


/*
 *  ���g�p�����ݐ����}�N��
 */

/* �x�N�^�e�[�u������̊O���Q�Ɛ錾�����}�N��	*/
#define	UNUSED_INT_EXTERNAL()	asm("	.glb	_unused_interrupt")

/* �x�N�^�e�[�u���o�^�V���{�������}�N��	*/
#define	UNUSED_INT_SYMBOL()		asm("	.lword	_unused_interrupt")


/*
 *  �t�b�N���[�`��NULL�V���{�������}�N��
 */
#define	NULL_ERRORHOOK \
asm(".glb	$ErrorHook");\
asm("$ErrorHook .equ 0");

#define	NULL_STARTUPHOOK \
asm(".glb	_StartupHook"); \
asm("_StartupHook .equ 0");

#define	NULL_SHUTDOWNHOOK \
asm(".glb	$ShutdownHook"); \
asm("$ShutdownHook .equ 0");

#define	NULL_PRETASKHOOK \
asm(".glb	_PreTaskHook"); \
asm("_PreTaskHook .equ 0");

#define	NULL_POSTTASKHOOK \
asm(".glb	_PostTaskHook"); \
asm("_PostTaskHook .equ 0");


#endif /* _MACRO_ONLY */
#endif	/* _CPU_CONFIG_H_	*/

