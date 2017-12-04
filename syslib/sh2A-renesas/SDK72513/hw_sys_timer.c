/*
 *  TOPPERS Automotive Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 *      Automotive Kernel
 * 
 *  Copyright (C) 2004-2006 by Witz Corporation, JAPAN
 *  Copyright (C) 2006,2007 by Hitachi,Ltd., Automotive Systems, JAPAN
 *  Copyright (C) 2006,2007 by Hitachi Information & Control Solutions,Ltd., JAPAN
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
 *	�T���v�������^�[�Q�b�g�ˑ��V�X�e���^�C�}���W���[���iSH2A SDK72513�p�j
 */


#include	"hw_sys_timer.h"
#include	"sh72513.h"

#define CMSTR_STR0 (0x0001)
#define CMCR_CMIE (0x40)
#define	IPR05_IPL_CMT0_SHFT (12)
#define	IPR05_IPL_CMT0_MASK (~(0xF << IPR05_IPL_CMT0_SHFT))


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
	CMSTR &= ~CMSTR_STR0;
	
	/*
	 *  ������ ���ӃN���b�N 1/8(0.4us), ���荞�݋֎~
	 */
	CMCR_0 = 0;


	/*
	 *  �R���y�}�b�`�J�E���^�ڕW�l�ݒ�
	 */
	CMCOR_0 = CFG_SYSCLK;

	/*
	 *  �^�C�}�R���y�A�����݃��x���ݒ�i�ݒ背�x���̓w�b�_�Q�Ɓj
	 */
	IPR05 = (IPR05 & IPR05_IPL_CMT0_MASK) 
			| ( CFG_INTLVL_SYSCLK << IPR05_IPL_CMT0_SHFT);
	/*
	 *  �J�E���^�N���A�Ɗ����݋���
	 */
	CMCNT_0 = (UINT16)0x0000;		/* �J�E���g�N���A */
	CMSR_0  = 0;					/* CMF �N���A */
	CMCR_0 |= CMCR_CMIE;			/* ������ enable */
	CMSTR  |= CMSTR_STR0;

}	/* InitHwSysTimer	*/


/*
 *  �V�X�e���^�C�}�̒�~����
 *
 *  �����݋֎~��ԂŌďo�����ƁD
 */
void
TermHwSysTimer( void )
{
	CMSTR	&= ~CMSTR_STR0;
	CMCR_0	&= ~CMCR_CMIE;	/* ������ disable */
	CMSR_0	 = 0;			/* CMF �N���A */
}	/* TermHwSysTimer	*/


