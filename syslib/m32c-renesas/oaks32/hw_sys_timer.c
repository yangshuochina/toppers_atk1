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


#include	"hw_sys_timer.h"


/*
 *  システムタイマの起動処理
 *
 *  割込み禁止状態で呼出すこと．
 */
void
InitHwSysTimer( void )
{
	/*
	 *  タイマを停止して各レジスタ設定
	 */
	TA0S = 0;	/* カウント停止	*/

	/*
	 *  タイマA0ダウンカウント, タイマモード, カウントソースf1
	 */
	TA0UD = (UINT8)( 0 );
	TA0MR = (UINT8)( 0 );

	/*
	 *  ハードウェア仕様にてタイマソースのレジスタ設定値+1分周するため,
	 *  レジスタ設定値はシステムクロック周期に相当するカウント数から
	 *  マイナス1する値を設定する.（設定値はヘッダ参照）
	 */
	TA0 = CFG_SYSCLK - (UINT16)( 1 );

	/*
	 *  タイマコンペア割込みレベル設定（設定レベルはヘッダ参照）
	 *  TA0IC の bit3 が割込み要求フラグであり，同時にクリアしている．
	 */
	TA0IC = CFG_INTLVL_SYSCLK;

	TA0S = 1;	/* カウント開始	*/
}	/* InitHwSysTimer	*/


/*
 *  システムタイマの停止処理
 *
 *  割込み禁止状態で呼出すこと．
 */
void
TermHwSysTimer(void)
{
	TA0S = 0;					/* カウント停止	*/
	TA0IC = (UINT8)( 0 );		/* 割込みマスク	*/
}	/* TermHwSysTimer	*/


