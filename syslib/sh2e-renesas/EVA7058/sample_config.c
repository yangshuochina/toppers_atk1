/*
 *  TOPPERS Automotive Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 *      Automotive Kernel
 * 
 *  Copyright (C) 2006 by Witz Corporation, JAPAN
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
 *	サンプル向けターゲット依存モジュール（SH2 HEW EVAボード用）
 */


#include	"sample_config.h"
#include	"sh7058.h"


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
 */
UINT8
GetAppModeInfo( void )
{
	/*
	 *  本来はここでアプリケーションモードの判定を行うべきだが、
	 *  ボード上にモードを取得できるH/Wが実装されていないため、
	 *  常に0を返す．
	 */
	
	return 0;

}	/* GetAppModeInfo	*/


/*
 *  サンプルカウンタソース用
 *
 *  SH7058 ではCMT1で実装する．
 */

/*
 *  SignalCounter実行用割込み初期化処理
 *
 *  タイマの起動は別関数で行う．
 */
void
InitCounterInt( void )
{
	/*
	 *  コンペアマッチタイマを停止して各レジスタ設定
	 */
	P_CMT.CMSTR.BIT.STR1 = 0;		/* カウント停止 */

	/*
	 *  分周比 周辺クロック 1/8, 割り込み禁止
	 *  CMCSR の bit6 が割込み要求フラグであり，同時にクリアしている．
	 */
	P_CMT.CMCSR1.WORD = (UINT16)0x0000;

	/*
	 *  コンペマッチカウンタ目標値設定
	 *  タイマ起動直後にコンペアマッチさせるため
	 */
	P_CMT.CMCOR1 = (UINT16)0x0001;

	/*
	 *  タイマコンペア割込みレベル設定（設定レベルはヘッダ参照）
	 */
	P_INTC.IPRJ.BIT.CMT1_AD1 = CFG_INTLVL_COUNTER;

	/*
	 *  カウンタクリアと割込み許可
	 */
	P_CMT.CMCNT1 = 0x0000;				/* カウントクリア */
	P_CMT.CMCSR1.BIT.CMIE = 1;				/* コンペアマッチ割込み許可 */

}	/* InitCounterInt	*/

/*
 *  SignalCounter実行用割込み停止処理
 */
void
TermCounterInt( void )
{
	P_CMT.CMSTR.BIT.STR1 = 0;		/* カウント停止 */
	P_CMT.CMCSR1.WORD = (UINT16)0x0000;			/* 機能初期化 */
}	/* TermCounterInt	*/

/*
 *  SignalCounter実行用割込み起動処理
 */
void
ActCounterInt( void )
{
	P_CMT.CMCNT1 = 0x0000;			/* カウントクリア */
	P_CMT.CMSTR.BIT.STR1 = 1;		/* カウント開始 */
}	/* ActCounterInt	*/

/*
 *  SignalCounter実行用割込みサービスルーチン
 */
ISR( CounterInt )
{
	StatusType ercd;

	/*
	 *  1回のみ SignalCounter 実行したいため，タイマを停止する．
	 */
	P_CMT.CMCSR1.BIT.CMIE = 0;				/* コンペアマッチ割込み禁止 */
	P_CMT.CMSTR.BIT.STR1 = 0;		/* カウント停止 */

	/*
	 *  割込み要求クリア
	 */
	P_CMT.CMCSR1.BIT.CMF = 0;		/* 割込み要求クリア */

	/*
	 *  カウンタ加算通知処理実行
	 */
	ercd = SignalCounter( SampleCnt );

	/* エラーリターンの場合はシャットダウン	*/
	if( ercd != E_OK ){
		ShutdownOS( ercd );
	}
}	/* ISR( CounterInt )	*/


