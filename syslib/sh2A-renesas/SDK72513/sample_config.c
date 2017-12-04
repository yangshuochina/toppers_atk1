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
 *	�T���v�������^�[�Q�b�g�ˑ����W���[���iSH2A HEW SDK72513�p�j
 */


#include	"sample_config.h"
#include	"sh72513.h"

#define CMSTR_STR1 (0x0002)
#define CMCR_CMIE (0x40)
#define	IPR05_IPL_CMT1_SHFT (8)
#define	IPR05_IPL_CMT1_MASK (~(0xF << IPR05_IPL_CMT1_SHFT))

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
 *  CMT1�Ŏ�������D
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
	CMSTR &= ~CMSTR_STR1;	/* �J�E���g��~ */

	/*
	 *  ������ ���ӃN���b�N 1/8(0.4us), ���荞�݋֎~
	 */
	CMCR_1 = 0;

	/*
	 *  ���荞�݃t���O�N���A
	 */
	CMSR_1 = 0;

	/*
	 *  �R���y�}�b�`�J�E���^�ڕW�l�ݒ�
	 *  �^�C�}�N������ɃR���y�A�}�b�`�����邽��
	 */
	CMCOR_1 = (UINT16)0x0001;

	/*
	 *  �^�C�}�R���y�A�����݃��x���ݒ�i�ݒ背�x���̓w�b�_�Q�Ɓj
	 */
	IPR05 = (IPR05 & IPR05_IPL_CMT1_MASK) 
					| ( CFG_INTLVL_COUNTER << IPR05_IPL_CMT1_SHFT);

	/*
	 *  �J�E���^�N���A�Ɗ����݋���
	 */
	CMCNT_1 = (UINT16)0x0000;		/* �J�E���g�N���A */
	CMSR_1  = 0;	/* CMF �N���A */
	CMCR_1	|= CMCR_CMIE;	/* ������ enable */

}	/* InitCounterInt	*/

/*
 *  SignalCounter���s�p�����ݒ�~����
 */
void
TermCounterInt( void )
{
	CMSTR &= ~CMSTR_STR1;	/* �J�E���g��~ */
	CMSR_1 = 0;	/* �@�\������ */
}	/* TermCounterInt	*/

/*
 *  SignalCounter���s�p�����݋N������
 */
void
ActCounterInt( void )
{
	CMCNT_1 = (UINT16)0x0000;		/* �J�E���g�N���A */
	CMSTR   |= CMSTR_STR1;				/* �J�E���g�J�n */
}	/* ActCounterInt	*/

/*
 *  SignalCounter���s�p�����݃T�[�r�X���[�`��
 */
ISR( CounterInt )
{
	StatusType ercd;
	UINT8 dmy;

	/*
	 *  1��̂� SignalCounter ���s���������߁C�^�C�}���~����D
	 */
	CMCR_1 &= ~CMCR_CMIE;	/* ������ disable */
	CMSTR  &= ~CMSTR_STR1;	/* �J�E���g��~ */

	/*
	 *  �����ݗv���N���A
	 */
	CMSR_1 = 0;	/* CMF �N���A */
	dmy = CMSR_1;	/* �_�~�[���[�h */

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
	 *  �^�C�}�c���~���Ċe���W�X�^�ݒ�
	 */
	ATUENR  &= ~ATUENR_TDE;
	TSTRD	&= ~(TSTRD_STRD0 | TSTRD_STRD1);
	DSTRD0  &= ~DSTRD0_DSTD00;		/* �_�E���J�E���g��~ */
	DSTRD1  &= ~DSTRD1_DSTD10;
	
	TCRD0	= TCRD0_DCSELD0;		/* �_�E���J�E���^�N���b�N�I�� */
	TCRD1	= TCRD1_DCSELD1;		/* �_�E���J�E���^�N���b�N�I�� */
	/*
	 *  �_�E���J�E���^�ݒ�
	 *  �J�E���^�̉��ʂW�r�b�g�͂O�Ƃ���
	 */
	DCNTD00 = CFG_HW_CNT1 << 8;
	DCNTD10 = CFG_HW_CNT2 << 8;

	/*
	 *  �^�C�}�R���y�A�����݃��x���ݒ�i�ݒ背�x���̓w�b�_�Q�Ɓj
	 */
	IPR10 = (IPR10 & 0xFF0F) | (CFG_INTLVL_HW_CNT1 << 4);
	IPR11 = (IPR11 & 0xF0FF) | (CFG_INTLVL_HW_CNT2 << 8);
	TSRD0 &= ~TSRD0_UDFD00;
	TSRD1 &= ~TSRD1_UDFD10;

	/*
	 * �����݋���
	 */
	TIERD0 |= TIERD0_UDED00;
	TIERD1 |= TIERD1_UDED10;

	/*
	 *  �^�C�}�J�E���g�J�n
	 */
	ATUENR  |= ATUENR_TDE;
	TSTRD	|= TSTRD_STRD0 | TSTRD_STRD1;
	DSTRD0  |= DSTRD0_DSTD00;
	DSTRD1  |= DSTRD1_DSTD10;

}	/* InitHwCntInt	*/

/*
 *  ISR1�EISR2�J�E���^��~����
 */
void
TermHwCntInt( void )
{
	TIERD0 &= ~TIERD0_UDED00;	/* ���荞�݋֎~ */
	TIERD1 &= ~TIERD1_UDED10;
	DSTRD0 &= ~DSTRD0_DSTD00;		/* �_�E���J�E���g��~ */
	DSTRD1 &= ~DSTRD1_DSTD10;
	TSTRD	&= ~(TSTRD_STRD0 | TSTRD_STRD1);
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
	UINT16	dmy;
	/* �����ݗv���N���A */
	TSRD0 &= ~TSRD0_UDFD00;
	dmy = TSRD0;	/* �_�~�[���[�h */

	/* �^�C�}�J�E���g�J�n */
	DCNTD00 = CFG_HW_CNT1 << 8;
	DSTRD0  |= DSTRD0_DSTD00;
	
	hw_cnt1++;
}	/* HwCnt1Int	*/

/*
 *  ISR2�J�E���^���Z�p�����݃T�[�r�X���[�`��
 */
ISR( HwCnt2Int )
{
	UINT16	dmy;
	/* �����ݗv���N���A */
	TSRD1 &= ~TSRD1_UDFD10;
	dmy = TSRD1;	/* �_�~�[���[�h */

	/* �^�C�}�J�E���g�J�n */
	DCNTD10 = CFG_HW_CNT2 << 8;
	DSTRD1  |= DSTRD1_DSTD10;

	hw_cnt2++;
}	/* ISR( HwCnt2Int )	*/


