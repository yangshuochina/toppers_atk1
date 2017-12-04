/*
 *  TOPPERS Automotive Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 *      Automotive Kernel
 * 
 *  Copyright (C) 2006 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
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
 *  ターゲットシステム依存シリアルモジュール（H8/Tiny用）
 *    SCI3を使用 
 */

#ifndef _HW_SERIAL_H_
#define _HW_SERIAL_H_


#include	"kernel.h"
#include	"h8_36057.h"


#ifndef _MACRO_ONLY

/*
 *  システムログ出力モジュール初期化関数プロトタイプ宣言
 */
extern void InitHwSerial( void );

/*
 *  システムログ出力モジュール停止関数プロトタイプ宣言
 */
extern void	TermHwSerial( void );

/*
 *  システムログ出力関数プロトタイプ宣言
 */
Inline void	PutHwChar( UINT8 character );

/*
 *  コールバック関数外部参照
 */
extern void	RxSerialInt( UINT8 character );

/*
 *  呼び指しコンテキストでの文字送信．
 *
 *  本関数は割込み禁止状態で呼び出すこと．
 *  改行コードなどの制御コードも要求側で行うこと．
 */
Inline void
PutHwChar( UINT8 character )
{
	/* 送信バッファが空になるまで待つ	*/
	while(0 == (SCI3_SSR & (UINT8)SSR_TDRE));

	SCI3_TDR = (UINT16)(character);
}

#endif	/* _MACRO_ONLY */

#endif /* _HW_SERIAL_H_ */
