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


#if !defined( _HW_SERIAL_H_ )
#define _HW_SERIAL_H_


#include	"kernel.h"
#include	"sh72513.h"


/*
 *  �V���A���|�[�g�̊����݃��x����`
 */
#define	CFG_INTLVL_SERIAL_RX1	(UINT16)( 0x6 )	/* �V���A����M */

/*
 *  �V���A���|�[�g�̃{�[���[�g��`
 *
 *  CFG_BRR_SERIAL �̒�`�ύX�Ń{�[���[�g��ύX�\
 */
#define	BRR_SERIAL_9600		(UINT8)( 129 )	
#define	BRR_SERIAL_19200	(UINT8)( 64 )	
#define	BRR_SERIAL_38400	(UINT8)( 32 )	
#define	BRR_SERIAL_57600	(UINT8)( 21 )	
#define	BRR_SERIAL_115200	(UINT8)( 10 )	
//#define	CFG_BRR_SERIAL		BRR_SERIAL_57600
#define	CFG_BRR_SERIAL		BRR_SERIAL_115200

#define	SCSCR1_RIE	(0x40)
#define	SCSCR1_TE	(0x20)
#define	SCSCR1_RE	(0x10)
#define	SCSSR1_TDRE	(0x80)
#define	SCSSR1_RDRF	(0x40)


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
static void	PutHwChar( UINT8 character );

/*
 *  �R�[���o�b�N�֐��O���Q��
 */
extern void	RxSerialInt( UINT8 character );

/*
 *  �Ăюw���R���e�L�X�g�ł̕������M�D
 *
 *  ���s�R�[�h�Ȃǂ̐���R�[�h���v�����ōs�����ƁD
 */
static void
PutHwChar( UINT8 character )
{
	/* ���M�o�b�t�@����ɂȂ�܂ő҂�	*/
	while( (SCSSR1A & SCSSR1_TDRE) == 0 ){
	}

	/* �P������������ */
	SCTDR1A = character;

	/* ���M���Ƃ��� */
	SCSSR1A &= ~SCSSR1_TDRE;

}	/* PutHwChar	*/

#endif /* _MACRO_ONLY */


#endif /* _HW_SERIAL_H_ */

