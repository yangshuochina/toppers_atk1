/*
 *  TOPPERS Automotive Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 *      Automotive Kernel
 * 
 *  Copyright (C) 2006 by Witz Corporation, JAPAN
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
 *	サンプル向けターゲット依存モジュール（OAKS16-mini用）
 */

#ifndef _SAMPLE_CONFIG_H_
#define _SAMPLE_CONFIG_H_


#include	"kernel.h"


/*
 *  SignalCounter実行用割込みレベル定義
 */
#define CFG_INTLVL_COUNTER	(UINT8)( 0x03 )

/*
 *  ISR1・ISR2カウンタ割込みレベル定義
 */
#define CFG_INTLVL_HW_CNT1	(UINT8)( 0x05 )
#define CFG_INTLVL_HW_CNT2	(UINT8)( 0x02 )

/*
 *  ISR1・ISR2カウンタタイマのコンペア値（1ms）
 *
 *  oaks16-miniではタイマB0,B1で実装する．
 */
#define	CFG_HW_CNT1		(UINT16)( 625u )
#define	CFG_HW_CNT2		(UINT16)( 625u )


#ifndef _MACRO_ONLY

/*
 *  アプリケーションモード用
 */
/*
 *  アプリケーションモード決定用の情報取得処理関数プロトタイプ宣言
 */
extern UINT8	GetAppModeInfo( void );


/*
 *  サンプルカウンタソース用
 */
/*
 *  SignalCounter実行用割込み初期化処理関数プロトタイプ宣言
 */
extern void	InitCounterInt( void );

/*
 *  SignalCounter実行用割込み停止処理関数プロトタイプ宣言
 */
extern void	TermCounterInt( void );

/*
 *  SignalCounter実行用割込み起動処理関数プロトタイプ宣言
 */
extern void	ActCounterInt( void );


/*
 *  ISR1・ISR2稼動確認用
 */
/*
 *  ISR1・ISR2カウンタ初期化処理関数プロトタイプ宣言
 */
extern void	InitHwCntInt( void );

/*
 *  ISR1・ISR2カウンタ停止処理関数プロトタイプ宣言
 */
extern void	TermHwCntInt( void );

/*
 *  ISR1・ISR2カウンタ取得処理関数プロトタイプ宣言
 */
extern void	GetHwCnt( UINT8 *isr1_cnt, UINT8 *isr2_cnt );


#endif /* _MACRO_ONLY */

#endif /* _SAMPLE_CONFIG_H_ */

