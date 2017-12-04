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
 *	サンプル向けターゲット依存モジュール（hokuto_bb用）
 */


#include	"sample_config.h"
#include	"h8_36057.h"


/*
 *  OIL定義シンボルの外部参照
 */
DeclareCounter( SampleCnt );


/*
 *	内部関数プロトタイプ宣言
 */
ISR( CounterInt );
ISR( HwCnt2Int );


/*
 *  アプリケーションモード用
 */
/*
 *  アプリケーションモード決定用の情報取得処理
 *
 *  システムごとに任意の入力手法により実装すること．
 *  0,1,2が判別できること．3は2と同じ扱いになる．
 * 
 *  ToDo :  
 *
 */
UINT8
GetAppModeInfo( void )
{
	return 0;
}


/*
 *  サンプルカウンタソース用
 *
 */

/*
 *  SignalCounter実行用割込み初期化処理
 *
 */
void
InitCounterInt( void )
{

	TV_TCRV0 = (UINT8)0;    /* タイマ停止 */	
	TV_TCORA = (UINT8)0x01; /* タイムアウト値を設定 */
	TV_TCRV1 |= (UINT8)TV_TCRV1_ICKS0;
}

/*
 *  SignalCounter実行用割込み停止処理
 */
void
TermCounterInt( void )
{
	/* 特になし */
}

/*
 *  SignalCounter実行用割込み起動処理
 */
void
ActCounterInt( void )
{
	/*
	 * カウント値設定
	 */ 
	TV_TCNTV = (UINT8)0x00;
	
	/*
	 * コンペアマッチAでクリア
	 * コンペアマッチインタラプトイネーブルA	  
	 * φ/128 でスタート
	 */
	TV_TCRV0 = (UINT8)(TV_TCRV0_CMIEA|TV_TCRV0_CCLR0|TV_TCRV0_CKS1|TV_TCRV0_CKS0);
}

/*
 *  SignalCounter実行用割込みサービスルーチン
 *  タイマ割込みは１回のみ発生させる
 */
ISR( CounterInt )
{
	UINT8 tmp;
	
	/* 割込み要求をクリア */
	tmp = TV_TCSRV;    
	TV_TCSRV = (UINT8)0;
	
	/* タイマ停止 */
	TV_TCRV0 = (UINT8)0;
	
	/*
	 *  カウンタ加算通知処理実行
	 */
	SignalCounter( SampleCnt );
}


/*
 *  ISR1・ISR2稼動確認用
 *
 */
/*
 *  ハードウェアカウンタバッファ
 */
static UINT8	hw_cnt1;
static UINT8	hw_cnt2;

/*
 *  ISR1・ISR2カウンタ初期化処理
 */
void
InitHwCntInt( void )
{
	hw_cnt1 = 0;
	hw_cnt2 = 0;

	/*
	 * ISR1用確認用タイマZチャネル0初期化
	 */
	/* GRAのコンペアマッチでクリア、立下りエッジ、内部クロックでカウント */
	TZ_TCR_0 = (UINT8)TZ_TCR_CCLR0;
	TZ_GRA_0 = (UINT16)20000;           /* カウント値を設定 */
	TZ_TSTR |= (UINT8)TZ_TSTR_STR0;     /* タイマスタート */
	TZ_TIER_0 |=  (UINT8)TZ_TIER_IMIEA; /* 割込み許可 */ 


	/*
	 * ISR2用確認用タイマB初期化
	 *  8bitタイマ
	 */
	
	/*
     * オートリロード
	 * クロック φ/8192
	 * 50n * 256 = 12800n
     * 1m / 12800 = 78.125 = 79 = 0x4f
	 */
	TB1_TMB1 = (UINT8)(TB1_TMB1_RLD|TB1_TMB1_CKS1|TB1_TMB1_CKS0);

	TB1_TLB1 = (UINT8)(0xff - 0x4f);
	
	/* タイマB1オーバーフロー割込み許可 */
	IENR2 |= (UINT8)IENR2_IENTB1;
}

/*
 *  ISR1・ISR2カウンタ停止処理
 */
void
TermHwCntInt( void )
{
	UINT8 tmp;
	
	/*
	 * ISR1確認用タイマZチャネル0停止処理
	 */
	TZ_TSTR &= (UINT8)(~(TZ_TSTR_STR0)); /* タイマ停止 */
	TZ_TSR_0 &= (UINT8)(~(TZ_TSR_IMFA)); /* 割り込み要求をクリア */

	/*
	 * ISR2確認用タイマB停止
	 */ 
	IENR2 &= (UINT8)(~(IENR2_IENTB1)); /* タイマB1オーバーフロー割込み禁止 */
}

/*
 *  ISR1・ISR2カウンタ取得処理
 *
 */
void
GetHwCnt( UINT8 *isr1_cnt, UINT8 *isr2_cnt )
{
	*isr1_cnt = hw_cnt1;
	*isr2_cnt = hw_cnt2;
}

/*
 *  ISR1カウンタ加算用割込みサービスルーチン
 */
void
HwCnt1Int( void )
{
	TZ_TSR_0 &= (UINT8)(~(TZ_TSR_IMFA)); /* 割り込み要求をクリア */
	hw_cnt1++;
}

/*
 *  ISR2カウンタ加算用割込みサービスルーチン
 */
ISR( HwCnt2Int )
{
	/* 割込みクリア */
	IRR2 &= (UINT8)(~(IRR2_IRRTB1));
	
	hw_cnt2++;
}
