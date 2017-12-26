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

/*
 *  サンプルプログラム(1) ECC2の本体
 *
 *  TOPPERS Automotive Kernelの基本的な動作を確認するためのサンプルプログラム．
 *
 *  Outline of the program：Serial communication is performed between PC and board,
 *  and operation and log output are performed according to user input command.
 *
 *  ＜Command list＞
 *  ・Task designation
 *    '1' : The following commands are executed for Task 1.
 *    '2' : The following commands are executed for Task 2.
 *    '3' : The following commands are executed for Task 3.
 *    '4' : The following commands are executed for Task 4.
 *    '5' : The following commands are executed for Task 5.
 *  ・Task management function
 *    'a' : Activate the task with ActivateTask.
 *    'A' : Terminate the task with TerminateTask.
 *    '!'(Shift+1) : End the task with ChainTask and activate Task1.
 *    '"'(Shift+2) : End the task with ChainTask and activate Task2.
 *    '#'(Shift+3) : End the task with ChainTask and activate Task3.
 *    '$'(Shift+4) : End the task with ChainTask and activate Task4.
 *    '%'(Shift+5) : End the task with ChainTask and activate Task5.
 *    's' : Activate the highest priority task HighPriorityTask in task MainTask
 *          which is a nonpreemptive attribute, and reschedule with Schedule.
 *    'S' : Start non-preemptive task NonPriTask.
 *          Non-preemptive task NonPriTask has the highest priority
 *          Activate the task HighPriorityTask and finish the task.
 *    'z' : Get the ID of the invoking task with GetTaskID.
 *    'Z' : Get the task state with GetTaskState.
 *  ・Interrupt management function
 *    'd' : After executing DisableAllInterrupts,  display the hardware
 *          counter value three times and execute EnableAllInterrupts.
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
 *    'T' : Display the hardware counter value three times.
 *  ・Resource management function
 *    'k' : Get Resource TskLevelRes with GetResource.
 *          Since Task3 has a higher priority than this resource, it becomes an error.
 *    'K' : Release Resource TskLevelRes with ReleaseResource.
 *    'l' : After obtaining the scheduler resource with GetResource,
 *          activate the highest priority task HighPriorityTask and
 *          release the scheduler resource with ReleaseResource.
 *    'i' : After getting the resource IntLevelRes with GetResource,
 *          display the hardware counter value three times and release
 *          the resource IntLevelRes with ReleaseResource.
 *  ・Event control function
 *    'e' : Set events with SetEvent.
 *          Since there is no assignment except Task2 and Task3, an error occurs.
 *    'w' : ClearEvent clears the event of the invoking task.
 *          Since there is no assignment except for Task2 and Task3, an error occurs.
 *    'E' : Get event state with GetEvent.
 *          Since there is no assignment except for Task2 and Task3, an error occurs.
 *    'W' : WaitEvent waits for the event of the invoking task.
 *          An error occurs except Task 3 and Task 4.
 *  ・Alarm function
 *    'b' : Get alarm base information of alarm MainCycArm with GetAlarmBase.
 *    'B' : Acquire the remaining count value of alarm MainCycArm twice in GetAlarm continuously.
 *    'v' : Activate alarm ActTskArm with SetRelAlarm, and start task Task 1 500 ms later.
 *    'V' : Set alarm SetEvtArm with SetRelAlarm and set event T3Evt 500 ms later.
 *    'n' : Set alarm CallBackArm with SetRelAlarm, expire after parameter 900 ms · Specify single-shot alarm.
 *    'N' : Set alarm CallBackArm with SetRelAlarm, expire after parameter 900 ms · Set 500 ms cycle alarm.
 *    'm' : Set alarm CallBackArm with SetAbsAlarm, expire to parameter counter value 900, and specify single-shot alarm.
 *    'M' : Set alarm CallBackArm with SetAbsAlarm, expire to parameter counter value 900 · Set with 500 ms period alarm.
 *    'h' : Cancel Alarm Cancel CallBackArm with Alarm.
 *  ・Counter operation function (outside OSEK specification)
 *    'c' : カウンタ通知用割込みを起動し，割込み内にて SignalCounter
 *          を実行し，カウンタ SampleCnt にシグナル通知する．
 *          1 シグナルでアラーム SampleArm が満了し，コールバックを
 *          実行する．
 *  ・OS execution control function
 *    'p' : Get the application mode with GetActiveApplicationMode.
 *    'q' : Execute ShutdownOS with code E_OK and exit the sample program.
 *    'Q' : Execute ShutdownOS with code E_OS_STATE and exit the sample program.
 *
 *  ＜Object list＞
 *  ・OS
 *    Startup hook: use
 *    Shutdown hook: use
 *    Error hook: used
 *    Pre-task hook: unused
 *    Post-task hook: unused
 *    Scheduler resource: used
 *  ・task
 *  Main task
 *    Task ID：MainTask
 *    Priority：14
 *    Multiple activation number：1
 *    Schedule: Non preemptive
 *    Auto start：AppMode1, AppMode2, AppMode3
 *    Overview：User interface (Receives command from serial IO and
 *              performs corresponding operation.)
 *              By the cycle alarm MainCycArm, wait is canceled every 100 ms
 *              Polls whether or not a command is received.
 *              Event (ID: MainEvt) is associated.
 *  Highest priority task
 *    Task ID：HighPriorityTask
 *    Priority：15
 *    Multiple activation number：1
 *    Schedule: full preemptive
 *    Auto start：None
 *    Overview：Output the startup log and exit. It is started from non-preemptive
 *              task and is used to check whether it is preempted.
 *  Non preemptive task
 *    Task ID：NonPriTask
 *    Priority：1
 *    Multiple activation number：8
 *    Schedule: Non preemptive
 *    Auto start：None
 *    Overview：After outputting the startup log, activate the highest priority task
 *              HighPriorityTask, output an end log and end the task.
 *  Task1
 *    Task ID：Task1
 *    Priority: 4
 *    Schedule: full preemptive
 *    Auto start: AppMode2
 *    Multiple activation number: 8
 *    Overview：Parallel processing task (operated by command from main task).
 *              When activated, it enters an infinite loop and executes command processing.
 *              Resource TskLevelRes is associated.
 *              Resource IntLevelRes is associated.
 *  Task2
 *    Task ID：Task2
 *    Priority: 7
 *    Multiple activation number: 1
 *    Schedule: full preemptive
 *    Auto start: None
 *    Overview：Parallel processing task (operated by command from main task).
 *              When activated, it enters an infinite loop and executes command processing.
 *              Resource TskLevelRes is associated.
 *              Resource IntLevelRes is associated.
 *              And associates event T2Evt.
 *  Task3
 *    Task ID：Task3
 *    Priority: 12
 *    Multiple activation number: 1
 *    Schedule: full preemptive
 *    Auto start: AppMode3
 *    Overview：Parallel processing task (operated by command from main task).
 *              When activated, it enters an infinite loop and executes command processing.
 *              It is possible to wait for an event.
 *              Resource IntLevelRes is associated.
 *              And associates event T3Evt.
 *  Task4
 *    Task ID：Task4
 *    Priority: 6
 *    Multiple activation number: 5
 *    Schedule: full preemptive
 *    Auto start: None
 *    Overview：Parallel processing task (operated by command from main task).
 *              When activated, it enters an infinite loop and executes command processing.
 *              Resource TskLevelRes is associated.
 *              Resource IntLevelRes is associated.
 *              Associates an internal resource GroupRes.
 *  Task5
 *    Task ID：Task5
 *    Priority: 9
 *    Multiple activation number: 5
 *    Schedule: full preemptive
 *    Auto start: None
 *    Overview：Parallel processing task (operated by command from main task).
 *              When activated, it enters an infinite loop and executes command processing.
 *              Resource TskLevelRes is associated.
 *              Resource IntLevelRes is associated.
 *              Associates an internal resource GroupRes.
 *  ・Interrupt service routine
 *  Serial IO receive interrupt
 *    ISRID：RxHwSerialInt
 *    Priority: 6
 *    Category：1
 *    Overview：Receives the command.
 *  Hardware counter 1 interrupt
 *    ISRID：HwCnt1Int
 *    Priority: 5
 *    Category：1
 *    Overview：And adds the interrupt prohibition confirmation counter 1.
 *  System timer interrupt
 *    ISRID：SysTimerInt
 *    Priority: 4
 *    Category：2
 *    Overview：Execute SignalCounter (SysTimerCnt).
 *  Counter source interrupt
 *    ISRID：CounterInt
 *    Priority: 3
 *    Category：2
 *    Overview：Execute SignalCounter (SampleCnt).
 *  Hardware Counter 2 Interrupt
 *    ISRID：HwCnt1Int
 *    Priority: 2
 *    Category：2
 *    Overview：And adds the interrupt prohibition confirmation counter 2.
 *          Resource (ID: IntLevelRes) is associated.
 *  ・Resource
 *  Task level resources
 *    Resource ID：TskLevelRes
 *    Property: Standard
 *  Interrupt level resource
 *    Resource ID：IntLevelRes
 *    Property: Standard
 *  Task group resource
 *    Resource ID：GroupRes
 *    Property: Internal
 *  ・Event
 *  Main task event
 *    Event ID: MainEvt
 *  Task 2 event
 *    Event ID：T2Evt
 *  Task 3 event
 *    Event ID：T3Evt
 *  ・Counter
 *  System timer counter
 *    Counter ID：SysTimerCnt
 *    Count value：0～999
 *    Addition value：1
 *  Sample counter
 *    Counter ID：SampleCnt
 *    Count value：0～99
 *    Addition value：10
 *  ・Alarm
 *  Main cycle alarm
 *    Alarm ID：MainCycArm
 *    Base counter ID：SysTimerCnt
 *    Action: Event setting MainEvt
 *    Auto start: AppMode1, AppMode2, AppMode3
 *    Setting: Counter 100, Period 100
 *  Task activation alarm
 *    Alarm ID：ActTskArm
 *    Base counter ID：SysTimerCnt
 *    Action: Task activation Task1
 *    Auto start: None
 *  Event setting alarm
 *    Alarm ID：SetEvtArm
 *    Base counter ID：SysTimerCnt
 *    Action: Event setting T3Evt
 *    Auto start: None
 *  Callback execution alarm
 *    Alarm ID：CallBackArm
 *    Base counter ID：SysTimerCnt
 *    Action: Execute callback function
 *    Auto start: None
 *  SignalCounter confirmation alarm
 *    Alarm ID：SampleArm
 *    Base counter ID：SampleCnt
 *    Action: Execute callback function
 *    Auto start: None
 *  ・Application mode
 *  No automatic start mode
 *    Application mode ID：AppMode1
 *  Task1 Auto start mode
 *    Application mode ID：AppMode2
 *  Task3 Auto start mode
 *    Application mode ID：AppMode3
 *
 */

