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
 *  上記著作権者は，以下の (1)～(4) の条件か，Free Software Foundation 
 *  によって公表されている GNU General Public License の Version 2 に記
 *  述されている条件を満たす場合に限り，本ソフトウェア（本ソフトウェア
 *  を改変したものを含む．以下同じ）を使用・複製・改変・再配布（以下，
 *  利用と呼ぶ）することを無償で許諾する．
 *  (1) 本ソフトウェアをソースコードの形で利用する場合には，上記の著作
 *      権表示，この利用条件および下記の無保証規定が，そのままの形でソー
 *      スコード中に含まれていること．
 *  (2) 本ソフトウェアを，ライブラリ形式など，他のソフトウェア開発に使
 *      用できる形で再配布する場合には，再配布に伴うドキュメント（利用
 *      者マニュアルなど）に，上記の著作権表示，この利用条件および下記
 *      の無保証規定を掲載すること．
 *  (3) 本ソフトウェアを，機器に組み込むなど，他のソフトウェア開発に使
 *      用できない形で再配布する場合には，次のいずれかの条件を満たすこ
 *      と．
 *    (a) 再配布に伴うドキュメント（利用者マニュアルなど）に，上記の著
 *        作権表示，この利用条件および下記の無保証規定を掲載すること．
 *    (b) 再配布の形態を，別に定める方法によって，TOPPERSプロジェクトに
 *        報告すること．
 *  (4) 本ソフトウェアの利用により直接的または間接的に生じるいかなる損
 *      害からも，上記著作権者およびTOPPERSプロジェクトを免責すること．
 * 
 *  本ソフトウェアは，無保証で提供されているものである．上記著作権者お
 *  よびTOPPERSプロジェクトは，本ソフトウェアに関して，その適用可能性も
 *  含めて，いかなる保証も行わない．また，本ソフトウェアの利用により直
 *  接的または間接的に生じたいかなる損害に関しても，その責任を負わない．
 * 
 */
#include "kernel.h"
#include "sys_timer.h"
#include "serial.h"
#include "sample_config.h"
#include "kernel_id.h"
#include "sample1_com_ecc2.h"

/*
 *  内部定数データテーブル
 */
/* 無効イベントマスク値	*/
static const EventMaskType	invalid_mask = (EventMaskType)( 0 );

/* イベントマスクテーブル	*/
static const EventMaskType * const	event_mask_tbl[] = {
	&invalid_mask,
	&T2Evt,
	&T3Evt,
	&invalid_mask,
	&invalid_mask
};

/* タスクIDテーブル	*/
static const TaskType * const	task_id_tbl[] = {
	&Task1,
	&Task2,
	&Task3,
	&Task4,
	&Task5
};

/* アラームIDテーブル	*/
static const AlarmType * const	alarm_id_tbl[] = {
	&ActTskArm,
	&SetEvtArm,
	&CallBackArm
};

/* ティック値テーブル	*/
static const TickType	tick_tbl[] = {
	(TickType)500,
	(TickType)900
};

/* サイクル値テーブル	*/
static const TickType	cycle_tbl[] = {
	(TickType)0,
	(TickType)500
};

/* イベントマスク名文字列テーブル	*/
static const UINT8	*event_name_tbl[] = {
	"Invalid",
	"T2Evt",
	"T3Evt",
	"Invalid",
	"Invalid"
};

/* タスク名文字列テーブル	*/
const UINT8	*task_name_tbl[] = {
	"Task1",
	"Task2",
	"Task3",
	"Task4",
	"Task5"
};

/* タスク状態文字列テーブル	*/
static const UINT8	*task_state_tbl[] = {
	"SUSPENDED",
	"RUNNING",
	"READY",
	"WAITING",
};

/* アラーム名文字列テーブル	*/
static const UINT8	*alarm_name_tbl[] = {
	"ActTskArm",
	"SetEvtArm",
	"CallBackArm"
};


/* エラー文字列テーブル	*/
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
 *  ActivateTask 実行・ログ出力処理
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
 *  ActivateTask 実行(NonPriTask)・ログ出力処理
 */
void
PutActNonPriTsk( void )
{
	PutSysLog( (const UINT8 *)
				"Call ActivateTask(NonPriTask)\r\n" );

	error_log( ActivateTask( NonPriTask ) );
}	/* PutActNonPriTsk	*/

/*
 *  TerminateTask 実行・ログ出力処理
 */
void
PutTermTsk( UINT8 task_no )
{
	StatusType	ercd;		/* エラーコード			*/

	PutSysLog( task_name_tbl[task_no] );
	PutSysLog( (const UINT8 *)" TERMINATE\r\n" );

	ercd = TerminateTask();
	ShutdownOS( ercd );
}

/*
 *  ChainTask 実行・ログ出力処理
 */
