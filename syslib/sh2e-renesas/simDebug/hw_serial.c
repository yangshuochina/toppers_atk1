/*
 *  TOPPERS Automotive Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 *      Automotive Kernel
 * 
 *  Copyright (C) 2004-2006 by Witz Corporation, JAPAN
 *  Copyright (C) 2006 by Hitachi,Ltd., Automotive Systems, JAPAN
 *  Copyright (C) 2006 by Hitachi Information & Control Solutions,Ltd., JAPAN
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
 *	サンプル向けターゲット依存システムタイマモジュール（SH2 HEW simDebug用）
 */

/*
 *	本来はシリアル受信割り込みで処理するが、simDebug では、
 *	割り込み処理時にキー入力をポーリングする。
 */

#include	"hw_serial.h"


/*
 *  シリアルIOモジュール初期化処理
 *
 *  割込み禁止状態で呼出すこと．
 */
void
InitHwSerial( void )
{

}	/* InitHwSerial	*/


/*
 *  シリアルIOモジュール停止処理
 *
 *  割込み禁止状態で呼出すこと．
 *  上位で出力が完了していることを保障すること．
 */
void
TermHwSerial( void )
{
}	/* TermHwSerial	*/


/*
 *  シリアルIOモジュール受信エラー割込みサービスルーチン
 */
#if defined( OMIT_ISR1_ENTRY )
/* ISR1入り口未生成時は本関数を割込み関数指定する	*/
#pragma interrupt	ErrHwSerialInt
#endif	/* OMIT_ISR1_ENTRY */
void ErrHwSerialInt( void );
void ErrHwSerialInt( void )
{
}


/*
 *  シリアルIOモジュール受信割込みサービスルーチン
 */
#if defined( OMIT_ISR1_ENTRY )
/* ISR1入り口未生成時は本関数を割込み関数指定する	*/
#pragma interrupt	RxHwSerialInt
#endif	/* OMIT_ISR1_ENTRY	*/
void RxHwSerialInt( void );
void RxHwSerialInt( void )
{
	UINT8	rx_data;	/* データ受信バッファ	*/

	rx_data = charget();

	/*
	 *  正常受信時はコールバック実行
	 */
	if( rx_data != 0 ){
		RxSerialInt( rx_data );
	}

}	/* RxHwSerialInt	*/


