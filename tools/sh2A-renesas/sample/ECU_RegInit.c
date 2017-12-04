/*
 *  TOPPERS Automotive Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 *      Automotive Kernel
 * 
 *  Copyright (C) 2007 by Hitachi,Ltd., Automotive Systems, JAPAN
 *  Copyright (C) 2007 by Hitachi Information & Control Solutions,Ltd., JAPAN
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
 *	サンプル向けターゲット依存モジュール（SH2A SDK72513用）
 */

#include <sh72513.h>

#pragma section ResetPRG

#define DFL_CS2BCR_BSZ_SHFT	(9)
#define DFL_CS2BCR_BSZ_MASK (~(3 << DFL_CS2BCR_BSZ_SHFT))

void
REG_INIT_BSC()			/* バスステートコントローラ初期化 RAMチェック前に実施*/
{
	/*	外部IOデバイスの CS2空間 のみ、明示的にデータバス幅を指定する (16bit)	*/
	/* 設定 BSC.CS2BCR.BIT.BSZ		=	2;	(16bit) */
	CS2BCR	= 	(CS2BCR & DFL_CS2BCR_BSZ_MASK) | (2 << DFL_CS2BCR_BSZ_SHFT);

	PCCR4	=	0x1111;		/*	データバス入出力を選択	*/
	PCCR3	=	0x1111;		/*	データバス入出力を選択	*/
	PCCR2	=	0x1111;		/*	データバス入出力を選択	*/
	PCCR1	=	0x1111;		/*	データバス入出力を選択	*/
	PBCR2	|=	0x1000;		/*	WE1 端子有効	*/
	
	/* CS 空間アクセスウェイト設定 (No wait) */
	CS0BCR = 0x00000400;	/* Access間 No wait  */

	/* CS 空間 Read サイクルウェイト設定 (1 wait) */
	CS0WCR = 0x00000080;	/* Read wait 1cycle */

	RAMACYC = 0x7810;		/* Write 3 wait, read 2 wait (推奨値) */
	RAMACYC = RAMACYC | 0;	/* 書き込み後、ダミーリード実施 */

	/* ROM キャッシュを 無効にする場合の設定値
	 *  ROMC.RCCR.LONG = 0;
	 *	RCCR = 0;
	 */
}


void
REG_INIT_ATUIII()			/* ATU-III レジスタ共通部初期化 */
{
	ATUENR	= 0;			/*	全タイマ停止 */
	PSCR1	= 1;			/* 分周比 Pφ/2  0.1us */
    ATUENR	|= ATUENR_PSCE;		/* プリスケーラスタート */
}

#pragma section
