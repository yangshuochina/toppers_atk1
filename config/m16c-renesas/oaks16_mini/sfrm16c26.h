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
 *  SFR�w�b�_�t�@�C���iM16C/26�p�j
 */
#if !defined( _SFR_M16C_26_H_ )				/* ��d��`�h�~					*/
#define		_SFR_M16C_26_H_					/* ��d��`�h�~					*/


/********************************************************/
/* �d�����o��H											*/
/********************************************************/
/*
 *  Power supply detection register 1
 */
#pragma ADDRESS		vcr1_addr	0019H		/* �d�����o���W�X�^1			*/
typedef union {
	struct {
		UINT8	reserve1:3;	/* RW 0�Œ�										*/
		UINT8	vc13:1;		/* RW �d���ቺ���j�^ 0:VCC��Vdet4, 1:VCC��Vdet4	*/
		UINT8	reserve2:4;	/* RW 0�Œ�										*/
	} bit;
	UINT8	byte;
} VCR1_TYPE;
VCR1_TYPE	vcr1_addr;

#define		VCR1			vcr1_addr.byte
#define		VC13			vcr1_addr.bit.vc13

/*
 *  Power supply detection register 2
 */
#pragma ADDRESS		vcr2_addr	001aH		/* �d�����o���W�X�^2			*/
typedef union {
	struct {
		UINT8	reserve:6;	/* RW 0�Œ�										*/
		UINT8	vc26:1;		/* RW ���Z�b�g�̈�Ď� 0:����, 1:�L��			*/
		UINT8	vc27:1;		/* RW �d���ቺ�Ď� 0:����, 1:�L��				*/
	} bit;
	UINT8	byte;
} VCR2_TYPE;
VCR2_TYPE	vcr2_addr;

#define		VCR2			vcr2_addr.byte
#define		VC26			vcr2_addr.bit.vc26
#define		VC27			vcr2_addr.bit.vc27

/*
 *  Power supply 4V detection register
 */
#pragma ADDRESS		d4int_addr	001fH		/* �d���ቺ���o���荞�݃��W�X�^	*/
typedef union {
	struct {
		UINT8	d40:1;		/* RW �d���ቺ���o���荞�݋��� 0:�֎~, 1:����	*/
		UINT8	d41:1;		/* RW STOP�������� 0:����, 1:�L��				*/
		UINT8	d42:1;		/* RW �d���ω����o 0:�����o, 1:Vdet4�ʉߌ��o	*/
		UINT8	d43:1;		/* RW WDT�A���_�t���[���o 0:�����o, 1:���o		*/
		UINT8	df0:1;		/* RW �T���v�����O�N���b�N�I��(df0��df1�Ŏw��)	*/
		UINT8	df1:1;		/*    00:8����, 01:16����, 10:32����, 11:64����	*/
		UINT8	no_assign:2;/* -  �s�� �����ޏꍇ��0						*/
	} bit;
} D4INT_TYPE;
D4INT_TYPE	d4int_addr;

#define		D4INT			d4int_addr.byte
#define		D40				d4int_addr.bit.d40
#define		D41				d4int_addr.bit.d41
#define		D42				d4int_addr.bit.d42
#define		D43				d4int_addr.bit.d43
#define		Df0				d4int_addr.bit.df0
#define		Df1				d4int_addr.bit.df1


/********************************************************/
/* �v���Z�b�T���[�h										*/
/********************************************************/
/*
 *  Processor mode register 0
 */
#pragma ADDRESS		pm0_addr	0004H		/* �v���Z�b�T���[�h���W�X�^0	*/
typedef union {
	struct {
		UINT8	pm00:1;		/* RW �v���Z�b�T���[�h(pm00,pm01�Ŏw��)			*/
		UINT8	pm01:1;		/* RW 00B:�V���O���`�b�v, 01B:�ݒ�֎~			*/
							/*    10B:�ݒ�֎~, 11B:�ݒ�֎~				*/
		UINT8	reserve1:1;	/* RW 0�Œ�										*/
		UINT8	pm03:1;		/* RW �\�t�g�E�F�A���Z�b�g 0:�ʏ펞,1:���Z�b�g	*/
		UINT8	reserve2:4;	/* RW 0�Œ�										*/
	} bit;
	UINT8 byte;
} PM0_TYPE;
PM0_TYPE	pm0_addr;

#define		PM0				pm0_addr.byte
#define		PM00			pm0_addr.bit.pm00
#define		PM01			pm0_addr.bit.pm01
#define		PM03			pm0_addr.bit.pm03

/*
 *  Processor mode register 1
 */
#pragma ADDRESS		pm1_addr	0005H		/* �v���Z�b�T���[�h���W�X�^1	*/
typedef union {
	struct {
		UINT8	pm10:1;		/* RW �f�[�^�̈�A�N�Z�X 0:�֎~, 1:����			*/
		UINT8	reserve1:1;	/* RW 0�Œ�										*/
		UINT8	pm12:1;		/* RW �Ď��^�C�}�@�\�I��						*/
							/*       0:�Ď��^�C�}������, 1:���Z�b�g			*/
		UINT8	reserve2:1;	/* RW 1�Œ�										*/
		UINT8	reserve3:2;	/* RW 0�Œ�										*/
		UINT8	reserve4:1;	/* W  0�Œ�										*/
		UINT8	pm17:1;		/* RW �E�F�C�g 0:�Ȃ�, 1:����					*/
	} bit;
	UINT8 byte;
} PM1_TYPE;
PM1_TYPE	pm1_addr;

#define		PM1				pm1_addr.byte
#define		PM10			pm1_addr.bit.pm10
#define		PM12			pm1_addr.bit.pm12
#define		PM17			pm1_addr.bit.pm17


/********************************************************/
/* �N���b�N������H										*/
/********************************************************/
/*
 *  System clock control register 0
 */
#pragma ADDRESS		cm0_addr	0006H		/* �V�X�e���N���b�N���䃌�W�X�^0*/
typedef union {
	struct {
		UINT8	reserve:2;	/* RW 0�Œ�										*/
		UINT8	cm02:1;		/* RW WAIT�����Ӌ@�\�N���b�N��~				*/
							/*    0:�N���b�N��~���Ȃ�, 1:�N���b�N��~����	*/
		UINT8	cm03:1;		/* RW XCIN-XCOUT�쓮�\�͑I�� 0:Low, 1:High		*/
		UINT8	cm04:1;		/* RW �|�[�gXC�؂�ւ� 0:���o�̓|�[�gP86�AP87	*/
							/*    1:XCIN-XCOUT���U�@�\						*/
		UINT8	cm05:1;		/* RW ���C���N���b�N��~ 0:���U, 1:��~			*/
		UINT8	cm06:1;		/* RW ���C���N���b�N������I��					*/
							/*    0:CM16�ACM17�r�b�g�L��, 8�������[�h		*/
		UINT8	cm07:1;		/* RW �V�X�e���N���b�N�I�� 0:���C��, 1:�T�u		*/
	} bit;
	UINT8	byte;
} CM0_TYPE;
CM0_TYPE	cm0_addr;

#define		CM0				cm0_addr.byte
#define		CM02			cm0_addr.bit.cm02
#define		CM03			cm0_addr.bit.cm03
#define		CM04			cm0_addr.bit.cm04
#define		CM05			cm0_addr.bit.cm05
#define		CM06			cm0_addr.bit.cm06
#define		CM07			cm0_addr.bit.cm07

/*
 *  System clock control register 1
 */
#pragma ADDRESS		cm1_addr	0007H		/* �V�X�e���N���b�N���䃌�W�X�^1*/
typedef union {
	struct {
		UINT8	cm10:1;		/* RW �S�N���b�N��~���� 0:���U, 1:��~			*/
		UINT8	reserve:4;	/* RW 0�Œ�										*/
		UINT8	cm15:1;		/* RW XIN-XOUT�쓮�\�͑I�� 0:LOW, 1:HIGH		*/
		UINT8	cm16:1;		/* RW ���C���N���b�N������I��(cm16,cm17�Ŏw��)	*/
		UINT8	cm17:1;		/*    00:�����Ȃ�, 01:2����, 10:4����, 11:16����*/
	} bit;
	UINT8	byte;
} CM1_TYPE;
CM1_TYPE	cm1_addr;

#define		CM1				cm1_addr.byte
#define		CM10			cm1_addr.bit.cm10
#define		CM15			cm1_addr.bit.cm15
#define		CM16			cm1_addr.bit.cm16
#define		CM17			cm1_addr.bit.cm17

/*
 *  System clock control register 2
 */
#pragma ADDRESS		cm2_addr	000cH		/* ���U��~���o���W�X�^			*/
typedef union {
	struct {
		UINT8	cm20:1;		/* RW ���U��~�A�Ĕ��U���o���� 0:����, 1:�L��	*/
		UINT8	cm21:1;		/* RW �V�X�e���N���b�N�I�� 0:���C��, 1:�����O	*/
		UINT8	cm22:1;		/* RW ���U��~�A�Ĕ��U���o 0:�����o, 1:���o		*/
		UINT8	cm23:1;		/* RW XIN���j�^�t���O 0:���U, 1:��~			*/
		UINT8	reserve:2;	/* RW 0�Œ�										*/
		UINT8	no_assign:1;/* -  �s�� �����ޏꍇ��0						*/
		UINT8	cm27:1;		/* RW ���U��~�A�Ĕ��U���o���̓���I��			*/
							/*    0:���Z�b�g, 1:�Ĕ��U���o���荞��			*/
	} bit;
	UINT8	byte;
} CM2_TYPE;
CM2_TYPE	cm2_addr;

#define		CM2				cm2_addr.byte
#define		CM20			cm2_addr.bit.cm20
#define		CM21			cm2_addr.bit.cm21
#define		CM22			cm2_addr.bit.cm22
#define		CM23			cm2_addr.bit.cm23
#define		CM27			cm2_addr.bit.cm27

/*
 *  Peripheral Clock Select Register
 */
#pragma ADDRESS		pclkr_addr	025eH		/* ���ӃN���b�N�I�����W�X�^		*/
typedef union {
	struct {
		UINT8	pclk0:1;	/* RW �^�C�}A�AB�N���b�N�I�� 0:f2, 1:f1			*/
		UINT8	pclk1:1;	/* RW SI/O�N���b�N�I�� 0:f2SIO, 1:f1SIO			*/
		UINT8	reserve:6;	/* RW 0�Œ�										*/
	} bit;
	UINT8	byte;
} PCLKR_TYPE;
PCLKR_TYPE	pclkr_addr;

#define		PCLKR			pclkr_addr.byte
#define		PCLK0			pclkr_addr.bit.pclk0
#define		PCLK1			pclkr_addr.bit.pclk1

/*
 *  Processor mode register 2
 */
#pragma ADDRESS		pm2_addr	001eH		/* �v���Z�b�T���[�h���W�X�^2	*/
typedef union {
	struct {
		UINT8	pm20:1;		/* RW SFR�A�N�Z�X�̃E�G�C�g�w�� 0:2, 1:1		*/
		UINT8	pm21:1;		/* RW �V�X�e���N���b�N�ی� 0:�ی�,1:�ύX�֎~	*/
		UINT8	pm22:1;		/* RW WDT�J�E���g�\�[�X�ی� 0:CPU�N���b�N		*/
							/*       1:�����O�N���b�N						*/
		UINT8	reserve:1;	/* RW 0�Œ�										*/
		UINT8	pm24:1;		/* RW P85/NMI�@�\�؂�ւ� 0:P85, 1:NMI			*/
		UINT8	no_assign:3;/* -  �s�� �����ޏꍇ��0						*/
	} bit;
	UINT8	byte;
} PM2_TYPE;
PM2_TYPE	pm2_addr;

#define		PM2				pm2_addr.byte
#define		PM20			pm2_addr.bit.pm20
#define		PM21			pm2_addr.bit.pm21
#define		PM22			pm2_addr.bit.pm22
#define		PM24			pm2_addr.bit.pm24


/********************************************************/
/* �v���e�N�g											*/
/********************************************************/
/*
 *  Protect register
 */
#pragma ADDRESS		prcr_addr	000aH		/* �v���e�N�g���W�X�^			*/
typedef union {
	struct {
		UINT8	prc0:1;		/* RW �v���e�N�g0 0:�֎~, 1:����				*/
		UINT8	prc1:1;		/* RW �v���e�N�g1 0:�֎~, 1:����				*/
		UINT8	prc2:1;		/* RW �v���e�N�g2 0:�֎~, 1:����				*/
		UINT8	prc3:1;		/* RW �v���e�N�g3 0:�֎~, 1:����				*/
		UINT8	reserve:2;	/* RW 0�Œ�										*/
		UINT8	no_assign:2;/* -  �s�� �����ޏꍇ��0						*/
	} bit;
	UINT8	byte;
} PRCR_TYPE;
PRCR_TYPE	prcr_addr;

#define		PRCR			prcr_addr.byte
#define		PRC0			prcr_addr.bit.prc0
#define		PRC1			prcr_addr.bit.prc1
#define		PRC2			prcr_addr.bit.prc2
#define		PRC3			prcr_addr.bit.prc3


/********************************************************/
/* ���荞��												*/
/********************************************************/
/*
 *  interrupt control register1
 */
typedef union {
	struct {
		UINT8	ilvl0:1;	/* RW ���荞�ݗD�惌�x��(ilvl0,ilvl1,ilvl2�w��)	*/
		UINT8	ilvl1:1;	/*    000:���x��0, 001:���x��1, 010:���x��2		*/
		UINT8	ilvl2:1;	/*    011:���x��3, 100:���x��4, 101:���x��5		*/
							/*    110:���x��6, 111:���x��7					*/
		UINT8	ir:1;		/* RW ���荞�ݗv�� 0:�Ȃ�, 1:����				*/
		UINT8	no_assign:4;/* -  �s�� �����ޏꍇ��0						*/
	} bit;
	UINT8	byte;
} ICR1_TYPE;


/*
 *  Bus collision detection interrupt control register
 */
#pragma ADDRESS		bcnic_addr	004aH		/* BCNIC �����ݐ��䃌�W�X�^		*/
ICR1_TYPE	bcnic_addr;

#define		BCNIC			bcnic_addr.byte
#define		ILVL0_BCNIC		bcnic_addr.bit.ilvl0
#define		ILVL1_BCNIC		bcnic_addr.bit.ilvl1
#define		ILVL2_BCNIC		bcnic_addr.bit.ilvl2
#define		IR_BCNIC		bcnic_addr.bit.ir

/*
 *  DMA0 interrupt control register
 */
#pragma ADDRESS		dm0ic_addr	004bH		/* DM0IC �����ݐ��䃌�W�X�^		*/
ICR1_TYPE	dm0ic_addr;

#define		DM0IC			dm0ic_addr.byte
#define		ILVL0_DM0IC		dm0ic_addr.bit.ilvl0
#define		ILVL1_DM0IC		dm0ic_addr.bit.ilvl1
#define		ILVL2_DM0IC		dm0ic_addr.bit.ilvl2
#define		IR_DM0IC		dm0ic_addr.bit.ir

/*
 *  DMA1 interrupt control register
 */
#pragma ADDRESS		dm1ic_addr	004cH		/* DM1IC �����ݐ��䃌�W�X�^		*/
ICR1_TYPE	dm1ic_addr;

#define		DM1IC			dm1ic_addr.byte
#define		ILVL0_DM1IC		dm1ic_addr.bit.ilvl0
#define		ILVL1_DM1IC		dm1ic_addr.bit.ilvl1
#define		ILVL2_DM1IC		dm1ic_addr.bit.ilvl2
#define		IR_DM1IC		dm1ic_addr.bit.ir

/*
 *  Key input interrupt control register
 */
#pragma ADDRESS		kupic_addr	004dH		/* KUPIC �����ݐ��䃌�W�X�^		*/
ICR1_TYPE	kupic_addr;

#define		KUPIC			kupic_addr.byte
#define		ILVL0_KUPIC		kupic_addr.bit.ilvl0
#define		ILVL1_KUPIC		kupic_addr.bit.ilvl1
#define		ILVL2_KUPIC		kupic_addr.bit.ilvl2
#define		IR_KUPIC		kupic_addr.bit.ir

/*
 *  A-D conversion interrupt control register
 */
#pragma ADDRESS		adic_addr	004eH		/* ADIC �����ݐ��䃌�W�X�^		*/
ICR1_TYPE	adic_addr;

#define		ADIC			adic_addr.byte
#define		ILVL0_ADIC		adic_addr.bit.ilvl0
#define		ILVL1_ADIC		adic_addr.bit.ilvl1
#define		ILVL2_ADIC		adic_addr.bit.ilvl2
#define		IR_ADIC			adic_addr.bit.ir

