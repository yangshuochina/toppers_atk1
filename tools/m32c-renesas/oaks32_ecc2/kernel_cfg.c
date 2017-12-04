/*
 *  kernel_cfg.c
 *  Fri Oct 31 14:54:27 2008
 *  SG Version 2.10
 *  sg.exe sample1_ecc2.oil -template=..\..\..\config\m32c-renesas\oaks32\m32c83.sgt -I..\..\..\sg\impl_oil -I..\..\..\syslib -I..\..\..\syslib\m32c-renesas\oaks32 -os=ECC2
 */
#include "osek_kernel.h"
#include "kernel_id.h"
#include "alarm.h"
#include "interrupt.h"
#include "resource.h"
#include "task.h"

#define __STK_UNIT VP
#define __TCOUNT_STK_UNIT(sz) (((sz) + sizeof(__STK_UNIT) - 1) / sizeof(__STK_UNIT))

#define TNUM_ALARM     5
#define TNUM_COUNTER   2
#define TNUM_ISR2      3
#define TNUM_RESOURCE  4
#define TNUM_TASK      8
#define TNUM_EXTTASK   3

const UINT8 tnum_alarm    = TNUM_ALARM;
const UINT8 tnum_counter  = TNUM_COUNTER;
const UINT8 tnum_isr2     = TNUM_ISR2;
const UINT8 tnum_resource = TNUM_RESOURCE;
const UINT8 tnum_task     = TNUM_TASK;
const UINT8 tnum_exttask  = TNUM_EXTTASK;

 /****** Object OS ******/

 /****** Object TASK ******/

const TaskType MainTask = 0;
const TaskType Task2 = 1;
const TaskType Task3 = 2;
const TaskType HighPriorityTask = 3;
const TaskType NonPriTask = 4;
const TaskType Task1 = 5;
const TaskType Task4 = 6;
const TaskType Task5 = 7;

extern void TASKNAME( MainTask )( void );
extern void TASKNAME( Task2 )( void );
extern void TASKNAME( Task3 )( void );
extern void TASKNAME( HighPriorityTask )( void );
extern void TASKNAME( NonPriTask )( void );
extern void TASKNAME( Task1 )( void );
extern void TASKNAME( Task4 )( void );
extern void TASKNAME( Task5 )( void );

static __STK_UNIT _stack_MainTask[__TCOUNT_STK_UNIT(384)];
static __STK_UNIT _stack_Task2[__TCOUNT_STK_UNIT(256)];
static __STK_UNIT _stack_Task3[__TCOUNT_STK_UNIT(256)];
static __STK_UNIT _stack_HighPriorityTask[__TCOUNT_STK_UNIT(192)];
static __STK_UNIT _stack_Task1[__TCOUNT_STK_UNIT(256)];
static __STK_UNIT _stack_Task4[__TCOUNT_STK_UNIT(256)];
static __STK_UNIT _stack_Task5[__TCOUNT_STK_UNIT(256)];
static __STK_UNIT _stack_priority_1[__TCOUNT_STK_UNIT(192)];

const Priority tinib_inipri[TNUM_TASK] = { TPRI_MINTASK + 14, TPRI_MINTASK + 7, TPRI_MINTASK + 12, TPRI_MINTASK + 15, TPRI_MINTASK + 1, TPRI_MINTASK + 4, TPRI_MINTASK + 6, TPRI_MINTASK + 9, };
const Priority tinib_exepri[TNUM_TASK] = { TPRI_MAXTASK, TPRI_MINTASK + 7, TPRI_MINTASK + 12, TPRI_MINTASK + 15, TPRI_MAXTASK, TPRI_MINTASK + 4, TPRI_MINTASK + 9, TPRI_MINTASK + 9, };
const UINT8 tinib_maxact[TNUM_TASK] = { (1) - 1, (1) - 1, (1) - 1, (1) - 1, (8) - 1, (8) - 1, (5) - 1, (5) - 1, };
const AppModeType tinib_autoact[TNUM_TASK] = { 0x00000007, 0x00000000, 0x00000004, 0x00000000, 0x00000000, 0x00000002, 0x00000000, 0x00000000, };
const FP tinib_task[TNUM_TASK] = { TASKNAME( MainTask ), TASKNAME( Task2 ), TASKNAME( Task3 ), TASKNAME( HighPriorityTask ), TASKNAME( NonPriTask ), TASKNAME( Task1 ), TASKNAME( Task4 ), TASKNAME( Task5 ), };
const __STK_UNIT tinib_stk[TNUM_TASK] = { (__STK_UNIT)_stack_MainTask, (__STK_UNIT)_stack_Task2, (__STK_UNIT)_stack_Task3, (__STK_UNIT)_stack_HighPriorityTask, (__STK_UNIT)_stack_priority_1, (__STK_UNIT)_stack_Task1, (__STK_UNIT)_stack_Task4, (__STK_UNIT)_stack_Task5, };
const UINT16 tinib_stksz[TNUM_TASK] = { 384, 256, 256, 192, 192, 256, 256, 256, };

