/*
 *  kernel_cfg.c
 *  Fri Nov 14 09:01:21 2008
 *  SG Version 2.10
 *  sg.exe -cfg=kernel_cfg.c -template=../../../../config¥sh2e-renesas¥sh2e_7058f.sgt -I ../../../../sg¥impl_oil -odep=kernel_support.src -os=ECC2 D:¥toppers_automotive_kernel¥tools¥sh2e-renesas¥sample¥SG¥sample1.oil
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

static __STK_UNIT _stack_MainTask[__TCOUNT_STK_UNIT(1024)];
static __STK_UNIT _stack_Task2[__TCOUNT_STK_UNIT(256)];
static __STK_UNIT _stack_Task3[__TCOUNT_STK_UNIT(256)];
static __STK_UNIT _stack_HighPriorityTask[__TCOUNT_STK_UNIT(192)];
static __STK_UNIT _stack_Task1[__TCOUNT_STK_UNIT(256)];
static __STK_UNIT _stack_Task4[__TCOUNT_STK_UNIT(256)];
static __STK_UNIT _stack_Task5[__TCOUNT_STK_UNIT(256)];
static __STK_UNIT _stack_priority_1[__TCOUNT_STK_UNIT(256)];

const Priority tinib_inipri[TNUM_TASK] = { TPRI_MINTASK + 14, TPRI_MINTASK + 7, TPRI_MINTASK + 12, TPRI_MINTASK + 15, TPRI_MINTASK + 1, TPRI_MINTASK + 4, TPRI_MINTASK + 6, TPRI_MINTASK + 9, };
const Priority tinib_exepri[TNUM_TASK] = { TPRI_MAXTASK, TPRI_MINTASK + 7, TPRI_MINTASK + 12, TPRI_MINTASK + 15, TPRI_MAXTASK, TPRI_MINTASK + 4, TPRI_MINTASK + 9, TPRI_MINTASK + 9, };
const UINT8 tinib_maxact[TNUM_TASK] = { (1) - 1, (1) - 1, (1) - 1, (1) - 1, (8) - 1, (8) - 1, (5) - 1, (5) - 1, };
const AppModeType tinib_autoact[TNUM_TASK] = { 0x00000007, 0x00000000, 0x00000004, 0x00000000, 0x00000000, 0x00000002, 0x00000000, 0x00000000, };
const FP tinib_task[TNUM_TASK] = { TASKNAME( MainTask ), TASKNAME( Task2 ), TASKNAME( Task3 ), TASKNAME( HighPriorityTask ), TASKNAME( NonPriTask ), TASKNAME( Task1 ), TASKNAME( Task4 ), TASKNAME( Task5 ), };
const __STK_UNIT tinib_stk[TNUM_TASK] = { (__STK_UNIT)_stack_MainTask, (__STK_UNIT)_stack_Task2, (__STK_UNIT)_stack_Task3, (__STK_UNIT)_stack_HighPriorityTask, (__STK_UNIT)_stack_priority_1, (__STK_UNIT)_stack_Task1, (__STK_UNIT)_stack_Task4, (__STK_UNIT)_stack_Task5, };
const UINT16 tinib_stksz[TNUM_TASK] = { 1024, 256, 256, 192, 256, 256, 256, 256, };

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


