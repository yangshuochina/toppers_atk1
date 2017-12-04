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
 *  上記著作権者は，以下の (1)〜(4) の条件か，Free Software Foundation 
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

/* 
 *  サンプルプログラム(1) ECC2の本体
 *
 *  TOPPERS Automotive Kernelの基本的な動作を確認するためのサンプルプログラム．
 *
 *  プログラムの概要：PCとボード間でシリアル通信を行い，ユーザ入力
 *  コマンドに応じた動作とログ出力を行なう．
 *
 *  ＜コマンド一覧＞
 *  ・タスク指定
 *    '1' : 以降のコマンドを Task1 に対して行う．
 *    '2' : 以降のコマンドを Task2 に対して行う．
 *    '3' : 以降のコマンドを Task3 に対して行う．
 *    '4' : 以降のコマンドを Task4 に対して行う．
 *    '5' : 以降のコマンドを Task5 に対して行う．
 *  ・タスク管理機能
 *    'a' : ActivateTask にてタスクを起動する．
 *    'A' : TerminateTask にてタスクを終了する．
 *    '!'(Shift+1) : ChainTask にてタスクを終了し，Task1 を起動する．
 *    '"'(Shift+2) : ChainTask にてタスクを終了し，Task2 を起動する．
 *    '#'(Shift+3) : ChainTask にてタスクを終了し，Task3 を起動する．
 *    '$'(Shift+4) : ChainTask にてタスクを終了し，Task4 を起動する．
 *    '%'(Shift+5) : ChainTask にてタスクを終了し，Task5 を起動する．
 *    's' : ノンプリエンプティブ属性であるタスク MainTask にて最高
 *          優先度タスク HighPriorityTask を起動し，Schedule にて
 *          再スケジューリングを行う．
 *    'S' : ノンプリエンプティブタスク NonPriTask を起動する．
 *          ノンプリエンプティブタスク NonPriTask にて最高優先度
 *          タスク HighPriorityTask を起動し，タスク終了する．
 *    'z' : GetTaskID にて自タスクのIDを取得する．
 *    'Z' : GetTaskState にてタスク状態を取得する．
 *  ・割込み管理機能
 *    'd' : DisableAllInterrupts を実行後，ハードウェアカウンタ値を
 *          3回表示し， EnableAllInterrupts を実行する．
 *    'D' : SuspendAllInterrupts を実行後，ハードウェアカウンタ値を
 *          3回表示し，さらに SuspendAllInterrupts を実行後、ハード
 *          ウェアカウンタ値を3回表示し，ResumeAllInterrupts を実行後、
 *          ハードウェアカウンタ値を3回表示し，ResumeAllInterrupts を
 *          実行する．
 *    'f' : SuspendOSInterrupts を実行後，ハードウェアカウンタ値を
 *          3回表示し，さらに SuspendOSInterrupts を実行後、ハード
 *          ウェアカウンタ値を3回表示し，さらに SuspendAllInterrupts
 *          を実行後，ハードウェアカウンタ値を3回表示し，
 *          ResumeAllInterrupts を実行後、ハードウェアカウンタを3回
 *          表示し，ResumeOSInterrupts を実行後ハードウェアカウンタ
 *          値を3回表示し，ResumeOSInterrupts を実行する．
 *    'T' : ハードウェアカウンタ値を3回表示する．
 *  ・リソース管理機能
 *    'k' : GetResource にてリソース TskLevelRes を取得する．なお，
 *          Task3 は、このリソースより優先度が高いためエラーとなる．
 *    'K' : ReleaseResource にてリソース TskLevelRes を解放する．
 *    'l' : GetResource にてスケジューラリソースを取得後，最高優先度
 *          タスク HighPriorityTask を起動し，ReleaseResource にて
 *          スケジューラリソースを解放する．
 *    'i' : GetResource にてリソース IntLevelRes を取得後，ハード
 *          ウェアカウンタ値を3回表示し，ReleaseResource にて
 *          リソース IntLevelRes を解放する．
 *  ・イベント制御機能
 *    'e' : SetEvent にてイベントを設定する．Task2 と Task3 以外は
 *          割り当てがないためエラーとなる．
 *    'w' : ClearEvent にて自タスクのイベントをクリアする．Task2 と
 *          Task3 以外は割り当てがないためエラーとなる．
 *    'E' : GetEvent にてイベント状態を取得する．Task2 と Task3
 *          以外は割り当てがないためエラーとなる．
 *    'W' : WaitEvent にて自タスクのイベントを待つ．Task3 と Task4
 *          以外はエラーとなる．
 *  ・アラーム機能
 *    'b' : GetAlarmBase にてアラーム MainCycArm のアラームベース
 *          情報を取得する．
 *    'B' : GetAlarm にてアラーム MainCycArm の残りカウント値を2回
 *          連続で取得する．
 *    'v' : SetRelAlarm にてアラーム ActTskArm を起動し，500ms 後に
 *          タスク Task1 を起動する．
 *    'V' : SetRelAlarm にてアラーム SetEvtArm を起動し，500ms 後に
 *          イベント T3Evt を設定する．
 *    'n' : SetRelAlarm にてアラーム CallBackArm を，パラメータ
 *          900ms 後に満了・単発アラーム指定で設定する．
 *    'N' : SetRelAlarm にてアラーム CallBackArm を，パラメータ
 *          900ms 後に満了・ 500ms 周期アラーム指定で設定する．
 *    'm' : SetAbsAlarm にてアラーム CallBackArm を，パラメータ
 *          カウンタ値900に満了・単発アラーム指定で設定する．
 *    'M' : SetAbsAlarm にてアラーム CallBackArm を，パラメータ
 *          カウンタ値900に満了・ 500ms 周期アラームで設定する．
 *    'h' : CancelAlarm にてアラーム CallBackArm をキャンセルする．
 *  ・カウンタ操作機能（OSEK仕様外）
 *    'c' : カウンタ通知用割込みを起動し，割込み内にて SignalCounter
 *          を実行し，カウンタ SampleCnt にシグナル通知する．
 *          1 シグナルでアラーム SampleArm が満了し，コールバックを
 *          実行する．
 *  ・OS実行制御機能
 *    'p' : GetActiveApplicationMode にてアプリケーションモードを
 *          取得する．
 *    'q' : ShutdownOS をコード E_OK で実行し，サンプルプログラムを
 *          終了する．
 *    'Q' : ShutdownOS をコード E_OS_STATE で実行し，サンプルプログラム
 *          を終了する．
 *  
 *  ＜オブジェクト一覧＞
 *  ・OS
 *    スタートアップフック：使用
 *    シャットダウンフック：使用
 *    エラーフック：使用
 *    プレタスクフック：未使用
 *    ポストタスクフック：未使用
 *    スケジューラリソース：使用
 *  ・タスク
 *  メインタスク
 *    タスクID：MainTask
 *    優先度：14
 *    多重起動数：1
 *    スケジュール：ノンプリエンプティブ
 *    自動起動：AppMode1, AppMode2, AppMode3
 *    概要：ユーザインタフェース（シリアルIOよりコマンドを受信し，
 *          それに対応した動作を行なう．）
 *          周期アラーム MainCycArm により，100msごとに待ち解除し
 *          コマンドの受信有無をポーリングする．
 *          イベント（ID：MainEvt）を関連付けている．
 *  最高優先度タスク
 *    タスクID：HighPriorityTask
 *    優先度：15
 *    多重起動数：1
 *    スケジュール：フルプリエンプティブ
 *    自動起動：なし
 *    概要：起動ログを出力して終了する．ノンプリエンプティブタスク
 *          から起動され，プリエンプトしているかどうかの確認用．
 *  ノンプリエンプティブタスク
 *    タスクID：NonPriTask
 *    優先度：1
 *    多重起動数：8
 *    スケジュール：ノンプリエンプティブ
 *    自動起動：なし
 *    概要：起動ログを出力し，最高優先度タスク HighPriorityTask を
 *          起動後，終了ログを出力してタスクを終了する．
 *  タスク1
 *    タスクID：Task1
 *    優先度：4
 *    スケジュール：フルプリエンプティブ
 *    自動起動：AppMode2
 *    多重起動数：8
 *    概要：並列処理タスク（メインタスクからの指令により動作）．
 *          起動されすると無限ループに入り，コマンド処理を実行する．
 *          リソース TskLevelRes を関連付けている．
 *          リソース IntLevelRes を関連付けている．
 *  タスク2
 *    タスクID：Task2
 *    優先度：7
 *    多重起動数：1
 *    スケジュール：フルプリエンプティブ
 *    自動起動：なし
 *    概要：並列処理タスク（メインタスクからの指令により動作）．
 *          起動されすると無限ループに入り，コマンド処理を実行する．
 *          リソース TskLevelRes を関連付けている．
 *          リソース IntLevelRes を関連付けている．
 *          イベント T2Evt を関連付けている．
 *  タスク3
 *    タスクID：Task3
 *    優先度：12
 *    多重起動数：1
 *    スケジュール：フルプリエンプティブ
 *    自動起動：AppMode3
 *    概要：並列処理タスク（メインタスクからの指令により動作）．
 *          起動されすると無限ループに入り，コマンド処理を実行する．
 *          イベント待ちすることが可能である．
 *          リソース IntLevelRes を関連付けている．
 *          イベント T3Evt を関連付けている．
 *  タスク4
 *    タスクID：Task4
 *    優先度：6
 *    多重起動数：5
 *    スケジュール：フルプリエンプティブ
 *    自動起動：なし
 *    概要：並列処理タスク（メインタスクからの指令により動作）．
 *          起動されすると無限ループに入り，コマンド処理を実行する．
 *          リソース TskLevelRes を関連付けている．
 *          リソース IntLevelRes を関連付けている．
 *          内部リソース GroupRes を関連付けている．
 *  タスク5
 *    タスクID：Task5
 *    優先度：9
 *    多重起動数：5
 *    スケジュール：フルプリエンプティブ
 *    自動起動：なし
 *    概要：並列処理タスク（メインタスクからの指令により動作）．
 *          起動されすると無限ループに入り，コマンド処理を実行する．
 *          リソース TskLevelRes を関連付けている．
 *          リソース IntLevelRes を関連付けている．
 *          内部リソース GroupRes を関連付けている．
 *  ・割込みサービスルーチン
 *  シリアルIO受信割込み
 *    ISRID：RxHwSerialInt
 *    優先度：6
 *    カテゴリ：1
 *    概要：コマンドを受信する．
 *  ハードウェアカウンタ1割込み
 *    ISRID：HwCnt1Int
 *    優先度：5
 *    カテゴリ：1
 *    概要：割込み禁止確認用カウンタ1を加算する．
 *  システムタイマ割込み
 *    ISRID：SysTimerInt
 *    優先度：4
 *    カテゴリ：2
 *    概要：SignalCounter(SysTimerCnt) を実行する．
 *  カウンタソース割込み
 *    ISRID：CounterInt
 *    優先度：3
 *    カテゴリ：2
 *    概要：SignalCounter(SampleCnt) を実行する．
 *  ハードウェアカウンタ2割込み
 *    ISRID：HwCnt1Int
 *    優先度：2
 *    カテゴリ：2
 *    概要：割込み禁止確認用カウンタ2を加算する．
 *          リソース（ID：IntLevelRes）を関連付けている．
 *  ・リソース
 *  タスクレベルリソース
 *    リソースID：TskLevelRes
 *    プロパティ：標準
 *  割込みレベルリソース
 *    リソースID：IntLevelRes
 *    プロパティ：標準
 *  タスクグループリソース
 *    リソースID：GroupRes
 *    プロパティ：内部
 *  ・イベント
 *  メインタスクイベント
 *    イベントID：MainEvt
 *  タスク2イベント
 *    イベントID：T2Evt
 *  タスク3イベント
 *    イベントID：T3Evt
 *  ・カウンタ
 *  システムタイマカウンタ
 *    カウンタID：SysTimerCnt
 *    カウント値：0〜999
 *    加算値：1
 *  サンプルカウンタ
 *    カウンタID：SampleCnt
 *    カウント値：0〜99
 *    加算値：10
 *  ・アラーム
 *  メイン周期アラーム
 *    アラームID：MainCycArm
 *    ベースカウンタID：SysTimerCnt
 *    アクション：イベント設定 MainEvt
 *    自動起動：AppMode1, AppMode2, AppMode3
 *    設定：カウンタ100，周期100
 *  タスク起動アラーム
 *    アラームID：ActTskArm
 *    ベースカウンタID：SysTimerCnt
 *    アクション：タスク起動 Task1
 *    自動起動：なし
 *  イベント設定アラーム
 *    アラームID：SetEvtArm
 *    ベースカウンタID：SysTimerCnt
 *    アクション：イベント設定 T3Evt
 *    自動起動：なし
 *  コールバック実行アラーム
 *    アラームID：CallBackArm
 *    ベースカウンタID：SysTimerCnt
 *    アクション：コールバック関数実行
 *    自動起動：なし
 *  SignalCounter確認用アラーム
 *    アラームID：SampleArm
 *    ベースカウンタID：SampleCnt
 *    アクション：コールバック関数実行
 *    自動起動：なし
 *  ・アプリケーションモード
 *  自動起動なしモード
 *    アプリケーションモードID：AppMode1
 *  Task1自動起動モード
 *    アプリケーションモードID：AppMode2
 *  Task3自動起動モード
 *    アプリケーションモードID：AppMode3
 *
 */

