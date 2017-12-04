/*
 *  TOPPERS Automotive Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 *      Automotive Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2003 by Naoki Saito
 *             Nagoya Municipal Industrial Research Institute, JAPAN
 *  Copyright (C) 2004 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 *  Copyright (C) 2005-2006 by Witz Corporation, JAPAN
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
 *	�^�[�Q�b�g�V�X�e���Ɉˑ������`�iOAKS16-mini�p�j
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
#define OAKS16_MINI

/*
 *  �N�����b�Z�[�W�̃^�[�Q�b�g�V�X�e����
 */
#define TARGET_NAME "OAKS16-mini"

/*
 *  �����ݔԍ��̒�`
 */
#define	INT_BRKV		0		/* BRK����				*/
#define	INT_INT3		4		/* INT3					*/
#define	INT_INT5		8		/* INT5					*/
#define	INT_INT4		9		/* INT4					*/
#define	INT_UART2BCN	10		/* UART2�o�X�Փˌ��o	*/
#define	INT_DMA0		11		/* DMA0					*/
#define	INT_DMA1		12		/* DMA1					*/
#define	INT_KEY			13		/* �L�[����				*/
#define	INT_AD			14		/* A/D�ϊ�1				*/
#define	INT_NACK2		15		/* NACK					*/
#define	INT_ACK2		16		/* ACK					*/
#define	INT_UART2TX		15		/* UART2���M			*/
#define	INT_UART2RX		16		/* UART2��M			*/
#define	INT_UART0TX		17		/* UART0���M			*/
#define	INT_UART0RX		18		/* UART0��M			*/
#define	INT_UART1TX		19		/* UART1���M			*/
#define	INT_UART1RX		20		/* UART1��M			*/
#define	INT_TA0			21		/* �^�C�}A0				*/
#define	INT_TA1			22		/* �^�C�}A1				*/
#define	INT_TA2			23		/* �^�C�}A2				*/
#define	INT_TA3			24		/* �^�C�}A3				*/
#define	INT_TA4			25		/* �^�C�}A4				*/
#define	INT_TB0			26		/* �^�C�}B0				*/
#define	INT_TB1			27		/* �^�C�}B1				*/
#define	INT_TB2			28		/* �^�C�}B2				*/
#define	INT_INT0		29		/* INT0					*/
#define	INT_INT1		30		/* INT1					*/
#define	INT_UDI			64		/* ����`����			*/
#define	INT_OVF			65		/* �I�[�o�[�t���[		*/
#define	INT_BLKF		66		/* BRK����				*/
#define	INT_ADR			67		/* �A�h���X��v			*/
#define	INT_SSI			68		/* �V���O���X�e�b�v(�f�o�b�O�c�[���p)			*/
#define	INT_WDT			69		/* �Ď��^�C�}/���U��~��Ĕ��U���o/�d���ቺ���o	*/
#define	INT_DBC			70		/* �f�o�b�O�c�[���p		*/
#define	INT_NMI			71		/* NMI					*/
#define	INT_RESET		72		/* ���Z�b�g				*/


#endif /* _SYS_DEFS_H_ */