#include "kernel.h"
#include "sys_timer.h"
#include "serial.h"
#include "sample_config.h"
#include "kernel_id.h"
#include "sample1_com_ecc2.h"

/*
 *	Internal function prototype declaration
 */
int main(void);
TASK(MainTask);
TASK(HighPriorityTask);
TASK(NonPriTask);
TASK(Task1);
TASK(Task2);
TASK(Task3);
TASK(Task4);
TASK(Task5);
ALARMCALLBACK(SysTimerAlmCb);
static void		TaskProk(UINT8 task_no);

static volatile UINT8 cur_task_no = 0;

/*
 * Number of parallel execution tasks
 */
#define PARALLEL_TASK_NUM	5

/*
 *  Internal data buffer
 */
static volatile UINT8	command_tbl[8];	/* Command delivery table */

extern const UINT8	*task_name_tbl[];

/*
 *  User Main Function
 *
 *  Judgment of application mode and kernel activation.
 */
int main(void)
{
    AppModeType	crt_app_mode;

    /*
     *  Judgment of application mode
     */
    switch (GetAppModeInfo()) {
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
     *  Start the kernel
     */
    StartOS(crt_app_mode);

    while (1);
}	/* main	*/

/*
 *  Main task
 *
 *  Receive user commands and execute processing for each command.
 */
TASK(MainTask)
{
    UINT8		command;
    UINT8		task_no;
    UINT8		echo[] ={ " \r\n" };
    UINT8		command_error[] ={ "Not ASCII character\r\n" };
    UINT8		init_lpcnt;

    /*
     *  Task number · command buffer initialization
     */
    task_no = (UINT8)(0);

    for (init_lpcnt=0; init_lpcnt < PARALLEL_TASK_NUM; init_lpcnt++) {
        command_tbl[init_lpcnt] = (UINT8)(0);
    }

    /*
     *  Command execution loop
     */
    while (1) {
        WaitEvent(MainEvt);	/* Waiting for 100 ms working time	*/
        ClearEvent(MainEvt);

        /*
         *  Acquire input command
         */
        RecvPolSerialChar(&command);	/* Receive buffer polling	*/

        /*
         *  Input command check
         */
        if (command != 0 &&
            ((command <= (UINT8)(0x1f)) || (command >= (UINT8)(0x80)))) {
            PutSysLog((const UINT8 *)command_error);
        }
        else {
            echo[0] = command;
            PutSysLog((const UINT8 *)echo);

            /*
             *  Command determination
             */
            switch (command) {
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
                /*
                 *  Change task to be processed
                 */
                task_no = (UINT8)(command - '1');
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
                 *  Command notification to task
                 */
                command_tbl[task_no] = command;
                break;
            case 0:
                command_tbl[cur_task_no] = 0xFF;
                break;
                /*
                 *  Command processing in the main task after that
                 */
            case 'a':
                PutActTsk(task_no);
                break;
            case 's':
                PutSchedule();
                break;
            case 'S':
                PutActNonPriTsk();
                break;
            case 'Z':
                PutTaskState(task_no);
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
                PutSetEvt(task_no);
                break;
            case 'E':
                PutGetEvt(task_no);
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
                PutSysLog((const UINT8 *)
                    "Call SignalCounter(SampleCnt)\r\n");
                ActCounterInt();
                break;
            case 'p':
                PutAppMode();
                break;
            case 'q':
                ShutdownOS(E_OK);
                break;
            case 'Q':
                ShutdownOS(E_OS_STATE);
                break;
            default:
                break;
            }
        }
    }

    /*
     *  ここにはこない．
     */
    PutSysLog((const UINT8 *)"MainTask TERMINATE\r\n");
    error_log(TerminateTask());
}	/* TASK( MainTask )	*/

/*
 *  Highest priority task
 *
 *  For confirming preemption of each task.
 */
TASK(HighPriorityTask)
{
    PutSysLog((const UINT8 *)"HighPriorityTask ACTIVATE\r\n");

    error_log(TerminateTask());
}	/* TASK( HighPriorityTask )	*/

/*
 *  Non preemptive task
 *
 *  For confirmation that it does not preempt during execution.
 */
TASK(NonPriTask)
{
    PutSysLog((const UINT8 *)"NonPriTask ACTIVATE\r\n");
    PutSysLog((const UINT8 *)
        "Call ActivateTask(HighPriorityTask)\r\n");
    error_log(ActivateTask(HighPriorityTask));
    PutSysLog((const UINT8 *)"NonPriTask TERMINATE\r\n");

    error_log(TerminateTask());
}	/* TASK( NonPriTask )	*/

/*
 *  Parallel execution task 1
 */
TASK(Task1)
{
    TaskProk(0);
}	/* TASK( Task1 )	*/

/*
 *  Parallel execution task 2
 */
TASK(Task2)
{
    TaskProk(1);
}	/* TASK( Task2 )	*/

/*
 *  Parallel execution task 3
 */
TASK(Task3)
{
    TaskProk(2);
}	/* TASK( Task3 )	*/

/*
 *  Parallel execution task 4
 */
TASK(Task4)
{
    TaskProk(3);
}	/* TASK( Task4 )	*/

/*
 *  Parallel execution task 5
 */
TASK(Task5)
{
    TaskProk(4);
}	/* TASK( Task5 )	*/

/*
 *  Parallel execution task internal processing
 *
 *  Execution of processing for each command notified from the main task.
 */
static void
TaskProk(UINT8 task_no)
{
    UINT8		command;	/* Command save buffer	*/
    UINT8		count = 0;

    /*
     *  Task activation log output
     */
    PutSysLog(task_name_tbl[task_no]);
    PutSysLog((const UINT8 *)" ACTIVATE\r\n");

    /*
     *  Command execution loop
     */
    while (1) {
        /*
         *  Command acquisition
         */
        while (command_tbl[task_no] == 0) {
            cur_task_no = task_no;
        }
        command = command_tbl[task_no];
        command_tbl[task_no] = 0;

        /*
         *  Command determination
         */
        switch (command) {
        case 'A':
            PutTermTsk(task_no);
            break;
        case '!':
        case '"':
        case '#':
        case '$':
        case '%':
            PutChainTsk(task_no, (command - '!'));
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
            PutClrEvt(task_no);
            break;
        case 'W':
            PutWaitEvt(task_no);
            break;
        default:
            count++;
            if (count >= 5) {
                PutSysLog(task_name_tbl[task_no]);
                PutSysLog((const UINT8 *)" is running\r\n");
                count = 0;
            }
            break;
        }
    }
}	/* TaskProk	*/

/*
 *  Error hook routine
 */
#ifdef USE_ERRORHOOK
void ErrorHook(StatusType ercd)
{
    UINT8	str_buf[16];	/* Log string generation buffer	*/

    /*
     *  Error code log output
     */
    PutSysLog((const UINT8 *)"Error:");
    PutSysLog(ercd_tbl[ercd]);

    /*
     *  Parameter log output for each error cause
     */
    switch (OSErrorGetServiceId()) {
    case OSServiceId_ActivateTask:
        PutSysLog((const UINT8 *)"=ActivateTask(");
        ConvByte2DecStr(str_buf, OSError_ActivateTask_TaskID());
        PutSysLog((const UINT8 *)str_buf);
        break;
    case OSServiceId_TerminateTask:
        PutSysLog((const UINT8 *)"=TerminateTask(");
        break;
    case OSServiceId_ChainTask:
        PutSysLog((const UINT8 *)"=ChainTask(");
        ConvByte2DecStr(str_buf, OSError_ChainTask_TaskID());
        PutSysLog((const UINT8 *)str_buf);
        break;
    case OSServiceId_Schedule:
        PutSysLog((const UINT8 *)"=Schedule(");
        break;
    case OSServiceId_GetTaskID:
        PutSysLog((const UINT8 *)"=GetTaskID(0x");
        ConvLong2HexStr(str_buf, (UINT32)OSError_GetTaskID_TaskID());
        PutSysLog((const UINT8 *)str_buf);
        break;
    case OSServiceId_GetTaskState:
        PutSysLog((const UINT8 *)"=GetTaskState(");
        ConvByte2DecStr(str_buf, OSError_GetTaskState_TaskID());
        PutSysLog((const UINT8 *)str_buf);
        PutSysLog((const UINT8 *)",0x");
        ConvLong2HexStr(str_buf, (UINT32)OSError_GetTaskState_State());
        PutSysLog((const UINT8 *)str_buf);
        break;
    case OSServiceId_EnableAllInterrupts:
        PutSysLog((const UINT8 *)"=EnableAllInterrupts(");
        break;
    case OSServiceId_DisableAllInterrupts:
        PutSysLog((const UINT8 *)"=DisableAllInterrupts(");
        break;
    case OSServiceId_ResumeAllInterrupts:
        PutSysLog((const UINT8 *)"=ResumeAllInterrupts(");
        break;
    case OSServiceId_SuspendAllInterrupts:
        PutSysLog((const UINT8 *)"=SuspendAllInterrupts(");
        break;
    case OSServiceId_ResumeOSInterrupts:
        PutSysLog((const UINT8 *)"=ResumeOSInterrupts(");
        break;
    case OSServiceId_SuspendOSInterrupts:
        PutSysLog((const UINT8 *)"=SuspendOSInterrupts(");
        break;
    case OSServiceId_GetResource:
        PutSysLog((const UINT8 *)"=GetResource(");
        ConvByte2DecStr(str_buf, OSError_GetResource_ResID());
        PutSysLog((const UINT8 *)str_buf);
        break;
    case OSServiceId_ReleaseResource:
        PutSysLog((const UINT8 *)"=ReleaseResource(");
        ConvByte2DecStr(str_buf, OSError_ReleaseResource_ResID());
        PutSysLog((const UINT8 *)str_buf);
        break;
    case OSServiceId_SetEvent:
        PutSysLog((const UINT8 *)"=SetEvent(");
        ConvByte2DecStr(str_buf, OSError_SetEvent_TaskID());
        PutSysLog((const UINT8 *)str_buf);
        PutSysLog((const UINT8 *)",0x");
        ConvLong2HexStr(str_buf, OSError_SetEvent_Mask());
        PutSysLog((const UINT8 *)str_buf);
        break;
    case OSServiceId_ClearEvent:
        PutSysLog((const UINT8 *)"=ClearEvent(0x");
        ConvLong2HexStr(str_buf, OSError_ClearEvent_Mask());
        PutSysLog((const UINT8 *)str_buf);
        break;
    case OSServiceId_GetEvent:
        PutSysLog((const UINT8 *)"=GetEvent(");
        ConvByte2DecStr(str_buf, OSError_GetEvent_TaskID());
        PutSysLog((const UINT8 *)str_buf);
        PutSysLog((const UINT8 *)",0x");
        ConvLong2HexStr(str_buf, (UINT32)OSError_GetEvent_Mask());
        PutSysLog((const UINT8 *)str_buf);
        break;
    case OSServiceId_WaitEvent:
        PutSysLog((const UINT8 *)"=WaitEvent(0x");
        ConvLong2HexStr(str_buf, OSError_WaitEvent_Mask());
        PutSysLog((const UINT8 *)str_buf);
        break;
    case OSServiceId_GetAlarmBase:
        PutSysLog((const UINT8 *)"=GetAlarmBase(");
        ConvByte2DecStr(str_buf, OSError_GetAlarmBase_AlarmID());
        PutSysLog((const UINT8 *)str_buf);
        PutSysLog((const UINT8 *)",0x");
        ConvLong2HexStr(str_buf, (UINT32)OSError_GetAlarmBase_Info());
        PutSysLog((const UINT8 *)str_buf);
        break;
    case OSServiceId_GetAlarm:
        PutSysLog((const UINT8 *)"=GetAlarm(");
        ConvByte2DecStr(str_buf, OSError_GetAlarm_AlarmID());
        PutSysLog((const UINT8 *)str_buf);
        PutSysLog((const UINT8 *)",");
        ConvLong2DecStr(str_buf, (UINT32)OSError_GetAlarm_Tick());
        PutSysLog((const UINT8 *)str_buf);
        break;
    case OSServiceId_SetRelAlarm:
        PutSysLog((const UINT8 *)"=SetRelAlarm(");
        ConvByte2DecStr(str_buf, OSError_SetRelAlarm_AlarmID());
        PutSysLog((const UINT8 *)str_buf);
        PutSysLog((const UINT8 *)",");
        ConvLong2DecStr(str_buf, OSError_SetRelAlarm_increment());
        PutSysLog((const UINT8 *)str_buf);
        PutSysLog((const UINT8 *)",");
        ConvLong2DecStr(str_buf, OSError_SetRelAlarm_cycle());
        PutSysLog((const UINT8 *)str_buf);
        break;
    case OSServiceId_SetAbsAlarm:
        PutSysLog((const UINT8 *)"=SetAbsAlarm(");
        ConvByte2DecStr(str_buf, OSError_SetAbsAlarm_AlarmID());
        PutSysLog((const UINT8 *)str_buf);
        PutSysLog((const UINT8 *)",");
        ConvLong2DecStr(str_buf, OSError_SetAbsAlarm_start());
        PutSysLog((const UINT8 *)str_buf);
        PutSysLog((const UINT8 *)",");
        ConvLong2DecStr(str_buf, OSError_SetAbsAlarm_cycle());
        PutSysLog((const UINT8 *)str_buf);
        break;
    case OSServiceId_CancelAlarm:
        PutSysLog((const UINT8 *)"=CancelAlarm(");
        ConvByte2DecStr(str_buf, OSError_CancelAlarm_AlarmID());
        PutSysLog((const UINT8 *)str_buf);
        break;
    case OSServiceId_GetActiveApplicationMode:
        PutSysLog((const UINT8 *)"=GetActiveApplicationMode(");
        break;
    case OSServiceId_StartOS:
        PutSysLog((const UINT8 *)"=StartOS(");
        break;
    case OSServiceId_ShutdownOS:
        PutSysLog((const UINT8 *)"=ShutdownOS(");
        break;
    case OSServiceId_SignalCounter:
        PutSysLog((const UINT8 *)"=SignalCounter(");
        ConvByte2DecStr(str_buf, OSError_SignalCounter_CounterID());
        PutSysLog((const UINT8 *)str_buf);
        break;
    default:
        PutSysLog((const UINT8 *)"=UnKnownFunc(");
        break;
    }

    PutSysLog((const UINT8 *)")\r\n");
}	/* ErrorHook	*/
#endif /* USE_ERRORHOOK */

/*
 *  プレタスクフックルーチン
 *
 *  本サンプルでは未使用．
 */
#ifdef USE_PRETASKHOOK
void PreTaskHook(void)
{
}	/* PreTaskHook	*/
#endif /* USE_PRETASKHOOK */

/*
 *  ポストタスクフックルーチン
 *
 *  本サンプルでは未使用．
 */
#ifdef USE_POSTTASKHOOK
void PostTaskHook(void)
{
}	/* PostTaskHook	*/
#endif /* USE_POSTTASKHOOK */

/*
 *  スタートアップフックルーチン
 */
#ifdef USE_STARTUPHOOK
void StartupHook(void)
{
    InitSerial();		/* Serial IO module initialization */
    /* Startup log output	*/
    PutIntSysLog((const UINT8 *)
        "\r\nTOPPERS Automotive Kernel Release 1.0");
#if defined( TARGET_NAME )
    PutIntSysLog((const UINT8 *)" for ");
    PutIntSysLog(TARGET_NAME);
#endif	/* TARGET_NAME	*/
    PutIntSysLog((const UINT8 *)
        "\r\nECC2 Sample System StartUp\r\n\r\n");
    InitSysTimer();		/* System timer activation				*/
    InitCounterInt();	/* Interrupt initialization for executing SignalCounter	*/
    InitHwCntInt();		/* 割込み検証用カウンタ起動			*/
}	/* StartupHook	*/
#endif /* USE_STARTUPHOOK */

/*
 *  シャットダウンフックルーチン
 */
#ifdef USE_SHUTDOWNHOOK
void ShutdownHook(StatusType ercd)
{
    TermHwCntInt();		/* 割込み検証用カウンタ停止			*/
    TermCounterInt();	/* SignalCounter実行用割込み停止	*/
    TermSysTimer();		/* システムタイマ停止				*/
    /* 終了ログ出力	*/
    PutIntSysLog((const UINT8 *)
        "\r\nECC2 Sample System ShutDown\r\nShutDownCode:");
    PutIntSysLog(ercd_tbl[ercd]);
    PutIntSysLog((const UINT8 *)"\r\n\r\n");
    TermSerial();		/* シリアルIOモジュール停止			*/
}	/* ShutdownHook	*/
#endif /* USE_SHUTDOWNHOOK */

/*
 *  システムタイマによるアラームコールバック
 */
ALARMCALLBACK(SysTimerAlmCb)
{
    /*
     *  コールバック実行ログ出力
     */
    PutSysLog((const UINT8 *)"CallBackArm Expire\r\n");
}	/* ALARMCALLBACK(SysTimerAlmCb)	*/

/*
 *  SignalCounter確認用アラームコールバック
 */
ALARMCALLBACK(SampleAlmCb)
{
    /*
     *  コールバック実行ログ出力
     */
    PutSysLog((const UINT8 *)"SampleArm Expire\r\n");
}	/* ALARMCALLBACK( SampleAlmCb )	*/