#include "kernel.h"
#include "sys_timer.h"
#include "serial.h"
#include "sample_config.h"
#include "kernel_id.h"
#include "sample1_com_ecc2.h"

/*
 *	内部関数プロトタイプ宣言
 */
int main( void );
TASK( MainTask );
TASK( HighPriorityTask );
TASK( NonPriTask );
TASK( Task1 );
TASK( Task2 );
TASK( Task3 );
TASK( Task4 );
TASK( Task5 );
ALARMCALLBACK( SysTimerAlmCb );
static void		TaskProk( UINT8 task_no );

static volatile UINT8 cur_task_no = 0;

/*
 *並列実行タスク数
 */
#define PARALLEL_TASK_NUM	5

/*
 *  内部データバッファ
 */
static volatile UINT8	command_tbl[8];	/* コマンド引渡しテーブル	*/

extern const UINT8	*task_name_tbl[];


/*
 *  ユーザメイン関数
 *
 *  アプリケーションモードの判断と，カーネル起動．
 */
int main( void )
{
	AppModeType	crt_app_mode;

	/*
	 *  アプリケーションモードの判断
	 */
	switch( GetAppModeInfo() ){
	case 0:
		crt_app_mode = AppMode1;
		break;
	case 1:
		crt_app_mode = AppMode2;
		break;
	default:
		crt_app_mode = AppMode3;
		break;
	}

	/*
	 *  カーネル起動
	 */
	StartOS( crt_app_mode );

	while( 1 );
}	/* main	*/


