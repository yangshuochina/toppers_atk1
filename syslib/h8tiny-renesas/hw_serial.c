/*
 *  TOPPERS Automotive Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 *      Automotive Kernel
 * 
 *  Copyright (C) 2006 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN    
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
 *  ターゲットシステム依存シリアルモジュール（H8/Tiny用）
 *    SCI3を使用 
 */

#include	"hw_serial.h"


/*
 *  ポートのクローズ
 */
static
cls_port(void)
{
	long count;
	
	/* TDRE が 1 になるまで待つ */
	while( 0 == (SCI3_SSR & (UINT8)SSR_TDRE) );

	/*
     * 11ビット送信分待つ
	 *  約 1.2 msec待つ 
	 *   9600bps = 約 0.1 msec
	 *   0.1 * 11 + 1 = 1.2 msec
	 * 1回のwhileループに要する時間
	 *   1命令の実行ステートの最小は2ステート
	 *   20Mhz動作の場合，1ステート50nsec
	 *   while命令は4ステップ
	 *    4 * 2 * 50nsec = 400nsec
	 * 1.2msec / 400nsec = 3000   
	 */
	count = 3000L;
	while (0 < count){
		count--;
	}

	/* 送受信停止 */
	SCI3_SCR &= (UINT8)(~(SCR_TIE|SCR_RIE|SCR_TE|SCR_RE));
}

/*
 *  シリアルIOモジュール初期化処理
 *    ポートを初期化して受信割込みを有効にする．
 */
void
InitHwSerial(void)
{
	long count;
	
	cls_port();

	/* モード設定 */
	SCI3_SMR = (UINT8)0;
	
	/* ボーレート設定(38900bps) */
	SCI3_BRR = (UINT8)15;

	/* 割込みの禁止とクロックソースの選択 */
	SCI3_SCR = (UINT8)0;

	/* ボーレートの設定後、1bit待つ必要がある 
	 *  約 0.1 msec待つ 
	 *   9600bps = 約 0.1 msec (最低ボーレート)
	 * 1回のwhileループに要する時間
	 *   1命令の実行ステートの最小は2ステート
	 *   20Mhz動作の場合，1ステート50nsec
	 *   while命令は4ステップ
	 *    4 * 2 * 50nsec = 400nsec
	 * 0.1msec / 400nsec = 250
	 */
	count = 250L;
	while (0 < count){
		count--;
	}

	/* エラーフラグをクリア */
	SCI3_SSR &= (UINT8)(~(SSR_ORER|SSR_FER|SSR_PER));

	/* 送受信許可, 受信割込み許可 */
	SCI3_SCR |= (UINT8)(SCR_TE|SCR_RE|SCR_RIE);
	
	/* ポートを有効に */
	IO_PMR1 |= (UINT8)IO_PMR1_TXD;
}

/*
 *  シリアルIOモジュール停止処理
 *
 */
void
TermHwSerial(void)
{
	cls_port();
}

  
/*
 *  シリアルIOモジュール受信割込みサービスルーチン
 */
void RxHwSerialInt(void)
{
	UINT8 data;
	
	if((SCI3_SSR & (UINT8)(SSR_ORER|SSR_FER|SSR_PER)) != 0){
		/* エラー処理 */
		/* エラーフラグをクリア */
		SCI3_SSR &= (UINT8)(~(SSR_ORER|SSR_FER|SSR_PER));
	}
	else {
		/* データ受信 */
		data = (UINT8)SCI3_RDR;
		/* 受信フラグクリア */
		SCI3_SSR &= (UINT8)(~(SSR_RDRF));
		RxSerialInt(data);	/* 受信コールバック実行 */
	}
}
