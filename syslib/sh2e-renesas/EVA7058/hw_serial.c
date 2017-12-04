/*
 *  TOPPERS Automotive Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 *      Automotive Kernel
 * 
 *  Copyright (C) 2004-2006 by Witz Corporation, JAPAN
 *  Copyright (C) 2006 by Hitachi,Ltd., Automotive Systems, JAPAN
 *  Copyright (C) 2006 by Hitachi Information & Control Solutions,Ltd., JAPAN
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
 *	サンプル向けターゲット依存シリアル通信モジュール（SH2 HEW EVAボード用）
 */

/*
 *	SCI1 に端末を接続し、シリアル受信割り込みで処理する
 */

#include	"hw_serial.h"
#include	"sh7058.h"

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
	P_SCI1.SCR1.BYTE = (UINT8)0x00;			/* 送受信禁止, 内部クロック使用 */

	/*
	 *   調歩同期通信, 8ビットデータ, パリティなし, 1ストップビット,
	 *   マルチプロセッサ無効, クロックソース Ｐφ(20MHz)
	 *   LSBファースト
	 */
	P_SCI1.SMR1.BYTE = (UINT8)0x00;
	P_SCI1.SDCR1.BYTE = (UINT8)0xF2;

	/*
	 *  ボーレート設定（設定値はヘッダ参照）
	 */
	P_SCI1.BRR1 = CFG_BRR_SERIAL;

	/*
	 *  受信割込みレベル設定（設定レベルはヘッダ参照）
	 *  SSR の RDRF が割込み要求フラグだが、初期値0のため操作しない．
	 *
	 *  送信割込みは使用しない．
	 */
	P_INTC.IPRK.BIT.SCI1 = CFG_INTLVL_SERIAL_RX1;
	P_SCI1.SCR1.BIT.RIE = 1;

	/*
	 *  IOポートをシリアルポートに変更
	 */
	P_PFC.PCCR.BIT.PC1MD = 1;		/* PC1 を RxD1 */
	P_PFC.PCCR.BIT.PC0MD = 1;		/* PC0 を TxD1 */
	P_PFC.PCIOR.BIT.PC1IOR = 0;		/* RxD1 を入力 */
	P_PFC.PCIOR.BIT.PC0IOR = 1;		/* TxD1 を出力 */

	/*
	 *  送受信を許可
	 */
	P_SCI1.SCR1.BIT.TE = 1;
	P_SCI1.SCR1.BIT.RE = 1;

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
	P_SCI1.SCR1.BYTE = (UINT8)0x0;			/* 送受信禁止 */
	P_SCI1.SSR1.BYTE = (UINT8)0x0;			/* ステータス初期化 */

	/*
	 *  シリアル割込みレベル最低化
	 */
	P_INTC.IPRK.BIT.SCI1 = 0;

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
	P_SCI1.SSR1.BYTE &= (UINT8)~0x38;	/* OROR,FER,PER = 0 */
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
	rx_data = P_SCI1.RDR1;

	/*
	 * 割込み要求をクリア
	 */
	P_SCI1.SSR1.BIT.RDRF = 0;

	/*
	 *  正常受信時はコールバック実行
	 *  エラー時はエラー復帰処理
	 */
	if( ( P_SCI1.SSR1.BYTE & (UINT8)0x38 ) == 0x0 ){
		RxSerialInt( rx_data );
	}
	else{
		P_SCI1.SSR1.BYTE &= (UINT8)~0x38;
	}
}	/* RxHwSerialInt	*/