/*
 *  メインタスク
 *
 *  ユーザコマンドの受信と，コマンドごとの処理実行．
 */
TASK( MainTask )
{
	UINT8		command;
	UINT8		task_no;
	UINT8		echo[] = { " ¥r¥n" };
	UINT8		command_error[] = { "Not ASCII character¥r¥n" };
	UINT8		init_lpcnt;

	/*
	 *  タスク番号・コマンドバッファ初期化
	 */
	task_no = (UINT8)( 0 );

	for( init_lpcnt=0; init_lpcnt<PARALLEL_TASK_NUM; init_lpcnt++ ){
		command_tbl[init_lpcnt] = (UINT8)( 0 );
	}

	/*
	 *  コマンド実行ループ
	 */
	while( 1 ){
		WaitEvent( MainEvt );	/* 100msの作業時間待ち	*/
		ClearEvent( MainEvt );

		/*
		 *  入力コマンド取得
		 */
		RecvPolSerialChar( &command );	/* 受信バッファポーリング	*/

		/*
		 *  入力コマンドチェック
		 */
		if(command != 0 && 
			(( command <= (UINT8)( 0x1f ) ) || ( command >= (UINT8)( 0x80 ) ) )){
			PutSysLog( (const UINT8 *)command_error );
		}
		else{
			echo[0] = command;
			PutSysLog( (const UINT8 *)echo );

			/*
			 *  コマンド判別
			 */
			switch( command ){
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
				/*
				 *  処理対象タスクの変更
				 */
				task_no = (UINT8)( command - '1' );
				break;
			case 'A':
			case '!':
			case '"':
			case '#':
			case '$':
			case '%':
			case 'z':
			case 'k':
			case 'K':
			case 'l':
			case 'i':
			case 'w':
			case 'W':
				/*
				 *  タスクへのコマンド通知
				 */
				command_tbl[task_no] = command;
				break;
			case 0:
				command_tbl[cur_task_no] = 0xFF;
				break;
				/*
				 *  以降はメインタスクでコマンド処理
				 */
			case 'a':
				PutActTsk( task_no );
				break;
			case 's':
				PutSchedule();
				break;
			case 'S':
				PutActNonPriTsk();
				break;
			case 'Z':
				PutTaskState( task_no );
				break;
			case 'd':
				PutDisAllInt();
				break;
			case 'D':
				PutSusAllInt();
				break;
			case 'f':
				PutSusOSInt();
				break;
			case 'T':
				PutHwCnt3();
				break;
			case 'e':
				PutSetEvt( task_no );
				break;
			case 'E':
				PutGetEvt( task_no );
				break;
			case 'b':
				PutArmBase();
				break;
			case 'B':
				PutArmTick();
				PutArmTick();
				break;
			case 'v':
				/* SetRelAlarm( ActTskArm, 500, 0 );	*/
				PutSetRel(0, 0, 0);
				break;
			case 'V':
				/* SetRelAlarm( SetEvtArm, 500, 0 );	*/
				PutSetRel(1, 0, 0);
				break;
			case 'n':
				/* SetRelAlarm( CallBackArm, 900, 0 );	*/
				PutSetRel(2, 1, 0);
				break;
			case 'N':
				/* SetRelAlarm( CallBackArm, 900, 500 );	*/
				PutSetRel(2, 1, 1);
				break;
			case 'm':
				/* SetAbsAlarm( CallBackArm, 900, 0 );		*/
				PutSetAbs(2, 1, 0);
				break;
			case 'M':
				/* SetAbsAlarm( CallBackArm, 900, 500 );	*/
				PutSetAbs(2, 1, 1);
				break;
			case 'h':
				/* CancelAlarm( CallBackArm );				*/
				PutCanArm();
				break;
			case 'c':
				PutSysLog( (const UINT8 *)
							"Call SignalCounter(SampleCnt)¥r¥n" );
				ActCounterInt();
				break;
			case 'p':
				PutAppMode();
				break;
			case 'q':
				ShutdownOS( E_OK );
				break;
			case 'Q':
				ShutdownOS( E_OS_STATE );
				break;
			default:
				break;
			}
		}
	}

	/*
	 *  ここにはこない．
	 */
	PutSysLog( (const UINT8 *)"MainTask TERMINATE¥r¥n" );
	error_log( TerminateTask() );
}	/* TASK( MainTask )	*/