UINT8 tcb_tstat[TNUM_TASK];
Priority tcb_curpri[TNUM_TASK];
DEFINE_CTXB(TNUM_TASK);
TaskType tcb_next[TNUM_TASK];
EventMaskType tcb_curevt[TNUM_EXTTASK];
EventMaskType tcb_waievt[TNUM_EXTTASK];
UINT8 tcb_actcnt[TNUM_TASK];
ResourceType tcb_lastres[TNUM_TASK];

 /****** Object COUNTER ******/

const CounterType SysTimerCnt = 0;
const CounterType SampleCnt = 1;

const TickType cntinib_maxval[TNUM_COUNTER] = { 999, 99, };
const TickType cntinib_maxval2[TNUM_COUNTER] = { 1999, 199, };
const TickType cntinib_tickbase[TNUM_COUNTER] = { 1, 10, };
const TickType cntinib_mincyc[TNUM_COUNTER] = { 1, 10, };

AlarmType cntcb_almque[TNUM_COUNTER];
TickType cntcb_curval[TNUM_COUNTER];

 /****** Object ALARM ******/

const AlarmType MainCycArm = 0;
const AlarmType ActTskArm = 1;
const AlarmType SetEvtArm = 2;
const AlarmType CallBackArm = 3;
const AlarmType SampleArm = 4;

DeclareTask(MainTask);
DeclareEvent(MainEvt);
static void _setevent_alarm_MainCycArm( void );
static void _setevent_alarm_MainCycArm( void )
{ (void)SetEvent( MainTask, MainEvt ); }

DeclareTask(Task1);
static void _activate_alarm_ActTskArm( void );
static void _activate_alarm_ActTskArm( void )
{ (void)ActivateTask( Task1 ); }

DeclareTask(Task3);
DeclareEvent(T3Evt);
static void _setevent_alarm_SetEvtArm( void );
static void _setevent_alarm_SetEvtArm( void )
{ (void)SetEvent( Task3, T3Evt ); }

extern void ALARMCALLBACKNAME( SysTimerAlmCb )(void);

extern void ALARMCALLBACKNAME( SampleAlmCb )(void);

const CounterType alminib_cntid[TNUM_ALARM] = { 0, 0, 0, 0, 1, };
const FP alminib_cback[TNUM_ALARM] = { _setevent_alarm_MainCycArm, _activate_alarm_ActTskArm, _setevent_alarm_SetEvtArm, ALARMCALLBACKNAME( SysTimerAlmCb ), ALARMCALLBACKNAME( SampleAlmCb ), };
const AppModeType alminib_autosta[TNUM_ALARM] = { 0x00000007, 0x00000000, 0x00000000, 0x00000000, 0x00000007, };
const TickType alminib_almval[TNUM_ALARM] = { 100, 0, 0, 0, 10, };
const TickType alminib_cycle[TNUM_ALARM] = { 100, 0, 0, 0, 10, };

AlarmType almcb_next[TNUM_ALARM];
AlarmType almcb_prev[TNUM_ALARM];
TickType almcb_almval[TNUM_ALARM];
TickType almcb_cycle[TNUM_ALARM];

 /****** Object RESOURCE ******/

const ResourceType TskLevelRes = 1;
const ResourceType IntLevelRes = 2;
const ResourceType GroupRes = 3;

const Priority resinib_ceilpri[TNUM_RESOURCE] = { TPRI_SCHEDULER, TPRI_MINTASK + 9, TPRI_MINISR + 2, TPRI_MINTASK + 9, };

Priority rescb_prevpri[TNUM_RESOURCE];
ResourceType rescb_prevres[TNUM_RESOURCE];

 /****** Object EVENT ******/

const EventMaskType MainEvt = (1UL << 0);
const EventMaskType T2Evt = (1UL << 1);
const EventMaskType T3Evt = (1UL << 2);

 /****** Object ISR ******/

const IsrType SysTimerInt = 0;
const IsrType CounterInt = 1;
const IsrType HwCnt2Int = 2;

#define IPL_MAXISR2 4
const IPL ipl_maxisr2 = IPL_MAXISR2;


