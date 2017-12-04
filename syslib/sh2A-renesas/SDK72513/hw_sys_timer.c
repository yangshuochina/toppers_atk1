/*
 *  TOPPERS Automotive Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 *      Automotive Kernel
 * 
 *  Copyright (C) 2004-2006 by Witz Corporation, JAPAN
 *  Copyright (C) 2006,2007 by Hitachi,Ltd., Automotive Systems, JAPAN
 *  Copyright (C) 2006,2007 by Hitachi Information & Control Solutions,Ltd., JAPAN
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
 *	サンプル向けターゲット依存システムタイマモジュール（SH2A SDK72513用）
 */


#include	"hw_sys_timer.h"
#include	"sh72513.h"

#define CMSTR_STR0 (0x0001)
#define CMCR_CMIE (0x40)
#define	IPR05_IPL_CMT0_SHFT (12)
#define	IPR05_IPL_CMT0_MASK (~(0xF << IPR05_IPL_CMT0_SHFT))


/*
 *  システムタイマの起動処理
 *
 *  割込み禁止状態で呼出すこと．
 */
void
InitHwSysTimer( void )
{
	/*
	 *  コンペアマッチタイマを停止して各レジスタ設定
	 *  コンペアマッチタイマ0を使用する．
	 */
	CMSTR &= ~CMSTR_STR0;
	
	/*
	 *  分周比 周辺クロック 1/8(0.4us), 割り込み禁止
	 */
	CMCR_0 = 0;


	/*
	 *  コンペマッチカウンタ目標値設定
	 */
	CMCOR_0 = CFG_SYSCLK;

	/*
	 *  タイマコンペア割込みレベル設定（設定レベルはヘッダ参照）
	 */
	IPR05 = (IPR05 & IPR05_IPL_CMT0_MASK) 
			| ( CFG_INTLVL_SYSCLK << IPR05_IPL_CMT0_SHFT);
	/*
	 *  カウンタクリアと割込み許可
	 */
	CMCNT_0 = (UINT16)0x0000;		/* カウントクリア */
	CMSR_0  = 0;					/* CMF クリア */
	CMCR_0 |= CMCR_CMIE;			/* 割込み enable */
	CMSTR  |= CMSTR_STR0;

}	/* InitHwSysTimer	*/


/*
 *  システムタイマの停止処理
 *
 *  割込み禁止状態で呼出すこと．
 */
void
TermHwSysTimer( void )
{
	CMSTR	&= ~CMSTR_STR0;
	CMCR_0	&= ~CMCR_CMIE;	/* 割込み disable */
	CMSR_0	 = 0;			/* CMF クリア */
}	/* TermHwSysTimer	*/


