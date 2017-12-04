/*
 *  TOPPERS Automotive Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Automotive Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2003 by Naoki Saito
 *             Nagoya Municipal Industrial Research Institute, JAPAN
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
 *	サンプル向けターゲット依存システムタイマモジュール（OAKS32用）
 */

#if !defined( _HW_SYS_TIMER_H_ )
#define _HW_SYS_TIMER_H_


#include	"kernel.h"
#include	"sfrm32c83.h"


/*
 *  システムタイマの割込みレベル定義
 */
#define CFG_INTLVL_SYSCLK	(UINT8)( 0x04 )

/*
 *  システムタイマのコンペア値（1ms）
 */
#define	CFG_SYSCLK		(UINT16)( 30000 )

#if !defined( _MACRO_ONLY )
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
	IR_TA0IC = 0;	/* 割込み要求クリア	*/
}	/* ClearHwSysTimerInt	*/

#endif /* _MACRO_ONLY */


#endif /* _HW_SYS_TIMER_H_ */