/*
 *  UART0 transmit interrupt control register
 */
#pragma ADDRESS		s0tic_addr	0051H		/* S0TIC �����ݐ��䃌�W�X�^		*/
ICR1_TYPE	s0tic_addr;

#define		S0TIC			s0tic_addr.byte
#define		ILVL0_S0TIC		s0tic_addr.bit.ilvl0
#define		ILVL1_S0TIC		s0tic_addr.bit.ilvl1
#define		ILVL2_S0TIC		s0tic_addr.bit.ilvl2
#define		IR_S0TIC		s0tic_addr.bit.ir

/*
 *  UART1 transmit interrupt control register
 */
#pragma ADDRESS		s1tic_addr	0053H		/* S1TIC �����ݐ��䃌�W�X�^		*/
ICR1_TYPE	s1tic_addr;

#define		S1TIC			s1tic_addr.byte
#define		ILVL0_S1TIC		s1tic_addr.bit.ilvl0
#define		ILVL1_S1TIC		s1tic_addr.bit.ilvl1
#define		ILVL2_S1TIC		s1tic_addr.bit.ilvl2
#define		IR_S1TIC		s1tic_addr.bit.ir

/*
 *  UART2 transmit interrupt control register
 */
#pragma ADDRESS		s2tic_addr	004fH		/* S2TIC �����ݐ��䃌�W�X�^		*/
ICR1_TYPE	s2tic_addr;

#define		S2TIC			s2tic_addr.byte
#define		ILVL0_S2TIC		s2tic_addr.bit.ilvl0
#define		ILVL1_S2TIC		s2tic_addr.bit.ilvl1
#define		ILVL2_S2TIC		s2tic_addr.bit.ilvl2
#define		IR_S2TIC		s2tic_addr.bit.ir

/*
 *  UART0 receive interrupt control register
 */
#pragma ADDRESS		s0ric_addr	0052H		/* S0RIC �����ݐ��䃌�W�X�^		*/
ICR1_TYPE	s0ric_addr;

#define		S0RIC			s0ric_addr.byte
#define		ILVL0_S0RIC		s0ric_addr.bit.ilvl0
#define		ILVL1_S0RIC		s0ric_addr.bit.ilvl1
#define		ILVL2_S0RIC		s0ric_addr.bit.ilvl2
#define		IR_S0RIC		s0ric_addr.bit.ir

/*
 *  UART1 receive interrupt control register
 */
#pragma ADDRESS		s1ric_addr	0054H		/* S1RIC �����ݐ��䃌�W�X�^		*/
ICR1_TYPE	s1ric_addr;

#define		S1RIC			s1ric_addr.byte
#define		ILVL0_S1RIC		s1ric_addr.bit.ilvl0
#define		ILVL1_S1RIC		s1ric_addr.bit.ilvl1
#define		ILVL2_S1RIC		s1ric_addr.bit.ilvl2
#define		IR_S1RIC		s1ric_addr.bit.ir

/*
 *  UART2 receive interrupt control register
 */
#pragma ADDRESS		s2ric_addr	0050H		/* S2RIC �����ݐ��䃌�W�X�^		*/
ICR1_TYPE	s2ric_addr;

#define		S2RIC			s2ric_addr.byte
#define		ILVL0_S2RIC		s2ric_addr.bit.ilvl0
#define		ILVL1_S2RIC		s2ric_addr.bit.ilvl1
#define		ILVL2_S2RIC		s2ric_addr.bit.ilvl2
#define		IR_S2RIC		s2ric_addr.bit.ir

/*
 *  Timer A0 interrupt control register
 */
#pragma ADDRESS		ta0ic_addr	0055H		/* TA0IC �����ݐ��䃌�W�X�^		*/
ICR1_TYPE	ta0ic_addr;

#define		TA0IC			ta0ic_addr.byte
#define		ILVL0_TA0IC		ta0ic_addr.bit.ilvl0
#define		ILVL1_TA0IC		ta0ic_addr.bit.ilvl1
#define		ILVL2_TA0IC		ta0ic_addr.bit.ilvl2
#define		IR_TA0IC		ta0ic_addr.bit.ir

/*
 *  Timer A1 interrupt control register
 */
#pragma ADDRESS		ta1ic_addr	0056H		/* TA1IC �����ݐ��䃌�W�X�^		*/
ICR1_TYPE	ta1ic_addr;

#define		TA1IC			ta1ic_addr.byte
#define		ILVL0_TA1IC		ta1ic_addr.bit.ilvl0
#define		ILVL1_TA1IC		ta1ic_addr.bit.ilvl1
#define		ILVL2_TA1IC		ta1ic_addr.bit.ilvl2
#define		IR_TA1IC		ta1ic_addr.bit.ir

/*
 *  Timer A2 interrupt control register
 */
#pragma ADDRESS		ta2ic_addr	0057H		/* TA2IC �����ݐ��䃌�W�X�^		*/
ICR1_TYPE	ta2ic_addr;

#define		TA2IC			ta2ic_addr.byte
#define		ILVL0_TA2IC		ta2ic_addr.bit.ilvl0
#define		ILVL1_TA2IC		ta2ic_addr.bit.ilvl1
#define		ILVL2_TA2IC		ta2ic_addr.bit.ilvl2
#define		IR_TA2IC		ta2ic_addr.bit.ir

/*
 *  Timer A3 interrupt control register
 */
#pragma ADDRESS		ta3ic_addr	0058H		/* TA3IC �����ݐ��䃌�W�X�^		*/
ICR1_TYPE	ta3ic_addr;

#define		TA3IC			ta3ic_addr.byte
#define		ILVL0_TA3IC		ta3ic_addr.bit.ilvl0
#define		ILVL1_TA3IC		ta3ic_addr.bit.ilvl1
#define		ILVL2_TA3IC		ta3ic_addr.bit.ilvl2
#define		IR_TA3IC		ta3ic_addr.bit.ir

/*
 *  Timer A4 interrupt control register
 */
#pragma ADDRESS		ta4ic_addr	0059H		/* TA4IC �����ݐ��䃌�W�X�^		*/
ICR1_TYPE	ta4ic_addr;

#define		TA4IC			ta4ic_addr.byte
#define		ILVL0_TA4IC		ta4ic_addr.bit.ilvl0
#define		ILVL1_TA4IC		ta4ic_addr.bit.ilvl1
#define		ILVL2_TA4IC		ta4ic_addr.bit.ilvl2
#define		IR_TA4IC		ta4ic_addr.bit.ir

/*
 *  Timer B0 interrupt control register
 */
#pragma ADDRESS		tb0ic_addr	005aH		/* TB0IC �����ݐ��䃌�W�X�^		*/
ICR1_TYPE	tb0ic_addr;

#define		TB0IC			tb0ic_addr.byte
#define		ILVL0_TB0IC		tb0ic_addr.bit.ilvl0
#define		ILVL1_TB0IC		tb0ic_addr.bit.ilvl1
#define		ILVL2_TB0IC		tb0ic_addr.bit.ilvl2
#define		IR_TB0IC		tb0ic_addr.bit.ir

/*
 *  Timer B1 interrupt control register
 */
#pragma ADDRESS		tb1ic_addr	005bH		/* TB1IC �����ݐ��䃌�W�X�^		*/
ICR1_TYPE	tb1ic_addr;

#define		TB1IC			tb1ic_addr.byte
#define		ILVL0_TB1IC		tb1ic_addr.bit.ilvl0
#define		ILVL1_TB1IC		tb1ic_addr.bit.ilvl1
#define		ILVL2_TB1IC		tb1ic_addr.bit.ilvl2
#define		IR_TB1IC		tb1ic_addr.bit.ir

/*
 *  Timer B2 interrupt control register
 */
#pragma ADDRESS		tb2ic_addr	005cH		/* TB2IC �����ݐ��䃌�W�X�^		*/
ICR1_TYPE	tb2ic_addr;

#define		TB2IC			tb2ic_addr.byte
#define		ILVL0_TB2IC		tb2ic_addr.bit.ilvl0
#define		ILVL1_TB2IC		tb2ic_addr.bit.ilvl1
#define		ILVL2_TB2IC		tb2ic_addr.bit.ilvl2
#define		IR_TB2IC		tb2ic_addr.bit.ir


/*
 *  interrupt control register2
 */
typedef union {
	struct {
		UINT8	ilvl0:1;	/* RW ���荞�ݗD�惌�x��(ilvl0,ilvl1,ilvl2�w��)	*/
		UINT8	ilvl1:1;	/*    000:���x��0, 001:���x��1, 010:���x��2		*/
		UINT8	ilvl2:1;	/*    011:���x��3, 100:���x��4, 101:���x��5		*/
							/*    110:���x��6, 111:���x��7					*/
		UINT8	ir:1;		/* RW ���荞�ݗv�� 0:�Ȃ�, 1:����				*/
		UINT8	pol:1;		/* RW �ɐ��؂�ւ� 0:���オ��, 1:������			*/
		UINT8	reserve:1;	/* RW 0�Œ�										*/
		UINT8	no_assign:2;/* -  �s�� �����ޏꍇ��0						*/
	} bit;
	UINT8	byte;
} ICR2_TYPE;

/*
 *  INT0 interrupt control register
 */
#pragma ADDRESS		int0ic_addr	005dH		/* INT0 �����ݐ��䃌�W�X�^		*/
ICR2_TYPE	int0ic_addr;

#define		INT0IC			int0ic_addr.byte
#define		ILVL0_INT0IC	int0ic_addr.bit.ilvl0
#define		ILVL1_INT0IC	int0ic_addr.bit.ilvl1
#define		ILVL2_INT0IC	int0ic_addr.bit.ilvl2
#define		IR_INT0IC		int0ic_addr.bit.ir
#define		POL_INT0IC		int0ic_addr.bit.pol

/*
 *  INT1 interrupt control register
 */
#pragma ADDRESS		int1ic_addr	005eH		/* INT1 �����ݐ��䃌�W�X�^		*/
ICR2_TYPE	int1ic_addr;

#define		INT1IC			int1ic_addr.byte
#define		ILVL0_INT1IC	int1ic_addr.bit.ilvl0
#define		ILVL1_INT1IC	int1ic_addr.bit.ilvl1
#define		ILVL2_INT1IC	int1ic_addr.bit.ilvl2
#define		IR_INT1IC		int1ic_addr.bit.ir
#define		POL_INT1IC		int1ic_addr.bit.pol

/*
 *  INT3 interrupt control register
 */
#pragma ADDRESS		int3ic_addr	0044H		/* INT3 �����ݐ��䃌�W�X�^		*/
ICR2_TYPE	int3ic_addr;

#define		INT3IC			int3ic_addr.byte
#define		ILVL0_INT3IC	int3ic_addr.bit.ilvl0
#define		ILVL1_INT3IC	int3ic_addr.bit.ilvl1
#define		ILVL2_INT3IC	int3ic_addr.bit.ilvl2
#define		IR_INT3IC		int3ic_addr.bit.ir
#define		POL_INT3IC		int3ic_addr.bit.pol

/*
 *  INT4 interrupt control register
 */
#pragma ADDRESS		int4ic_addr	0049H		/* INT4 �����ݐ��䃌�W�X�^		*/
ICR2_TYPE	int4ic_addr;

#define		INT4IC			int4ic_addr.byte
#define		ILVL0_INT4IC	int4ic_addr.bit.ilvl0
#define		ILVL1_INT4IC	int4ic_addr.bit.ilvl1
#define		ILVL2_INT4IC	int4ic_addr.bit.ilvl2
#define		IR_INT4IC		int4ic_addr.bit.ir
#define		POL_INT4IC		int4ic_addr.bit.pol

/*
 *  INT5 interrupt control register
 */
#pragma ADDRESS		int5ic_addr	0048H		/* INT5 �����ݐ��䃌�W�X�^		*/
ICR2_TYPE	int5ic_addr;

#define		INT5IC			int5ic_addr.byte
#define		ILVL0_INT5IC	int5ic_addr.bit.ilvl0
#define		ILVL1_INT5IC	int5ic_addr.bit.ilvl1
#define		ILVL2_INT5IC	int5ic_addr.bit.ilvl2
#define		IR_INT5IC		int5ic_addr.bit.ir
#define		POL_INT5IC		int5ic_addr.bit.pol

/*
 *  interrupt cause select register
 */
#pragma ADDRESS		ifsr_addr	035fH		/* ���荞�ݗv���I�����W�X�^		*/
typedef union {
	struct {
		UINT8	ifsr0:1;	/* RW INT0���荞�݋ɐ��؂�ւ�					*/
							/*      0:�ЃG�b�W 1:���G�b�W					*/
		UINT8	ifsr1:1;	/* RW INT1���荞�݋ɐ��؂�ւ�					*/
							/*      0:�ЃG�b�W 1:���G�b�W					*/
		UINT8	no_assign:1;/* -  �s�� �����ޏꍇ��0						*/
		UINT8	ifsr3:1;	/* RW INT3���荞�݋ɐ��؂�ւ�					*/
							/*      0:�ЃG�b�W 1:���G�b�W					*/
		UINT8	ifsr4:1;	/* RW INT4���荞�݋ɐ��؂�ւ�					*/
							/*      0:�ЃG�b�W 1:���G�b�W					*/
		UINT8	ifsr5:1;	/* RW INT5���荞�݋ɐ��؂�ւ�					*/
							/*      0:�ЃG�b�W 1:���G�b�W					*/
		UINT8	ifsr6:1;	/* RW ���荞�ݗv���؂�ւ� 0:�\��, 1:INT4		*/
		UINT8	ifsr7:1;	/* RW ���荞�ݗv���؂�ւ� 0:�\��, 1:INT5		*/
	} bit;
	UINT8	byte;
} IFSR_TYPE;
IFSR_TYPE	ifsr_addr;

#define		IFSR			ifsr_addr.byte
#define		IFSR0			ifsr_addr.bit.ifsr0
#define		IFSR1			ifsr_addr.bit.ifsr1
#define		IFSR3			ifsr_addr.bit.ifsr3
#define		IFSR4			ifsr_addr.bit.ifsr4
#define		IFSR5			ifsr_addr.bit.ifsr5
#define		IFSR6			ifsr_addr.bit.ifsr6
#define		IFSR7			ifsr_addr.bit.ifsr7

/*
 *  Addrese match interrupt enable register
 */
#pragma ADDRESS		aier_addr	0009H	/* �A�h���X��v���荞�݋����W�X�^	*/
typedef union {
	struct {
		UINT8	aier0:1;	/* RW �A�h���X��v���荞��0���� 0:�֎~, 1:����	*/
		UINT8	aier1:1;	/* RW �A�h���X��v���荞��1���� 0:�֎~, 1:����	*/
		UINT8	no_assign:6;/* -  �s�� �����ޏꍇ��0						*/
	} bit;
	UINT8	byte;
} AIER_TYPE;
AIER_TYPE	aier_addr;

#define		AIER			aier_addr.byte
#define		AIER0			aier_addr.bit.aier0
#define		AIER1			aier_addr.bit.aier1

/*
 *  Address match interrupt register
 */
typedef union {
	struct {
		UINT8	rmad_low;	/* RW �A�h���X�ݒ� ����8bit						*/
		UINT8	rmad_mid;	/* RW �A�h���X�ݒ� ����8bit						*/
		UINT8	rmad_high;	/* RW �A�h���X�ݒ� ���8bit						*/
		UINT8	reserved;	/* �A�N�Z�X�֎~ ��SFR�̈�						*/
	} byte;
	struct{
		UINT16	rmad_low;	/* RW �A�h���X�ݒ� ����16bit					*/
		UINT16	rmad_high;	/* RW �A�h���X�ݒ� ���16bit					*/
							/*        �ŏ��8bit�̓}�X�N���K�v				*/
	} word;
	UINT32	dword;			/* RW �A�h���X�ݒ� 32bit						*/
							/*        �ŏ��8bit�̓}�X�N���K�v				*/
} RMAD_TYPE;

/*
 *  Address match interrupt register 0
 */
#pragma ADDRESS		rmad0_addr	0010H	/* �A�h���X��v���荞�݃��W�X�^0	*/
RMAD_TYPE	rmad0_addr;

/*#define	RMAD0			rmad0_addr.dword*/
#define		RMAD0WL			rmad0_addr.word.rmad_low
/*#define	RMAD0WH			rmad0_addr.word.rmad_high*/
#define		RMAD0BL			rmad0_addr.byte.rmad_low
#define		RMAD0BM			rmad0_addr.byte.rmad_mid
#define		RMAD0BH			rmad0_addr.byte.rmad_high
/* 32bit�A�N�Z�X����я��16bit�A�N�Z�X�ɂ��ẮC��SFR�̈���A�N�Z�X����	*/
/* ���܂����߁C�R�����g�A�E�g�Ƃ���D										*/

