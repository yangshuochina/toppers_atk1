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
#include "kernel.h"
#include "sys_timer.h"
#include "serial.h"
#include "sample_config.h"
#include "kernel_id.h"
#include "sample1_com_ecc2.h"

/*
 *  �����萔�f�[�^�e�[�u��
 */
/* �����C�x���g�}�X�N�l	*/
static const EventMaskType	invalid_mask = (EventMaskType)( 0 );

/* �C�x���g�}�X�N�e�[�u��	*/
static const EventMaskType * const	event_mask_tbl[] = {
	&invalid_mask,
	&T2Evt,
	&T3Evt,
	&invalid_mask,
	&invalid_mask
};

/* �^�X�NID�e�[�u��	*/
static const TaskType * const	task_id_tbl[] = {
	&Task1,
	&Task2,
	&Task3,
	&Task4,
	&Task5
};

/* �A���[��ID�e�[�u��	*/
static const AlarmType * const	alarm_id_tbl[] = {
	&ActTskArm,
	&SetEvtArm,
	&CallBackArm
};

/* �e�B�b�N�l�e�[�u��	*/
static const TickType	tick_tbl[] = {
	(TickType)500,
	(TickType)900
};

/* �T�C�N���l�e�[�u��	*/
static const TickType	cycle_tbl[] = {
	(TickType)0,
	(TickType)500
};

/* �C�x���g�}�X�N��������e�[�u��	*/
static const UINT8	*event_name_tbl[] = {
	"Invalid",
	"T2Evt",
	"T3Evt",
	"Invalid",
	"Invalid"
};

/* �^�X�N��������e�[�u��	*/
const UINT8	*task_name_tbl[] = {
	"Task1",
	"Task2",
	"Task3",
	"Task4",
	"Task5"
};

/* �^�X�N��ԕ�����e�[�u��	*/
static const UINT8	*task_state_tbl[] = {
	"SUSPENDED",
	"RUNNING",
	"READY",
	"WAITING",
};

/* �A���[����������e�[�u��	*/
static const UINT8	*alarm_name_tbl[] = {
	"ActTskArm",
	"SetEvtArm",
	"CallBackArm"
};


/* �G���[������e�[�u��	*/
const UINT8	*ercd_tbl[] = {
	"E_OK",
	"E_OS_ACCESS",
	"E_OS_CALLEVEL",
	"E_OS_ID",
	"E_OS_LIMIT",
	"E_OS_NOFUNC",
	"E_OS_RESOURCE",
	"E_OS_STATE",
	"E_OS_VALUE"
};


/*
 *  ActivateTask ���s�E���O�o�͏���
 */
void
PutActTsk( UINT8 task_no )
{
	PutSysLog( (const UINT8 *)"Call ActivateTask(" );
	PutSysLog( task_name_tbl[task_no] );
	PutSysLog( (const UINT8 *)")\r\n" );

	error_log( ActivateTask( *(task_id_tbl[task_no]) ) );

}	/* PutActTsk	*/

/*
 *  ActivateTask ���s(NonPriTask)�E���O�o�͏���
 */
void
PutActNonPriTsk( void )
{
	PutSysLog( (const UINT8 *)
				"Call ActivateTask(NonPriTask)\r\n" );

	error_log( ActivateTask( NonPriTask ) );
}	/* PutActNonPriTsk	*/

/*
 *  TerminateTask ���s�E���O�o�͏���
 */
void
PutTermTsk( UINT8 task_no )
{
	StatusType	ercd;		/* �G���[�R�[�h			*/

	PutSysLog( task_name_tbl[task_no] );
	PutSysLog( (const UINT8 *)" TERMINATE\r\n" );

	ercd = TerminateTask();
	ShutdownOS( ercd );
}

/*
 *  ChainTask ���s�E���O�o�͏���
 */
void
PutChainTsk( UINT8 from_task_no, UINT8 to_task_no )
{
	StatusType	ercd;			/* �G���[�R�[�h			*/

	PutSysLog( (const UINT8 *)"Call ChainTask(" );
	PutSysLog( task_name_tbl[to_task_no] );
	PutSysLog( (const UINT8 *)")\r\n" );
	PutSysLog( task_name_tbl[from_task_no] );
	PutSysLog( (const UINT8 *)" TERMINATE\r\n" );

	ercd = ChainTask( *(task_id_tbl[to_task_no]) );
	if( ercd == E_OS_LIMIT ){
		PutSysLog( (const UINT8 *)"Call TerminateTask()\r\n" );
		PutSysLog( (const UINT8 *)
					"Because of ChainTask E_OS_LIMIT return\r\n" );
		ercd = TerminateTask();
	}
	ShutdownOS( ercd );
}	/* PutChainTsk	*/

/*
 *  Schedule ���s�E���O�o�͏���
 */
