/*
 *  TOPPERS Automotive Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
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
 *	�T���v�������^�[�Q�b�g�ˑ��V���A��IO���W���[���iOAKS32�p�j
 */

/*
 *  KD3083 �g�p��( USE_KD3083 ��`��)�� KD3083 �� UART1 ���g�p���邽�߁C
 *  �V���A��IO���W���[���͓��삳���Ȃ��D
 *  UART0 ���g�p�����͂��邪�COIL�t�@�C���ɋL�ڂ��Ă��銄���݃G���g���[
 *  �ԍ����R���p�C���I�v�V����( USE_KD3083 )�Őؑւ���悢���@���Ȃ����߁C
 *  UART0 ���g�p��������͍s��Ȃ��D
 */

#if !defined( _HW_SERIAL_H_ )
#define _HW_SERIAL_H_


#include	"kernel.h"
#include	"sfrm32c83.h"


/*
 *  �V���A���|�[�g�̊����݃��x����`
 */
#define	CFG_INTLVL_SERIAL_RX	(UINT8)0x06	/* �V���A����M */

/*
 *  �V���A���|�[�g�̃{�[���[�g��`
 *
 *  CFG_BRG_SERIAL �̒�`�ύX�Ń{�[���[�g��ύX�\
 */
#define	BRG_SERIAL_9600		(UINT8)( 194 )	/* 30000000/{(UxBRG+1)*16} = 9615	*/
#define	BRG_SERIAL_19200	(UINT8)( 97 )	/* 30000000/{(UxBRG+1)*16} = 19132	*/
#define	BRG_SERIAL_38400	(UINT8)( 48 )	/* 30000000/{(UxBRG+1)*16} = 38265	*/
#define	CFG_BRG_SERIAL		BRG_SERIAL_38400


#if !defined( _MACRO_ONLY )

/*
 *  �V�X�e�����O�o�̓��W���[���������֐��v���g�^�C�v�錾
 */
extern void	InitHwSerial( void );

/*
 *  �V�X�e�����O�o�̓��W���[����~�֐��v���g�^�C�v�錾
 */
extern void	TermHwSerial( void );

/*
 *  �Ăюw���R���e�L�X�g�ł̕������M�֐��v���g�^�C�v�錾
 */
Inline void	PutHwChar( UINT8 character );

/*
 *  �R�[���o�b�N�֐��O���Q��
 */
extern void	RxSerialInt( UINT8 character );

/*
 *  �Ăюw���R���e�L�X�g�ł̕������M�D
 *
 *  �{�֐��͊����݋֎~��ԂŌĂяo�����ƁD
 *  ���s�R�[�h�Ȃǂ̐���R�[�h���v�����ōs�����ƁD
 */
Inline void
PutHwChar( UINT8 character )
{
#if !defined( USE_KD3083 )
	/* ���M�o�b�t�@����ɂȂ�܂ő҂�	*/
	while( TI_U1C1 == 0 ){
	}
	U1TB = (UINT16)( character );
#endif	/* USE_KD3083	*/
}	/* PutHwChar	*/

#endif /* _MACRO_ONLY */


#endif /* _HW_SERIAL_H_ */

