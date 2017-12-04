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
 *	サンプル向けターゲット依存システムタイマモジュール（SH2 HEW simDebug用）
 */


#include	"sample_config.h"


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
 */

/*
 *  SignalCounter実行用割込み初期化処理
 *
 *  タイマの起動は別関数で行う．
 */
void
InitCounterInt( void )
{
}	/* InitCounterInt	*/

/*
 *  SignalCounter実行用割込み停止処理
 */
void
TermCounterInt( void )
{
}	/* TermCounterInt	*/

/*
 *  SignalCounter実行用割込み起動処理
 */
void
ActCounterInt( void )
{
}	/* ActCounterInt	*/

/*
 *  SignalCounter実行用割込みサービスルーチン
 */
ISR( CounterInt )
{
	StatusType ercd;

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

}	/* InitHwCntInt	*/

/*
 *  ISR1・ISR2カウンタ停止処理
 */
void
TermHwCntInt( void )
{
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
	hw_cnt1++;
}	/* HwCnt1Int	*/

/*
 *  ISR2カウンタ加算用割込みサービスルーチン
 */
ISR( HwCnt2Int )
{
	hw_cnt2++;
}	/* ISR( HwCnt2Int )	*/