/*
 *  Address match interrupt register 1
 */
#pragma ADDRESS		rmad1_addr	0014H	/* �A�h���X��v���荞�݃��W�X�^1	*/
RMAD_TYPE	rmad1_addr;

/*#define	RMAD1			rmad1_addr.dword*/
#define		RMAD1WL			rmad1_addr.word.rmad_low
/*#define	RMAD1WH			rmad1_addr.word.rmad_high*/
#define		RMAD1BL			rmad1_addr.byte.rmad_low
#define		RMAD1BM			rmad1_addr.byte.rmad_mid
#define		RMAD1BH			rmad1_addr.byte.rmad_high
/* 32bit�A�N�Z�X����я��16bit�A�N�Z�X�ɂ��ẮC��SFR�̈���A�N�Z�X����	*/
/* ���܂����߁C�R�����g�A�E�g�Ƃ���D										*/


/********************************************************/
/* �Ď��^�C�}											*/
/********************************************************/
/*
 *  Watchdog timer control register
 */
#pragma ADDRESS		wdc_addr	000fH		/* �Ď��^�C�}���䃌�W�X�^		*/
typedef union {
	struct {
		UINT8	wdc_high:5;	/* R  �Ď��^�C�}�̏�ʃr�b�g					*/
		UINT8	wdc5:1;		/* RW �R�[���h�X�^�[�g/�E�H�[���X�^�[�g����		*/
							/*    0:�R�[���h�X�^�[�g, 1:�E�H�[���X�^�[�g	*/
		UINT8	reserve:1;	/* RW 0�Œ�										*/
		UINT8	wdc7:1;		/* RW �v���X�P�[���I�� 0:16����, 1:128����		*/
	} bit;
	UINT8	byte;
} WDC_TYPE;
WDC_TYPE	wdc_addr;

#define		WDC				wdc_addr.byte
#define		WDC5			wdc_addr.bit.wdc5
#define		WDC7			wdc_addr.bit.wdc7

/*
 *  Watchdog timer start register
 */
#pragma ADDRESS		wdts_addr	000eH		/* �Ď��^�C�}�X�^�[�g���W�X�^	*/
UINT8		wdts_addr;

#define		WDTS			wdts_addr


/********************************************************/
/* DMAC													*/
/********************************************************/
/*
 *  DMA cause select register
 */
typedef union {
	struct {
		UINT8	dsel0:1;	/* RW DMA�v���v���I�� (dsel0 - dsel3�Ŏw��)		*/
		UINT8	dsel1:1;	/*    �ڂ����̓n�[�h�E�F�A�}�j���A���Q��		*/
		UINT8	dsel2:1;
		UINT8	dsel3:1;
		UINT8	no_assign:2;/* -  �s�� �����ޏꍇ��0						*/
		UINT8	dms:1;		/* RW DMA�v���g���I�� 0:��{, 1:�g��			*/
		UINT8	dsr:1;		/* RW �\�t�g�E�G�ADMA�v��						*/
	} bit;
	UINT8	byte;
} DMSL_TYPE;

/*
 *  DMA0 cause select register
 */
#pragma ADDRESS		dm0sl_addr	03b8H		/* DMA0�v���I�����W�X�^			*/
DMSL_TYPE	dm0sl_addr;

#define		DM0SL			dm0sl_addr.byte
#define		DSEL0_DM0SL		dm0sl_addr.bit.dsel0
#define		DSEL1_DM0SL		dm0sl_addr.bit.dsel1
#define		DSEL2_DM0SL		dm0sl_addr.bit.dsel2
#define		DSEL3_DM0SL		dm0sl_addr.bit.dsel3
#define		DMS_DM0SL		dm0sl_addr.bit.dms
#define		DSR_DM0SL		dm0sl_addr.bit.dsr

/*
 *  DMA1 cause select register
 */
#pragma ADDRESS		dm1sl_addr	03baH		/* DMA1�v���I�����W�X�^			*/
DMSL_TYPE	dm1sl_addr;

#define		DM1SL			dm1sl_addr.byte
#define		DSEL0_DM1SL		dm1sl_addr.bit.dsel0
#define		DSEL1_DM1SL		dm1sl_addr.bit.dsel1
#define		DSEL2_DM1SL		dm1sl_addr.bit.dsel2
#define		DSEL3_DM1SL		dm1sl_addr.bit.dsel3
#define		DMS_DM1SL		dm1sl_addr.bit.dms
#define		DSR_DM1SL		dm1sl_addr.bit.dsr

/*
 *  DMA control register
 */
typedef union {
	struct {
		UINT8	dmbit:1;	/* RW �]���P�ʃr�b�g���I�� 0:16bit, 1:8bit		*/
		UINT8	dmasl:1;	/* RW ���s�[�g�]�����[�h�I��					*/
							/*        0:�P�]��, 1:���s�[�g�]��				*/
		UINT8	dmas:1;		/* RW DMA�v�� 0:�Ȃ�, 1:����					*/
		UINT8	dmae:1;		/* RW DMA���� 0:�֎~, 1:����					*/
		UINT8	dsd:1;		/* RW �]�����A�h���X�����I�� 0:�Œ�, 1:������	*/
		UINT8	dad:1;		/* RW �]����A�h���X�����I�� 0:�Œ�, 1:������	*/
		UINT8	no_assign:2;/* -  �s�� �����ޏꍇ��0						*/
	} bit;
	UINT8	byte;
} DMCON_TYPE;

/*
 *  DMA0 control register
 */
#pragma ADDRESS		dm0con_addr	002cH		/* DMA0���䃌�W�X�^				*/
DMCON_TYPE	dm0con_addr;

#define		DM0CON			dm0con_addr.byte
#define		DMBIT_DM0CON	dm0con_addr.bit.dmbit
#define		DMASL_DM0CON	dm0con_addr.bit.dmasl
#define		DMAS_DM0CON		dm0con_addr.bit.dmas
#define		DMAE_DM0CON		dm0con_addr.bit.dmae
#define		DSD_DM0CON		dm0con_addr.bit.dsd
#define		DAD_DM0CON		dm0con_addr.bit.dad

/*
 *  DMA1 destination pointer
 */
#pragma ADDRESS		dm1con_addr	003cH		/* DMA1���䃌�W�X�^				*/
DMCON_TYPE	dm1con_addr;

#define		DM1CON			dm1con_addr.byte
#define		DMBIT_DM1CON	dm1con_addr.bit.dmbit
#define		DMASL_DM1CON	dm1con_addr.bit.dmasl
#define		DMAS_DM1CON		dm1con_addr.bit.dmas
#define		DMAE_DM1CON		dm1con_addr.bit.dmae
#define		DSD_DM1CON		dm1con_addr.bit.dsd
#define		DAD_DM1CON		dm1con_addr.bit.dad

/*
 *  DMA source pointer
 */
typedef union {
	struct {
		UINT8	sar_low;	/* RW �A�h���X�ݒ� ����8bit						*/
		UINT8	sar_mid;	/* RW �A�h���X�ݒ� ����8bit						*/
		UINT8	sar_high;	/* RW �A�h���X�ݒ� ���8bit						*/
		UINT8	reserved;	/* �A�N�Z�X�֎~ ��SFR�̈�						*/
	} byte;
	struct {
		UINT16	sar_low;	/* RW �A�h���X�ݒ� ����16bit					*/
		UINT16	sar_high;	/* RW �A�h���X�ݒ� ���16bit					*/
							/*        �ŏ��8bit�̓}�X�N���K�v				*/
	} word;
	UINT32	dword;			/* RW �A�h���X�ݒ� 32bit						*/
							/*        �ŏ��8bit�̓}�X�N���K�v				*/
} SAR_TYPE;

/*
 *  DMA0 source pointer
 */
#pragma ADDRESS		sar0_addr	0020H		/* DMA0�\�[�X�|�C���^			*/
SAR_TYPE	sar0_addr;

/*#define	SAR0			sar0_addr.dword*/
#define		SAR0WL			sar0_addr.word.sar_low
/*#define	SAR0WH			sar0_addr.word.sar_high*/
#define		SAR0BL			sar0_addr.byte.sar_low
#define		SAR0BM			sar0_addr.byte.sar_mid
#define		SAR0BH			sar0_addr.byte.sar_high
/* 32bit�A�N�Z�X����я��16bit�A�N�Z�X�ɂ��ẮC��SFR�̈���A�N�Z�X����	*/
/* ���܂����߁C�R�����g�A�E�g�Ƃ���D										*/

/*
 *  DMA1 source pointer
 */
#pragma ADDRESS		sar1_addr	0030H		/* DMA1�\�[�X�|�C���^			*/
SAR_TYPE	sar1_addr;

/*#define	SAR1			sar1_addr.dword*/
#define		SAR1WL			sar1_addr.word.sar_low
/*#define	SAR1WH			sar1_addr.word.sar_high*/
#define		SAR1BL			sar1_addr.byte.sar_low
#define		SAR1BM			sar1_addr.byte.sar_mid
#define		SAR1BH			sar1_addr.byte.sar_high
/* 32bit�A�N�Z�X����я��16bit�A�N�Z�X�ɂ��ẮC��SFR�̈���A�N�Z�X����	*/
/* ���܂����߁C�R�����g�A�E�g�Ƃ���D										*/

/*
 *  DMA destination pointer
 */
typedef union {
	struct {
		UINT8	dar_low;	/* RW �A�h���X�ݒ� ����8bit						*/
		UINT8	dar_mid;	/* RW �A�h���X�ݒ� ����8bit						*/
		UINT8	dar_high;	/* RW �A�h���X�ݒ� ���8bit						*/
		UINT8	reserved;	/* �A�N�Z�X�֎~ ��SFR�̈�						*/
	} byte;
	struct {
		UINT16	dar_low;	/* RW �A�h���X�ݒ� ����16bit					*/
		UINT16	dar_high;	/* RW �A�h���X�ݒ� ���16bit					*/
							/*        �ŏ��8bit�̓}�X�N���K�v				*/
	} word;
	UINT32	dword;			/* RW �A�h���X�ݒ� 32bit						*/
							/*        �ŏ��8bit�̓}�X�N���K�v				*/
} DAR_TYPE;

/*
 *  DMA0 destination pointer
 */
#pragma ADDRESS		dar0_addr	0024H	/* DMA0�f�B�X�e�B�l�[�V�����|�C���^	*/
DAR_TYPE	dar0_addr;

/*#define	DAR0			dar0_addr.dword*/
#define		DAR0WL			dar0_addr.word.dar_low
/*#define	DAR0WH			dar0_addr.word.dar_high*/
#define		DAR0BL			dar0_addr.byte.dar_low
#define		DAR0BM			dar0_addr.byte.dar_mid
#define		DAR0BH			dar0_addr.byte.dar_high
/* 32bit�A�N�Z�X����я��16bit�A�N�Z�X�ɂ��ẮC��SFR�̈���A�N�Z�X����	*/
/* ���܂����߁C�R�����g�A�E�g�Ƃ���D										*/

/*
 *  DMA1 destination pointer
 */
#pragma ADDRESS		dar1_addr	0034H	/* DMA1�f�B�X�e�B�l�[�V�����|�C���^	*/
DAR_TYPE	dar1_addr;

/*#define	DAR1			dar1_addr.dword*/
#define		DAR1WL			dar1_addr.word.dar_low
/*#define	DAR1WH			dar1_addr.word.dar_high*/
#define		DAR1BL			dar1_addr.byte.dar_low
#define		DAR1BM			dar1_addr.byte.dar_mid
#define		DAR1BH			dar1_addr.byte.dar_high
/* 32bit�A�N�Z�X����я��16bit�A�N�Z�X�ɂ��ẮC��SFR�̈���A�N�Z�X����	*/
/* ���܂����߁C�R�����g�A�E�g�Ƃ���D										*/

/*
 *  DMA transfer counter
 */
typedef union {
	struct {
		UINT8	tcr_low;	/* RW �A�h���X�ݒ� ����8bit						*/
		UINT8	tcr_high;	/* RW �A�h���X�ݒ� ���8bit						*/
	} byte;
	UINT16	word;			/* RW �A�h���X�ݒ� 16bit						*/
} TCR_TYPE;

/*
 *  DMA0 transfer counter
 */
#pragma ADDRESS		tcr0_addr	0028H		/* DMA0�]���J�E���^				*/
TCR_TYPE	tcr0_addr;

#define		TCR0			tcr0_addr.word
#define		TCR0L			tcr0_addr.byte.tcr_low
#define		TCR0H			tcr0_addr.byte.tcr_high

/*
 *  DMA1 transfer counter
 */
#pragma ADDRESS		tcr1_addr	0038H		/* DMA1�]���J�E���^				*/
TCR_TYPE	tcr1_addr;

#define		TCR1			tcr1_addr.word
#define		TCR1L			tcr1_addr.byte.tcr_low
#define		TCR1H			tcr1_addr.byte.tcr_high


/********************************************************/
/* �^�C�}												*/
/********************************************************/
/*
 *  Timer mode register
 */
typedef union {
	struct {
		UINT8	tmod0:1;	/* RW ���샂�[�h�I��(TMOD0/1�Ŏw��) 00:�^�C�}	*/
		UINT8	tmod1:1;	/*    01:�C�x���g�J�E���^, 10:�����V���b�g�^�C�}*/
							/*    11:�p���X���ϒ�(PWM)						*/
		UINT8	mr0:1;		/* RW ���샂�[�h�ɂ���ċ@�\���قȂ�			*/
		UINT8	mr1:1;		/* RW ���샂�[�h�ɂ���ċ@�\���قȂ�			*/
		UINT8	mr2:1;		/* RW ���샂�[�h�ɂ���ċ@�\���قȂ�			*/
		UINT8	mr3:1;		/* RW ���샂�[�h�ɂ���ċ@�\���قȂ�			*/
		UINT8	tck0:1;		/* RW �J�E���g�\�[�X�I��(TCK0/1�Ŏw��)			*/
		UINT8	tck1:1;		/*    ���샂�[�h�ɂ���ċ@�\���قȂ�			*/
	} bit;
	UINT8	byte;
} TAMR_TYPE;

/*
 *  Timer A0 mode register
 */
#pragma ADDRESS		ta0mr_addr	0396H		/* �^�C�}A0���[�h���W�X�^		*/
TAMR_TYPE	ta0mr_addr;

#define		TA0MR			ta0mr_addr.byte
#define		TMOD0_TA0MR		ta0mr_addr.bit.tmod0
#define		TMOD1_TA0MR		ta0mr_addr.bit.tmod1
#define		MR0_TA0MR		ta0mr_addr.bit.mr0
#define		MR1_TA0MR		ta0mr_addr.bit.mr1
#define		MR2_TA0MR		ta0mr_addr.bit.mr2
#define		MR3_TA0MR		ta0mr_addr.bit.mr3
#define		TCK0_TA0MR		ta0mr_addr.bit.tck0
#define		TCK1_TA0MR		ta0mr_addr.bit.tck1

/*
 *  Timer A1 mode register
 */
#pragma ADDRESS		ta1mr_addr	0397H		/* �^�C�}A1���[�h���W�X�^		*/
TAMR_TYPE	ta1mr_addr;

#define		TA1MR			ta1mr_addr.byte
#define		TMOD0_TA1MR		ta1mr_addr.bit.tmod0
#define		TMOD1_TA1MR		ta1mr_addr.bit.tmod1
#define		MR0_TA1MR		ta1mr_addr.bit.mr0
#define		MR1_TA1MR		ta1mr_addr.bit.mr1
#define		MR2_TA1MR		ta1mr_addr.bit.mr2
#define		MR3_TA1MR		ta1mr_addr.bit.mr3
#define		TCK0_TA1MR		ta1mr_addr.bit.tck0
#define		TCK1_TA1MR		ta1mr_addr.bit.tck1

/*
 *  Timer A2 mode register
 */
#pragma ADDRESS		ta2mr_addr	0398H		/* �^�C�}A2���[�h���W�X�^		*/
TAMR_TYPE	ta2mr_addr;

#define		TA2MR			ta2mr_addr.byte
#define		TMOD0_TA2MR		ta2mr_addr.bit.tmod0
#define		TMOD1_TA2MR		ta2mr_addr.bit.tmod1
#define		MR0_TA2MR		ta2mr_addr.bit.mr0
#define		MR1_TA2MR		ta2mr_addr.bit.mr1
#define		MR2_TA2MR		ta2mr_addr.bit.mr2
#define		MR3_TA2MR		ta2mr_addr.bit.mr3
#define		TCK0_TA2MR		ta2mr_addr.bit.tck0
#define		TCK1_TA2MR		ta2mr_addr.bit.tck1

/*
 *  Timer A3 mode register
 */
