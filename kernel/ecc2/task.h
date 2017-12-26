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
 *	Task management module (ECC 2)
 */

#ifndef _TASK_H_
#define _TASK_H_

/*
 *  Definition of special value of task ID
 */
#define TSKID_NULL		((TaskType) UINT8_INVALID)	/* Invalid ID */

/*
 *  Definition of task state (tcb_stat) value
 */
#define TS_RUNNABLE		READY				/* Execution state, executable state */
#define TS_DORMANT		SUSPENDED			/* Suspended state */
#define TS_WAITING		WAITING				/* waiting state */

/*
 *  Declaration of variables holding the number of tasks（kernel_cfg.c）
 */
extern const UINT8	tnum_task;		    /* Number of tasks */
extern const UINT8	tnum_exttask;		/* Number of extended tasks */

/*
 *  Task initialization block（kernel_cfg.c）
 */
extern const Priority	tinib_inipri[];		/* Initial priority */
extern const Priority	tinib_exepri[];		/* Priority at start of execution */
extern const UINT8		tinib_maxact[];		/* Maximum number of multiple activation requests */
extern const AppModeType tinib_autoact[];	/* Starting mode */
extern const FP			tinib_task[];		/* Task activation number */
extern const VP			tinib_stk[];		/* Start address of stack area */
extern const UINT16		tinib_stksz[];		/* Size of stack area */

/*
 * Task management block（kernel_cfg.c）
 *
 * In addition to this, an array for storing a task context is defined
 * as a target dependency.
 */
extern TaskType			tcb_next[];			/* Task queue */
extern UINT8			tcb_tstat[];		/* Task state */
extern Priority			tcb_curpri[];		/* Current priority */
extern UINT8			tcb_actcnt[];		/* Multiple activation request number */
extern EventMaskType	tcb_curevt[];		/* Current event */
extern EventMaskType	tcb_waievt[];		/* Waiting event */
extern ResourceType		tcb_lastres[];		/* Lastly acquired resources */

/*
 * Execution task
 *
 * If there is no task in the execution state, set it to TSKID_NULL.
 */
extern TaskType			runtsk;

/*
 *  Highest priority task
 *
 * During task execution, it matches runtsk. If there is no task in the executable state
 * (execution state or executable state), set TSKID_NULL.
 */
extern TaskType			schedtsk;

/*
 *  Highest priority in ready queue
 *
 *  レディキューには実行可能状態のタスクのみを含むので，実行可能状態の
 *  タスクの中出の最高優先度を保持する．レディキューが空の時（実行可能
 *  状態のタスクが無い時）は TPRI_MINTASK（＝0）にする．
 */
extern Priority			nextpri;

/*
 *  Initialization of task management module
 */
extern void	task_initialize(void);

/*
 *  Activate task
 *
 * Activate the target task (task specified by tskid) (Transition from suspend state
 * to executable state Initialize necessary task at startup.
 */
extern BOOL	make_active(TaskType tskid);

/*
 *  Transition to executable state
 *
 *  対象タスク（tskid で指定したタスク）を実行できる状態に遷移させる．
 *  対象タスクの優先度が，最高優先度タスク（schedtsk）の優先度よりも高
 *  い場合には，対象タスクを新しい最高優先度タスクとし，それまでの最高
 *  優先度タスクをレディキューの先頭に入れる．そうでない場合には，対象
 *  タスクをレディキューの末尾に入れる．対象タスクを最高優先度タスクと
 *  した場合に，TRUE を返す．
 */
extern BOOL	make_runnable(TaskType tskid);

/*
 *  最高優先順位タスクのサーチ
 *
 *  レディキュー中で最も優先順位の高いタスクをサーチし，それをレディ
 *  キューから外して，最高優先順位タスク（schedtsk）とする．実際には，
 *  レディキュー中の最高優先度が nextpri に設定されているためにサーチ
 *  は必要なく，優先度 nextpri のレディキューの先頭のタスクを最高優先
 *  順位タスクとする．レディキューのサーチは，そのタスクをレディキュー
 *  から外した後に nextpri を更新するために必要となる．このサーチに，
 *  ready_primap を用いる．
 *  この関数は，それまで実行状態であったタスクが待ち状態か休止状態に移
 *  行した時に，次に実行すべきタスクを選ぶために呼び出す．よってこの関
 *  数では，それまでの最高優先度タスクは無視する．
 */
extern void	search_schedtsk(void);

/*
 *  タスクのプリエンプト
 *
 *  自タスクを実行可能状態に移行させ，最高優先度タスクを実行状態にする．
 *  この関数から戻った後に，dispatch を呼び出して他のタスクへ切り替える
 *  ことを想定している．
 */
extern void	preempt(void);

#endif /* _TASK_H_ */