const Priority isrinib_intpri[TNUM_ISR2] = { TPRI_MINISR + (4), TPRI_MINISR + (3), TPRI_MINISR + (2), };
ResourceType isrcb_lastres[TNUM_ISR2];

 /****** Object APPMODE ******/

void object_initialize( void )
{
	alarm_initialize();
	interrupt_initialize();
	resource_initialize();
	task_initialize();
}

/*
 *  TOPPERS Automotive Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Automotive Kernel
 * 
 *  Copyright (C) 2006 by Witz Corporation, JAPAN
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







/* 割込み入り口処理外部参照 */
ISR1_EXTERNAL(RxHwSerialInt);
ISR2_EXTERNAL(SysTimerInt);
ISR1_EXTERNAL(HwCnt1Int);
ISR2_EXTERNAL(CounterInt);
ISR2_EXTERNAL(HwCnt2Int);


/* 割込み入り口処理	*/
ISR1_ENTRY(RxHwSerialInt);
ISR2_ENTRY(SysTimerInt,(0));
ISR1_ENTRY(HwCnt1Int);
ISR2_ENTRY(CounterInt,(1));
ISR2_ENTRY(HwCnt2Int,(2));


/* ベクタテーブル登録シンボル外部参照	*/
UNUSED_INT_EXTERNAL();	/* 未定義の割込み */
asm("	.glb	_start");	/* リセット */

/* 割込み可変ベクタテーブル	*/
asm("	.section vvector");

