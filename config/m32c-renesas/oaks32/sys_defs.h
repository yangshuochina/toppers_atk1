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
 *	�^�[�Q�b�g�V�X�e���Ɉˑ������`�iOAKS32�p�j
 */

#ifndef _SYS_DEFS_H_
#define _SYS_DEFS_H_

/* 
 *  �J�[�l���X�e�[�^�X�^�C�v�̒�`
 *
 *  ���L��`��L���ɂ��邱�ƂŁCOSEK�d�l�̊g���G���[�`�F�b�N�𖳌����ł���D
 */
/*#define BASIC_STATUS	*/

/* 
 *  �^�[�Q�b�g���ʃ}�N��(�V�X�e�����̒�`)
 */
#define OAKS32

/*
 *  �N�����b�Z�[�W�̃^�[�Q�b�g�V�X�e����
 */
#define	TARGET_NAME		(const UINT8 *)"M32C/OAKS32"

/*
 *  �V�X�e���Ŏg�p����v���Z�b�T�̎��
 *  144�s���ł��g�p����ꍇ�� SYS_MCU_M30835���`����
 *  100�s���ł��g�p����ꍇ�� SYS_MCU_M30833���`����
 */
/*#define	SYS_MCU_M30835	*/
#define	SYS_MCU_M30833


/*
 *  �����ݔԍ��̒�`
 */
#define	INT_BRKV		0		/* BRK����	*/
#define	INT_AD1			7		/* A/D�ϊ�1	*/
#define	INT_DMA0		8		/* DMA0	*/
#define	INT_DMA1		9		/* DMA1	*/
#define	INT_DMA2		10		/* DMA2	*/
#define	INT_DMA3		11		/* DMA3	*/
#define	INT_TA0			12		/* �^�C�}A0	*/
#define	INT_TA1			13		/* �^�C�}A1	*/
#define	INT_TA2			14		/* �^�C�}A2	*/
#define	INT_TA3			15		/* �^�C�}A3	*/
#define	INT_TA4			16		/* �^�C�}A4	*/
#define	INT_S0TNACK		17		/* NACK	*/
#define	INT_S0RACK		18		/* ACK	*/
#define	INT_S1TNACK		19		/* NACK	*/
#define	INT_S1RACK		20		/* ACK	*/
#define	INT_UART0TX		17		/* UART0���M	*/
#define	INT_UART0RX		18		/* UART0��M	*/
#define	INT_UART1TX		19		/* UART1���M	*/
#define	INT_UART1RX		20		/* UART1��M	*/
#define	INT_TB0			21		/* �^�C�}B0	*/
#define	INT_TB1			22		/* �^�C�}B1	*/
#define	INT_TB2			23		/* �^�C�}B2	*/
#define	INT_TB3			24		/* �^�C�}B3	*/
#define	INT_TB4			25		/* �^�C�}B4	*/
#define	INT_INT5		26		/* INT5	*/
#define	INT_INT4		27		/* INT4	*/
#define	INT_INT3		28		/* INT3	*/
#define	INT_INT2		29		/* INT2	*/
#define	INT_INT1		30		/* INT1	*/
#define	INT_INT0		31		/* INT0	*/
#define	INT_TB5			32		/* �^�C�}B5	*/
#define	INT_S2TNACK		33		/* NACK	*/
#define	INT_S2RACK		34		/* ACK	*/
#define	INT_S3TNACK		35		/* NACK	*/
#define	INT_S3RACK		36		/* ACK	*/
#define	INT_S4TNACK 	37		/* NACK	*/
#define	INT_S4RACK		38		/* ACK	*/
#define	INT_UART2TX		33		/* UART2���M	*/
#define	INT_UART2RX		34		/* UART2��M	*/
#define	INT_UART3TX		35		/* UART3���M	*/
#define	INT_UART3RX		36		/* UART3��M	*/
#define	INT_UART4TX 	37		/* UART4���M	*/
#define	INT_UART4RX		38		/* UART4��M	*/
#define	INT_SSC2		39		/* �o�X�Փˌ��o/�X�^�[�g�R���f�B�V�������o/�X�g�b�v�R���f�B�V�������o(UART2)/��Q�G���[	*/
#define	INT_SSC30		40		/* �o�X�Փˌ��o/�X�^�[�g�R���f�B�V�������o/�X�g�b�v�R���f�B�V�������o(UART3/UART0)/��Q�G���[	*/
#define	INT_SSC41		41		/* �o�X�Փˌ��o/�X�^�[�g�R���f�B�V�������o/�X�g�b�v�R���f�B�V�������o(UART4/UART1)/��Q�G���[	*/
#define	INT_AD0			42		/* A/D�ϊ�0	*/
#define	INT_KEY			43		/* �L�[����	*/
#define	INT_IIO0		44		/* �C���e���W�F���gI/O0	*/
#define	INT_IIO1		45		/* �C���e���W�F���gI/O1	*/
#define	INT_IIO2		46		/* �C���e���W�F���gI/O2	*/
#define	INT_IIO3		47		/* �C���e���W�F���gI/O3	*/
#define	INT_IIO4		48		/* �C���e���W�F���gI/O4	*/
#define	INT_IIO5		49		/* �C���e���W�F���gI/O5	*/
#define	INT_IIO6		50		/* �C���e���W�F���gI/O6	*/
#define	INT_IIO7		51		/* �C���e���W�F���gI/O7	*/
#define	INT_IIO8		52		/* �C���e���W�F���gI/O8	*/
#define	INT_IIO9CAN0	53		/* �C���e���W�F���gI/O9,CAN0	*/
#define	INT_IIO10CAN1	54		/* �C���e���W�F���gI/O10,CAN1	*/
#define	INT_IIO11CAN2	57		/* �C���e���W�F���gI/O11,CAN2	*/
#define	INT_UDI			64		/* ����`����	*/
#define	INT_OVF			65		/* �I�[�o�[�t���[	*/
#define	INT_BLKF		66		/* BRK����	*/
#define	INT_ADR			67		/* �A�h���X��v	*/
#define	INT_WDT			69		/* �Ď��^�C�}/���U��~���o	*/
#define	INT_NMI			71		/* NMI	*/
#define	INT_RESET		72		/* ���Z�b�g	*/


#endif /* _SYS_DEFS_H_ */