/*
 *  ISR1・ISR2稼動確認用
 *
 *  7058 では ATU channel 8A, 8E で実装する．
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
	/*
	 *  ハードウェアカウンタ初期化
	 */
	hw_cnt1 = (UINT8)0;
	hw_cnt2 = (UINT8)0;

	/*
	 *  タイマを停止して各レジスタ設定
	 */
	P_ATUII.PSCR1.BYTE = 0;			/* ATU プリスケーラ Pφ/1 */
									/* ATU 共通なので、sys_initialize() でセットすべき */
	P_ATUII8.DSTR.BIT.DST8A = 0;		/* ダウンカウント停止 */
	P_ATUII8.DSTR.BIT.DST8E = 0;
	P_ATUII8.TCNR.BIT.CN8A = 0;		/* タイマコネクション 無効 */
	P_ATUII8.TCNR.BIT.CN8E = 0;
	P_ATUII8.OTR.BIT.OTEA = 0;		/* Output terminate 無効 */
	P_ATUII8.OTR.BIT.OTEE = 0;
	P_ATUII8.RLDENR.BIT.RLDEN = 0;	/* Reload 無効 */
	
	/*
	 *  タイマチャネル8A-H   1/32分周
	 */
	P_ATUII8.TCR8.BIT.CKSELA = 5;		
	

	/*
	 *  ダウンカウンタ設定
	 */
	P_ATUII8.DCNT8A = CFG_HW_CNT1;
	P_ATUII8.DCNT8E = CFG_HW_CNT2;

	/*
	 *  タイマコンペア割込みレベル設定（設定レベルはヘッダ参照）
	 *  TSR の bit0,1 が割込み要求フラグによりクリアしている．
	 */
	P_INTC.IPRH.BIT.ATU81 = CFG_INTLVL_HW_CNT1;
	P_INTC.IPRH.BIT.ATU82 = CFG_INTLVL_HW_CNT2;
	P_ATUII8.TSR8.BIT.OSF8A  = 0;
	P_ATUII8.TSR8.BIT.OSF8E = 0;

	/*
	 * 割込み許可 A,E
	 */
	P_ATUII8.TIER8.BIT.OSE8A = 1;
	P_ATUII8.TIER8.BIT.OSE8E = 1;

	/*
	 *  タイマカウント開始
	 */
	P_ATUII8.DSTR.BIT.DST8A = 1;
	P_ATUII8.DSTR.BIT.DST8E = 1;

}	/* InitHwCntInt	*/

/*
 *  ISR1・ISR2カウンタ停止処理
 */
void
TermHwCntInt( void )
{
	P_ATUII8.TIER8.BIT.OSE8A = 0;	/* 割り込み禁止 */
	P_ATUII8.TIER8.BIT.OSE8E = 0;
	P_ATUII8.DSTR.BIT.DST8A = 0;	/* ダウンカウント停止 */
	P_ATUII8.DSTR.BIT.DST8E = 0;
}	/* TermHwCntInt	*/

/*
 *  ISR1・ISR2カウンタ取得処理
 *
 *  hw_cnt1とhw_cnt2の同時取得は保障しなくてよい（割込み禁止は不要）．
 */
void
GetHwCnt( UINT8 *isr1_cnt, UINT8 *isr2_cnt )
{
	*isr1_cnt = hw_cnt1;
	*isr2_cnt = hw_cnt2;
}	/* GetHwCnt	*/

/*
 *  ISR1カウンタ加算用割込みサービスルーチン
 */
#if defined( OMIT_ISR1_ENTRY )
/* ISR1入り口未生成時は本関数を割込み関数指定する	*/
#pragma interrupt	HwCnt1Int
#endif	/* OMIT_ISR1_ENTRY	*/
void	HwCnt1Int( void );
void
HwCnt1Int( void )
{
	/* 割込み要求クリア */
	P_ATUII8.DCNT8A = CFG_HW_CNT1;
	P_ATUII8.TSR8.BIT.OSF8A  = 0;
	P_ATUII8.DSTR.BIT.DST8A = 1;

	hw_cnt1++;
}	/* HwCnt1Int	*/

/*
 *  ISR2カウンタ加算用割込みサービスルーチン
 */
ISR( HwCnt2Int )
{
	/* 割込み要求クリア */
	P_ATUII8.DCNT8E = CFG_HW_CNT2;
	P_ATUII8.TSR8.BIT.OSF8E  = 0;
	P_ATUII8.DSTR.BIT.DST8E = 1;

	hw_cnt2++;
}	/* ISR( HwCnt2Int )	*/


