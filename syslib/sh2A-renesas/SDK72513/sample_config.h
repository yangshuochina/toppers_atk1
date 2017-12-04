/*
 *  TOPPERS Automotive Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 *      Automotive Kernel
 * 
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
 *	�T���v�������^�[�Q�b�g�ˑ����W���[���iSH2 HEW EVA�{�[�h�p�j
 */

#if !defined( _SAMPLE_CONFIG_H_ )
#define _SAMPLE_CONFIG_H_


#include	"kernel.h"


/*
 *  SignalCounter���s�p�����݃��x����`
 */
#define CFG_INTLVL_COUNTER	(UINT8)( 0x03 )

/*
 *  ISR1�EISR2�J�E���^�����݃��x����`
 */
#define CFG_INTLVL_HW_CNT1	(UINT8)( 0x05 )
#define CFG_INTLVL_HW_CNT2	(UINT8)( 0x02 )

/*
 *  ISR1�EISR2�J�E���^�^�C�}�̃R���y�A�l�i1ms�j
 *
 *  ATU �^�C�}�c�̃_�E���J�E���^�O���g��
 *  �قȂ� INTLVL �ɂ��邽�߁A�T�u�u���b�N�O�C�P���g�p����B
 *  P�� / 2 (10MHz) �ŃJ�E���g����
 * 
 */
#define	CFG_HW_CNT1		(UINT32)( 10000 )
#define	CFG_HW_CNT2		(UINT32)( 10000 )

#if !defined( _MACRO_ONLY )

/*
 *  �A�v���P�[�V�������[�h�p
 */
/*
 *  �A�v���P�[�V�������[�h����p�̏��擾�����֐��v���g�^�C�v�錾
 */
extern UINT8	GetAppModeInfo( void );


/*
 *  �T���v���J�E���^�\�[�X�p
 */
/*
 *  SignalCounter���s�p�����ݏ����������֐��v���g�^�C�v�錾
 */
extern void	InitCounterInt( void );

/*
 *  SignalCounter���s�p�����ݒ�~�����֐��v���g�^�C�v�錾
 */
extern void	TermCounterInt( void );

/*
 *  SignalCounter���s�p�����݋N�������֐��v���g�^�C�v�錾
 */
extern void	ActCounterInt( void );


/*
 *  ISR1�EISR2�ғ��m�F�p
 */
/*
 *  ISR1�EISR2�J�E���^�����������֐��v���g�^�C�v�錾
 */
extern void	InitHwCntInt( void );

/*
 *  ISR1�EISR2�J�E���^��~�����֐��v���g�^�C�v�錾
 */
extern void	TermHwCntInt( void );

/*
 *  ISR1�EISR2�J�E���^�擾�����֐��v���g�^�C�v�錾
 */
extern void	GetHwCnt( UINT8 *isr1_cnt, UINT8 *isr2_cnt );


#endif /* _MACRO_ONLY */


#endif /* _SAMPLE_CONFIG_H_ */


