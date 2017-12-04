/*
 *  TOPPERS Automotive Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 *      Automotive Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2004 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 *  Copyright (C) 2006 by Witz Corporation, JAPAN
 *  Copyright (C) 2006,2007 by Hitachi,Ltd., Automotive Systems, JAPAN
 *  Copyright (C) 2006,2007 by Hitachi Information & Control Solutions,Ltd., JAPAN
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
 *  プロセッサ依存モジュール（SH2A用）
 */


/*ヘッダファイル*/
#include	"osek_kernel.h"
#include 	"sh72513.h"
UINT32 int_ena_flag;
UINT32 int_ena_level;
UINT32 common_stack_top;	/* 共通スタック領域 */

extern UINT8 Enable_Resbank;

/*
 *  プロセッサ依存の初期化
 */
void
cpu_initialize(void)
{
	/* カーネルで使用する変数の初期化 */
	int_ena_flag = 1;
	int_ena_level = 0;

	/* 共通スタック領域初期化 */
	common_stack_top = (UINT32) STACK_TOP;
	if(Enable_Resbank)
	{
		IBCR = 0;			/* 割込みレベルごとの設定はしない */
/*		IBNR_BE = 1;		   レジスタバンクを全割込みレベルで有効にする(IBCRを無視) */
/*		IBNR_BOVE = 1;		   レジスタバンクオーバーフロー例外有効 */
		IBNR = (0x6000);	/* SH72513 では、IBNR へは 16bit アクセス必須 */
	}
	else
	{
/*		IBNR_BE = 0;		   レジスタバンクを全割込みレベルで無効にする */
		IBNR = (0x0000);	/* SH72513 では、IBNR へは 16bit アクセス必須 */
	}

}

/*
 *  プロセッサ依存の終了処理
 */
void
cpu_terminate(void)
{
	/* 特に必要ない */
}

#if defined(SH2) || defined(SH2E)
/*
 *  SH2,SH2Eには、バレルシフト命令が無いため、変数によるシフト演算は低速である。
 *  よって、配列に結果を格納しておく。
 */
const UINT16 primap_bitmask[16] = 
	{ 1, 2, 4, 8, 16, 32, 64, 128,
	  256, 512, 1024, 2048, 4096, 8192, 16384, 32768 };
#endif	/* SH2 or SH2E */