/*
 *  最高優先度タスク
 *
 *  各タスクのプリエンプト確認用．
 */
TASK( HighPriorityTask )
{
	PutSysLog( (const UINT8 *)"HighPriorityTask ACTIVATE¥r¥n" );

	error_log( TerminateTask() );
}	/* TASK( HighPriorityTask )	*/


/*
 *  ノンプリエンプティブタスク
 *
 *  実行中はプリエンプトしないことの確認用．
 */
TASK( NonPriTask )
{
	PutSysLog( (const UINT8 *)"NonPriTask ACTIVATE¥r¥n" );
	PutSysLog( (const UINT8 *)
				"Call ActivateTask(HighPriorityTask)¥r¥n" );
	error_log( ActivateTask( HighPriorityTask ) );
	PutSysLog( (const UINT8 *)"NonPriTask TERMINATE¥r¥n" );

	error_log( TerminateTask() );
}	/* TASK( NonPriTask )	*/


/*
 *  並列実行タスク1
 */
TASK( Task1 )
{
	TaskProk( 0 );
}	/* TASK( Task1 )	*/


/*
 *  並列実行タスク2
 */
TASK( Task2 )
{
	TaskProk( 1 );
}	/* TASK( Task2 )	*/


/*
 *  並列実行タスク3
 */