#pragma ADDRESS		ta3mr_addr	0399H		/* �^�C�}A3���[�h���W�X�^		*/
TAMR_TYPE	ta3mr_addr;

#define		TA3MR			ta3mr_addr.byte
#define		TMOD0_TA3MR		ta3mr_addr.bit.tmod0
#define		TMOD1_TA3MR		ta3mr_addr.bit.tmod1
#define		MR0_TA3MR		ta3mr_addr.bit.mr0
#define		MR1_TA3MR		ta3mr_addr.bit.mr1
#define		MR2_TA3MR		ta3mr_addr.bit.mr2
#define		MR3_TA3MR		ta3mr_addr.bit.mr3
#define		TCK0_TA3MR		ta3mr_addr.bit.tck0
#define		TCK1_TA3MR		ta3mr_addr.bit.tck1

/*
 *  Timer A4 mode register
 */
#pragma ADDRESS		ta4mr_addr	039aH		/* �^�C�}A4���[�h���W�X�^		*/
TAMR_TYPE	ta4mr_addr;

#define		TA4MR			ta4mr_addr.byte
#define		TMOD0_TA4MR		ta4mr_addr.bit.tmod0
#define		TMOD1_TA4MR		ta4mr_addr.bit.tmod1
#define		MR0_TA4MR		ta4mr_addr.bit.mr0
#define		MR1_TA4MR		ta4mr_addr.bit.mr1
#define		MR2_TA4MR		ta4mr_addr.bit.mr2
#define		MR3_TA4MR		ta4mr_addr.bit.mr3
#define		TCK0_TA4MR		ta4mr_addr.bit.tck0
#define		TCK1_TA4MR		ta4mr_addr.bit.tck1

/*
 *  Timer A register
 */
typedef union {
	struct {
		UINT8	ta_low;		/* RW �A�h���X�ݒ� ����8bit						*/
		UINT8	ta_high;	/* RW �A�h���X�ݒ� ���8bit						*/
	} byte;
	UINT16	word;			/* RW �A�h���X�ݒ� 16bit						*/
} TA_TYPE;

/*
 *  Timer A0 register
 */
#pragma ADDRESS		ta0_addr	0386H		/* �^�C�}A0���W�X�^				*/
TA_TYPE		ta0_addr;

#define		TA0				ta0_addr.word
#define		TA0L			ta0_addr.byte.ta_low
#define		TA0H			ta0_addr.byte.ta_high

/*
 *  Timer A1 register
 */
#pragma ADDRESS		ta1_addr	0388H		/* �^�C�}A1���W�X�^				*/
TA_TYPE		ta1_addr;

#define		TA1				ta1_addr.word
#define		TA1L			ta1_addr.byte.ta_low
#define		TA1H			ta1_addr.byte.ta_high

/*
 *  Timer A2 register
 */
#pragma ADDRESS		ta2_addr	038aH		/* �^�C�}A2���W�X�^				*/
TA_TYPE		ta2_addr;

#define		TA2				ta2_addr.word
#define		TA2L			ta2_addr.byte.ta_low
#define		TA2H			ta2_addr.byte.ta_high

/*
 *  Timer A3 register
 */
#pragma ADDRESS		ta3_addr	038cH		/* �^�C�}A3���W�X�^				*/
TA_TYPE		ta3_addr;

#define		TA3				ta3_addr.word
#define		TA3L			ta3_addr.byte.ta_low
#define		TA3H			ta3_addr.byte.ta_high

/*
 *  Timer A4 register
 */
#pragma ADDRESS		ta4_addr	038eH		/* �^�C�}A4���W�X�^				*/
TA_TYPE		ta4_addr;

#define		TA4				ta4_addr.word
#define		TA4L			ta4_addr.byte.ta_low
#define		TA4H			ta4_addr.byte.ta_high

/*
 *  Timer A1-1 register
 */
#pragma ADDRESS		ta11_addr	0342H		/* �^�C�}A1-1���W�X�^				*/
TA_TYPE		ta11_addr;

#define		TA11			ta11_addr.word
#define		TA11L			ta11_addr.byte.ta_low
#define		TA11H			ta11_addr.byte.ta_high

/*
 *  Timer A2-1 register
 */
#pragma ADDRESS		ta21_addr	0344H		/* �^�C�}A2-1���W�X�^				*/
TA_TYPE		ta21_addr;

#define		TA21			ta21_addr.word
#define		TA21L			ta21_addr.byte.ta_low
#define		TA21H			ta21_addr.byte.ta_high

/*
 *  Timer A4-1 register
 */
#pragma ADDRESS		ta41_addr	0346H		/* �^�C�}A4-1���W�X�^				*/
TA_TYPE		ta41_addr;

#define		TA41			ta41_addr.word
#define		TA41L			ta41_addr.byte.ta_low
#define		TA41H			ta41_addr.byte.ta_high

/*
 *  Up-down flag
 */
#pragma ADDRESS		udf_addr	0384H		/* �A�b�v�_�E���t���O			*/
typedef union {
	struct {
		UINT8	ta0ud:1;	/* RW �^�C�}A0�A�b�v�_�E�� 0:�_�E��, 1:�A�b�v	*/
		UINT8	ta1ud:1;	/* RW �^�C�}A1�A�b�v�_�E�� 0:�_�E��, 1:�A�b�v	*/
		UINT8	ta2ud:1;	/* RW �^�C�}A2�A�b�v�_�E�� 0:�_�E��, 1:�A�b�v	*/
		UINT8	ta3ud:1;	/* RW �^�C�}A3�A�b�v�_�E�� 0:�_�E��, 1:�A�b�v	*/
		UINT8	ta4ud:1;	/* RW �^�C�}A4�A�b�v�_�E�� 0:�_�E��, 1:�A�b�v	*/
		UINT8	ta2p:1;		/* RW �^�C�}A2�񑊃p���X�M�������@�\�I��		*/
							/*                             0:�֎~, 1:����	*/
		UINT8	ta3p:1;		/* RW �^�C�}A3�񑊃p���X�M�������@�\�I��		*/
							/*                             0:�֎~, 1:����	*/
		UINT8	ta4p:1;		/* RW �^�C�}A4�񑊃p���X�M�������@�\�I��		*/
							/*                             0:�֎~, 1:����	*/
	} bit;
	UINT8	byte;
} UDF_TYPE;
UDF_TYPE	udf_addr;

#define		UDF				udf_addr.byte
#define		TA0UD			udf_addr.bit.ta0ud
#define		TA1UD			udf_addr.bit.ta1ud
#define		TA2UD			udf_addr.bit.ta2ud
#define		TA3UD			udf_addr.bit.ta3ud
#define		TA4UD			udf_addr.bit.ta4ud
#define		TA2P			udf_addr.bit.ta2p
#define		TA3P			udf_addr.bit.ta3p
#define		TA4P			udf_addr.bit.ta4p

/*
 *  One-shot start flag
 */
#pragma ADDRESS		onsf_addr	0382H		/* �����V���b�g�J�n�t���O		*/
typedef union {
	struct {
		UINT8	ta0os:1;	/* RW �^�C�}A0�����V���b�g�J�n					*/
		UINT8	ta1os:1;	/* RW �^�C�}A1�����V���b�g�J�n					*/
		UINT8	ta2os:1;	/* RW �^�C�}A2�����V���b�g�J�n					*/
		UINT8	ta3os:1;	/* RW �^�C�}A3�����V���b�g�J�n					*/
		UINT8	ta4os:1;	/* RW �^�C�}A4�����V���b�g�J�n					*/
		UINT8	reserve:1;	/* RW 0�Œ�										*/
		UINT8	ta0tgl:1;	/* RW �^�C�}A0�C�x���g�^�g���K�I���r�b�g		*/
		UINT8	ta0tgh:1;	/*    (TA0TGL/TA0TGH�Ŏw��) 00:TA0IN�[�q�̓���	*/
							/*    01:TB2�̃I�[�o�t���[, 10:TA4�̃I�[�o�t���[*/
							/*    11:TA1�̃I�[�o�t���[						*/
	} bit;
	UINT8	byte;
} ONSF_TYPE;
ONSF_TYPE	onsf_addr;

#define		ONSF			onsf_addr.byte
#define		TA0OS			onsf_addr.bit.ta0os
#define		TA1OS			onsf_addr.bit.ta1os
#define		TA2OS			onsf_addr.bit.ta2os
#define		TA3OS			onsf_addr.bit.ta3os
#define		TA4OS			onsf_addr.bit.ta4os
#define		TA0TGL			onsf_addr.bit.ta0tgl
#define		TA0TGH			onsf_addr.bit.ta0tgh

/*
 *  Trigger select register
 */
#pragma ADDRESS		trgsr_addr	0383H		/* �g���K�I�����W�X�^			*/
typedef union {
	struct {
		UINT8	ta1tgl:1;	/* RW �^�C�}A1�C�x���g�^�g���K�I���r�b�g		*/
		UINT8	ta1tgh:1;	/*    (TA1TGL/TA1TGH�Ŏw��) 00:TA1IN�[�q�̓���	*/
							/*    01:TB2�̃I�[�o�t���[, 10:TA0�̃I�[�o�t���[*/
							/*    11:TA2�̃I�[�o�t���[						*/
		UINT8	ta2tgl:1;	/* RW �^�C�}A2�C�x���g�^�g���K�I���r�b�g		*/
		UINT8	ta2tgh:1;	/*    (TA2TGL/TA2TGH�Ŏw��) 00:TA2IN�[�q�̓���	*/
							/*    01:TB2�̃I�[�o�t���[, 10:TA1�̃I�[�o�t���[*/
							/*    11:TA3�̃I�[�o�t���[						*/
		UINT8	ta3tgl:1;	/* RW �^�C�}A3�C�x���g�^�g���K�I���r�b�g		*/
		UINT8	ta3tgh:1;	/*    (TA3TGL/TA3TGH�Ŏw��) 00:TA3IN�[�q�̓���	*/
							/*    01:TB2�̃I�[�o�t���[, 10:TA2�̃I�[�o�t���[*/
							/*    11:TA4�̃I�[�o�t���[						*/
		UINT8	ta4tgl:1;	/* RW �^�C�}A4�C�x���g�^�g���K�I���r�b�g		*/
		UINT8	ta4tgh:1;	/*    (TA4TGL/TA4TGH�Ŏw��) 00:TA4IN�[�q�̓���	*/
							/*    01:TB2�̃I�[�o�t���[, 10:TA3�̃I�[�o�t���[*/
							/*    11:TA0�̃I�[�o�t���[						*/
	} bit;
	UINT8 byte;
} TRGSR_TYPE;
TRGSR_TYPE	trgsr_addr;

#define		TRGSR			trgsr_addr.byte
#define		TA1TGL			trgsr_addr.bit.ta1tgl
#define		TA1TGH			trgsr_addr.bit.ta1tgh
#define		TA2TGL			trgsr_addr.bit.ta2tgl
#define		TA2TGH			trgsr_addr.bit.ta2tgh
#define		TA3TGL			trgsr_addr.bit.ta3tgl
#define		TA3TGH			trgsr_addr.bit.ta3tgh
#define		TA4TGL			trgsr_addr.bit.ta4tgl
#define		TA4TGH			trgsr_addr.bit.ta4tgh

/*
 *  Timer B mode register
 */
typedef union {
	struct {
		UINT8	tmod0:1;	/* RW ���샂�[�h�I��(TMOD0/1�Ŏw��) 00:�^�C�}	*/
		UINT8	tmod1:1;	/*    01:�C�x���g�J�E���^, 10:�p���X��(����)����*/
							/*    11:�ݒ�s��								*/
		UINT8	mr0:1;		/* RW ���샂�[�h�ɂ���ċ@�\���قȂ�			*/
		UINT8	mr1:1;		/* RW ���샂�[�h�ɂ���ċ@�\���قȂ�			*/
		UINT8	mr2:1;		/* RW ���샂�[�h�ɂ���ċ@�\���قȂ�			*/
		UINT8	mr3:1;		/* RW ���샂�[�h�ɂ���ċ@�\���قȂ�			*/
		UINT8	tck0:1;		/* RW �J�E���g�\�[�X�I��(TCK0/1�Ŏw��)			*/
		UINT8	tck1:1;		/*    ���샂�[�h�ɂ���ċ@�\���قȂ�			*/
	} bit;
	UINT8	byte;
} TBMR_TYPE;

/*
 *  Timer B0 mode register
 */
#pragma ADDRESS		tb0mr_addr	039bH		/* �^�C�}B0���[�h���W�X�^		*/
TBMR_TYPE	tb0mr_addr;

#define		TB0MR			tb0mr_addr.byte
#define		TMOD0_TB0MR		tb0mr_addr.bit.tmod0
#define		TMOD1_TB0MR		tb0mr_addr.bit.tmod1
#define		MR0_TB0MR		tb0mr_addr.bit.mr0
#define		MR1_TB0MR		tb0mr_addr.bit.mr1
#define		MR2_TB0MR		tb0mr_addr.bit.mr2
#define		MR3_TB0MR		tb0mr_addr.bit.mr3
#define		TCK0_TB0MR		tb0mr_addr.bit.tck0
#define		TCK1_TB0MR		tb0mr_addr.bit.tck1

/*
 *  Timer B1 mode register
 */
#pragma ADDRESS		tb1mr_addr	039cH		/* �^�C�}B1���[�h���W�X�^		*/
TBMR_TYPE	tb1mr_addr;

#define		TB1MR			tb1mr_addr.byte
#define		TMOD0_TB1MR		tb1mr_addr.bit.tmod0
#define		TMOD1_TB1MR		tb1mr_addr.bit.tmod1
#define		MR0_TB1MR		tb1mr_addr.bit.mr0
#define		MR1_TB1MR		tb1mr_addr.bit.mr1
#define		MR2_TB1MR		tb1mr_addr.bit.mr2
#define		MR3_TB1MR		tb1mr_addr.bit.mr3
#define		TCK0_TB1MR		tb1mr_addr.bit.tck0
#define		TCK1_TB1MR		tb1mr_addr.bit.tck1

/*
 *  Timer B2 mode register
 */
#pragma ADDRESS		tb2mr_addr	039dH		/* �^�C�}B2���[�h���W�X�^		*/
TBMR_TYPE	tb2mr_addr;

#define		TB2MR			tb2mr_addr.byte
#define		TMOD0_TB2MR		tb2mr_addr.bit.tmod0
#define		TMOD1_TB2MR		tb2mr_addr.bit.tmod1
#define		MR0_TB2MR		tb2mr_addr.bit.mr0
#define		MR1_TB2MR		tb2mr_addr.bit.mr1
#define		MR2_TB2MR		tb2mr_addr.bit.mr2
#define		MR3_TB2MR		tb2mr_addr.bit.mr3
#define		TCK0_TB2MR		tb2mr_addr.bit.tck0
#define		TCK1_TB2MR		tb2mr_addr.bit.tck1

/*
 *  Timer B register
 */
typedef union {
	struct {
		UINT8	tb_low;		/* RW �A�h���X�ݒ� ����8bit						*/
		UINT8	tb_high;	/* RW �A�h���X�ݒ� ���8bit						*/
	} byte;
	UINT16	word;			/* RW �A�h���X�ݒ� 16bit						*/
} TB_TYPE;

/*
 *  Timer B0 register
 */
#pragma ADDRESS		tb0_addr	0390H		/* �^�C�}B0���W�X�^				*/
TB_TYPE		tb0_addr;

#define		TB0				tb0_addr.word
#define		TB0L			tb0_addr.byte.tb_low
#define		TB0H			tb0_addr.byte.tb_high

/*
 *  Timer B1 register
 */
#pragma ADDRESS		tb1_addr	0392H		/* �^�C�}B1���W�X�^				*/
TB_TYPE		tb1_addr;

#define		TB1				tb1_addr.word
#define		TB1L			tb1_addr.byte.tb_low
#define		TB1H			tb1_addr.byte.tb_high

/*
 *  Timer B2 register
 */
#pragma ADDRESS		tb2_addr	0394H		/* �^�C�}B2���W�X�^				*/
TB_TYPE		tb2_addr;

#define		TB2				tb2_addr.word
#define		TB2L			tb2_addr.byte.tb_low
#define		TB2H			tb2_addr.byte.tb_high

/*
 *  Count start flag
 */
