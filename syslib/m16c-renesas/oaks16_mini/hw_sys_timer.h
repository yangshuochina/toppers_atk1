/*
 *  TOPPERS Automotive Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 *      Automotive Kernel
 * 
 *  Copyright (C) 2000-2002 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2003 by TOPPERS Project Educational Group.
 *  Copyright (C) 2004-2006 by Witz Corporation, JAPAN
 * 
 *  ��L���쌠�҂́CFree Software Foundation �ɂ���Č��\����Ă��� 
 *  GNU General Public License �� Version 2 �ɋL�q����Ă���������C��
 *  ����(1)�`(4)�̏����𖞂����ꍇ�Ɍ���C�{�\�t�g�E�F�A�i�{�\�t�g�E�F
 *  �A�����ς������̂��܂ށD�ȉ������j���g�p�E�����E���ρE�Ĕz�z�i�ȉ��C
 *  ���p�ƌĂԁj���邱�Ƃ𖳏��ŋ�������D
 *  (1) �{�\�t�g�E�F�A���\�[�X�R�[�h�̌`�ŗ��p����ꍇ�ɂ́C��L�̒���
 *      ���\���C���̗��p��������щ��L�̖��ۏ؋K�肪�C���̂܂܂̌`�Ń\�[
 *      �X�R�[�h���Ɋ܂܂�Ă��邱�ƁD
 *  (2) �{�\�t�g�E�F�A���ė��p�\�ȃo�C�i���R�[�h�i�����P�[�^�u���I�u
 *      �W�F�N�g�t�@�C���⃉�C�u�����Ȃǁj�̌`�ŗ��p����ꍇ�ɂ́C���p
 *      �ɔ����h�L�������g�i���p�҃}�j���A���Ȃǁj�ɁC��L�̒��쌠�\���C
 *      ���̗��p��������щ��L�̖��ۏ؋K����f�ڂ��邱�ƁD
 *  (3) �{�\�t�g�E�F�A���ė��p�s�\�ȃo�C�i���R�[�h�̌`�܂��͋@��ɑg
 *      �ݍ��񂾌`�ŗ��p����ꍇ�ɂ́C���̂����ꂩ�̏����𖞂������ƁD
 *    (a) ���p�ɔ����h�L�������g�i���p�҃}�j���A���Ȃǁj�ɁC��L�̒���
 *        ���\���C���̗��p��������щ��L�̖��ۏ؋K����f�ڂ��邱�ƁD
 *    (b) ���p�̌`�Ԃ��C�ʂɒ�߂���@�ɂ���āC��L���쌠�҂ɕ񍐂���
 *        ���ƁD
 *  (4) �{�\�t�g�E�F�A�̗��p�ɂ�蒼�ړI�܂��͊ԐړI�ɐ����邢���Ȃ鑹
 *      �Q������C��L���쌠�҂�Ɛӂ��邱�ƁD
 * 
 *  �{�\�t�g�E�F�A�́C���ۏ؂Œ񋟂���Ă�����̂ł���D��L���쌠�҂́C
 *  �{�\�t�g�E�F�A�Ɋւ��āC���̓K�p�\�����܂߂āC�����Ȃ�ۏ؂��s��
 *  �Ȃ��D�܂��C�{�\�t�g�E�F�A�̗��p�ɂ�蒼�ړI�܂��͊ԐړI�ɐ�������
 *  ���Ȃ鑹�Q�Ɋւ��Ă��C���̐ӔC�𕉂�Ȃ��D
 * 
 */

/*
 *	�^�[�Q�b�g�ˑ��^�C�}���W���[���iOAKS16-mini�j
 */

#ifndef _HW_SYS_TIMER_H_
#define _HW_SYS_TIMER_H_

#include	"kernel.h"
#include	"sfrm16c26.h"


/*
 *  �V�X�e���^�C�}�̊����݃��x����`
 */
#define CFG_INTLVL_SYSCLK	(UINT8)0x04	/* �V�X�e���N���b�N�p�^�C�} */

/*
 *  �V�X�e���^�C�}�̃R���y�A�l�i1ms�j
 */
#define	CFG_SYSCLK			(UINT16)(625u)


#ifndef _MACRO_ONLY
/*
 *  �V�X�e���^�C�}�̋N�������֐��v���g�^�C�v�錾
 */
extern void InitHwSysTimer( void );

/*
 *  �V�X�e���^�C�}�̒�~�����֐��v���g�^�C�v�錾
 */
extern void TermHwSysTimer( void );

/*
 *  �V�X�e���^�C�}�̊����ݗv���N���A�����֐��v���g�^�C�v�錾
 */
Inline void	ClearHwSysTimerInt( void );

/*
 *  �V�X�e���^�C�}�̊����ݗv���N���A����
 *
 *  �����ݔ������Ɏ����I�ɃN���A����邪�C�����݈ȊO����
 *  ���s����邱�Ƃ��z�肵�C���L��������������D
 */
Inline void
ClearHwSysTimerInt( void )
{
	IR_TA0IC = 0;						/* �����ݗv���N���A				*/
}	/* ClearHwSysTimerInt	*/

#endif /* _MACRO_ONLY */

#endif /* _HW_SYS_TIMER_H_ */
