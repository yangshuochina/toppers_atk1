/*
 *  TOPPERS Automotive Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 *      Automotive Kernel
 * 
 *  Copyright (C) 2007 by Hitachi,Ltd., Automotive Systems, JAPAN
 *  Copyright (C) 2007 by Hitachi Information & Control Solutions,Ltd., JAPAN
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
 *	�T���v�������^�[�Q�b�g�ˑ����W���[���iSH2A SDK72513�p�j
 */

#include <sh72513.h>

#pragma section ResetPRG

#define DFL_CS2BCR_BSZ_SHFT	(9)
#define DFL_CS2BCR_BSZ_MASK (~(3 << DFL_CS2BCR_BSZ_SHFT))

void
REG_INIT_BSC()			/* �o�X�X�e�[�g�R���g���[�������� RAM�`�F�b�N�O�Ɏ��{*/
{
	/*	�O��IO�f�o�C�X�� CS2��� �̂݁A�����I�Ƀf�[�^�o�X�����w�肷�� (16bit)	*/
	/* �ݒ� BSC.CS2BCR.BIT.BSZ		=	2;	(16bit) */
	CS2BCR	= 	(CS2BCR & DFL_CS2BCR_BSZ_MASK) | (2 << DFL_CS2BCR_BSZ_SHFT);

	PCCR4	=	0x1111;		/*	�f�[�^�o�X���o�͂�I��	*/
	PCCR3	=	0x1111;		/*	�f�[�^�o�X���o�͂�I��	*/
	PCCR2	=	0x1111;		/*	�f�[�^�o�X���o�͂�I��	*/
	PCCR1	=	0x1111;		/*	�f�[�^�o�X���o�͂�I��	*/
	PBCR2	|=	0x1000;		/*	WE1 �[�q�L��	*/
	
	/* CS ��ԃA�N�Z�X�E�F�C�g�ݒ� (No wait) */
	CS0BCR = 0x00000400;	/* Access�� No wait  */

	/* CS ��� Read �T�C�N���E�F�C�g�ݒ� (1 wait) */
	CS0WCR = 0x00000080;	/* Read wait 1cycle */

	RAMACYC = 0x7810;		/* Write 3 wait, read 2 wait (�����l) */
	RAMACYC = RAMACYC | 0;	/* �������݌�A�_�~�[���[�h���{ */

	/* ROM �L���b�V���� �����ɂ���ꍇ�̐ݒ�l
	 *  ROMC.RCCR.LONG = 0;
	 *	RCCR = 0;
	 */
}


void
REG_INIT_ATUIII()			/* ATU-III ���W�X�^���ʕ������� */
{
	ATUENR	= 0;			/*	�S�^�C�}��~ */
	PSCR1	= 1;			/* ������ P��/2  0.1us */
    ATUENR	|= ATUENR_PSCE;		/* �v���X�P�[���X�^�[�g */
}

#pragma section
