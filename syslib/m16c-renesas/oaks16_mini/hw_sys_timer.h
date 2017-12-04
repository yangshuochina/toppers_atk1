/*
 *  TOPPERS Automotive Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 *      Automotive Kernel
 * 
 *  Copyright (C) 2000-2002 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2003 by TOPPERS Project Educational Group.
 *  Copyright (C) 2004-2006 by Witz Corporation, JAPAN
 * 
 *  上記著作権者は，Free Software Foundation によって公表されている 
 *  GNU General Public License の Version 2 に記述されている条件か，以
 *  下の(1)〜(4)の条件を満たす場合に限り，本ソフトウェア（本ソフトウェ
 *  アを改変したものを含む．以下同じ）を使用・複製・改変・再配布（以下，
 *  利用と呼ぶ）することを無償で許諾する．
 *  (1) 本ソフトウェアをソースコードの形で利用する場合には，上記の著作
 *      権表示，この利用条件および下記の無保証規定が，そのままの形でソー
 *      スコード中に含まれていること．
 *  (2) 本ソフトウェアを再利用可能なバイナリコード（リロケータブルオブ
 *      ジェクトファイルやライブラリなど）の形で利用する場合には，利用
 *      に伴うドキュメント（利用者マニュアルなど）に，上記の著作権表示，
 *      この利用条件および下記の無保証規定を掲載すること．
 *  (3) 本ソフトウェアを再利用不可能なバイナリコードの形または機器に組
 *      み込んだ形で利用する場合には，次のいずれかの条件を満たすこと．
 *    (a) 利用に伴うドキュメント（利用者マニュアルなど）に，上記の著作
 *        権表示，この利用条件および下記の無保証規定を掲載すること．
 *    (b) 利用の形態を，別に定める方法によって，上記著作権者に報告する
 *        こと．
 *  (4) 本ソフトウェアの利用により直接的または間接的に生じるいかなる損
 *      害からも，上記著作権者を免責すること．
 * 
 *  本ソフトウェアは，無保証で提供されているものである．上記著作権者は，
 *  本ソフトウェアに関して，その適用可能性も含めて，いかなる保証も行わ
 *  ない．また，本ソフトウェアの利用により直接的または間接的に生じたい
 *  かなる損害に関しても，その責任を負わない．
 * 
 */

/*
 *	ターゲット依存タイマモジュール（OAKS16-mini）
 */

#ifndef _HW_SYS_TIMER_H_
#define _HW_SYS_TIMER_H_

#include	"kernel.h"
#include	"sfrm16c26.h"


/*
 *  システムタイマの割込みレベル定義
 */
#define CFG_INTLVL_SYSCLK	(UINT8)0x04	/* システムクロック用タイマ */

/*
 *  システムタイマのコンペア値（1ms）
 */
#define	CFG_SYSCLK			(UINT16)(625u)


#ifndef _MACRO_ONLY
/*
 *  システムタイマの起動処理関数プロトタイプ宣言
 */
extern void InitHwSysTimer( void );

/*
 *  システムタイマの停止処理関数プロトタイプ宣言
 */
extern void TermHwSysTimer( void );

/*
 *  システムタイマの割込み要求クリア処理関数プロトタイプ宣言
 */
Inline void	ClearHwSysTimerInt( void );

/*
 *  システムタイマの割込み要求クリア処理
 *
 *  割込み発生時に自動的にクリアされるが，割込み以外から
 *  実行されることも想定し，下記処理を実装する．
 */
Inline void
ClearHwSysTimerInt( void )
{
	IR_TA0IC = 0;						/* 割込み要求クリア				*/
}	/* ClearHwSysTimerInt	*/

#endif /* _MACRO_ONLY */

#endif /* _HW_SYS_TIMER_H_ */
