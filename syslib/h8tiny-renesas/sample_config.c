/*
 *  TOPPERS Automotive Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 *      Automotive Kernel
 * 
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
 *	�T���v�������^�[�Q�b�g�ˑ����W���[���ihokuto_bb�p�j
 */


#include	"sample_config.h"
#include	"h8_36057.h"


/*
 *  OIL��`�V���{���̊O���Q��
 */
DeclareCounter( SampleCnt );


/*
 *	�����֐��v���g�^�C�v�錾
 */
ISR( CounterInt );
ISR( HwCnt2Int );


/*
 *  �A�v���P�[�V�������[�h�p
 */
/*
 *  �A�v���P�[�V�������[�h����p�̏��擾����
 *
 *  �V�X�e�����ƂɔC�ӂ̓��͎�@�ɂ��������邱�ƁD
 *  0,1,2�����ʂł��邱�ƁD3��2�Ɠ��������ɂȂ�D
 * 
 *  ToDo :  
 *
 */
UINT8
GetAppModeInfo( void )
{
	return 0;
}


/*
 *  �T���v���J�E���^�\�[�X�p
 *
 */

/*
 *  SignalCounter���s�p�����ݏ���������
 *
 */
void
InitCounterInt( void )
{

	TV_TCRV0 = (UINT8)0;    /* �^�C�}��~ */	
	TV_TCORA = (UINT8)0x01; /* �^�C���A�E�g�l��ݒ� */
	TV_TCRV1 |= (UINT8)TV_TCRV1_ICKS0;
}

/*
 *  SignalCounter���s�p�����ݒ�~����
 */
void
TermCounterInt( void )
{
	/* ���ɂȂ� */
}

/*
 *  SignalCounter���s�p�����݋N������
 */
void
ActCounterInt( void )
{
	/*
	 * �J�E���g�l�ݒ�
	 */ 
	TV_TCNTV = (UINT8)0x00;
	
	/*
	 * �R���y�A�}�b�`A�ŃN���A
	 * �R���y�A�}�b�`�C���^���v�g�C�l�[�u��A	  
	 * ��/128 �ŃX�^�[�g
	 */
	TV_TCRV0 = (UINT8)(TV_TCRV0_CMIEA|TV_TCRV0_CCLR0|TV_TCRV0_CKS1|TV_TCRV0_CKS0);
}

/*
 *  SignalCounter���s�p�����݃T�[�r�X���[�`��
 *  �^�C�}�����݂͂P��̂ݔ���������
 */
ISR( CounterInt )
{
	UINT8 tmp;
	
	/* �����ݗv�����N���A */
	tmp = TV_TCSRV;    
	TV_TCSRV = (UINT8)0;
	
	/* �^�C�}��~ */
	TV_TCRV0 = (UINT8)0;
	
	/*
	 *  �J�E���^���Z�ʒm�������s
	 */
	SignalCounter( SampleCnt );
}


/*
 *  ISR1�EISR2�ғ��m�F�p
 *
 */
/*
 *  �n�[�h�E�F�A�J�E���^�o�b�t�@
 */
static UINT8	hw_cnt1;
static UINT8	hw_cnt2;

/*
 *  ISR1�EISR2�J�E���^����������
 */
void
InitHwCntInt( void )
{
	hw_cnt1 = 0;
	hw_cnt2 = 0;

	/*
	 * ISR1�p�m�F�p�^�C�}Z�`���l��0������
	 */
	/* GRA�̃R���y�A�}�b�`�ŃN���A�A������G�b�W�A�����N���b�N�ŃJ�E���g */
	TZ_TCR_0 = (UINT8)TZ_TCR_CCLR0;
	TZ_GRA_0 = (UINT16)20000;           /* �J�E���g�l��ݒ� */
	TZ_TSTR |= (UINT8)TZ_TSTR_STR0;     /* �^�C�}�X�^�[�g */
	TZ_TIER_0 |=  (UINT8)TZ_TIER_IMIEA; /* �����݋��� */ 


	/*
	 * ISR2�p�m�F�p�^�C�}B������
	 *  8bit�^�C�}
	 */
	
	/*
     * �I�[�g�����[�h
	 * �N���b�N ��/8192
	 * 50n * 256 = 12800n
     * 1m / 12800 = 78.125 = 79 = 0x4f
	 */
	TB1_TMB1 = (UINT8)(TB1_TMB1_RLD|TB1_TMB1_CKS1|TB1_TMB1_CKS0);

	TB1_TLB1 = (UINT8)(0xff - 0x4f);
	
	/* �^�C�}B1�I�[�o�[�t���[�����݋��� */
	IENR2 |= (UINT8)IENR2_IENTB1;
}

/*
 *  ISR1�EISR2�J�E���^��~����
 */
void
TermHwCntInt( void )
{
	UINT8 tmp;
	
	/*
	 * ISR1�m�F�p�^�C�}Z�`���l��0��~����
	 */
	TZ_TSTR &= (UINT8)(~(TZ_TSTR_STR0)); /* �^�C�}��~ */
	TZ_TSR_0 &= (UINT8)(~(TZ_TSR_IMFA)); /* ���荞�ݗv�����N���A */

	/*
	 * ISR2�m�F�p�^�C�}B��~
	 */ 
	IENR2 &= (UINT8)(~(IENR2_IENTB1)); /* �^�C�}B1�I�[�o�[�t���[�����݋֎~ */
}

/*
 *  ISR1�EISR2�J�E���^�擾����
 *
 */
void
GetHwCnt( UINT8 *isr1_cnt, UINT8 *isr2_cnt )
{
	*isr1_cnt = hw_cnt1;
	*isr2_cnt = hw_cnt2;
}

/*
 *  ISR1�J�E���^���Z�p�����݃T�[�r�X���[�`��
 */
void
HwCnt1Int( void )
{
	TZ_TSR_0 &= (UINT8)(~(TZ_TSR_IMFA)); /* ���荞�ݗv�����N���A */
	hw_cnt1++;
}

/*
 *  ISR2�J�E���^���Z�p�����݃T�[�r�X���[�`��
 */
ISR( HwCnt2Int )
{
	/* �����݃N���A */
	IRR2 &= (UINT8)(~(IRR2_IRRTB1));
	
	hw_cnt2++;
}
