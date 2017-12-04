/*
 *  TOPPERS Automotive Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 *      Automotive Kernel
 * 
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
 *	�T���v�������^�[�Q�b�g�ˑ����W���[���iSH2 HEW EVA�{�[�h�p�j
 */


#include	"sample_config.h"
#include	"sh7058.h"


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
 */
UINT8
GetAppModeInfo( void )
{
	/*
	 *  �{���͂����ŃA�v���P�[�V�������[�h�̔�����s���ׂ������A
	 *  �{�[�h��Ƀ��[�h���擾�ł���H/W����������Ă��Ȃ����߁A
	 *  ���0��Ԃ��D
	 */
	
	return 0;

}	/* GetAppModeInfo	*/


/*
 *  �T���v���J�E���^�\�[�X�p
 *
 *  SH7058 �ł�CMT1�Ŏ�������D
 */

/*
 *  SignalCounter���s�p�����ݏ���������
 *
 *  �^�C�}�̋N���͕ʊ֐��ōs���D
 */
void
InitCounterInt( void )
{
	/*
	 *  �R���y�A�}�b�`�^�C�}���~���Ċe���W�X�^�ݒ�
	 */
	P_CMT.CMSTR.BIT.STR1 = 0;		/* �J�E���g��~ */

	/*
	 *  ������ ���ӃN���b�N 1/8, ���荞�݋֎~
	 *  CMCSR �� bit6 �������ݗv���t���O�ł���C�����ɃN���A���Ă���D
	 */
	P_CMT.CMCSR1.WORD = (UINT16)0x0000;

	/*
	 *  �R���y�}�b�`�J�E���^�ڕW�l�ݒ�
	 *  �^�C�}�N������ɃR���y�A�}�b�`�����邽��
	 */
	P_CMT.CMCOR1 = (UINT16)0x0001;

	/*
	 *  �^�C�}�R���y�A�����݃��x���ݒ�i�ݒ背�x���̓w�b�_�Q�Ɓj
	 */
	P_INTC.IPRJ.BIT.CMT1_AD1 = CFG_INTLVL_COUNTER;

	/*
	 *  �J�E���^�N���A�Ɗ����݋���
	 */
	P_CMT.CMCNT1 = 0x0000;				/* �J�E���g�N���A */
	P_CMT.CMCSR1.BIT.CMIE = 1;				/* �R���y�A�}�b�`�����݋��� */

}	/* InitCounterInt	*/

/*
 *  SignalCounter���s�p�����ݒ�~����
 */
void
TermCounterInt( void )
{
	P_CMT.CMSTR.BIT.STR1 = 0;		/* �J�E���g��~ */
	P_CMT.CMCSR1.WORD = (UINT16)0x0000;			/* �@�\������ */
}	/* TermCounterInt	*/

/*
 *  SignalCounter���s�p�����݋N������
 */
void
ActCounterInt( void )
{
	P_CMT.CMCNT1 = 0x0000;			/* �J�E���g�N���A */
	P_CMT.CMSTR.BIT.STR1 = 1;		/* �J�E���g�J�n */
}	/* ActCounterInt	*/

/*
 *  SignalCounter���s�p�����݃T�[�r�X���[�`��
 */
ISR( CounterInt )
{
	StatusType ercd;

	/*
	 *  1��̂� SignalCounter ���s���������߁C�^�C�}���~����D
	 */
	P_CMT.CMCSR1.BIT.CMIE = 0;				/* �R���y�A�}�b�`�����݋֎~ */
	P_CMT.CMSTR.BIT.STR1 = 0;		/* �J�E���g��~ */

	/*
	 *  �����ݗv���N���A
	 */
	P_CMT.CMCSR1.BIT.CMF = 0;		/* �����ݗv���N���A */

	/*
	 *  �J�E���^���Z�ʒm�������s
	 */
	ercd = SignalCounter( SampleCnt );

	/* �G���[���^�[���̏ꍇ�̓V���b�g�_�E��	*/
	if( ercd != E_OK ){
		ShutdownOS( ercd );
	}
}	/* ISR( CounterInt )	*/


