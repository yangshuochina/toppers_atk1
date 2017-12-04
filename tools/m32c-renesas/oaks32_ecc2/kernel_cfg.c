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







/* �����ݓ���������O���Q�� */
ISR1_EXTERNAL(RxHwSerialInt);
ISR2_EXTERNAL(SysTimerInt);
ISR1_EXTERNAL(HwCnt1Int);
ISR2_EXTERNAL(CounterInt);
ISR2_EXTERNAL(HwCnt2Int);


/* �����ݓ��������	*/
ISR1_ENTRY(RxHwSerialInt);
ISR2_ENTRY(SysTimerInt,(0));
ISR1_ENTRY(HwCnt1Int);
ISR2_ENTRY(CounterInt,(1));
ISR2_ENTRY(HwCnt2Int,(2));


/* �x�N�^�e�[�u���o�^�V���{���O���Q��	*/
UNUSED_INT_EXTERNAL();	/* ����`�̊����� */
asm("	.glb	_start");	/* ���Z�b�g */

/* �����݉σx�N�^�e�[�u��	*/
asm("	.section vvector");

UNUSED_INT_SYMBOL(); /*  0, +0x00: BRK����	*/
UNUSED_INT_SYMBOL(); /*  1, +0x04: �\��̈�	*/
UNUSED_INT_SYMBOL(); /*  2, +0x08: �\��̈�	*/
UNUSED_INT_SYMBOL(); /*  3, +0x0C: �\��̈�	*/
UNUSED_INT_SYMBOL(); /*  4, +0x10: �\��̈�	*/
UNUSED_INT_SYMBOL(); /*  5, +0x14: �\��̈�	*/
UNUSED_INT_SYMBOL(); /*  6, +0x18: �\��̈�	*/
UNUSED_INT_SYMBOL(); /*  7, +0x1C: A/D�ϊ�1	*/
UNUSED_INT_SYMBOL(); /*  8, +0x20: DMA0	*/
UNUSED_INT_SYMBOL(); /*  9, +0x24: DMA1	*/
UNUSED_INT_SYMBOL(); /* 10, +0x28: DMA2	*/
UNUSED_INT_SYMBOL(); /* 11, +0x2C: DMA3	*/
ISR2_SYMBOL(SysTimerInt); /* 12, +0x30: �^�C�}A0	*/
ISR2_SYMBOL(CounterInt); /* 13, +0x34: �^�C�}A1	*/
UNUSED_INT_SYMBOL(); /* 14, +0x38: �^�C�}A2	*/
UNUSED_INT_SYMBOL(); /* 15, +0x3C: �^�C�}A3	*/
UNUSED_INT_SYMBOL(); /* 16, +0x40: �^�C�}A4	*/
UNUSED_INT_SYMBOL(); /* 17, +0x44: UART0���M,NACK	*/
UNUSED_INT_SYMBOL(); /* 18, +0x48: UART0��M,ACK	*/
UNUSED_INT_SYMBOL(); /* 19, +0x4C: UART1���M,NACK	*/
ISR1_SYMBOL(RxHwSerialInt); /* 20, +0x50: UART1��M,ACK	*/
ISR1_SYMBOL(HwCnt1Int); /* 21, +0x54: �^�C�}B0	*/
ISR2_SYMBOL(HwCnt2Int); /* 22, +0x58: �^�C�}B1	*/
UNUSED_INT_SYMBOL(); /* 23, +0x5C: �^�C�}B2	*/
UNUSED_INT_SYMBOL(); /* 24, +0x60: �^�C�}B3	*/
UNUSED_INT_SYMBOL(); /* 25, +0x64: �^�C�}B4	*/
UNUSED_INT_SYMBOL(); /* 26, +0x68: �O��������5	*/
UNUSED_INT_SYMBOL(); /* 27, +0x6C: �O��������4	*/
UNUSED_INT_SYMBOL(); /* 28, +0x70: �O��������3	*/
UNUSED_INT_SYMBOL(); /* 29, +0x74: �O��������2	*/
UNUSED_INT_SYMBOL(); /* 30, +0x78: �O��������1	*/
UNUSED_INT_SYMBOL(); /* 31, +0x7C: �O��������0	*/
UNUSED_INT_SYMBOL(); /* 32, +0x80: �^�C�}B5	*/
UNUSED_INT_SYMBOL(); /* 33, +0x84: UART2���M,NACK	*/
UNUSED_INT_SYMBOL(); /* 34, +0x88: UART2��M,ACK	*/
UNUSED_INT_SYMBOL(); /* 35, +0x8C: UART3���M,NACK	*/
UNUSED_INT_SYMBOL(); /* 36, +0x90: UART3��M,ACK	*/
UNUSED_INT_SYMBOL(); /* 37, +0x94: UART4���M,NACK	*/
UNUSED_INT_SYMBOL(); /* 38, +0x98: UART4��M,ACK	*/
UNUSED_INT_SYMBOL(); /* 39, +0x9C: �o�X�Փˌ��o/�X�^�[�g�R���f�B�V�������o/�X�g�b�v�R���f�B�V�������o(UART2)/��Q�G���[	*/
UNUSED_INT_SYMBOL(); /* 40, +0xA0: �o�X�Փˌ��o/�X�^�[�g�R���f�B�V�������o/�X�g�b�v�R���f�B�V�������o(UART3/UART0)/��Q�G���[	*/
UNUSED_INT_SYMBOL(); /* 41, +0xA4: �o�X�Փˌ��o/�X�^�[�g�R���f�B�V�������o/�X�g�b�v�R���f�B�V�������o(UART4/UART1)/��Q�G���[	*/
UNUSED_INT_SYMBOL(); /* 42, +0xA8: A/D�ϊ�0	*/
UNUSED_INT_SYMBOL(); /* 43, +0xAC: �L�[����	*/
UNUSED_INT_SYMBOL(); /* 44, +0xB0: �C���e���W�F���gI/O0	*/
UNUSED_INT_SYMBOL(); /* 45, +0xB4: �C���e���W�F���gI/O1	*/
UNUSED_INT_SYMBOL(); /* 46, +0xB8: �C���e���W�F���gI/O2	*/
UNUSED_INT_SYMBOL(); /* 47, +0xBC: �C���e���W�F���gI/O3	*/
UNUSED_INT_SYMBOL(); /* 48, +0xC0: �C���e���W�F���gI/O4	*/
UNUSED_INT_SYMBOL(); /* 49, +0xC4: �C���e���W�F���gI/O5	*/
UNUSED_INT_SYMBOL(); /* 50, +0xC8: �C���e���W�F���gI/O6	*/
UNUSED_INT_SYMBOL(); /* 51, +0xCC: �C���e���W�F���gI/O7	*/
UNUSED_INT_SYMBOL(); /* 52, +0xD0: �C���e���W�F���gI/O8	*/
UNUSED_INT_SYMBOL(); /* 53, +0xD4: �C���e���W�F���gI/O9/CAN0	*/
UNUSED_INT_SYMBOL(); /* 54, +0xD4: �C���e���W�F���gI/O10/CAN1	*/
UNUSED_INT_SYMBOL(); /* 55, +0xDC: �\��̈�	*/
UNUSED_INT_SYMBOL(); /* 56, +0xE0: �\��̈�	*/
UNUSED_INT_SYMBOL(); /* 57, +0xE8: �C���e���W�F���gI/O11/CAN2	*/
UNUSED_INT_SYMBOL(); /* 58, +0xE8: �\��̈�	*/
UNUSED_INT_SYMBOL(); /* 59, +0xEC: �\��̈�	*/
UNUSED_INT_SYMBOL(); /* 60, +0xF0: �\��̈�	*/
UNUSED_INT_SYMBOL(); /* 61, +0xF4: �\��̈�	*/
UNUSED_INT_SYMBOL(); /* 62, +0xF8: �\��̈�	*/
UNUSED_INT_SYMBOL(); /* 63, +0xFC: �\��̈�	*/

/* �����݌Œ�x�N�^�e�[�u��	*/
asm("	.section fvector");

UNUSED_INT_SYMBOL(); /* 64, 0xFFFFDC: ����`����	*/
UNUSED_INT_SYMBOL(); /* 65, 0xFFFFE0: �I�[�o�[�t���[	*/
UNUSED_INT_SYMBOL(); /* 66, 0xFFFFE4: BRK����	*/
UNUSED_INT_SYMBOL(); /* 67, 0xFFFFE8: �A�h���X��v	*/
UNUSED_INT_SYMBOL(); /* 68, 0xFFFFEC: �\��̈�	*/
UNUSED_INT_SYMBOL(); /* 69, 0xFFFFF0: �Ď��^�C�}/���U��~���o	*/
UNUSED_INT_SYMBOL(); /* 70, 0xFFFFF4: �\��̈�	*/
UNUSED_INT_SYMBOL(); /* 71, 0xFFFFF8: NMI	*/
asm("	.lword	_start"); /* 72, 0xFFFFFC: ���Z�b�g	*/

/* �t�b�N���[�`��	*/



NULL_PRETASKHOOK
NULL_POSTTASKHOOK