UNUSED_INT_SYMBOL(); /*  0, +0x00: BRK命令	*/
UNUSED_INT_SYMBOL(); /*  1, +0x04: 予約領域	*/
UNUSED_INT_SYMBOL(); /*  2, +0x08: 予約領域	*/
UNUSED_INT_SYMBOL(); /*  3, +0x0C: 予約領域	*/
UNUSED_INT_SYMBOL(); /*  4, +0x10: 予約領域	*/
UNUSED_INT_SYMBOL(); /*  5, +0x14: 予約領域	*/
UNUSED_INT_SYMBOL(); /*  6, +0x18: 予約領域	*/
UNUSED_INT_SYMBOL(); /*  7, +0x1C: A/D変換1	*/
UNUSED_INT_SYMBOL(); /*  8, +0x20: DMA0	*/
UNUSED_INT_SYMBOL(); /*  9, +0x24: DMA1	*/
UNUSED_INT_SYMBOL(); /* 10, +0x28: DMA2	*/
UNUSED_INT_SYMBOL(); /* 11, +0x2C: DMA3	*/
ISR2_SYMBOL(SysTimerInt); /* 12, +0x30: タイマA0	*/
ISR2_SYMBOL(CounterInt); /* 13, +0x34: タイマA1	*/
UNUSED_INT_SYMBOL(); /* 14, +0x38: タイマA2	*/
UNUSED_INT_SYMBOL(); /* 15, +0x3C: タイマA3	*/
UNUSED_INT_SYMBOL(); /* 16, +0x40: タイマA4	*/
UNUSED_INT_SYMBOL(); /* 17, +0x44: UART0送信,NACK	*/
UNUSED_INT_SYMBOL(); /* 18, +0x48: UART0受信,ACK	*/
UNUSED_INT_SYMBOL(); /* 19, +0x4C: UART1送信,NACK	*/
ISR1_SYMBOL(RxHwSerialInt); /* 20, +0x50: UART1受信,ACK	*/
ISR1_SYMBOL(HwCnt1Int); /* 21, +0x54: タイマB0	*/
ISR2_SYMBOL(HwCnt2Int); /* 22, +0x58: タイマB1	*/
UNUSED_INT_SYMBOL(); /* 23, +0x5C: タイマB2	*/
UNUSED_INT_SYMBOL(); /* 24, +0x60: タイマB3	*/
UNUSED_INT_SYMBOL(); /* 25, +0x64: タイマB4	*/
UNUSED_INT_SYMBOL(); /* 26, +0x68: 外部割込み5	*/
UNUSED_INT_SYMBOL(); /* 27, +0x6C: 外部割込み4	*/
UNUSED_INT_SYMBOL(); /* 28, +0x70: 外部割込み3	*/
UNUSED_INT_SYMBOL(); /* 29, +0x74: 外部割込み2	*/
UNUSED_INT_SYMBOL(); /* 30, +0x78: 外部割込み1	*/
UNUSED_INT_SYMBOL(); /* 31, +0x7C: 外部割込み0	*/
UNUSED_INT_SYMBOL(); /* 32, +0x80: タイマB5	*/
UNUSED_INT_SYMBOL(); /* 33, +0x84: UART2送信,NACK	*/
UNUSED_INT_SYMBOL(); /* 34, +0x88: UART2受信,ACK	*/
UNUSED_INT_SYMBOL(); /* 35, +0x8C: UART3送信,NACK	*/
UNUSED_INT_SYMBOL(); /* 36, +0x90: UART3受信,ACK	*/
UNUSED_INT_SYMBOL(); /* 37, +0x94: UART4送信,NACK	*/
UNUSED_INT_SYMBOL(); /* 38, +0x98: UART4受信,ACK	*/
UNUSED_INT_SYMBOL(); /* 39, +0x9C: バス衝突検出/スタートコンディション検出/ストップコンディション検出(UART2)/障害エラー	*/
UNUSED_INT_SYMBOL(); /* 40, +0xA0: バス衝突検出/スタートコンディション検出/ストップコンディション検出(UART3/UART0)/障害エラー	*/
UNUSED_INT_SYMBOL(); /* 41, +0xA4: バス衝突検出/スタートコンディション検出/ストップコンディション検出(UART4/UART1)/障害エラー	*/
UNUSED_INT_SYMBOL(); /* 42, +0xA8: A/D変換0	*/
UNUSED_INT_SYMBOL(); /* 43, +0xAC: キー入力	*/
UNUSED_INT_SYMBOL(); /* 44, +0xB0: インテリジェントI/O0	*/
UNUSED_INT_SYMBOL(); /* 45, +0xB4: インテリジェントI/O1	*/
UNUSED_INT_SYMBOL(); /* 46, +0xB8: インテリジェントI/O2	*/
UNUSED_INT_SYMBOL(); /* 47, +0xBC: インテリジェントI/O3	*/
UNUSED_INT_SYMBOL(); /* 48, +0xC0: インテリジェントI/O4	*/
UNUSED_INT_SYMBOL(); /* 49, +0xC4: インテリジェントI/O5	*/
UNUSED_INT_SYMBOL(); /* 50, +0xC8: インテリジェントI/O6	*/
UNUSED_INT_SYMBOL(); /* 51, +0xCC: インテリジェントI/O7	*/
UNUSED_INT_SYMBOL(); /* 52, +0xD0: インテリジェントI/O8	*/
UNUSED_INT_SYMBOL(); /* 53, +0xD4: インテリジェントI/O9/CAN0	*/
UNUSED_INT_SYMBOL(); /* 54, +0xD4: インテリジェントI/O10/CAN1	*/
UNUSED_INT_SYMBOL(); /* 55, +0xDC: 予約領域	*/
UNUSED_INT_SYMBOL(); /* 56, +0xE0: 予約領域	*/
UNUSED_INT_SYMBOL(); /* 57, +0xE8: インテリジェントI/O11/CAN2	*/
UNUSED_INT_SYMBOL(); /* 58, +0xE8: 予約領域	*/
UNUSED_INT_SYMBOL(); /* 59, +0xEC: 予約領域	*/
UNUSED_INT_SYMBOL(); /* 60, +0xF0: 予約領域	*/
UNUSED_INT_SYMBOL(); /* 61, +0xF4: 予約領域	*/
UNUSED_INT_SYMBOL(); /* 62, +0xF8: 予約領域	*/
UNUSED_INT_SYMBOL(); /* 63, +0xFC: 予約領域	*/

/* 割込み固定ベクタテーブル	*/
asm("	.section fvector");

UNUSED_INT_SYMBOL(); /* 64, 0xFFFFDC: 未定義命令	*/
UNUSED_INT_SYMBOL(); /* 65, 0xFFFFE0: オーバーフロー	*/
UNUSED_INT_SYMBOL(); /* 66, 0xFFFFE4: BRK命令	*/
UNUSED_INT_SYMBOL(); /* 67, 0xFFFFE8: アドレス一致	*/
UNUSED_INT_SYMBOL(); /* 68, 0xFFFFEC: 予約領域	*/
UNUSED_INT_SYMBOL(); /* 69, 0xFFFFF0: 監視タイマ/発振停止検出	*/
UNUSED_INT_SYMBOL(); /* 70, 0xFFFFF4: 予約領域	*/
UNUSED_INT_SYMBOL(); /* 71, 0xFFFFF8: NMI	*/
asm("	.lword	_start"); /* 72, 0xFFFFFC: リセット	*/

/* フックルーチン	*/



NULL_PRETASKHOOK
NULL_POSTTASKHOOK




