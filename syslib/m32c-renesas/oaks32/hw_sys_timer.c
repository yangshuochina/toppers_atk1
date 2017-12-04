/*
 *  TOPPERS Automotive Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Automotive Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2003 by Naoki Saito
 *             Nagoya Municipal Industrial Research Institute, JAPAN
 *  Copyright (C) 2004 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
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
 *	�T���v�������^�[�Q�b�g�ˑ��V�X�e���^�C�}���W���[���iOAKS32�p�j
 */


#include	"hw_sys_timer.h"


/*
 *  �V�X�e���^�C�}�̋N������
 *
 *  �����݋֎~��ԂŌďo�����ƁD
 */
void
InitHwSysTimer( void )
{
	/*
	 *  �^�C�}���~���Ċe���W�X�^�ݒ�
	 */
	TA0S = 0;	/* �J�E���g��~	*/

	/*
	 *  �^�C�}A0�_�E���J�E���g, �^�C�}���[�h, �J�E���g�\�[�Xf1
	 */
	TA0UD = (UINT8)( 0 );
	TA0MR = (UINT8)( 0 );

	/*
	 *  �n�[�h�E�F�A�d�l�ɂă^�C�}�\�[�X�̃��W�X�^�ݒ�l+1�������邽��,
	 *  ���W�X�^�ݒ�l�̓V�X�e���N���b�N�����ɑ�������J�E���g������
	 *  �}�C�i�X1����l��ݒ肷��.�i�ݒ�l�̓w�b�_�Q�Ɓj
	 */
	TA0 = CFG_SYSCLK - (UINT16)( 1 );

	/*
	 *  �^�C�}�R���y�A�����݃��x���ݒ�i�ݒ背�x���̓w�b�_�Q�Ɓj
	 *  TA0IC �� bit3 �������ݗv���t���O�ł���C�����ɃN���A���Ă���D
	 */
	TA0IC = CFG_INTLVL_SYSCLK;

	TA0S = 1;	/* �J�E���g�J�n	*/
}	/* InitHwSysTimer	*/


/*
 *  �V�X�e���^�C�}�̒�~����
 *
 *  �����݋֎~��ԂŌďo�����ƁD
 */
void
TermHwSysTimer(void)
{
	TA0S = 0;					/* �J�E���g��~	*/
	TA0IC = (UINT8)( 0 );		/* �����݃}�X�N	*/
}	/* TermHwSysTimer	*/

