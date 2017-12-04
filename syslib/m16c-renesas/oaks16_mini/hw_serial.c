/*
 *  TOPPERS Automotive Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 *      Automotive Kernel
 * 
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
 *	�T���v�������^�[�Q�b�g�ˑ��V���A��IO���W���[���iOAKS16-mini�j
 */

/*
 *  KD30 �g�p��( USE_KD30 ��`��)�� KD30 �� UART1 ���g�p���邽�߁C
 *  �V���A��IO���W���[���͓��삳���Ȃ��D
 *  UART0 ���g�p�����͂��邪�COIL�t�@�C���ɋL�ڂ��Ă��銄���݃G���g���[
 *  �ԍ����R���p�C���I�v�V����( USE_KD30 )�Őؑւ���悢���@���Ȃ����߁C
 *  UART0 ���g�p��������͍s��Ȃ��D
 */

#include "hw_serial.h"


/*
 *  �V���A��IO���W���[������������
 *
 *  �����݋֎~��ԂŌďo�����ƁD
 */
void
InitHwSerial( void )
{
#if !defined( USE_KD30 )
	/*
	 *  ����M���֎~���Ċe���W�X�^�ݒ�
	 */
	TE_U1C1 = 0;						/* ���M�֎~					*/
	RE_U1C1 = 0;						/* ��M�֎~					*/

	/*
	 *  �����N���b�N�g�p, �񓯊��ʐM, 8�r�b�g�f�[�^,
	 *  �p���e�B�Ȃ�, �X���[�v�Ȃ�, �N���b�Nf1, CTS/RTS�֎~
	 */
	U1MR = (UINT8)0x05;			/* �����N���b�N, �񓯊�, 8�r�b�g,	*/
								/* �p���e�B�Ȃ�, �X���[�v�Ȃ�		*/
	U1C0 = (UINT8)0x10;			/* �N���b�Nf1�I��, CTS/RTS�֎~		*/

	/*
	 *  �{�[���[�g�ݒ�i�ݒ�l�̓w�b�_�Q�Ɓj
	 */
	U1BRG = CFG_BRG_SERIAL;				/* 38400bps					*/

	/*
	 *  ��M�����݃��x���ݒ�i�ݒ背�x���̓w�b�_�Q�Ɓj
	 *  S1RIC �� bit3 �������ݗv���t���O�ł���C�����ɃN���A���Ă���D
	 *
	 *  ���M�����݂͎g�p���Ȃ��D
	 */
	S1RIC = CFG_INTLVL_SERIAL_RX;

	/* �V���A���ʐM�J�n	*/
	RE_U1C1 = 1;						/* ��M����					*/
	TE_U1C1 = 1;						/* ���M����					*/
#endif	/* USE_KD30	*/
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
#if !defined( USE_KD30 )
	S1RIC = (UINT8)( 0 );				/* ��M�����݃}�X�N			*/
	S1TIC = (UINT8)( 0 );				/* ���M�����݃}�X�N			*/

	TE_U1C1 = 0;						/* ���M�֎~					*/
	RE_U1C1 = 0;						/* ��M�֎~					*/
#endif	/* USE_KD30	*/
}	/* TermHwSerial	*/

/*
 *  �V���A��IO���W���[����M�����݃T�[�r�X���[�`��
 */
#if defined( OMIT_ISR1_ENTRY )
/* ISR1��������������͖{�֐��������݊֐��w�肷��	*/
#pragma INTERRUPT	RxHwSerialInt
#endif	/* OMIT_ISR1_ENTRY	*/
void	RxHwSerialInt( void );
void
RxHwSerialInt( void )
{
#if !defined( USE_KD30 )
	UINT16	rx_data;					/* �f�[�^��M�o�b�t�@		*/

	/*
	 *  �I�[�o�����h�~�̂��߂܂��Ǎ���
	 */
	rx_data = U1RB;

	/*
	 *  �����M���̓R�[���o�b�N���s
	 *  �G���[���̓G���[���A�����i��M�֎~���邱�ƂŃG���[�t���OOFF�j
	 */
	if( ( rx_data & (UINT16)0xff00u ) == 0 ){
		RxSerialInt( (UINT8)rx_data );
	}
	else{
		RE_U1C1 = 0;					/* ��M�֎~					*/
		RE_U1C1 = 1;					/* ��M����					*/
	}
#endif	/* USE_KD30	*/
}	/* RxHwSerialInt	*/


