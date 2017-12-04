/*
 *  TOPPERS Automotive Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 *      Automotive Kernel
 * 
 *  Copyright (C) 2006 by Witz Corporation, JAPAN
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
 *	サンプル向けシリアルIOモジュール
 */

#include	"hw_serial.h"
#include	"serial.h"


/*
 *  受信用データ
 */
static UINT8	rx_char;
static BOOL		rx_flag;

/*
 *  シリアルIOモジュール初期化処理
 *
 *  割込み禁止状態で呼出すこと．
 */
void
InitSerial( void )
{
	/*
	 *  受信フラグ初期化
	 */
	rx_flag = FALSE;

	/*
	 *  依存部初期化処理実行
	 */
	InitHwSerial();
}	/* InitSerial	*/

/*
 *  シリアルIOモジュール停止処理
 *
 *  出力が完了していることは保障しない（デッドロック防止）．
 *  コンテキストロックして出力するので，ほぼ問題なし（最後の２文字のみ）．
 *
 *  割込み禁止状態で呼出すこと．
 */
void
TermSerial( void )
{
	/*
	 *  依存部初期化処理実行
	 */
	TermHwSerial();

	/*
	 *  受信データ無効化
	 */
	rx_flag = FALSE;
}	/* TermSerial	*/

/*
 *  文字列送信処理
 */
void
SendSerialStr( const UINT8 * str )
{
	/*
	 *  割込み禁止状態にして，割込み中文字列送信処理実行
	 */
	SuspendAllInterrupts();
	SendIntSerialStr( str );
	ResumeAllInterrupts();
}	/* SendSerialStr	*/

/*
 *  割込み中文字列送信処理
 */
void
SendIntSerialStr( const UINT8 * str )
{
	/*
	 *  依存部文字出力処理にて全データを送信
	 */
	while( *str != '\0' ){
		PutHwChar( *str );
		str++;
	}
}	/* SendIntSerialStr	*/

/*
 *  文字受信処理
 */
void RecvPolSerialChar( UINT8 * character )
{
	if( rx_flag == TRUE ){
	/*
	 *  割込み禁止にして受信データ取得・フラグクリア
	 */
		SuspendAllInterrupts();
		*character = rx_char;
		rx_flag = FALSE;
		ResumeAllInterrupts();
	}
	else{
	/*
	 *  受信データがない場合は'\0'を返す
	 */
		*character = '\0';
	}
}	/* RecvPolSerialChar	*/

/*
 *  受信コールバック関数
 */
void
RxSerialInt( UINT8 character )
{
	/*
	 *  割込み禁止にして受信データ保持・フラグクリア
	 */
	SuspendAllInterrupts();
	rx_char = character;
	rx_flag = TRUE;
	ResumeAllInterrupts();
}	/* RxSerialInt	*/

/*
 *  32bit数値 -> 10進数文字列変換関数
 */
void
ConvLong2DecStr( UINT8 *dst, UINT32 src )
{
	UINT32	temp;	/* 桁数算出用テンポラリ	*/

	/*
	 *  表示桁数算出
	 */
	temp = src;
	while( ( temp /= 10 ) != 0 ){
		dst++;
	}
	
	dst[1] = '\0';	/* 文字列終端コード設定	*/

	/*
	 *  数字に変換
	 */
	do{
		*dst-- = (UINT8)( ( src % 10 ) + '0' );
	} while( ( src /= 10 ) != 0 );
}	/* ConvLong2DecStr	*/

/*
 *  16bit数値 -> 10進数文字列変換関数
 */
void
ConvShort2DecStr( UINT8 *dst, UINT16 src )
{
	UINT16	temp;	/* 桁数算出用テンポラリ	*/

	/*
	 *  表示桁数算出
	 */
	temp = src;
	while( ( temp /= 10 ) != 0 ){
		dst++;
	}
	
	dst[1] = '\0';	/* 文字列終端コード設定	*/

	/*
	 *  数字に変換
	 */
	do{
		*dst-- = (UINT8)( ( src % 10 ) + '0' );
	} while( ( src /= 10 ) != 0 );
}	/* ConvShort2DecStr	*/

