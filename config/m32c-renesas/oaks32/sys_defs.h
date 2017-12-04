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
 *	ターゲットシステムに依存する定義（OAKS32用）
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
#define OAKS32

/*
 *  起動メッセージのターゲットシステム名
 */
#define	TARGET_NAME		(const UINT8 *)"M32C/OAKS32"

/*
 *  システムで使用するプロセッサの種類
 *  144ピン版を使用する場合は SYS_MCU_M30835を定義する
 *  100ピン版を使用する場合は SYS_MCU_M30833を定義する
 */
/*#define	SYS_MCU_M30835	*/
#define	SYS_MCU_M30833


/*
 *  割込み番号の定義
 */
#define	INT_BRKV		0		/* BRK命令	*/
#define	INT_AD1			7		/* A/D変換1	*/
#define	INT_DMA0		8		/* DMA0	*/
#define	INT_DMA1		9		/* DMA1	*/
#define	INT_DMA2		10		/* DMA2	*/
#define	INT_DMA3		11		/* DMA3	*/
#define	INT_TA0			12		/* タイマA0	*/
#define	INT_TA1			13		/* タイマA1	*/
#define	INT_TA2			14		/* タイマA2	*/
#define	INT_TA3			15		/* タイマA3	*/
#define	INT_TA4			16		/* タイマA4	*/
#define	INT_S0TNACK		17		/* NACK	*/
#define	INT_S0RACK		18		/* ACK	*/
#define	INT_S1TNACK		19		/* NACK	*/
#define	INT_S1RACK		20		/* ACK	*/
#define	INT_UART0TX		17		/* UART0送信	*/
#define	INT_UART0RX		18		/* UART0受信	*/
#define	INT_UART1TX		19		/* UART1送信	*/
#define	INT_UART1RX		20		/* UART1受信	*/
#define	INT_TB0			21		/* タイマB0	*/
#define	INT_TB1			22		/* タイマB1	*/
#define	INT_TB2			23		/* タイマB2	*/
#define	INT_TB3			24		/* タイマB3	*/
#define	INT_TB4			25		/* タイマB4	*/
#define	INT_INT5		26		/* INT5	*/
#define	INT_INT4		27		/* INT4	*/
#define	INT_INT3		28		/* INT3	*/
#define	INT_INT2		29		/* INT2	*/
#define	INT_INT1		30		/* INT1	*/
#define	INT_INT0		31		/* INT0	*/
#define	INT_TB5			32		/* タイマB5	*/
#define	INT_S2TNACK		33		/* NACK	*/
#define	INT_S2RACK		34		/* ACK	*/
#define	INT_S3TNACK		35		/* NACK	*/
#define	INT_S3RACK		36		/* ACK	*/
#define	INT_S4TNACK 	37		/* NACK	*/
#define	INT_S4RACK		38		/* ACK	*/
#define	INT_UART2TX		33		/* UART2送信	*/
#define	INT_UART2RX		34		/* UART2受信	*/
#define	INT_UART3TX		35		/* UART3送信	*/
#define	INT_UART3RX		36		/* UART3受信	*/
#define	INT_UART4TX 	37		/* UART4送信	*/
#define	INT_UART4RX		38		/* UART4受信	*/
#define	INT_SSC2		39		/* バス衝突検出/スタートコンディション検出/ストップコンディション検出(UART2)/障害エラー	*/
#define	INT_SSC30		40		/* バス衝突検出/スタートコンディション検出/ストップコンディション検出(UART3/UART0)/障害エラー	*/
#define	INT_SSC41		41		/* バス衝突検出/スタートコンディション検出/ストップコンディション検出(UART4/UART1)/障害エラー	*/
#define	INT_AD0			42		/* A/D変換0	*/
#define	INT_KEY			43		/* キー入力	*/
#define	INT_IIO0		44		/* インテリジェントI/O0	*/
#define	INT_IIO1		45		/* インテリジェントI/O1	*/
#define	INT_IIO2		46		/* インテリジェントI/O2	*/
#define	INT_IIO3		47		/* インテリジェントI/O3	*/
#define	INT_IIO4		48		/* インテリジェントI/O4	*/
#define	INT_IIO5		49		/* インテリジェントI/O5	*/
#define	INT_IIO6		50		/* インテリジェントI/O6	*/
#define	INT_IIO7		51		/* インテリジェントI/O7	*/
#define	INT_IIO8		52		/* インテリジェントI/O8	*/
#define	INT_IIO9CAN0	53		/* インテリジェントI/O9,CAN0	*/
#define	INT_IIO10CAN1	54		/* インテリジェントI/O10,CAN1	*/
#define	INT_IIO11CAN2	57		/* インテリジェントI/O11,CAN2	*/
#define	INT_UDI			64		/* 未定義命令	*/
#define	INT_OVF			65		/* オーバーフロー	*/
#define	INT_BLKF		66		/* BRK命令	*/
#define	INT_ADR			67		/* アドレス一致	*/
#define	INT_WDT			69		/* 監視タイマ/発振停止検出	*/
#define	INT_NMI			71		/* NMI	*/
#define	INT_RESET		72		/* リセット	*/


#endif /* _SYS_DEFS_H_ */