void
PutSchedule( void )
{
	PutSysLog( (const UINT8 *)
				"Call ActivateTask(HighPriorityTask)\r\n" );

	error_log( ActivateTask( HighPriorityTask ) );
	PutSysLog( (const UINT8 *)"Call Schedule()\r\n" );

	error_log( Schedule() );
	PutSysLog( (const UINT8 *)"Retrun Schedule()\r\n" );
}	/* PutSchedule	*/

/*
 *  GetTaskID ���s�E���O�o�͏���
 */
void
PutTaskID( void )
{
	TaskType	task_id;		/* �^�X�NID�擾�o�b�t�@		*/
	UINT8		str_buf[16];	/* ���O�����񐶐��o�b�t�@	*/

	error_log( GetTaskID( &task_id ) );

	PutSysLog( (const UINT8 *)"TaskID:" );
	ConvByte2DecStr( str_buf, task_id );
	PutSysLog(  (const UINT8 *)str_buf );
	PutSysLog( (const UINT8 *)"\r\n" );
}	/* PutTaskID	*/

/*
 *  GetTaskState ���s�E���O�o�͏���
 */
void
PutTaskState( UINT8 task_no )
{
	TaskStateType	state;		/* �^�X�NID�擾�o�b�t�@		*/

	error_log( GetTaskState( *(task_id_tbl[task_no]), &state ) );

	PutSysLog( task_name_tbl[task_no] );
	PutSysLog( (const UINT8 *)" State:" );
	PutSysLog(  task_state_tbl[state]  );
	PutSysLog( (const UINT8 *)"\r\n" );
}	/* PutTaskState	*/

/*
 *  DisableAllInterrupts/EnableAllInterrupts ���s�E���O�o�͏���
 */
void
PutDisAllInt( void )
{
	PutSysLog( (const UINT8 *)"Call DisableAllInterrupts\r\n" );

	DisableAllInterrupts();

	PutHwCnt3();
	PutIntSysLog( (const UINT8 *)"Call EnableAllInterrupts\r\n" );

	EnableAllInterrupts();
}	/* PutDisAllInt	*/

/*
 *  SuspendAllInterrupts/ResumeAllInterrupts ���s�E���O�o�͏���
 */
void
PutSusAllInt( void )
{
	PutSysLog( (const UINT8 *)"Call SuspendAllInterrupts\r\n" );

	SuspendAllInterrupts();

	PutHwCnt3();
	PutIntSysLog( (const UINT8 *)"Call SuspendAllInterrupts\r\n" );

	SuspendAllInterrupts();

	PutHwCnt3();
	PutIntSysLog( (const UINT8 *)"Call ResumeAllInterrupts\r\n" );

	ResumeAllInterrupts();

	PutHwCnt3();
	PutIntSysLog( (const UINT8 *)"Call ResumeAllInterrupts\r\n" );

	ResumeAllInterrupts();
}	/* PutSusAllInt	*/

/*
 *  SuspendOSInterrupts/ResumeOSInterrupts ���s�E���O�o�͏���
 */
void
PutSusOSInt( void )
{
	PutSysLog( (const UINT8 *)"Call SuspendOSInterrupts\r\n" );

	SuspendOSInterrupts();

	PutHwCnt3();
	PutSysLog( (const UINT8 *)"Call SuspendOSInterrupts\r\n" );

	SuspendOSInterrupts();

	PutHwCnt3();
	PutSysLog( (const UINT8 *)"Call SuspendAllInterrupts\r\n" );

	SuspendAllInterrupts();

	PutHwCnt3();
	PutIntSysLog( (const UINT8 *)"Call ResumeAllInterrupts\r\n" );

	ResumeAllInterrupts();

	PutHwCnt3();
	PutSysLog( (const UINT8 *)"Call ResumeOSInterrupts\r\n" );

	ResumeOSInterrupts();

	PutHwCnt3();
	PutSysLog( (const UINT8 *)"Call ResumeOSInterrupts\r\n" );

	ResumeOSInterrupts();
}	/* PutSusOSInt	*/

/*
 *  �����ݓ���e�X�g�pHW�J�E���^�l�̃��O�o�͏���
 */
void
PutHwCnt3( void )
{
	UINT8	isr1_cnt;		/* ISR1 �J�E���g�l�擾�o�b�t�@	*/
	UINT8	isr2_cnt;		/* ISR2 �J�E���g�l�擾�o�b�t�@	*/
	UINT8	cnt;			/* �o�͉񐔃J�E���^				*/
	UINT8	str_buf[16];	/* ���O�����񐶐��o�b�t�@		*/

	for( cnt = 0; cnt < 3; cnt++ ){
		GetHwCnt( &isr1_cnt, &isr2_cnt );
		PutIntSysLog( (const UINT8 *)"ISR1 Cnt:" );
		ConvByte2DecStr( str_buf, isr1_cnt );
		PutIntSysLog( (const UINT8 *)str_buf );
		PutIntSysLog( (const UINT8 *)", ISR2 Cnt:" );
		ConvByte2DecStr( str_buf, isr2_cnt );
		PutIntSysLog( (const UINT8 *)str_buf );
		PutIntSysLog( (const UINT8 *)"\r\n" );
	}
}	/* PutHwCnt3	*/