#pragma ADDRESS		tabsr_addr	0380H		/* �J�E���g�J�n�t���O			*/
typedef union {
	struct {
		UINT8	ta0s:1;		/* RW �^�C�}A0�J�E���g�J�n 0:��~, 1:�J�n		*/
		UINT8	ta1s:1;		/* RW �^�C�}A1�J�E���g�J�n 0:��~, 1:�J�n		*/
		UINT8	ta2s:1;		/* RW �^�C�}A2�J�E���g�J�n 0:��~, 1:�J�n		*/
		UINT8	ta3s:1;		/* RW �^�C�}A3�J�E���g�J�n 0:��~, 1:�J�n		*/
		UINT8	ta4s:1;		/* RW �^�C�}A4�J�E���g�J�n 0:��~, 1:�J�n		*/
		UINT8	tb0s:1;		/* RW �^�C�}B0�J�E���g�J�n 0:��~, 1:�J�n		*/
		UINT8	tb1s:1;		/* RW �^�C�}B1�J�E���g�J�n 0:��~, 1:�J�n		*/
		UINT8	tb2s:1;		/* RW �^�C�}B2�J�E���g�J�n 0:��~, 1:�J�n		*/
	} bit;
	UINT8	byte;
} TABSR_TYPE;
TABSR_TYPE	tabsr_addr;

#define		TABSR			tabsr_addr.byte
#define		TA0S			tabsr_addr.bit.ta0s
#define		TA1S			tabsr_addr.bit.ta1s
#define		TA2S			tabsr_addr.bit.ta2s
#define		TA3S			tabsr_addr.bit.ta3s
#define		TA4S			tabsr_addr.bit.ta4s
#define		TB0S			tabsr_addr.bit.tb0s
#define		TB1S			tabsr_addr.bit.tb1s
#define		TB2S			tabsr_addr.bit.tb2s

/*
 *  Clock prescaler reset flag
 */
#pragma ADDRESS		cpsrf_addr	0381H	/* ���v�p�v���X�P�[�����Z�b�g�t���O	*/
typedef union {
	struct {
		UINT8	no_assign:7;/* -  �s�� �����ޏꍇ��0						*/
		UINT8	cpsr:1;
	} bit;
	UINT8	byte;
} CPSRF_TYPE;

#define		CPSRF			cpsrf_addr.byte
#define		CPSR			cpsrf_addr.bit.cpsr

/*
 *  Three-phase PWM control register 0
 */
#pragma ADDRESS		invc0_addr	0348H		/* �O��PWM���䃌�W�X�^0			*/
typedef union {
	struct {
		UINT8	inv00:1;	/* RW ���荞�ݗL���o�͋ɐ��I��					*/
		UINT8	inv01:1;	/* RW ���荞�ݗL���o�͎w��						*/
		UINT8	inv02:1;	/* RW ���[�h�I��								*/
		UINT8	inv03:1;	/* RW �o�͐��� 0:�o�͋֎~, 1:�o�͋���			*/
		UINT8	inv04:1;	/* RW ���t�������A�N�e�B�u�o�͋֎~�@�\����		*/
							/*             0:�o�͋���, 1:�o�͋֎~			*/
		UINT8	inv05:1;	/* RW ���t�������A�N�e�B�u�o�͌��o				*/
							/*             0:�����o,1:���o					*/
		UINT8	inv06:1;	/* RW �ϒ����[�h�I�� 0:�O�p�g�ϒ�, 1:���g�ϒ�	*/
		UINT8	inv07:1;	/* RW �\�t�g�E�G�A�g���K�I��					*/
	} bit;
	UINT8	byte;
} INVC0_TYPE;
INVC0_TYPE	invc0_addr;

#define		INVC0			invc0_addr.byte
#define		INV00			invc0_addr.bit.inv00
#define		INV01			invc0_addr.bit.inv01
#define		INV02			invc0_addr.bit.inv02
#define		INV03			invc0_addr.bit.inv03
#define		INV04			invc0_addr.bit.inv04
#define		INV05			invc0_addr.bit.inv05
#define		INV06			invc0_addr.bit.inv06
#define		INV07			invc0_addr.bit.inv07

/*
 *  Three-phase PWM control register 1
 */
#pragma ADDRESS		invc1_addr	0349H		/* �O��PWM���䃌�W�X�^1			*/
typedef union {
	struct {
		UINT8	inv10:1;	/* RW �^�C�}A1�AA2�AA4�X�^�[�g�g���K�I��		*/
		UINT8	inv11:1;	/* RW �^�C�}A1-1�AA2-1�AA4-1����				*/
		UINT8	inv12:1;	/* RW �Z���h�~�^�C�}�J�E���g�\�[�X�I��			*/
		UINT8	inv13:1;	/* RW �����g��Ԍ��o							*/
		UINT8	inv14:1;	/* RW �o�͋ɐ����� 0:L�A�N�e�B�u, 1:H�A�N�e�B�u	*/
		UINT8	inv15:1;	/* RW �Z���h�~���Ԗ��� 0:�L��, 1:����			*/
		UINT8	inv16:1;	/* RW �Z���h�~���ԃ^�C�}�g���K�I��				*/
		UINT8	reserve:1;	/* RW 0�Œ�										*/
	} bit;
	UINT8	byte;
} INVC1_TYPE;
INVC1_TYPE	invc1_addr;

#define		INVC1			invc1_addr.byte
#define		INV10			invc1_addr.bit.inv10
#define		INV11			invc1_addr.bit.inv11
#define		INV12			invc1_addr.bit.inv12
#define		INV13			invc1_addr.bit.inv13
#define		INV14			invc1_addr.bit.inv14
#define		INV15			invc1_addr.bit.inv15
#define		INV16			invc1_addr.bit.inv16

/*
 *  Three-phase output buffer register 0
 */
#pragma ADDRESS		idb0_addr	034aH		/* �O���o�̓o�b�t�@���W�X�^0	*/
typedef union {
	struct {
		UINT8	du0:1;		/* RW U���o�̓o�b�t�@							*/
		UINT8	dub0:1;		/* RW U~���o�̓o�b�t�@							*/
		UINT8	dv0:1;		/* RW V���o�̓o�b�t�@							*/
		UINT8	dvb0:1;		/* RW V~���o�̓o�b�t�@							*/
		UINT8	dw0:1;		/* RW W���o�̓o�b�t�@							*/
		UINT8	dwb0:1;		/* RW W~���o�̓o�b�t�@							*/
		UINT8	no_assign:2;/* -  �s�� �����ޏꍇ��0						*/
	} bit;
	UINT8	byte;
} IDB0_TYPE;
IDB0_TYPE	idb0_addr;

#define		IDB0			idb0_addr.byte
#define		DU0				idb0_addr.bit.du0
#define		DUB0			idb0_addr.bit.dub0
#define		DV0				idb0_addr.bit.dv0
#define		DVB0			idb0_addr.bit.dvb0
#define		DW0				idb0_addr.bit.dw0
#define		DWB0			idb0_addr.bit.dwb0

/*
 *  Three-phase output buffer register 1
 */
#pragma ADDRESS		idb1_addr	034bH		/* �O���o�̓o�b�t�@���W�X�^1	*/
typedef union {
	struct {
		UINT8	du1:1;		/* RW U���o�̓o�b�t�@							*/
		UINT8	dub1:1;		/* RW U~���o�̓o�b�t�@							*/
		UINT8	dv1:1;		/* RW V���o�̓o�b�t�@							*/
		UINT8	dvb1:1;		/* RW V~���o�̓o�b�t�@							*/
		UINT8	dw1:1;		/* RW W���o�̓o�b�t�@							*/
		UINT8	dwb1:1;		/* RW W~���o�̓o�b�t�@							*/
		UINT8	no_assign:2;/* -  �s�� �����ޏꍇ��0						*/
	} bit;
	UINT8	byte;
} IDB1_TYPE;
IDB1_TYPE	idb1_addr;

#define		IDB1			idb1_addr.byte
#define		DU1				idb1_addr.bit.du1
#define		DUB1			idb1_addr.bit.dub1
#define		DV1				idb1_addr.bit.dv1
#define		DVB1			idb1_addr.bit.dvb1
#define		DW1				idb1_addr.bit.dw1
#define		DWB1			idb1_addr.bit.dwb1

/*
 *  Dead time timer
 */
#pragma ADDRESS		dtt_addr	034cH		/* �Z���h�~�^�C�}				*/
UINT8		dtt_addr;

#define		DTT				dtt_addr

/*
 *  Timer B2 interrupt occurrences frequency set counter
 */
#pragma ADDRESS		ictb2_addr	034dH/* �^�C�}B2���荞�ݔ����p�x�ݒ�J�E���^*/
UINT8		ictb2_addr;

#define		ICTB2			ictb2_addr

/*
 *  Timer B2 special mode register
 */
#pragma ADDRESS		tb2sc_addr	039eH		/* �^�C�}B2���ꃂ�[�h���W�X�^	*/
typedef union {
	struct {
		UINT8	pwcon:1;	/* RW �^�C�}B2�����[�h�^�C�~���O�؂�ւ�		*/
		UINT8	ivpcr1:1;	/* RW �O���o�̓|�[�gSD����						*/
		UINT8	no_assign:6;/* -  �s�� �����ޏꍇ��0						*/
	} bit;
	UINT8	byte;
} TB2SC_TYPE;
TB2SC_TYPE	tb2sc_addr;

#define		TB2SC			tb2sc_addr.byte
#define		PWCON			tb2sc_addr.bit.pwcon
#define		IVPCR1			tb2sc_addr.bit.ivpcr1


/********************************************************/
/* �V���A��I/O											*/
/********************************************************/
/*
 *  UART transmit buffer register
 */
typedef union {
	struct {
		UINT8	b0:1;		/* W  ���M�f�[�^								*/
		UINT8	b1:1;		/* W  ���M�f�[�^								*/
		UINT8	b2:1;		/* W  ���M�f�[�^								*/
		UINT8	b3:1;		/* W  ���M�f�[�^								*/
		UINT8	b4:1;		/* W  ���M�f�[�^								*/
		UINT8	b5:1;		/* W  ���M�f�[�^								*/
		UINT8	b6:1;		/* W  ���M�f�[�^								*/
		UINT8	b7:1;		/* W  ���M�f�[�^								*/
		UINT8	b8:1;		/* W  ���M�f�[�^								*/
		UINT8	no_assign:7;/* -  �s�� �����ޏꍇ��0						*/
	} bit;
	struct {
		UINT8	low;		/* RW �A�h���X�ݒ� ����8bit						*/
		UINT8	high;		/* RW �A�h���X�ݒ� ���8bit						*/
	} byte;
	UINT16	word;
} UTB_TYPE;

/*
 *  UART0 transmit buffer register
 */
#pragma ADDRESS		u0tb_addr	03a2H		/* UART0���M�o�b�t�@���W�X�^	*/
UTB_TYPE	u0tb_addr;

#define		U0TB			u0tb_addr.word
#define		U0TBL			u0tb_addr.byte.low
#define		U0TBH			u0tb_addr.byte.high

/*
 *  UART1 transmit buffer register
 */
#pragma ADDRESS		u1tb_addr	03aaH		/* UART1���M�o�b�t�@���W�X�^	*/
UTB_TYPE	u1tb_addr;

#define		U1TB			u1tb_addr.word
#define		U1TBL			u1tb_addr.byte.low
#define		U1TBH			u1tb_addr.byte.high

/*
 *  UART2 transmit buffer register
 */
#pragma ADDRESS		u2tb_addr	037aH		/* UART1���M�o�b�t�@���W�X�^	*/
UTB_TYPE	u2tb_addr;

#define		U2TB			u2tb_addr.word
#define		U2TBL			u2tb_addr.byte.low
#define		U2TBH			u2tb_addr.byte.high

/*
 *  UART receive buffer register
 */
typedef union {
	struct {
		UINT8	b0:1;		/* R  ��M�f�[�^								*/
		UINT8	b1:1;		/* R  ��M�f�[�^								*/
		UINT8	b2:1;		/* R  ��M�f�[�^								*/
		UINT8	b3:1;		/* R  ��M�f�[�^								*/
		UINT8	b4:1;		/* R  ��M�f�[�^								*/
		UINT8	b5:1;		/* R  ��M�f�[�^								*/
		UINT8	b6:1;		/* R  ��M�f�[�^								*/
		UINT8	b7:1;		/* R  ��M�f�[�^								*/
		UINT8	b8:1;		/* R  ��M�f�[�^								*/
		UINT8	no_assign:2;/* -  �s�� �����ޏꍇ��0						*/
		UINT8	abt:1;		/* RW �A�[�r�g���[�V�������X�g���o				*/
							/*        0:�����o, 1:���o						*/
		UINT8	oer:1;		/* R  �I�[�o�����G���[ 0:�Ȃ�, 1:����			*/
		UINT8	fer:1;		/* R  �t���[�~���O�G���[ 0:�Ȃ�, 1:����			*/
		UINT8	per:1;		/* R  �p���e�B�G���[ 0:�Ȃ�, 1:����				*/
		UINT8	sum:1;		/* R  �G���[�T�� 0:�Ȃ�, 1:����					*/
	} bit;
	struct {
		UINT8    low;		/* RW �A�h���X�ݒ� ����8bit						*/
		UINT8    high;		/* RW �A�h���X�ݒ� ���8bit						*/
	} byte;
	UINT16  word;
} URB_TYPE;

/*
 *  UART0 receive buffer register
 */
#pragma ADDRESS		u0rb_addr	03a6H		/* UART0��M�o�b�t�@���W�X�^	*/
URB_TYPE	u0rb_addr;

#define		U0RB			u0rb_addr.word
#define		U0RBL			u0rb_addr.byte.low
#define		U0RBH			u0rb_addr.byte.high
#define		ABT_U0RB		u0rb_addr.bit.abt
#define		OER_U0RB		u0rb_addr.bit.oer
#define		FER_U0RB		u0rb_addr.bit.fer
#define		PER_U0RB		u0rb_addr.bit.per
#define		SUM_U0RB		u0rb_addr.bit.sum

/*
 *  UART1 receive buffer register
 */
#pragma ADDRESS		u1rb_addr	03aeH		/* UART1��M�o�b�t�@���W�X�^	*/
URB_TYPE	u1rb_addr;

#define		U1RB			u1rb_addr.word
#define		U1RBL			u1rb_addr.byte.low
#define		U1RBH			u1rb_addr.byte.high
#define		ABT_U1RB		u1rb_addr.bit.abt
#define		OER_U1RB		u1rb_addr.bit.oer
#define		FER_U1RB		u1rb_addr.bit.fer
#define		PER_U1RB		u1rb_addr.bit.per
#define		SUM_U1RB		u1rb_addr.bit.sum

/*
 *  UART2 receive buffer register
 */
#pragma ADDRESS		u2rb_addr	037eH		/* UART2��M�o�b�t�@���W�X�^	*/
URB_TYPE	u2rb_addr;

#define		U2RB			u2rb_addr.word
#define		U2RBL			u2rb_addr.byte.low
#define		U2RBH			u2rb_addr.byte.high
#define		ABT_U2RB		u2rb_addr.bit.abt
#define		OER_U2RB		u2rb_addr.bit.oer
#define		FER_U2RB		u2rb_addr.bit.fer
#define		PER_U2RB		u2rb_addr.bit.per
#define		SUM_U2RB		u2rb_addr.bit.sum

/*
 *  UART0 bit rate generator
 */
#pragma ADDRESS		u0brg_addr	03a1H		/* UART0�]�����x���W�X�^		*/
UINT8		u0brg_addr;

#define		U0BRG			u0brg_addr

/*
 *  UART1 bit rate generator
 */
#pragma ADDRESS		u1brg_addr	03a9H		/* UART1�]�����x���W�X�^		*/
UINT8		u1brg_addr;

#define		U1BRG			u1brg_addr

/*
 *  UART2 bit rate generator
 */
#pragma ADDRESS		u2brg_addr	0379H		/* UART2�]�����x���W�X�^		*/
UINT8		u2brg_addr;

#define		U2BRG			u2brg_addr

/*
 *  UART transmit/receive mode register
 */
typedef union {
	struct {
		UINT8	smd0:1;		/* RW �V���A��I/O���[�h�I��(smd0/1/2�Ŏw��)		*/
		UINT8	smd1:1;		/*    �V���A��I/O���[�h�I��						*/
		UINT8	smd2:1;		/*    �V���A��I/O���[�h�I��						*/
		UINT8	ckdir:1;	/* RW ��/�O���N���b�N�I�� 0:����, 1:�O��		*/
		UINT8	stps:1;		/* RW �X�g�b�v�r�b�g���I��0:1�X�g�b�v,2:�X�g�b�v*/
		UINT8	pry:1;		/* RW �p���e�B��/���I�� 0:�, 1:����			*/
		UINT8	prye:1;		/* RW �p���e�B���� 0:�֎~, 1:����				*/
		UINT8	iopol:1;	/* RW TxD�ARxD���o�͋ɐ��؂�ւ� 0:�Ȃ�, 1:����	*/
	} bit;
	UINT8	byte;
} UMR_TYPE;

/*
 *  UART0 transmit/receive mode register
 */
