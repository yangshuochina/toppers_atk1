/*
 *  TOPPERS Automotive Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 *      Automotive Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2004 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 *  Copyright (C) 2006 by Witz Corporation, JAPAN
 *  Copyright (C) 2006-2008 by Hitachi,Ltd., Automotive Systems, JAPAN
 *  Copyright (C) 2006-2008 by Hitachi Information & Control Solutions,Ltd., JAPAN
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
 *  �v���Z�b�T�ˑ����W���[���iSH2A�p�j
 */


#ifndef	_CPU_CONFIG_H_
#define	_CPU_CONFIG_H_

#define MAX_IPM  0xf	/* �X�^�u�Ȃ��̏ꍇ�͍ō��D��x��CPU���b�N */

#ifndef _MACRO_ONLY
#include "cpu_insn.h"
#endif /* _MACRO_ONLY */


#ifndef _MACRO_ONLY
/* �C�����C���֐��v���g�^�C�v�錾	*/
#pragma inline(set_ipl)
static void set_ipl(UINT8 ipl);
#pragma inline(current_ipl)
static UINT8 current_ipl(void);

extern UINT32 int_ena_flag;
extern UINT32 int_ena_level;

/*
 *  �{OS�J�[�l���ł͊����ݐ����I�t���O�y��IPL�̑o����p���čs��
 *  ���Ƃ�O��Ƃ���D�{CPU��IPL�݂̂��������Ȃ����߁A
 *  I�t���O���\�t�g�E�F�A�ŕ₤�d�l�Ƃ���
 */

/*
 *  �����ݗD��x���x���ݒ�
 */
static void set_ipl(UINT8 ipl)
{
	/*
	 *  CPU���b�N�����ǂ������肵�A���b�N���łȂ����
	 *  SR���W�X�^�ɒ��ڐݒ肷��D���b�N���ł����
	 *  int_ena_level��IPL��ۑ�����D
	 */
	if(int_ena_flag != 0){
		/* SH2A �ł� SR �ȊO�ɁA�V�X�e�����ʂ̃r�b�g������̂ŁA�ۑ����� */
		set_sr((current_sr() & ~IPM_MASK_BIT) |  (ipl << 4) );
	}
	else{
		int_ena_level = ipl << 4;
	}
}


/*
 *  �����ݗD��x���x���擾
 */
static UINT8 current_ipl(void)
{
	/*
	 *  CPU���b�N�����ǂ������肵�A���b�N���łȂ����
	 *  SR���W�X�^���璼�ړǂݏo���D���b�N���ł����
	 *  int_ena_level����IPL��ǂݏo���D
	 */
	if(int_ena_flag != 0)
	{
		return (UINT8)((current_sr() & IPM_MASK_BIT ) >> 4);
	}
	else
	{
		return int_ena_level >> 4;
	}
}


/*
 *  �v���Z�b�T�ˑ��̏�����(cpu_config.c)
 */
extern void	cpu_initialize(void);

/*
 *  �v���Z�b�T�ˑ��̏I��������(cpu_config.c)
 */
extern void	cpu_terminate(void);

#define DEFINE_CTXB(tnum) \
FP tcxb_pc[tnum]; \
VP tcxb_sp[tnum]

extern FP tcxb_pc[];
extern VP tcxb_sp[];

/* �f�B�X�p�b�`����̃A�Z���u���֐��v���g�^�C�v�錾	*/
extern void  dispatch(void);
extern void  exit_and_dispatch(void);
extern void  start_dispatch(void);

#endif /* _MACRO_ONLY */

#if defined(SH2) || defined(SH2E)
/*
 *  SH2,SH2E�ɂ́A�o�����V�t�g���߂��������߁A�ϐ��ɂ��V�t�g���Z�͒ᑬ�ł���B
 *  ����āA�z��Ɍ��ʂ��i�[���Ă����B
 */
extern const UINT16 primap_bitmask[16];
#define	PRIMAP_BIT(pri)		(primap_bitmask[pri])
#endif	/* SH2 or SH2E */

#endif	/* _CPU_CONFIG_H_	*/

