/*
 *  TOPPERS Automotive Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 *      Automotive Kernel
 * 
 *  Copyright (C) 2004 by Witz Corporation, JAPAN
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
 *  �v���Z�b�T�ˑ����W���[��(H8/300H Tiny�p)
 */ 
#ifndef	_CPU_CONFIG_H_
#define	_CPU_CONFIG_H_


#ifndef _MACRO_ONLY
#include "cpu_insn.h"
#endif /* _MACRO_ONLY */

#ifndef _MACRO_ONLY

/*
 *  TOPPERS Automotive Kernel �ł́C�����ݐ���������ݑS�֎~�t���O(I�t���O)�Ɗ���
 *  �݃}�X�N(IPL)�̗��������݂��Ă��邱�Ƃ�O��Ƃ��Ă���D
 *  H8/Tiny�ł́CI�t���O�݂̂����݂��邽�߁CIPL���\�t�g�E�F�A�ŕ₤�D
 *  ��̓I�ɂ́CIPL��1�ȏ�̒l���Z�b�g������I�t���O���Z�b�g���C0���Z�b�g������
 *  I�t���O���N���A����D�܂��C�����݋֎~��Ԃ��̏�Ԃ�ێ��C�����݋֎~��Ԃ̎��ɂ�
 *  I�t���O�͑��삵�Ȃ��D
 */

extern UINT8 i_flag;    /* �����ݏ�ԕێ��t���O */
extern UINT8 ipl_level; /* �����݃��x���ێ��ϐ� */

/*
 *  �����ݗD��x���x���ݒ�
 */
Inline void set_ipl(UINT8 ipl)
{

	if( FALSE == i_flag ) {
		/* �����݋���ԂȂ��I�t���O�𑀍삷�� */
		if( 0 == ipl ) {
			/* �����݋��� */
			set_imask_ccr(0);
		}
		else {
			/* �����݋֎~ */
			set_imask_ccr(1);
		}
	}

	ipl_level = ipl;	
}


/*
 *  �����ݗD��x���x���擾
 */
Inline UINT8 current_ipl(void)
{
	return((UINT8)ipl_level);
}


/*�Q�ƃv���g�^�C�v*/
/*
 *  �v���Z�b�T�ˑ��̏�����(cpu_config.c)
 */
extern void	cpu_initialize(void);

/*
 *  �v���Z�b�T�ˑ��̏I��������(cpu_config.c)
 */
extern void	cpu_terminate(void);

#define DEFINE_CTXB(tnum) \
VP tcxb_pc[tnum]; \
VP tcxb_sp[tnum]

extern VP tcxb_pc[];
extern VP tcxb_sp[];

/* �f�B�X�p�b�`����̃A�Z���u���֐��v���g�^�C�v�錾	*/
extern void  dispatch(void);
extern void  exit_and_dispatch(void);
extern void  start_dispatch(void);

#endif /* _MACRO_ONLY */
#endif	/* _CPU_CONFIG_H_	*/