#pragma ADDRESS		u0mr_addr	03a0H		/* UART0����M���[�h���W�X�^	*/
UMR_TYPE	u0mr_addr;

#define		U0MR			u0mr_addr.byte
#define		SMD0_U0MR		u0mr_addr.bit.smd0
#define		SMD1_U0MR		u0mr_addr.bit.smd1
#define		SMD2_U0MR		u0mr_addr.bit.smd2
#define		CKDIR_U0MR		u0mr_addr.bit.ckdir
#define		STPS_U0MR		u0mr_addr.bit.stps
#define		PRY_U0MR		u0mr_addr.bit.pry
#define		PRYE_U0MR		u0mr_addr.bit.prye

/*
 *  UART1 transmit/receive mode register
 */
#pragma ADDRESS		u1mr_addr	03a8H		/* UART1����M���[�h���W�X�^	*/
UMR_TYPE	u1mr_addr;

#define		U1MR			u1mr_addr.byte
#define		SMD0_U1MR		u1mr_addr.bit.smd0
#define		SMD1_U1MR		u1mr_addr.bit.smd1
#define		SMD2_U1MR		u1mr_addr.bit.smd2
#define		CKDIR_U1MR		u1mr_addr.bit.ckdir
#define		STPS_U1MR		u1mr_addr.bit.stps
#define		PRY_U1MR		u1mr_addr.bit.pry
#define		PRYE_U1MR		u1mr_addr.bit.prye

/*
 *  UART2 transmit/receive mode register
 */
#pragma ADDRESS		u2mr_addr	0378H		/* UART2����M���[�h���W�X�^	*/
UMR_TYPE	u2mr_addr;

#define		U2MR			u2mr_addr.byte
#define		SMD0_U2MR		u2mr_addr.bit.smd0
#define		SMD1_U2MR		u2mr_addr.bit.smd1
#define		SMD2_U2MR		u2mr_addr.bit.smd2
#define		CKDIR_U2MR		u2mr_addr.bit.ckdir
#define		STPS_U2MR		u2mr_addr.bit.stps
#define		PRY_U2MR		u2mr_addr.bit.pry
#define		PRYE_U2MR		u2mr_addr.bit.prye
#define		IOPOL_U2MR		u2mr_addr.bit.iopol

/*
 *  UART transmit/receive control register 0
 */
typedef union {
	struct {
		UINT8	clk0:1;		/* RW BRG�J�E���g�\�[�X�I��(clk0/1�Ŏw��)		*/
		UINT8	clk1:1;		/*    BRG�J�E���g�\�[�X�I��						*/
		UINT8	crs:1;		/* RW CTS/RTS�@�\�I��							*/
		UINT8	txept:1;	/* R  ���M���W�X�^�� 0:���M��, 1:���M����		*/
		UINT8	crd:1;		/* RW CTS/RTS�֎~ 0:����, 1:�֎~				*/
		UINT8	nch:1;		/* RW �f�[�^�o�͑I��							*/
		UINT8	ckpol:1;	/* RW CLK�ɐ��I��								*/
		UINT8	uform:1;	/* RW �]���t�H�[�}�b�g�I�� 0:LSB, 1:MSB			*/
	} bit;
	UINT8	byte;
} UC0_TYPE;

/*
 *  UART0 transmit/receive control register 0
 */
#pragma ADDRESS		u0c0_addr	03a4H		/* UART0 ����M���䃌�W�X�^0	*/
UC0_TYPE	u0c0_addr;

#define		U0C0			u0c0_addr.byte
#define		CLK0_U0C0		u0c0_addr.bit.clk0
#define		CLK1_U0C0		u0c0_addr.bit.clk1
#define		CRS_U0C0		u0c0_addr.bit.crs
#define		TXEPT_U0C0		u0c0_addr.bit.txept
#define		CRD_U0C0		u0c0_addr.bit.crd
#define		NCH_U0C0		u0c0_addr.bit.nch
#define		CKPOL_U0C0		u0c0_addr.bit.ckpol
#define		UFORM_U0C0		u0c0_addr.bit.uform

/*
 *  UART1 transmit/receive control register 0
 */
#pragma ADDRESS		u1c0_addr	03acH		/* UART1 ����M���䃌�W�X�^0	*/
UC0_TYPE	u1c0_addr;

#define		U1C0			u1c0_addr.byte
#define		CLK0_U1C0		u1c0_addr.bit.clk0
#define		CLK1_U1C0		u1c0_addr.bit.clk1
#define		CRS_U1C0		u1c0_addr.bit.crs
#define		TXEPT_U1C0		u1c0_addr.bit.txept
#define		CRD_U1C0		u1c0_addr.bit.crd
#define		NCH_U1C0		u1c0_addr.bit.nch
#define		CKPOL_U1C0		u1c0_addr.bit.ckpol
#define		UFORM_U1C0		u1c0_addr.bit.uform

/*
 *  UART2 transmit/receive control register 0
 */
#pragma ADDRESS		u2c0_addr	037cH		/* UART2 ����M���䃌�W�X�^0	*/
UC0_TYPE	u2c0_addr;

#define		U2C0			u2c0_addr.byte
#define		CLK0_U2C0		u2c0_addr.bit.clk0
#define		CLK1_U2C0		u2c0_addr.bit.clk1
#define		CRS_U2C0		u2c0_addr.bit.crs
#define		TXEPT_U2C0		u2c0_addr.bit.txept
#define		CRD_U2C0		u2c0_addr.bit.crd
#define		NCH_U2C0		u2c0_addr.bit.nch
#define		CKPOL_U2C0		u2c0_addr.bit.ckpol
#define		UFORM_U2C0		u2c0_addr.bit.uform

/*
 *  UART transmit/receive control register 1
 */
typedef union {
	struct {
		UINT8	te:1;		/* RW ���M���� 0:�֎~, 1:����					*/
		UINT8	ti:1;		/* R  ���M�o�b�t�@�� 0:����, 1:�Ȃ�				*/
		UINT8	re:1;		/* RW ��M���� 0:�֎~, 1:����					*/
		UINT8	ri:1;		/* R  ��M���� 0:�Ȃ�, 1:����					*/
		UINT8	no_assign:4;/* -  �s�� �����ޏꍇ��0						*/
	} bit;
	UINT8	byte;
} UC1_TYPE;

/*
 *  UART0 transmit/receive control register 1
 */
#pragma ADDRESS		u0c1_addr	03a5H		/* UART0����M���䃌�W�X�^1		*/
UC1_TYPE	u0c1_addr;

#define		U0C1		u0c1_addr.byte
#define		TE_U0C1		u0c1_addr.bit.te
#define		TI_U0C1		u0c1_addr.bit.ti
#define		RE_U0C1		u0c1_addr.bit.re
#define		RI_U0C1		u0c1_addr.bit.ri

/*
 *  UART1 transmit/receive control register 1
 */
#pragma ADDRESS		u1c1_addr	03adH		/* UART1����M���䃌�W�X�^1		*/
UC1_TYPE	u1c1_addr;

#define		U1C1		u1c1_addr.byte
#define		TE_U1C1		u1c1_addr.bit.te
#define		TI_U1C1		u1c1_addr.bit.ti
#define		RE_U1C1		u1c1_addr.bit.re
#define		RI_U1C1		u1c1_addr.bit.ri

/*
 *  UART2 transmit/receive control register 1
 */
#pragma ADDRESS		u2c1_addr	037dH		/* UART2����M���䃌�W�X�^1		*/
typedef union {
	struct {
		UINT8	te:1;		/* RW ���M���� 0:�֎~, 1:����					*/
		UINT8	ti:1;		/* R  ���M�o�b�t�@�� 0:����, 1:�Ȃ�				*/
		UINT8	re:1;		/* RW ��M���� 0:�֎~, 1:����					*/
		UINT8	ri:1;		/* R  ��M���� 0:�Ȃ�, 1:����					*/
		UINT8	u2irs:1;	/* RW UART2���M���荞�ݗv���I��					*/
		UINT8	u2rrm:1;	/* RW UART2�A����M���[�h���� 0:�֎~, 1:����	*/
		UINT8	u2lch:1;	/* RW �f�[�^�_���I�� 0:���]�Ȃ�, 1;���]����		*/
		UINT8	u2ere:1;	/* RW �G���[�M���o�͋��� 0:���Ȃ�, 1:����		*/
	} bit;
	UINT8	byte;
} U2C1_TYPE;
U2C1_TYPE	u2c1_addr;

#define		U2C1			u2c1_addr.byte
#define		TE_U2C1			u2c1_addr.bit.te
#define		TI_U2C1			u2c1_addr.bit.ti
#define		RE_U2C1			u2c1_addr.bit.re
#define		RI_U2C1			u2c1_addr.bit.ri
#define		U2IRS			u2c1_addr.bit.u2irs
#define		U2RRM			u2c1_addr.bit.u2rrm
#define		U2LCH			u2c1_addr.bit.u2lch
#define		U2ERE			u2c1_addr.bit.u2ere

/*
 *  UART transmit/receive control register 2
 */
#pragma ADDRESS		ucon_addr	03b0H		/* UART����M���䃌�W�X�^2		*/
typedef union {
	struct {
		UINT8	u0irs:1;	/* RW UART0���M���荞�ݗv���I�� 0:��, 1:����	*/
		UINT8	u1irs:1;	/* RW UART1���M���荞�ݗv���I�� 0:��, 1:����	*/
		UINT8	u0rrm:1;	/* RW UART0�A����M���[�h���� 0:�֎~, 1:����	*/
		UINT8	u1rrm:1;	/* RW UART1�A����M���[�h���� 0:�֎~, 1:����	*/
		UINT8	clkmd0:1;	/* RW UART1CLK�ACLKS�I���r�b�g0					*/
		UINT8	clkmd1:1;	/* RW UART1CLK�ACLKS�I���r�b�g1					*/
		UINT8	rcsp:1;		/* RW UART0CTS/RTS����							*/
		UINT8	no_assign:1;/* -  �s�� �����ޏꍇ��0						*/
	} bit;
	UINT8	byte;
} UCON_TYPE;
UCON_TYPE	ucon_addr;

#define		UCON			ucon_addr.byte
#define		U0IRS			ucon_addr.bit.u0irs
#define		U1IRS			ucon_addr.bit.u1irs
#define		U0RRM			ucon_addr.bit.u0rrm
#define		U1RRM			ucon_addr.bit.u1rrm
#define		CLKMD0			ucon_addr.bit.clkmd0
#define		CLKMD1			ucon_addr.bit.clkmd1
#define		RCSP			ucon_addr.bit.rcsp

/*
 *  UART2 special mode register
 */
#pragma ADDRESS		u2smr_addr	0377H		/* UART2���ꃂ�[�h���W�X�^		*/
typedef union {
	struct {
		UINT8	iicm:1;		/* RW I2C Bus���[�h�I��							*/
		UINT8	abc:1;		/* RW �A�[�r�g���[�V�������X�g���o�t���O����	*/
		UINT8	bbs:1;		/* RW �o�X�r�W�[								*/
		UINT8	reserve:1;	/* RW 0�Œ�										*/
		UINT8	abscs:1;	/* RW �o�X�Փˌ��o�T���v�����O�N���b�N�I��		*/
		UINT8	acse:1;		/* RW ���M���r�b�g�����N���A�@�\�I��			*/
		UINT8	sss:1;		/* RW ���M�J�n�����I��							*/
		UINT8	no_assign:1;/* -  �s�� �����ޏꍇ��0						*/
	} bit;
	UINT8	byte;
} U2SMR_TYPE;
U2SMR_TYPE	u2smr_addr;

#define		U2SMR			u2smr_addr.byte
#define		IICM			u2smr_addr.bit.iicm
#define		ABC				u2smr_addr.bit.abc
#define		BBS				u2smr_addr.bit.bbs
#define		ABSCS			u2smr_addr.bit.abscs
#define		ACSE			u2smr_addr.bit.acse
#define		SSS				u2smr_addr.bit.sss


/*
 *  UART2 special mode register2
 */
#pragma ADDRESS		u2smr2_addr	0376H		/* UART2���ꃂ�[�h���W�X�^2		*/
typedef union {
	struct {
		UINT8	iicm2:1;	/* RW I2C Bus���[�h�I���r�b�g2					*/
		UINT8	csc:1;		/* RW �N���b�N������ 0:�֎~, 1:����				*/
		UINT8	swc:1;		/* RW SCL�E�G�C�g�o�� 0:�֎~, 1:����			*/
		UINT8	als:1;		/* RW SDA�o�͒�~ 0:�֎~, 1:����				*/
		UINT8	stac:1;		/* RW UARTi������ 0:�֎~, 1:����				*/
		UINT8	swc2:1;		/* RW SCL�E�G�C�g�o�̓r�b�g2					*/
							/*        0:�]���N���b�N, 1:L�o��				*/
		UINT8	sdhi:1;		/* RW SDA�o�͋֎~ 0:����, 1:�֎~				*/
		UINT8	no_assign:1;/* -  �s�� �����ޏꍇ��0						*/
	} bit;
	UINT8	byte;
} U2SMR2_TYPE;
U2SMR2_TYPE	u2smr2_addr;

#define		U2SMR2			u2smr2_addr.byte
#define		IICM2			u2smr2_addr.bit.iicm2
#define		CSC				u2smr2_addr.bit.csc
#define		SWC				u2smr2_addr.bit.swc
#define		ALS				u2smr2_addr.bit.als
#define		STAC			u2smr2_addr.bit.stac
#define		SWC2			u2smr2_addr.bit.swc2
#define		SDHI			u2smr2_addr.bit.sdhi

/*
 *  UART2 special mode register3
 */
#pragma ADDRESS		u2smr3_addr	0375H		/* UART2���ꃂ�|�h���W�X�^3		*/
typedef union {
	struct {
		UINT8	no_assign1:1;/* -  �s�� �����ޏꍇ��0						*/
		UINT8	ckph:1;		/* RW �N���b�N�ʑ��ݒ� 0:�x��Ȃ�, 1:�x�ꂠ��	*/
		UINT8	no_assign2:1;/* -  �s�� �����ޏꍇ��0						*/
		UINT8	nodc:1;		/* RW �N���b�N�o�͑I��							*/
		UINT8	no_assign3:1;/* -  �s�� �����ޏꍇ��0						*/
		UINT8	dl0:1;		/* RW SDA�f�B�W�^���x���l�ݒ�r�b�g				*/
		UINT8	dl1:1;		/*    (DL0/1/2�Ŏw��)							*/
		UINT8	dl2:1;
	} bit;
	UINT8	byte;
} U2SMR3_TYPE;
U2SMR3_TYPE	u2smr3_addr;

#define		U2SMR3			u2smr3_addr.byte
#define		CKPH			u2smr3_addr.bit.ckph
#define		NODC			u2smr3_addr.bit.nodc
#define		DL0				u2smr3_addr.bit.dl0
#define		DL1				u2smr3_addr.bit.dl1
#define		DL2				u2smr3_addr.bit.dl2

/*
 *  UART2 special mode register4
 */
#pragma ADDRESS		u2smr4_addr	0374H		/* UART2���ꃂ�[�h���W�X�^4		*/
typedef union {
	struct {
		UINT8	stareq:1;	/* RW �X�^�[�g�R���f�B�V���������r�b�g			*/
		UINT8	rstareq:1;	/* RW ���X�^�[�g�R���f�B�V���������r�b�g		*/
		UINT8	stpreq:1;	/* RW �X�g�b�v�R���f�B�V���������r�b�g			*/
		UINT8	stspsel:1;	/* RW SCL�ASDA�o�͑I��							*/
		UINT8	ackd:1;		/* RW ACK�f�[�^ 0:ACK, 1:NACK					*/
		UINT8	ackc:1;		/* RW ACK�f�[�^�o�͋���							*/
		UINT8	schli:1;	/* RW SCL�o�͒�~���� 0:�֎~, 1:����			*/
		UINT8	swc9:1;		/* RW SCL�E�G�C�g�r�b�g3 0:�֎~, 1:����			*/
	} bit;
	UINT8	byte;
} U2SMR4_TYPE;
U2SMR4_TYPE	u2smr4_addr;

#define		U2SMR4			u2smr4_addr.byte
#define		STAREQ			u2smr4_addr.bit.stareq
#define		RSTAREQ			u2smr4_addr.bit.rstareq
#define		STPREQ			u2smr4_addr.bit.stpreq
#define		STSPSEL			u2smr4_addr.bit.stspsel
#define		ACKD			u2smr4_addr.bit.ackd
#define		ACKC			u2smr4_addr.bit.ackc
#define		SCLHI			u2smr4_addr.bit.schli
#define		SWC9			u2smr4_addr.bit.swc9


