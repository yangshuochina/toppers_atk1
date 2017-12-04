/*
 *  TOPPERS/OSEK Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      OSEK Kernel
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
 *	サンプル向けターゲット依存モジュール（OAKS32用）
 */


#include	"sample_config.h"
#include	"sfrm32c83.h"


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
 *  oaks32では周辺入力デバイスがないので，ポート10のbit0,bit1を
 *  プルアップ入力にて使用する．
 */
UINT8
GetAppModeInfo( void )
{
	/*
	 *  ポート10のbit0,bit1をプルアップ入力にする．
	 */
	PD10_0 = 0;
	PD10_1 = 0;
	PU30 = 1;

	/*
	 *  負論理で下位2bitを読込み
	 */
	return (UINT8)( (UINT8)(~P10) & (UINT8)( 0x03 ) );
}	/* GetAppModeInfo	*/


/*
 *  サンプルカウンタソース用
 *
 *  oaks32ではタイマA1で実装する．
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
	 *  タイマを停止して各レジスタ設定
	 */
	TA1S = 0;	/* カウント停止	*/

	/*
	 *  タイマA1ダウンカウント, タイマモード, カウントソースf1
	 */
	TA1UD = (UINT8)( 0 );
	TA1MR = (UINT8)( 0 );

	/*
	 *  タイマ起動直後にコンペアさせたいので，最低値を設定する．
	 */
	TA1 = (UINT16)( 1 );

}	/* InitCounterInt	*/

/*
 *  SignalCounter実行用割込み停止処理
 */
void
TermCounterInt( void )
{
	TA1IC = (UINT8)( 0 );	/* 割込みマスク			*/
	TA1S = 0;				/* タイマA1カウント停止	*/
}	/* TermCounterInt	*/

/*
 *  SignalCounter実行用割込み起動処理
 */
void
ActCounterInt( void )
{
	/*
	 *  タイマコンペア割込みレベル設定（設定レベルはヘッダ参照）
	 *  TA1IC の bit3 が割込み要求フラグであり，同時にクリアしている．
	 */
	TA1IC = CFG_INTLVL_COUNTER;
	TA1S = 1;	/* タイマA1カウント開始	*/
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
	TA1IC = (UINT8)( 0 );	/* 割込みマスク			*/
	TA1S = 0;				/* タイマA1カウント停止	*/
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
 *  oaks32ではタイマB0,B1で実装する．
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
	hw_cnt1 = (UINT8)( 0 );
	hw_cnt2 = (UINT8)( 0 );

	/*
	 *  タイマを停止して各レジスタ設定
	 */
	TB0S = 0;	/* カウント停止	*/
	TB1S = 0;	/* カウント停止	*/

	/*
	 *  タイマモード, カウントソースf1
	 */
	TB0MR = (UINT8)( 0 );
	TB1MR = (UINT8)( 0 );

	/*
	 *  ハードウェア仕様にてタイマソースのレジスタ設定値+1分周するため,
	 *  レジスタ設定値はシステムクロック周期に相当するカウント数から
	 *  マイナス1する値を設定する.（設定値はヘッダ参照）
	 */
	TB0 = CFG_HW_CNT1 - (UINT16)( 1 );
	TB1 = CFG_HW_CNT2 - (UINT16)( 1 );

	/*
	 *  タイマコンペア割込みレベル設定（設定レベルはヘッダ参照）
	 *  TB0IC, TB1IC の bit3 が割込み要求フラグであり，同時にクリアしている．
	 */
	TB0IC = CFG_INTLVL_HW_CNT1;
	TB1IC = CFG_INTLVL_HW_CNT2;

	TB0S = 1;	/* カウント開始	*/
	TB1S = 1;	/* カウント開始	*/
}	/* InitHwCntInt	*/

/*
 *  ISR1・ISR2カウンタ停止処理
 */
void
TermHwCntInt( void )
{
	TB0IC = (UINT8)( 0 );	/* 割込みマスク			*/
	TB1IC = (UINT8)( 0 );	/* 割込みマスク			*/
	TB0S = 0;				/* カウント停止			*/
	TB1S = 0;				/* カウント停止			*/
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
#pragma INTERRUPT	HwCnt1Int
#endif	/* OMIT_ISR1_ENTRY	*/
void	HwCnt1Int( void );
void
HwCnt1Int( void )
{
	hw_cnt1++;
}	/* HwCnt1Int	*/

/*
 *  ISR2カウンタ加算用割込みサービスルーチン
 */
ISR( HwCnt2Int )
{
	hw_cnt2++;
}	/* ISR( HwCnt2Int )	*/