TASK( Task3 )
{
	TaskProk( 2 );
}	/* TASK( Task3 )	*/


/*
 *  並列実行タスク4
 */
TASK( Task4 )
{
	TaskProk( 3 );
}	/* TASK( Task4 )	*/


/*
 *  並列実行タスク5
 */
TASK( Task5 )
{
	TaskProk( 4 );
}	/* TASK( Task5 )	*/


/*
 *  並列実行タスク内部処理
 *
 *  メインタスクから通知されたコマンドごとの処理実行．
 */
static void
TaskProk( UINT8 task_no )
{
	UINT8		command;	/* コマンド退避バッファ	*/
	UINT8		count = 0;

	/*
	 *  タスク起動ログ出力
	 */
	PutSysLog( task_name_tbl[task_no] );
	PutSysLog( (const UINT8 *)" ACTIVATE¥r¥n" );

	/*
	 *  コマンド実行ループ
	 */
	while( 1 ){

		/*
		 *  コマンド取得
		 */
		while( command_tbl[task_no] == 0 ) {
			cur_task_no = task_no;
		}
		command = command_tbl[task_no];
		command_tbl[task_no] = 0;

		/*
		 *  コマンド判定
		 */
		switch( command ){
		case 'A':
			PutTermTsk( task_no );
			break;
		case '!':
		case '"':
		case '#':
		case '$':
		case '%':
			PutChainTsk( task_no, ( command - '!' ) );
			break;
		case 'z':
			PutTaskID();
			break;
		case 'k':
			PutGetTskRes();
			break;
		case 'K':
			PutRelTskRes();
			break;
		case 'l':
			PutGetSchedRes();
			break;
		case 'i':
			PutGetIntRes();
			break;
		case 'w':
			PutClrEvt( task_no );
			break;
		case 'W':
			PutWaitEvt( task_no );
			break;
		default:
			count ++;
			if (count >= 5) {
				PutSysLog( task_name_tbl[task_no] );
				PutSysLog( (const UINT8 *)" is running¥r¥n" );
				count = 0;
			}
			break;
		}
	}
}	/* TaskProk	*/



