/*
 *  TOPPERS/OSEK Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      OSEK Kernel
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
 *	�T���v�������^�[�Q�b�g�ˑ����W���[���iOAKS32�p�j
 */


#include	"sample_config.h"
#include	"sfrm32c83.h"


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
 *  oaks32�ł͎��ӓ��̓f�o�C�X���Ȃ��̂ŁC�|�[�g10��bit0,bit1��
 *  �v���A�b�v���͂ɂĎg�p����D
 */
UINT8
GetAppModeInfo( void )
{
	/*
	 *  �|�[�g10��bit0,bit1���v���A�b�v���͂ɂ���D
	 */
	PD10_0 = 0;
	PD10_1 = 0;
	PU30 = 1;

	/*
	 *  ���_���ŉ���2bit��Ǎ���
	 */
	return (UINT8)( (UINT8)(~P10) & (UINT8)( 0x03 ) );
}	/* GetAppModeInfo	*/


/*
 *  �T���v���J�E���^�\�[�X�p
 *
 *  oaks32�ł̓^�C�}A1�Ŏ�������D
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
	 *  �^�C�}���~���Ċe���W�X�^�ݒ�
	 */
	TA1S = 0;	/* �J�E���g��~	*/

	/*
	 *  �^�C�}A1�_�E���J�E���g, �^�C�}���[�h, �J�E���g�\�[�Xf1
	 */
	TA1UD = (UINT8)( 0 );
	TA1MR = (UINT8)( 0 );

	/*
	 *  �^�C�}�N������ɃR���y�A���������̂ŁC�Œ�l��ݒ肷��D
	 */
	TA1 = (UINT16)( 1 );

}	/* InitCounterInt	*/

/*
 *  SignalCounter���s�p�����ݒ�~����
 */
void
TermCounterInt( void )
{
	TA1IC = (UINT8)( 0 );	/* �����݃}�X�N			*/
	TA1S = 0;				/* �^�C�}A1�J�E���g��~	*/
}	/* TermCounterInt	*/

/*
 *  SignalCounter���s�p�����݋N������
 */
void
ActCounterInt( void )
{
	/*
	 *  �^�C�}�R���y�A�����݃��x���ݒ�i�ݒ背�x���̓w�b�_�Q�Ɓj
	 *  TA1IC �� bit3 �������ݗv���t���O�ł���C�����ɃN���A���Ă���D
	 */
	TA1IC = CFG_INTLVL_COUNTER;
	TA1S = 1;	/* �^�C�}A1�J�E���g�J�n	*/
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
	TA1IC = (UINT8)( 0 );	/* �����݃}�X�N			*/
	TA1S = 0;				/* �^�C�}A1�J�E���g��~	*/
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
 *  oaks32�ł̓^�C�}B0,B1�Ŏ�������D
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
	hw_cnt1 = (UINT8)( 0 );
	hw_cnt2 = (UINT8)( 0 );

	/*
	 *  �^�C�}���~���Ċe���W�X�^�ݒ�
	 */
	TB0S = 0;	/* �J�E���g��~	*/
	TB1S = 0;	/* �J�E���g��~	*/

	/*
	 *  �^�C�}���[�h, �J�E���g�\�[�Xf1
	 */
	TB0MR = (UINT8)( 0 );
	TB1MR = (UINT8)( 0 );

	/*
	 *  �n�[�h�E�F�A�d�l�ɂă^�C�}�\�[�X�̃��W�X�^�ݒ�l+1�������邽��,
	 *  ���W�X�^�ݒ�l�̓V�X�e���N���b�N�����ɑ�������J�E���g������
	 *  �}�C�i�X1����l��ݒ肷��.�i�ݒ�l�̓w�b�_�Q�Ɓj
	 */
	TB0 = CFG_HW_CNT1 - (UINT16)( 1 );
	TB1 = CFG_HW_CNT2 - (UINT16)( 1 );

	/*
	 *  �^�C�}�R���y�A�����݃��x���ݒ�i�ݒ背�x���̓w�b�_�Q�Ɓj
	 *  TB0IC, TB1IC �� bit3 �������ݗv���t���O�ł���C�����ɃN���A���Ă���D
	 */
	TB0IC = CFG_INTLVL_HW_CNT1;
	TB1IC = CFG_INTLVL_HW_CNT2;

	TB0S = 1;	/* �J�E���g�J�n	*/
	TB1S = 1;	/* �J�E���g�J�n	*/
}	/* InitHwCntInt	*/

/*
 *  ISR1�EISR2�J�E���^��~����
 */
void
TermHwCntInt( void )
{
	TB0IC = (UINT8)( 0 );	/* �����݃}�X�N			*/
	TB1IC = (UINT8)( 0 );	/* �����݃}�X�N			*/
	TB0S = 0;				/* �J�E���g��~			*/
	TB1S = 0;				/* �J�E���g��~			*/
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
#pragma INTERRUPT	HwCnt1Int
#endif	/* OMIT_ISR1_ENTRY	*/
void	HwCnt1Int( void );
void
HwCnt1Int( void )
{
	hw_cnt1++;
}	/* HwCnt1Int	*/

/*
 *  ISR2�J�E���^���Z�p�����݃T�[�r�X���[�`��
 */
ISR( HwCnt2Int )
{
	hw_cnt2++;
}	/* ISR( HwCnt2Int )	*/