void
PutChainTsk( UINT8 from_task_no, UINT8 to_task_no )
{
	StatusType	ercd;			/* エラーコード			*/

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
 *  Schedule 実行・ログ出力処理
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
 *  GetTaskID 実行・ログ出力処理
 */
void
PutTaskID( void )
{
	TaskType	task_id;		/* タスクID取得バッファ		*/
	UINT8		str_buf[16];	/* ログ文字列生成バッファ	*/

	error_log( GetTaskID( &task_id ) );

	PutSysLog( (const UINT8 *)"TaskID:" );
	ConvByte2DecStr( str_buf, task_id );
	PutSysLog(  (const UINT8 *)str_buf );
	PutSysLog( (const UINT8 *)"\r\n" );
}	/* PutTaskID	*/

/*
 *  GetTaskState 実行・ログ出力処理
 */
void
PutTaskState( UINT8 task_no )
{
	TaskStateType	state;		/* タスクID取得バッファ		*/

	error_log( GetTaskState( *(task_id_tbl[task_no]), &state ) );

	PutSysLog( task_name_tbl[task_no] );
	PutSysLog( (const UINT8 *)" State:" );
	PutSysLog(  task_state_tbl[state]  );
	PutSysLog( (const UINT8 *)"\r\n" );
}	/* PutTaskState	*/

/*
 *  DisableAllInterrupts/EnableAllInterrupts 実行・ログ出力処理
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
 *  SuspendAllInterrupts/ResumeAllInterrupts 実行・ログ出力処理
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
 *  SuspendOSInterrupts/ResumeOSInterrupts 実行・ログ出力処理
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
 *  割込み動作テスト用HWカウンタ値のログ出力処理
 */
void
PutHwCnt3( void )
{
	UINT8	isr1_cnt;		/* ISR1 カウント値取得バッファ	*/
	UINT8	isr2_cnt;		/* ISR2 カウント値取得バッファ	*/
	UINT8	cnt;			/* 出力回数カウンタ				*/
	UINT8	str_buf[16];	/* ログ文字列生成バッファ		*/

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
 *  GetResource/ReleaseResource 実行(スケジューラ)・ログ出力処理
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
 *  GetResource/ReleaseResource 実行(割込みレベル)・ログ出力処理
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
 *  GetResource 実行(タスクレベル)・ログ出力処理
 */
void
PutGetTskRes( void )
{
	PutSysLog( (const UINT8 *)
				"Call GetResource(TskLevelRes)\r\n" );

	error_log( GetResource( TskLevelRes ) );
}	/* PutGetTskRes	*/

/*
 *  ReleaseResource 実行(タスクレベル)・ログ出力処理
 */
void
PutRelTskRes( void )
{
	PutSysLog( (const UINT8 *)
				"Call ReleaseResource(TskLevelRes)\r\n" );

	error_log( ReleaseResource( TskLevelRes ) );
}

/*
 *  SetEvent 実行・ログ出力処理
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
 *  ClearEvent 実行・ログ出力処理
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
 *  GetEvent 実行・ログ出力処理
 */
 void
PutGetEvt( UINT8 task_no )
{
	EventMaskType	mask;			/* イベントマスク取得バッファ	*/
	UINT8			str_buf[16];	/* ログ文字列生成バッファ		*/

	error_log( GetEvent( *(task_id_tbl[task_no]), &mask ) );

	PutSysLog( task_name_tbl[task_no] );
	PutSysLog( (const UINT8 *)" Event Mask:0x" );
	ConvLong2HexStr( str_buf, mask );
	PutSysLog( (const UINT8 *)str_buf );
	PutSysLog( (const UINT8 *)"\r\n" );
}	/* PutGetEvt	*/

/*
 *  WaitEvent 実行・ログ出力処理
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
 *  GetAlarmBase 実行・ログ出力処理
 */
void
PutArmBase( void )
{
	AlarmBaseType	info;			/* アラームベース情報取得バッファ	*/
	UINT8			str_buf[16];	/* ログ文字列生成バッファ			*/

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
 *  PutArmTick 実行・ログ出力処理
 */
void
PutArmTick( void )
{
	TickType	tick;			/* 残りティック取得バッファ	*/
	UINT8		str_buf[16];	/* ログ文字列生成バッファ	*/

	error_log( GetAlarm( MainCycArm, &tick ) );

	PutSysLog( (const UINT8 *)"MainCycArm Tick:" );
	ConvLong2DecStr( str_buf, tick );
	PutSysLog( (const UINT8 *)str_buf );
	PutSysLog( (const UINT8 *)"\r\n" );
}	/* PutArmTick	*/

/*
 *  SetRelAlarm 実行・ログ出力処理
 */
void
PutSetRel( UINT8 alarm_no, UINT8 tick_no, UINT8 cycle_no )
{
	UINT8		str_buf[16];	/* ログ文字列生成バッファ	*/

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
 *  SetAbsAlarm 実行・ログ出力処理
 */
void
PutSetAbs( UINT8 alarm_no, UINT8 tick_no, UINT8 cycle_no )
{
	UINT8		str_buf[16];	/* ログ文字列生成バッファ	*/

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
 *  CancelAlarm 実行・ログ出力処理
 */
void
PutCanArm( void )
{
	PutSysLog( (const UINT8 *)
				"Call CancelAlarm(CallBackArm)\r\n" );

	error_log( CancelAlarm( CallBackArm ) );
}	/* PutCanArm	*/

/*
 *  GetActiveApplicationMode 実行・ログ出力処理
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