/*
 *  エラーフックルーチン
 */
#ifdef USE_ERRORHOOK
void ErrorHook( StatusType ercd )
{
	UINT8	str_buf[16];	/* ログ文字列生成バッファ	*/

	/*
	 *  エラーコードログ出力
	 */
	PutSysLog( (const UINT8 *)"Error:" );
	PutSysLog( ercd_tbl[ercd] );

	/*
	 *  エラー要因ごとのパラメータログ出力
	 */
	switch( OSErrorGetServiceId() ){
	case OSServiceId_ActivateTask:
		PutSysLog( (const UINT8 *)"=ActivateTask(" );
		ConvByte2DecStr( str_buf, OSError_ActivateTask_TaskID() );
		PutSysLog( (const UINT8 *)str_buf );
		break;
	case OSServiceId_TerminateTask:
		PutSysLog( (const UINT8 *)"=TerminateTask(" );
		break;
	case OSServiceId_ChainTask:
		PutSysLog( (const UINT8 *)"=ChainTask(" );
		ConvByte2DecStr( str_buf, OSError_ChainTask_TaskID() );
		PutSysLog( (const UINT8 *)str_buf );
		break;
	case OSServiceId_Schedule:
		PutSysLog( (const UINT8 *)"=Schedule(" );
		break;
	case OSServiceId_GetTaskID:
		PutSysLog( (const UINT8 *)"=GetTaskID(0x" );
		ConvLong2HexStr( str_buf, (UINT32)OSError_GetTaskID_TaskID() );
		PutSysLog( (const UINT8 *)str_buf );
		break;
	case OSServiceId_GetTaskState:
		PutSysLog( (const UINT8 *)"=GetTaskState(" );
		ConvByte2DecStr( str_buf, OSError_GetTaskState_TaskID() );
		PutSysLog( (const UINT8 *)str_buf );
		PutSysLog( (const UINT8 *)",0x" );
		ConvLong2HexStr( str_buf, (UINT32)OSError_GetTaskState_State() );
		PutSysLog( (const UINT8 *)str_buf );
		break;
	case OSServiceId_EnableAllInterrupts:
		PutSysLog( (const UINT8 *)"=EnableAllInterrupts(" );
		break;
	case OSServiceId_DisableAllInterrupts:
		PutSysLog( (const UINT8 *)"=DisableAllInterrupts(" );
		break;
	case OSServiceId_ResumeAllInterrupts:
		PutSysLog( (const UINT8 *)"=ResumeAllInterrupts(" );
		break;
	case OSServiceId_SuspendAllInterrupts:
		PutSysLog( (const UINT8 *)"=SuspendAllInterrupts(" );
		break;
	case OSServiceId_ResumeOSInterrupts:
		PutSysLog( (const UINT8 *)"=ResumeOSInterrupts(" );
		break;
	case OSServiceId_SuspendOSInterrupts:
		PutSysLog( (const UINT8 *)"=SuspendOSInterrupts(" );
		break;
	case OSServiceId_GetResource:
		PutSysLog( (const UINT8 *)"=GetResource(" );
		ConvByte2DecStr( str_buf, OSError_GetResource_ResID() );
		PutSysLog( (const UINT8 *)str_buf );
		break;
	case OSServiceId_ReleaseResource:
		PutSysLog( (const UINT8 *)"=ReleaseResource(" );
		ConvByte2DecStr( str_buf, OSError_ReleaseResource_ResID() );
		PutSysLog( (const UINT8 *)str_buf );
		break;
	case OSServiceId_SetEvent:
		PutSysLog( (const UINT8 *)"=SetEvent(" );
		ConvByte2DecStr( str_buf, OSError_SetEvent_TaskID() );
		PutSysLog( (const UINT8 *)str_buf );
		PutSysLog( (const UINT8 *)",0x" );
		ConvLong2HexStr( str_buf, OSError_SetEvent_Mask() );
		PutSysLog( (const UINT8 *)str_buf );
		break;
	case OSServiceId_ClearEvent:
		PutSysLog( (const UINT8 *)"=ClearEvent(0x" );
		ConvLong2HexStr( str_buf, OSError_ClearEvent_Mask() );
		PutSysLog( (const UINT8 *)str_buf );
		break;
	case OSServiceId_GetEvent:
		PutSysLog( (const UINT8 *)"=GetEvent(" );
		ConvByte2DecStr( str_buf, OSError_GetEvent_TaskID() );
		PutSysLog( (const UINT8 *)str_buf );
		PutSysLog( (const UINT8 *)",0x" );
		ConvLong2HexStr( str_buf, (UINT32)OSError_GetEvent_Mask() );
		PutSysLog( (const UINT8 *)str_buf );
		break;
	case OSServiceId_WaitEvent:
		PutSysLog( (const UINT8 *)"=WaitEvent(0x" );
		ConvLong2HexStr( str_buf, OSError_WaitEvent_Mask() );
		PutSysLog( (const UINT8 *)str_buf );
		break;
	case OSServiceId_GetAlarmBase:
		PutSysLog( (const UINT8 *)"=GetAlarmBase(" );
		ConvByte2DecStr( str_buf, OSError_GetAlarmBase_AlarmID() );
		PutSysLog( (const UINT8 *)str_buf );
		PutSysLog( (const UINT8 *)",0x" );
		ConvLong2HexStr( str_buf, (UINT32)OSError_GetAlarmBase_Info() );
		PutSysLog( (const UINT8 *)str_buf );
		break;
	case OSServiceId_GetAlarm:
		PutSysLog( (const UINT8 *)"=GetAlarm(" );
		ConvByte2DecStr( str_buf, OSError_GetAlarm_AlarmID() );
		PutSysLog( (const UINT8 *)str_buf );
		PutSysLog( (const UINT8 *)"," );
		ConvLong2DecStr( str_buf, (UINT32)OSError_GetAlarm_Tick() );
		PutSysLog( (const UINT8 *)str_buf );
		break;
	case OSServiceId_SetRelAlarm:
		PutSysLog( (const UINT8 *)"=SetRelAlarm(" );
		ConvByte2DecStr( str_buf, OSError_SetRelAlarm_AlarmID() );
		PutSysLog( (const UINT8 *)str_buf );
		PutSysLog( (const UINT8 *)"," );
		ConvLong2DecStr( str_buf, OSError_SetRelAlarm_increment() );
		PutSysLog( (const UINT8 *)str_buf );
		PutSysLog( (const UINT8 *)"," );
		ConvLong2DecStr( str_buf, OSError_SetRelAlarm_cycle() );
		PutSysLog( (const UINT8 *)str_buf );
		break;
	case OSServiceId_SetAbsAlarm:
		PutSysLog( (const UINT8 *)"=SetAbsAlarm(" );
		ConvByte2DecStr( str_buf, OSError_SetAbsAlarm_AlarmID() );
		PutSysLog( (const UINT8 *)str_buf );
		PutSysLog( (const UINT8 *)"," );
		ConvLong2DecStr( str_buf, OSError_SetAbsAlarm_start() );
		PutSysLog( (const UINT8 *)str_buf );
		PutSysLog( (const UINT8 *)"," );
		ConvLong2DecStr( str_buf, OSError_SetAbsAlarm_cycle() );
		PutSysLog( (const UINT8 *)str_buf );
		break;
	case OSServiceId_CancelAlarm:
		PutSysLog( (const UINT8 *)"=CancelAlarm(" );
		ConvByte2DecStr( str_buf, OSError_CancelAlarm_AlarmID() );
		PutSysLog( (const UINT8 *)str_buf );
		break;
	case OSServiceId_GetActiveApplicationMode:
		PutSysLog( (const UINT8 *)"=GetActiveApplicationMode(" );
		break;
	case OSServiceId_StartOS:
		PutSysLog( (const UINT8 *)"=StartOS(" );
		break;
	case OSServiceId_ShutdownOS:
		PutSysLog( (const UINT8 *)"=ShutdownOS(" );
		break;
	case OSServiceId_SignalCounter:
		PutSysLog( (const UINT8 *)"=SignalCounter(" );
		ConvByte2DecStr( str_buf, OSError_SignalCounter_CounterID() );
		PutSysLog( (const UINT8 *)str_buf );
		break;
	default:
		PutSysLog( (const UINT8 *)"=UnKnownFunc(" );
		break;
	}

	PutSysLog( (const UINT8 *)")¥r¥n" );
}	/* ErrorHook	*/
#endif /* USE_ERRORHOOK */