/*
 *  GetResource/ReleaseResource ���s(�X�P�W���[��)�E���O�o�͏���
 */
void
PutGetSchedRes( void )
{
	PutSysLog( (const UINT8 *)
				"Call GetResource(RES_SCHEDULER)\r\n" );
	error_log( GetResource( RES_SCHEDULER ) );
	error_log( ActivateTask( HighPriorityTask ) );
	PutSysLog( (const UINT8 *)
				"Call ReleaseResource(RES_SCHEDULER)\r\n" );
	error_log( ReleaseResource( RES_SCHEDULER ) );
}	/* PutGetSchedRes	*/

/*
 *  GetResource/ReleaseResource ���s(�����݃��x��)�E���O�o�͏���
 */
void
PutGetIntRes( void )
{
	PutSysLog( (const UINT8 *)
				"Call GetResource(IntLevelRes)\r\n" );
	error_log( GetResource( IntLevelRes ) );

	PutHwCnt3();
	PutSysLog( (const UINT8 *)
				"Call ReleaseResource(IntLevelRes)\r\n" );

	error_log( ReleaseResource( IntLevelRes ) );
}	/* PutGetIntRes	*/

/*
 *  GetResource ���s(�^�X�N���x��)�E���O�o�͏���
 */
void
PutGetTskRes( void )
{
	PutSysLog( (const UINT8 *)
				"Call GetResource(TskLevelRes)\r\n" );

	error_log( GetResource( TskLevelRes ) );
}	/* PutGetTskRes	*/

/*
 *  ReleaseResource ���s(�^�X�N���x��)�E���O�o�͏���
 */
void
PutRelTskRes( void )
{
	PutSysLog( (const UINT8 *)
				"Call ReleaseResource(TskLevelRes)\r\n" );

	error_log( ReleaseResource( TskLevelRes ) );
}

/*
 *  SetEvent ���s�E���O�o�͏���
 */
void
PutSetEvt( UINT8 task_no )
{
	PutSysLog( (const UINT8 *)"Call SetEvent(" );
	PutSysLog( task_name_tbl[task_no] );
	PutSysLog( (const UINT8 *)", " );
	PutSysLog( event_name_tbl[task_no] );
	PutSysLog( (const UINT8 *)")\r\n" );

	error_log( SetEvent( *(task_id_tbl[task_no]), *(event_mask_tbl[task_no]) ) );
}	/* PutSetEvt	*/

/*
 *  ClearEvent ���s�E���O�o�͏���
 */
void
PutClrEvt( UINT8 task_no )
{
	PutSysLog( (const UINT8 *)"Call ClearEvent(" );
	PutSysLog( event_name_tbl[task_no] );
	PutSysLog( (const UINT8 *)")\r\n" );

	error_log( ClearEvent( *( event_mask_tbl[task_no] ) ) );
}	/* PutClrEvt	*/

/*
 *  GetEvent ���s�E���O�o�͏���
 */
 void
PutGetEvt( UINT8 task_no )
{
	EventMaskType	mask;			/* �C�x���g�}�X�N�擾�o�b�t�@	*/
	UINT8			str_buf[16];	/* ���O�����񐶐��o�b�t�@		*/

	error_log( GetEvent( *(task_id_tbl[task_no]), &mask ) );

	PutSysLog( task_name_tbl[task_no] );
	PutSysLog( (const UINT8 *)" Event Mask:0x" );
	ConvLong2HexStr( str_buf, mask );
	PutSysLog( (const UINT8 *)str_buf );
	PutSysLog( (const UINT8 *)"\r\n" );
}	/* PutGetEvt	*/

/*
 *  WaitEvent ���s�E���O�o�͏���
 */
void
PutWaitEvt( UINT8 task_no )
{
	PutSysLog( (const UINT8 *)"Call WaitEvent(" );
	PutSysLog( event_name_tbl[task_no] );
	PutSysLog( (const UINT8 *)")\r\n" );

	error_log( WaitEvent( *( event_mask_tbl[task_no] ) ) );
}	/* PutWaitEvt	*/

/*
 *  GetAlarmBase ���s�E���O�o�͏���
 */
