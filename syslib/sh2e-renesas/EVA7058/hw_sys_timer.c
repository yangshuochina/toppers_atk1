/*
 *  TOPPERS Automotive Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 *      Automotive Kernel
 * 
 *  Copyright (C) 2004-2006 by Witz Corporation, JAPAN
 *  Copyright (C) 2006 by Hitachi,Ltd., Automotive Systems, JAPAN
 *  Copyright (C) 2006 by Hitachi Information & Control Solutions,Ltd., JAPAN
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
 *	�T���v�������^�[�Q�b�g�ˑ��V�X�e���^�C�}���W���[���iSH2 HEW EVA�{�[�h�p�j
 */


#include	"hw_sys_timer.h"
#include	"sh7058.h"


/*
 *  �V�X�e���^�C�}�̋N������
 *
 *  �����݋֎~��ԂŌďo�����ƁD
 */
void
InitHwSysTimer( void )
{
	/*
	 *  �R���y�A�}�b�`�^�C�}���~���Ċe���W�X�^�ݒ�
	 *  �R���y�A�}�b�`�^�C�}0���g�p����D
	 */
	P_CMT.CMSTR.BIT.STR0 = 0;		/* �J�E���g��~ */

	/*
	 *  ������ ���ӃN���b�N 1/8, ���荞�݋֎~
	 *  CMCSR �� bit6 �������ݗv���t���O�ł���C�����ɃN���A���Ă���D
	 */
	P_CMT.CMCSR0.WORD = (UINT16)0x0000;

	/*
	 *  �R���y�}�b�`�J�E���^�ڕW�l�ݒ�
	 */
	P_CMT.CMCOR0 = CFG_SYSCLK;

	/*
	 *  �^�C�}�R���y�A�����݃��x���ݒ�i�ݒ背�x���̓w�b�_�Q�Ɓj
	 */
	P_INTC.IPRJ.BIT.CMT0_AD0 = CFG_INTLVL_SYSCLK;

	/*
	 *  �J�E���^�N���A�Ɗ����݋���
	 */
	P_CMT.CMCNT0 = (UINT16)0x0000;		/* �J�E���g�N���A */
	P_CMT.CMCSR0.BIT.CMIE = 1;		/* �R���y�A�}�b�`�����݋��� */

	P_CMT.CMSTR.BIT.STR0 = 1;		/* �J�E���g�J�n */

}	/* InitHwSysTimer	*/


/*
 *  �V�X�e���^�C�}�̒�~����
 *
 *  �����݋֎~��ԂŌďo�����ƁD
 */
void
TermHwSysTimer( void )
{
	P_CMT.CMSTR.BIT.STR0 = 0;		/* �J�E���g��~ */
	P_CMT.CMCSR0.WORD = (UINT16)0x0000;		/* �@�\������ */
}	/* TermHwSysTimer	*/


