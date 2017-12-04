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
#if !defined( _SAMPLE_COM_H_ )
#define _SAMPLE_COM_H_

#include "kernel_id.h"

/*
 *  OIL定義シンボルの外部参照
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
 *  ログ出力関数
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
 *  APIエラーログマクロ
 *
 *  ErrorHookが有効の場合はErrorHookから
 *  エラーログを出力し, ErrorHookが無効の場合は
 *  以下のマクロよりエラーログ出力を行う.
 */
#if defined( USE_ERRORHOOK )
#define	error_log( api )	api
#else	/* !defined( USE_ERRORHOOK ) */
#define	error_log( api )					\
	{										\
		StatusType	ercd;					\
		ercd = api;		/* 各API実行	*/	\
		if( ercd != E_OK ){					\
			PutSysLog( (const UINT8 *)"Error:" );	\
			PutSysLog( ercd_tbl[ercd] );	\
			PutSysLog( (const UINT8 *)"\r\n" );		\
		}									\
	}
#endif	/* defined( USE_ERRORHOOK ) */

#endif /* _SAMPLE_COM_H_ */