/********************************************************/
/* A/D�ϊ�												*/
/********************************************************/
/*
 *  A-D control register 0
 */
#pragma ADDRESS		adcon0_addr	03d6H		/* A-D���䃌�W�X�^0				*/
typedef union {
	struct {
		UINT8	ch0:1;		/* RW �A�i���O���͒[�q�I�� (CH0/1/2�Ŏw��)		*/
		UINT8	ch1:1;		/*    �A�i���O���͒[�q�I��						*/
		UINT8	ch2:1;		/*    �A�i���O���͒[�q�I��						*/
		UINT8	md0:1;		/* RW A-D���샂�[�h�I�� (MD0/1�Ŏw��) 00:�P��	*/
		UINT8	md1:1;		/*    01:�J�Ԃ�, 10:�P�|��, 11:�J�Ԃ��|��0/1	*/
		UINT8	trg:1;		/* RW �g���K�I�� 0:�\�t�g�E�F�A, 1:ADTRG		*/
		UINT8	adst:1;		/* RW A-D�ϊ��J�n�t���O 0:��~, 1:�J�n			*/
		UINT8	cks0:1;		/* RW ���g���I���r�b�g0							*/
	} bit;
	UINT8	byte;
} ADCON0_TYPE;
ADCON0_TYPE	adcon0_addr;

#define		ADCON0			adcon0_addr.byte
#define		CH0				adcon0_addr.bit.ch0
#define		CH1				adcon0_addr.bit.ch1
#define		CH2				adcon0_addr.bit.ch2
#define		MD0				adcon0_addr.bit.md0
#define		MD1				adcon0_addr.bit.md1
#define		TRG				adcon0_addr.bit.trg
#define		ADST			adcon0_addr.bit.adst
#define		CKS0			adcon0_addr.bit.cks0

/*
 *  A-D control register 1
 */
#pragma ADDRESS		adcon1_addr	03d7H		/* A-D���䃌�W�X�^1				*/
typedef union {
	struct {
		UINT8	scan0:1;	/* RW A-D�|���[�q�I��							*/
		UINT8	scan1:1;	/*    A-D�|���[�q�I��							*/
		UINT8	md2:1;		/* RW A-D���샂�[�h�I��							*/
		UINT8	bits:1;		/* RW 8/10�r�b�g���[�h�I�� 0:8�r�b�g, 1:10�r�b�g*/
		UINT8	cks1:1;		/* RW ���g���I���r�b�g1							*/
		UINT8	vcut:1;		/* RW Vref�ڑ��r�b�g 0:���ڑ�, 1:�ڑ�			*/
		UINT8	reserve:2;	/* RW 0�Œ�										*/
	} bit;
	UINT8	byte;
} ADCON1_TYPE;
ADCON1_TYPE	adcon1_addr;

#define		ADCON1			adcon1_addr.byte
#define		SCAN0			adcon1_addr.bit.scan0
#define		SCAN1			adcon1_addr.bit.scan1
#define		MD2				adcon1_addr.bit.md2
#define		BITS			adcon1_addr.bit.bits
#define		CKS1			adcon1_addr.bit.cks1
#define		VCUT			adcon1_addr.bit.vcut

/*
 *  A-D control register 2
 */
#pragma ADDRESS		adcon2_addr	03d4H		/* A-D���䃌�W�X�^2				*/
typedef union {
	struct {
		UINT8	smp:1;		/* RW A-D�ϊ������I�� 0:�Ȃ�, 1:����			*/
		UINT8	reserve:3;	/* RW 0�Œ�										*/
		UINT8	cks2:1;		/* RW ���g���I���r�b�g2							*/
		UINT8	no_assign:3;/* -  �s�� �����ޏꍇ��0						*/
	} bit;
	UINT8	byte;
} ADCON2_TYPE;
ADCON2_TYPE	adcon2_addr;

#define		ADCON2			adcon2_addr.byte
#define		SMP				adcon2_addr.bit.smp
#define		CKS2			adcon2_addr.bit.cks2

/*
 *  A-D register
 */
typedef union {
	struct {
		UINT8	b0:1;		/* RO A/D�ϊ����ʂ̃r�b�g0						*/
		UINT8	b1:1;		/* RO A/D�ϊ����ʂ̃r�b�g1						*/
		UINT8	b2:1;		/* RO A/D�ϊ����ʂ̃r�b�g2						*/
		UINT8	b3:1;		/* RO A/D�ϊ����ʂ̃r�b�g3						*/
		UINT8	b4:1;		/* RO A/D�ϊ����ʂ̃r�b�g4						*/
		UINT8	b5:1;		/* RO A/D�ϊ����ʂ̃r�b�g5						*/
		UINT8	b6:1;		/* RO A/D�ϊ����ʂ̃r�b�g6						*/
		UINT8	b7:1;		/* RO A/D�ϊ����ʂ̃r�b�g7						*/
		UINT8	b8:1;		/* RO A/D�ϊ����ʂ̃r�b�g8(8bit���[�h�ł͕s��l)*/
		UINT8	b9:1;		/* RO A/D�ϊ����ʂ̃r�b�g9(8bit���[�h�ł͕s��l)*/
		UINT8	reserved:6;	/* RO �s��										*/
	} bit;
	struct {
		UINT8	low;		/* RO A/D�ϊ����ʂ̉���8�r�b�g					*/
		UINT8	high;		/* RO A/D�ϊ����ʂ̏��2�r�b�g����ѕs��l		*/
	} byte;
	UINT16	word;
} AD_TYPE;

/*
 *  A-D register 0
 */
#pragma ADDRESS		ad0_addr	03c0H		/* A-D���W�X�^0					*/
AD_TYPE		ad0_addr;

#define		AD0				ad0_addr.word
#define		AD0L			ad0_addr.byte.low
#define		AD0H			ad0_addr.byte.high

/*
 *  A-D register 1
 */
#pragma ADDRESS		ad1_addr	03c2H		/* A-D���W�X�^1					*/
AD_TYPE		ad1_addr;

#define		AD1				ad1_addr.word
#define		AD1L			ad1_addr.byte.low
#define		AD1H			ad1_addr.byte.high

/*
 *  A-D register 2
 */
#pragma ADDRESS		ad2_addr	03c4H		/* A-D���W�X�^2					*/
AD_TYPE		ad2_addr;

#define		AD2				ad2_addr.word
#define		AD2L			ad2_addr.byte.low
#define		AD2H			ad2_addr.byte.high

/*
 *  A-D register 3
 */
#pragma ADDRESS		ad3_addr	03c6H		/* A-D���W�X�^3					*/
AD_TYPE		ad3_addr;

#define		AD3				ad3_addr.word
#define		AD3L			ad3_addr.byte.low
#define		AD3H			ad3_addr.byte.high

/*
 *  A-D register 4
 */
#pragma ADDRESS		ad4_addr	03c8H		/* A-D���W�X�^4					*/
AD_TYPE		ad4_addr;

#define		AD4				ad4_addr.word
#define		AD4L			ad4_addr.byte.low
#define		AD4H			ad4_addr.byte.high

/*
 *  A-D register 5
 */
#pragma ADDRESS		ad5_addr	03caH		/* A-D���W�X�^5					*/
AD_TYPE		ad5_addr;

#define		AD5				ad5_addr.word
#define		AD5L			ad5_addr.byte.low
#define		AD5H			ad5_addr.byte.high

/*
 *  A-D register 6
 */
#pragma ADDRESS		ad6_addr	03ccH		/* A-D���W�X�^6					*/
AD_TYPE		ad6_addr;

#define		AD6				ad6_addr.word
#define		AD6L			ad6_addr.byte.low
#define		AD6H			ad6_addr.byte.high

/*
 *  A-D register 7
 */
#pragma ADDRESS		ad7_addr	03ceH		/* A-D���W�X�^7					*/
AD_TYPE		ad7_addr;

#define		AD7				ad7_addr.word
#define		AD7L			ad7_addr.byte.low
#define		AD7H			ad7_addr.byte.high


/********************************************************/
/* �v���O���}�u�����o�̓|�[�g							*/
/********************************************************/
/*
 *  Port P1 direction register
 */
#pragma ADDRESS		pd1_addr	03e3H		/* �|�[�gP1�������W�X�^			*/
typedef union {
	struct {
		UINT8	no_assign:5;/* -  �s�� �����ޏꍇ��0						*/
		UINT8	pd1_5:1;	/* RW �[�q�@�\(����)�I�� 0B:����/1B:�o��		*/
		UINT8	pd1_6:1;	/* RW �[�q�@�\(����)�I�� 0B:����/1B:�o��		*/
		UINT8	pd1_7:1;	/* RW �[�q�@�\(����)�I�� 0B:����/1B:�o��		*/
	} bit;
	UINT8	byte;
} PD1_TYPE;
PD1_TYPE	pd1_addr;

#define		PD1				pd1_addr.byte
#define		PD1_5			pd1_addr.bit.pd1_5
#define		PD1_6			pd1_addr.bit.pd1_6
#define		PD1_7			pd1_addr.bit.pd1_7

/*
 *  Port P6 direction register
 */
#pragma ADDRESS		pd6_addr	03eeH		/* �|�[�gP6�������W�X�^			*/
typedef union {
	struct {
		UINT8	pd6_0:1;	/* RW �[�q�@�\(����)�I�� 0B:����/1B:�o��		*/
		UINT8	pd6_1:1;	/* RW �[�q�@�\(����)�I�� 0B:����/1B:�o��		*/
		UINT8	pd6_2:1;	/* RW �[�q�@�\(����)�I�� 0B:����/1B:�o��		*/
		UINT8	pd6_3:1;	/* RW �[�q�@�\(����)�I�� 0B:����/1B:�o��		*/
		UINT8	pd6_4:1;	/* RW �[�q�@�\(����)�I�� 0B:����/1B:�o��		*/
		UINT8	pd6_5:1;	/* RW �[�q�@�\(����)�I�� 0B:����/1B:�o��		*/
		UINT8	pd6_6:1;	/* RW �[�q�@�\(����)�I�� 0B:����/1B:�o��		*/
		UINT8	pd6_7:1;	/* RW �[�q�@�\(����)�I�� 0B:����/1B:�o��		*/
	} bit;
	UINT8	byte;
} PD6_TYPE;
PD6_TYPE	pd6_addr;

#define		PD6				pd6_addr.byte
#define		PD6_0			pd6_addr.bit.pd6_0
#define		PD6_1			pd6_addr.bit.pd6_1
#define		PD6_2			pd6_addr.bit.pd6_2
#define		PD6_3			pd6_addr.bit.pd6_3
#define		PD6_4			pd6_addr.bit.pd6_4
#define		PD6_5			pd6_addr.bit.pd6_5
#define		PD6_6			pd6_addr.bit.pd6_6
#define		PD6_7			pd6_addr.bit.pd6_7

/*
 *  Port P7 direction register
 */
#pragma ADDRESS		pd7_addr	03efH		/* �|�[�gP7�������W�X�^			*/
typedef union {
	struct {
		UINT8	pd7_0:1;	/* RW �[�q�@�\(����)�I�� 0B:����/1B:�o��		*/
		UINT8	pd7_1:1;	/* RW �[�q�@�\(����)�I�� 0B:����/1B:�o��		*/
		UINT8	pd7_2:1;	/* RW �[�q�@�\(����)�I�� 0B:����/1B:�o��		*/
		UINT8	pd7_3:1;	/* RW �[�q�@�\(����)�I�� 0B:����/1B:�o��		*/
		UINT8	pd7_4:1;	/* RW �[�q�@�\(����)�I�� 0B:����/1B:�o��		*/
		UINT8	pd7_5:1;	/* RW �[�q�@�\(����)�I�� 0B:����/1B:�o��		*/
		UINT8	pd7_6:1;	/* RW �[�q�@�\(����)�I�� 0B:����/1B:�o��		*/
		UINT8	pd7_7:1;	/* RW �[�q�@�\(����)�I�� 0B:����/1B:�o��		*/
	} bit;
	UINT8	byte;
} PD7_TYPE;
PD7_TYPE	pd7_addr;

#define		PD7				pd7_addr.byte
#define		PD7_0			pd7_addr.bit.pd7_0
#define		PD7_1			pd7_addr.bit.pd7_1
#define		PD7_2			pd7_addr.bit.pd7_2
#define		PD7_3			pd7_addr.bit.pd7_3
#define		PD7_4			pd7_addr.bit.pd7_4
#define		PD7_5			pd7_addr.bit.pd7_5
#define		PD7_6			pd7_addr.bit.pd7_6
#define		PD7_7			pd7_addr.bit.pd7_7

/*
 *  Port P8 direction register
 */
#pragma ADDRESS		pd8_addr	03f2H		/* �|�[�gP8�������W�X�^			*/
typedef union {
	struct {
		UINT8	pd8_0:1;	/* RW �[�q�@�\(����)�I�� 0B:����/1B:�o��		*/
		UINT8	pd8_1:1;	/* RW �[�q�@�\(����)�I�� 0B:����/1B:�o��		*/
		UINT8	pd8_2:1;	/* RW �[�q�@�\(����)�I�� 0B:����/1B:�o��		*/
		UINT8	pd8_3:1;	/* RW �[�q�@�\(����)�I�� 0B:����/1B:�o��		*/
		UINT8	no_assign:1;/* -  �s�� �����ޏꍇ��0						*/
		UINT8	pd8_5:1;	/* RW �[�q�@�\(����)�I�� 0B:����/1B:�o��		*/
		UINT8	pd8_6:1;	/* RW �[�q�@�\(����)�I�� 0B:����/1B:�o��		*/
		UINT8	pd8_7:1;	/* RW �[�q�@�\(����)�I�� 0B:����/1B:�o��		*/
	} bit;
	UINT8	byte;
} PD8_TYPE;
PD8_TYPE	pd8_addr;

#define		PD8				pd8_addr.byte
#define		PD8_0			pd8_addr.bit.pd8_0
#define		PD8_1			pd8_addr.bit.pd8_1
#define		PD8_2			pd8_addr.bit.pd8_2
#define		PD8_3			pd8_addr.bit.pd8_3
#define		PD8_5			pd8_addr.bit.pd8_5
#define		PD8_6			pd8_addr.bit.pd8_6
#define		PD8_7			pd8_addr.bit.pd8_7

/*
 *  Port P9 direction register
 */
#pragma ADDRESS		pd9_addr	03f3H		/* �|�[�gP9�������W�X�^			*/
typedef union {
	struct {
		UINT8	pd9_0:1;	/* RW �[�q�@�\(����)�I�� 0B:����/1B:�o��		*/
		UINT8	pd9_1:1;	/* RW �[�q�@�\(����)�I�� 0B:����/1B:�o��		*/
		UINT8	pd9_2:1;	/* RW �[�q�@�\(����)�I�� 0B:����/1B:�o��		*/
		UINT8	pd9_3:1;	/* RW �[�q�@�\(����)�I�� 0B:����/1B:�o��		*/
		UINT8	no_assign:4;/* -  �s�� �����ޏꍇ��0						*/
	} bit;
	UINT8	byte;
} PD9_TYPE;
PD9_TYPE	pd9_addr;

#define		PD9				pd9_addr.byte
#define		PD9_0			pd9_addr.bit.pd9_0
#define		PD9_1			pd9_addr.bit.pd9_1
#define		PD9_2			pd9_addr.bit.pd9_2
#define		PD9_3			pd9_addr.bit.pd9_3

/*
 *  Port P10 direction register
 */
#pragma ADDRESS		pd10_addr	03f6H		/* �|�[�gP10�������W�X�^		*/
typedef union {
	struct {
		UINT8	pd10_0:1;	/* RW �[�q�@�\(����)�I�� 0B:����/1B:�o��		*/
		UINT8	pd10_1:1;	/* RW �[�q�@�\(����)�I�� 0B:����/1B:�o��		*/
		UINT8	pd10_2:1;	/* RW �[�q�@�\(����)�I�� 0B:����/1B:�o��		*/
		UINT8	pd10_3:1;	/* RW �[�q�@�\(����)�I�� 0B:����/1B:�o��		*/
		UINT8	pd10_4:1;	/* RW �[�q�@�\(����)�I�� 0B:����/1B:�o��		*/
		UINT8	pd10_5:1;	/* RW �[�q�@�\(����)�I�� 0B:����/1B:�o��		*/
		UINT8	pd10_6:1;	/* RW �[�q�@�\(����)�I�� 0B:����/1B:�o��		*/
		UINT8	pd10_7:1;	/* RW �[�q�@�\(����)�I�� 0B:����/1B:�o��		*/
	} bit;
	UINT8	byte;
} PD10_TYPE;
PD10_TYPE	pd10_addr;

