/*
 *  TOPPERS Automotive Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 *      Automotive Kernel
 * 
 *  Copyright (C) 2006 by Witz Corporation, JAPAN
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
 *	�T���v�������V���A��IO���W���[��
 */


#if !defined( _SERIAL_H_ )
#define _SERIAL_H_


#include	"kernel.h"


/*
 *  �V�X�e�����O�o�͊֐��̃��l�[��
 *  �V�X�e�����O�o�͊֐��̓V���A�����M�֐��ő�p����D
 */
/*
 *  �����񑗐M�����֐��v���g�^�C�v�錾
 */
#define	PutSysLog	SendSerialStr

/*
 *  �����ݒ������񑗐M�����֐��v���g�^�C�v�錾
 */
#define	PutIntSysLog	SendIntSerialStr


#if !defined( _MACRO_ONLY )

/*
 *  �V���A��IO���W���[�������������֐��v���g�^�C�v�錾
 */
extern void	InitSerial( void );

/*
 *  �V���A��IO���W���[����~�����֐��v���g�^�C�v�錾
 */
extern void	TermSerial( void );

/*
 *  �����񑗐M�����֐��v���g�^�C�v�錾
 */
extern void	SendSerialStr( const UINT8 * str );

/*
 *  �����ݒ������񑗐M�����֐��v���g�^�C�v�錾
 */
extern void	SendIntSerialStr( const UINT8 * str );

/*
 *  ������M�����֐��v���g�^�C�v�錾
 */
extern void	RecvPolSerialChar( UINT8 * character );

/*
 *  32bit���l -> 10�i��������ϊ��֐��v���g�^�C�v�錾
 */
extern void	ConvLong2DecStr( UINT8 *dst, UINT32 src );

/*
 *  16bit���l -> 10�i��������ϊ��֐�
 */
extern void	ConvShort2DecStr( UINT8 *dst, UINT16 src );

/*
 *  8bit���l -> 10�i��������ϊ��֐�
 */
extern void	ConvByte2DecStr( UINT8 *dst, UINT8 src );

/*
 *  32bit���l -> 16�i��������ϊ��֐�
 */
extern void	ConvLong2HexStr( UINT8 *dst, UINT32 src );

/*
 *  16bit���l -> 16�i��������ϊ��֐�
 */
extern void	ConvShort2HexStr( UINT8 *dst, UINT16 src );

/*
 *  8bit���l -> 16�i��������ϊ��֐�
 */
extern void	ConvByte2HexStr( UINT8 *dst, UINT8 src );

#endif /* _MACRO_ONLY */


#endif /* _SERIAL_H_ */