void
PutArmBase( void )
{
	AlarmBaseType	info;			/* �A���[���x�[�X���擾�o�b�t�@	*/
	UINT8			str_buf[16];	/* ���O�����񐶐��o�b�t�@			*/

	error_log( GetAlarmBase( MainCycArm, &info) );

	PutSysLog( (const UINT8 *)
				"MainCycArm Base:\r\n\tMAXALLOWEDVALUE=" );
	ConvLong2DecStr( str_buf, info.maxallowedvalue );
	PutSysLog( (const UINT8 *)str_buf );
	PutSysLog( (const UINT8 *)"\r\n\tTICKSPERBASE=" );
	ConvLong2DecStr( str_buf, info.ticksperbase );
	PutSysLog( (const UINT8 *)str_buf );
	PutSysLog( (const UINT8 *)"\r\n\tMINCYCLE=" );
	ConvLong2DecStr( str_buf, info.mincycle );
	PutSysLog( (const UINT8 *)str_buf );
	PutSysLog( (const UINT8 *)"\r\n" );
}	/* PutArmBase	*/

/*
 *  PutArmTick ���s�E���O�o�͏���
 */
void
PutArmTick( void )
{
	TickType	tick;			/* �c��e�B�b�N�擾�o�b�t�@	*/
	UINT8		str_buf[16];	/* ���O�����񐶐��o�b�t�@	*/

	error_log( GetAlarm( MainCycArm, &tick ) );

	PutSysLog( (const UINT8 *)"MainCycArm Tick:" );
	ConvLong2DecStr( str_buf, tick );
	PutSysLog( (const UINT8 *)str_buf );
	PutSysLog( (const UINT8 *)"\r\n" );
}	/* PutArmTick	*/

/*
 *  SetRelAlarm ���s�E���O�o�͏���
 */
void
PutSetRel( UINT8 alarm_no, UINT8 tick_no, UINT8 cycle_no )
{
	UINT8		str_buf[16];	/* ���O�����񐶐��o�b�t�@	*/

	PutSysLog( (const UINT8 *)"Call SetRelAlarm(" );
	PutSysLog( alarm_name_tbl[alarm_no] );
	PutSysLog( (const UINT8 *)", ");
	ConvLong2DecStr(str_buf, tick_tbl[tick_no]);
	PutSysLog( (const UINT8 *)str_buf );
	PutSysLog( (const UINT8 *)", ");
	ConvLong2DecStr(str_buf, cycle_tbl[cycle_no]);
	PutSysLog( (const UINT8 *)str_buf );
	PutSysLog( (const UINT8 *)")\r\n");

	error_log( SetRelAlarm( *(alarm_id_tbl[alarm_no]),
							tick_tbl[tick_no], cycle_tbl[cycle_no] ) );
}	/* PutSetRel	*/

/*
 *  SetAbsAlarm ���s�E���O�o�͏���
 */
void
PutSetAbs( UINT8 alarm_no, UINT8 tick_no, UINT8 cycle_no )
{
	UINT8		str_buf[16];	/* ���O�����񐶐��o�b�t�@	*/

	PutSysLog( (const UINT8 *)"Call SetAbsAlarm(" );
	PutSysLog( alarm_name_tbl[alarm_no] );
	PutSysLog( (const UINT8 *)", ");
	ConvLong2DecStr(str_buf, tick_tbl[tick_no]);
	PutSysLog( (const UINT8 *)str_buf );
	PutSysLog( (const UINT8 *)", ");
	ConvLong2DecStr(str_buf, cycle_tbl[cycle_no]);
	PutSysLog( (const UINT8 *)str_buf );
	PutSysLog( (const UINT8 *)")\r\n");

	error_log( SetAbsAlarm( *(alarm_id_tbl[alarm_no]),
							tick_tbl[tick_no], cycle_tbl[cycle_no] ) );
}	/* PutSetAbs	*/

/*
 *  CancelAlarm ���s�E���O�o�͏���
 */
void
PutCanArm( void )
{
	PutSysLog( (const UINT8 *)
				"Call CancelAlarm(CallBackArm)\r\n" );

	error_log( CancelAlarm( CallBackArm ) );
}	/* PutCanArm	*/

/*
 *  GetActiveApplicationMode ���s�E���O�o�͏���
 */
void
PutAppMode( void )
{
	PutSysLog( (const UINT8 *)"ActiveApplicationMode:" );
	switch( GetActiveApplicationMode() ){
	case AppMode1:
		PutSysLog( (const UINT8 *)"AppMode1\r\n" );
		break;
	case AppMode2:
		PutSysLog( (const UINT8 *)"AppMode2\r\n" );
		break;
	case AppMode3:
		PutSysLog( (const UINT8 *)"AppMode3\r\n" );
		break;
	default:
		PutSysLog( (const UINT8 *)"Non\r\n" );
		break;
	}
}	/* PutAppMode	*/