/*
 *  プレタスクフックルーチン
 *
 *  本サンプルでは未使用．
 */
#ifdef USE_PRETASKHOOK
void PreTaskHook( void )
{
}	/* PreTaskHook	*/
#endif /* USE_PRETASKHOOK */

/*
 *  ポストタスクフックルーチン
 *
 *  本サンプルでは未使用．
 */
#ifdef USE_POSTTASKHOOK
void PostTaskHook( void )
{
}	/* PostTaskHook	*/
#endif /* USE_POSTTASKHOOK */

/*
 *  スタートアップフックルーチン
 */
#ifdef USE_STARTUPHOOK
void StartupHook( void )
{
	InitSerial();		/* シリアルIOモジュール初期化		*/
	/* 起動ログ出力	*/
	PutIntSysLog( (const UINT8 *)
					"¥r¥nTOPPERS Automotive Kernel Release 1.0" );
#if defined( TARGET_NAME )
	PutIntSysLog( (const UINT8 *)" for " );
	PutIntSysLog( TARGET_NAME );
#endif	/* TARGET_NAME	*/
	PutIntSysLog( (const UINT8 *)
					"¥r¥nECC2 Sample System StartUp¥r¥n¥r¥n" );
	InitSysTimer();		/* システムタイマ起動				*/
	InitCounterInt();	/* SignalCounter実行用割込み初期化	*/
	InitHwCntInt();		/* 割込み検証用カウンタ起動			*/
}	/* StartupHook	*/
#endif /* USE_STARTUPHOOK */