#define		PD10			pd10_addr.byte
#define		PD10_0			pd10_addr.bit.pd10_0
#define		PD10_1			pd10_addr.bit.pd10_1
#define		PD10_2			pd10_addr.bit.pd10_2
#define		PD10_3			pd10_addr.bit.pd10_3
#define		PD10_4			pd10_addr.bit.pd10_4
#define		PD10_5			pd10_addr.bit.pd10_5
#define		PD10_6			pd10_addr.bit.pd10_6
#define		PD10_7			pd10_addr.bit.pd10_7

/*
 *  Port P1
 */
#pragma ADDRESS		p1_addr		03e1H		/* �|�[�gP1���W�X�^				*/
typedef union {
	struct {
		UINT8	no_assign:5;/* -  �s�� �����ޏꍇ��0						*/
		UINT8	p1_5:1;		/* RW �[�q�@�\(����)�I�� 0B:����/1B:�o��		*/
		UINT8	p1_6:1;		/* RW �[�q�@�\(����)�I�� 0B:����/1B:�o��		*/
		UINT8	p1_7:1;		/* RW �[�q�@�\(����)�I�� 0B:����/1B:�o��		*/
	} bit;
	UINT8	byte;
} P1_TYPE;
P1_TYPE		p1_addr;

#define		P1				p1_addr.byte
#define		P1_5			p1_addr.bit.p1_5
#define		P1_6			p1_addr.bit.p1_6
#define		P1_7			p1_addr.bit.p1_7

/*
 *  Port P6
 */
#pragma ADDRESS		p6_addr		03ecH		/* �|�[�gP6���W�X�^				*/
typedef union {
	struct {
		UINT8	p6_0:1;		/* RW �[�q�@�\(����)�I�� 0B:����/1B:�o��		*/
		UINT8	p6_1:1;		/* RW �[�q�@�\(����)�I�� 0B:����/1B:�o��		*/
		UINT8	p6_2:1;		/* RW �[�q�@�\(����)�I�� 0B:����/1B:�o��		*/
		UINT8	p6_3:1;		/* RW �[�q�@�\(����)�I�� 0B:����/1B:�o��		*/
		UINT8	p6_4:1;		/* RW �[�q�@�\(����)�I�� 0B:����/1B:�o��		*/
		UINT8	p6_5:1;		/* RW �[�q�@�\(����)�I�� 0B:����/1B:�o��		*/
		UINT8	p6_6:1;		/* RW �[�q�@�\(����)�I�� 0B:����/1B:�o��		*/
		UINT8	p6_7:1;		/* RW �[�q�@�\(����)�I�� 0B:����/1B:�o��		*/
	} bit;
	UINT8	byte;
} P6_TYPE;
P6_TYPE		p6_addr;

#define		P6				p6_addr.byte
#define		P6_0			p6_addr.bit.p6_0
#define		P6_1			p6_addr.bit.p6_1
#define		P6_2			p6_addr.bit.p6_2
#define		P6_3			p6_addr.bit.p6_3
#define		P6_4			p6_addr.bit.p6_4
#define		P6_5			p6_addr.bit.p6_5
#define		P6_6			p6_addr.bit.p6_6
#define		P6_7			p6_addr.bit.p6_7

/*
 *  Port P7
 */
#pragma ADDRESS		p7_addr		03edH		/* �|�[�gP7���W�X�^				*/
typedef union {
	struct {
		UINT8	p7_0:1;		/* RW �[�q�@�\(����)�I�� 0B:����/1B:�o��		*/
		UINT8	p7_1:1;		/* RW �[�q�@�\(����)�I�� 0B:����/1B:�o��		*/
		UINT8	p7_2:1;		/* RW �[�q�@�\(����)�I�� 0B:����/1B:�o��		*/
		UINT8	p7_3:1;		/* RW �[�q�@�\(����)�I�� 0B:����/1B:�o��		*/
		UINT8	p7_4:1;		/* RW �[�q�@�\(����)�I�� 0B:����/1B:�o��		*/
		UINT8	p7_5:1;		/* RW �[�q�@�\(����)�I�� 0B:����/1B:�o��		*/
		UINT8	p7_6:1;		/* RW �[�q�@�\(����)�I�� 0B:����/1B:�o��		*/
		UINT8	p7_7:1;		/* RW �[�q�@�\(����)�I�� 0B:����/1B:�o��		*/
	} bit;
	UINT8	byte;
} P7_TYPE;
P7_TYPE		p7_addr;

#define		P7				p7_addr.byte
#define		P7_0			p7_addr.bit.p7_0
#define		P7_1			p7_addr.bit.p7_1
#define		P7_2			p7_addr.bit.p7_2
#define		P7_3			p7_addr.bit.p7_3
#define		P7_4			p7_addr.bit.p7_4
#define		P7_5			p7_addr.bit.p7_5
#define		P7_6			p7_addr.bit.p7_6
#define		P7_7			p7_addr.bit.p7_7

/*
 *  Port P8
 */
#pragma ADDRESS		p8_addr		03f0H		/* �|�[�gP8���W�X�^				*/
typedef union {
	struct {
		UINT8	p8_0:1;		/* RW �[�q�@�\(����)�I�� 0B:����/1B:�o��		*/
		UINT8	p8_1:1;		/* RW �[�q�@�\(����)�I�� 0B:����/1B:�o��		*/
		UINT8	p8_2:1;		/* RW �[�q�@�\(����)�I�� 0B:����/1B:�o��		*/
		UINT8	p8_3:1;		/* RW �[�q�@�\(����)�I�� 0B:����/1B:�o��		*/
		UINT8	no_assign:1;/* -  �s�� �����ޏꍇ��0						*/
		UINT8	p8_5:1;		/* RW �[�q�@�\(����)�I�� 0B:����/1B:�o��		*/
		UINT8	p8_6:1;		/* RW �[�q�@�\(����)�I�� 0B:����/1B:�o��		*/
		UINT8	p8_7:1;		/* RW �[�q�@�\(����)�I�� 0B:����/1B:�o��		*/
	} bit;
	UINT8	byte;
} P8_TYPE;
P8_TYPE		p8_addr;

#define		P8				p8_addr.byte
#define		P8_0			p8_addr.bit.p8_0
#define		P8_1			p8_addr.bit.p8_1
#define		P8_2			p8_addr.bit.p8_2
#define		P8_3			p8_addr.bit.p8_3
#define		P8_5			p8_addr.bit.p8_5
#define		P8_6			p8_addr.bit.p8_6
#define		P8_7			p8_addr.bit.p8_7

/*
 *  Port P9
 */
#pragma ADDRESS		p9_addr		03f1H		/* �|�[�gP9���W�X�^				*/
typedef union {
	struct {
		UINT8	p9_0:1;		/* RW �[�q�@�\(����)�I�� 0B:����/1B:�o��		*/
		UINT8	p9_1:1;		/* RW �[�q�@�\(����)�I�� 0B:����/1B:�o��		*/
		UINT8	p9_2:1;		/* RW �[�q�@�\(����)�I�� 0B:����/1B:�o��		*/
		UINT8	p9_3:1;		/* RW �[�q�@�\(����)�I�� 0B:����/1B:�o��		*/
		UINT8	no_assign:4;/* -  �s�� �����ޏꍇ��0						*/
	} bit;
	UINT8	byte;
} P9_TYPE;
P9_TYPE		p9_addr;

#define		P9				p9_addr.byte
#define		P9_0			p9_addr.bit.p9_0
#define		P9_1			p9_addr.bit.p9_1
#define		P9_2			p9_addr.bit.p9_2
#define		P9_3			p9_addr.bit.p9_3

/*
 *  Port P10
 */
#pragma ADDRESS		p10_addr	03f4H		/* �|�[�gP10���W�X�^			*/
typedef union {
	struct {
		UINT8	p10_0:1;	/* RW �[�q�@�\(����)�I�� 0B:����/1B:�o��		*/
		UINT8	p10_1:1;	/* RW �[�q�@�\(����)�I�� 0B:����/1B:�o��		*/
		UINT8	p10_2:1;	/* RW �[�q�@�\(����)�I�� 0B:����/1B:�o��		*/
		UINT8	p10_3:1;	/* RW �[�q�@�\(����)�I�� 0B:����/1B:�o��		*/
		UINT8	p10_4:1;	/* RW �[�q�@�\(����)�I�� 0B:����/1B:�o��		*/
		UINT8	p10_5:1;	/* RW �[�q�@�\(����)�I�� 0B:����/1B:�o��		*/
		UINT8	p10_6:1;	/* RW �[�q�@�\(����)�I�� 0B:����/1B:�o��		*/
		UINT8	p10_7:1;	/* RW �[�q�@�\(����)�I�� 0B:����/1B:�o��		*/
	} bit;
	UINT8	byte;
} P10_TYPE;
P10_TYPE	p10_addr;

#define		P10				p10_addr.byte
#define		P10_0			p10_addr.bit.p10_0
#define		P10_1			p10_addr.bit.p10_1
#define		P10_2			p10_addr.bit.p10_2
#define		P10_3			p10_addr.bit.p10_3
#define		P10_4			p10_addr.bit.p10_4
#define		P10_5			p10_addr.bit.p10_5
#define		P10_6			p10_addr.bit.p10_6
#define		P10_7			p10_addr.bit.p10_7

/*
 *  Pull-up control register 0
 */
#pragma ADDRESS		pur0_addr	03fcH		/* �v���A�b�v���䃌�W�X�^0		*/
typedef union {
	struct {
		UINT8	no_assign1:3;/* -  �s�� �����ޏꍇ��0						*/
		UINT8	pu03:1;		/* RW P15�`P17�̃v���A�b�v 0:�Ȃ�, 1:����		*/
		UINT8	no_assign2:4;/* -  �s�� �����ޏꍇ��0						*/
	} bit;
	UINT8	byte;
} PUR0_TYPE;
PUR0_TYPE	pur0_addr;

#define		PUR0			pur0_addr.byte
#define		PU03			pur0_addr.bit.pu03

/*
 *  Pull-up control register 1
 */
#pragma ADDRESS		pur1_addr	03fdH		/* �v���A�b�v���䃌�W�X�^1		*/
typedef union {
	struct {
		UINT8	no_assign:4;/* -  �s�� �����ޏꍇ��0						*/
		UINT8	pu14:1;		/* RW P60�`P63�̃v���A�b�v 0:�Ȃ�, 1:����		*/
		UINT8	pu15:1;		/* RW P64�`P67�̃v���A�b�v 0:�Ȃ�, 1:����		*/
		UINT8	pu16:1;		/* RW P72�`P73�̃v���A�b�v 0:�Ȃ�, 1:����		*/
		UINT8	pu17:1;		/* RW P74�`P77�̃v���A�b�v 0:�Ȃ�, 1:����		*/
	} bit;
	UINT8	byte;
} PUR1_TYPE;
PUR1_TYPE	pur1_addr;

#define		PUR1			pur1_addr.byte
#define		PU14			pur1_addr.bit.pu14
#define		PU15			pur1_addr.bit.pu15
#define		PU16			pur1_addr.bit.pu16
#define		PU17			pur1_addr.bit.pu17

/*
 *  Pull-up control register 2
 */
#pragma ADDRESS		pur2_addr	03feH		/* �v���A�b�v���䃌�W�X�^2		*/
typedef union {
	struct {
		UINT8	pu20:1;		/* RW P80�`P83�̃v���A�b�v 0:�Ȃ�, 1:����		*/
		UINT8	pu21:1;		/* RW P85�`P87�̃v���A�b�v 0:�Ȃ�, 1:����		*/
		UINT8	pu22:1;		/* RW P90�`P93�̃v���A�b�v 0:�Ȃ�, 1:����		*/
		UINT8	no_assign1:1;/* -  �s�� �����ޏꍇ��0						*/
		UINT8	pu24:1;		/* RW P100�`P103�̃v���A�b�v 0:�Ȃ�, 1:����		*/
		UINT8	pu25:1;		/* RW P104�`P107�̃v���A�b�v 0:�Ȃ�, 1:����		*/
		UINT8	no_assign2:2;/* -  �s�� �����ޏꍇ��0						*/
		
	} bit;
	UINT8	byte;
} PUR2_TYPE;
PUR2_TYPE	pur2_addr;

#define		PUR2			pur2_addr.byte
#define		PU20			pur2_addr.bit.pu20
#define		PU21			pur2_addr.bit.pu21
#define		PU22			pur2_addr.bit.pu22
#define		PU24			pur2_addr.bit.pu24
#define		PU25			pur2_addr.bit.pu25

/*
 *  Port control register
 */
#pragma ADDRESS		pcr_addr	03ffH		/* �|�[�g���䃌�W�X�^			*/
typedef union {
	struct{
		UINT8	pcr0:1;		/* RW �|�[�gP1����r�b�g						*/
		UINT8	no_assign:7;/* -  �s�� �����ޏꍇ��0						*/
	} bit;
	UINT8	byte;
} PCR_TYPE;
PCR_TYPE	pcr_addr;

#define		PCR				pcr_addr.byte
#define		PCR0			pcr_addr.bit.pcr0

/********************************************************/
/* �t���b�V����������									*/
/********************************************************/
/*
 *  Flash Control Register 0
 */
#pragma ADDRESS		fmr0_addr	01b7H		/* �t���b�V�����������䃌�W�X�^0*/
typedef union {
	struct {
		UINT8	fmr00:1;	/* R  RY/BY�X�e�[�^�X�t���O 0:busy, 1:ready		*/
		UINT8	fmr01:1;	/* RW CPU�����������[�h�I���r�b�g 0:����, 1:�L��*/
		UINT8	fmr02:1;	/* RW �u���b�N0,1���������r�b�g 0:�֎~, 1:����*/
		UINT8	fmstp:1;	/* RW �t���b�V����������~�r�b�g 0:����, 1:��~	*/
		UINT8	reserve:2;	/* RW 0�Œ�										*/
		UINT8	fmr06:1;	/* R  �v���O�����X�e�[�^�X 0:����, 1:�G���[		*/
		UINT8	fmr07:1;	/* R  �C���[�Y�X�e�[�^�X 0:����, 1:�G���[		*/
	} bit;
	UINT8	byte;
} FMR0_TYPE;
FMR0_TYPE	fmr0_addr;

#define		FMR0			fmr0_addr.byte
#define		FMR00			fmr0_addr.bit.fmr00
#define		FMR01			fmr0_addr.bit.fmr01
#define		FMR02			fmr0_addr.bit.fmr02
#define		FMSTP			fmr0_addr.bit.fmstp
#define		FMR06			fmr0_addr.bit.fmr06
#define		FMR07			fmr0_addr.bit.fmr07

/*
 *  Flash Control Register 1
 */
#pragma ADDRESS		fmr1_addr	01b5H		/* �t���b�V�����������䃌�W�X�^1*/
typedef union {
	struct {
		UINT8	reserve1:1;	/* R  �s��										*/
		UINT8	fmr11:1;	/* RW EW1���[�h�I�� 0:EW0���[�h, 1:EW1���[�h	*/
		UINT8	reserve2:2;	/* R  �s��										*/
		UINT8	reserve3:2;	/* RW 0�Œ�										*/
		UINT8	no_assign:1;/* -  �s�� �����ޏꍇ��0						*/
		UINT8	fmr17:1;	/* RW �u���b�NA,B�A�N�Z�X�E�G�C�g				*/
	} bit;
	UINT8	byte;
} FMR1_TYPE;
FMR1_TYPE	fmr1_addr;

#define		FMR1			fmr1_addr.byte
#define		FMR11			fmr1_addr.bit.fmr11
#define		FMR17			fmr1_addr.bit.fmr17

/*
 *  Flash Control Register 4
 */
#pragma ADDRESS		fmr4_addr	01b3H		/* �t���b�V�����������䃌�W�X�^4*/
typedef union {
	struct {
		UINT8	fmr40:1;	/* RW �C���[�Y�T�X�y���h�@�\���� 0:�֎~, 1:����	*/
		UINT8	fmr41:1;	/* RW �C���[�Y�T�X�y���h���N�G�X�g				*/
							/*    0:�C���[�Y���X�^�[�g1:�T�X�y���h���N�G�X�g*/
		UINT8	reserve1:4;	/* RW 0�Œ�										*/
		UINT8	fmr46:1;	/* R  �C���[�Y�X�e�[�^�X 0:���쒆, 1:��~		*/
		UINT8	reserve2:1;	/* RW 0�Œ�										*/
	} bit;
	UINT8	byte;
} FMR4_TYPE;
FMR4_TYPE	fmr4_addr;

#define		FMR4			fmr4_addr.byte
#define		FMR40			fmr4_addr.bit.fmr40
#define		FMR41			fmr4_addr.bit.fmr41
#define		FMR46			fmr4_addr.bit.fmr46


#endif	/* _SFR_M16C_26_H_	*/
