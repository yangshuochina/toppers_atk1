/*
 *  TOPPERS Automotive Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 *      Automotive Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2004 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 *  Copyright (C) 2006 by Witz Corporation, JAPAN
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
 *  �v���Z�b�T�ˑ����W���[���iSH2A�p�j
 */


/*�w�b�_�t�@�C��*/
#include	"osek_kernel.h"
#include 	"sh72513.h"
UINT32 int_ena_flag;
UINT32 int_ena_level;
UINT32 common_stack_top;	/* ���ʃX�^�b�N�̈� */

extern UINT8 Enable_Resbank;

/*
 *  �v���Z�b�T�ˑ��̏�����
 */
void
cpu_initialize(void)
{
	/* �J�[�l���Ŏg�p����ϐ��̏����� */
	int_ena_flag = 1;
	int_ena_level = 0;

	/* ���ʃX�^�b�N�̈揉���� */
	common_stack_top = (UINT32) STACK_TOP;
	if(Enable_Resbank)
	{
		IBCR = 0;			/* �����݃��x�����Ƃ̐ݒ�͂��Ȃ� */
/*		IBNR_BE = 1;		   ���W�X�^�o���N��S�����݃��x���ŗL���ɂ���(IBCR�𖳎�) */
/*		IBNR_BOVE = 1;		   ���W�X�^�o���N�I�[�o�[�t���[��O�L�� */
		IBNR = (0x6000);	/* SH72513 �ł́AIBNR �ւ� 16bit �A�N�Z�X�K�{ */
	}
	else
	{
/*		IBNR_BE = 0;		   ���W�X�^�o���N��S�����݃��x���Ŗ����ɂ��� */
		IBNR = (0x0000);	/* SH72513 �ł́AIBNR �ւ� 16bit �A�N�Z�X�K�{ */
	}

}

/*
 *  �v���Z�b�T�ˑ��̏I������
 */
void
cpu_terminate(void)
{
	/* ���ɕK�v�Ȃ� */
}

#if defined(SH2) || defined(SH2E)
/*
 *  SH2,SH2E�ɂ́A�o�����V�t�g���߂��������߁A�ϐ��ɂ��V�t�g���Z�͒ᑬ�ł���B
 *  ����āA�z��Ɍ��ʂ��i�[���Ă����B
 */
const UINT16 primap_bitmask[16] = 
	{ 1, 2, 4, 8, 16, 32, 64, 128,
	  256, 512, 1024, 2048, 4096, 8192, 16384, 32768 };
#endif	/* SH2 or SH2E */
