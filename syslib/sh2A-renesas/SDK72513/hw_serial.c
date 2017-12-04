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
 *	サンプル向けターゲット依存シリアル通信モジュール（SH2A SDK72513用）
 */

/*
 *	SCIA に端末を接続し、シリアル受信割り込みで処理する
 */

#include	"hw_serial.h"
#include	"sh72513.h"

#define PJCR1_MD6      0x1000    /* PJ6MD:1(RxD_A入力)             */
#define PJCR1_MD5      0x0400    /* PJ5MD:1(TxD_A出力)             */



/*
 *  シリアルIOモジュール初期化処理
 *
 *  割込み禁止状態で呼出すこと．
 */
void
InitHwSerial( void )
{
	/*
	 *  送受信を禁止して各レジスタ設定
	 */
	SCSCR1A = (UINT8)0x00;			/* 送受信禁止, 内部クロック使用 */
	SCSSR1A = 0;
	/*
	 *   調歩同期通信, 8ビットデータ, パリティなし, 1ストップビット,
	 */
	SCSMR1A = (UINT8)0x00;

	/*
	 *  ボーレート設定（設定値はヘッダ参照）
	 */
	SCBRR1A = CFG_BRR_SERIAL;

	/*
	 *  受信割込みレベル設定（設定レベルはヘッダ参照）
	 *  SSR の RDRF が割込み要求フラグだが、初期値0のため操作しない．
	 *
	 *  送信割込みは使用しない．
	 */
	IPR26 = (IPR26 & 0x0FFF) | (CFG_INTLVL_SERIAL_RX1 <<12);
	SCSCR1A = SCSCR1_RIE;

	/*
	 *  IOポートをシリアルポートに変更
	 */
	PJCR1 = (PJCR1 & 0xC3FF) | PJCR1_MD6 | PJCR1_MD5;

	/*
	 *  送受信を許可
	 */
	SCSCR1A	|= SCSCR1_TE;
	SCSCR1A	|= SCSCR1_RE;

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
	/*
	 *  送受信および送受信割込み禁止
	 */
	SCSCR1A = (UINT8)0x0;			/* 送受信禁止 */
	SCSSR1A = (UINT8)0x0;			/* ステータス初期化 */

	/*
	 *  シリアル割込みレベル最低化
	 */
	IPR26 = (IPR26 & 0x0FFF);

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
	UINT8 dmy;
	SCSSR1A &= (UINT8)~0x38;	/* OROR,FER,PER = 0 */
	dmy = SCSSR1A;				/* ダミーリード */
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

	/*
	 *  オーバラン防止のためまず読込む
	 */
	rx_data = SCRDR1A;

	/*
	 * 割込み要求をクリア
	 */
	SCSSR1A &= ~SCSSR1_RDRF;
	/* 下の処理で SCSSR1A を読み込んでいるのでダミーリード不要 */
	
	/*
	 *  正常受信時はコールバック実行
	 *  エラー時はエラー復帰処理
	 */
	if( ( SCSSR1A  & (UINT8)0x38 ) == 0x0 ){
		RxSerialInt( rx_data );
	}
	else{
		SCSSR1A &= (UINT8)~0x38;
	}
}	/* RxHwSerialInt	*/


