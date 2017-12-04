/*
 *  TOPPERS Automotive Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 *      Automotive Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2001-2003 by Industrial Technology Institute,
 *                              Miyagi Prefectural Government, JAPAN
 *  Copyright (C) 2006 by Witz Corporation, JAPAN
 *  Copyright (C) 2006 by Hitachi,Ltd., Automotive Systems, JAPAN
 *  Copyright (C) 2006 by Hitachi Information & Control Solutions,Ltd., JAPAN
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
 *  �჌�x���v���Z�b�T���샋�[�`��(SH2�p)
 */


#ifndef	_CPU_INSN_H_
#define	_CPU_INSN_H_

/*
 *  Inline�֐��v���g�^�C�v�錾
 */
#pragma inline(disable_int)
static void disable_int(void);
#pragma inline(enable_int)
static void enable_int(void);
#pragma inline_asm(nop)
static void nop(void);
#pragma inline_asm(set_sr)
static void set_sr(UINT32 sr);
#pragma inline_asm(current_sr)
static UINT32 current_sr(void);


extern UINT32 int_ena_flag;
extern UINT32 int_ena_level;

/*
 *  �X�e�[�^�X���W�X�^�iSR�j�̊����݃}�X�N���x���̃}�X�N�r�b�g
 */
#define IPM_MASK_BIT (0x000000f0u)


/*
 *  �X�e�[�^�X���W�X�^�iSR�j�̌��ݒl�̕ύX
 */
static void
set_sr(UINT32 sr)
{
	ldc R4, SR
}

/*
 *  �X�e�[�^�X���W�X�^�iSR�j�̌��ݒl�̓Ǐo��
 */
static UINT32
current_sr(void)
{
	stc sr, R0
}


/*
 *  �O�������ݑS�֎~
 */
static void
disable_int(void)
{
	UINT32 int_ena_level_temp;
	
	/*
	 * �����Ń��[�J���ϐ���SR���W�X�^�̒l��ۑ����Ă���̂́A
	 * SR���W�X�^�̓ǂݏo���Ǝ��ۂɊ����݋֎~�̊ԂɊ��荞�݂��������ꍇ�ɁA
	 * ���荞�݃n���h�����Ŋ��荞�݋֎~�����s�����int_ena_level�l��
	 * ����������Ă��܂����߂ł���
	 */
	
	/* ���d�� disable_int ���R�[������Ă��Aint_ena_level���j�󂳂�Ȃ��悤�ɂ���B */
	if( int_ena_flag != 0) {
		int_ena_level_temp = current_sr() & IPM_MASK_BIT;
		set_sr((current_sr() & ~IPM_MASK_BIT) |  (MAX_IPM << 4) );
		int_ena_level = int_ena_level_temp;
		int_ena_flag = 0;
	}
}


/*
 *  �O�������ݑS�֎~����
 */
static void
enable_int(void)
{
	if( int_ena_flag == 0) {
		int_ena_flag = 1;
		set_sr((current_sr() & ~IPM_MASK_BIT) | int_ena_level);
	}
}


/*
 *  nop ���߂̎��s
 */
static void nop()
{
	nop
}
#endif /* _CPU_INSN_H_ */