/*
 *  ISR1�EISR2�ғ��m�F�p
 *
 *  7058 �ł� ATU channel 8A, 8E �Ŏ�������D
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
	/*
	 *  �n�[�h�E�F�A�J�E���^������
	 */
	hw_cnt1 = (UINT8)0;
	hw_cnt2 = (UINT8)0;

	/*
	 *  �^�C�}���~���Ċe���W�X�^�ݒ�
	 */
	P_ATUII.PSCR1.BYTE = 0;			/* ATU �v���X�P�[�� P��/1 */
									/* ATU ���ʂȂ̂ŁAsys_initialize() �ŃZ�b�g���ׂ� */
	P_ATUII8.DSTR.BIT.DST8A = 0;		/* �_�E���J�E���g��~ */
	P_ATUII8.DSTR.BIT.DST8E = 0;
	P_ATUII8.TCNR.BIT.CN8A = 0;		/* �^�C�}�R�l�N�V���� ���� */
	P_ATUII8.TCNR.BIT.CN8E = 0;
	P_ATUII8.OTR.BIT.OTEA = 0;		/* Output terminate ���� */
	P_ATUII8.OTR.BIT.OTEE = 0;
	P_ATUII8.RLDENR.BIT.RLDEN = 0;	/* Reload ���� */
	
	/*
	 *  �^�C�}�`���l��8A-H   1/32����
	 */
	P_ATUII8.TCR8.BIT.CKSELA = 5;		
	

	/*
	 *  �_�E���J�E���^�ݒ�
	 */
	P_ATUII8.DCNT8A = CFG_HW_CNT1;
	P_ATUII8.DCNT8E = CFG_HW_CNT2;

	/*
	 *  �^�C�}�R���y�A�����݃��x���ݒ�i�ݒ背�x���̓w�b�_�Q�Ɓj
	 *  TSR �� bit0,1 �������ݗv���t���O�ɂ��N���A���Ă���D
	 */
	P_INTC.IPRH.BIT.ATU81 = CFG_INTLVL_HW_CNT1;
	P_INTC.IPRH.BIT.ATU82 = CFG_INTLVL_HW_CNT2;
	P_ATUII8.TSR8.BIT.OSF8A  = 0;
	P_ATUII8.TSR8.BIT.OSF8E = 0;

	/*
	 * �����݋��� A,E
	 */
	P_ATUII8.TIER8.BIT.OSE8A = 1;
	P_ATUII8.TIER8.BIT.OSE8E = 1;

	/*
	 *  �^�C�}�J�E���g�J�n
	 */
	P_ATUII8.DSTR.BIT.DST8A = 1;
	P_ATUII8.DSTR.BIT.DST8E = 1;

}	/* InitHwCntInt	*/

/*
 *  ISR1�EISR2�J�E���^��~����
 */
void
TermHwCntInt( void )
{
	P_ATUII8.TIER8.BIT.OSE8A = 0;	/* ���荞�݋֎~ */
	P_ATUII8.TIER8.BIT.OSE8E = 0;
	P_ATUII8.DSTR.BIT.DST8A = 0;	/* �_�E���J�E���g��~ */
	P_ATUII8.DSTR.BIT.DST8E = 0;
}	/* TermHwCntInt	*/

/*
 *  ISR1�EISR2�J�E���^�擾����
 *
 *  hw_cnt1��hw_cnt2�̓����擾�͕ۏႵ�Ȃ��Ă悢�i�����݋֎~�͕s�v�j�D
 */
void
GetHwCnt( UINT8 *isr1_cnt, UINT8 *isr2_cnt )
{
	*isr1_cnt = hw_cnt1;
	*isr2_cnt = hw_cnt2;
}	/* GetHwCnt	*/

/*
 *  ISR1�J�E���^���Z�p�����݃T�[�r�X���[�`��
 */
#if defined( OMIT_ISR1_ENTRY )
/* ISR1��������������͖{�֐��������݊֐��w�肷��	*/
#pragma interrupt	HwCnt1Int
#endif	/* OMIT_ISR1_ENTRY	*/
void	HwCnt1Int( void );
void
HwCnt1Int( void )
{
	/* �����ݗv���N���A */
	P_ATUII8.DCNT8A = CFG_HW_CNT1;
	P_ATUII8.TSR8.BIT.OSF8A  = 0;
	P_ATUII8.DSTR.BIT.DST8A = 1;

	hw_cnt1++;
}	/* HwCnt1Int	*/

/*
 *  ISR2�J�E���^���Z�p�����݃T�[�r�X���[�`��
 */
ISR( HwCnt2Int )
{
	/* �����ݗv���N���A */
	P_ATUII8.DCNT8E = CFG_HW_CNT2;
	P_ATUII8.TSR8.BIT.OSF8E  = 0;
	P_ATUII8.DSTR.BIT.DST8E = 1;

	hw_cnt2++;
}	/* ISR( HwCnt2Int )	*/