/*
 *  シャットダウンフックルーチン
 */
#ifdef USE_SHUTDOWNHOOK
void ShutdownHook( StatusType ercd )
{
	TermHwCntInt();		/* 割込み検証用カウンタ停止			*/
	TermCounterInt();	/* SignalCounter実行用割込み停止	*/
	TermSysTimer();		/* システムタイマ停止				*/
	/* 終了ログ出力	*/
	PutIntSysLog( (const UINT8 *)
					"¥r¥nECC2 Sample System ShutDown¥r¥nShutDownCode:" );
	PutIntSysLog( ercd_tbl[ercd] );
	PutIntSysLog( (const UINT8 *)"¥r¥n¥r¥n" );
	TermSerial();		/* シリアルIOモジュール停止			*/
}	/* ShutdownHook	*/
#endif /* USE_SHUTDOWNHOOK */

/*
 *  システムタイマによるアラームコールバック
 */
ALARMCALLBACK( SysTimerAlmCb )
{
	/*
	 *  コールバック実行ログ出力
	 */
	PutSysLog( (const UINT8 *)"CallBackArm Expire¥r¥n" );
}	/* ALARMCALLBACK(SysTimerAlmCb)	*/

/*
 *  SignalCounter確認用アラームコールバック
 */
ALARMCALLBACK( SampleAlmCb )
{
	/*
	 *  コールバック実行ログ出力
	 */
	PutSysLog( (const UINT8 *)"SampleArm Expire¥r¥n" );
}	/* ALARMCALLBACK( SampleAlmCb )	*/


