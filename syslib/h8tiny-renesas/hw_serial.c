/*
 *  TOPPERS Automotive Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 *      Automotive Kernel
 * 
 *  Copyright (C) 2006 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN    
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
 *  �^�[�Q�b�g�V�X�e���ˑ��V���A�����W���[���iH8/Tiny�p�j
 *    SCI3���g�p 
 */

#include	"hw_serial.h"


/*
 *  �|�[�g�̃N���[�Y
 */
static
cls_port(void)
{
	long count;
	
	/* TDRE �� 1 �ɂȂ�܂ő҂� */
	while( 0 == (SCI3_SSR & (UINT8)SSR_TDRE) );

	/*
     * 11�r�b�g���M���҂�
	 *  �� 1.2 msec�҂� 
	 *   9600bps = �� 0.1 msec
	 *   0.1 * 11 + 1 = 1.2 msec
	 * 1���while���[�v�ɗv���鎞��
	 *   1���߂̎��s�X�e�[�g�̍ŏ���2�X�e�[�g
	 *   20Mhz����̏ꍇ�C1�X�e�[�g50nsec
	 *   while���߂�4�X�e�b�v
	 *    4 * 2 * 50nsec = 400nsec
	 * 1.2msec / 400nsec = 3000   
	 */
	count = 3000L;
	while (0 < count){
		count--;
	}

	/* ����M��~ */
	SCI3_SCR &= (UINT8)(~(SCR_TIE|SCR_RIE|SCR_TE|SCR_RE));
}

/*
 *  �V���A��IO���W���[������������
 *    �|�[�g�����������Ď�M�����݂�L���ɂ���D
 */
void
InitHwSerial(void)
{
	long count;
	
	cls_port();

	/* ���[�h�ݒ� */
	SCI3_SMR = (UINT8)0;
	
	/* �{�[���[�g�ݒ�(38900bps) */
	SCI3_BRR = (UINT8)15;

	/* �����݂̋֎~�ƃN���b�N�\�[�X�̑I�� */
	SCI3_SCR = (UINT8)0;

	/* �{�[���[�g�̐ݒ��A1bit�҂K�v������ 
	 *  �� 0.1 msec�҂� 
	 *   9600bps = �� 0.1 msec (�Œ�{�[���[�g)
	 * 1���while���[�v�ɗv���鎞��
	 *   1���߂̎��s�X�e�[�g�̍ŏ���2�X�e�[�g
	 *   20Mhz����̏ꍇ�C1�X�e�[�g50nsec
	 *   while���߂�4�X�e�b�v
	 *    4 * 2 * 50nsec = 400nsec
	 * 0.1msec / 400nsec = 250
	 */
	count = 250L;
	while (0 < count){
		count--;
	}

	/* �G���[�t���O���N���A */
	SCI3_SSR &= (UINT8)(~(SSR_ORER|SSR_FER|SSR_PER));

	/* ����M����, ��M�����݋��� */
	SCI3_SCR |= (UINT8)(SCR_TE|SCR_RE|SCR_RIE);
	
	/* �|�[�g��L���� */
	IO_PMR1 |= (UINT8)IO_PMR1_TXD;
}

/*
 *  �V���A��IO���W���[����~����
 *
 */
void
TermHwSerial(void)
{
	cls_port();
}

  
/*
 *  �V���A��IO���W���[����M�����݃T�[�r�X���[�`��
 */
void RxHwSerialInt(void)
{
	UINT8 data;
	
	if((SCI3_SSR & (UINT8)(SSR_ORER|SSR_FER|SSR_PER)) != 0){
		/* �G���[���� */
		/* �G���[�t���O���N���A */
		SCI3_SSR &= (UINT8)(~(SSR_ORER|SSR_FER|SSR_PER));
	}
	else {
		/* �f�[�^��M */
		data = (UINT8)SCI3_RDR;
		/* ��M�t���O�N���A */
		SCI3_SSR &= (UINT8)(~(SSR_RDRF));
		RxSerialInt(data);	/* ��M�R�[���o�b�N���s */
	}
}
