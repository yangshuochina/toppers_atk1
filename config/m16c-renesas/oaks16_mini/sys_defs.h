/*
 *  TOPPERS Automotive Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 *      Automotive Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2003 by Naoki Saito
 *             Nagoya Municipal Industrial Research Institute, JAPAN
 *  Copyright (C) 2004 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 *  Copyright (C) 2005-2006 by Witz Corporation, JAPAN
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
 *	ターゲットシステムに依存する定義（OAKS16-mini用）
 */

#ifndef _SYS_DEFS_H_
#define _SYS_DEFS_H_

/* 
 *  カーネルステータスタイプの定義
 *
 *  下記定義を有効にすることで，OSEK仕様の拡張エラーチェックを無効化できる．
 */
/*#define BASIC_STATUS	*/

/* 
 *  ターゲット識別マクロ(システム名の定義)
 */
#define OAKS16_MINI

/*
 *  起動メッセージのターゲットシステム名
 */
#define TARGET_NAME "OAKS16-mini"

/*
 *  割込み番号の定義
 */
#define	INT_BRKV		0		/* BRK命令				*/
#define	INT_INT3		4		/* INT3					*/
#define	INT_INT5		8		/* INT5					*/
#define	INT_INT4		9		/* INT4					*/
#define	INT_UART2BCN	10		/* UART2バス衝突検出	*/
#define	INT_DMA0		11		/* DMA0					*/
#define	INT_DMA1		12		/* DMA1					*/
#define	INT_KEY			13		/* キー入力				*/
#define	INT_AD			14		/* A/D変換1				*/
#define	INT_NACK2		15		/* NACK					*/
#define	INT_ACK2		16		/* ACK					*/
#define	INT_UART2TX		15		/* UART2送信			*/
#define	INT_UART2RX		16		/* UART2受信			*/
#define	INT_UART0TX		17		/* UART0送信			*/
#define	INT_UART0RX		18		/* UART0受信			*/
#define	INT_UART1TX		19		/* UART1送信			*/
#define	INT_UART1RX		20		/* UART1受信			*/
#define	INT_TA0			21		/* タイマA0				*/
#define	INT_TA1			22		/* タイマA1				*/
#define	INT_TA2			23		/* タイマA2				*/
#define	INT_TA3			24		/* タイマA3				*/
#define	INT_TA4			25		/* タイマA4				*/
#define	INT_TB0			26		/* タイマB0				*/
#define	INT_TB1			27		/* タイマB1				*/
#define	INT_TB2			28		/* タイマB2				*/
#define	INT_INT0		29		/* INT0					*/
#define	INT_INT1		30		/* INT1					*/
#define	INT_UDI			64		/* 未定義命令			*/
#define	INT_OVF			65		/* オーバーフロー		*/
#define	INT_BLKF		66		/* BRK命令				*/
#define	INT_ADR			67		/* アドレス一致			*/
#define	INT_SSI			68		/* シングルステップ(デバッグツール用)			*/
#define	INT_WDT			69		/* 監視タイマ/発振停止･再発振検出/電圧低下検出	*/
#define	INT_DBC			70		/* デバッグツール用		*/
#define	INT_NMI			71		/* NMI					*/
#define	INT_RESET		72		/* リセット				*/


#endif /* _SYS_DEFS_H_ */
