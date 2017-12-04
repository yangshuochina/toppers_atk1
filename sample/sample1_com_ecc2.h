/*
 *  TOPPERS Automotive Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 *      Automotive Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
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
#if !defined( _SAMPLE_COM_H_ )
#define _SAMPLE_COM_H_

#include "kernel_id.h"

/*
 *  OIL��`�V���{���̊O���Q��
 */
DeclareTask( MainTask );
DeclareTask( HighPriorityTask );
DeclareTask( NonPriTask );
DeclareTask( Task1 );
DeclareTask( Task2 );
DeclareTask( Task3 );
DeclareTask( Task4 );
DeclareTask( Task5 );
DeclareResource( TskLevelRes );
DeclareResource( IntLevelRes );
DeclareEvent( MainEvt );
DeclareEvent( T2Evt );
DeclareEvent( T3Evt );
DeclareAlarm( MainCycArm );
DeclareAlarm( ActTskArm );
DeclareAlarm( SetEvtArm );
DeclareAlarm( CallBackArm );

/*
 *  ���O�o�͊֐�
 */
void		PutActTsk( UINT8 task_no );
void		PutActNonPriTsk( void );
void		PutTermTsk( UINT8 task_no );
void		PutChainTsk( UINT8 from_task_no, UINT8 to_task_no );
void		PutSchedule( void );
void		PutTaskID( void );
void		PutTaskState( UINT8 task_no );
void		PutDisAllInt( void );
void		PutSusAllInt( void );
void		PutSusOSInt( void );
void		PutHwCnt3( void );
void		PutGetSchedRes( void );
void		PutGetIntRes( void );
void		PutGetTskRes( void );
void		PutRelTskRes( void );
void		PutSetEvt( UINT8 task_no );
void		PutClrEvt( UINT8 task_no );
void		PutGetEvt( UINT8 task_no );
void		PutWaitEvt( UINT8 task_no );
void		PutArmBase( void );
void		PutArmTick( void );
void		PutSetRel( UINT8 alarm_no, UINT8 tick_no, UINT8 cycle_no );
void		PutSetAbs( UINT8 alarm_no, UINT8 tick_no, UINT8 cycle_no );
void		PutCanArm( void );
void		PutAppMode( void );

extern const UINT8	*ercd_tbl[];

/*
 *  API�G���[���O�}�N��
 *
 *  ErrorHook���L���̏ꍇ��ErrorHook����
 *  �G���[���O���o�͂�, ErrorHook�������̏ꍇ��
 *  �ȉ��̃}�N�����G���[���O�o�͂��s��.
 */
#if defined( USE_ERRORHOOK )
#define	error_log( api )	api
#else	/* !defined( USE_ERRORHOOK ) */
#define	error_log( api )					\
	{										\
		StatusType	ercd;					\
		ercd = api;		/* �eAPI���s	*/	\
		if( ercd != E_OK ){					\
			PutSysLog( (const UINT8 *)"Error:" );	\
			PutSysLog( ercd_tbl[ercd] );	\
			PutSysLog( (const UINT8 *)"\r\n" );		\
		}									\
	}
#endif	/* defined( USE_ERRORHOOK ) */

#endif /* _SAMPLE_COM_H_ */