/*
 *  8bit数値 -> 10進数文字列変換関数
 */
void
ConvByte2DecStr( UINT8 *dst, UINT8 src )
{
	UINT8	temp;	/* 桁数算出用テンポラリ	*/

	/*
	 *  表示桁数算出
	 */
	temp = src;
	while( ( temp /= 10 ) != 0 ){
		dst++;
	}
	
	dst[1] = '\0';	/* 文字列終端コード設定	*/

	/*
	 *  数字に変換
	 */
	do{
		*dst-- = (UINT8)( ( src % 10 ) + '0' );
	} while( ( src /= 10 ) != 0 );
}	/* ConvByte2DecStr	*/

/*
 *  32bit数値 -> 16進数文字列変換関数
 *
 *  本関数の出力バッファ（*dstが指し示す先）は 9Byte（8桁+文字終端コード）
 *  以上保持することを前提とする．
 */
void
ConvLong2HexStr( UINT8 *dst, UINT32 src )
{
	UINT8	mod;
	INT8	idx = 8;
	/*
	 *  8桁0詰めで16進数文字列に変換
	 */

	dst[idx--] = '\0';	/* 文字列終端コード設定	*/

	/*
	 *  16進数字に変換
	 */
	do{
		mod = (UINT8)( src & (UINT32)0x0000000f );
		if( mod < 10 ){
			dst[idx--] = (UINT8)( mod + '0' );
		}
		else{
			dst[idx--] = (UINT8)( ( mod - 10 ) + 'A' );
		}
	} while( ( src >>= 4 ) != 0 );

	/*
	 *  残りの桁を0詰め
	 */
	while( idx >= 0 ){
		dst[idx--] = (UINT8)'0';
	}
}	/* ConvLong2HexStr	*/

/*
 *  16bit数値 -> 16進数文字列変換関数
 *
 *  本関数の出力バッファ（*dstが指し示す先）は 5Byte（4桁+文字終端コード）
 *  以上保持することを前提とする．
 */
void
ConvShort2HexStr( UINT8 *dst, UINT16 src )
{
	UINT8	mod;
	INT8	idx = 4;
	/*
	 *  4桁0詰めで16進数文字列に変換
	 */

	dst[idx--] = '\0';	/* 文字列終端コード設定	*/

	/*
	 *  16進数字に変換
	 */
	do{
		mod = (UINT8)( src & (UINT16)0x000f );
		if( mod < 10 ){
			dst[idx--] = (UINT8)( mod + '0' );
		}
		else{
			dst[idx--] = (UINT8)( ( mod - 10 ) + 'A' );
		}
	} while( ( src >>= 4 ) != 0 );

	/*
	 *  残りの桁を0詰め
	 */
	while( idx >= 0 ){
		dst[idx--] = (UINT8)'0';
	}
}	/* ConvShort2HexStr	*/

/*
 *  8bit数値 -> 16進数文字列変換関数
 *
 *  本関数の出力バッファ（*dstが指し示す先）は 3Byte（2桁+文字終端コード）
 *  以上保持することを前提とする．
 */
void
ConvByte2HexStr( UINT8 *dst, UINT8 src )
{
	UINT8	mod;
	INT8	idx = 2;
	/*
	 *  2桁0詰めで16進数文字列に変換
	 */

	dst[idx--] = '\0';	/* 文字列終端コード設定	*/

	/*
	 *  16進数字に変換
	 */
	do{
		mod = (UINT8)( src & (UINT8)0x0f );
		if( mod < 10 ){
			dst[idx--] = (UINT8)( mod + '0' );
		}
		else{
			dst[idx--] = (UINT8)( ( mod - 10 ) + 'A' );
		}
	} while( ( src >>= 4 ) != 0 );

	/*
	 *  残りの桁を0詰め
	 */
	while( idx >= 0 ){
		dst[idx--] = (UINT8)'0';
	}
}	/* ConvByte2HexStr	*/


