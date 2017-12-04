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
 *	�T���v�������^�[�Q�b�g�ˑ��V���A���ʐM���W���[���iSH2A SDK72513�p�j
 */

/*
 *	SCIA �ɒ[����ڑ����A�V���A����M���荞�݂ŏ�������
 */

#include	"hw_serial.h"
#include	"sh72513.h"

#define PJCR1_MD6      0x1000    /* PJ6MD:1(RxD_A����)             */
#define PJCR1_MD5      0x0400    /* PJ5MD:1(TxD_A�o��)             */



/*
 *  �V���A��IO���W���[������������
 *
 *  �����݋֎~��ԂŌďo�����ƁD
 */
void
InitHwSerial( void )
{
	/*
	 *  ����M���֎~���Ċe���W�X�^�ݒ�
	 */
	SCSCR1A = (UINT8)0x00;			/* ����M�֎~, �����N���b�N�g�p */
	SCSSR1A = 0;
	/*
	 *   ���������ʐM, 8�r�b�g�f�[�^, �p���e�B�Ȃ�, 1�X�g�b�v�r�b�g,
	 */
	SCSMR1A = (UINT8)0x00;

	/*
	 *  �{�[���[�g�ݒ�i�ݒ�l�̓w�b�_�Q�Ɓj
	 */
	SCBRR1A = CFG_BRR_SERIAL;

	/*
	 *  ��M�����݃��x���ݒ�i�ݒ背�x���̓w�b�_�Q�Ɓj
	 *  SSR �� RDRF �������ݗv���t���O�����A�����l0�̂��ߑ��삵�Ȃ��D
	 *
	 *  ���M�����݂͎g�p���Ȃ��D
	 */
	IPR26 = (IPR26 & 0x0FFF) | (CFG_INTLVL_SERIAL_RX1 <<12);
	SCSCR1A = SCSCR1_RIE;

	/*
	 *  IO�|�[�g���V���A���|�[�g�ɕύX
	 */
	PJCR1 = (PJCR1 & 0xC3FF) | PJCR1_MD6 | PJCR1_MD5;

	/*
	 *  ����M������
	 */
	SCSCR1A	|= SCSCR1_TE;
	SCSCR1A	|= SCSCR1_RE;

}	/* InitHwSerial	*/


/*
 *  �V���A��IO���W���[����~����
 *
 *  �����݋֎~��ԂŌďo�����ƁD
 *  ��ʂŏo�͂��������Ă��邱�Ƃ�ۏႷ�邱�ƁD
 */
void
TermHwSerial( void )
{
	/*
	 *  ����M����ё���M�����݋֎~
	 */
	SCSCR1A = (UINT8)0x0;			/* ����M�֎~ */
	SCSSR1A = (UINT8)0x0;			/* �X�e�[�^�X������ */

	/*
	 *  �V���A�������݃��x���Œቻ
	 */
	IPR26 = (IPR26 & 0x0FFF);

}	/* TermHwSerial	*/


/*
 *  �V���A��IO���W���[����M�G���[�����݃T�[�r�X���[�`��
 */
#if defined( OMIT_ISR1_ENTRY )
/* ISR1��������������͖{�֐��������݊֐��w�肷��	*/
#pragma interrupt	ErrHwSerialInt
#endif	/* OMIT_ISR1_ENTRY */
void ErrHwSerialInt( void );
void ErrHwSerialInt( void )
{
	UINT8 dmy;
	SCSSR1A &= (UINT8)~0x38;	/* OROR,FER,PER = 0 */
	dmy = SCSSR1A;				/* �_�~�[���[�h */
}


/*
 *  �V���A��IO���W���[����M�����݃T�[�r�X���[�`��
 */
#if defined( OMIT_ISR1_ENTRY )
/* ISR1��������������͖{�֐��������݊֐��w�肷��	*/
#pragma interrupt	RxHwSerialInt
#endif	/* OMIT_ISR1_ENTRY	*/
void RxHwSerialInt( void );
void RxHwSerialInt( void )
{
	UINT8	rx_data;	/* �f�[�^��M�o�b�t�@	*/

	/*
	 *  �I�[�o�����h�~�̂��߂܂��Ǎ���
	 */
	rx_data = SCRDR1A;

	/*
	 * �����ݗv�����N���A
	 */
	SCSSR1A &= ~SCSSR1_RDRF;
	/* ���̏����� SCSSR1A ��ǂݍ���ł���̂Ń_�~�[���[�h�s�v */
	
	/*
	 *  �����M���̓R�[���o�b�N���s
	 *  �G���[���̓G���[���A����
	 */
	if( ( SCSSR1A  & (UINT8)0x38 ) == 0x0 ){
		RxSerialInt( rx_data );
	}
	else{
		SCSSR1A &= (UINT8)~0x38;
	}
}	/* RxHwSerialInt	*/


