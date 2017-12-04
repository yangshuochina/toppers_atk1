/*
 *  TOPPERS Automotive Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 *      Automotive Kernel
 * 
 *  Copyright (C) 2007 by Hitachi,Ltd., Automotive Systems, JAPAN
 *  Copyright (C) 2007 by Hitachi Information & Control Solutions,Ltd., JAPAN
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
 *  �T���v���p IO ��` SH72513 �p
 */


#ifndef _SH72513_H
#define _SH72513_H

/* BSC */
#define CS0BCR	(*(volatile unsigned long *) 0xFFFC0004u)
#define CS2BCR	(*(volatile unsigned long *) 0xFFFC000Cu)
#define CS0WCR	(*(volatile unsigned long *) 0xFFFC0028u)

/* PORTB PFC */
#define PBCR2	(*(volatile unsigned short *)0xFFFE3894u)

/* PORTC PFC */
#define PCCR4	(*(volatile unsigned short *)0xFFFE3910u)
#define PCCR3	(*(volatile unsigned short *)0xFFFE3912u)
#define PCCR2	(*(volatile unsigned short *)0xFFFE3914u)
#define PCCR1	(*(volatile unsigned short *)0xFFFE3916u)

/* PORTJ PFC */
#define PJCR1	(*(volatile unsigned short *)0xFFFFC872u)

/* ROM */
#define RCCR	(*(volatile unsigned long  *)0xFFFC1400u)

/* RAM */
#define RAMACYC	(*(volatile unsigned short *)0xFFFF0812u)
#define RAMWEN	(*(volatile unsigned short *)0xFFFF0802u)
#define RAMERR	(*(volatile unsigned char  *)0xFFFF0806u)

/* ATU-III */
#define ATUENR	(*(volatile unsigned short *)0xFFFFF000u)
#define	ATUENR_TDE	(0x0010)
#define	ATUENR_PSCE	(0x0001)

#define PSCR0	(*(volatile unsigned short  *)0xFFFFF100u)
#define PSCR1	(*(volatile unsigned short  *)0xFFFFF102u)
#define PSCR2	(*(volatile unsigned short  *)0xFFFFF104u)
#define PSCR3	(*(volatile unsigned short  *)0xFFFFF106u)

#define	TSTRD	(*(volatile unsigned char  *)0xFFFFF500u)
#define	TSTRD_STRD0	(0x01)
#define	TSTRD_STRD1	(0x02)

#define	TCRD0	(*(volatile unsigned short *)0xFFFFF52Cu)
#define	TCRD1	(*(volatile unsigned short *)0xFFFFF53Cu)
#define	TCRD0_DCSELD0		(0x0001)	/* �_�E���J�E���g�N���b�N �N���b�N�o�X�P (10MHz) */
#define	TCRD1_DCSELD1		(0x0001)	/* �_�E���J�E���g�N���b�N �N���b�N�o�X�P (10MHz) */

#define	DSTRD0	(*(volatile unsigned char  *)0xFFFFF585u)
#define	DSTRD1	(*(volatile unsigned char  *)0xFFFFF5C5u)
#define	DSTRD0_DSTD00	(0x01)
#define	DSTRD1_DSTD10	(0x01)

#define	TSRD0	(*(volatile unsigned short *)0xFFFFF58Cu)
#define	TSRD1	(*(volatile unsigned short *)0xFFFFF5CCu)
#define	TSRD0_UDFD00	(0x0100)
#define	TSRD1_UDFD10	(0x0100)

#define	TIERD0	(*(volatile unsigned short *)0xFFFFF58Eu)
#define	TIERD1	(*(volatile unsigned short *)0xFFFFF5CEu)
#define	TIERD0_UDED00	(0x0100)
#define	TIERD1_UDED10	(0x0100)

#define	DCNTD00	(*(volatile unsigned long  *)0xFFFFF5B0u)
#define	DCNTD10	(*(volatile unsigned long  *)0xFFFFF5F0u)


/* CMT */
#define CMSTR	(*(volatile unsigned short *)0xFFFEC000u)
#define CMCR_0	(*(volatile unsigned char  *)0xFFFEC010u)
#define CMSR_0	(*(volatile unsigned char  *)0xFFFEC011u)
#define CMCNT_0	(*(volatile unsigned short *)0xFFFEC012u)
#define CMCOR_0	(*(volatile unsigned short *)0xFFFEC014u)

#define CMCR_1	(*(volatile unsigned char  *)0xFFFEC020u)
#define CMSR_1	(*(volatile unsigned char  *)0xFFFEC021u)
#define CMCNT_1	(*(volatile unsigned short *)0xFFFEC022u)
#define CMCOR_1	(*(volatile unsigned short *)0xFFFEC024u)

/* INTC */
#define	IPR05	(*(volatile unsigned short *)0xFFFE0C04u)
#define	IPR06	(*(volatile unsigned short *)0xFFFE0C06u)
#define	IPR10	(*(volatile unsigned short *)0xFFFE0C0Eu)
#define	IPR11	(*(volatile unsigned short *)0xFFFE0C10u)
#define	IPR26	(*(volatile unsigned short *)0xFFFE0C2Eu)
#define	IBCR	(*(volatile unsigned short *)0xFFFE080Cu)
#define	IBNR	(*(volatile unsigned short *)0xFFFE080Eu)

/* SCI A  */
#define	SCSMR1A	(*(volatile unsigned char  *)0xFFFF8000u)
#define	SCBRR1A	(*(volatile unsigned char  *)0xFFFF8004u)
#define	SCSCR1A	(*(volatile unsigned char  *)0xFFFF8008u)
#define	SCTDR1A	(*(volatile unsigned char  *)0xFFFF800Cu)
#define	SCSSR1A	(*(volatile unsigned char  *)0xFFFF8010u)
#define	SCRDR1A	(*(volatile unsigned char  *)0xFFFF8014u)

#endif   /* _SH72513_H */
