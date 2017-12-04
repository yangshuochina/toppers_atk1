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
 *  SFRヘッダファイル（M32C/83用）
 */

#if !defined( _SFR_M32C_83_H_ )			/* 二重定義防止		*/
#define		_SFR_M32C_83_H_				/* 二重定義防止		*/


/*------------------------------------------------------
    Processor mode register 0
------------------------------------------------------*/
#pragma ADDRESS     pm0_addr	0004H       /* Processor mode register 0 */
typedef union {
	struct{
		UINT8	pm00:1;  /* プロセッサモード(pm00,pm01で指定)					*/
		UINT8	pm01:1;  /* 00B:シングルチップ,01B:メモリ拡張,11B:マ イクロプロセッサ		*/
		UINT8	pm02:1;  /* R/Wモード選択 0:~RD/~WD/~BHE,1:~RD/~WRH/~WRL			*/
		UINT8	pm03:1;  /* ソフトウェアリセット 0:通常時,1:リセット				*/
		UINT8	pm04:1;  /* マ ルチプレクスバス空間選択(pm04,pm05で指定)				*/
		UINT8	pm05:1;  /* 00B:未使用,01B:~CS2に割当て,10B:~CS1に割当て,11B:~CS全空間に割当て	*/
		UINT8	reserve:1;  /* 0固定								*/
		UINT8	pm07:1;  /* BCLK出力機能選択 0:BCLK出力,1:出力しない(CM00/CM01を00Bとすること)	*/
	} bit;
	UINT8 byte;
} PM0_ADDR;	/* リセット値:1000 0000B(CNVss端子がL)/0000 0011(CNVss端子がH)				*/
PM0_ADDR	pm0_addr;

#define		PM0     	pm0_addr.byte
#define		PM00        pm0_addr.bit.pm00     /* Processor mode bit */
#define		PM01        pm0_addr.bit.pm01     /* Processor mode bit */
#define		PM02        pm0_addr.bit.pm02     /* R/W mode select bit */
#define		PM03        pm0_addr.bit.pm03     /* Software reset bit */
#define		PM04        pm0_addr.bit.pm04     /* Multiplexed bus space select bit */
#define		PM05        pm0_addr.bit.pm05     /* Multiplexed bus space select bit */
#define		PM07        pm0_addr.bit.pm07     /* BCLK output function select bit */

/*------------------------------------------------------
    Processor mode register 1
------------------------------------------------------*/
#pragma ADDRESS     pm1_addr	0005H       /* Processor mode register 1 */
typedef union {
	struct{
		UINT8	pm10:1;  
		UINT8	pm11:1;  
		UINT8	pm12:1;  
		UINT8	pm13:1;  
		UINT8	pm14:1;  
		UINT8	pm15:1;  
		UINT8	pm16:1;  
		UINT8	pm17:1;  
	} bit;
	UINT8 byte;
} PM1_ADDR;
PM1_ADDR	pm1_addr;

#define		PM1    		pm1_addr.byte
#define		PM10        pm1_addr.bit.pm10     /* External memory area mode bit */
#define		PM11        pm1_addr.bit.pm11     /* External memory area mode bit */
#define		PM12        pm1_addr.bit.pm12     /* Internal memory wait bit */
#define		PM13        pm1_addr.bit.pm13     /* SFR wait bit */
#define		PM14        pm1_addr.bit.pm14     /* ALE pin select bit */
#define		PM15        pm1_addr.bit.pm15     /* ALE pin select bit */
#define		PM16        pm1_addr.bit.pm16    
#define		PM17		pm1_addr.bit.pm17		/* Reserved bit */

/*------------------------------------------------------
    System clock control register 0
------------------------------------------------------*/
#pragma ADDRESS     cm0_addr	0006H       /* System clock control register 0 */
typedef union {
	struct{
		UINT8	cm00:1;  
		UINT8	cm01:1;  
		UINT8	cm02:1;  
		UINT8	cm03:1;  
		UINT8	cm04:1;  
		UINT8	cm05:1;  
		UINT8  	cm06:1;
		UINT8	cm07:1;  
	} bit;
	UINT8 byte;
} CM0_ADDR;
CM0_ADDR	cm0_addr;

#define		CM0     	cm0_addr.byte
#define		CM00        cm0_addr.bit.cm00     /* Clock output function select bit */
#define		CM01        cm0_addr.bit.cm01     /* Clock output function select bit */
#define		CM02        cm0_addr.bit.cm02     /* WAIT peripheral function clock stop bit */
//#define     CM03        cm0_addr.bit.cm02     /* WAIT peripheral function clock stop bit */
#define		CM04        cm0_addr.bit.cm04     /* Port Xc select bit */
#define		CM05        cm0_addr.bit.cm05     /* Main clock stop bit */
#define		CM06        cm0_addr.bit.cm06     /* WDT function select bit */
#define		CM07        cm0_addr.bit.cm07     /* System clock select bit (Xin-Xout or Xcin-Xcout)*/

/*------------------------------------------------------
    System clock control register 1
------------------------------------------------------*/
#pragma ADDRESS     cm1_addr	0007H       /* System clock control register 1 */
typedef union {
	struct{
		UINT8	cm10:1;  
		UINT8	cm11:1;  
		UINT8	cm12:1;  
		UINT8	cm13:1;  
		UINT8	cm14:1;  
		UINT8	cm15:1;  
		UINT8	cm16:1;
		UINT8	cm17:1;  
	} bit;
	UINT8 byte;
} CM1_ADDR;		
CM1_ADDR	cm1_addr;

#define		CM1     	cm1_addr.byte
#define		CM10        cm1_addr.bit.cm10     /* All clock stop control bit */
#define		CM17		cm1_addr.bit.cm17		/* System clock select bit (Xin-Xout or PLL clock) */

/*------------------------------------------------------
    Wait control register
------------------------------------------------------*/
#pragma ADDRESS     wcr_addr	0008H       /* Wait control register */
typedef union {
	struct{
		UINT8	wcr00:1;  
		UINT8	wcr01:1;  
		UINT8	wcr02:1;  
		UINT8	wcr03:1;  
		UINT8	wcr04:1;  
		UINT8	wcr05:1;  
		UINT8  	wcr06:1;
		UINT8	wcr07:1;  
	} bit;
	UINT8 byte;
} WCR_ADDR;
WCR_ADDR	wcr_addr;

#define		WCR     	wcr_addr.byte
#define		WCR0        wcr_addr.bit.wcr00
#define		WCR1        wcr_addr.bit.wcr01
#define		WCR2        wcr_addr.bit.wcr02
#define		WCR3        wcr_addr.bit.wcr03
#define		WCR4        wcr_addr.bit.wcr04
#define		WCR5        wcr_addr.bit.wcr05
#define		WCR6        wcr_addr.bit.wcr06
#define		WCR7        wcr_addr.bit.wcr07

/*------------------------------------------------------
    Address match interrupt enable register
------------------------------------------------------*/
#pragma ADDRESS     aier_addr	0009H       /* Address match interrupt enable register */
typedef union {
	struct{
		UINT8	aier00:1;  
		UINT8	aier01:1;  
		UINT8	aier02:1;  
		UINT8	aier03:1;  
		UINT8	aier04:1;  
		UINT8	aier05:1;  
		UINT8  	aier06:1;
		UINT8	aier07:1;  
	} bit;
	UINT8 byte;
} AIER_ADDR;
AIER_ADDR	aier_addr;

#define		AIER        aier_addr.byte
#define		AIER0       aier_addr.bit.aier00    /* Address match interrupt 0 enable bit */
#define		AIER1       aier_addr.bit.aier01    /* Address match interrupt 1 enable bit */
#define		AIER2       aier_addr.bit.aier02    /* Address match interrupt 2 enable bit */  /*99.08.30*/
#define		AIER3       aier_addr.bit.aier03    /* Address match interrupt 3 enable bit */  /*99.08.30*/

/*------------------------------------------------------
    Protect register
------------------------------------------------------*/
#pragma ADDRESS     prcr_addr	000aH       /* Protect register */
typedef union {
	struct{
		UINT8	prcr00:1;  
		UINT8	prcr01:1;  
		UINT8	prcr02:1;  
		UINT8	prcr03:1;  
		UINT8	prcr04:1;  
		UINT8	prcr05:1;  
		UINT8  	prcr06:1;
		UINT8	prcr07:1;  
	} bit;
	UINT8 byte;
} PRCR_ADDR;
PRCR_ADDR	prcr_addr;

#define		PRCR        prcr_addr.byte
#define		PRC0        prcr_addr.bit.prcr00    /* Enables writing to system clock control register 0 and 1 */
#define		PRC1        prcr_addr.bit.prcr01    /* Enables writing to processor mode register 0 and 1 */
#define		PRC2        prcr_addr.bit.prcr02    /* Enables writing to port P9 direction register and function select register A3 */
#define		PRC3		prcr_addr.bit.prcr03	/* Enables writing VDC control register and PLL VDC control register */

/*------------------------------------------------------
    External data bus width control register
------------------------------------------------------*/
#pragma ADDRESS     ds_addr		000bH       /* External data bus width control register */
typedef union {
	struct{
		UINT8	ds00:1;  
		UINT8	ds01:1;  
		UINT8	ds02:1;  
		UINT8	ds03:1;  
		UINT8	ds04:1;  
		UINT8	ds05:1;  
		UINT8  	ds06:1;
		UINT8	ds07:1;  
	} bit;
	UINT8 byte;
} DS_ADDR;
DS_ADDR	ds_addr;

#define		DS      ds_addr.byte
#define		DS0     ds_addr.bit.ds00
#define		DS1     ds_addr.bit.ds01
#define		DS2     ds_addr.bit.ds02
#define		DS3     ds_addr.bit.ds03

/*------------------------------------------------------
    Main clock division register
------------------------------------------------------*/
#pragma ADDRESS     mcd_addr	000cH       /* Main clock division register */
typedef union {
	struct{
		UINT8	mcd00:1;  
		UINT8	mcd01:1;  
		UINT8	mcd02:1;  
		UINT8	mcd03:1;  
		UINT8	mcd04:1;  
		UINT8	mcd05:1;  
		UINT8  	mcd06:1;
		UINT8	mcd07:1;  
	} bit;
	UINT8 byte;
} MCD_ADDR;
MCD_ADDR	mcd_addr;

#define		MCD     	mcd_addr.byte
#define		MCD0        mcd_addr.bit.mcd00
#define		MCD1        mcd_addr.bit.mcd01
#define		MCD2        mcd_addr.bit.mcd02
#define		MCD3        mcd_addr.bit.mcd03
#define		MCD4        mcd_addr.bit.mcd04

/*------------------------------------------------------
    Oscillation stop detect register
------------------------------------------------------*/
#pragma ADDRESS     cm2_addr	000dH       /* Oscillation stop detect register */
typedef union {
	struct{
		UINT8	cm20:1;  
		UINT8	cm21:1;  
		UINT8	cm22:1;  
		UINT8	cm23:1;  
		UINT8	cm24:1;  
		UINT8	cm25:1;  
		UINT8  	cm26:1;
		UINT8	cm27:1;  
	} bit;
	UINT8 byte;
} CM2_ADDR;		
CM2_ADDR	cm2_addr;

#define		CM2     	cm2_addr.byte
#define		CM20        cm2_addr.bit.cm20     
#define		CM21        cm2_addr.bit.cm21     
#define		CM22        cm2_addr.bit.cm22     
#define		CM23        cm2_addr.bit.cm23     
#define		CM24        cm2_addr.bit.cm24     
#define		CM25        cm2_addr.bit.cm25     
#define		CM26        cm2_addr.bit.cm26     
#define		CM27        cm2_addr.bit.cm27     

/*------------------------------------------------------
    Watchdog timer start register
------------------------------------------------------*/
#pragma ADDRESS     wdts_addr	000eH       /* Watchdog timer start register */
typedef union {
	UINT8 byte;
} WDTS_ADDR;
WDTS_ADDR	wdts_addr;

#define		WDTS        wdts_addr.byte

/*------------------------------------------------------
    Watchdog timer control register
------------------------------------------------------*/
#pragma ADDRESS     wdc_addr	000fH       /* Watchdog timer control register */
typedef union {
	struct{
		UINT8	wdc00:1;  
		UINT8	wdc01:1;  
		UINT8	wdc02:1;  
		UINT8	wdc03:1;  
		UINT8	wdc04:1;  
		UINT8	wdc05:1;  
		UINT8  	wdc06:1;
		UINT8	wdc07:1;  
	} bit;
	UINT8 byte;
} WDC_ADDR;
WDC_ADDR	wdc_addr;

#define		WDC     wdc_addr.byte
//#define		WDC5		wdc_addr.bit.wdc05
//#define		WDC6		wdc_addr.bit.wdc06
#define		WDC7    wdc_addr.bit.wdc07     /* Prescaler select bit */

#pragma ADDRESS     rmad0_addr	0010H       /* Address match interrupt register 0 */
typedef union {
	struct{
        UINT8    rmad0_low;                /* low  8 bit */
        UINT8    rmad0_mid;                /* mid  8 bit */
        UINT8    rmad0_high;               /* high 8 bit */
        UINT8    rmad0_nc;                 /* non use */
    } byte;
    UINT32   dword;
} RMAD0_ADDR;
RMAD0_ADDR	rmad0_addr;

#define		RMAD0   rmad0_addr.dword        /* Address match interrupt register 0 32 bit */
#define		RMAD0L  rmad0_addr.byte.rmad0_low        /* Address match interrupt register 0 low  8 bit */
#define		RMAD0M  rmad0_addr.byte.rmad0_mid        /* Address match interrupt register 0 mid  8 bit */
#define		RMAD0H  rmad0_addr.byte.rmad0_high        /* Address match interrupt register 0 high 8 bit */

#pragma ADDRESS     rmad1_addr	0014H       /* Address match interrupt register 1 */
typedef union {
	struct{
        UINT8    rmad1_low;                /* low  8 bit */
        UINT8    rmad1_mid;                /* mid  8 bit */
        UINT8    rmad1_high;               /* high 8 bit */
        UINT8    rmad1_nc;                 /* non use */
    } byte;
    UINT32   dword;
} RMAD1_ADDR;
RMAD1_ADDR	rmad1_addr;

#define		RMAD1   rmad1_addr.dword        /* Address match interrupt register 1 32 bit */
#define		RMAD1L  rmad1_addr.byte.rmad1_low         /* Address match interrupt register 1 low  8 bit */
#define		RMAD1M  rmad1_addr.byte.rmad1_mid         /* Address match interrupt register 1 mid  8 bit */
#define		RMAD1H  rmad1_addr.byte.rmad1_high        /* Address match interrupt register 1 high 8 bit */

/*------------------------------------------------------
    PLL VDC control register
------------------------------------------------------*/
#pragma ADDRESS     plv_addr	0017H       /* PLL VDC control register */
typedef union {
	struct{
		UINT8	plv00:1;  
		UINT8	plv01:1;    
	} bit;
	UINT8 byte;
} PLV_ADDR;
PLV_ADDR	plv_addr;

#define		PLV     	plv_addr.byte
#define		PLV00		plv_addr.bit.plv00		
//#define	PLV01		plv_addr.bit.plv01

#pragma ADDRESS     rmad2_addr	0018H       /* Address match interrupt register 2 */
typedef union {
	struct{
        UINT8    rmad2_low;                /* low  8 bit */
        UINT8    rmad2_mid;                /* mid  8 bit */
        UINT8    rmad2_high;               /* high 8 bit */
        UINT8    rmad2_nc;                 /* non use */
    } byte;
    UINT32   dword;
} RMAD2_ADDR;
RMAD2_ADDR	rmad2_addr;

#define		RMAD2   rmad2_addr.dword        /* Address match interrupt register 2 32 bit */
#define		RMAD2L  rmad2_addr.byte.rmad2_low         /* Address match interrupt register 2 low  8 bit */
#define		RMAD2M  rmad2_addr.byte.rmad2_mid         /* Address match interrupt register 2 mid  8 bit */
#define		RMAD2H  rmad2_addr.byte.rmad2_high        /* Address match interrupt register 2 high 8 bit */

/*------------------------------------------------------
    VDC control  register 0
------------------------------------------------------*/
#pragma ADDRESS     vdc0_addr	001bH       /* VDC control register 0 */
typedef union {
	struct{
		UINT8	vdc00:1;  
		UINT8	vdc01:1;  
		UINT8	vdc02:1;  
		UINT8	vdc03:1;  
		UINT8	vdc04:1;  
		UINT8	vdc05:1;  
		UINT8  	vdc06:1;
		UINT8	vdc07:1;  
	} bit;
	UINT8 byte;
} VDC0_ADDR;
VDC0_ADDR	vdc0_addr;

#define		VDC0       vdc0_addr.byte
#define		VDC00     vdc0_addr.bit.vdc00
#define		VDC01     vdc0_addr.bit.vdc01
#define		VDC02     vdc0_addr.bit.vdc02
#define		VDC03     vdc0_addr.bit.vdc03
#define		VDC04     vdc0_addr.bit.vdc04
#define		VDC05     vdc0_addr.bit.vdc05
#define		VDC06     vdc0_addr.bit.vdc06
#define		VDC07     vdc0_addr.bit.vdc07

#pragma ADDRESS     rmad3_addr	001cH       /* Address match interrupt register 3 */
typedef union {
	struct{
        UINT8    rmad3_low;                /* low  8 bit */
        UINT8    rmad3_mid;                /* mid  8 bit */
        UINT8    rmad3_high;               /* high 8 bit */
        UINT8    rmad3_nc;                 /* non use */
    } byte;
    UINT32   dword;
} RMAD3_ADDR;
RMAD3_ADDR	rmad3_addr;

#define		RMAD3   rmad3_addr.dword        /* Address match interrupt register 3 32 bit */
#define		RMAD3L  rmad3_addr.byte.rmad3_low         /* Address match interrupt register 3 low  8 bit */
#define		RMAD3M  rmad3_addr.byte.rmad3_mid         /* Address match interrupt register 3 mid  8 bit */
#define		RMAD3H  rmad3_addr.byte.rmad3_high        /* Address match interrupt register 3 high 8 bit */

/*------------------------------------------------------
    VDC control  register 1
------------------------------------------------------*/
#pragma ADDRESS		vdc1_addr	001fH		/* VDC control register 1 */
typedef union {
	struct{
		UINT8	vdc10:1;  
		UINT8	vdc11:1;  
		UINT8	vdc12:1;  
		UINT8	vdc13:1;  
		UINT8	vdc14:1;  
		UINT8	vdc15:1;  
		UINT8  	vdc16:1;
		UINT8	vdc17:1;  
	} bit;
	UINT8 byte;
} VDC1_ADDR;
VDC1_ADDR	vdc1_addr;

#define		VDC1       vdc1_addr.byte
#define		VDC10     vdc1_addr.bit.vdc10
#define		VDC11     vdc1_addr.bit.vdc11
#define		VDC12     vdc1_addr.bit.vdc12
#define		VDC13     vdc1_addr.bit.vdc13
#define		VDC14     vdc1_addr.bit.vdc14
#define		VDC15     vdc1_addr.bit.vdc15
#define		VDC16     vdc1_addr.bit.vdc16
#define		VDC17     vdc1_addr.bit.vdc17

#pragma ADDRESS		eiad_addr	0020H		/* Emulator Exclusive Use Interrupt Register */
typedef union {
	struct{
        UINT8    eiad_low;                /* low  8 bit */
        UINT8    eiad_mid;                /* mid  8 bit */
        UINT8    eiad_high;               /* high 8 bit */
        UINT8    eiad_nc;                 /* non use */
    } byte;
    UINT32   dword;
} EIAD_ADDR;
EIAD_ADDR	eiad_addr;

#define		EIAD	eiad_addr.dword
#define		EIADL	eiad_addr.byte.eiad_low
#define		EIADM	eiad_addr.byte.eiad_mid
#define		EIADH	eiad_addr.byte.eiad_high

/*------------------------------------------------------
	Emulator Exclusive Use Interrupt
		Distinction Register
------------------------------------------------------*/
#pragma ADDRESS		eitd_addr	0023H		/* Emulator Exclusive Use Interrupt Distinction Register*/
typedef union {
	struct{
		UINT8	eitd0:1;
		UINT8	eitd1:1;
		UINT8	reserved:6;
	} bit;
	UINT8 byte;
} EITD_ADDR;
EITD_ADDR	eitd_addr;

#define		EITD       eitd_addr.byte
#define		EITD0     eitd_addr.bit.eitd0
#define		EITD1     eitd_addr.bit.eitd1

/*------------------------------------------------------
	Emulator Exclusive Use Protect Register
------------------------------------------------------*/
#pragma ADDRESS		eprr_addr	0024H		/* Emulator Exclusive Use Protect Register*/
typedef union {
	struct{
		UINT8 eprr0:1;
	} bit;
	UINT8 byte;
} EPRR_ADDR;
EPRR_ADDR	eprr_addr;

#define		EPRR       eprr_addr.byte
#define		EPRR0     eprr_addr.bit.eprr0

/*------------------------------------------------------
	Emulator Setting Register
------------------------------------------------------*/
#pragma ADDRESS		emu_addr	0025H		/* Emulator Setting Register*/
typedef union {
	struct{
		UINT8 emu0:1;
		UINT8 emu1:1;
		UINT8 emu2:1;
	} bit;
	UINT8 byte;
} EMU_ADDR;
EMU_ADDR	emu_addr;

#define		EMU       emu_addr.byte
#define		EMU0     emu_addr.bit.emu0
#define		EMU1     emu_addr.bit.emu1
#define		EMU2     emu_addr.bit.emu2

/*------------------------------------------------------
	ROM Area Setting Register
------------------------------------------------------*/
#pragma ADDRESS		roa_addr	0030H		/* ROM Area Setting Register*/
typedef union {
	struct{
		UINT8 roa0:1;
		UINT8 roa1:1;
		UINT8 roa2:1;
	} bit;
	UINT8 byte;
} ROA_ADDR;
ROA_ADDR	roa_addr;

#define		ROA       roa_addr.byte
#define		ROA0     roa_addr.bit.roa0
#define		ROA1     roa_addr.bit.roa1
#define		ROA2     roa_addr.bit.roa2

/*------------------------------------------------------
	Debugging Monitor Setting Register
------------------------------------------------------*/
#pragma ADDRESS		dba_addr	0031H		/* Debugging Monitor Setting Register*/
typedef union {
	UINT8 byte;
} DBA_ADDR;
DBA_ADDR	dba_addr;

#define		DBA       dba_addr.byte

/*------------------------------------------------------
	Expansion Area Setting Register 0
------------------------------------------------------*/
#pragma ADDRESS		exa0_addr	0032H		/* Expansion Area Setting Register 0*/
typedef union {
	struct{
		UINT8	exa00:1;  
		UINT8	exa01:1;  
		UINT8	exa02:1;  
		UINT8	exa03:1;  
		UINT8	exa04:1;  
		UINT8	exa05:1;  
		UINT8  	exa06:1;
		UINT8	exa07:1;  
	} bit;
	UINT8 byte;
} EXA0_ADDR;
EXA0_ADDR	exa0_addr;

#define		EXA0       exa0_addr.byte
#define		EXA00     exa0_addr.bit.exa00
#define		EXA01     exa0_addr.bit.exa01
#define		EXA02     exa0_addr.bit.exa02
#define		EXA03     exa0_addr.bit.exa03
#define		EXA04     exa0_addr.bit.exa04
#define		EXA05     exa0_addr.bit.exa05
#define		EXA06     exa0_addr.bit.exa06
#define		EXA07     exa0_addr.bit.exa07

/*------------------------------------------------------
	Expansion Area Setting Register 1
------------------------------------------------------*/
#pragma ADDRESS		exa1_addr	0033H		/* Expansion Area Setting Register 1*/
typedef union {
	struct{
		UINT8	exa10:1;  
		UINT8	exa11:1;  
		UINT8	exa12:1;  
		UINT8	exa13:1;  
		UINT8	exa14:1;  
		UINT8	exa15:1;  
		UINT8  	exa16:1;
		UINT8	exa17:1;  
	} bit;
	UINT8 byte;
} EXA1_ADDR;
EXA1_ADDR	exa1_addr;

#define		EXA1       exa1_addr.byte
#define		EXA10     exa1_addr.bit.exa10
#define		EXA11     exa1_addr.bit.exa11
#define		EXA12     exa1_addr.bit.exa12
#define		EXA13     exa1_addr.bit.exa13
#define		EXA14     exa1_addr.bit.exa14
#define		EXA15     exa1_addr.bit.exa15
#define		EXA16     exa1_addr.bit.exa16
#define		EXA17     exa1_addr.bit.exa17

/*------------------------------------------------------
	Expansion Area Setting Register 2
------------------------------------------------------*/
#pragma ADDRESS		exa2_addr	0034H		/* Expansion Area Setting Register 2*/
typedef union {
	struct{
		UINT8	exa20:1;  
		UINT8	exa21:1;  
		UINT8	exa22:1;  
		UINT8	exa23:1;  
		UINT8	exa24:1;  
		UINT8	exa25:1;  
		UINT8  	exa26:1;
		UINT8	exa27:1;  
	} bit;
	UINT8 byte;
} EXA2_ADDR;
EXA2_ADDR	exa2_addr;

#define		EXA2       exa2_addr.byte
#define		EXA20     exa2_addr.bit.exa20
#define		EXA21     exa2_addr.bit.exa21
#define		EXA22     exa2_addr.bit.exa22
#define		EXA23     exa2_addr.bit.exa23
#define		EXA24     exa2_addr.bit.exa24
#define		EXA25     exa2_addr.bit.exa25
#define		EXA26     exa2_addr.bit.exa26
#define		EXA27     exa2_addr.bit.exa27

/*------------------------------------------------------
	Expansion Area Setting Register 3
------------------------------------------------------*/
#pragma ADDRESS		exa3_addr	0035H		/* Expansion Area Setting Register 3*/
typedef union {
	struct{
		UINT8	exa30:1;  
		UINT8	exa31:1;  
		UINT8	exa32:1;  
		UINT8	exa33:1;  
		UINT8	exa34:1;  
		UINT8	exa35:1;  
		UINT8  	exa36:1;
		UINT8	exa37:1;  
	} bit;
	UINT8 byte;
} EXA3_ADDR;
EXA3_ADDR	exa3_addr;

#define		EXA3       exa3_addr.byte
#define		EXA30     exa3_addr.bit.exa30
#define		EXA31     exa3_addr.bit.exa31
#define		EXA32     exa3_addr.bit.exa32
#define		EXA33     exa3_addr.bit.exa33
#define		EXA34     exa3_addr.bit.exa34
#define		EXA35     exa3_addr.bit.exa35
#define		EXA36     exa3_addr.bit.exa36
#define		EXA37     exa3_addr.bit.exa37

/*------------------------------------------------------
    DRAM control register
------------------------------------------------------*/
#pragma ADDRESS     dramcont_addr    0040H  /* DRAM control register */
typedef union {
	struct{
/*UINT8*/UINT8	wt_dramcont:1;  
		UINT8	ar0_dramcont:1;  
		UINT8	ar1_dramcont:1;  
		UINT8	ar2_dramcont:1;  
		UINT8	b4:1;  
		UINT8	b5:1;  
		UINT8	b6:1;  
		UINT8	srff_dramcont:1;  
	} bit;
/*UINT8*/UINT8 byte;
} DRAMCONT_ADDR;	
DRAMCONT_ADDR	dramcont_addr;

#define		DRAMCONT         dramcont_addr.byte
#define		WT_DRAMCONT      dramcont_addr.bit.wt_dramcont
#define		AR0_DRAMCONT     dramcont_addr.bit.ar0_dramcont
#define		AR1_DRAMCONT     dramcont_addr.bit.ar1_dramcont
#define		AR2_DRAMCONT     dramcont_addr.bit.ar2_dramcont
#define		SREF_DRAMCONT    dramcont_addr.bit.srff_dramcont

/*------------------------------------------------------
    DRAM refresh interval set register
------------------------------------------------------*/
#pragma ADDRESS     refcnt_addr	0041H       /* DRAM refresh interval set register */
UINT8	refcnt_addr;

#define		REFCNT      refcnt_addr

/*------------------------------------------------------
    Flash Memory Control Register 2
------------------------------------------------------*/
#pragma ADDRESS		fmr2_addr	0055H		/* Flash Memory Control Register 2*/
typedef union {
	struct{
		UINT8	fmr20:1;  
		UINT8	fmr21:1;  
		UINT8	fmr22:1;  
	} bit;
UINT8 byte;
} FMR2_ADDR;	
FMR2_ADDR	fmr2_addr;

#define		FMR2      fmr2_addr.byte
#define		FMR20     fmr2_addr.bit.fmr20
#define		FMR22     fmr2_addr.bit.fmr22

/*------------------------------------------------------
    Flash Memory Control Register 1
------------------------------------------------------*/
#pragma ADDRESS		fmr1_addr	0056H		/* Flash Memory Control Register 2*/
typedef union {
	struct{
		UINT8	fmr10:1;  
		UINT8	fmr11:1;  
		UINT8	fmr12:1;  
		UINT8	fmr13:1;
		UINT8	fmr14:1;
		UINT8	fmr15:1;
	} bit;
UINT8 byte;
} FMR1_ADDR;
FMR1_ADDR	fmr1_addr;

#define		FMR1      fmr1_addr.byte
#define		FMR10     fmr1_addr.bit.fmr10
#define		FMR11     fmr1_addr.bit.fmr11
#define		FMR14     fmr1_addr.bit.fmr14
#define		FMR15     fmr1_addr.bit.fmr15

/*------------------------------------------------------
    Flash Memory Control Register 0
------------------------------------------------------*/
#pragma ADDRESS     fmr0_addr	0057H       /* Flash memory control register 0 */
typedef union {
	struct{
		UINT8	fmr00:1;  
		UINT8	fmr01:1;  
		UINT8	fmr02:1;  
		UINT8	fmr03:1;  
		UINT8	fmr04:1;  
		UINT8	fmr05:1;  
		UINT8	fmr06:1;  
		UINT8	fmr07:1;  
	} bit;
UINT8 byte;
} FMR0_ADDR;	
FMR0_ADDR	fmr0_addr;

#define		FMR0      fmr0_addr.byte
#define		FMR00     fmr0_addr.bit.fmr00
#define		FMR01     fmr0_addr.bit.fmr01
#define		FMR02     fmr0_addr.bit.fmr02
#define		FMR03     fmr0_addr.bit.fmr03
//#define   FMR04     fmr0_addr.bit.fmr04
//#define   FMR05     fmr0_addr.bit.fmr05
#define		FMR06     fmr0_addr.bit.fmr06
//#define   FMR07     fmr0_addr.bit.fmr07

/*------------------------------------------------------
     dm0ic
------------------------------------------------------*/
#pragma ADDRESS     dm0ic_addr	0068H       /* DMA0 interrupt control register */
typedef union {
    struct{
        UINT8    ilvl0_dm0ic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl1_dm0ic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl2_dm0ic:1;            /* Interrupt priority level select bit */
        UINT8    ir_dm0ic:1;               /* Interrupt request bit */
    } bit;
    UINT8    byte;
} DM0IC_ADDR;
DM0IC_ADDR	dm0ic_addr;

#define		DM0IC       dm0ic_addr.byte
#define		ILVL0_DM0IC dm0ic_addr.bit.ilvl0_dm0ic
#define		ILVL1_DM0IC	dm0ic_addr.bit.ilvl1_dm0ic
#define		ILVL2_DM0IC dm0ic_addr.bit.ilvl2_dm0ic
#define		IR_DM0IC    dm0ic_addr.bit.ir_dm0ic

/*------------------------------------------------------
     tb5ic
------------------------------------------------------*/
#pragma ADDRESS     tb5ic_addr  0069H       /* Timer B5 interrupt register */
typedef union {
    struct{
        UINT8    ilvl0_tb5ic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl1_tb5ic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl2_tb5ic:1;            /* Interrupt priority level select bit */
        UINT8    ir_tb5ic:1;               /* Interrupt request bit */
    } bit;
    UINT8    byte;
} TB5IC_ADDR;
TB5IC_ADDR	tb5ic_addr;

#define		TB5IC       tb5ic_addr.byte
#define		ILVL0_TB5IC tb5ic_addr.bit.ilvl0_tb5ic
#define		ILVL1_TB5IC tb5ic_addr.bit.ilvl1_tb5ic
#define		ILVL2_TB5IC tb5ic_addr.bit.ilvl2_tb5ic
#define		IR_TB5IC    tb5ic_addr.bit.ir_tb5ic

/*------------------------------------------------------
     dm2ic
------------------------------------------------------*/
#pragma ADDRESS     dm2ic_addr  006aH       /* DMA2 interrupt register */
typedef union {
    struct{
        UINT8    ilvl0_dm2ic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl1_dm2ic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl2_dm2ic:1;            /* Interrupt priority level select bit */
        UINT8    ir_dm2ic:1;               /* Interrupt request bit */
    } bit;
    UINT8    byte;
} DM2IC_ADDR;
DM2IC_ADDR	dm2ic_addr;


#define		DM2IC  		dm2ic_addr.byte    
#define		ILVL0_DM2IC    dm2ic_addr.bit.ilvl0_dm2ic
#define		ILVL1_DM2IC    dm2ic_addr.bit.ilvl1_dm2ic
#define		ILVL2_DM2IC    dm2ic_addr.bit.ilvl2_dm2ic
#define		IR_DM2IC    	dm2ic_addr.bit.ir_dm2ic

/*------------------------------------------------------
     s2ric
------------------------------------------------------*/
#pragma ADDRESS     s2ric_addr  006bH       /* UART2 receive/ack interrupt control register */
typedef union {
    struct{
        UINT8    ilvl0_s2ric:1;            /* Interrupt priority level select bit */
        UINT8    ilvl1_s2ric:1;            /* Interrupt priority level select bit */
        UINT8    ilvl2_s2ric:1;            /* Interrupt priority level select bit */
        UINT8    ir_s2ric:1;               /* Interrupt request bit */
    } bit;
    UINT8    byte;
} S2RIC_ADDR;
S2RIC_ADDR	s2ric_addr;

#define		S2RIC       	s2ric_addr.byte
#define		ILVL0_S2RIC 	s2ric_addr.bit.ilvl0_s2ric
#define		ILVL1_S2RIC 	s2ric_addr.bit.ilvl1_s2ric
#define		ILVL2_S2RIC 	s2ric_addr.bit.ilvl2_s2ric
#define		IR_S2RIC    	s2ric_addr.bit.ir_s2ric

/*------------------------------------------------------
     ta0ic
------------------------------------------------------*/
#pragma ADDRESS     ta0ic_addr  006cH       /* Timer A0 interrupt control register */
typedef union {
    struct{
        UINT8    ilvl0_ta0ic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl1_ta0ic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl2_ta0ic:1;            /* Interrupt priority level select bit */
        UINT8    ir_ta0ic:1;               /* Interrupt request bit */
    } bit;
    UINT8    byte;
} TA0IC_ADDR;
TA0IC_ADDR	ta0ic_addr;

#define		TA0IC      	ta0ic_addr.byte
#define		ILVL0_TA0IC ta0ic_addr.bit.ilvl0_ta0ic
#define		ILVL1_TA0IC ta0ic_addr.bit.ilvl1_ta0ic
#define		ILVL2_TA0IC ta0ic_addr.bit.ilvl2_ta0ic
#define		IR_TA0IC	ta0ic_addr.bit.ir_ta0ic

/*------------------------------------------------------
     s3ric
------------------------------------------------------*/
#pragma ADDRESS     s3ric_addr  006dH       /* UART3 receive/ack interrupt control register */
typedef union {
    struct{
        UINT8    ilvl0_s3ric:1;            /* Interrupt priority level select bit */
        UINT8    ilvl1_s3ric:1;            /* Interrupt priority level select bit */
        UINT8    ilvl2_s3ric:1;            /* Interrupt priority level select bit */
        UINT8    ir_s3ric:1;               /* Interrupt request bit */
    } bit;
    UINT8    byte;
} S3RIC_ADDR;
S3RIC_ADDR	s3ric_addr;

#define		S3RIC       s3ric_addr.byte
#define		ILVL0_S3RIC s3ric_addr.bit.ilvl0_s3ric
#define		ILVL1_S3RIC s3ric_addr.bit.ilvl1_s3ric
#define		ILVL2_S3RIC s3ric_addr.bit.ilvl2_s3ric
#define		IR_S3RIC    s3ric_addr.bit.ir_s3ric

/*------------------------------------------------------
     ta2ic
------------------------------------------------------*/
#pragma ADDRESS     ta2ic_addr  006eH       /* Timer A2 interrupt control register */
typedef union {
    struct{
        UINT8    ilvl0_ta2ic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl1_ta2ic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl2_ta2ic:1;            /* Interrupt priority level select bit */
        UINT8    ir_ta2ic:1;               /* Interrupt request bit */
    } bit;
    UINT8    byte;
} TA2IC_ADDR;
TA2IC_ADDR	ta2ic_addr;

#define		TA2IC      	ta2ic_addr.byte
#define		ILVL0_TA2IC ta2ic_addr.bit.ilvl0_ta2ic
#define		ILVL1_TA2IC ta2ic_addr.bit.ilvl1_ta2ic
#define		ILVL2_TA2IC ta2ic_addr.bit.ilvl2_ta2ic
#define		IR_TA2IC	ta2ic_addr.bit.ir_ta2ic

/*------------------------------------------------------
     s4ric
------------------------------------------------------*/
#pragma ADDRESS     s4ric_addr  006fH       /* UART4 receive/ack interrupt control register */
typedef union {
    struct{
        UINT8    ilvl0_s4ric:1;            /* Interrupt priority level select bit */
        UINT8    ilvl1_s4ric:1;            /* Interrupt priority level select bit */
        UINT8    ilvl2_s4ric:1;            /* Interrupt priority level select bit */
        UINT8    ir_s4ric:1;               /* Interrupt request bit */
    } bit;
    UINT8    byte;
} S4RIC_ADDR;
S4RIC_ADDR	s4ric_addr;

#define		S4RIC       s4ric_addr.byte
#define		ILVL0_S4RIC s4ric_addr.bit.ilvl0_s4ric
#define		ILVL1_S4RIC s4ric_addr.bit.ilvl1_s4ric
#define		ILVL2_S4RIC s4ric_addr.bit.ilvl2_s4ric
#define		IR_S4RIC    s4ric_addr.bit.ir_s4ric

/*------------------------------------------------------
     ta4ic
------------------------------------------------------*/
#pragma ADDRESS     ta4ic_addr  0070H       /* Timer A4 interrupt control register */
typedef union {
    struct{
        UINT8    ilvl0_ta4ic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl1_ta4ic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl2_ta4ic:1;            /* Interrupt priority level select bit */
        UINT8    ir_ta4ic:1;               /* Interrupt request bit */
    } bit;
    UINT8    byte;
} TA4IC_ADDR;
TA4IC_ADDR	ta4ic_addr;

#define		TA4IC      		ta4ic_addr.byte
#define		ILVL0_TA4IC 	ta4ic_addr.bit.ilvl0_ta4ic
#define		ILVL1_TA4IC 	ta4ic_addr.bit.ilvl1_ta4ic
#define		ILVL2_TA4IC 	ta4ic_addr.bit.ilvl2_ta4ic
#define		IR_TA4IC		ta4ic_addr.bit.ir_ta4ic

/*------------------------------------------------------
     bcn0ic
------------------------------------------------------*/
#pragma ADDRESS		bcn0ic_addr 0071H		/* Bus collision (UART0) interrupt control register */
typedef union {
    struct{
        UINT8    ilvl0_bcn0ic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl1_bcn0ic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl2_bcn0ic:1;            /* Interrupt priority level select bit */
        UINT8    ir_bcn0ic:1;               /* Interrupt request bit */
    } bit;
    UINT8    byte;
} BCN0IC_ADDR;
BCN0IC_ADDR	bcn0ic_addr;

#define		BCN0IC       	 bcn0ic_addr.byte
#define		ILVL0_BCN0IC 	 bcn0ic_addr.bit.ilvl0_bcn0ic
#define		ILVL1_BCN0IC	 bcn0ic_addr.bit.ilvl1_bcn0ic
#define		ILVL2_BCN0IC 	 bcn0ic_addr.bit.ilvl2_bcn0ic
#define		IR_BCN0IC    	 bcn0ic_addr.bit.ir_bcn0ic

/*------------------------------------------------------
     bcn3ic
------------------------------------------------------*/
#pragma ADDRESS     bcn3ic_addr 0071H       /* Bus collision (UART3) interrupt control register */
typedef union {
    struct{
        UINT8    ilvl0_bcn3ic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl1_bcn3ic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl2_bcn3ic:1;            /* Interrupt priority level select bit */
        UINT8    ir_bcn3ic:1;               /* Interrupt request bit */
    } bit;
    UINT8    byte;
} BCN3IC_ADDR;
BCN3IC_ADDR	bcn3ic_addr;

#define		BCN3IC       	 bcn3ic_addr.byte
#define		ILVL0_BCN3IC 	 bcn3ic_addr.bit.ilvl0_bcn3ic
#define		ILVL1_BCN3IC	 bcn3ic_addr.bit.ilvl1_bcn3ic
#define		ILVL2_BCN3IC 	 bcn3ic_addr.bit.ilvl2_bcn3ic
#define		IR_BCN3IC    	 bcn3ic_addr.bit.ir_bcn3ic

/*------------------------------------------------------
     s0ric
------------------------------------------------------*/
#pragma ADDRESS     s0ric_addr  0072H       /* UART0 receive interrupt control register */
typedef union {
    struct{
        UINT8    ilvl0_s0ric:1;            /* Interrupt priority level select bit */
        UINT8    ilvl1_s0ric:1;            /* Interrupt priority level select bit */
        UINT8    ilvl2_s0ric:1;            /* Interrupt priority level select bit */
        UINT8    ir_s0ric:1;               /* Interrupt request bit */
    } bit;
    UINT8    byte;
} S0RIC_ADDR;
S0RIC_ADDR	s0ric_addr;

#define		S0RIC       	s0ric_addr.byte
#define		ILVL0_S0RIC 	s0ric_addr.bit.ilvl0_s0ric
#define		ILVL1_S0RIC 	s0ric_addr.bit.ilvl1_s0ric
#define		ILVL2_S0RIC 	s0ric_addr.bit.ilvl2_s0ric
#define		IR_S0RIC    	s0ric_addr.bit.ir_s0ric

/*------------------------------------------------------
     ad0ic
------------------------------------------------------*/
#pragma ADDRESS     ad0ic_addr  0073H       /* A-D0 conversion interrupt control register */
typedef union {
    struct{
        UINT8    ilvl0_ad0ic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl1_ad0ic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl2_ad0ic:1;            /* Interrupt priority level select bit */
        UINT8    ir_ad0ic:1;               /* Interrupt request bit */
    } bit;
    UINT8    byte;
} AD0IC_ADDR;
AD0IC_ADDR	ad0ic_addr;

#define		AD0IC       	ad0ic_addr.byte
#define		ILVL0_AD0IC 	ad0ic_addr.bit.ilvl0_ad0ic
#define		ILVL1_AD0IC		ad0ic_addr.bit.ilvl1_ad0ic
#define		ILVL2_AD0IC 	ad0ic_addr.bit.ilvl2_ad0ic
#define		IR_AD0IC    	ad0ic_addr.bit.ir_ad0ic

/*------------------------------------------------------
     s1ric
------------------------------------------------------*/
#pragma ADDRESS     s1ric_addr  0074H       /* UART1 receive interrupt control register */
typedef union {
    struct{
        UINT8    ilvl0_s1ric:1;            /* Interrupt priority level select bit */
        UINT8    ilvl1_s1ric:1;            /* Interrupt priority level select bit */
        UINT8    ilvl2_s1ric:1;            /* Interrupt priority level select bit */
        UINT8    ir_s1ric:1;               /* Interrupt request bit */
    } bit;
    UINT8    byte;
} S1RIC_ADDR;
S1RIC_ADDR	s1ric_addr;

#define		S1RIC       	s1ric_addr.byte
#define		ILVL0_S1RIC 	s1ric_addr.bit.ilvl0_s1ric
#define		ILVL1_S1RIC 	s1ric_addr.bit.ilvl1_s1ric
#define		ILVL2_S1RIC 	s1ric_addr.bit.ilvl2_s1ric
#define		IR_S1RIC    	s1ric_addr.bit.ir_s1ric
/*------------------------------------------------------
     iio0ic
------------------------------------------------------*/
#pragma ADDRESS     iio0ic_addr 0075H       /* Intelligent I/O interrupt control register 0 */
typedef union {
    struct{
        UINT8    ilvl0_iio0ic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl1_iio0ic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl2_iio0ic:1;            /* Interrupt priority level select bit */
        UINT8    ir_iio0ic:1;               /* Interrupt request bit */
    } bit;
    UINT8    byte;
} IIO0IC_ADDR;
IIO0IC_ADDR	iio0ic_addr;

#define		IIO0IC       iio0ic_addr.byte
#define		ILVL0_IIO0IC iio0ic_addr.bit.ilvl0_iio0ic
#define		ILVL1_IIO0IC iio0ic_addr.bit.ilvl1_iio0ic
#define		ILVL2_IIO0IC iio0ic_addr.bit.ilvl2_iio0ic
#define		IR_IIO0IC    iio0ic_addr.bit.ir_iio0ic

/*------------------------------------------------------
     tb1ic
------------------------------------------------------*/
#pragma ADDRESS     tb1ic_addr  0076H       /* Timer B1 interrupt control register */
typedef union {
    struct{
        UINT8    ilvl0_tb1ic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl1_tb1ic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl2_tb1ic:1;            /* Interrupt priority level select bit */
        UINT8    ir_tb1ic:1;               /* Interrupt request bit */
    } bit;
    UINT8    byte;
} TB1IC_ADDR;
TB1IC_ADDR	tb1ic_addr;

#define		TB1IC       	tb1ic_addr.byte
#define		ILVL0_TB1IC 	tb1ic_addr.bit.ilvl0_tb1ic
#define		ILVL1_TB1IC 	tb1ic_addr.bit.ilvl1_tb1ic
#define		ILVL2_TB1IC 	tb1ic_addr.bit.ilvl2_tb1ic
#define		IR_TB1IC    	tb1ic_addr.bit.ir_tb1ic

/*------------------------------------------------------
     iio2ic
------------------------------------------------------*/
#pragma ADDRESS     iio2ic_addr 0077H       /* Intelligent I/O interrupt control register 2 */
typedef union {
    struct{
        UINT8    ilvl0_iio2ic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl1_iio2ic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl2_iio2ic:1;            /* Interrupt priority level select bit */
        UINT8    ir_iio2ic:1;               /* Interrupt request bit */
    } bit;
    UINT8    byte;
} IIO2IC_ADDR;
IIO2IC_ADDR	iio2ic_addr;

#define		IIO2IC       iio2ic_addr.byte
#define		ILVL0_IIO2IC iio2ic_addr.bit.ilvl0_iio2ic
#define		ILVL1_IIO2IC iio2ic_addr.bit.ilvl1_iio2ic
#define		ILVL2_IIO2IC iio2ic_addr.bit.ilvl2_iio2ic
#define		IR_IIO2IC    iio2ic_addr.bit.ir_iio2ic

/*------------------------------------------------------
     tb3ic
------------------------------------------------------*/
#pragma ADDRESS     tb3ic_addr  0078H       /* Timer B3 interrupt control register */
typedef union {
    struct{
        UINT8    ilvl0_tb3ic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl1_tb3ic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl2_tb3ic:1;            /* Interrupt priority level select bit */
        UINT8    ir_tb3ic:1;               /* Interrupt request bit */
    } bit;
    UINT8    byte;
} TB3IC_ADDR;
TB3IC_ADDR	tb3ic_addr;

#define		TB3IC       	tb3ic_addr.byte
#define		ILVL0_TB3IC 	tb3ic_addr.bit.ilvl0_tb3ic
#define		ILVL1_TB3IC 	tb3ic_addr.bit.ilvl1_tb3ic
#define		ILVL2_TB3IC 	tb3ic_addr.bit.ilvl2_tb3ic
#define		IR_TB3IC    	tb3ic_addr.bit.ir_tb3ic

/*------------------------------------------------------
     iio4ic
------------------------------------------------------*/
#pragma ADDRESS     iio4ic_addr 0079H       /* Intelligent I/O interrupt control register 4 */
typedef union {
    struct{
        UINT8    ilvl0_iio4ic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl1_iio4ic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl2_iio4ic:1;            /* Interrupt priority level select bit */
        UINT8    ir_iio4ic:1;               /* Interrupt request bit */
    } bit;
    UINT8    byte;
} IIO4IC_ADDR;
IIO4IC_ADDR	iio4ic_addr;

#define		IIO4IC       iio4ic_addr.byte
#define		ILVL0_IIO4IC iio4ic_addr.bit.ilvl0_iio4ic
#define		ILVL1_IIO4IC iio4ic_addr.bit.ilvl1_iio4ic
#define		ILVL2_IIO4IC iio4ic_addr.bit.ilvl2_iio4ic
#define		IR_IIO4IC    iio4ic_addr.bit.ir_iio4ic

/*------------------------------------------------------
     int5ic
------------------------------------------------------*/
#pragma ADDRESS     int5ic_addr 007aH       /* INT5~ interrupt control register */
typedef union {
    struct{
        UINT8    ilvl0_int5ic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl1_int5ic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl2_int5ic:1;            /* Interrupt priority level select bit */
        UINT8    ir_int5ic:1;               /* Interrupt request bit */
        UINT8    pol_int5ic:1;              /* Polarity select bit */
        UINT8    lvs_int5ic:1;
    } bit;
    UINT8    byte;
} INT5IC_ADDR;
INT5IC_ADDR	int5ic_addr;

#define		INT5IC      	int5ic_addr.byte
#define		ILVL0_INT5IC    int5ic_addr.bit.ilvl0_int5ic
#define		ILVL1_INT5IC    int5ic_addr.bit.ilvl1_int5ic
#define		ILVL2_INT5IC    int5ic_addr.bit.ilvl2_int5ic
#define		IR_INT5IC  		int5ic_addr.bit.ir_int5ic
#define		POL_INT5IC  	int5ic_addr.bit.pol_int5ic
#define		LVS_INT5IC  	int5ic_addr.bit.lvs_int5ic

/*------------------------------------------------------
     iio6ic
------------------------------------------------------*/
#pragma ADDRESS     iio6ic_addr 007bH       /* Intelligent I/O interrupt control register 6 */
typedef union {
    struct{
        UINT8    ilvl0_iio6ic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl1_iio6ic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl2_iio6ic:1;            /* Interrupt priority level select bit */
        UINT8    ir_iio6ic:1;               /* Interrupt request bit */
    } bit;
    UINT8    byte;
} IIO6IC_ADDR;
IIO6IC_ADDR	iio6ic_addr;

#define		IIO6IC       iio6ic_addr.byte
#define		ILVL0_IIO6IC iio6ic_addr.bit.ilvl0_iio6ic
#define		ILVL1_IIO6IC iio6ic_addr.bit.ilvl1_iio6ic
#define		ILVL2_IIO6IC iio6ic_addr.bit.ilvl2_iio6ic
#define		IR_IIO6IC    iio6ic_addr.bit.ir_iio6ic

/*------------------------------------------------------
     int3ic
------------------------------------------------------*/
#pragma ADDRESS     int3ic_addr 007cH       /* INT3~ interrupt control register */
typedef union {
    struct{
        UINT8    ilvl0_int3ic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl1_int3ic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl2_int3ic:1;            /* Interrupt priority level select bit */
        UINT8    ir_int3ic:1;               /* Interrupt request bit */
        UINT8    pol_int3ic:1;              /* Polarity select bit */
        UINT8    lvs_int3ic:1;
    } bit;
    UINT8    byte;
} INT3IC_ADDR;
INT3IC_ADDR	int3ic_addr;

#define		INT3IC      	int3ic_addr.byte
#define		ILVL0_INT3IC    int3ic_addr.bit.ilvl0_int3ic
#define		ILVL1_INT3IC    int3ic_addr.bit.ilvl1_int3ic
#define		ILVL2_INT3IC    int3ic_addr.bit.ilvl2_int3ic
#define		IR_INT3IC  		int3ic_addr.bit.ir_int3ic
#define		POL_INT3IC  	int3ic_addr.bit.pol_int3ic
#define		LVS_INT3IC  	int3ic_addr.bit.lvs_int3ic

/*------------------------------------------------------
     iio8ic
------------------------------------------------------*/
#pragma ADDRESS     iio8ic_addr 007dH       /* Intelligent I/O interrupt control register 8 */
typedef union {
    struct{
        UINT8    ilvl0_iio8ic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl1_iio8ic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl2_iio8ic:1;            /* Interrupt priority level select bit */
        UINT8    ir_iio8ic:1;               /* Interrupt request bit */
    } bit;
    UINT8    byte;
} IIO8IC_ADDR;
IIO8IC_ADDR	iio8ic_addr;

#define		IIO8IC       iio8ic_addr.byte
#define		ILVL0_IIO8IC iio8ic_addr.bit.ilvl0_iio8ic
#define		ILVL1_IIO8IC iio8ic_addr.bit.ilvl1_iio8ic
#define		ILVL2_IIO8IC iio8ic_addr.bit.ilvl2_iio8ic
#define		IR_IIO8IC    iio8ic_addr.bit.ir_iio8ic

/*------------------------------------------------------
     int1ic
------------------------------------------------------*/
#pragma ADDRESS     int1ic_addr 007eH       /* INT1~ interrupt control register */
typedef union {
    struct{
        UINT8    ilvl0_int1ic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl1_int1ic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl2_int1ic:1;            /* Interrupt priority level select bit */
        UINT8    ir_int1ic:1;               /* Interrupt request bit */
        UINT8    pol_int1ic:1;              /* Polarity select bit */
        UINT8    lvs_int1ic:1;
    } bit;
    UINT8    byte;
} INT1IC_ADDR;
INT1IC_ADDR	int1ic_addr;

#define		INT1IC      	int1ic_addr.byte
#define		ILVL0_INT1IC    int1ic_addr.bit.ilvl0_int1ic
#define		ILVL1_INT1IC    int1ic_addr.bit.ilvl1_int1ic
#define		ILVL2_INT1IC    int1ic_addr.bit.ilvl2_int1ic
#define		IR_INT1IC  		int1ic_addr.bit.ir_int1ic
#define		POL_INT1IC  	int1ic_addr.bit.pol_int1ic
#define		LVS_INT1IC  	int1ic_addr.bit.lvs_int1ic

/*------------------------------------------------------
     iio10ic
------------------------------------------------------*/
#pragma ADDRESS     iio10ic_addr 007fH      /* Intelligent I/O interrupt control register 10 */
typedef union {
    struct{
        UINT8    ilvl0_iio10ic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl1_iio10ic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl2_iio10ic:1;            /* Interrupt priority level select bit */
        UINT8    ir_iio10ic:1;               /* Interrupt request bit */
    } bit;
    UINT8    byte;
} IIO10IC_ADDR;
IIO10IC_ADDR	iio10ic_addr;

#define		IIO10IC       	iio10ic_addr.byte
#define		ILVL0_IIO10IC 	iio10ic_addr.bit.ilvl0_iio10ic
#define		ILVL1_IIO10IC 	iio10ic_addr.bit.ilvl1_iio10ic
#define		ILVL2_IIO10IC 	iio10ic_addr.bit.ilvl2_iio10ic
#define		IR_IIO10IC    	iio10ic_addr.bit.ir_iio10ic

/*------------------------------------------------------
     CAN1 Interrupt Control Register
------------------------------------------------------*/
#pragma ADDRESS		can1ic_addr 007fH		/* CAN1 Interrupt Control Register*/
typedef union {
    struct{
        UINT8    ilvl0_can1ic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl1_can1ic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl2_can1ic:1;            /* Interrupt priority level select bit */
        UINT8    ir_can1ic:1;               /* Interrupt request bit */
    } bit;
    UINT8    byte;
} CAN1IC_ADDR;
CAN1IC_ADDR	can1ic_addr;

#define		CAN1IC       	can1ic_addr.byte
#define		ILVL0_CAN1IC 	can1ic_addr.bit.ilvl0_can1ic
#define		ILVL1_CAN1IC 	can1ic_addr.bit.ilvl1_can1ic
#define		ILVL2_CAN1IC 	can1ic_addr.bit.ilvl2_can1ic
#define		IR_CAN1IC		can1ic_addr.bit.ir_can1ic

/*------------------------------------------------------
     iio11ic
------------------------------------------------------*/
#pragma ADDRESS     iio11ic_addr 0081H      /* Intelligent I/O interrupt control register 11 */
typedef union {
    struct{
        UINT8    ilvl0_iio11ic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl1_iio11ic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl2_iio11ic:1;            /* Interrupt priority level select bit */
        UINT8    ir_iio11ic:1;               /* Interrupt request bit */
    } bit;
    UINT8    byte;
} IIO11IC_ADDR;
IIO11IC_ADDR	iio11ic_addr;

#define		IIO11IC       	iio11ic_addr.byte
#define		ILVL0_IIO11IC 	iio11ic_addr.bit.ilvl0_iio11ic
#define		ILVL1_IIO11IC 	iio11ic_addr.bit.ilvl1_iio11ic
#define		ILVL2_IIO11IC 	iio11ic_addr.bit.ilvl2_iio11ic
#define		IR_IIO11IC    	iio11ic_addr.bit.ir_iio11ic

/*------------------------------------------------------
     CAN2 Interrupt Control Register
------------------------------------------------------*/
#pragma ADDRESS		can2ic_addr 0081H		/* CAN2 Interrupt Control Register*/
typedef union {
    struct{
        UINT8    ilvl0_can2ic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl1_can2ic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl2_can2ic:1;            /* Interrupt priority level select bit */
        UINT8    ir_can2ic:1;               /* Interrupt request bit */
    } bit;
    UINT8    byte;
} CAN2IC_ADDR;
CAN2IC_ADDR	can2ic_addr;

#define		CAN2IC       	can2ic_addr.byte
#define		ILVL0_CAN2IC 	can2ic_addr.bit.ilvl0_can2ic
#define		ILVL1_CAN2IC 	can2ic_addr.bit.ilvl1_can2ic
#define		ILVL2_CAN2IC 	can2ic_addr.bit.ilvl2_can2ic
#define		IR_CAN2IC		can2ic_addr.bit.ir_can2ic

/*------------------------------------------------------
     ad1ic
------------------------------------------------------*/
#pragma ADDRESS     ad1ic_addr  0086H       /* A-D1 conversion interrupt control register */
typedef union {
    struct{
        UINT8    ilvl0_ad1ic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl1_ad1ic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl2_ad1ic:1;            /* Interrupt priority level select bit */
        UINT8    ir_ad1ic:1;               /* Interrupt request bit */
    } bit;
    UINT8    byte;
} AD1IC_ADDR;
AD1IC_ADDR	ad1ic_addr;

#define		AD1IC       	ad1ic_addr.byte
#define		ILVL0_AD1IC 	ad1ic_addr.bit.ilvl0_ad1ic
#define		ILVL1_AD1IC		ad1ic_addr.bit.ilvl1_ad1ic
#define		ILVL2_AD1IC 	ad1ic_addr.bit.ilvl2_ad1ic
#define		IR_AD1IC    	ad1ic_addr.bit.ir_ad1ic

/*------------------------------------------------------
     dm1ic
------------------------------------------------------*/
#pragma ADDRESS     dm1ic_addr  0088H       /* DMA1 interrupt control register */
typedef union {
    struct{
        UINT8    ilvl0_dm1ic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl1_dm1ic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl2_dm1ic:1;            /* Interrupt priority level select bit */
        UINT8    ir_dm1ic:1;               /* Interrupt request bit */
    } bit;
    UINT8    byte;
} DM1IC_ADDR;
DM1IC_ADDR	dm1ic_addr;

#define		DM1IC  		dm1ic_addr.byte    
#define		ILVL0_DM1IC    dm1ic_addr.bit.ilvl0_dm1ic
#define		ILVL1_DM1IC    dm1ic_addr.bit.ilvl1_dm1ic
#define		ILVL2_DM1IC    dm1ic_addr.bit.ilvl2_dm1ic
#define		IR_DM1IC    	dm1ic_addr.bit.ir_dm1ic

/*------------------------------------------------------
     s2tic
------------------------------------------------------*/
#pragma ADDRESS     s2tic_addr  0089H       /* UART2 transmit/nack interrupt control register */
typedef union {
    struct{
        UINT8    ilvl0_s2tic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl1_s2tic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl2_s2tic:1;            /* Interrupt priority level select bit */
        UINT8    ir_s2tic:1;               /* Interrupt request bit */
    } bit;
    UINT8    byte;
} S2TIC_ADDR;
S2TIC_ADDR	s2tic_addr;

#define		S2TIC       	s2tic_addr.byte
#define		ILVL0_S2TIC 	s2tic_addr.bit.ilvl0_s2tic
#define		ILVL1_S2TIC 	s2tic_addr.bit.ilvl1_s2tic
#define		ILVL2_S2TIC 	s2tic_addr.bit.ilvl2_s2tic
#define		IR_S2TIC	 	s2tic_addr.bit.ir_s2tic

/*------------------------------------------------------
     dm3ic
------------------------------------------------------*/
#pragma ADDRESS     dm3ic_addr  008aH       /* DMA3 interrupt control register */
typedef union {
    struct{
        UINT8    ilvl0_dm3ic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl1_dm3ic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl2_dm3ic:1;            /* Interrupt priority level select bit */
        UINT8    ir_dm3ic:1;               /* Interrupt request bit */
    } bit;
    UINT8    byte;
} DM3IC_ADDR;
DM3IC_ADDR	dm3ic_addr;

#define		DM3IC  		dm3ic_addr.byte    
#define		ILVL0_DM3IC    dm3ic_addr.bit.ilvl0_dm3ic
#define		ILVL1_DM3IC    dm3ic_addr.bit.ilvl1_dm3ic
#define		ILVL2_DM3IC    dm3ic_addr.bit.ilvl2_dm3ic
#define		IR_DM3IC    	dm3ic_addr.bit.ir_dm3ic

/*------------------------------------------------------
     s3tic
------------------------------------------------------*/
#pragma ADDRESS     s3tic_addr  008bH       /* UART3 transmit/nack interrupt control register */
typedef union {
    struct{
        UINT8    ilvl0_s3tic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl1_s3tic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl2_s3tic:1;            /* Interrupt priority level select bit */
        UINT8    ir_s3tic:1;               /* Interrupt request bit */
    } bit;
    UINT8    byte;
} S3TIC_ADDR;
S3TIC_ADDR	s3tic_addr;

#define		S3TIC       	s3tic_addr.byte
#define		ILVL0_S3TIC 	s3tic_addr.bit.ilvl0_s3tic
#define		ILVL1_S3TIC 	s3tic_addr.bit.ilvl1_s3tic
#define		ILVL2_S3TIC 	s3tic_addr.bit.ilvl2_s3tic
#define		IR_S3TIC	 	s3tic_addr.bit.ir_s3tic

/*------------------------------------------------------
     ta1ic
------------------------------------------------------*/
#pragma ADDRESS     ta1ic_addr  008cH       /* Timer A1 interrupt control register */
typedef union {
    struct{
        UINT8    ilvl0_ta1ic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl1_ta1ic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl2_ta1ic:1;            /* Interrupt priority level select bit */
        UINT8    ir_ta1ic:1;               /* Interrupt request bit */
    } bit;
    UINT8    byte;
} TA1IC_ADDR;
TA1IC_ADDR	ta1ic_addr;

#define		TA1IC      	ta1ic_addr.byte
#define		ILVL0_TA1IC ta1ic_addr.bit.ilvl0_ta1ic
#define		ILVL1_TA1IC ta1ic_addr.bit.ilvl1_ta1ic
#define		ILVL2_TA1IC ta1ic_addr.bit.ilvl2_ta1ic
#define		IR_TA1IC	ta1ic_addr.bit.ir_ta1ic

/*------------------------------------------------------
     s4tic
------------------------------------------------------*/
#pragma ADDRESS     s4tic_addr  008dH       /* UART4 transmit/nack interrupt control register */
typedef union {
    struct{
        UINT8    ilvl0_s4tic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl1_s4tic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl2_s4tic:1;            /* Interrupt priority level select bit */
        UINT8    ir_s4tic:1;               /* Interrupt request bit */
    } bit;
    UINT8    byte;
} S4TIC_ADDR;
S4TIC_ADDR	s4tic_addr;

#define		S4TIC       	s4tic_addr.byte
#define		ILVL0_S4TIC 	s4tic_addr.bit.ilvl0_s4tic
#define		ILVL1_S4TIC 	s4tic_addr.bit.ilvl1_s4tic
#define		ILVL2_S4TIC 	s4tic_addr.bit.ilvl2_s4tic
#define		IR_S4TIC	 	s4tic_addr.bit.ir_s4tic

/*------------------------------------------------------
     ta3ic
------------------------------------------------------*/
#pragma ADDRESS     ta3ic_addr  008eH       /* Timer A3 interrupt control register */
typedef union {
    struct{
        UINT8    ilvl0_ta3ic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl1_ta3ic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl2_ta3ic:1;            /* Interrupt priority level select bit */
        UINT8    ir_ta3ic:1;               /* Interrupt request bit */
    } bit;
    UINT8    byte;
} TA3IC_ADDR;
TA3IC_ADDR	ta3ic_addr;

#define		TA3IC      	ta3ic_addr.byte
#define		ILVL0_TA3IC ta3ic_addr.bit.ilvl0_ta3ic
#define		ILVL1_TA3IC ta3ic_addr.bit.ilvl1_ta3ic
#define		ILVL2_TA3IC ta3ic_addr.bit.ilvl2_ta3ic
#define		IR_TA3IC	ta3ic_addr.bit.ir_ta3ic

/*------------------------------------------------------
     bcn2ic
------------------------------------------------------*/
#pragma ADDRESS     bcn2ic_addr 008fH       /* Bus collision (UART2) interrupt control register */
typedef union {
    struct{
        UINT8    ilvl0_bcn2ic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl1_bcn2ic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl2_bcn2ic:1;            /* Interrupt priority level select bit */
        UINT8    ir_bcn2ic:1;               /* Interrupt request bit */
    } bit;
    UINT8    byte;
} BCN2IC_ADDR;
BCN2IC_ADDR	bcn2ic_addr;

#define		BCN2IC       	 bcn2ic_addr.byte
#define		ILVL0_BCN2IC 	 bcn2ic_addr.bit.ilvl0_bcn2ic
#define		ILVL1_BCN2IC	 bcn2ic_addr.bit.ilvl1_bcn2ic
#define		ILVL2_BCN2IC 	 bcn2ic_addr.bit.ilvl2_bcn2ic
#define		IR_BCN2IC    	 bcn2ic_addr.bit.ir_bcn2ic

/*------------------------------------------------------
     s0tic
------------------------------------------------------*/
#pragma ADDRESS     s0tic_addr  0090H       /* UART0 transmit interrupt control register */
typedef union {
    struct{
        UINT8    ilvl0_s0tic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl1_s0tic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl2_s0tic:1;            /* Interrupt priority level select bit */
        UINT8    ir_s0tic:1;               /* Interrupt request bit */
    } bit;
    UINT8    byte;
} S0TIC_ADDR;
S0TIC_ADDR	s0tic_addr;

#define		S0TIC       	s0tic_addr.byte
#define		ILVL0_S0TIC 	s0tic_addr.bit.ilvl0_s0tic
#define		ILVL1_S0TIC 	s0tic_addr.bit.ilvl1_s0tic
#define		ILVL2_S0TIC 	s0tic_addr.bit.ilvl2_s0tic
#define		IR_S0TIC	 	s0tic_addr.bit.ir_s0tic

/*------------------------------------------------------
     bcn1ic
------------------------------------------------------*/
#pragma ADDRESS		bcn1ic_addr 0091H		/* Bus collision (UART1) interrupt control register*/
typedef union {
    struct{
        UINT8    ilvl0_bcn1ic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl1_bcn1ic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl2_bcn1ic:1;            /* Interrupt priority level select bit */
        UINT8    ir_bcn1ic:1;               /* Interrupt request bit */
    } bit;
    UINT8    byte;
} BCN1IC_ADDR;
BCN1IC_ADDR	bcn1ic_addr;

#define		BCN1IC       	 bcn1ic_addr.byte
#define		ILVL0_BCN1IC 	 bcn1ic_addr.bit.ilvl0_bcn1ic
#define		ILVL1_BCN1IC	 bcn1ic_addr.bit.ilvl1_bcn1ic
#define		ILVL2_BCN1IC 	 bcn1ic_addr.bit.ilvl2_bcn1ic
#define		IR_BCN1IC    	 bcn1ic_addr.bit.ir_bcn1ic

/*------------------------------------------------------
     bcn4ic
------------------------------------------------------*/
#pragma ADDRESS     bcn4ic_addr 0091H       /* Bus collision (UART4) interrupt control register */
typedef union {
    struct{
        UINT8    ilvl0_bcn4ic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl1_bcn4ic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl2_bcn4ic:1;            /* Interrupt priority level select bit */
        UINT8    ir_bcn4ic:1;               /* Interrupt request bit */
    } bit;
    UINT8    byte;
} BCN4IC_ADDR;
BCN4IC_ADDR	bcn4ic_addr;

#define		BCN4IC       	 bcn4ic_addr.byte
#define		ILVL0_BCN4IC 	 bcn4ic_addr.bit.ilvl0_bcn4ic
#define		ILVL1_BCN4IC	 bcn4ic_addr.bit.ilvl1_bcn4ic
#define		ILVL2_BCN4IC 	 bcn4ic_addr.bit.ilvl2_bcn4ic
#define		IR_BCN4IC    	 bcn4ic_addr.bit.ir_bcn4ic

/*------------------------------------------------------
     s1tic
------------------------------------------------------*/
#pragma ADDRESS     s1tic_addr  0092H       /* UART1 transmit interrupt control register */
typedef union {
    struct{
        UINT8    ilvl0_s1tic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl1_s1tic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl2_s1tic:1;            /* Interrupt priority level select bit */
        UINT8    ir_s1tic:1;               /* Interrupt request bit */
    } bit;
    UINT8    byte;
} S1TIC_ADDR;
S1TIC_ADDR	s1tic_addr;

#define		S1TIC       	s1tic_addr.byte
#define		ILVL0_S1TIC 	s1tic_addr.bit.ilvl0_s1tic
#define		ILVL1_S1TIC 	s1tic_addr.bit.ilvl1_s1tic
#define		ILVL2_S1TIC 	s1tic_addr.bit.ilvl2_s1tic
#define		IR_S1TIC	 	s1tic_addr.bit.ir_s1tic

/*------------------------------------------------------
     kupic
------------------------------------------------------*/
#pragma ADDRESS     kupic_addr  0093H       /* Key input interrupt control register */
typedef union {
    struct{
        UINT8    ilvl0_kupic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl1_kupic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl2_kupic:1;            /* Interrupt priority level select bit */
        UINT8    ir_kupic:1;               /* Interrupt request bit */
    } bit;
    UINT8    byte;
} KUPIC_ADDR;
KUPIC_ADDR	kupic_addr;

#define		KUPIC      	kupic_addr.byte
#define		ILVL0_KUPIC kupic_addr.bit.ilvl0_kupic
#define		ILVL1_KUPIC kupic_addr.bit.ilvl1_kupic
#define		ILVL2_KUPIC kupic_addr.bit.ilvl2_kupic
#define		IR_KUPIC	kupic_addr.bit.ir_kupic

/*------------------------------------------------------
     tb0ic
------------------------------------------------------*/
#pragma ADDRESS     tb0ic_addr  0094H       /* Timer B0 interrupt control register */
typedef union {
    struct{
        UINT8    ilvl0_tb0ic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl1_tb0ic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl2_tb0ic:1;            /* Interrupt priority level select bit */
        UINT8    ir_tb0ic:1;               /* Interrupt request bit */
    } bit;
    UINT8    byte;
} TB0IC_ADDR;
TB0IC_ADDR	tb0ic_addr;

#define		TB0IC       	tb0ic_addr.byte
#define		ILVL0_TB0IC 	tb0ic_addr.bit.ilvl0_tb0ic
#define		ILVL1_TB0IC 	tb0ic_addr.bit.ilvl1_tb0ic
#define		ILVL2_TB0IC 	tb0ic_addr.bit.ilvl2_tb0ic
#define		IR_TB0IC    	tb0ic_addr.bit.ir_tb0ic

/*------------------------------------------------------
     iio1ic
------------------------------------------------------*/
#pragma ADDRESS     iio1ic_addr 0095H       /* Intelligent I/O interrupt control register 1 */
typedef union {
    struct{
        UINT8    ilvl0_iio1ic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl1_iio1ic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl2_iio1ic:1;            /* Interrupt priority level select bit */
        UINT8    ir_iio1ic:1;               /* Interrupt request bit */
    } bit;
    UINT8    byte;
} IIO1IC_ADDR;
IIO1IC_ADDR	iio1ic_addr;

#define		IIO1IC       iio1ic_addr.byte
#define		ILVL0_IIO1IC iio1ic_addr.bit.ilvl0_iio1ic
#define		ILVL1_IIO1IC iio1ic_addr.bit.ilvl1_iio1ic
#define		ILVL2_IIO1IC iio1ic_addr.bit.ilvl2_iio1ic
#define		IR_IIO1IC    iio1ic_addr.bit.ir_iio1ic

/*------------------------------------------------------
     tb2ic
------------------------------------------------------*/
#pragma ADDRESS     tb2ic_addr  0096H       /* Timer B2 interrupt control register */
typedef union {
    struct{
        UINT8    ilvl0_tb2ic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl1_tb2ic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl2_tb2ic:1;            /* Interrupt priority level select bit */
        UINT8    ir_tb2ic:1;               /* Interrupt request bit */
    } bit;
    UINT8    byte;
} TB2IC_ADDR;
TB2IC_ADDR	tb2ic_addr;

#define		TB2IC       	tb2ic_addr.byte
#define		ILVL0_TB2IC 	tb2ic_addr.bit.ilvl0_tb2ic
#define		ILVL1_TB2IC 	tb2ic_addr.bit.ilvl1_tb2ic
#define		ILVL2_TB2IC 	tb2ic_addr.bit.ilvl2_tb2ic
#define		IR_TB2IC    	tb2ic_addr.bit.ir_tb2ic

/*------------------------------------------------------
     iio3ic
------------------------------------------------------*/
#pragma ADDRESS     iio3ic_addr 0097H       /* Intelligent I/O interrupt control register 3 */
typedef union {
    struct{
        UINT8    ilvl0_iio3ic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl1_iio3ic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl2_iio3ic:1;            /* Interrupt priority level select bit */
        UINT8    ir_iio3ic:1;               /* Interrupt request bit */
    } bit;
    UINT8    byte;
} IIO3IC_ADDR;
IIO3IC_ADDR	iio3ic_addr;

#define		IIO3IC       iio3ic_addr.byte
#define		ILVL0_IIO3IC iio3ic_addr.bit.ilvl0_iio3ic
#define		ILVL1_IIO3IC iio3ic_addr.bit.ilvl1_iio3ic
#define		ILVL2_IIO3IC iio3ic_addr.bit.ilvl2_iio3ic
#define		IR_IIO3IC    iio3ic_addr.bit.ir_iio3ic

/*------------------------------------------------------
     tb4ic
------------------------------------------------------*/
#pragma ADDRESS     tb4ic_addr  0098H       /* Timer B4 interrupt control register */
typedef union {
    struct{
        UINT8    ilvl0_tb4ic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl1_tb4ic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl2_tb4ic:1;            /* Interrupt priority level select bit */
        UINT8    ir_tb4ic:1;               /* Interrupt request bit */
    } bit;
    UINT8    byte;
} TB4IC_ADDR;
TB4IC_ADDR	tb4ic_addr;

#define		TB4IC       	tb4ic_addr.byte
#define		ILVL0_TB4IC 	tb4ic_addr.bit.ilvl0_tb4ic
#define		ILVL1_TB4IC 	tb4ic_addr.bit.ilvl1_tb4ic
#define		ILVL2_TB4IC 	tb4ic_addr.bit.ilvl2_tb4ic
#define		IR_TB4IC    	tb4ic_addr.bit.ir_tb4ic

/*------------------------------------------------------
     iio5ic
------------------------------------------------------*/
#pragma ADDRESS     iio5ic_addr 0099H       /* Intelligent I/O interrupt control register 5 */
typedef union {
    struct{
        UINT8    ilvl0_iio5ic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl1_iio5ic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl2_iio5ic:1;            /* Interrupt priority level select bit */
        UINT8    ir_iio5ic:1;               /* Interrupt request bit */
    } bit;
    UINT8    byte;
} IIO5IC_ADDR;
IIO5IC_ADDR	iio5ic_addr;

#define		IIO5IC       iio5ic_addr.byte
#define		ILVL0_IIO5IC iio5ic_addr.bit.ilvl0_iio5ic
#define		ILVL1_IIO5IC iio5ic_addr.bit.ilvl1_iio5ic
#define		ILVL2_IIO5IC iio5ic_addr.bit.ilvl2_iio5ic
#define		IR_IIO5IC    iio5ic_addr.bit.ir_iio5ic

/*------------------------------------------------------
     int4ic
------------------------------------------------------*/
#pragma ADDRESS     int4ic_addr 009aH       /* INT4~ interrupt control register */
typedef union {
    struct{
        UINT8    ilvl0_int4ic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl1_int4ic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl2_int4ic:1;            /* Interrupt priority level select bit */
        UINT8    ir_int4ic:1;               /* Interrupt request bit */
        UINT8    pol_int4ic:1;              /* Polarity select bit */
        UINT8    lvs_int4ic:1;
    } bit;
    UINT8    byte;
} INT4IC_ADDR;
INT4IC_ADDR	int4ic_addr;

#define		INT4IC      	int4ic_addr.byte
#define		ILVL0_INT4IC    int4ic_addr.bit.ilvl0_int4ic
#define		ILVL1_INT4IC    int4ic_addr.bit.ilvl1_int4ic
#define		ILVL2_INT4IC    int4ic_addr.bit.ilvl2_int4ic
#define		IR_INT4IC  		int4ic_addr.bit.ir_int4ic
#define		POL_INT4IC  	int4ic_addr.bit.pol_int4ic
#define		LVS_INT4IC  	int4ic_addr.bit.lvs_int4ic

/*------------------------------------------------------
     iio7ic
------------------------------------------------------*/
#pragma ADDRESS     iio7ic_addr 009bH       /* Intelligent I/O interrupt control register 7 */
typedef union {
    struct{
        UINT8    ilvl0_iio7ic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl1_iio7ic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl2_iio7ic:1;            /* Interrupt priority level select bit */
        UINT8    ir_iio7ic:1;               /* Interrupt request bit */
    } bit;
    UINT8    byte;
} IIO7IC_ADDR;
IIO7IC_ADDR	iio7ic_addr;

#define		IIO7IC       iio7ic_addr.byte
#define		ILVL0_IIO7IC iio7ic_addr.bit.ilvl0_iio7ic
#define		ILVL1_IIO7IC iio7ic_addr.bit.ilvl1_iio7ic
#define		ILVL2_IIO7IC iio7ic_addr.bit.ilvl2_iio7ic
#define		IR_IIO7IC    iio7ic_addr.bit.ir_iio7ic

/*------------------------------------------------------
     int2ic
------------------------------------------------------*/
#pragma ADDRESS     int2ic_addr 009cH       /* INT2~ interrupt control register */
typedef union {
    struct{
        UINT8    ilvl0_int2ic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl1_int2ic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl2_int2ic:1;            /* Interrupt priority level select bit */
        UINT8    ir_int2ic:1;               /* Interrupt request bit */
        UINT8    pol_int2ic:1;              /* Polarity select bit */
        UINT8    lvs_int2ic:1;
    } bit;
    UINT8    byte;
} INT2IC_ADDR;
INT2IC_ADDR	int2ic_addr;

#define		INT2IC      	int2ic_addr.byte
#define		ILVL0_INT2IC    int2ic_addr.bit.ilvl0_int2ic
#define		ILVL1_INT2IC    int2ic_addr.bit.ilvl1_int2ic
#define		ILVL2_INT2IC    int2ic_addr.bit.ilvl2_int2ic
#define		IR_INT2IC  		int2ic_addr.bit.ir_int2ic
#define		POL_INT2IC  	int2ic_addr.bit.pol_int2ic
#define		LVS_INT2IC  	int2ic_addr.bit.lvs_int2ic

/*------------------------------------------------------
     iio9ic
------------------------------------------------------*/
#pragma ADDRESS     iio9ic_addr 009dH       /* Intelligent I/O interrupt control register 9 */
typedef union {
    struct{
        UINT8    ilvl0_iio9ic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl1_iio9ic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl2_iio9ic:1;            /* Interrupt priority level select bit */
        UINT8    ir_iio9ic:1;               /* Interrupt request bit */
    } bit;
    UINT8    byte;
} IIO9IC_ADDR;
IIO9IC_ADDR	iio9ic_addr;

#define		IIO9IC       	iio9ic_addr.byte
#define		ILVL0_IIO9IC 	iio9ic_addr.bit.ilvl0_iio9ic
#define		ILVL1_IIO9IC 	iio9ic_addr.bit.ilvl1_iio9ic
#define		ILVL2_IIO9IC 	iio9ic_addr.bit.ilvl2_iio9ic
#define		IR_IIO9IC    	iio9ic_addr.bit.ir_iio9ic

/*------------------------------------------------------
     CAN0 Interrupt Control Register
------------------------------------------------------*/
#pragma ADDRESS		can0ic_addr 009dH		/* CAN0 Interrupt Control Register*/
typedef union {
    struct{
        UINT8    ilvl0_can0ic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl1_can0ic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl2_can0ic:1;            /* Interrupt priority level select bit */
        UINT8    ir_can0ic:1;               /* Interrupt request bit */
    } bit;
    UINT8    byte;
} CAN0IC_ADDR;
CAN0IC_ADDR	can0ic_addr;

#define		CAN0IC       	can0ic_addr.byte
#define		ILVL0_CAN0IC 	can0ic_addr.bit.ilvl0_can0ic
#define		ILVL1_CAN0IC 	can0ic_addr.bit.ilvl1_can0ic
#define		ILVL2_CAN0IC 	can0ic_addr.bit.ilvl2_can0ic
#define		IR_CAN0IC		can0ic_addr.bit.ir_can0ic

/*------------------------------------------------------
     int0ic
------------------------------------------------------*/
#pragma ADDRESS     int0ic_addr 009eH       /* INT0~ interrupt control register */
typedef union {
    struct{
        UINT8    ilvl0_int0ic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl1_int0ic:1;            /* Interrupt priority level select bit */
        UINT8    ilvl2_int0ic:1;            /* Interrupt priority level select bit */
        UINT8    ir_int0ic:1;               /* Interrupt request bit */
        UINT8    pol_int0ic:1;              /* Polarity select bit */
        UINT8    lvs_int0ic:1;
    } bit;
    UINT8    byte;
} INT0IC_ADDR;
INT0IC_ADDR	int0ic_addr;

#define		INT0IC      	int0ic_addr.byte
#define		ILVL0_INT0IC    int0ic_addr.bit.ilvl0_int0ic
#define		ILVL1_INT0IC    int0ic_addr.bit.ilvl1_int0ic
#define		ILVL2_INT0IC    int0ic_addr.bit.ilvl2_int0ic
#define		IR_INT0IC  		int0ic_addr.bit.ir_int0ic
#define		POL_INT0IC  	int0ic_addr.bit.pol_int0ic
#define		LVS_INT0IC  	int0ic_addr.bit.lvs_int0ic

/*------------------------------------------------------
    Exit priority register
------------------------------------------------------*/
#pragma ADDRESS     rlvl_addr   009fH       /* Exit priority register */
typedef union {
	struct{
		UINT8	rlvl0:1;  
		UINT8	rlvl1:1;  
		UINT8	rlvl2:1;  
		UINT8	fsit:1;  
		UINT8	b4:1;  
		UINT8	dmaii:1;  
		UINT8  	b6:1;
		UINT8	b7:1;  
	} bit;
	UINT8 byte;
} RLVL_ADDR;
RLVL_ADDR	rlvl_addr;

#define		RLVL        rlvl_addr.byte
#define		RLVL0       rlvl_addr.bit.rlvl0
#define		RLVL1       rlvl_addr.bit.rlvl1
#define		RLVL2       rlvl_addr.bit.rlvl2
#define		FSIT        rlvl_addr.bit.fsit
#define		DMAII		rlvl_addr.bit.dmaii
/*------------------------------------------------------
     iio0ir
------------------------------------------------------*/
#pragma ADDRESS     iio0ir_addr 00a0H       /* Interrupt request register 0 */
typedef union {
    struct{
        UINT8    bit0:1;
        UINT8    tm02r:1;
        UINT8    po13r:1;
 		UINT8    bit3:1;
        UINT8    g0rir:1;
        UINT8    sio0rr:1;        
    } bit;
    UINT8    byte;
} IIO0IR_ADDR;
IIO0IR_ADDR	iio0ir_addr;

#define		IIO0IR      iio0ir_addr.byte
#define		TM02R		iio0ir_addr.bit.tm02r	
#define		PO13R		iio0ir_addr.bit.po13r	
#define		G0RIR		iio0ir_addr.bit.g0rir	
#define		SIO0RR		iio0ir_addr.bit.sio0rr	

/*------------------------------------------------------
     iio1ir
------------------------------------------------------*/
#pragma ADDRESS     iio1ir_addr 00a1H       /* Interrupt request register 1 */
typedef union {
    struct{
        UINT8    bit0:1;
        UINT8    bit1:1;
 		UINT8    po14r:1;
        UINT8    bit3:1;
        UINT8    g0tor:1;
        UINT8    sio0tr:1;        
    } bit;
    UINT8    byte;
} IIO1IR_ADDR;
IIO1IR_ADDR	iio1ir_addr;

#define		IIO1IR      iio1ir_addr.byte
#define		TM00R		iio1ir_addr.bit.bit1	
#define		PO00R		iio1ir_addr.bit.bit1	
#define		PO14R		iio1ir_addr.bit.po14r	
#define		G0TOR		iio1ir_addr.bit.g0tor	
#define		SIO0TR		iio1ir_addr.bit.sio0tr	

/*------------------------------------------------------
     iio2ir
------------------------------------------------------*/
#pragma ADDRESS     iio2ir_addr 00a2H       /* Interrupt request register 2 */
typedef union {
    struct{
        UINT8    bit0:1;
        UINT8    bit1:1;
        UINT8    bit2:1;
 		UINT8    bit3:1;
        UINT8    g1rir:1;
        UINT8    sio1rr:1;        
    } bit;
    UINT8    byte;
} IIO2IR_ADDR;
IIO2IR_ADDR	iio2ir_addr;

#define		IIO2IR      iio2ir_addr.byte
#define		TM12R		iio2ir_addr.bit.bit2	
#define		PO12R		iio2ir_addr.bit.bit2	
#define		G1RIR		iio2ir_addr.bit.g1rir	
#define		SIO1RR		iio2ir_addr.bit.sio1rr	

/*------------------------------------------------------
     iio3ir
------------------------------------------------------*/
#pragma ADDRESS     iio3ir_addr 00a3H       /* Interrupt request register 3 */
typedef union {
    struct{
        UINT8    bit0:1;
        UINT8    tm03r:1;
 		UINT8    po10r:1;
        UINT8    po27r:1;
        UINT8    g1tor:1;
        UINT8    sio1tr:1;        
    } bit;
    UINT8    byte;
} IIO3IR_ADDR;
IIO3IR_ADDR	iio3ir_addr;

#define		IIO3IR      iio3ir_addr.byte
#define		TM03R		iio3ir_addr.bit.tm03r	
#define		PO10R		iio3ir_addr.bit.po10r	
#define		PO27R		iio3ir_addr.bit.po27r	
#define		G1TOR		iio3ir_addr.bit.g1tor	
#define		SIO1TR		iio3ir_addr.bit.sio1tr	

/*------------------------------------------------------
     iio4ir
------------------------------------------------------*/
#pragma ADDRESS     iio4ir_addr 00a4H       /* Interrupt request register 4 */
typedef union {
    struct{
        UINT8    b1:1;
        UINT8    bit1:1;
 		UINT8    bit2:1;
        UINT8    po32r:1;
        UINT8    bt1r:1;        
 		UINT8    bit5:1; 
        UINT8    srt1r:1;
        UINT8    srt0r:1;
    } bit;
    UINT8    byte;
} IIO4IR_ADDR;
IIO4IR_ADDR	iio4ir_addr;

#define		IIO4IR      iio4ir_addr.byte
#define		TM04R		iio4ir_addr.bit.bit1	
#define		PO04R		iio4ir_addr.bit.bit1	
#define		TM17R		iio4ir_addr.bit.bit2	
#define		PO17R		iio4ir_addr.bit.bit2	
#define		PO32R		iio4ir_addr.bit.po32r	
#define		BT1R		iio4ir_addr.bit.bt1r	
#define		SRT1R		iio4ir_addr.bit.srt1r	
#define		SRT0R		iio4ir_addr.bit.srt0r	
/*------------------------------------------------------
     iio5ir
------------------------------------------------------*/
#pragma ADDRESS     iio5ir_addr 00a5H       /* Interrupt request register 5 */
typedef union {
    struct{
        UINT8    bit0:1;
        UINT8    bit1:1;
 		UINT8    po21r:1;
        UINT8    po33r:1;
        UINT8    sio2rr:1;
    } bit;
    UINT8    byte;
} IIO5IR_ADDR;
IIO5IR_ADDR	iio5ir_addr;

#define		IIO5IR       iio5ir_addr.byte
#define		TM05R		iio5ir_addr.bit.bit1
#define		PO05R		iio5ir_addr.bit.bit1
#define		PO21R		iio5ir_addr.bit.po21r
#define		PO33R		iio5ir_addr.bit.po33r
#define		SIO2RR		iio5ir_addr.bit.sio2rr

/*------------------------------------------------------
     iio6ir
------------------------------------------------------*/
#pragma ADDRESS     iio6ir_addr 00a6H       /* Interrupt request register 6 */
typedef union {
    struct{
        UINT8    bit0:1;
        UINT8    tm06r:1;
 		UINT8    po20r:1;
        UINT8    po34r:1;
        UINT8    sio2tr:1;        
    } bit;
    UINT8    byte;
} IIO6IR_ADDR;
IIO6IR_ADDR	iio6ir_addr;

#define		IIO6IR      iio6ir_addr.byte
#define		TM06R		iio6ir_addr.bit.tm06r
#define		PO20R		iio6ir_addr.bit.po20r
#define		PO34R		iio6ir_addr.bit.po34r
#define		SIO2TR		iio6ir_addr.bit.sio2tr

/*------------------------------------------------------
     iio7ir
------------------------------------------------------*/
#pragma ADDRESS     iio7ir_addr 00a7H       /* Interrupt request register 7 */
typedef union {
    struct{
        UINT8    bit0:1;
        UINT8    tm07r:1;
 		UINT8    po22r:1;
        UINT8    po35r:1;
        UINT8    bt0r:1;
        UINT8    bit5:1;
        UINT8    bit6:1;
        UINT8    ie0r:1;        
    } bit;
    UINT8    byte;
} IIO7IR_ADDR;
IIO7IR_ADDR	iio7ir_addr;

#define		IIO7IR      iio7ir_addr.byte
#define		TM07R		iio7ir_addr.bit.tm07r
#define		PO22R		iio7ir_addr.bit.po22r
#define		PO35R		iio7ir_addr.bit.po35r
#define		BT0R		iio7ir_addr.bit.bt0r
#define		IE0R		iio7ir_addr.bit.ie0r

/*------------------------------------------------------
     iio8ir
------------------------------------------------------*/
#pragma ADDRESS     iio8ir_addr 00a8H       /* Interrupt request register 8 */
typedef union {
    struct{
        UINT8    bit0:1;
        UINT8    bit1:1;
 		UINT8    po23r:1;
        UINT8    po36r:1;
        UINT8    bt2r:1;
        UINT8    bit5:1;
        UINT8    ie2r:1;
        UINT8    ie1r:1;        
    } bit;
    UINT8    byte;
} IIO8IR_ADDR;
IIO8IR_ADDR	iio8ir_addr;

#define		IIO8IR       iio8ir_addr.byte
#define		TM11R		iio8ir_addr.bit.bit1
#define		PO11R		iio8ir_addr.bit.bit1
#define		PO23R		iio8ir_addr.bit.po23r
#define		PO36R		iio8ir_addr.bit.po36r
#define		BT2R			iio8ir_addr.bit.bt2r
#define		IE2R			iio8ir_addr.bit.ie2r
#define		IE1R			iio8ir_addr.bit.ie1r

/*------------------------------------------------------
     iio9ir
------------------------------------------------------*/
#pragma ADDRESS     iio9ir_addr 00a9H       /* Interrupt request register 9 */
typedef union {
    struct{
        UINT8    bit0:1;
        UINT8    po15r:1;
 		UINT8    po24r:1;
        UINT8    po31r:1;
        UINT8    sio3rr:1;
        UINT8    bit5:1;
        UINT8    bit6:1;
        UINT8    can0r:1;        
    } bit;
    UINT8    byte;
} IIO9IR_ADDR;
IIO9IR_ADDR	iio9ir_addr;

#define		IIO9IR      iio9ir_addr.byte
#define		PO15R		iio9ir_addr.bit.po15r
#define		PO24R		iio9ir_addr.bit.po24r
#define		PO31R		iio9ir_addr.bit.po31r
#define		SIO3RR		iio9ir_addr.bit.sio3rr
#define		CAN0R		iio9ir_addr.bit.can0r

/*------------------------------------------------------
     iio10ir
------------------------------------------------------*/
#pragma ADDRESS     iio10ir_addr 00aaH      /* Interrupt request register 10 */
typedef union {
    struct{
        UINT8    bit0:1;
        UINT8    bit1:1;
 		UINT8    po25r:1;
        UINT8    po30r:1;
        UINT8    sio3tr:1;
 		UINT8    bit5:1;
        UINT8    bit6r:1;
        UINT8    can1r:1;              
    } bit;
    UINT8    byte;
} IIO10IR_ADDR;
IIO10IR_ADDR	iio10ir_addr;

#define		IIO10IR    	iio10ir_addr.byte
#define		TM16R		iio10ir_addr.bit.bit1
#define		PO16R		iio10ir_addr.bit.bit1
#define		PO25R		iio10ir_addr.bit.po25r
#define		PO30R		iio10ir_addr.bit.po30r
#define		SIO3TR		iio10ir_addr.bit.sio3tr
#define		CAN1R		iio10ir_addr.bit.can1r

/*------------------------------------------------------
     iio11ir
------------------------------------------------------*/
#pragma ADDRESS     iio11ir_addr 00abH      /* Interrupt request register 11 */
typedef union {
    struct{
        UINT8    bit0:1;
        UINT8    bit1:1;
 		UINT8    po26r:1;
        UINT8    po37r:1;
        UINT8    bt3r:1;
        UINT8    hdlcr:1;        
        UINT8    bit6:1;
        UINT8    can2r:1;        
    } bit;
    UINT8    byte;
} IIO11IR_ADDR;
IIO11IR_ADDR	iio11ir_addr;

#define		IIO11IR     iio11ir_addr.byte
#define		TM01R		iio11ir_addr.bit.bit1
#define		PO01R		iio11ir_addr.bit.bit1
#define		PO26R		iio11ir_addr.bit.po26r
#define		PO37R		iio11ir_addr.bit.po37r
#define		BT3R		iio11ir_addr.bit.bt3r
#define		HDLCR		iio11ir_addr.bit.hdlcr
#define		CAN2R		iio11ir_addr.bit.can2r

/*------------------------------------------------------
     iio0ie
------------------------------------------------------*/
#pragma ADDRESS     iio0ie_addr 00b0H       /* Interrupt enable register 0 */
typedef union {
    struct{
        UINT8    irlt0e:1;
        UINT8    tm02e:1;
        UINT8    po13e:1;
        UINT8    bit3:1;
        UINT8    g0rie:1;
        UINT8    sio0re:1;
    } bit;
    UINT8    byte;
} IIO0IE_ADDR;
IIO0IE_ADDR	iio0ie_addr;

#define		IIO0IE  		iio0ie_addr.byte
#define		IRLT0E 			iio0ie_addr.bit.irlt0e
#define		TM02E			iio0ie_addr.bit.tm02e
#define		PO13E			iio0ie_addr.bit.po13e
#define		G0RIE			iio0ie_addr.bit.g0rie
#define		SIO0RE			iio0ie_addr.bit.sio0re

/*------------------------------------------------------
     iio1ie
------------------------------------------------------*/
#pragma ADDRESS     iio1ie_addr 00b1H       /* Interrupt enable register 1 */
typedef union {
    struct{
        UINT8    irlt1e:1;
        UINT8    bit1:1;
        UINT8    po14e:1;
        UINT8    bit3:1;
        UINT8    g0toe:1;
        UINT8    sio0te:1;
    } bit;
    UINT8    byte;
} IIO1IE_ADDR;
IIO1IE_ADDR	iio1ie_addr;

#define		IIO1IE     		iio1ie_addr.byte
#define		IRLT1E			iio1ie_addr.bit.irlt1e
#define		TM00E			iio1ie_addr.bit.bit1
#define		PO00E			iio1ie_addr.bit.bit1
#define		PO14E			iio1ie_addr.bit.po14e
#define		G0TOE			iio1ie_addr.bit.g0toe
#define		SIO0TE			iio1ie_addr.bit.sio0te

/*------------------------------------------------------
     iio2ie
------------------------------------------------------*/
#pragma ADDRESS     iio2ie_addr 00b2H       /* Interrupt enable register 2 */
typedef union {
    struct{
        UINT8    irlt2e:1;
        UINT8    bit1:1;
        UINT8    bit2:1;
        UINT8    bit3:1;
        UINT8    g1rie:1;
        UINT8    sio1re:1;
    } bit;
    UINT8    byte;
} IIO2IE_ADDR;
IIO2IE_ADDR	iio2ie_addr;

#define		IIO2IE   		iio2ie_addr.byte
#define		IRLT2E  		iio2ie_addr.bit.irlt2e
#define		TM12E			iio2ie_addr.bit.bit2
#define		PO12E			iio2ie_addr.bit.bit2
#define		G1RIE			iio2ie_addr.bit.g1rie
#define		SIO1RE			iio2ie_addr.bit.sio1re

/*------------------------------------------------------
     iio3ie
------------------------------------------------------*/
#pragma ADDRESS     iio3ie_addr 00b3H       /* Interrupt enable register 3 */
typedef union {
    struct{
        UINT8    irlt3e:1;
        UINT8    tm03e:1;
        UINT8    po10e:1;
        UINT8    po27e:1;
        UINT8    g1toe:1;
        UINT8    sio1te:1;
    } bit;
    UINT8    byte;
} IIO3IE_ADDR;
IIO3IE_ADDR	iio3ie_addr;

#define		IIO3IE	        iio3ie_addr.byte
#define		IRLT3E			iio3ie_addr.bit.irlt3e
#define		TM03E			iio3ie_addr.bit.tm03e
#define		PO10E			iio3ie_addr.bit.po10e
#define		PO27E			iio3ie_addr.bit.po27e
#define		G1TOE			iio3ie_addr.bit.g1toe
#define		SIO1TE			iio3ie_addr.bit.sio1te

/*------------------------------------------------------
     iio4ie
------------------------------------------------------*/
#pragma ADDRESS     iio4ie_addr 00b4H       /* Interrupt enable register 4 */
typedef union {
    struct{
        UINT8    irlt4e:1;
        UINT8    bit1:1;
        UINT8    bit2:1;
        UINT8    po32e:1;
        UINT8    bt1e:1;
        UINT8    bit5:1;
        UINT8    srt1e:1; 
        UINT8    srt0e:1;
    } bit;
    UINT8    byte;
} IIO4IE_ADDR;
IIO4IE_ADDR	iio4ie_addr;

#define		IIO4IE  	    iio4ie_addr.byte
#define		IRLT4E			iio4ie_addr.bit.irlt4e
#define		TM04E			iio4ie_addr.bit.bit1
#define		PO04E			iio4ie_addr.bit.bit1
#define		TM17E			iio4ie_addr.bit.bit2
#define		PO17E			iio4ie_addr.bit.bit2
#define		PO32E			iio4ie_addr.bit.po32e
#define		BT1E			iio4ie_addr.bit.bt1e
#define		SRT1E			iio4ie_addr.bit.srt1e
#define		SRT0E			iio4ie_addr.bit.srt0e

/*------------------------------------------------------
     iio5ie
------------------------------------------------------*/
#pragma ADDRESS     iio5ie_addr 00b5H       /* Interrupt enable register 5 */
typedef union {
    struct{
        UINT8    irlt5e:1;
        UINT8    bit1:1;
        UINT8    po21e:1;
        UINT8    po33e:1;
        UINT8    sio2re:1;
    } bit;
    UINT8    byte;
} IIO5IE_ADDR;
IIO5IE_ADDR	iio5ie_addr;

#define		IIO5IE   		iio5ie_addr.byte
#define		IRLT5E  		iio5ie_addr.bit.irlt5e
#define		TM05E			iio5ie_addr.bit.bit1
#define		PO05E			iio5ie_addr.bit.bit1
#define		PO21E			iio5ie_addr.bit.po21e
#define		PO33E			iio5ie_addr.bit.po33e
#define		SIO2RE			iio5ie_addr.bit.sio2re

/*------------------------------------------------------
     iio6ie
------------------------------------------------------*/
#pragma ADDRESS     iio6ie_addr 00b6H       /* Interrupt enable register 6 */
typedef union {
    struct{
        UINT8    irlt6e:1;
        UINT8    tm06e:1;
        UINT8    po20e:1;
        UINT8    po34e:1;
        UINT8    sio2te:1;
    } bit;
    UINT8    byte;
} IIO6IE_ADDR;
IIO6IE_ADDR	iio6ie_addr;

#define		IIO6IE   		iio6ie_addr.byte
#define		IRLT6E  		iio6ie_addr.bit.irlt6e
#define		TM06E			iio6ie_addr.bit.tm06e
#define		PO20E			iio6ie_addr.bit.po20e
#define		PO34E			iio6ie_addr.bit.po34e
#define		SIO2TE			iio6ie_addr.bit.sio2te

/*------------------------------------------------------
     iio7ie
------------------------------------------------------*/
#pragma ADDRESS     iio7ie_addr 00b7H       /* Interrupt enable register 7 */
typedef union {
    struct{
        UINT8    irlt7e:1;
        UINT8    tm07e:1;
        UINT8    po22e:1;
        UINT8    po35e:1;
        UINT8    bt0e:1;
        UINT8    bit5:1;
        UINT8    bit6:1; 
        UINT8    ie0e:1;
    } bit;
    UINT8    byte;
} IIO7IE_ADDR;
IIO7IE_ADDR	iio7ie_addr;

#define		IIO7IE       	iio7ie_addr.byte
#define		IRLT7E			iio7ie_addr.bit.irlt7e
#define		TM07E			iio7ie_addr.bit.tm07e
#define		PO22E			iio7ie_addr.bit.po22e
#define		PO35E			iio7ie_addr.bit.po35e
#define		BT0E			iio7ie_addr.bit.bt0e
#define		IE0E			iio7ie_addr.bit.ie0e

/*------------------------------------------------------
     iio8ie
------------------------------------------------------*/
#pragma ADDRESS     iio8ie_addr 00b8H       /* Interrupt enable register 8 */
typedef union {
    struct{
        UINT8    irlt8e:1;
        UINT8    bit1:1;
        UINT8    po23e:1;
        UINT8    po36e:1;
        UINT8    bt2e:1;
        UINT8    bit5:1;
        UINT8    ie2e:1; 
        UINT8    ie1e:1;
    } bit;
    UINT8    byte;
} IIO8IE_ADDR;
IIO8IE_ADDR	iio8ie_addr;

#define		IIO8IE      	iio8ie_addr.byte
#define		IRLT8E			iio8ie_addr.bit.irlt8e
#define		TM11E			iio8ie_addr.bit.bit1
#define		PO11E			iio8ie_addr.bit.bit1
#define		PO23E			iio8ie_addr.bit.po23e
#define		PO36E			iio8ie_addr.bit.po36e
#define		BT2E			iio8ie_addr.bit.bt2e
#define		IE2E			iio8ie_addr.bit.ie2e
#define		IE1E			iio8ie_addr.bit.ie1e

/*------------------------------------------------------
     iio9ie
------------------------------------------------------*/
#pragma ADDRESS     iio9ie_addr 00b9H       /* Interrupt enable register 9 */
typedef union {
    struct{
        UINT8    irlt9e:1;
        UINT8    po15e:1;
        UINT8    po24e:1;
        UINT8    po31e:1;
        UINT8    sio3re:1;
        UINT8    bit5:1;
        UINT8    bit6:1; 
        UINT8    can0e:1;
    } bit;
    UINT8    byte;
} IIO9IE_ADDR;
IIO9IE_ADDR	iio9ie_addr;

#define		IIO9IE			iio9ie_addr.byte
#define		IRLT9E			iio9ie_addr.bit.irlt9e
#define		PO15E			iio9ie_addr.bit.po15e
#define		PO24E			iio9ie_addr.bit.po24e
#define		PO31E			iio9ie_addr.bit.po31e
#define		SIO3RE			iio9ie_addr.bit.sio3re
#define		CAN0E			iio9ie_addr.bit.can0e

/*------------------------------------------------------
     iio10ie
------------------------------------------------------*/
#pragma ADDRESS     iio10ie_addr 00baH      /* Interrupt enable register 10 */
typedef union {
    struct{
        UINT8    irlt10e:1;
        UINT8    bit1:1;
        UINT8    po25e:1;
        UINT8    po30e:1;
        UINT8    sio3te:1;
        UINT8    bit5:1;
        UINT8    bit6:1; 
        UINT8    can1e:1;
    } bit;
    UINT8    byte;
} IIO10IE_ADDR;
IIO10IE_ADDR	iio10ie_addr;

#define		IIO10IE   		iio10ie_addr.byte
#define		IRLT10E			iio10ie_addr.bit.irlt10e
#define		TM16E			iio10ie_addr.bit.bit1
#define		PO16E			iio10ie_addr.bit.bit1
#define		PO25E			iio10ie_addr.bit.po25e
#define		PO30E			iio10ie_addr.bit.po30e
#define		SIO3TE			iio10ie_addr.bit.sio3te
#define		CAN1E			iio10ie_addr.bit.can1e

/*------------------------------------------------------
     iio11ie
------------------------------------------------------*/
#pragma ADDRESS     iio11ie_addr 00bbH      /* Interrupt enable register 11 */
typedef union {
    struct{
        UINT8    irlt11e:1;
        UINT8    bit1:1;
        UINT8    po26e:1;
        UINT8    po37e:1;
        UINT8    bt3e:1;
        UINT8    hdlce:1;
        UINT8    bit6:1; 
        UINT8    can2e:1;
    } bit;
    UINT8    byte;
} IIO11IE_ADDR;
IIO11IE_ADDR	iio11ie_addr;

#define		IIO11IE   		iio11ie_addr.byte
#define		IRLT11E			iio11ie_addr.bit.irlt11e
#define		TM01E			iio11ie_addr.bit.bit1
#define		PO01E			iio11ie_addr.bit.bit1
#define		PO26E			iio11ie_addr.bit.po26e
#define		PO37E			iio11ie_addr.bit.po37e
#define		BT3E			iio11ie_addr.bit.bt3e
#define		HDLCE			iio11ie_addr.bit.hdlce
#define		CAN2E			iio11ie_addr.bit.can2e

/*-------------------------------------------------*/
#pragma ADDRESS     g0tm0_addr  00c0H       /* Group 0 time measurement register 0 */
typedef union {
    struct{
        UINT8    g0tm0_low;                /* Low  8 bit */
        UINT8    g0tm0_high;               /* High 8 bit */
    } byte;
    UINT16  word;
} G0TM0_ADDR;
G0TM0_ADDR	g0tm0_addr;

#define		G0TM0        g0tm0_addr.word      /* Group 0 time measurement register 0 */
#define		G0TM0L       g0tm0_addr.byte.g0tm0_low
#define		G0TM0H       g0tm0_addr.byte.g0tm0_high

/*-------------------------------------------------*/
#pragma ADDRESS     g0po0_addr  00c0H       /* Group 0 waveform generate register 0 */
typedef union {
    struct{
        UINT8    g0po0_low;                /* Low  8 bit */
        UINT8    g0po0_high;               /* High 8 bit */
    } byte;
    UINT16  word;
} G0PO0_ADDR;
G0PO0_ADDR	g0po0_addr;

#define		G0PO0        g0po0_addr.word      /* Group 0 waveform generate register 0 */
#define		G0PO0L       g0po0_addr.byte.g0po0_low
#define		G0PO0H       g0po0_addr.byte.g0po0_high

/*-------------------------------------------------*/
#pragma ADDRESS     g0tm1_addr  00c2H       /* Group 0 time measurement register 1 */
typedef union {
    struct{
        UINT8    g0tm1_low;                /* Low  8 bit */
        UINT8    g0tm1_high;               /* High 8 bit */
    } byte;
    UINT16  word;
} G0TM1_ADDR;
G0TM1_ADDR	g0tm1_addr;

#define		G0TM1        g0tm1_addr.word      /* Group 0 time measurement register 1 */
#define		G0TM1L       g0tm1_addr.byte.g0tm1_low
#define		G0TM1H       g0tm1_addr.byte.g0tm1_high

/*-------------------------------------------------*/
#pragma ADDRESS     g0po1_addr  00c2H       /* Group 0 waveform generate register 1 */
typedef union {
    struct{
        UINT8    g0po1_low;                /* Low  8 bit */
        UINT8    g0po1_high;               /* High 8 bit */
    } byte;
    UINT16  word;
} G0PO1_ADDR;
G0PO1_ADDR	g0po1_addr;

#define		G0PO1        g0po1_addr.word      /* Group 0 waveform generate register 1 */
#define		G0PO1L       g0po1_addr.byte.g0po1_low
#define		G0PO1H       g0po1_addr.byte.g0po1_high

/*-------------------------------------------------*/
#pragma ADDRESS     g0tm2_addr  00c4H       /* Group 0 time measurement register 2 */
typedef union {
    struct{
        UINT8    g0tm2_low;                /* Low  8 bit */
        UINT8    g0tm2_high;               /* High 8 bit */
    } byte;
    UINT16  word;
} G0TM2_ADDR;
G0TM2_ADDR	g0tm2_addr;

#define		G0TM2        g0tm2_addr.word      /* Group 0 time measurement register 2 */
#define		G0TM2L       g0tm2_addr.byte.g0tm2_low
#define		G0TM2H       g0tm2_addr.byte.g0tm2_high

/*-------------------------------------------------*/
#pragma ADDRESS     g0po2_addr  00c4H       /* Group 0 waveform generate register 2 */
typedef union {
    struct{
        UINT8    g0po2_low;                /* Low  8 bit */
        UINT8    g0po2_high;               /* High 8 bit */
    } byte;
    UINT16  word;
} G0PO2_ADDR;
G0PO2_ADDR	g0po2_addr;

#define		G0PO2        g0po2_addr.word      /* Group 0 waveform generate register 2 */
#define		G0PO2L       g0po2_addr.byte.g0po2_low
#define		G0PO2H       g0po2_addr.byte.g0po2_high

/*-------------------------------------------------*/
#pragma ADDRESS     g0tm3_addr  00c6H       /* Group 0 time measurement register 3 */
typedef union {
    struct{
        UINT8    g0tm3_low;                /* Low  8 bit */
        UINT8    g0tm3_high;               /* High 8 bit */
    } byte;
    UINT16  word;
} G0TM3_ADDR;
G0TM3_ADDR	g0tm3_addr;

#define		G0TM3        g0tm3_addr.word      /* Group 0 time measurement register 3 */
#define		G0TM3L       g0tm3_addr.byte.g0tm3_low
#define		G0TM3H       g0tm3_addr.byte.g0tm3_high

/*-------------------------------------------------*/
#pragma ADDRESS     g0po3_addr  00c6H       /* Group 0 waveform generate register 3 */
typedef union {
    struct{
        UINT8    g0po3_low;                /* Low  8 bit */
        UINT8    g0po3_high;               /* High 8 bit */
    } byte;
    UINT16  word;
} G0PO3_ADDR;
G0PO3_ADDR	g0po3_addr;

#define		G0PO3        g0po3_addr.word      /* Group 0 waveform generate register 3 */
#define		G0PO3L       g0po3_addr.byte.g0po3_low
#define		G0PO3H       g0po3_addr.byte.g0po3_high

/*-------------------------------------------------*/
#pragma ADDRESS     g0tm4_addr  00c8H       /* Group 0 time measurement register 4 */
typedef union {
    struct{
        UINT8    g0tm4_low;                /* Low  8 bit */
        UINT8    g0tm4_high;               /* High 8 bit */
    } byte;
    UINT16  word;
} G0TM4_ADDR;
G0TM4_ADDR	g0tm4_addr;

#define		G0TM4        g0tm4_addr.word      /* Group 0 time measurement register 4 */
#define		G0TM4L       g0tm4_addr.byte.g0tm4_low
#define		G0TM4H       g0tm4_addr.byte.g0tm4_high

/*-------------------------------------------------*/
#pragma ADDRESS     g0po4_addr  00c8H       /* Group 0 waveform generate register 4 */
typedef union {
    struct{
        UINT8    g0po4_low;                /* Low  8 bit */
        UINT8    g0po4_high;               /* High 8 bit */
    } byte;
    UINT16  word;
} G0PO4_ADDR;
G0PO4_ADDR	g0po4_addr;

#define		G0PO4        g0po4_addr.word      /* Group 0 waveform generate register 4 */
#define		G0PO4L       g0po4_addr.byte.g0po4_low
#define		G0PO4H       g0po4_addr.byte.g0po4_high

/*-------------------------------------------------*/
#pragma ADDRESS     g0tm5_addr  00caH       /* Group 0 time measurement register 5 */
typedef union {
    struct{
        UINT8    g0tm5_low;                /* Low  8 bit */
        UINT8    g0tm5_high;               /* High 8 bit */
    } byte;
    UINT16  word;
} G0TM5_ADDR;
G0TM5_ADDR	g0tm5_addr;

#define		G0TM5        g0tm5_addr.word      /* Group 0 time measurement register 5 */
#define		G0TM5L       g0tm5_addr.byte.g0tm5_low
#define		G0TM5H       g0tm5_addr.byte.g0tm5_high

/*-------------------------------------------------*/
#pragma ADDRESS     g0po5_addr  00caH       /* Group 0 waveform generate register 5 */
typedef union {
    struct{
        UINT8    g0po5_low;                /* Low  8 bit */
        UINT8    g0po5_high;               /* High 8 bit */
    } byte;
    UINT16  word;
} G0PO5_ADDR;
G0PO5_ADDR	g0po5_addr;

#define		G0PO5        g0po5_addr.word      /* Group 0 waveform generate register 5 */
#define		G0PO5L       g0po5_addr.byte.g0po5_low
#define		G0PO5H       g0po5_addr.byte.g0po5_high

/*-------------------------------------------------*/
#pragma ADDRESS     g0tm6_addr  00ccH       /* Group 0 time measurement register 6 */
typedef union {
    struct{
        UINT8    g0tm6_low;                /* Low  8 bit */
        UINT8    g0tm6_high;               /* High 8 bit */
    } byte;
    UINT16  word;
} G0TM6_ADDR;
G0TM6_ADDR	g0tm6_addr;

#define		G0TM6        g0tm6_addr.word      /* Group 0 time measurement register 6 */
#define		G0TM6L       g0tm6_addr.byte.g0tm6_low
#define		G0TM6H       g0tm6_addr.byte.g0tm6_high

/*-------------------------------------------------*/
#pragma ADDRESS     g0po6_addr  00ccH       /* Group 0 waveform generate register 6 */
typedef union {
    struct{
        UINT8    g0po6_low;                /* Low  8 bit */
        UINT8    g0po6_high;               /* High 8 bit */
    } byte;
    UINT16  word;
} G0PO6_ADDR;
G0PO6_ADDR	g0po6_addr;

#define		G0PO6        g0po6_addr.word      /* Group 0 waveform generate register 6 */
#define		G0PO6L       g0po6_addr.byte.g0po6_low
#define		G0PO6H       g0po6_addr.byte.g0po6_high

/*-------------------------------------------------*/
#pragma ADDRESS     g0tm7_addr  00ceH       /* Group 0 time measurement register 7 */
typedef union {
    struct{
        UINT8    g0tm7_low;                /* Low  8 bit */
        UINT8    g0tm7_high;               /* High 8 bit */
    } byte;
    UINT16  word;
} G0TM7_ADDR;
G0TM7_ADDR	g0tm7_addr;

#define		G0TM7        g0tm7_addr.word      /* Group 0 time measurement register 7 */
#define		G0TM7L       g0tm7_addr.byte.g0tm7_low
#define		G0TM7H       g0tm7_addr.byte.g0tm7_high

/*-------------------------------------------------*/
#pragma ADDRESS     g0po7_addr  00ceH       /* Group 0 waveform generate register 7 */
typedef union {
    struct{
        UINT8    g0po7_low;                /* Low  8 bit */
        UINT8    g0po7_high;               /* High 8 bit */
    } byte;
    UINT16  word;
} G0PO7_ADDR;
G0PO7_ADDR	g0po7_addr;

#define		G0PO7        g0po7_addr.word      /* Group 0 waveform generate register 7 */
#define		G0PO7L       g0po7_addr.byte.g0po7_low
#define		G0PO7H       g0po7_addr.byte.g0po7_high

/*------------------------------------------------------
    Group 0 waveform generate control register 0
------------------------------------------------------*/
#pragma ADDRESS     g0pocr0_addr 00d0H      /* Group 0 pulse output control register0 */
typedef union {
	struct{
		UINT8	mod0_g0pocr0:1;  
		UINT8	mod1_g0pocr0:1;  
		UINT8	mod2_g0pocr0:1;  
		UINT8	bit3:1;  
		UINT8	ivl_g0pocr0:1;  
		UINT8	rld_g0pocr0:1;  
		UINT8  	bit6:1;
		UINT8	inv_g0pocr0:1;  
	} bit;
	UINT8 byte;
} G0POCR0_ADDR;
G0POCR0_ADDR	g0pocr0_addr;

#define		G0POCR0				g0pocr0_addr.byte
#define		MOD0_G0POCR0      	g0pocr0_addr.bit.mod0_g0pocr0
#define		MOD1_G0POCR0   		g0pocr0_addr.bit.mod1_g0pocr0
#define		MOD2_G0POCR0      	g0pocr0_addr.bit.mod2_g0pocr0
#define		IVL_G0POCR0      	g0pocr0_addr.bit.ivl_g0pocr0
#define		RLD_G0POCR0      	g0pocr0_addr.bit.rld_g0pocr0
#define		INV_G0POCR0      	g0pocr0_addr.bit.inv_g0pocr0

/*------------------------------------------------------
    Group 0 waveform generate control register 1
------------------------------------------------------*/
#pragma ADDRESS     g0pocr1_addr 00d1H      /* Group 0 pulse output control register1 */
typedef union {
	struct{
		UINT8	mod0_g0pocr1:1;  
		UINT8	mod1_g0pocr1:1;  
		UINT8	mod2_g0pocr1:1;  
		UINT8	bit3:1;  
		UINT8	ivl_g0pocr1:1;  
		UINT8	rld_g0pocr1:1;  
		UINT8  	bit6:1;
		UINT8	inv_g0pocr1:1;  
	} bit;
	UINT8 byte;
} G0POCR1_ADDR;
G0POCR1_ADDR	g0pocr1_addr;

#define		G0POCR1				g0pocr1_addr.byte
#define		MOD0_G0POCR1      	g0pocr1_addr.bit.mod0_g0pocr1
#define		MOD1_G0POCR1   		g0pocr1_addr.bit.mod1_g0pocr1
#define		MOD2_G0POCR1      	g0pocr1_addr.bit.mod2_g0pocr1
#define		IVL_G0POCR1      	g0pocr1_addr.bit.ivl_g0pocr1
#define		RLD_G0POCR1      	g0pocr1_addr.bit.rld_g0pocr1
#define		INV_G0POCR1      	g0pocr1_addr.bit.inv_g0pocr1

/*------------------------------------------------------
    Group 0 waveform generate control register 2
------------------------------------------------------*/
#pragma ADDRESS     g0pocr2_addr 00d2H      /* Group 0 pulse output control register2 */
typedef union {
	struct{
		UINT8	mod0_g0pocr2:1;  
		UINT8	mod1_g0pocr2:1;  
		UINT8	mod2_g0pocr2:1;  
		UINT8	bit3:1;  
		UINT8	ivl_g0pocr2:1;  
		UINT8	rld_g0pocr2:1;  
		UINT8  	bit6:1;
		UINT8	inv_g0pocr2:1;  
	} bit;
	UINT8 byte;
} G0POCR2_ADDR;
G0POCR2_ADDR	g0pocr2_addr;

#define		G0POCR2				g0pocr2_addr.byte
#define		MOD0_G0POCR2      	g0pocr2_addr.bit.mod0_g0pocr2
#define		MOD1_G0POCR2   		g0pocr2_addr.bit.mod1_g0pocr2
#define		MOD2_G0POCR2      	g0pocr2_addr.bit.mod2_g0pocr2
#define		IVL_G0POCR2      	g0pocr2_addr.bit.ivl_g0pocr2
#define		RLD_G0POCR2      	g0pocr2_addr.bit.rld_g0pocr2
#define		INV_G0POCR2      	g0pocr2_addr.bit.inv_g0pocr2

/*------------------------------------------------------
    Group 0 waveform generate control register 3
------------------------------------------------------*/
#pragma ADDRESS     g0pocr3_addr 00d3H      /* Group 0 pulse output control register3 */
typedef union {
	struct{
		UINT8	mod0_g0pocr3:1;  
		UINT8	mod1_g0pocr3:1;  
		UINT8	mod2_g0pocr3:1;  
		UINT8	bit3:1;  
		UINT8	ivl_g0pocr3:1;  
		UINT8	rld_g0pocr3:1;  
		UINT8  	bit6:1;
		UINT8	inv_g0pocr3:1;  
	} bit;
	UINT8 byte;
} G0POCR3_ADDR;
G0POCR3_ADDR	g0pocr3_addr;

#define		G0POCR3				g0pocr3_addr.byte
#define		MOD0_G0POCR3      	g0pocr3_addr.bit.mod0_g0pocr3
#define		MOD1_G0POCR3   		g0pocr3_addr.bit.mod1_g0pocr3
#define		MOD2_G0POCR3      	g0pocr3_addr.bit.mod2_g0pocr3
#define		IVL_G0POCR3      	g0pocr3_addr.bit.ivl_g0pocr3
#define		RLD_G0POCR3      	g0pocr3_addr.bit.rld_g0pocr3
#define		INV_G0POCR3      	g0pocr3_addr.bit.inv_g0pocr3

/*------------------------------------------------------
    Group 0 waveform generate control register 4
------------------------------------------------------*/
#pragma ADDRESS     g0pocr4_addr 00d4H      /* Group 0 pulse output control register4 */
typedef union {
	struct{
		UINT8	mod0_g0pocr4:1;  
		UINT8	mod1_g0pocr4:1;  
		UINT8	mod2_g0pocr4:1;  
		UINT8	bit3:1;  
		UINT8	ivl_g0pocr4:1;  
		UINT8	rld_g0pocr4:1;  
		UINT8  	bit6:1;
		UINT8	inv_g0pocr4:1;  
	} bit;
	UINT8 byte;
} G0POCR4_ADDR;
G0POCR4_ADDR	g0pocr4_addr;

#define		G0POCR4				g0pocr4_addr.byte
#define		MOD0_G0POCR4     	g0pocr4_addr.bit.mod0_g0pocr4
#define		MOD1_G0POCR4  		g0pocr4_addr.bit.mod1_g0pocr4
#define		MOD2_G0POCR4     	g0pocr4_addr.bit.mod2_g0pocr4
#define		IVL_G0POCR4    		g0pocr4_addr.bit.ivl_g0pocr4
#define		RLD_G0POCR4    		g0pocr4_addr.bit.rld_g0pocr4
#define		INV_G0POCR4    		g0pocr4_addr.bit.inv_g0pocr4

/*------------------------------------------------------
    Group 0 waveform generate control register 5
------------------------------------------------------*/
#pragma ADDRESS     g0pocr5_addr 00d5H      /* Group 0 pulse output control register5 */
typedef union {
	struct{
		UINT8	mod0_g0pocr5:1;  
		UINT8	mod1_g0pocr5:1;  
		UINT8	mod2_g0pocr5:1;  
		UINT8	bit3:1;  
		UINT8	ivl_g0pocr5:1;  
		UINT8	rld_g0pocr5:1;  
		UINT8  	bit6:1;
		UINT8	inv_g0pocr5:1;  
	} bit;
	UINT8 byte;
} G0POCR5_ADDR;
G0POCR5_ADDR	g0pocr5_addr;

#define		G0POCR5				g0pocr5_addr.byte
#define		MOD0_G0POCR5      	g0pocr5_addr.bit.mod0_g0pocr5
#define		MOD1_G0POCR5   		g0pocr5_addr.bit.mod1_g0pocr5
#define		MOD2_G0POCR5      	g0pocr5_addr.bit.mod2_g0pocr5
#define		IVL_G0POCR5      	g0pocr5_addr.bit.ivl_g0pocr5
#define		RLD_G0POCR5      	g0pocr5_addr.bit.rld_g0pocr5
#define		INV_G0POCR5      	g0pocr5_addr.bit.inv_g0pocr5

/*------------------------------------------------------
    Group 0 waveform generate control register 6
------------------------------------------------------*/
#pragma ADDRESS     g0pocr6_addr 00d6H      /* Group 0 pulse output control register6 */
typedef union {
	struct{
		UINT8	mod0_g0pocr6:1;  
		UINT8	mod1_g0pocr6:1;  
		UINT8	mod2_g0pocr6:1;  
		UINT8	bit3:1;  
		UINT8	ivl_g0pocr6:1;  
		UINT8	rld_g0pocr6:1;  
		UINT8  	bit6:1;
		UINT8	inv_g0pocr6:1;  
	} bit;
	UINT8 byte;
} G0POCR6_ADDR;
G0POCR6_ADDR	g0pocr6_addr;

#define		G0POCR6				g0pocr6_addr.byte
#define		MOD0_G0POCR6      	g0pocr6_addr.bit.mod0_g0pocr6
#define		MOD1_G0POCR6   		g0pocr6_addr.bit.mod1_g0pocr6
#define		MOD2_G0POCR6      	g0pocr6_addr.bit.mod2_g0pocr6
#define		IVL_G0POCR6      	g0pocr6_addr.bit.ivl_g0pocr6
#define		RLD_G0POCR6      	g0pocr6_addr.bit.rld_g0pocr6
#define		INV_G0POCR6      	g0pocr6_addr.bit.inv_g0pocr6

/*------------------------------------------------------
    Group 0 waveform generate control register 7
------------------------------------------------------*/
#pragma ADDRESS     g0pocr7_addr 00d7H      /* Group 0 pulse output control register7 */
typedef union {
	struct{
		UINT8	mod0_g0pocr7:1;  
		UINT8	mod1_g0pocr7:1;  
		UINT8	mod2_g0pocr7:1;  
		UINT8	bit3:1;  
		UINT8	ivl_g0pocr7:1;  
		UINT8	rld_g0pocr7:1;  
		UINT8  	bit6:1;
		UINT8	inv_g0pocr7:1;  
	} bit;
	UINT8 byte;
} G0POCR7_ADDR;
G0POCR7_ADDR	g0pocr7_addr;

#define		G0POCR7				g0pocr7_addr.byte
#define		MOD0_G0POCR7      	g0pocr7_addr.bit.mod0_g0pocr7
#define		MOD1_G0POCR7   		g0pocr7_addr.bit.mod1_g0pocr7
#define		MOD2_G0POCR7      	g0pocr7_addr.bit.mod2_g0pocr7
#define		IVL_G0POCR7      	g0pocr7_addr.bit.ivl_g0pocr7
#define		RLD_G0POCR7      	g0pocr7_addr.bit.rld_g0pocr7
#define		INV_G0POCR7      	g0pocr7_addr.bit.inv_g0pocr7

/*------------------------------------------------------
    Group 0 time measurement control register 0
------------------------------------------------------*/
#pragma ADDRESS     g0tmcr0_addr 00d8H      /* Group 0 time measuring control register0 */
typedef union {
	struct{
		UINT8	cts0_g0tmcr0:1;  
		UINT8	cts1_g0tmcr0:1;  
		UINT8	df0_g0tmcr0:1;  
		UINT8	df1_g0tmcr0:1;  
		UINT8	gt_g0tmcr0:1;  
		UINT8	goc_g0tmcr0:1;  
		UINT8  	gsc_g0tmcr0:1;
		UINT8	pr_g0tmcr0:1;  
	} bit;
	UINT8 byte;
} G0TMCR0_ADDR;
G0TMCR0_ADDR	g0tmcr0_addr;

#define		G0TMCR0 	  	 g0tmcr0_addr.byte
#define		CTS0_G0TMCR0     g0tmcr0_addr.bit.cts0_g0tmcr0
#define		CTS1_G0TMCR0     g0tmcr0_addr.bit.cts1_g0tmcr0
#define		DF0_G0TMCR0      g0tmcr0_addr.bit.df0_g0tmcr0
#define		DF1_G0TMCR0      g0tmcr0_addr.bit.df1_g0tmcr0
#define		GT_G0TMCR0       g0tmcr0_addr.bit.gt_g0tmcr0
#define		GOC_G0TMCR0      g0tmcr0_addr.bit.goc_g0tmcr0
#define		GSC_G0TMCR0      g0tmcr0_addr.bit.gsc_g0tmcr0
#define		PR_G0TMCR0       g0tmcr0_addr.bit.pr_g0tmcr0

/*------------------------------------------------------
    Group 0 time measurement control register 1
------------------------------------------------------*/
#pragma ADDRESS     g0tmcr1_addr 00d9H      /* Group 0 time measuring control register1 */
typedef union {
	struct{
		UINT8	cts0_g0tmcr1:1;  
		UINT8	cts1_g0tmcr1:1;  
		UINT8	df0_g0tmcr1:1;  
		UINT8	df1_g0tmcr1:1;  
		UINT8	gt_g0tmcr1:1;  
		UINT8	goc_g0tmcr1:1;  
		UINT8  	gsc_g0tmcr1:1;
		UINT8	pr_g0tmcr1:1;  
	} bit;
	UINT8 byte;
} G0TMCR1_ADDR;
G0TMCR1_ADDR	g0tmcr1_addr;

#define		G0TMCR1 	  	 g0tmcr1_addr.byte
#define		CTS0_G0TMCR1     g0tmcr1_addr.bit.cts0_g0tmcr1
#define		CTS1_G0TMCR1     g0tmcr1_addr.bit.cts1_g0tmcr1
#define		DF0_G0TMCR1      g0tmcr1_addr.bit.df0_g0tmcr1
#define		DF1_G0TMCR1      g0tmcr1_addr.bit.df1_g0tmcr1
#define		GT_G0TMCR1       g0tmcr1_addr.bit.gt_g0tmcr1
#define		GOC_G0TMCR1      g0tmcr1_addr.bit.goc_g0tmcr1
#define		GSC_G0TMCR1      g0tmcr1_addr.bit.gsc_g0tmcr1
#define		PR_G0TMCR1       g0tmcr1_addr.bit.pr_g0tmcr1

/*------------------------------------------------------
    Group 0 time measurement control register 2
------------------------------------------------------*/
#pragma ADDRESS     g0tmcr2_addr 00daH      /* Group 0 time measuring control register2 */
typedef union {
	struct{
		UINT8	cts0_g0tmcr2:1;  
		UINT8	cts1_g0tmcr2:1;  
		UINT8	df0_g0tmcr2:1;  
		UINT8	df1_g0tmcr2:1;  
		UINT8	gt_g0tmcr2:1;  
		UINT8	goc_g0tmcr2:1;  
		UINT8  	gsc_g0tmcr2:1;
		UINT8	pr_g0tmcr2:1;  
	} bit;
	UINT8 byte;
} G0TMCR2_ADDR;
G0TMCR2_ADDR	g0tmcr2_addr;

#define		G0TMCR2 	  	 g0tmcr2_addr.byte
#define		CTS0_G0TMCR2     g0tmcr2_addr.bit.cts0_g0tmcr2
#define		CTS1_G0TMCR2     g0tmcr2_addr.bit.cts1_g0tmcr2
#define		DF0_G0TMCR2      g0tmcr2_addr.bit.df0_g0tmcr2
#define		DF1_G0TMCR2      g0tmcr2_addr.bit.df1_g0tmcr2
#define		GT_G0TMCR2       g0tmcr2_addr.bit.gt_g0tmcr2
#define		GOC_G0TMCR2      g0tmcr2_addr.bit.goc_g0tmcr2
#define		GSC_G0TMCR2      g0tmcr2_addr.bit.gsc_g0tmcr2
#define		PR_G0TMCR2       g0tmcr2_addr.bit.pr_g0tmcr2

/*------------------------------------------------------
    Group 0 time measurement control register 3
------------------------------------------------------*/
#pragma ADDRESS     g0tmcr3_addr 00dbH      /* Group 0 time measuring control register3 */
typedef union {
	struct{
		UINT8	cts0_g0tmcr3:1;  
		UINT8	cts1_g0tmcr3:1;  
		UINT8	df0_g0tmcr3:1;  
		UINT8 	df1_g0tmcr3:1;  
		UINT8	gt_g0tmcr3:1;  
		UINT8	goc_g0tmcr3:1;  
		UINT8  	gsc_g0tmcr3:1;
		UINT8  	pr_g0tmcr3:1;  
	} bit;
	UINT8 byte;
} G0TMCR3_ADDR;
G0TMCR3_ADDR	g0tmcr3_addr;

#define		G0TMCR3 	  	 g0tmcr3_addr.byte
#define		CTS0_G0TMCR3     g0tmcr3_addr.bit.cts0_g0tmcr3
#define		CTS1_G0TMCR3     g0tmcr3_addr.bit.cts1_g0tmcr3
#define		DF0_G0TMCR3      g0tmcr3_addr.bit.df0_g0tmcr3
#define		DF1_G0TMCR3      g0tmcr3_addr.bit.df1_g0tmcr3
#define		GT_G0TMCR3       g0tmcr3_addr.bit.gt_g0tmcr3
#define		GOC_G0TMCR3      g0tmcr3_addr.bit.goc_g0tmcr3
#define		GSC_G0TMCR3      g0tmcr3_addr.bit.gsc_g0tmcr3
#define		PR_G0TMCR3       g0tmcr3_addr.bit.pr_g0tmcr3

/*------------------------------------------------------
    Group 0 time measurement control register 4
------------------------------------------------------*/
#pragma ADDRESS     g0tmcr4_addr 00dcH      /* Group 0 time measuring control register4 */
typedef union {
	struct{
		UINT8	cts0_g0tmcr4:1;  
		UINT8	cts1_g0tmcr4:1;  
		UINT8	df0_g0tmcr4:1;  
		UINT8	df1_g0tmcr4:1;  
		UINT8	gt_g0tmcr4:1;  
		UINT8	goc_g0tmcr4:1;  
		UINT8  	gsc_g0tmcr4:1;
		UINT8	pr_g0tmcr4:1;  
	} bit;
	UINT8 byte;
} G0TMCR4_ADDR;
G0TMCR4_ADDR	g0tmcr4_addr;

#define		G0TMCR4 	  	 g0tmcr4_addr.byte
#define		CTS0_G0TMCR4     g0tmcr4_addr.bit.cts0_g0tmcr4
#define		CTS1_G0TMCR4     g0tmcr4_addr.bit.cts1_g0tmcr4
#define		DF0_G0TMCR4      g0tmcr4_addr.bit.df0_g0tmcr4
#define		DF1_G0TMCR4      g0tmcr4_addr.bit.df1_g0tmcr4
#define		GT_G0TMCR4       g0tmcr4_addr.bit.gt_g0tmcr4
#define		GOC_G0TMCR4      g0tmcr4_addr.bit.goc_g0tmcr4
#define		GSC_G0TMCR4      g0tmcr4_addr.bit.gsc_g0tmcr4
#define		PR_G0TMCR4       g0tmcr4_addr.bit.pr_g0tmcr4

/*------------------------------------------------------
    Group 0 time measurement control register 5
------------------------------------------------------*/
#pragma ADDRESS     g0tmcr5_addr 00ddH      /* Group 0 time measuring control register5 */
typedef union {
	struct{
		UINT8	cts0_g0tmcr5:1;  
		UINT8	cts1_g0tmcr5:1;  
		UINT8	df0_g0tmcr5:1;  
		UINT8	df1_g0tmcr5:1;  
		UINT8	gt_g0tmcr5:1;  
		UINT8	goc_g0tmcr5:1;  
		UINT8  	gsc_g0tmcr5:1;
		UINT8 	pr_g0tmcr5:1;  
	} bit;
	UINT8 byte;
} G0TMCR5_ADDR;
G0TMCR5_ADDR	g0tmcr5_addr;

#define		G0TMCR5 	  	 g0tmcr5_addr.byte
#define		CTS0_G0TMCR5     g0tmcr5_addr.bit.cts0_g0tmcr5
#define		CTS1_G0TMCR5     g0tmcr5_addr.bit.cts1_g0tmcr5
#define		DF0_G0TMCR5      g0tmcr5_addr.bit.df0_g0tmcr5
#define		DF1_G0TMCR5      g0tmcr5_addr.bit.df1_g0tmcr5
#define		GT_G0TMCR5       g0tmcr5_addr.bit.gt_g0tmcr5
#define		GOC_G0TMCR5      g0tmcr5_addr.bit.goc_g0tmcr5
#define		GSC_G0TMCR5      g0tmcr5_addr.bit.gsc_g0tmcr5
#define		PR_G0TMCR5       g0tmcr5_addr.bit.pr_g0tmcr5

/*------------------------------------------------------
    Group 0 time measurement control register 6
------------------------------------------------------*/
#pragma ADDRESS     g0tmcr6_addr 00deH      /* Group 0 time measuring control register6 */
typedef union {
	struct{
		UINT8	cts0_g0tmcr6:1;  
		UINT8	cts1_g0tmcr6:1;  
		UINT8	df0_g0tmcr6:1;  
		UINT8	df1_g0tmcr6:1;  
		UINT8	gt_g0tmcr6:1;  
		UINT8	goc_g0tmcr6:1;  
		UINT8  	gsc_g0tmcr6:1;
		UINT8	pr_g0tmcr6:1;  
	} bit;
	UINT8 byte;
} G0TMCR6_ADDR;
G0TMCR6_ADDR	g0tmcr6_addr;

#define		G0TMCR6 	  	 g0tmcr6_addr.byte
#define		CTS0_G0TMCR6     g0tmcr6_addr.bit.cts0_g0tmcr6
#define		CTS1_G0TMCR6     g0tmcr6_addr.bit.cts1_g0tmcr6
#define		DF0_G0TMCR6      g0tmcr6_addr.bit.df0_g0tmcr6
#define		DF1_G0TMCR6      g0tmcr6_addr.bit.df1_g0tmcr6
#define		GT_G0TMCR6       g0tmcr6_addr.bit.gt_g0tmcr6
#define		GOC_G0TMCR6      g0tmcr6_addr.bit.goc_g0tmcr6
#define		GSC_G0TMCR6      g0tmcr6_addr.bit.gsc_g0tmcr6
#define		PR_G0TMCR6       g0tmcr6_addr.bit.pr_g0tmcr6

/*------------------------------------------------------
    Group 0 time measurement control register 7
------------------------------------------------------*/
#pragma ADDRESS     g0tmcr7_addr 00dfH      /* Group 0 time measuring control register7 */
typedef union {
	struct{
		UINT8	cts0_g0tmcr7:1;  
		UINT8	cts1_g0tmcr7:1;  
		UINT8	df0_g0tmcr7:1;  
		UINT8	df1_g0tmcr7:1;  
		UINT8	gt_g0tmcr7:1;  
		UINT8	goc_g0tmcr7:1;  
		UINT8  	gsc_g0tmcr7:1;
		UINT8	pr_g0tmcr7:1;  
	} bit;
	UINT8 byte;
} G0TMCR7_ADDR;
G0TMCR7_ADDR	g0tmcr7_addr;

#define		G0TMCR7 	  	 g0tmcr7_addr.byte
#define		CTS0_G0TMCR7     g0tmcr7_addr.bit.cts0_g0tmcr7
#define		CTS1_G0TMCR7     g0tmcr7_addr.bit.cts1_g0tmcr7
#define		DF0_G0TMCR7      g0tmcr7_addr.bit.df0_g0tmcr7
#define		DF1_G0TMCR7      g0tmcr7_addr.bit.df1_g0tmcr7
#define		GT_G0TMCR7       g0tmcr7_addr.bit.gt_g0tmcr7
#define		GOC_G0TMCR7      g0tmcr7_addr.bit.goc_g0tmcr7
#define		GSC_G0TMCR7      g0tmcr7_addr.bit.gsc_g0tmcr7
#define		PR_G0TMCR7       g0tmcr7_addr.bit.pr_g0tmcr7


/*-------------------------------------------------*/
#pragma ADDRESS     g0bt_addr   00e0H       /* Group 0 base timer register */
typedef union {
    struct{
        UINT8    g0bt_low;                /* Low  8 bit */
        UINT8    g0bt_high;               /* High 8 bit */
    } byte;
    UINT16  word;
} G0BT_ADDR;
G0BT_ADDR	g0bt_addr;

#define		G0BT      g0bt_addr.word      /* Group 0 base timer register */
#define		G0BTL     g0bt_addr.byte.g0bt_low
#define		G0BTH     g0bt_addr.byte.g0bt_high

/*------------------------------------------------------
    Group 0 base timer control register 0
------------------------------------------------------*/
#pragma ADDRESS     g0bcr0_addr 00e2H       /* Group 0 base timer control register0 */
typedef union {
	struct{
		UINT8	bck0_g0bcr0:1;  
		UINT8	bck1_g0bcr0:1;  
		UINT8	div0_g0bcr0:1;  
		UINT8	div1_g0bcr0:1;  
		UINT8	div2_g0bcr0:1;  
		UINT8	div3_g0bcr0:1;  
		UINT8  	div4_g0bcr0:1;
		UINT8	it_g0bcr0:1;  
	} bit;
	UINT8 byte;
} G0BCR0_ADDR;
G0BCR0_ADDR	g0bcr0_addr;

#define		G0BCR0		 	  g0bcr0_addr.byte
#define		BCK0_G0BCR0       g0bcr0_addr.bit.bck0_g0bcr0
#define		BCK1_G0BCR0       g0bcr0_addr.bit.bck1_g0bcr0
#define		DIV0_G0BCR0       g0bcr0_addr.bit.div0_g0bcr0
#define		DIV1_G0BCR0       g0bcr0_addr.bit.div1_g0bcr0
#define		DIV2_G0BCR0       g0bcr0_addr.bit.div2_g0bcr0
#define		DIV3_G0BCR0       g0bcr0_addr.bit.div3_g0bcr0
#define		DIV4_G0BCR0       g0bcr0_addr.bit.div4_g0bcr0
#define		IT_G0BCR0   	  g0bcr0_addr.bit.it_g0bcr0

/*------------------------------------------------------
    Group 0 base timer control register 1
------------------------------------------------------*/
#pragma ADDRESS     g0bcr1_addr 00e3H       /* Group 0 base timer control register1 */
typedef union {
	struct{
		UINT8	rst0_g0bcr1:1;  
		UINT8	rst1_g0bcr1:1;  
		UINT8	rst2_g0bcr1:1;  
		UINT8	rst3_g0bcr1:1;  
		UINT8	bts_g0bcr1:1;  
		UINT8	ud0_g0bcr1:1;  
		UINT8  	ud1_g0bcr1:1;
		UINT8	cas_g0bcr1:1;  
	} bit;
	UINT8 byte;
} G0BCR1_ADDR;
G0BCR1_ADDR	g0bcr1_addr;

#define		G0BCR1		  		g0bcr1_addr.byte
#define		RST0_G0BCR1       	g0bcr1_addr.bit.rst0_g0bcr1
#define		RST1_G0BCR1       	g0bcr1_addr.bit.rst1_g0bcr1
#define		RST2_G0BCR1       	g0bcr1_addr.bit.rst2_g0bcr1
#define		RST3_G0BCR1       	g0bcr1_addr.bit.rst3_g0bcr1
#define		BTS_G0BCR1       	g0bcr1_addr.bit.bts_g0bcr1
#define		UD0_G0BCR1      	g0bcr1_addr.bit.ud0_g0bcr1
#define		UD1_G0BCR1       	g0bcr1_addr.bit.ud1_g0bcr1
#define		CAS_G0BCR1   	  	g0bcr1_addr.bit.cas_g0bcr1

/*------------------------------------------------------
    Group 0 time measurement prescaler register 6
------------------------------------------------------*/
#pragma ADDRESS     g0tpr6_addr 00e4H       /* Group 0 priscale reload register6 */
typedef union {
	UINT8 byte;
} G0TPR6_ADDR;
G0TPR6_ADDR	g0tpr6_addr;

#define		G0TPR6      g0tpr6_addr.byte

/*------------------------------------------------------
    Group 0 time measurement prescaler register 7
------------------------------------------------------*/
#pragma ADDRESS     g0tpr7_addr 00e5H       /* Group 0 priscale reload register7 */
typedef union {
	UINT8 byte;
} G0TPR7_ADDR;
G0TPR7_ADDR	g0tpr7_addr;

#define		G0TPR7      g0tpr7_addr.byte

/*------------------------------------------------------
    Group 0 function enable register
------------------------------------------------------*/
#pragma ADDRESS     g0fe_addr   00e6H       /* Group 0 function enable register */
typedef union {
	struct{
		UINT8	ife0_g0fe:1;  
		UINT8	ife1_g0fe:1;  
		UINT8	ife2_g0fe:1;  
		UINT8	ife3_g0fe:1;  
		UINT8	ife4_g0fe:1;  
		UINT8	ife5_g0fe:1;  
		UINT8  	ife6_g0fe:1;
		UINT8	ife7_g0fe:1;  
	} bit;
	UINT8 byte;
} G0FE_ADDR;
G0FE_ADDR	g0fe_addr;

#define		G0FE		   	 g0fe_addr.byte
#define		IFE0_G0FE        g0fe_addr.bit.ife0_g0fe
#define		IFE1_G0FE        g0fe_addr.bit.ife1_g0fe
#define		IFE2_G0FE        g0fe_addr.bit.ife2_g0fe
#define		IFE3_G0FE        g0fe_addr.bit.ife3_g0fe
#define		IFE4_G0FE        g0fe_addr.bit.ife4_g0fe
#define		IFE5_G0FE        g0fe_addr.bit.ife5_g0fe
#define		IFE6_G0FE        g0fe_addr.bit.ife6_g0fe
#define		IFE7_G0FE        g0fe_addr.bit.ife7_g0fe

/*------------------------------------------------------
    Group 0 function select register
------------------------------------------------------*/
#pragma ADDRESS     g0fs_addr   00e7H       /* Group 0 function select register */
typedef union {
	struct{
		UINT8	fsc0_g0fs:1;  
		UINT8	fsc1_g0fs:1;  
		UINT8	fsc2_g0fs:1;  
		UINT8	fsc3_g0fs:1;  
		UINT8	fsc4_g0fs:1;  
		UINT8	fsc5_g0fs:1;  
		UINT8  	fsc6_g0fs:1;
		UINT8	fsc7_g0fs:1;  
	} bit;
	UINT8 byte;
} G0FS_ADDR;
G0FS_ADDR	g0fs_addr;

#define		G0FS		   	 g0fs_addr.byte
#define		FSC0_G0FS        g0fs_addr.bit.fsc0_g0fs
#define		FSC1_G0FS        g0fs_addr.bit.fsc1_g0fs
#define		FSC2_G0FS        g0fs_addr.bit.fsc2_g0fs
#define		FSC3_G0FS        g0fs_addr.bit.fsc3_g0fs
#define		FSC4_G0FS        g0fs_addr.bit.fsc4_g0fs
#define		FSC5_G0FS        g0fs_addr.bit.fsc5_g0fs
#define		FSC6_G0FS        g0fs_addr.bit.fsc6_g0fs
#define		FSC7_G0FS        g0fs_addr.bit.fsc7_g0fs

/*------------------------------------------------------
     g0rb
------------------------------------------------------*/
#pragma ADDRESS     g0rb_addr   00e8H       /* Group 0 SI/O receive buffer register */
typedef union {
    struct{
        UINT8    b0:1;
        UINT8    b1:1;
        UINT8    b2:1;
        UINT8    b3:1;
        UINT8    b4:1;
        UINT8    b5:1;
        UINT8    b6:1;
        UINT8    b7:1;
        UINT8    b8:1;
        UINT8    b9:1;
        UINT8    b10:1;
        UINT8    b11:1;
        UINT8    oer_g0rb:1;              /* Overrun error flag */
        UINT8    fer_g0rb:1;              /* Framing error flag */
        UINT8    per_g0rb:1;              /* Parity error flag */
        UINT8    sum_g0rb:1;              /* Error sum flag */
    } bit;
    struct{
        UINT8    g0rb_low;                /* Low  8 bit */
        UINT8    g0rb_high;               /* High 8 bit */
    } byte;
    UINT16  word;
} G0RB_ADDR;
G0RB_ADDR	g0rb_addr;

#define		G0RB   		g0rb_addr.word
#define		G0RBL   	g0rb_addr.byte.g0rb_low
#define		G0RBH   	g0rb_addr.byte.g0rb_high
#define		OER_G0RB   	g0rb_addr.bit.oer_g0rb   /* Overrun error flag */
#define		FER_G0RB   	g0rb_addr.bit.fer_g0rb   /* Framing error flag */
//#define   PER_G0RB   	g0rb_addr.bit.per_g0rb   /* Parity error flag */
//#define   SUM_G0RB   	g0rb_addr.bit.sum_g0rb   /* Error sum flag */

/*------------------------------------------------------
    Group 0 transmitting buffer register
------------------------------------------------------*/
#pragma ADDRESS     g0tb_addr   00eaH       /* Group 0 SI/O transmitting buffer register */
typedef union {
	UINT8 byte;
} G0TB_ADDR;
G0TB_ADDR	g0tb_addr;

#define		G0TB       	 g0tb_addr.byte

/*------------------------------------------------------
    Group 0 receive data register
------------------------------------------------------*/
#pragma ADDRESS     g0dr_addr   00eaH       /* Group 0 receive data register */
UINT8	g0dr_addr;

#define		G0DR       g0dr_addr

/*------------------------------------------------------
    Group 0 receive input register
------------------------------------------------------*/
#pragma ADDRESS     g0ri_addr   00ecH       /* Group 0 receive input register */
typedef union {
	UINT8 byte;
} G0RI_ADDR;
G0RI_ADDR	g0ri_addr;

#define		G0RI         g0ri_addr.byte

/*------------------------------------------------------
    Group 0 SI/O communication mode register
------------------------------------------------------*/
#pragma ADDRESS     g0mr_addr   00edH       /* Group 0 SI/O communication control register */
typedef union {
	struct{
		UINT8	gmd0_g0mr:1;  
		UINT8	gmd1_g0mr:1;  
		UINT8	ckdir_g0mr:1;  
		UINT8	stps_g0mr:1;  
		UINT8	pry_g0mr:1;  
		UINT8	prye_g0mr1;  
		UINT8  	uform_g0mr:1;
		UINT8	irs_g0mr:1;  
	} bit;
	UINT8 byte;
} G0MR_ADDR;
G0MR_ADDR	g0mr_addr;

#define		G0MR			g0mr_addr.byte
#define		GMD0_G0MR       g0mr_addr.bit.gmd0_g0mr
#define		GMD1_G0MR       g0mr_addr.bit.gmd1_g0mr
#define		CKDIR_G0MR      g0mr_addr.bit.ckdir_g0mr
#define		STPS_G0MR       g0mr_addr.bit.stps_g0mr
//#define     	PRY_G0MR        g0mr_addr.bit.pry_g0mr
//#define     	PRYE_G0MR       g0mr_addr.bit.prye_g0mr
#define		UFORM_G0MR      g0mr_addr.bit.uform_g0mr
#define		IRS_G0MR        g0mr_addr.bit.irs_g0mr

/*------------------------------------------------------
    Group 0 transmit output register
------------------------------------------------------*/
#pragma ADDRESS     g0to_addr   00eeH       /* Group 0 transmit output register */
typedef union {
	UINT8 byte;
} G0TO_ADDR;
G0TO_ADDR	g0to_addr;

#define		G0TO         g0to_addr.byte

/*------------------------------------------------------
    Group 0 SI/O communication control register
------------------------------------------------------*/
#pragma ADDRESS     g0cr_addr   00efH       /* Group 0 SI/O communication control register */
typedef union {
	struct{
		UINT8	ti_g0cr:1;  
		UINT8	txept_g0cr:1;  
		UINT8	ri_g0cr:1;  
		UINT8	bit3:1;  
		UINT8	te_g0cr:1;  
		UINT8	re_g0cr:1;  
		UINT8  	ipol_g0cr:1;
		UINT8	opol_g0cr:1;  
	} bit;
	UINT8 byte;
} G0CR_ADDR;
G0CR_ADDR	g0cr_addr;

#define		G0CR				g0cr_addr.byte
#define		TI_G0CR        		g0cr_addr.bit.ti_g0cr
#define		TXEPT_G0CR        	g0cr_addr.bit.txept_g0cr
#define		RI_G0CR        		g0cr_addr.bit.ri_g0cr
#define		TE_G0CR        		g0cr_addr.bit.te_g0cr
#define		RE_G0CR        		g0cr_addr.bit.re_g0cr
#define		IPOL_G0CR        	g0cr_addr.bit.ipol_g0cr
#define		OPOL_G0CR        	g0cr_addr.bit.opol_g0cr

/*------------------------------------------------------
    Group 0 data compare register 0
------------------------------------------------------*/
#pragma ADDRESS     g0cmp0_addr 00f0H       /* Group 0 data compare register 0 */
typedef union {
	UINT8 byte;
} G0CMP0_ADDR;
G0CMP0_ADDR	g0cmp0_addr;

#define		G0CMP0       g0cmp0_addr.byte

/*------------------------------------------------------
    Group 0 data compare register 1
------------------------------------------------------*/
#pragma ADDRESS     g0cmp1_addr 00f1H       /* Group 0 data compare register 1 */
typedef union {
	UINT8 byte;
} G0CMP1_ADDR;
G0CMP1_ADDR	g0cmp1_addr;

#define		G0CMP1       g0cmp1_addr.byte

/*------------------------------------------------------
    Group 0 data compare register 2
------------------------------------------------------*/
#pragma ADDRESS     g0cmp2_addr 00f2H       /* Group 0 data compare register 2 */
typedef union {
	UINT8 byte;
} G0CMP2_ADDR;
G0CMP2_ADDR	g0cmp2_addr;

#define		G0CMP2       g0cmp2_addr.byte

/*------------------------------------------------------
    Group 0 data compare register 3
------------------------------------------------------*/
#pragma ADDRESS     g0cmp3_addr 00f3H       /* Group 0 data compare register 3 */
typedef union {
	UINT8 byte;
} G0CMP3_ADDR;
G0CMP3_ADDR	g0cmp3_addr;

#define		G0CMP3       g0cmp3_addr.byte

/*------------------------------------------------------
    Group 0 data mask register 0
------------------------------------------------------*/
#pragma ADDRESS     g0msk0_addr 00f4H       /* Group 0 data mask register 0 */
typedef union {
	UINT8 byte;
} G0MSK0_ADDR;
G0MSK0_ADDR	g0msk0_addr;

#define		G0MSK0       g0msk0_addr.byte

/*------------------------------------------------------
    Group 0 data mask register 1
------------------------------------------------------*/
#pragma ADDRESS     g0msk1_addr 00f5H       /* Group 0 data mask register 1 */
typedef union {
	UINT8 byte;
} G0MSK1_ADDR;
G0MSK1_ADDR	g0msk1_addr;

#define		G0MSK1       g0msk1_addr.byte

/*-------------------------------------------------------*/
#pragma ADDRESS     g0rcrc_addr 00f8H       /* Group 0 receive CRC code register */
typedef union {
    struct{
        UINT8    g0rcrc_low;                /* Low  8 bit */
        UINT8    g0rcrc_high;               /* High 8 bit */
    } byte;
    UINT16  word;
} G0RCRC_ADDR;
G0RCRC_ADDR	g0rcrc_addr;

#define		G0RCRC      g0rcrc_addr.word      /* Group 0 receive CRC code register */
#define		G0RCRCL     g0rcrc_addr.byte.g0rcrc_low
#define		G0RCRCH     g0rcrc_addr.byte.g0rcrc_high

/*-------------------------------------------------------*/
#pragma ADDRESS     g0tcrc_addr 00faH       /* Group 0 transmit CRC code register */
typedef union {
    struct{
        UINT8    g0tcrc_low;                /* Low  8 bit */
        UINT8    g0tcrc_high;               /* High 8 bit */
    } byte;
    UINT16  word;
} G0TCRC_ADDR;
G0TCRC_ADDR	g0tcrc_addr;

#define		G0TCRC      g0tcrc_addr.word      /* Group 0 transmit CRC code register */
#define		G0TCRCL     g0tcrc_addr.byte.g0tcrc_low
#define		G0TCRCH     g0tcrc_addr.byte.g0tcrc_high

/*------------------------------------------------------
    Group 0 SI/O expansion mode register
------------------------------------------------------*/
#pragma ADDRESS     g0emr_addr  00fcH       /* Group 0 SI/O expansion mode register */
typedef union {
	struct{
		UINT8	smode_g0emr:1;  
		UINT8	crcv_g0emr:1;  
		UINT8	acrc_g0emr:1;  
		UINT8	bsint_g0emr:1;  
		UINT8	rxsl_g0emr:1;  
		UINT8	txsl_g0emr:1;  
		UINT8  	crc0_g0emr:1;
		UINT8	crc1_g0emr:1;  
	} bit;
	UINT8 byte;
} G0EMR_ADDR;
G0EMR_ADDR	g0emr_addr;

#define		G0EMR			   	g0emr_addr.byte
#define		SMODE_G0EMR        	g0emr_addr.bit.smode_g0emr
#define		CRCV_G0EMR         	g0emr_addr.bit.crcv_g0emr
#define		ACRC_G0EMR        	g0emr_addr.bit.acrc_g0emr
#define		BSINT_G0EMR        	g0emr_addr.bit.bsint_g0emr
#define		RXSL_G0EMR       	g0emr_addr.bit.rxsl_g0emr
#define		TXSL_G0EMR        	g0emr_addr.bit.txsl_g0emr
#define		CRC0_G0EMR        	g0emr_addr.bit.crc0_g0emr
#define		CRC1_G0EMR        	g0emr_addr.bit.crc1_g0emr

/*------------------------------------------------------
    Group 0 SI/O communication mode register
------------------------------------------------------*/
#pragma ADDRESS     g0erc_addr  00fdH       /* Group 0 SI/O expansion receive control register */
typedef union {
	struct{
		UINT8	cmp0e_g0erc:1;  
		UINT8	cmp1e_g0erc:1;  
		UINT8	cmp2e_g0erc:1;  
		UINT8	cmp3e_g0erc:1;  
		UINT8	rcrce_g0erc:1;  
		UINT8	rshte_g0erc:1;  
		UINT8  	rbsf0_g0erc:1;
		UINT8	rbsf1_g0erc:1;  
	} bit;
	UINT8 byte;
} G0ERC_ADDR;
G0ERC_ADDR	g0erc_addr;

#define		G0ERC	  		 g0erc_addr.byte
#define		CMP0E_G0ERC      g0erc_addr.bit.cmp0e_g0erc
#define		CMP1E_G0ERC      g0erc_addr.bit.cmp1e_g0erc
#define		CMP2E_G0ERC      g0erc_addr.bit.cmp2e_g0erc
#define		CMP3E_G0ERC      g0erc_addr.bit.cmp3e_g0erc
#define		RCRCE_G0ERC      g0erc_addr.bit.rcrce_g0erc
#define		RSHTE_G0ERC      g0erc_addr.bit.rshte_g0erc
#define		RBSF0_G0ERC      g0erc_addr.bit.rbsf0_g0erc
#define		RBSF1_G0ERC      g0erc_addr.bit.rbsf1_g0erc

/*------------------------------------------------------
    Group 0 SI/O special communication 
            interrupt detect register
------------------------------------------------------*/
#pragma ADDRESS     g0irf_addr  00feH       /* Group 0 SI/O special communication interrupt detect register */
typedef union {
	struct{
		UINT8	bit0:1;  
		UINT8	bit1:1;  
		UINT8	bserr_g0irf:1;  
		UINT8	abt_g0irf:1;  
		UINT8	irf0_g0irf:1;  
		UINT8	irf1_g0irf:1;  
		UINT8  	irf2_g0irf:1;
		UINT8	irf3_g0irf:1;  
	} bit;
	UINT8 byte;
} G0IRF_ADDR;
G0IRF_ADDR	g0irf_addr;

#define		G0IRF	  		g0irf_addr.byte
#define		BSERR_G0IRF     g0irf_addr.bit.bserr_g0irf
#define		ABT_G0IRF     	g0irf_addr.bit.abt_g0irf
#define		IRF0_G0IRF      g0irf_addr.bit.irf0_g0irf
#define		IRF1_G0IRF      g0irf_addr.bit.irf1_g0irf
#define		IRF2_G0IRF     	g0irf_addr.bit.irf2_g0irf
#define		IRF3_G0IRF      g0irf_addr.bit.irf3_g0irf

/*------------------------------------------------------
    Group 0 SI/O expansion transmit control register
------------------------------------------------------*/
#pragma ADDRESS     g0etc_addr  00ffH       /* Group 0 SI/O expansion transmit control register */
typedef union {
	struct{
		UINT8	bit0:1;  
		UINT8	bit1:1;  
		UINT8	bit2:1;  
		UINT8	sof_g0etc:1;  
		UINT8	tcrce_g0etc:1;  
		UINT8	abte_g0etc:1;  
		UINT8  	tbsf0_g0etc:1;
		UINT8	tbsf1_g0etc:1;  
	} bit;
	UINT8 byte;
} G0ETC_ADDR;
G0ETC_ADDR	g0etc_addr;

#define		G0ETC       		g0etc_addr.byte
#define		SOF_G0ETC       	g0etc_addr.bit.sof_g0etc
#define		TCRCE_G0ETC       	g0etc_addr.bit.tcrce_g0etc
#define		ABTE_G0ETC      	g0etc_addr.bit.abte_g0etc
#define		TBSF0_G0ETC      	g0etc_addr.bit.tbsf0_g0etc
#define		TBSF1_G0ETC      	g0etc_addr.bit.tbsf1_g0etc

/*-------------------------------------------------*/
#pragma ADDRESS     g1tm0_addr  0100H       /* Group 1 time measurement register 0 */
typedef union {
    struct{
        UINT8    g1tm0_low;                /* Low  8 bit */
        UINT8    g1tm0_high;               /* High 8 bit */
    } byte;
    UINT16  word;
} G1TM0_ADDR;
G1TM0_ADDR	g1tm0_addr;

#define		G1TM0       g1tm0_addr.word      /* Group 1 time measurement register 0 */
#define		G1TM0L      g1tm0_addr.byte.g1tm0_low
#define		G1TM0H      g1tm0_addr.byte.g1tm0_high

/*-------------------------------------------------*/
#pragma ADDRESS		g1po0_addr	0100H		/* Group 1 waveform generate register 0 */
typedef union {
    struct{
        UINT8    g1po0_low;                /* Low  8 bit */
        UINT8    g1po0_high;               /* High 8 bit */
    } byte;
    UINT16  word;
} G1PO0_ADDR;
G1PO0_ADDR	g1po0_addr;

#define		G1PO0        g1po0_addr.word      /* Group 1 waveform generate register 0 */
#define		G1PO0L       g1po0_addr.byte.g1po0_low
#define		G1PO0H       g1po0_addr.byte.g1po0_high

/*-------------------------------------------------*/
#pragma ADDRESS     g1tm1_addr  0102H       /* Group 1 time measurement register 1 */
typedef union {
    struct{
        UINT8    g1tm1_low;                /* Low  8 bit */
        UINT8    g1tm1_high;               /* High 8 bit */
    } byte;
    UINT16  word;
} G1TM1_ADDR;
G1TM1_ADDR	g1tm1_addr;

#define		G1TM1       g1tm1_addr.word      /* Group 1 time measurement register 1 */
#define		G1TM1L      g1tm1_addr.byte.g1tm1_low
#define		G1TM1H      g1tm1_addr.byte.g1tm1_high

/*-------------------------------------------------*/
#pragma ADDRESS		g1po1_addr	0102H		/* Group 1 waveform generate register 1 */
typedef union {
    struct{
        UINT8    g1po1_low;                /* Low  8 bit */
        UINT8    g1po1_high;               /* High 8 bit */
    } byte;
    UINT16  word;
} G1PO1_ADDR;
G1PO1_ADDR	g1po1_addr;

#define		G1PO1        g1po1_addr.word      /* Group 1 waveform generate register 1 */
#define		G1PO1L       g1po1_addr.byte.g1po1_low
#define		G1PO1H       g1po1_addr.byte.g1po1_high

/*-------------------------------------------------*/
#pragma ADDRESS     g1tm2_addr  0104H       /* Group 1 time measurement register 2 */
typedef union {
    struct{
        UINT8    g1tm2_low;                /* Low  8 bit */
        UINT8    g1tm2_high;               /* High 8 bit */
    } byte;
    UINT16  word;
} G1TM2_ADDR;
G1TM2_ADDR	g1tm2_addr;

#define		G1TM2       g1tm2_addr.word      /* Group 1 time measurement register 2 */
#define		G1TM2L      g1tm2_addr.byte.g1tm2_low
#define		G1TM2H      g1tm2_addr.byte.g1tm2_high

/*-------------------------------------------------*/
#pragma ADDRESS		g1po2_addr	0104H		/* Group 1 waveform generate register 2 */
typedef union {
    struct{
        UINT8    g1po2_low;                /* Low  8 bit */
        UINT8    g1po2_high;               /* High 8 bit */
    } byte;
    UINT16  word;
} G1PO2_ADDR;
G1PO2_ADDR	g1po2_addr;
#define		G1PO2        g1po2_addr.word      /* Group 1 waveform generate register 2 */
#define		G1PO2L       g1po2_addr.byte.g1po2_low
#define		G1PO2H       g1po2_addr.byte.g1po2_high

/*-------------------------------------------------*/
#pragma ADDRESS     g1tm3_addr  0106H       /* Group 1 time measurement register 3 */
typedef union {
    struct{
        UINT8    g1tm3_low;                /* Low  8 bit */
        UINT8    g1tm3_high;               /* High 8 bit */
    } byte;
    UINT16  word;
} G1TM3_ADDR;
G1TM3_ADDR	g1tm3_addr;

#define		G1TM3       g1tm3_addr.word      /* Group 1 time measurement register 3 */
#define		G1TM3L      g1tm3_addr.byte.g1tm3_low
#define		G1TM3H      g1tm3_addr.byte.g1tm3_high

/*-------------------------------------------------*/
#pragma ADDRESS		g1po3_addr	0106H		/* Group 1 waveform generate register 3 */
typedef union {
    struct{
        UINT8    g1po3_low;                /* Low  8 bit */
        UINT8    g1po3_high;               /* High 8 bit */
    } byte;
    UINT16  word;
} G1PO3_ADDR;
G1PO3_ADDR	g1po3_addr;
#define		G1PO3        g1po3_addr.word      /* Group 1 waveform generate register 3 */
#define		G1PO3L       g1po3_addr.byte.g1po3_low
#define		G1PO3H       g1po3_addr.byte.g1po3_high

/*-------------------------------------------------*/
#pragma ADDRESS     g1tm4_addr  0108H       /* Group 1 time measurement register 4 */
typedef union {
    struct{
        UINT8    g1tm4_low;                /* Low  8 bit */
        UINT8    g1tm4_high;               /* High 8 bit */
    } byte;
    UINT16  word;
} G1TM4_ADDR;
G1TM4_ADDR	g1tm4_addr;

#define		G1TM4       g1tm4_addr.word      /* Group 1 time measurement register 4 */
#define		G1TM4L      g1tm4_addr.byte.g1tm4_low
#define		G1TM4H      g1tm4_addr.byte.g1tm4_high

/*-------------------------------------------------*/
#pragma ADDRESS		g1po4_addr	0108H		/* Group 1 waveform generate register 4 */
typedef union {
    struct{
        UINT8    g1po4_low;                /* Low  8 bit */
        UINT8    g1po4_high;               /* High 8 bit */
    } byte;
    UINT16  word;
} G1PO4_ADDR;
G1PO4_ADDR	g1po4_addr;
#define		G1PO4        g1po4_addr.word      /* Group 1 waveform generate register 4 */
#define		G1PO4L       g1po4_addr.byte.g1po4_low
#define		G1PO4H       g1po4_addr.byte.g1po4_high

/*-------------------------------------------------*/
#pragma ADDRESS     g1tm5_addr  010aH       /* Group 1 time measurement register 5 */
typedef union {
    struct{
        UINT8    g1tm5_low;                /* Low  8 bit */
        UINT8    g1tm5_high;               /* High 8 bit */
    } byte;
    UINT16  word;
} G1TM5_ADDR;
G1TM5_ADDR	g1tm5_addr;

#define		G1TM5       g1tm5_addr.word      /* Group 1 time measurement register 5 */
#define		G1TM5L      g1tm5_addr.byte.g1tm5_low
#define		G1TM5H      g1tm5_addr.byte.g1tm5_high

/*-------------------------------------------------*/
#pragma ADDRESS		g1po5_addr	010aH		/* Group 1 waveform generate register 5 */
typedef union {
    struct{
        UINT8    g1po5_low;                /* Low  8 bit */
        UINT8    g1po5_high;               /* High 8 bit */
    } byte;
    UINT16  word;
} G1PO5_ADDR;
G1PO5_ADDR	g1po5_addr;
#define		G1PO5        g1po5_addr.word      /* Group 1 waveform generate register 5 */
#define		G1PO5L       g1po5_addr.byte.g1po5_low
#define		G1PO5H       g1po5_addr.byte.g1po5_high

/*-------------------------------------------------*/
#pragma ADDRESS     g1tm6_addr  010cH       /* Group 1 time measurement register 6 */
typedef union {
    struct{
        UINT8    g1tm6_low;                /* Low  8 bit */
        UINT8    g1tm6_high;               /* High 8 bit */
    } byte;
    UINT16  word;
} G1TM6_ADDR;
G1TM6_ADDR	g1tm6_addr;

#define		G1TM6       g1tm6_addr.word      /* Group 1 time measurement register 6 */
#define		G1TM6L      g1tm6_addr.byte.g1tm6_low
#define		G1TM6H      g1tm6_addr.byte.g1tm6_high

/*-------------------------------------------------*/
#pragma ADDRESS		g1po6_addr	010cH		/* Group 1 waveform generate register 6 */
typedef union {
    struct{
        UINT8    g1po6_low;                /* Low  8 bit */
        UINT8    g1po6_high;               /* High 8 bit */
    } byte;
    UINT16  word;
} G1PO6_ADDR;
G1PO6_ADDR	g1po6_addr;
#define		G1PO6        g1po6_addr.word      /* Group 1 waveform generate register 6 */
#define		G1PO6L       g1po6_addr.byte.g1po6_low
#define		G1PO6H       g1po6_addr.byte.g1po6_high

/*-------------------------------------------------*/
#pragma ADDRESS     g1tm7_addr  010eH       /* Group 1 time measurement register 7 */
typedef union {
    struct{
        UINT8    g1tm7_low;                /* Low  8 bit */
        UINT8    g1tm7_high;               /* High 8 bit */
    } byte;
    UINT16  word;
} G1TM7_ADDR;
G1TM7_ADDR	g1tm7_addr;

#define		G1TM7       g1tm7_addr.word      /* Group 1 time measurement register 7 */
#define		G1TM7L      g1tm7_addr.byte.g1tm7_low
#define		G1TM7H      g1tm7_addr.byte.g1tm7_high

/*-------------------------------------------------*/
#pragma ADDRESS		g1po7_addr	010eH		/* Group 1 waveform generate register 7 */
typedef union {
    struct{
        UINT8    g1po7_low;                /* Low  8 bit */
        UINT8    g1po7_high;               /* High 8 bit */
    } byte;
    UINT16  word;
} G1PO7_ADDR;
G1PO7_ADDR	g1po7_addr;
#define		G1PO7        g1po7_addr.word      /* Group 1 waveform generate register 7 */
#define		G1PO7L       g1po7_addr.byte.g1po7_low
#define		G1PO7H       g1po7_addr.byte.g1po7_high

/*------------------------------------------------------
    Group 1 waveform generate control register 0
------------------------------------------------------*/
#pragma ADDRESS     g1pocr0_addr 0110H      /* Group 1 waveform generate control register 0 */
typedef union {
	struct{
		UINT8	mod0_g1pocr0:1;  
		UINT8	mod1_g1pocr0:1;  
		UINT8	mod2_g1pocr0:1;  
		UINT8	bit3:1;  
		UINT8	ivl_g1pocr0:1;  
		UINT8	rld_g1pocr0:1;  
		UINT8  	bit6:1;
		UINT8	inv_g1pocr0:1;  
	} bit;
	UINT8 byte;
} G1POCR0_ADDR;
G1POCR0_ADDR	g1pocr0_addr;

#define		G1POCR0				g1pocr0_addr.byte
#define		MOD0_G1POCR0      	g1pocr0_addr.bit.mod0_g1pocr0
#define		MOD1_G1POCR0    	g1pocr0_addr.bit.mod1_g1pocr0
#define		MOD2_G1POCR0      	g1pocr0_addr.bit.mod2_g1pocr0
#define		IVL_G1POCR0       	g1pocr0_addr.bit.ivl_g1pocr0
#define		RLD_G1POCR0     	g1pocr0_addr.bit.rld_g1pocr0
#define		INV_G1POCR0       	g1pocr0_addr.bit.inv_g1pocr0

/*------------------------------------------------------
    Group 1 waveform generate control register 1
------------------------------------------------------*/
#pragma ADDRESS     g1pocr1_addr 0111H      /* Group 1 waveform generate control register 1 */
typedef union {
	struct{
		UINT8	mod0_g1pocr1:1;  
		UINT8	mod1_g1pocr1:1;  
		UINT8	mod2_g1pocr1:1;  
		UINT8	bit3:1;  
		UINT8	ivl_g1pocr1:1;  
		UINT8	rld_g1pocr1:1;  
		UINT8  	bit6:1;
		UINT8	inv_g1pocr1:1;  
	} bit;
	UINT8 byte;
} G1POCR1_ADDR;
G1POCR1_ADDR	g1pocr1_addr;

#define		G1POCR1				g1pocr1_addr.byte
#define		MOD0_G1POCR1      	g1pocr1_addr.bit.mod0_g1pocr1
#define		MOD1_G1POCR1    	g1pocr1_addr.bit.mod1_g1pocr1
#define		MOD2_G1POCR1      	g1pocr1_addr.bit.mod2_g1pocr1
#define		IVL_G1POCR1       	g1pocr1_addr.bit.ivl_g1pocr1
#define		RLD_G1POCR1     	g1pocr1_addr.bit.rld_g1pocr1
#define		INV_G1POCR1       	g1pocr1_addr.bit.inv_g1pocr1

/*------------------------------------------------------
    Group 1 waveform generate control register 2
------------------------------------------------------*/
#pragma ADDRESS     g1pocr2_addr 0112H      /* Group 1 waveform generate control register 2 */
typedef union {
	struct{
		UINT8	mod0_g1pocr2:1;  
		UINT8	mod1_g1pocr2:1;  
		UINT8	mod2_g1pocr2:1;  
		UINT8	bit3:1;  
		UINT8	ivl_g1pocr2:1;  
		UINT8	rld_g1pocr2:1;  
		UINT8  	bit6:1;
		UINT8	inv_g1pocr2:1;  
	} bit;
	UINT8 byte;
} G1POCR2_ADDR;
G1POCR2_ADDR	g1pocr2_addr;

#define		G1POCR2				g1pocr2_addr.byte
#define		MOD0_G1POCR2      	g1pocr2_addr.bit.mod0_g1pocr2
#define		MOD1_G1POCR2    	g1pocr2_addr.bit.mod1_g1pocr2
#define		MOD2_G1POCR2      	g1pocr2_addr.bit.mod2_g1pocr2
#define		IVL_G1POCR2       	g1pocr2_addr.bit.ivl_g1pocr2
#define		RLD_G1POCR2     	g1pocr2_addr.bit.rld_g1pocr2
#define		INV_G1POCR2       	g1pocr2_addr.bit.inv_g1pocr2

/*------------------------------------------------------
    Group 1 waveform generate control register 3
------------------------------------------------------*/
#pragma ADDRESS     g1pocr3_addr 0113H      /* Group 1 waveform generate control register 3 */
typedef union {
	struct{
		UINT8	mod0_g1pocr3:1;  
		UINT8	mod1_g1pocr3:1;  
		UINT8	mod2_g1pocr3:1;  
		UINT8	bit3:1;  
		UINT8	ivl_g1pocr3:1;  
		UINT8	rld_g1pocr3:1;  
		UINT8  	bit6:1;
		UINT8	inv_g1pocr3:1;  
	} bit;
	UINT8 byte;
} G1POCR3_ADDR;
G1POCR3_ADDR	g1pocr3_addr;

#define		G1POCR3				g1pocr3_addr.byte
#define		MOD0_G1POCR3      	g1pocr3_addr.bit.mod0_g1pocr3
#define		MOD1_G1POCR3    	g1pocr3_addr.bit.mod1_g1pocr3
#define		MOD2_G1POCR3      	g1pocr3_addr.bit.mod2_g1pocr3
#define		IVL_G1POCR3       	g1pocr3_addr.bit.ivl_g1pocr3
#define		RLD_G1POCR3     	g1pocr3_addr.bit.rld_g1pocr3
#define		INV_G1POCR3       	g1pocr3_addr.bit.inv_g1pocr3

/*------------------------------------------------------
    Group 1 waveform generate control register 4
------------------------------------------------------*/
#pragma ADDRESS     g1pocr4_addr 0114H      /* Group 1 waveform generate control register 4 */
typedef union {
	struct{
		UINT8	mod0_g1pocr4:1;  
		UINT8	mod1_g1pocr4:1;  
		UINT8	mod2_g1pocr4:1;  
		UINT8	bit3:1;  
		UINT8	ivl_g1pocr4:1;  
		UINT8	rld_g1pocr4:1;  
		UINT8  	bit6:1;
		UINT8	inv_g1pocr4:1;  
	} bit;
	UINT8 byte;
} G1POCR4_ADDR;
G1POCR4_ADDR	g1pocr4_addr;

#define		G1POCR4				g1pocr4_addr.byte
#define		MOD0_G1POCR4      	g1pocr4_addr.bit.mod0_g1pocr4
#define		MOD1_G1POCR4    	g1pocr4_addr.bit.mod1_g1pocr4
#define		MOD2_G1POCR4      	g1pocr4_addr.bit.mod2_g1pocr4
#define		IVL_G1POCR4       	g1pocr4_addr.bit.ivl_g1pocr4
#define		RLD_G1POCR4     	g1pocr4_addr.bit.rld_g1pocr4
#define		INV_G1POCR4       	g1pocr4_addr.bit.inv_g1pocr4

/*------------------------------------------------------
    Group 1 waveform generate control register 5
------------------------------------------------------*/
#pragma ADDRESS     g1pocr5_addr 0115H      /* Group 1 waveform generate control register 5 */
typedef union {
	struct{
		UINT8	mod0_g1pocr5:1;  
		UINT8	mod1_g1pocr5:1;  
		UINT8	mod2_g1pocr5:1;  
		UINT8	bit3:1;  
		UINT8	ivl_g1pocr5:1;  
		UINT8	rld_g1pocr5:1;  
		UINT8  	bit6:1;
		UINT8	inv_g1pocr5:1;  
	} bit;
	UINT8 byte;
} G1POCR5_ADDR;
G1POCR5_ADDR	g1pocr5_addr;

#define		G1POCR5				g1pocr5_addr.byte
#define		MOD0_G1POCR5      	g1pocr5_addr.bit.mod0_g1pocr5
#define		MOD1_G1POCR5    	g1pocr5_addr.bit.mod1_g1pocr5
#define		MOD2_G1POCR5      	g1pocr5_addr.bit.mod2_g1pocr5
#define		IVL_G1POCR5       	g1pocr5_addr.bit.ivl_g1pocr5
#define		RLD_G1POCR5     	g1pocr5_addr.bit.rld_g1pocr5
#define		INV_G1POCR5       	g1pocr5_addr.bit.inv_g1pocr5

/*------------------------------------------------------
    Group 1 waveform generate control register 6
------------------------------------------------------*/
#pragma ADDRESS     g1pocr6_addr 0116H      /* Group 1 waveform generate control register 6 */
typedef union {
	struct{
		UINT8	mod0_g1pocr6:1;  
		UINT8	mod1_g1pocr6:1;  
		UINT8	mod2_g1pocr6:1;  
		UINT8	bit3:1;  
		UINT8	ivl_g1pocr6:1;  
		UINT8	rld_g1pocr6:1;  
		UINT8  	bit6:1;
		UINT8	inv_g1pocr6:1;  
	} bit;
	UINT8 byte;
} G1POCR6_ADDR;
G1POCR6_ADDR	g1pocr6_addr;

#define		G1POCR6				g1pocr6_addr.byte
#define		MOD0_G1POCR6      	g1pocr6_addr.bit.mod0_g1pocr6
#define		MOD1_G1POCR6    	g1pocr6_addr.bit.mod1_g1pocr6
#define		MOD2_G1POCR6      	g1pocr6_addr.bit.mod2_g1pocr6
#define		IVL_G1POCR6       	g1pocr6_addr.bit.ivl_g1pocr6
#define		RLD_G1POCR6     	g1pocr6_addr.bit.rld_g1pocr6
#define		INV_G1POCR6       	g1pocr6_addr.bit.inv_g1pocr6

/*------------------------------------------------------
    Group 1 waveform generate control register 7
------------------------------------------------------*/
#pragma ADDRESS     g1pocr7_addr 0117H      /* Group 1 waveform generate control register 7 */
typedef union {
	struct{
		UINT8	mod0_g1pocr7:1;  
		UINT8	mod1_g1pocr7:1;  
		UINT8	mod2_g1pocr7:1;  
		UINT8	bit3:1;  
		UINT8	ivl_g1pocr7:1;  
		UINT8	rld_g1pocr7:1;  
		UINT8  	bit6:1;
		UINT8	inv_g1pocr7:1;  
	} bit;
	UINT8 byte;
} G1POCR7_ADDR;
G1POCR7_ADDR	g1pocr7_addr;

#define		G1POCR7				g1pocr7_addr.byte
#define		MOD0_G1POCR7      	g1pocr7_addr.bit.mod0_g1pocr7
#define		MOD1_G1POCR7    	g1pocr7_addr.bit.mod1_g1pocr7
#define		MOD2_G1POCR7      	g1pocr7_addr.bit.mod2_g1pocr7
#define		IVL_G1POCR7       	g1pocr7_addr.bit.ivl_g1pocr7
#define		RLD_G1POCR7     	g1pocr7_addr.bit.rld_g1pocr7
#define		INV_G1POCR7       	g1pocr7_addr.bit.inv_g1pocr7

/*------------------------------------------------------
    Group 1 time measurement control register 0
------------------------------------------------------*/
#pragma ADDRESS     g1tmcr0_addr 0118H      /* Group 1 time measurement control register 0 */
typedef union {
	struct{
		UINT8	cts0_g1tmcr0:1;  
		UINT8	cts1_g1tmcr0:1;  
		UINT8	df0_g1tmcr0:1;  
		UINT8	df1_g1tmcr0:1;  
		UINT8	gt_g1tmcr0:1;  
		UINT8	goc_g1tmcr0:1;  
		UINT8  	gsc_g1tmcr0:1;
		UINT8	pr_g1tmcr0:1;  
	} bit;
	UINT8 byte;
} G1TMCR0_ADDR;
G1TMCR0_ADDR	g1tmcr0_addr;

#define		G1TMCR0	 		g1tmcr0_addr.byte
#define		CTS0_G1TMCR0  	g1tmcr0_addr.bit.cts0_g1tmcr0
#define		CTS1_G1TMCR0  	g1tmcr0_addr.bit.cts1_g1tmcr0
#define		DF0_G1TMCR0   	g1tmcr0_addr.bit.df0_g1tmcr0
#define		DF1_G1TMCR0   	g1tmcr0_addr.bit.df1_g1tmcr0
#define		GT_G1TMCR0   	g1tmcr0_addr.bit.gt_g1tmcr0
#define		GOC_G1TMCR0    	g1tmcr0_addr.bit.goc_g1tmcr0
#define		GSC_G1TMCR0    	g1tmcr0_addr.bit.gsc_g1tmcr0
#define		PR_G1TMCR0    	g1tmcr0_addr.bit.pr_g1tmcr0
	

/*------------------------------------------------------
    Group 1 time measurement control register 1
------------------------------------------------------*/
#pragma ADDRESS     g1tmcr1_addr 0119H      /* Group 1 time measurement control register 1 */
typedef union {
	struct{
		UINT8	cts0_g1tmcr1:1;  
		UINT8	cts1_g1tmcr1:1;  
		UINT8	df0_g1tmcr1:1;  
		UINT8	df1_g1tmcr1:1;  
		UINT8	gt_g1tmcr1:1;  
		UINT8	goc_g1tmcr1:1;  
		UINT8  	gsc_g1tmcr1:1;
		UINT8	pr_g1tmcr1:1;  
	} bit;
	UINT8 byte;
} G1TMCR1_ADDR;
G1TMCR1_ADDR	g1tmcr1_addr;

#define		G1TMCR1	 		g1tmcr1_addr.byte
#define		CTS0_G1TMCR1  	g1tmcr1_addr.bit.cts0_g1tmcr1
#define		CTS1_G1TMCR1  	g1tmcr1_addr.bit.cts1_g1tmcr1
#define		DF0_G1TMCR1   	g1tmcr1_addr.bit.df0_g1tmcr1
#define		DF1_G1TMCR1   	g1tmcr1_addr.bit.df1_g1tmcr1
#define		GT_G1TMCR1   	g1tmcr1_addr.bit.gt_g1tmcr1
#define		GOC_G1TMCR1    	g1tmcr1_addr.bit.goc_g1tmcr1
#define		GSC_G1TMCR1    	g1tmcr1_addr.bit.gsc_g1tmcr1
#define		PR_G1TMCR1    	g1tmcr1_addr.bit.pr_g1tmcr1

/*------------------------------------------------------
    Group 1 time measurement control register 2
------------------------------------------------------*/
#pragma ADDRESS     g1tmcr2_addr 011aH      /* Group 1 time measurement control register 2 */
typedef union {
	struct{
		UINT8	cts0_g1tmcr2:1;  
		UINT8	cts1_g1tmcr2:1;  
		UINT8	df0_g1tmcr2:1;  
		UINT8	df1_g1tmcr2:1;  
		UINT8	gt_g1tmcr2:1;  
		UINT8	goc_g1tmcr2:1;  
		UINT8  	gsc_g1tmcr2:1;
		UINT8	pr_g1tmcr2:1;  
	} bit;
	UINT8 byte;
} G1TMCR2_ADDR;
G1TMCR2_ADDR	g1tmcr2_addr;

#define		G1TMCR2	 		g1tmcr2_addr.byte
#define		CTS0_G1TMCR2  	g1tmcr2_addr.bit.cts0_g1tmcr2
#define		CTS1_G1TMCR2  	g1tmcr2_addr.bit.cts1_g1tmcr2
#define		DF0_G1TMCR2   	g1tmcr2_addr.bit.df0_g1tmcr2
#define		DF1_G1TMCR2   	g1tmcr2_addr.bit.df1_g1tmcr2
#define		GT_G1TMCR2   	g1tmcr2_addr.bit.gt_g1tmcr2
#define		GOC_G1TMCR2    	g1tmcr2_addr.bit.goc_g1tmcr2
#define		GSC_G1TMCR2    	g1tmcr2_addr.bit.gsc_g1tmcr2
#define		PR_G1TMCR2    	g1tmcr2_addr.bit.pr_g1tmcr2

/*------------------------------------------------------
    Group 1 time measurement control register 3
------------------------------------------------------*/
#pragma ADDRESS     g1tmcr3_addr 011bH      /* Group 1 time measurement control register 3 */
typedef union {
	struct{
		UINT8	cts0_g1tmcr3:1;  
		UINT8	cts1_g1tmcr3:1;  
		UINT8	df0_g1tmcr3:1;  
		UINT8	df1_g1tmcr3:1;  
		UINT8	gt_g1tmcr3:1;  
		UINT8	goc_g1tmcr3:1;  
		UINT8  	gsc_g1tmcr3:1;
		UINT8	pr_g1tmcr3:1;  
	} bit;
	UINT8 byte;
} G1TMCR3_ADDR;
G1TMCR3_ADDR	g1tmcr3_addr;

#define		G1TMCR3	 		g1tmcr3_addr.byte
#define		CTS0_G1TMCR3  	g1tmcr3_addr.bit.cts0_g1tmcr3
#define		CTS1_G1TMCR3  	g1tmcr3_addr.bit.cts1_g1tmcr3
#define		DF0_G1TMCR3   	g1tmcr3_addr.bit.df0_g1tmcr3
#define		DF1_G1TMCR3   	g1tmcr3_addr.bit.df1_g1tmcr3
#define		GT_G1TMCR3   	g1tmcr3_addr.bit.gt_g1tmcr3
#define		GOC_G1TMCR3    	g1tmcr3_addr.bit.goc_g1tmcr3
#define		GSC_G1TMCR3    	g1tmcr3_addr.bit.gsc_g1tmcr3
#define		PR_G1TMCR3    	g1tmcr3_addr.bit.pr_g1tmcr3

/*------------------------------------------------------
    Group 1 time measurement control register 4
------------------------------------------------------*/
#pragma ADDRESS     g1tmcr4_addr 011cH      /* Group 1 time measurement control register 4 */
typedef union {
	struct{
		UINT8	cts0_g1tmcr4:1;  
		UINT8	cts1_g1tmcr4:1;  
		UINT8	df0_g1tmcr4:1;  
		UINT8	df1_g1tmcr4:1;  
		UINT8	gt_g1tmcr4:1;  
		UINT8	goc_g1tmcr4:1;  
		UINT8  	gsc_g1tmcr4:1;
		UINT8 	pr_g1tmcr4:1;  
	} bit;
	UINT8 byte;
} G1TMCR4_ADDR;
G1TMCR4_ADDR	g1tmcr4_addr;

#define		G1TMCR	 		g1tmcr4_addr.byte
#define		CTS0_G1TMCR4  	g1tmcr4_addr.bit.cts0_g1tmcr4
#define		CTS1_G1TMCR4  	g1tmcr4_addr.bit.cts1_g1tmcr4
#define		DF0_G1TMCR4   	g1tmcr4_addr.bit.df0_g1tmcr4
#define		DF1_G1TMCR4   	g1tmcr4_addr.bit.df1_g1tmcr4
#define		GT_G1TMCR4   	g1tmcr4_addr.bit.gt_g1tmcr4
#define		GOC_G1TMCR4    	g1tmcr4_addr.bit.goc_g1tmcr4
#define		GSC_G1TMCR4    	g1tmcr4_addr.bit.gsc_g1tmcr4
#define		PR_G1TMCR4    	g1tmcr4_addr.bit.pr_g1tmcr4

/*------------------------------------------------------
    Group 1 time measurement control register 5
------------------------------------------------------*/
#pragma ADDRESS     g1tmcr5_addr 011dH      /* Group 1 time measurement control register 5 */
typedef union {
	struct{
		UINT8	cts0_g1tmcr5:1;  
		UINT8	cts1_g1tmcr5:1;  
		UINT8	df0_g1tmcr5:1;  
		UINT8	df1_g1tmcr5:1;  
		UINT8	gt_g1tmcr5:1;  
		UINT8	goc_g1tmcr5:1;  
		UINT8  	gsc_g1tmcr5:1;
		UINT8 	pr_g1tmcr5:1;  
	} bit;
	UINT8 byte;
} G1TMCR5_ADDR;
G1TMCR5_ADDR	g1tmcr5_addr;

#define		G1TMCR5	 		g1tmcr5_addr.byte
#define		CTS0_G1TMCR5  	g1tmcr5_addr.bit.cts0_g1tmcr5
#define		CTS1_G1TMCR5  	g1tmcr5_addr.bit.cts1_g1tmcr5
#define		DF0_G1TMCR5   	g1tmcr5_addr.bit.df0_g1tmcr5
#define		DF1_G1TMCR5   	g1tmcr5_addr.bit.df1_g1tmcr5
#define		GT_G1TMCR5   	g1tmcr5_addr.bit.gt_g1tmcr5
#define		GOC_G1TMCR5   	g1tmcr5_addr.bit.goc_g1tmcr5
#define		GSC_G1TMCR5    	g1tmcr5_addr.bit.gsc_g1tmcr5
#define		PR_G1TMCR5    	g1tmcr5_addr.bit.pr_g1tmcr5

/*------------------------------------------------------
    Group 1 time measurement control register 6
------------------------------------------------------*/
#pragma ADDRESS     g1tmcr6_addr 011eH      /* Group 1 time measurement control register 6 */
typedef union {
	struct{
		UINT8	cts0_g1tmcr6:1;  
		UINT8	cts1_g1tmcr6:1;  
		UINT8	df0_g1tmcr6:1;  
		UINT8	df1_g1tmcr6:1;  
		UINT8	gt_g1tmcr6:1;  
		UINT8	goc_g1tmcr6:1;  
		UINT8  	gsc_g1tmcr6:1;
		UINT8 	pr_g1tmcr6:1;  
	} bit;
	UINT8 byte;
} G1TMCR6_ADDR;
G1TMCR6_ADDR	g1tmcr6_addr;

#define		G1TMCR6	 		g1tmcr6_addr.byte
#define		CTS0_G1TMCR6  	g1tmcr6_addr.bit.cts0_g1tmcr6
#define		CTS1_G1TMCR6  	g1tmcr6_addr.bit.cts1_g1tmcr6
#define		DF0_G1TMCR6   	g1tmcr6_addr.bit.df0_g1tmcr6
#define		DF1_G1TMCR6   	g1tmcr6_addr.bit.df1_g1tmcr6
#define		GT_G1TMCR6   	g1tmcr6_addr.bit.gt_g1tmcr6
#define		GOC_G1TMCR6   	g1tmcr6_addr.bit.goc_g1tmcr6
#define		GSC_G1TMCR6    	g1tmcr6_addr.bit.gsc_g1tmcr6
#define		PR_G1TMCR6    	g1tmcr6_addr.bit.pr_g1tmcr6

/*------------------------------------------------------
    Group 1 time measurement control register 7
------------------------------------------------------*/
#pragma ADDRESS     g1tmcr7_addr 011fH      /* Group 1 time measurement control register 7 */
typedef union {
	struct{
		UINT8	cts0_g1tmcr7:1;  
		UINT8	cts1_g1tmcr7:1;  
		UINT8	df0_g1tmcr7:1;  
		UINT8	df1_g1tmcr7:1;  
		UINT8	gt_g1tmcr7:1;  
		UINT8	goc_g1tmcr7:1;  
		UINT8  	gsc_g1tmcr7:1;
		UINT8 	pr_g1tmcr7:1;  
	} bit;
	UINT8 byte;
} G1TMCR7_ADDR;
G1TMCR7_ADDR	g1tmcr7_addr;

#define		G1TMCR7	 		g1tmcr7_addr.byte
#define		CTS0_G1TMCR7  	g1tmcr7_addr.bit.cts0_g1tmcr7
#define		CTS1_G1TMCR7  	g1tmcr7_addr.bit.cts1_g1tmcr7
#define		DF0_G1TMCR7  	g1tmcr7_addr.bit.df0_g1tmcr7
#define		DF1_G1TMCR7   	g1tmcr7_addr.bit.df1_g1tmcr7
#define		GT_G1TMCR7   	g1tmcr7_addr.bit.gt_g1tmcr7
#define		GOC_G1TMCR7   	g1tmcr7_addr.bit.goc_g1tmcr7
#define		GSC_G1TMCR7    	g1tmcr7_addr.bit.gsc_g1tmcr7
#define		PR_G1TMCR7    	g1tmcr7_addr.bit.pr_g1tmcr7

/*-------------------------------------------------*/
#pragma ADDRESS     g1bt_addr    0120H      /* Group 1 base timer register */
typedef union {
    struct{
        UINT8    g1bt_low;                /* Low  8 bit */
        UINT8    g1bt_high;               /* High 8 bit */
    } byte;
    UINT16  word;
} G1BT_ADDR;
G1BT_ADDR	g1bt_addr;

#define		G1BT       g1bt_addr.word      /* Group 1 base timer register */
#define		G1BTL      g1bt_addr.byte.g1bt_low
#define		G1BTH      g1bt_addr.byte.g1bt_high

/*------------------------------------------------------
    Group 1 base timer control register 0
------------------------------------------------------*/
#pragma ADDRESS     g1bcr0_addr  0122H      /* Group 1 base timer control register 0 */
typedef union {
	struct{
		UINT8	bck0_g1bcr0:1;  
		UINT8	bck1_g1bcr0:1;  
		UINT8	div0_g1bcr0:1;  
		UINT8	div1_g1bcr0:1;  
		UINT8	div2_g1bcr0:1;  
		UINT8	div3_g1bcr0:1;  
		UINT8  	div4_g1bcr0:1;
		UINT8	it_g1bcr0:1;  
	} bit;
	UINT8 byte;
} G1BCR0_ADDR;
G1BCR0_ADDR	g1bcr0_addr;

#define		G1BCR0	   		 g1bcr0_addr.byte
#define		BCK0_G1BCR0      g1bcr0_addr.bit.bck0_g1bcr0
#define		BCK1_G1BCR0      g1bcr0_addr.bit.bck1_g1bcr0
#define		DIV0_G1BCR0      g1bcr0_addr.bit.div0_g1bcr0
#define		DIV1_G1BCR0      g1bcr0_addr.bit.div1_g1bcr0
#define		DIV2_G1BCR0      g1bcr0_addr.bit.div2_g1bcr0
#define		DIV3_G1BCR0      g1bcr0_addr.bit.div3_g1bcr0
#define		DIV4_G1BCR0      g1bcr0_addr.bit.div4_g1bcr0
#define		IT_G1BCR0     	 g1bcr0_addr.bit.it_g1bcr0

/*------------------------------------------------------
    Group 1 base timer control register 1
------------------------------------------------------*/
#pragma ADDRESS     g1bcr1_addr  0123H      /* Group 1 base timer control register 1 */
typedef union {
	struct{
		UINT8	rst0_g1bcr1:1;  
		UINT8	rst1_g1bcr1:1;  
		UINT8	rst2_g1bcr1:1;  
		UINT8	rst3_g1bcr1:1;  
		UINT8	bts_g1bcr1:1;  
		UINT8	ud0_g1bcr1:1;  
		UINT8  	ud1_g1bcr1:1;
		UINT8	cas_g1bcr1:1;  
	} bit;
	UINT8 byte;
} G1BCR1_ADDR;
G1BCR1_ADDR	g1bcr1_addr;

#define		G1BCR1	   		 g1bcr1_addr.byte
#define		RST0_G1BCR1      g1bcr1_addr.bit.rst0_g1bcr1
#define		RST1_G1BCR1      g1bcr1_addr.bit.rst1_g1bcr1
#define		RST2_G1BCR1      g1bcr1_addr.bit.rst2_g1bcr1
#define		RST3_G1BCR1      g1bcr1_addr.bit.rst3_g1bcr1
#define		BTS_G1BCR1       g1bcr1_addr.bit.bts_g1bcr1
#define		UD0_G1BCR1       g1bcr1_addr.bit.ud0_g1bcr1
#define		UD1_G1BCR1       g1bcr1_addr.bit.ud1_g1bcr1
#define		CAS_G1BCR1   	 g1bcr1_addr.bit.cas_g1bcr1

/*------------------------------------------------------
    Group 1 time measurement prescaler register 6
------------------------------------------------------*/
#pragma ADDRESS     g1tpr6_addr  0124H      /* Group 1 time measurement prescaler register 6 */
typedef union {
	UINT8 byte;
} G1TPR6_ADDR;
G1TPR6_ADDR	g1tpr6_addr;
#define		G1TPR6      g1tpr6_addr.byte

/*------------------------------------------------------
    Group 1 time measurement prescaler register 7
------------------------------------------------------*/
#pragma ADDRESS     g1tpr7_addr  0125H      /* Group 1 time measurement prescaler register 7 */
typedef union {
	UINT8 byte;
} G1TPR7_ADDR;
G1TPR7_ADDR	g1tpr7_addr;
#define		G1TPR7      g1tpr7_addr.byte

/*------------------------------------------------------
    Group 1 function enable register
------------------------------------------------------*/
#pragma ADDRESS     g1fe_addr    0126H      /* Group 1 function enable register */
typedef union {
	struct{
		UINT8	ife0_g1fe:1;  
		UINT8	ife1_g1fe:1;  
		UINT8	ife2_g1fe:1;  
		UINT8	ife3_g1fe:1;  
		UINT8	ife4_g1fe:1;  
		UINT8	ife5_g1fe:1;  
		UINT8  	ife6_g1fe:1;
		UINT8	ife7_g1fe:1;  
	} bit;
	UINT8 byte;
} G1FE_ADDR;
G1FE_ADDR	g1fe_addr;

#define		G1FE		   	 g1fe_addr.byte
#define		IFE0_G1FE        g1fe_addr.bit.ife0_g1fe
#define		IFE1_G1FE        g1fe_addr.bit.ife1_g1fe
#define		IFE2_G1FE        g1fe_addr.bit.ife2_g1fe
#define		IFE3_G1FE        g1fe_addr.bit.ife3_g1fe
#define		IFE4_G1FE        g1fe_addr.bit.ife4_g1fe
#define		IFE5_G1FE        g1fe_addr.bit.ife5_g1fe
#define		IFE6_G1FE        g1fe_addr.bit.ife6_g1fe
#define		IFE7_G1FE        g1fe_addr.bit.ife7_g1fe

/*------------------------------------------------------
    Group 1 function select register
------------------------------------------------------*/
#pragma ADDRESS     g1fs_addr    0127H      /* Group 1 function select register */
typedef union {
	struct{
		UINT8	b0:1;
		UINT8	b1:1;
		UINT8	b2:1;
		UINT8	b3:1;
		UINT8	b4:1;
		UINT8	fsc5_g1fs:1;
		UINT8	fsc6_g1fs:1;
		UINT8	fsc7_g1fs:1;
	} bit;
	 UINT8 byte;
} G1FS_ADDR;
G1FS_ADDR	g1fs_addr;

#define		G1FS		g1fs_addr.byte

#define		FSC5_G1FS	g1fs_addr.bit.fsc5_g1fs
#define		FSC6_G1FS	g1fs_addr.bit.fsc6_g1fs
#define		FSC7_G1FS	g1fs_addr.bit.fsc7_g1fs

/*------------------------------------------------------
     g1rb
------- -----------------------------------------------*/
#pragma ADDRESS     g1rb_addr    0128H      /* Group 1 SI/O communication buffer register */
typedef union {
    struct{
        UINT8    b0:1;
        UINT8    b1:1;
        UINT8    b2:1;
        UINT8    b3:1;
        UINT8    b4:1;
        UINT8    b5:1;
        UINT8    b6:1;
        UINT8    b7:1;
        UINT8    b8:1;
        UINT8    b9:1;
        UINT8    b10:1;
        UINT8    b11:1;
        UINT8    oer_g1rb:1;              /* Overrun error flag */
        UINT8    fer_g1rb:1;              /* Framing error flag */
        UINT8    per_g1rb:1;              /* Parity error flag */
        UINT8    sum_g1rb:1;              /* Error sum flag */
    } bit;
    struct{
        UINT8    g1rb_low;                /* Low  8 bit */
        UINT8    g1rb_high;               /* High 8 bit */
    } byte;
    UINT16  word;
} G1RB_ADDR;
G1RB_ADDR	g1rb_addr;

#define		G1RB   		g1rb_addr.word
#define		G1RBL   	g1rb_addr.byte.g1rb_low
#define		G1RBH   	g1rb_addr.byte.g1rb_high
#define		OER_G1RB   	g1rb_addr.bit.oer_g1rb   /* Overrun error flag */
#define		FER_G1RB   	g1rb_addr.bit.fer_g1rb   /* Framing error flag */
//#define   PER_G1RB   	g1rb_addr.bit.per_g1rb   /* Parity error flag */
//#define   SUM_G1RB   	g1rb_addr.bit.sum_g1rb   /* Error sum flag */

/*------------------------------------------------------
    Group 1 SI/O transmitting buffer register
------------------------------------------------------*/
#pragma ADDRESS     g1tb_addr    012aH      /* Group 1 SI/O transmiting data register */
typedef union {
	struct{
		UINT8	b0:1;
		UINT8	b1:1;
		UINT8	b2:1;
		UINT8	b3:1;
		UINT8	b4:1;
		UINT8	b5:1;
		UINT8	b6:1;
		UINT8	b7:1;
	} bit;
	 UINT8 byte;
} G1TB_ADDR;
G1TB_ADDR	g1tb_addr;

#define		G1TB		g1tb_addr.byte

/*------------------------------------------------------
    Group 1 receive data register
------------------------------------------------------*/
#pragma ADDRESS     g1dr_addr    012aH      /* Group 1 receive data register */
UINT8	g1dr_addr;
#define		G1DR       g1dr_addr

/*------------------------------------------------------
    Group 1 receive input register
------------------------------------------------------*/
#pragma ADDRESS     g1ri_addr    012cH      /* Group 1 receive input register */
typedef union {
	struct{
		UINT8	b0:1;
		UINT8	b1:1;
		UINT8	b2:1;
		UINT8	b3:1;
		UINT8	b4:1;
		UINT8	b5:1;
		UINT8	b6:1;
		UINT8	b7:1;
	} bit;
	 UINT8 byte;
} G1RI_ADDR;
G1RI_ADDR	g1ri_addr;

#define		G1RI		g1ri_addr.byte

/*------------------------------------------------------
    Group 1 SI/O communication mode register
------------------------------------------------------*/
#pragma ADDRESS     g1mr_addr    012dH      /* Group 1 SI/O communication mode register */
typedef union {
	struct{
		UINT8	GMD0_G1MR:1;
		UINT8	gmd1_g1mr:1;
		UINT8	ckdir_g1mr:1;
		UINT8	stps_g1mr:1;
		UINT8	b4:1;
		UINT8	b5:1;
		UINT8	uform_g1mr:1;
		UINT8	irs_g1mr:1;
	} bit;
	 UINT8 byte;
} G1MR_ADDR;
G1MR_ADDR	g1mr_addr;

#define		G1MR		g1mr_addr.byte

#define		GMD0_G1MR	g1mr_addr.bit.GMD0_G1MR
#define		GMD1_G1MR	g1mr_addr.bit.gmd1_g1mr
#define		CKDIR_G1MR	g1mr_addr.bit.ckdir_g1mr
#define		STPS_G1MR	g1mr_addr.bit.stps_g1mr
#define		UFORM_G1MR	g1mr_addr.bit.uform_g1mr
#define		IRS_G1MR	g1mr_addr.bit.irs_g1mr

/*------------------------------------------------------
    Group 1 transmit output register
------------------------------------------------------*/
#pragma ADDRESS     g1to_addr    012eH      /* Group 1 transmit output register */
typedef union {
	struct{
		UINT8	b0:1;
		UINT8	b1:1;
		UINT8	b2:1;
		UINT8	b3:1;
		UINT8	b4:1;
		UINT8	b5:1;
		UINT8	b6:1;
		UINT8	b7:1;
	} bit;
	 UINT8 byte;
} G1TO_ADDR;
G1TO_ADDR	g1to_addr;

#define		G1TO		g1to_addr.byte

/*------------------------------------------------------
    Group 1 SI/O communication control register
------------------------------------------------------*/
#pragma ADDRESS     g1cr_addr    012fH      /* Group 1 SI/O communication control register */
typedef union {
	struct{
		UINT8	ti_g1cr:1;
		UINT8	txept_g1cr:1;
		UINT8	ri_g1cr:1;
		UINT8	b3:1;
		UINT8	te_g1cr:1;
		UINT8	re_g1cr:1;
		UINT8	ipol_g1cr:1;
		UINT8	opol_g1cr:1;
	} bit;
	 UINT8 byte;
} G1CR_ADDR;
G1CR_ADDR	g1cr_addr;

#define		G1CR		g1cr_addr.byte

#define		TI_G1CR		g1cr_addr.bit.ti_g1cr
#define		TXEPT_G1CR	g1cr_addr.bit.txept_g1cr
#define		RI_G1CR		g1cr_addr.bit.ri_g1cr
#define		TE_G1CR		g1cr_addr.bit.te_g1cr
#define		RE_G1CR		g1cr_addr.bit.re_g1cr
#define		IPOL_G1CR	g1cr_addr.bit.ipol_g1cr
#define		OPOL_G1CR	g1cr_addr.bit.opol_g1cr

/*------------------------------------------------------
    Group 1 data compare register 0
------------------------------------------------------*/
#pragma ADDRESS     g1cmp0_addr  0130H      /* Group 1 data compare register 0 */
typedef union {
	struct{
		UINT8	b0:1;
		UINT8	b1:1;
		UINT8	b2:1;
		UINT8	b3:1;
		UINT8	b4:1;
		UINT8	b5:1;
		UINT8	b6:1;
		UINT8	b7:1;
	} bit;
	 UINT8 byte;
} G1CMP0_ADDR;
G1CMP0_ADDR	g1cmp0_addr;

#define		G1CMP0		g1cmp0_addr.byte

/*------------------------------------------------------
    Group 1 data compare register 1
------------------------------------------------------*/
#pragma ADDRESS     g1cmp1_addr  0131H      /* Group 1 data compare register 1 */
typedef union {
	struct{
		UINT8	b0:1;
		UINT8	b1:1;
		UINT8	b2:1;
		UINT8	b3:1;
		UINT8	b4:1;
		UINT8	b5:1;
		UINT8	b6:1;
		UINT8	b7:1;
	} bit;
	 UINT8 byte;
} G1CMP1_ADDR;
G1CMP1_ADDR	g1cmp1_addr;

#define		G1CMP1		g1cmp1_addr.byte

/*------------------------------------------------------
    Group 1 data compare register 2
------------------------------------------------------*/
#pragma ADDRESS     g1cmp2_addr  0132H      /* Group 1 data compare register 2 */
typedef union {
	struct{
		UINT8	b0:1;
		UINT8	b1:1;
		UINT8	b2:1;
		UINT8	b3:1;
		UINT8	b4:1;
		UINT8	b5:1;
		UINT8	b6:1;
		UINT8	b7:1;
	} bit;
	 UINT8 byte;
} G1CMP2_ADDR;
G1CMP2_ADDR	g1cmp2_addr;

#define		G1CMP2		g1cmp2_addr.byte

/*------------------------------------------------------
    Group 1 data compare register 3
------------------------------------------------------*/
#pragma ADDRESS     g1cmp3_addr  0133H      /* Group 1 data compare register 3 */
typedef union {
	struct{
		UINT8	b0:1;
		UINT8	b1:1;
		UINT8	b2:1;
		UINT8	b3:1;
		UINT8	b4:1;
		UINT8	b5:1;
		UINT8	b6:1;
		UINT8	b7:1;
	} bit;
	 UINT8 byte;
} G1CMP3_ADDR;
G1CMP3_ADDR	g1cmp3_addr;

#define		G1CMP3		g1cmp3_addr.byte

/*------------------------------------------------------
    Group 1 data mask register 0
------------------------------------------------------*/
#pragma ADDRESS     g1msk0_addr  0134H      /* Group 1 data mask register 0 */
typedef union {
	struct{
		UINT8	b0:1;
		UINT8	b1:1;
		UINT8	b2:1;
		UINT8	b3:1;
		UINT8	b4:1;
		UINT8	b5:1;
		UINT8	b6:1;
		UINT8	b7:1;
	} bit;
	 UINT8 byte;
} G1MSK0_ADDR;
G1MSK0_ADDR	g1msk0_addr;

#define		G1MSK0		g1msk0_addr.byte

/*------------------------------------------------------
    Group 1 data mask register 1
------------------------------------------------------*/
#pragma ADDRESS     g1msk1_addr  0135H      /* Group 1 data mask register 1 */
typedef union {
	struct{
		UINT8	b0:1;
		UINT8	b1:1;
		UINT8	b2:1;
		UINT8	b3:1;
		UINT8	b4:1;
		UINT8	b5:1;
		UINT8	b6:1;
		UINT8	b7:1;
	} bit;
	 UINT8 byte;
} G1MSK1_ADDR;
G1MSK1_ADDR	g1msk1_addr;

#define		G1MSK1		g1msk1_addr.byte

/*-------------------------------------------------------*/
#pragma ADDRESS     g1rcrc_addr  0138H      /* Group 1 receive CRC code register */
typedef union {
    struct{
        UINT8    g1rcrc_low;                /* Low  8 bit */
        UINT8    g1rcrc_high;               /* High 8 bit */
    } byte;
    UINT16  word;
} G1RCRC_ADDR;
G1RCRC_ADDR	g1rcrc_addr;

#define		G1RCRC       g1rcrc_addr.word       /* Group 1 receive CRC code register */
#define		G1RCRCL      g1rcrc_addr.byte.g1rcrc_low
#define		G1RCRCH      g1rcrc_addr.byte.g1rcrc_high

/*-------------------------------------------------------*/
#pragma ADDRESS     g1tcrc_addr  013aH      /* Group 1 transmit CRC code register */
typedef union {
    struct{
        UINT8    g1tcrc_low;                /* Low  8 bit */
        UINT8    g1tcrc_high;               /* High 8 bit */
    } byte;
    UINT16  word;
} G1TCRC_ADDR;
G1TCRC_ADDR	g1tcrc_addr;

#define		G1TCRC      g1tcrc_addr.word      /* Group 1 transmit CRC code register */
#define		G1TCRCL     g1tcrc_addr.byte.g1tcrc_low
#define		G1TCRCH     g1tcrc_addr.byte.g1tcrc_high

/*------------------------------------------------------
    Group 1 SI/O expansion mode register
------------------------------------------------------*/
#pragma ADDRESS     g1emr_addr   013cH      /* Group 1 SI/O expansion mode register */
typedef union {
	struct{
		UINT8	smode_g1emr:1;
		UINT8	crcv_g1emr:1;
		UINT8	acrc_g1emr:1;
		UINT8	bsint_g1emr:1;
		UINT8	rxsl_g1emr:1;
		UINT8	txsl_g1emr:1;
		UINT8	crc0_g1emr:1;
		UINT8	crc1_g1emr:1;
	} bit;
	 UINT8 byte;
} G1EMR_ADDR;
G1EMR_ADDR	g1emr_addr;

#define		G1EMR		g1emr_addr.byte

#define		SMODE_G1EMR	g1emr_addr.bit.smode_g1emr
#define		CRCV_G1EMR	g1emr_addr.bit.crcv_g1emr
#define		ACRC_G1EMR	g1emr_addr.bit.acrc_g1emr
#define		BSINT_G1EMR	g1emr_addr.bit.bsint_g1emr
#define		RXSL_G1EMR	g1emr_addr.bit.rxsl_g1emr
#define		TXSL_G1EMR	g1emr_addr.bit.txsl_g1emr
#define		CRC0_G1EMR	g1emr_addr.bit.crc0_g1emr
#define		CRC1_G1EMR	g1emr_addr.bit.crc1_g1emr

/*------------------------------------------------------
    Group 1 SI/O communication mode register
------------------------------------------------------*/
#pragma ADDRESS     g1erc_addr   013dH      /* Group 1 SI/O expansion receive control register */
typedef union {
	struct{
		UINT8	cmp0e_g1erc:1;
		UINT8	cmp1e_g1erc:1;
		UINT8	cmp2e_g1erc:1;
		UINT8	cmp3e_g1erc:1;
		UINT8	rcrce_g1erc:1;
		UINT8	rshte_g1erc:1;
		UINT8	rbsf0_g1erc:1;
		UINT8	rbsf1_g1erc:1;
	} bit;
	 UINT8 byte;
} G1ERC_ADDR;
G1ERC_ADDR	g1erc_addr;

#define		G1ERC		g1erc_addr.byte

#define		CMP0E_G1ERC	g1erc_addr.bit.cmp0e_g1erc
#define		CMP1E_G1ERC	g1erc_addr.bit.cmp1e_g1erc
#define		CMP2E_G1ERC	g1erc_addr.bit.cmp2e_g1erc
#define		CMP3E_G1ERC	g1erc_addr.bit.cmp3e_g1erc
#define		RCRCE_G1ERC	g1erc_addr.bit.rcrce_g1erc
#define		RSHTE_G1ERC	g1erc_addr.bit.rshte_g1erc
#define		RBSF0_G1ERC	g1erc_addr.bit.rbsf0_g1erc
#define		RBSF1_G1ERC	g1erc_addr.bit.rbsf1_g1erc

/*------------------------------------------------------
    Group 1 SI/O special communication 
            interrupt detect register
------------------------------------------------------*/
#pragma ADDRESS     g1irf_addr   013eH      /* Group 1 SI/O special communication interrupt detect register */
typedef union {
	struct{
		UINT8	b0:1;
		UINT8	b1:1;
		UINT8	bserr_g1irf:1;
		UINT8	abt_g1irf:1;
		UINT8	irf0_g1irf:1;
		UINT8	irf1_g1irf:1;
		UINT8	irf2_g1irf:1;
		UINT8	irf3_g1irf:1;
	} bit;
	 UINT8 byte;
} G1IRF_ADDR;
G1IRF_ADDR	g1irf_addr;

#define		G1IRF		g1irf_addr.byte

#define		BSERR_G1IRF	g1irf_addr.bit.bserr_g1irf
#define		ABT_G1IRF	g1irf_addr.bit.abt_g1irf
#define		IRF0_G1IRF	g1irf_addr.bit.irf0_g1irf
#define		IRF1_G1IRF	g1irf_addr.bit.irf1_g1irf
#define		IRF2_G1IRF	g1irf_addr.bit.irf2_g1irf
#define		IRF3_G1IRF	g1irf_addr.bit.irf3_g1irf

/*------------------------------------------------------
    Group 1 SI/O expansion transmit control register
------------------------------------------------------*/
#pragma ADDRESS     g1etc_addr   013fH      /* Group 1 SI/O expansion transmit control register */
typedef union {
	struct{
		UINT8	b0:1;
		UINT8	b1:1;
		UINT8	b2:1;
		UINT8	sof_g1etc:1;
		UINT8	tcrce_g1etc:1;
		UINT8	abte_g1etc:1;
		UINT8	tbsf0_g1etc:1;
		UINT8	tbsf1_g1etc:1;
	} bit;
	 UINT8 byte;
} G1ETC_ADDR;
G1ETC_ADDR	g1etc_addr;

#define		G1ETC		g1etc_addr.byte

#define		SOF_G1ETC	g1etc_addr.bit.sof_g1etc
#define		TCRCE_G1ETC	g1etc_addr.bit.tcrce_g1etc
#define		ABTE_G1ETC	g1etc_addr.bit.abte_g1etc
#define		TBSF0_G1ETC	g1etc_addr.bit.tbsf0_g1etc
#define		TBSF1_G1ETC	g1etc_addr.bit.tbsf1_g1etc

/*----------------------------------------------------*/
#pragma ADDRESS     g2po0_addr   0140H      /* Group 2 waveform generate register 0 */
typedef union {
    struct{
        UINT8    low;                /* Low  8 bit */
        UINT8    high;               /* High 8 bit */
    } byte;
    UINT16  word;
} G2PO0_ADDR;
G2PO0_ADDR	g2po0_addr;

#define		G2PO0        g2po0_addr.word      /* Group 2 waveform generate register 0 */
#define		G2PO0L       g2po0_addr.byte.low
#define		G2PO0H       g2po0_addr.byte.high

/*----------------------------------------------------*/
#pragma ADDRESS     g2po1_addr   0142H      /* Group 2 waveform generate register 1 */
typedef union {
    struct{
        UINT8    low;                /* Low  8 bit */
        UINT8    high;               /* High 8 bit */
    } byte;
    UINT16  word;
} G2PO1_ADDR;
G2PO1_ADDR	g2po1_addr;

#define		G2PO1        g2po1_addr.word      /* Group 2 waveform generate register 1 */
#define		G2PO1L       g2po1_addr.byte.low
#define		G2PO1H       g2po1_addr.byte.high

/*----------------------------------------------------*/
#pragma ADDRESS     g2po2_addr   0144H      /* Group 2 waveform generate register 2 */
typedef union {
    struct{
        UINT8    low;                /* Low  8 bit */
        UINT8    high;               /* High 8 bit */
    } byte;
    UINT16  word;
} G2PO2_ADDR;
G2PO2_ADDR	g2po2_addr;

#define		G2PO2        g2po2_addr.word      /* Group 2 waveform generate register 2 */
#define		G2PO2L       g2po2_addr.byte.low
#define		G2PO2H       g2po2_addr.byte.high

/*----------------------------------------------------*/
#pragma ADDRESS     g2po3_addr   0146H      /* Group 2 waveform generate register 3 */
typedef union {
    struct{
        UINT8    low;                /* Low  8 bit */
        UINT8    high;               /* High 8 bit */
    } byte;
    UINT16  word;
} G2PO3_ADDR;
G2PO3_ADDR	g2po3_addr;

#define		G2PO3        g2po3_addr.word      /* Group 2 waveform generate register 3 */
#define		G2PO3L       g2po3_addr.byte.low
#define		G2PO3H       g2po3_addr.byte.high

/*----------------------------------------------------*/
#pragma ADDRESS     g2po4_addr   0148H      /* Group 2 waveform generate register 4 */
typedef union {
    struct{
        UINT8    low;                /* Low  8 bit */
        UINT8    high;               /* High 8 bit */
    } byte;
    UINT16  word;
} G2PO4_ADDR;
G2PO4_ADDR	g2po4_addr;

#define		G2PO4        g2po4_addr.word      /* Group 2 waveform generate register 4 */
#define		G2PO4L       g2po4_addr.byte.low
#define		G2PO4H       g2po4_addr.byte.high

/*----------------------------------------------------*/
#pragma ADDRESS     g2po5_addr   014aH      /* Group 2 waveform generate register 5 */
typedef union {
    struct{
        UINT8    low;                /* Low  8 bit */
        UINT8    high;               /* High 8 bit */
    } byte;
    UINT16  word;
} G2PO5_ADDR;
G2PO5_ADDR	g2po5_addr;

#define		G2PO5        g2po5_addr.word      /* Group 2 waveform generate register 5 */
#define		G2PO5L       g2po5_addr.byte.low
#define		G2PO5H       g2po5_addr.byte.high

/*----------------------------------------------------*/
#pragma ADDRESS     g2po6_addr   014cH      /* Group 2 waveform generate register 6 */
typedef union {
    struct{
        UINT8    low;                /* Low  8 bit */
        UINT8    high;               /* High 8 bit */
    } byte;
    UINT16  word;
} G2PO6_ADDR;
G2PO6_ADDR	g2po6_addr;

#define		G2PO6        g2po6_addr.word      /* Group 2 waveform generate register 6 */
#define		G2PO6L       g2po6_addr.byte.low
#define		G2PO6H       g2po6_addr.byte.high

/*----------------------------------------------------*/
#pragma ADDRESS     g2po7_addr   014eH      /* Group 2 waveform generate register 7 */
typedef union {
    struct{
        UINT8    low;                /* Low  8 bit */
        UINT8    high;               /* High 8 bit */
    } byte;
    UINT16  word;
} G2PO7_ADDR;
G2PO7_ADDR	g2po7_addr;

#define		G2PO7        g2po7_addr.word      /* Group 2 waveform generate register 7 */
#define		G2PO7L       g2po7_addr.byte.low
#define		G2PO7H       g2po7_addr.byte.high

/*------------------------------------------------------
    Group 2 waveform generate control register 0
------------------------------------------------------*/
#pragma ADDRESS     g2pocr0_addr 0150H      /* Group 2 waveform generate control register 0 */
typedef union {
	struct{
		UINT8	mod0_g2pocr0:1;
		UINT8	mod1_g2pocr0:1;
		UINT8	mod2_g2pocr0:1;
		UINT8	prt_g2pocr0:1;
		UINT8	ivl_g2pocr0:1;
		UINT8	rld_g2pocr0:1;
		UINT8	rtp_g2pocr0:1;
		UINT8	inv_g2pocr0:1;
	} bit;
	 UINT8 byte;
} G2POCR0_ADDR;
G2POCR0_ADDR	g2pocr0_addr;

#define		G2POCR0		g2pocr0_addr.byte

#define		MOD0_G2POCR0	g2pocr0_addr.bit.mod0_g2pocr0
#define		MOD1_G2POCR0	g2pocr0_addr.bit.mod1_g2pocr0
#define		MOD2_G2POCR0	g2pocr0_addr.bit.mod2_g2pocr0
#define		PRT_G2POCR0	g2pocr0_addr.bit.prt_g2pocr0
#define		IVL_G2POCR0	g2pocr0_addr.bit.ivl_g2pocr0
#define		RLD_G2POCR0	g2pocr0_addr.bit.rld_g2pocr0
#define		RTP_G2POCR0	g2pocr0_addr.bit.rtp_g2pocr0
#define		INV_G2POCR0	g2pocr0_addr.bit.inv_g2pocr0

/*------------------------------------------------------
    Group 2 waveform generate control register 1
------------------------------------------------------*/
#pragma ADDRESS     g2pocr1_addr 0151H      /* Group 2 waveform generate control register 1 */
typedef union {
	struct{
		UINT8	mod0_g2pocr1:1;
		UINT8	mod1_g2pocr1:1;
		UINT8	mod2_g2pocr1:1;
		UINT8	prt_g2pocr1:1;
		UINT8	ivl_g2pocr1:1;
		UINT8	rld_g2pocr1:1;
		UINT8	rtp_g2pocr1:1;
		UINT8	inv_g2pocr1:1;
	} bit;
	 UINT8 byte;
} G2POCR1_ADDR;
G2POCR1_ADDR	g2pocr1_addr;

#define		G2POCR1		g2pocr1_addr.byte

#define		MOD0_G2POCR1	g2pocr1_addr.bit.mod0_g2pocr1
#define		MOD1_G2POCR1	g2pocr1_addr.bit.mod1_g2pocr1
#define		MOD2_G2POCR1	g2pocr1_addr.bit.mod2_g2pocr1
#define		PRT_G2POCR1	g2pocr1_addr.bit.prt_g2pocr1
#define		IVL_G2POCR1	g2pocr1_addr.bit.ivl_g2pocr1
#define		RLD_G2POCR1	g2pocr1_addr.bit.rld_g2pocr1
#define		RTP_G2POCR1	g2pocr1_addr.bit.rtp_g2pocr1
#define		INV_G2POCR1	g2pocr1_addr.bit.inv_g2pocr1

/*------------------------------------------------------
    Group 2 waveform generate control register 2
------------------------------------------------------*/
#pragma ADDRESS     g2pocr2_addr 0152H      /* Group 2 waveform generate control register 2 */
typedef union {
	struct{
		UINT8	mod0_g2pocr2:1;
		UINT8	mod1_g2pocr2:1;
		UINT8	mod2_g2pocr2:1;
		UINT8	prt_g2pocr2:1;
		UINT8	ivl_g2pocr2:1;
		UINT8	rld_g2pocr2:1;
		UINT8	rtp_g2pocr2:1;
		UINT8	inv_g2pocr2:1;
	} bit;
	 UINT8 byte;
} G2POCR2_ADDR;
G2POCR2_ADDR	g2pocr2_addr;

#define		G2POCR2		g2pocr2_addr.byte

#define		MOD0_G2POCR2	g2pocr2_addr.bit.mod0_g2pocr2
#define		MOD1_G2POCR2	g2pocr2_addr.bit.mod1_g2pocr2
#define		MOD2_G2POCR2	g2pocr2_addr.bit.mod2_g2pocr2
#define		PRT_G2POCR2	g2pocr2_addr.bit.prt_g2pocr2
#define		IVL_G2POCR2	g2pocr2_addr.bit.ivl_g2pocr2
#define		RLD_G2POCR2	g2pocr2_addr.bit.rld_g2pocr2
#define		RTP_G2POCR2	g2pocr2_addr.bit.rtp_g2pocr2
#define		INV_G2POCR2	g2pocr2_addr.bit.inv_g2pocr2

/*------------------------------------------------------
    Group 2 waveform generate control register 3
------------------------------------------------------*/
#pragma ADDRESS     g2pocr3_addr 0153H      /* Group 2 waveform generate control register 3 */
typedef union {
	struct{
		UINT8	mod0_g2pocr3:1;
		UINT8	mod1_g2pocr3:1;
		UINT8	mod2_g2pocr3:1;
		UINT8	prt_g2pocr3:1;
		UINT8	ivl_g2pocr3:1;
		UINT8	rld_g2pocr3:1;
		UINT8	rtp_g2pocr3:1;
		UINT8	inv_g2pocr3:1;
	} bit;
	 UINT8 byte;
} G2POCR3_ADDR;
G2POCR3_ADDR	g2pocr3_addr;

#define		G2POCR3		g2pocr3_addr.byte

#define		MOD0_G2POCR3	g2pocr3_addr.bit.mod0_g2pocr3
#define		MOD1_G2POCR3	g2pocr3_addr.bit.mod1_g2pocr3
#define		MOD2_G2POCR3	g2pocr3_addr.bit.mod2_g2pocr3
#define		PRT_G2POCR3	g2pocr3_addr.bit.prt_g2pocr3
#define		IVL_G2POCR3	g2pocr3_addr.bit.ivl_g2pocr3
#define		RLD_G2POCR3	g2pocr3_addr.bit.rld_g2pocr3
#define		RTP_G2POCR3	g2pocr3_addr.bit.rtp_g2pocr3
#define		INV_G2POCR3	g2pocr3_addr.bit.inv_g2pocr3

/*------------------------------------------------------
    Group 2 waveform generate control register 4
------------------------------------------------------*/
#pragma ADDRESS     g2pocr4_addr 0154H      /* Group 2 waveform generate control register 4 */
typedef union {
	struct{
		UINT8	mod0_g2pocr4:1;
		UINT8	mod1_g2pocr4:1;
		UINT8	mod2_g2pocr4:1;
		UINT8	prt_g2pocr4:1;
		UINT8	ivl_g2pocr4:1;
		UINT8	rld_g2pocr4:1;
		UINT8	rtp_g2pocr4:1;
		UINT8	inv_g2pocr4:1;
	} bit;
	 UINT8 byte;
} G2POCR4_ADDR;
G2POCR4_ADDR	g2pocr4_addr;

#define		G2POCR4		g2pocr4_addr.byte

#define		MOD0_G2POCR4	g2pocr4_addr.bit.mod0_g2pocr4
#define		MOD1_G2POCR4	g2pocr4_addr.bit.mod1_g2pocr4
#define		MOD2_G2POCR4	g2pocr4_addr.bit.mod2_g2pocr4
#define		PRT_G2POCR4	g2pocr4_addr.bit.prt_g2pocr4
#define		IVL_G2POCR4	g2pocr4_addr.bit.ivl_g2pocr4
#define		RLD_G2POCR4	g2pocr4_addr.bit.rld_g2pocr4
#define		RTP_G2POCR4	g2pocr4_addr.bit.rtp_g2pocr4
#define		INV_G2POCR4	g2pocr4_addr.bit.inv_g2pocr4

/*------------------------------------------------------
    Group 2 waveform generate control register 5
------------------------------------------------------*/
#pragma ADDRESS     g2pocr5_addr 0155H      /* Group 2 waveform generate control register 5 */
typedef union {
	struct{
		UINT8	mod0_g2pocr5:1;
		UINT8	mod1_g2pocr5:1;
		UINT8	mod2_g2pocr5:1;
		UINT8	prt_g2pocr5:1;
		UINT8	ivl_g2pocr5:1;
		UINT8	rld_g2pocr5:1;
		UINT8	rtp_g2pocr5:1;
		UINT8	inv_g2pocr5:1;
	} bit;
	 UINT8 byte;
} G2POCR5_ADDR;
G2POCR5_ADDR	g2pocr5_addr;

#define		G2POCR5		g2pocr5_addr.byte

#define		MOD0_G2POCR5	g2pocr5_addr.bit.mod0_g2pocr5
#define		MOD1_G2POCR5	g2pocr5_addr.bit.mod1_g2pocr5
#define		MOD2_G2POCR5	g2pocr5_addr.bit.mod2_g2pocr5
#define		PRT_G2POCR5	g2pocr5_addr.bit.prt_g2pocr5
#define		IVL_G2POCR5	g2pocr5_addr.bit.ivl_g2pocr5
#define		RLD_G2POCR5	g2pocr5_addr.bit.rld_g2pocr5
#define		RTP_G2POCR5	g2pocr5_addr.bit.rtp_g2pocr5
#define		INV_G2POCR5	g2pocr5_addr.bit.inv_g2pocr5

/*------------------------------------------------------
    Group 2 waveform generate control register 6
------------------------------------------------------*/
#pragma ADDRESS     g2pocr6_addr 0156H      /* Group 2 waveform generate control register 6 */
typedef union {
	struct{
		UINT8	mod0_g2pocr6:1;
		UINT8	mod1_g2pocr6:1;
		UINT8	mod2_g2pocr6:1;
		UINT8	prt_g2pocr6:1;
		UINT8	ivl_g2pocr6:1;
		UINT8	rld_g2pocr6:1;
		UINT8	rtp_g2pocr6:1;
		UINT8	inv_g2pocr6:1;
	} bit;
	 UINT8 byte;
} G2POCR6_ADDR;
G2POCR6_ADDR	g2pocr6_addr;

#define		G2POCR6		g2pocr6_addr.byte

#define		MOD0_G2POCR6	g2pocr6_addr.bit.mod0_g2pocr6
#define		MOD1_G2POCR6	g2pocr6_addr.bit.mod1_g2pocr6
#define		MOD2_G2POCR6	g2pocr6_addr.bit.mod2_g2pocr6
#define		PRT_G2POCR6	g2pocr6_addr.bit.prt_g2pocr6
#define		IVL_G2POCR6	g2pocr6_addr.bit.ivl_g2pocr6
#define		RLD_G2POCR6	g2pocr6_addr.bit.rld_g2pocr6
#define		RTP_G2POCR6	g2pocr6_addr.bit.rtp_g2pocr6
#define		INV_G2POCR6	g2pocr6_addr.bit.inv_g2pocr6

/*------------------------------------------------------
    Group 2 waveform generate control register 7
------------------------------------------------------*/
#pragma ADDRESS     g2pocr7_addr 0157H      /* Group 2 waveform generate control register 7 */
typedef union {
	struct{
		UINT8	mod0_g2pocr7:1;
		UINT8	mod1_g2pocr7:1;
		UINT8	mod2_g2pocr7:1;
		UINT8	prt_g2pocr7:1;
		UINT8	ivl_g2pocr7:1;
		UINT8	rld_g2pocr7:1;
		UINT8	rtp_g2pocr7:1;
		UINT8	inv_g2pocr7:1;
	} bit;
	 UINT8 byte;
} G2POCR7_ADDR;
G2POCR7_ADDR	g2pocr7_addr;

#define		G2POCR7		g2pocr7_addr.byte

#define		MOD0_G2POCR7	g2pocr7_addr.bit.mod0_g2pocr7
#define		MOD1_G2POCR7	g2pocr7_addr.bit.mod1_g2pocr7
#define		MOD2_G2POCR7	g2pocr7_addr.bit.mod2_g2pocr7
#define		PRT_G2POCR7	g2pocr7_addr.bit.prt_g2pocr7
#define		IVL_G2POCR7	g2pocr7_addr.bit.ivl_g2pocr7
#define		RLD_G2POCR7	g2pocr7_addr.bit.rld_g2pocr7
#define		RTP_G2POCR7	g2pocr7_addr.bit.rtp_g2pocr7
#define		INV_G2POCR7	g2pocr7_addr.bit.inv_g2pocr7

/*----------------------------------------------------*/
#pragma ADDRESS     g2bt_addr    0160H      /* Group 2 base timer register */
typedef union {
    struct{
        UINT8    low;                /* Low  8 bit */
        UINT8    high;               /* High 8 bit */
    } byte;
    UINT16  word;
} G2BT_ADDR;
G2BT_ADDR	g2bt_addr;

#define		G2BT        g2bt_addr.word      /* Group 2 base timer register */
#define		G2BTL       g2bt_addr.byte.low
#define		G2BTH       g2bt_addr.byte.high

/*------------------------------------------------------
    Group 2 base timer control register 0
------------------------------------------------------*/
#pragma ADDRESS     g2bcr0_addr  0162H      /* Group 2 base timer control register 0 */
typedef union {
	struct{
		UINT8	bck0_g2bcr0:1;
		UINT8	bck1_g2bcr0:1;
		UINT8	div0_g2bcr0:1;
		UINT8	div1_g2bcr0:1;
		UINT8	div2_g2bcr0:1;
		UINT8	div3_g2bcr0:1;
		UINT8	div4_g2bcr0:1;
		UINT8	it_g2bcr0:1;
	} bit;
	 UINT8 byte;
} G2BCR0_ADDR;
G2BCR0_ADDR	g2bcr0_addr;

#define		G2BCR0		g2bcr0_addr.byte

#define		BCK0_G2BCR0	g2bcr0_addr.bit.bck0_g2bcr0
#define		BCK1_G2BCR0	g2bcr0_addr.bit.bck1_g2bcr0
#define		DIV0_G2BCR0	g2bcr0_addr.bit.div0_g2bcr0
#define		DIV1_G2BCR0	g2bcr0_addr.bit.div1_g2bcr0
#define		DIV2_G2BCR0	g2bcr0_addr.bit.div2_g2bcr0
#define		DIV3_G2BCR0	g2bcr0_addr.bit.div3_g2bcr0
#define		DIV4_G2BCR0	g2bcr0_addr.bit.div4_g2bcr0
#define		IT_G2BCR0	g2bcr0_addr.bit.it_g2bcr0

/*------------------------------------------------------
    Group 2 base timer control register 1
------------------------------------------------------*/
#pragma ADDRESS     g2bcr1_addr  0163H      /* Group 2 base timer control register 1 */
typedef union {
	struct{
		UINT8	rst0_g2bcr1:1;
		UINT8	rst1_g2bcr1:1;
		UINT8	rst2_g2bcr1:1;
		UINT8	b3:1;
		UINT8	bst_g2bcr1:1;
		UINT8	b5:1;
		UINT8	b6:1;
		UINT8	prp_g2bcr1:1;
	} bit;
	 UINT8 byte;
} G2BCR1_ADDR;
G2BCR1_ADDR	g2bcr1_addr;

#define		G2BCR1		g2bcr1_addr.byte

#define		RST0_G2BCR1	g2bcr1_addr.bit.rst0_g2bcr1
#define		RST1_G2BCR1	g2bcr1_addr.bit.rst1_g2bcr1
#define		RST2_G2BCR1	g2bcr1_addr.bit.rst2_g2bcr1
#define		BST_G2BCR1	g2bcr1_addr.bit.bst_g2bcr1
#define		PRP_G2BCR1	g2bcr1_addr.bit.prp_g2bcr1

/*------------------------------------------------------
    Base timer start register
------------------------------------------------------*/
#pragma ADDRESS     btsr_addr    0164H      /* base timer start register */
typedef union {
	struct{
		UINT8	bt0s:1;
		UINT8	bt1s:1;
		UINT8	bt2s:1;
		UINT8	bt3s:1;
		UINT8	b4:1;
		UINT8	b5:1;
		UINT8	b6:1;
		UINT8	b7:1;
	} bit;
	 UINT8 byte;
} BTSR_ADDR;
BTSR_ADDR	btsr_addr;

#define		BTSR		btsr_addr.byte

#define		BT0S		btsr_addr.bit.bt0s
#define		BT1S		btsr_addr.bit.bt1s
#define		BT2S		btsr_addr.bit.bt2s
#define		BT3S		btsr_addr.bit.bt3s

/*------------------------------------------------------
    Group 2 function enable register
------------------------------------------------------*/
#pragma ADDRESS     g2fe_addr    0166H      /* Group 2 function enable register */
typedef union {
	struct{
		UINT8	ife0_g2fe:1;
		UINT8	ife1_g2fe:1;
		UINT8	ife2_g2fe:1;
		UINT8	ife3_g2fe:1;
		UINT8	ife4_g2fe:1;
		UINT8	ife5_g2fe:1;
		UINT8	ife6_g2fe:1;
		UINT8	ife7_g2fe:1;
	} bit;
	 UINT8 byte;
} G2FE_ADDR;
G2FE_ADDR	g2fe_addr;

#define		G2FE		g2fe_addr.byte

#define		IFE0_G2FE	g2fe_addr.bit.ife0_g2fe
#define		IFE1_G2FE	g2fe_addr.bit.ife1_g2fe
#define		IFE2_G2FE	g2fe_addr.bit.ife2_g2fe
#define		IFE3_G2FE	g2fe_addr.bit.ife3_g2fe
#define		IFE4_G2FE	g2fe_addr.bit.ife4_g2fe
#define		IFE5_G2FE	g2fe_addr.bit.ife5_g2fe
#define		IFE6_G2FE	g2fe_addr.bit.ife6_g2fe
#define		IFE7_G2FE	g2fe_addr.bit.ife7_g2fe

/*------------------------------------------------------
    Group 2 RTP output buffer register
------------------------------------------------------*/
#pragma ADDRESS     g2rtp_addr   0167H      /* Group 2 RTP output buffer register */
typedef union {
	struct{
		UINT8	rtp0_g2rtp:1;
		UINT8	rtp1_g2rtp:1;
		UINT8	rtp2_g2rtp:1;
		UINT8	rtp3_g2rtp:1;
		UINT8	rtp4_g2rtp:1;
		UINT8	rtp5_g2rtp:1;
		UINT8	rtp6_g2rtp:1;
		UINT8	rtp7_g2rtp:1;
	} bit;
	 UINT8 byte;
} G2RTP_ADDR;
G2RTP_ADDR	g2rtp_addr;

#define		G2RTP		g2rtp_addr.byte

#define		RTP0_G2RTP	g2rtp_addr.bit.rtp0_g2rtp
#define		RTP1_G2RTP	g2rtp_addr.bit.rtp1_g2rtp
#define		RTP2_G2RTP	g2rtp_addr.bit.rtp2_g2rtp
#define		RTP3_G2RTP	g2rtp_addr.bit.rtp3_g2rtp
#define		RTP4_G2RTP	g2rtp_addr.bit.rtp4_g2rtp
#define		RTP5_G2RTP	g2rtp_addr.bit.rtp5_g2rtp
#define		RTP6_G2RTP	g2rtp_addr.bit.rtp6_g2rtp
#define		RTP7_G2RTP	g2rtp_addr.bit.rtp7_g2rtp

/*------------------------------------------------------
    Group 2 SI/O communication mode register
------------------------------------------------------*/
#pragma ADDRESS     g2mr_addr    016aH      /* Group 2 SI/O communication mode register */
typedef union {
	struct{
		UINT8	gmd0_g2mr:1;
		UINT8	gmd1_g2mr:1;
		UINT8	ckdir_g2mr:1;
		UINT8	b3:1;
		UINT8	b4:1;
		UINT8	b5:1;
		UINT8	uform_g2mr:1;
		UINT8	irs_g2mr:1;
	} bit;
	 UINT8 byte;
} G2MR_ADDR;
G2MR_ADDR	g2mr_addr;

#define		G2MR		g2mr_addr.byte

#define		GMD0_G2MR	g2mr_addr.bit.gmd0_g2mr
#define		GMD1_G2MR	g2mr_addr.bit.gmd1_g2mr
#define		CKDIR_G2MR	g2mr_addr.bit.ckdir_g2mr
#define		UFORM_G2MR	g2mr_addr.bit.uform_g2mr
#define		IRS_G2MR	g2mr_addr.bit.irs_g2mr

/*------------------------------------------------------
    Group 2 SI/O communication control register
------------------------------------------------------*/
#pragma ADDRESS     g2cr_addr    016bH      /* Group 2 SI/O communication control register */
typedef union {
	struct{
		UINT8	te_g2cr:1;
		UINT8	txept_g2cr:1;
		UINT8	ti_g2cr:1;
		UINT8	b3:1;
		UINT8	re_g2cr:1;
		UINT8	ri_g2cr:1;
		UINT8	opol_g2cr:1;
		UINT8	ipol_g2cr:1;
	} bit;
	 UINT8 byte;
} G2CR_ADDR;
G2CR_ADDR	g2cr_addr;

#define		G2CR		g2cr_addr.byte

#define		TE_G2CR		g2cr_addr.bit.te_g2cr
#define		TXEPT_G2CR	g2cr_addr.bit.txept_g2cr
#define		TI_G2CR		g2cr_addr.bit.ti_g2cr
#define		RE_G2CR		g2cr_addr.bit.re_g2cr
#define		RI_G2CR		g2cr_addr.bit.ri_g2cr
#define		OPOL_G2CR	g2cr_addr.bit.opol_g2cr
#define		IPOL_G2CR	g2cr_addr.bit.ipol_g2cr

/*------------------------------------------------------
     Group 2 SI/O transmit buffer register
------------------------------------------------------*/
#pragma ADDRESS     g2tb_addr    016cH      /* Group 2 SI/O transmit buffer register */
typedef union {
    struct{
        UINT8    b0:1;
        UINT8    b1:1;
        UINT8    b2:1;
        UINT8    b3:1;
        UINT8    b4:1;
        UINT8    b5:1;
        UINT8    b6:1;
        UINT8    b7:1;
        UINT8    sz0:1;
        UINT8    sz1:1;
        UINT8    sz2:1;
        UINT8    b11:1;
        UINT8    b12:1;
        UINT8    a:1;
        UINT8    pc:1;
        UINT8    p:1;
    } bit;
    struct{
        UINT8    low;                /* Low  8 bit */
        UINT8    high;               /* High 8 bit */
    } byte;
    UINT16  word;
} G2TB_ADDR;
G2TB_ADDR	g2tb_addr;

#define		G2TB        g2tb_addr.word
#define		G2TBL       g2tb_addr.byte.low
#define		G2TBH       g2tb_addr.byte.high

#define		SZ0_G2TB    g2tb_addr.bit.sz0
#define		SZ1_G2TB    g2tb_addr.bit.sz1
#define		SZ2_G2TB    g2tb_addr.bit.sz2
#define		A_G2TB      g2tb_addr.bit.a
#define		PC_G2TB     g2tb_addr.bit.pc
#define		P_G2TB      g2tb_addr.bit.p

/*------------------------------------------------------
    Group 2 SI/O receive buffer register
------------------------------------------------------*/
#pragma ADDRESS     g2rb_addr    016eH      /* Group 2 SI/O receive buffer register */
typedef union {
    struct{
        UINT8    b0:1;
        UINT8    b1:1;
        UINT8    b2:1;
        UINT8    b3:1;
        UINT8    b4:1;
        UINT8    b5:1;
        UINT8    b6:1;
        UINT8    b7:1;
        UINT8    b8:1;
        UINT8    b9:1;
        UINT8    b10:1;
        UINT8    b11:1;
        UINT8    oer:1;
        UINT8    b13:1;
        UINT8    b14:1;
        UINT8    b15:1;
    } bit;
    struct{
        UINT8    low;                /* Low  8 bit */
        UINT8    high;               /* High 8 bit */
    } byte;
    UINT16  word;
} G2RB_ADDR;
G2RB_ADDR	g2rb_addr;

#define		G2RB        g2rb_addr.word
#define		G2RBL       g2rb_addr.byte.low
#define		G2RBH       g2rb_addr.byte.high

#define		OER_G2RB    g2rb_addr.bit.oer

/*----------------------------------------------------*/
#pragma ADDRESS     iear_addr    0170H      /* Group 2 IEBus address register */
typedef union {
    struct{
        UINT8    low;                /* Low  8 bit */
        UINT8    high;               /* High 8 bit */
    } byte;
    UINT16  word;
} IEAR_ADDR;
IEAR_ADDR	iear_addr;

#define		IEAR        iear_addr.word		 /* Group 2 IEBus address register */
#define		IEARL       iear_addr.byte.low
#define		IEARH       iear_addr.byte.high

/*------------------------------------------------------
    Group 2 IEBus control register
------------------------------------------------------*/
#pragma ADDRESS     iecr_addr    0172H      /* Group 2 IEBus control register */
typedef union {
	struct{
		UINT8	ieb:1;
		UINT8	iets:1;
		UINT8	iebbs:1;
		UINT8	b3:1;
		UINT8	b4:1;
		UINT8	b5:1;
		UINT8	df:1;
		UINT8	iem:1;
	} bit;
	 UINT8 byte;
} IECR_ADDR;
IECR_ADDR	iecr_addr;

#define		IECR		iecr_addr.byte

#define		IEB			iecr_addr.bit.ieb
#define		IETS		iecr_addr.bit.iets
#define		IEBBS		iecr_addr.bit.iebbs
#define		DF			iecr_addr.bit.df
#define		IEM			iecr_addr.bit.iem

/*------------------------------------------------------
    Group 2 IEBus receive interrupt cause detect register
------------------------------------------------------*/
#pragma ADDRESS     ietif_addr   0173H      /* Group 2 IEBus transmit interrupt cause detect register */
typedef union {
	struct{
		UINT8	b0:1;
		UINT8	ieack:1;
		UINT8	ietmb:1;
		UINT8	iett:1;
		UINT8	ieabl:1;
		UINT8	b5:1;
		UINT8	b6:1;
		UINT8	b7:1;
	} bit;
	 UINT8 byte;
} IETIF_ADDR;
IETIF_ADDR	ietif_addr;

#define		IETIF		ietif_addr.byte

#define		IEACK		ietif_addr.bit.ieack
#define		IETMB		ietif_addr.bit.ietmb
#define		IETT		ietif_addr.bit.iett
#define		IEABL		ietif_addr.bit.ieabl

/*------------------------------------------------------
    Group 2 IEBus receive interrupt cause detect register
------------------------------------------------------*/
#pragma ADDRESS     ierif_addr   0174H      /* Group 2 IEBus receive interrupt cause detect register */
typedef union {
	struct{
		UINT8	b0:1;
		UINT8	iepar:1;
		UINT8	iermb:1;
		UINT8	iert:1;
		UINT8	ieretc:1;
		UINT8	b5:1;
		UINT8	b6:1;
		UINT8	b7:1;
	} bit;
	 UINT8 byte;
} IERIF_ADDR;
IERIF_ADDR	ierif_addr;

#define		IERIF		ierif_addr.byte

#define		IEPAR		ierif_addr.bit.iepar
#define		IERMB		ierif_addr.bit.iermb
#define		IERT		ierif_addr.bit.iert
#define		IERETC		ierif_addr.bit.ieretc

/*------------------------------------------------------
    Input function select register
------------------------------------------------------*/
#pragma ADDRESS     ips_addr     0178H      /* Input function select register */
typedef union {
	struct{
		UINT8	ips0:1;
		UINT8	ips1:1;
		UINT8	ips2:1;
		UINT8	ips3:1;
		UINT8	ips4:1;
		UINT8	ips5:1;
		UINT8	ips6:1;
		UINT8	ips7:1;
	} bit;
	 UINT8 byte;
} IPS_ADDR;
IPS_ADDR	ips_addr;

#define		IPS			ips_addr.byte

#define		IPS0		ips_addr.bit.ips0
#define		IPS1		ips_addr.bit.ips1
#define		IPS2		ips_addr.bit.ips2
#define		IPS3		ips_addr.bit.ips3
#define		IPS4		ips_addr.bit.ips4
#define		IPS5		ips_addr.bit.ips5
#define		IPS6		ips_addr.bit.ips6
#define		IPS7		ips_addr.bit.ips7

/*------------------------------------------------------
    Group 3 SI/O communication mode register
------------------------------------------------------*/
#pragma ADDRESS     g3mr_addr    017aH      /* Group 3 SI/O communication mode register */
typedef union {
	struct{
		UINT8	gmd0_g3mr:1;
		UINT8	gmd1_g3mr:1;
		UINT8	ckdir_g3mr:1;
		UINT8	tld_g3mr:1;
		UINT8	b4:1;
		UINT8	b5:1;
		UINT8	uform_g3mr:1;
		UINT8	irs_g3mr:1;
	} bit;
	 UINT8 byte;
} G3MR_ADDR;
G3MR_ADDR	g3mr_addr;

#define		G3MR		g3mr_addr.byte

#define		GMD0_G3MR	g3mr_addr.bit.gmd0_g3mr
#define		GMD1_G3MR	g3mr_addr.bit.gmd1_g3mr
#define		CKDIR_G3MR	g3mr_addr.bit.ckdir_g3mr
#define		TLD_G3MR	g3mr_addr.bit.tld_g3mr
#define		UFORM_G3MR	g3mr_addr.bit.uform_g3mr
#define		IRS_G3MR	g3mr_addr.bit.irs_g3mr
/*------------------------------------------------------
    Group 3 SI/O communication control register
------------------------------------------------------*/
#pragma ADDRESS     g3cr_addr    017bH      /* Group 3 SI/O communication control register */
typedef union {
	struct{
		UINT8	te_g3cr:1;
		UINT8	txept_g3cr:1;
		UINT8	ti_g3cr:1;
		UINT8	b3:1;
		UINT8	re_g3cr:1;
		UINT8	ri_g3cr:1;
		UINT8	opol_g3cr:1;
		UINT8	ipol_g3cr:1;
	} bit;
	 UINT8 byte;
} G3CR_ADDR;
G3CR_ADDR	g3cr_addr;

#define		G3CR		g3cr_addr.byte

#define		TE_G3CR		g3cr_addr.bit.te_g3cr
#define		TXEPT_G3CR	g3cr_addr.bit.txept_g3cr
#define		TI_G3CR		g3cr_addr.bit.ti_g3cr
#define		RE_G3CR		g3cr_addr.bit.re_g3cr
#define		RI_G3CR		g3cr_addr.bit.ri_g3cr
#define		OPOL_G3CR	g3cr_addr.bit.opol_g3cr
#define		IPOL_G3CR	g3cr_addr.bit.ipol_g3cr

/*----------------------------------------------------*/
#pragma ADDRESS     g3tb_addr    017cH      /* Group 3 SI/O transmit buffer register */
typedef union {
    struct{
        UINT8    low;                /* Low  8 bit */
        UINT8    high;               /* High 8 bit */
    } byte;
    UINT16  word;
} G3TB_ADDR;
G3TB_ADDR	g3tb_addr;

#define		G3TB        g3tb_addr.word      /* Group 3 SI/O transmit buffer register */
#define		G3TBL       g3tb_addr.byte.low
#define		G3TBH       g3tb_addr.byte.high

/*----------------------------------------------------*/
#pragma ADDRESS     g3rb_addr    017eH      /* Group 3 SI/O receive buffer register */
typedef union {
    struct{
        UINT8    low;                /* Low  8 bit */
        UINT8    high;               /* High 8 bit */
    } byte;
    UINT16  word;
} G3RB_ADDR;
G3RB_ADDR	g3rb_addr;

#define		G3RB        g3rb_addr.word      /* Group 3 SI/O receive buffer register */
#define		G3RBL       g3rb_addr.byte.low
#define		G3RBH       g3rb_addr.byte.high

/*----------------------------------------------------*/
#pragma ADDRESS     g3po0_addr   0180H      /* Group 3 waveform generate register 0 */
typedef union {
    struct{
        UINT8    low;                /* Low  8 bit */
        UINT8    high;               /* High 8 bit */
    } byte;
    UINT16  word;
} G3PO0_ADDR;
G3PO0_ADDR	g3po0_addr;

#define		G3PO0        g3po0_addr.word      /* Group 3 waveform generate register 0 */
#define		G3PO0L       g3po0_addr.byte.low
#define		G3PO0H       g3po0_addr.byte.high

/*----------------------------------------------------*/
#pragma ADDRESS     g3po1_addr   0182H      /* Group 3 waveform generate register 1 */
typedef union {
    struct{
        UINT8    low;                /* Low  8 bit */
        UINT8    high;               /* High 8 bit */
    } byte;
    UINT16  word;
} G3PO1_ADDR;
G3PO1_ADDR	g3po1_addr;

#define		G3PO1        g3po1_addr.word      /* Group 3 waveform generate register 1 */
#define		G3PO1L       g3po1_addr.byte.low
#define		G3PO1H       g3po1_addr.byte.high

/*----------------------------------------------------*/
#pragma ADDRESS     g3po2_addr   0184H      /* Group 3 waveform generate register 2 */
typedef union {
    struct{
        UINT8    low;                /* Low  8 bit */
        UINT8    high;               /* High 8 bit */
    } byte;
    UINT16  word;
} G3PO2_ADDR;
G3PO2_ADDR	g3po2_addr;

#define		G3PO2        g3po2_addr.word      /* Group 3 waveform generate register 2 */
#define		G3PO2L       g3po2_addr.byte.low
#define		G3PO2H       g3po2_addr.byte.high

/*----------------------------------------------------*/
#pragma ADDRESS     g3po3_addr   0186H      /* Group 3 waveform generate register 3 */
typedef union {
    struct{
        UINT8    low;                /* Low  8 bit */
        UINT8    high;               /* High 8 bit */
    } byte;
    UINT16  word;
} G3PO3_ADDR;
G3PO3_ADDR	g3po3_addr;

#define		G3PO3        g3po3_addr.word      /* Group 3 waveform generate register 3 */
#define		G3PO3L       g3po3_addr.byte.low
#define		G3PO3H       g3po3_addr.byte.high

/*----------------------------------------------------*/
#pragma ADDRESS     g3po4_addr   0188H      /* Group 3 waveform generate register 4 */
typedef union {
    struct{
        UINT8    low;                /* Low  8 bit */
        UINT8    high;               /* High 8 bit */
    } byte;
    UINT16  word;
} G3PO4_ADDR;
G3PO4_ADDR	g3po4_addr;

#define		G3PO4        g3po4_addr.word      /* Group 3 waveform generate register 4 */
#define		G3PO4L       g3po4_addr.byte.low
#define		G3PO4H       g3po4_addr.byte.high

/*----------------------------------------------------*/
#pragma ADDRESS     g3po5_addr   018aH      /* Group 3 waveform generate register 5 */
typedef union {
    struct{
        UINT8    low;                /* Low  8 bit */
        UINT8    high;               /* High 8 bit */
    } byte;
    UINT16  word;
} G3PO5_ADDR;
G3PO5_ADDR	g3po5_addr;

#define		G3PO5        g3po5_addr.word      /* Group 3 waveform generate register 5 */
#define		G3PO5L       g3po5_addr.byte.low
#define		G3PO5H       g3po5_addr.byte.high

/*----------------------------------------------------*/
#pragma ADDRESS     g3po6_addr   018cH      /* Group 3 waveform generate register 6 */
typedef union {
    struct{
        UINT8    low;                /* Low  8 bit */
        UINT8    high;               /* High 8 bit */
    } byte;
    UINT16  word;
} G3PO6_ADDR;
G3PO6_ADDR	g3po6_addr;

#define		G3PO6        g3po6_addr.word      /* Group 3 waveform generate register 6 */
#define		G3PO6L       g3po6_addr.byte.low
#define		G3PO6H       g3po6_addr.byte.high

/*----------------------------------------------------*/
#pragma ADDRESS     g3po7_addr   018eH      /* Group 3 waveform generate register 7 */
typedef union {
    struct{
        UINT8    low;                /* Low  8 bit */
        UINT8    high;               /* High 8 bit */
    } byte;
    UINT16  word;
} G3PO7_ADDR;
G3PO7_ADDR	g3po7_addr;

#define		G3PO7        g3po7_addr.word      /* Group 3 waveform generate register 7 */
#define		G3PO7L       g3po7_addr.byte.low
#define		G3PO7H       g3po7_addr.byte.high

/*------------------------------------------------------
    Group 3 waveform generate control register 0
------------------------------------------------------*/
#pragma ADDRESS     g3pocr0_addr 0190H      /* Group 3 waveform generate control register 0 */
typedef union {
	struct{
		UINT8	mod0_g3pocr0:1;
		UINT8	mod1_g3pocr0:1;
		UINT8	mod2_g3pocr0:1;
		UINT8	prt_g3pocr0:1;
		UINT8	ivl_g3pocr0:1;
		UINT8	rld_g3pocr0:1;
		UINT8	rtp_g3pocr0:1;
		UINT8	inv_g3pocr0:1;
	} bit;
	 UINT8 byte;
} G3POCR0_ADDR;
G3POCR0_ADDR	g3pocr0_addr;

#define		G3POCR0		g3pocr0_addr.byte

#define		MOD0_G3POCR0	g3pocr0_addr.bit.mod0_g3pocr0
#define		MOD1_G3POCR0	g3pocr0_addr.bit.mod1_g3pocr0
#define		MOD2_G3POCR0	g3pocr0_addr.bit.mod2_g3pocr0
#define		PRT_G3POCR0	g3pocr0_addr.bit.prt_g3pocr0
#define		IVL_G3POCR0	g3pocr0_addr.bit.ivl_g3pocr0
#define		RLD_G3POCR0	g3pocr0_addr.bit.rld_g3pocr0
#define		RTP_G3POCR0	g3pocr0_addr.bit.rtp_g3pocr0
#define		INV_G3POCR0	g3pocr0_addr.bit.inv_g3pocr0

/*------------------------------------------------------
    Group 3 waveform generate control register 1
------------------------------------------------------*/
#pragma ADDRESS     g3pocr1_addr 0191H      /* Group 3 waveform generate control register 1 */
typedef union {
	struct{
		UINT8	mod0_g3pocr1:1;
		UINT8	mod1_g3pocr1:1;
		UINT8	mod2_g3pocr1:1;
		UINT8	prt_g3pocr1:1;
		UINT8	ivl_g3pocr1:1;
		UINT8	rld_g3pocr1:1;
		UINT8	rtp_g3pocr1:1;
		UINT8	inv_g3pocr1:1;
	} bit;
	 UINT8 byte;
} G3POCR1_ADDR;
G3POCR1_ADDR	g3pocr1_addr;

#define		G3POCR1		g3pocr1_addr.byte

#define		MOD0_G3POCR1	g3pocr1_addr.bit.mod0_g3pocr1
#define		MOD1_G3POCR1	g3pocr1_addr.bit.mod1_g3pocr1
#define		MOD2_G3POCR1	g3pocr1_addr.bit.mod2_g3pocr1
#define		PRT_G3POCR1	g3pocr1_addr.bit.prt_g3pocr1
#define		IVL_G3POCR1	g3pocr1_addr.bit.ivl_g3pocr1
#define		RLD_G3POCR1	g3pocr1_addr.bit.rld_g3pocr1
#define		RTP_G3POCR1	g3pocr1_addr.bit.rtp_g3pocr1
#define		INV_G3POCR1	g3pocr1_addr.bit.inv_g3pocr1

/*------------------------------------------------------
    Group 3 waveform generate control register 2
------------------------------------------------------*/
#pragma ADDRESS     g3pocr2_addr 0192H      /* Group 3 waveform generate control register 2 */
typedef union {
	struct{
		UINT8	mod0_g3pocr2:1;
		UINT8	mod1_g3pocr2:1;
		UINT8	mod2_g3pocr2:1;
		UINT8	prt_g3pocr2:1;
		UINT8	ivl_g3pocr2:1;
		UINT8	rld_g3pocr2:1;
		UINT8	rtp_g3pocr2:1;
		UINT8	inv_g3pocr2:1;
	} bit;
	 UINT8 byte;
} G3POCR2_ADDR;
G3POCR2_ADDR	g3pocr2_addr;

#define		G3POCR2		g3pocr2_addr.byte

#define		MOD0_G3POCR2	g3pocr2_addr.bit.mod0_g3pocr2
#define		MOD1_G3POCR2	g3pocr2_addr.bit.mod1_g3pocr2
#define		MOD2_G3POCR2	g3pocr2_addr.bit.mod2_g3pocr2
#define		PRT_G3POCR2	g3pocr2_addr.bit.prt_g3pocr2
#define		IVL_G3POCR2	g3pocr2_addr.bit.ivl_g3pocr2
#define		RLD_G3POCR2	g3pocr2_addr.bit.rld_g3pocr2
#define		RTP_G3POCR2	g3pocr2_addr.bit.rtp_g3pocr2
#define		INV_G3POCR2	g3pocr2_addr.bit.inv_g3pocr2

/*------------------------------------------------------
    Group 3 waveform generate control register 3
------------------------------------------------------*/
#pragma ADDRESS     g3pocr3_addr 0193H      /* Group 3 waveform generate control register 3 */
typedef union {
	struct{
		UINT8	mod0_g3pocr3:1;
		UINT8	mod1_g3pocr3:1;
		UINT8	mod2_g3pocr3:1;
		UINT8	prt_g3pocr3:1;
		UINT8	ivl_g3pocr3:1;
		UINT8	rld_g3pocr3:1;
		UINT8	rtp_g3pocr3:1;
		UINT8	inv_g3pocr3:1;
	} bit;
	 UINT8 byte;
} G3POCR3_ADDR;
G3POCR3_ADDR	g3pocr3_addr;

#define		G3POCR3		g3pocr3_addr.byte

#define		MOD0_G3POCR3	g3pocr3_addr.bit.mod0_g3pocr3
#define		MOD1_G3POCR3	g3pocr3_addr.bit.mod1_g3pocr3
#define		MOD2_G3POCR3	g3pocr3_addr.bit.mod2_g3pocr3
#define		PRT_G3POCR3	g3pocr3_addr.bit.prt_g3pocr3
#define		IVL_G3POCR3	g3pocr3_addr.bit.ivl_g3pocr3
#define		RLD_G3POCR3	g3pocr3_addr.bit.rld_g3pocr3
#define		RTP_G3POCR3	g3pocr3_addr.bit.rtp_g3pocr3
#define		INV_G3POCR3	g3pocr3_addr.bit.inv_g3pocr3

/*------------------------------------------------------
    Group 3 waveform generate control register 4
------------------------------------------------------*/
#pragma ADDRESS     g3pocr4_addr 0194H      /* Group 3 waveform generate control register 4 */
typedef union {
	struct{
		UINT8	mod0_g3pocr4:1;
		UINT8	mod1_g3pocr4:1;
		UINT8	mod2_g3pocr4:1;
		UINT8	prt_g3pocr4:1;
		UINT8	ivl_g3pocr4:1;
		UINT8	rld_g3pocr4:1;
		UINT8	rtp_g3pocr4:1;
		UINT8	inv_g3pocr4:1;
	} bit;
	 UINT8 byte;
} G3POCR4_ADDR;
G3POCR4_ADDR	g3pocr4_addr;

#define		G3POCR4		g3pocr4_addr.byte

#define		MOD0_G3POCR4	g3pocr4_addr.bit.mod0_g3pocr4
#define		MOD1_G3POCR4	g3pocr4_addr.bit.mod1_g3pocr4
#define		MOD2_G3POCR4	g3pocr4_addr.bit.mod2_g3pocr4
#define		PRT_G3POCR4	g3pocr4_addr.bit.prt_g3pocr4
#define		IVL_G3POCR4	g3pocr4_addr.bit.ivl_g3pocr4
#define		RLD_G3POCR4	g3pocr4_addr.bit.rld_g3pocr4
#define		RTP_G3POCR4	g3pocr4_addr.bit.rtp_g3pocr4
#define		INV_G3POCR4	g3pocr4_addr.bit.inv_g3pocr4

/*------------------------------------------------------
    Group 3 waveform generate control register 5
------------------------------------------------------*/
#pragma ADDRESS     g3pocr5_addr 0195H      /* Group 3 waveform generate control register 5 */
typedef union {
	struct{
		UINT8	mod0_g3pocr5:1;
		UINT8	mod1_g3pocr5:1;
		UINT8	mod2_g3pocr5:1;
		UINT8	prt_g3pocr5:1;
		UINT8	ivl_g3pocr5:1;
		UINT8	rld_g3pocr5:1;
		UINT8	rtp_g3pocr5:1;
		UINT8	inv_g3pocr5:1;
	} bit;
	 UINT8 byte;
} G3POCR5_ADDR;
G3POCR5_ADDR	g3pocr5_addr;

#define		G3POCR5		g3pocr5_addr.byte

#define		MOD0_G3POCR5	g3pocr5_addr.bit.mod0_g3pocr5
#define		MOD1_G3POCR5	g3pocr5_addr.bit.mod1_g3pocr5
#define		MOD2_G3POCR5	g3pocr5_addr.bit.mod2_g3pocr5
#define		PRT_G3POCR5	g3pocr5_addr.bit.prt_g3pocr5
#define		IVL_G3POCR5	g3pocr5_addr.bit.ivl_g3pocr5
#define		RLD_G3POCR5	g3pocr5_addr.bit.rld_g3pocr5
#define		RTP_G3POCR5	g3pocr5_addr.bit.rtp_g3pocr5
#define		INV_G3POCR5	g3pocr5_addr.bit.inv_g3pocr5

/*------------------------------------------------------
    Group 3 waveform generate control register 6
------------------------------------------------------*/
#pragma ADDRESS     g3pocr6_addr 0196H      /* Group 3 waveform generate control register 6 */
typedef union {
	struct{
		UINT8	mod0_g3pocr6:1;
		UINT8	mod1_g3pocr6:1;
		UINT8	mod2_g3pocr6:1;
		UINT8	prt_g3pocr6:1;
		UINT8	ivl_g3pocr6:1;
		UINT8	rld_g3pocr6:1;
		UINT8	rtp_g3pocr6:1;
		UINT8	inv_g3pocr6:1;
	} bit;
	 UINT8 byte;
} G3POCR6_ADDR;
G3POCR6_ADDR	g3pocr6_addr;

#define		G3POCR6		g3pocr6_addr.byte

#define		MOD0_G3POCR6	g3pocr6_addr.bit.mod0_g3pocr6
#define		MOD1_G3POCR6	g3pocr6_addr.bit.mod1_g3pocr6
#define		MOD2_G3POCR6	g3pocr6_addr.bit.mod2_g3pocr6
#define		PRT_G3POCR6	g3pocr6_addr.bit.prt_g3pocr6
#define		IVL_G3POCR6	g3pocr6_addr.bit.ivl_g3pocr6
#define		RLD_G3POCR6	g3pocr6_addr.bit.rld_g3pocr6
#define		RTP_G3POCR6	g3pocr6_addr.bit.rtp_g3pocr6
#define		INV_G3POCR6	g3pocr6_addr.bit.inv_g3pocr6

/*------------------------------------------------------
    Group 3 waveform generate control register 7
------------------------------------------------------*/
#pragma ADDRESS     g3pocr7_addr 0197H      /* Group 3 waveform generate control register 7 */
typedef union {
	struct{
		UINT8	mod0_g3pocr7:1;
		UINT8	mod1_g3pocr7:1;
		UINT8	mod2_g3pocr7:1;
		UINT8	prt_g3pocr7:1;
		UINT8	ivl_g3pocr7:1;
		UINT8	rld_g3pocr7:1;
		UINT8	rtp_g3pocr7:1;
		UINT8	inv_g3pocr7:1;
	} bit;
	 UINT8 byte;
} G3POCR7_ADDR;
G3POCR7_ADDR	g3pocr7_addr;

#define		G3POCR7		g3pocr7_addr.byte

#define		MOD0_G3POCR7	g3pocr7_addr.bit.mod0_g3pocr7
#define		MOD1_G3POCR7	g3pocr7_addr.bit.mod1_g3pocr7
#define		MOD2_G3POCR7	g3pocr7_addr.bit.mod2_g3pocr7
#define		PRT_G3POCR7	g3pocr7_addr.bit.prt_g3pocr7
#define		IVL_G3POCR7	g3pocr7_addr.bit.ivl_g3pocr7
#define		RLD_G3POCR7	g3pocr7_addr.bit.rld_g3pocr7
#define		RTP_G3POCR7	g3pocr7_addr.bit.rtp_g3pocr7
#define		INV_G3POCR7	g3pocr7_addr.bit.inv_g3pocr7

/*----------------------------------------------------*/
#pragma ADDRESS     g3mk4_addr   0198H      /* Group 3 waveform generate mask register 4 */
typedef union {
    struct{
        UINT8    low;                /* Low  8 bit */
        UINT8    high;               /* High 8 bit */
    } byte;
    UINT16  word;
} G3MK4_ADDR;
G3MK4_ADDR	g3mk4_addr;

#define		G3MK4        g3mk4_addr.word     /* Group 3 waveform generate mask register 4 */
#define		G3MK4L       g3mk4_addr.byte.low
#define		G3MK4H       g3mk4_addr.byte.high

/*----------------------------------------------------*/
#pragma ADDRESS     g3mk5_addr   019aH      /* Group 3 waveform generate mask register 5 */
typedef union {
    struct{
        UINT8    low;                /* Low  8 bit */
        UINT8    high;               /* High 8 bit */
    } byte;
    UINT16  word;
} G3MK5_ADDR;
G3MK5_ADDR	g3mk5_addr;

#define		G3MK5        g3mk5_addr.word     /* Group 3 waveform generate mask register 5 */
#define		G3MK5L       g3mk5_addr.byte.low
#define		G3MK5H       g3mk5_addr.byte.high

/*----------------------------------------------------*/
#pragma ADDRESS     g3mk6_addr   019cH      /* Group 3 waveform generate mask register 6 */
typedef union {
    struct{
        UINT8    low;                /* Low  8 bit */
        UINT8    high;               /* High 8 bit */
    } byte;
    UINT16  word;
} G3MK6_ADDR;
G3MK6_ADDR	g3mk6_addr;

#define		G3MK6        g3mk6_addr.word     /* Group 3 waveform generate mask register 6 */
#define		G3MK6L       g3mk6_addr.byte.low
#define		G3MK6H       g3mk6_addr.byte.high

/*----------------------------------------------------*/
#pragma ADDRESS     g3mk7_addr   019eH      /* Group 3 waveform generate mask register 7 */
typedef union {
    struct{
        UINT8    low;                /* Low  8 bit */
        UINT8    high;               /* High 8 bit */
    } byte;
    UINT16  word;
} G3MK7_ADDR;
G3MK7_ADDR	g3mk7_addr;

#define		G3MK7        g3mk7_addr.word      /* Group 3 waveform generate mask register 7 */
#define		G3MK7L       g3mk7_addr.byte.low
#define		G3MK7H       g3mk7_addr.byte.high

/*----------------------------------------------------*/
#pragma ADDRESS     g3bt_addr    01a0H      /* Group 3 base timer register */
typedef union {
    struct{
        UINT8    low;                /* Low  8 bit */
        UINT8    high;               /* High 8 bit */
    } byte;
    UINT16  word;
} G3BT_ADDR;
G3BT_ADDR	g3bt_addr;

#define		G3BT        g3bt_addr.word      /* Group 3 base timer register */
#define		G3BTL       g3bt_addr.byte.low
#define		G3BTH       g3bt_addr.byte.high

/*------------------------------------------------------
    Group 3 base timer control register 0
------------------------------------------------------*/
#pragma ADDRESS     g3bcr0_addr  01a2H      /* Group 3 base timer control register 0 */
typedef union {
	struct{
		UINT8	bck0_g3bcr0:1;
		UINT8	bck1_g3bcr0:1;
		UINT8	div0_g3bcr0:1;
		UINT8	div1_g3bcr0:1;
		UINT8	div2_g3bcr0:1;
		UINT8	div3_g3bcr0:1;
		UINT8	div4_g3bcr0:1;
		UINT8	it_g3bcr0:1;
	} bit;
	 UINT8 byte;
} G3BCR0_ADDR;
G3BCR0_ADDR	g3bcr0_addr;

#define		G3BCR0		g3bcr0_addr.byte

#define		BCK0_G3BCR0	g3bcr0_addr.bit.bck0_g3bcr0
#define		BCK1_G3BCR0	g3bcr0_addr.bit.bck1_g3bcr0
#define		DIV0_G3BCR0	g3bcr0_addr.bit.div0_g3bcr0
#define		DIV1_G3BCR0	g3bcr0_addr.bit.div1_g3bcr0
#define		DIV2_G3BCR0	g3bcr0_addr.bit.div2_g3bcr0
#define		DIV3_G3BCR0	g3bcr0_addr.bit.div3_g3bcr0
#define		DIV4_G3BCR0	g3bcr0_addr.bit.div4_g3bcr0
#define		IT_G3BCR0	g3bcr0_addr.bit.it_g3bcr0

/*------------------------------------------------------
    Group 3 base timer control register 1
------------------------------------------------------*/
#pragma ADDRESS     g3bcr1_addr  01a3H      /* Group 3 base timer control register 1 */
typedef union {
	struct{
		UINT8	rst0_g3bcr1:1;
		UINT8	rst1_g3bcr1:1;
		UINT8	rst2_g3bcr1:1;
		UINT8	b3:1;
		UINT8	bts_g3bcr1:1;
		UINT8	b5:1;
		UINT8	b6:1;
		UINT8	prp_g3bcr1:1;
	} bit;
	 UINT8 byte;
} G3BCR1_ADDR;
G3BCR1_ADDR	g3bcr1_addr;

#define		G3BCR1		g3bcr1_addr.byte

#define		RST0_G3BCR1	g3bcr1_addr.bit.rst0_g3bcr1
#define		RST1_G3BCR1	g3bcr1_addr.bit.rst1_g3bcr1
#define		RST2_G3BCR1	g3bcr1_addr.bit.rst2_g3bcr1
#define		BTS_G3BCR1	g3bcr1_addr.bit.bts_g3bcr1
#define		PRP_G3BCR1	g3bcr1_addr.bit.prp_g3bcr1

/*------------------------------------------------------
    Group 3 function enable register
------------------------------------------------------*/
#pragma ADDRESS     g3fe_addr    01a6H      /* Group 3 function enable register */
typedef union {
	struct{
		UINT8	ife0_g3fe:1;
		UINT8	ife1_g3fe:1;
		UINT8	ife2_g3fe:1;
		UINT8	ife3_g3fe:1;
		UINT8	ife4_g3fe:1;
		UINT8	ife5_g3fe:1;
		UINT8	ife6_g3fe:1;
		UINT8	ife7_g3fe:1;
	} bit;
	 UINT8 byte;
} G3FE_ADDR;
G3FE_ADDR	g3fe_addr;

#define		G3FE		g3fe_addr.byte

#define		IFE0_G3FE	g3fe_addr.bit.ife0_g3fe
#define		IFE1_G3FE	g3fe_addr.bit.ife1_g3fe
#define		IFE2_G3FE	g3fe_addr.bit.ife2_g3fe
#define		IFE3_G3FE	g3fe_addr.bit.ife3_g3fe
#define		IFE4_G3FE	g3fe_addr.bit.ife4_g3fe
#define		IFE5_G3FE	g3fe_addr.bit.ife5_g3fe
#define		IFE6_G3FE	g3fe_addr.bit.ife6_g3fe
#define		IFE7_G3FE	g3fe_addr.bit.ife7_g3fe

/*------------------------------------------------------
    Group 3 RTP output buffer register
------------------------------------------------------*/
#pragma ADDRESS     g3rtp_addr   01a7H      /* Group 3 RTP output buffer register */
typedef union {
	struct{
		UINT8	rtp0_g3rtp:1;
		UINT8	rtp1_g3rtp:1;
		UINT8	rtp2_g3rtp:1;
		UINT8	rtp3_g3rtp:1;
		UINT8	rtp4_g3rtp:1;
		UINT8	rtp5_g3rtp:1;
		UINT8	rtp6_g3rtp:1;
		UINT8	rtp7_g3rtp:1;
	} bit;
	 UINT8 byte;
} G3RTP_ADDR;
G3RTP_ADDR	g3rtp_addr;

#define		G3RTP		g3rtp_addr.byte

#define		RTP0_G3RTP	g3rtp_addr.bit.rtp0_g3rtp
#define		RTP1_G3RTP	g3rtp_addr.bit.rtp1_g3rtp
#define		RTP2_G3RTP	g3rtp_addr.bit.rtp2_g3rtp
#define		RTP3_G3RTP	g3rtp_addr.bit.rtp3_g3rtp
#define		RTP4_G3RTP	g3rtp_addr.bit.rtp4_g3rtp
#define		RTP5_G3RTP	g3rtp_addr.bit.rtp5_g3rtp
#define		RTP6_G3RTP	g3rtp_addr.bit.rtp6_g3rtp
#define		RTP7_G3RTP	g3rtp_addr.bit.rtp7_g3rtp

/*------------------------------------------------------
    Group 3 high-speed HDLC communication control register
------------------------------------------------------*/
#pragma ADDRESS     hdlc_addr    01acH      /* Group 3 high-speed HDLC communication control register */
typedef union {
	struct{
		UINT8	df_hdlc:1;
		UINT8	cnv_hdlc:1;
		UINT8	fn0_hdlc:1;
		UINT8	fn1_hdlc:1;
		UINT8	bse_hdlc:1;
		UINT8	b5:1;
		UINT8	b6:1;
		UINT8	ace_hdlc:1;
	} bit;
	 UINT8 byte;
} HDLC_ADDR;
HDLC_ADDR	hdlc_addr;

#define		HDLC		hdlc_addr.byte

#define		DF_HDLC		hdlc_addr.bit.df_hdlc
#define		CNV_HDLC	hdlc_addr.bit.cnv_hdlc
#define		FN0_HDLC	hdlc_addr.bit.fn0_hdlc
#define		FN1_HDLC	hdlc_addr.bit.fn1_hdlc
#define		BSE_HDLC	hdlc_addr.bit.bse_hdlc
#define		ACE_HDLC	hdlc_addr.bit.ace_hdlc
/*------------------------------------------------------
    Group 3 si/o communication flag register
------------------------------------------------------*/
#pragma ADDRESS     g3flg_addr   01adH      /* Group 3 high-speed HDLC communication register */
typedef union {
	struct{
		UINT8	roer_g3flg:1;
		UINT8	rnf_g3flg:1;
		UINT8	abt_g3flg:1;
		UINT8	crc_g3flg:1;
		UINT8	b4:1;
		UINT8	add_g3flg:1;
		UINT8	toer_g3flg:1;
		UINT8	tnf_g3flg:1;
	} bit;
	 UINT8 byte;
} G3FLG_ADDR;
G3FLG_ADDR	g3flg_addr;

#define		G3FLG		g3flg_addr.byte

#define		ROER_G3FLG	g3flg_addr.bit.roer_g3flg
#define		RNF_G3FLG	g3flg_addr.bit.rnf_g3flg
#define		ABT_G3FLG	g3flg_addr.bit.abt_g3flg
#define		CRC_G3FLG	g3flg_addr.bit.crc_g3flg
#define		ADD_G3FLG	g3flg_addr.bit.add_g3flg
#define		TOER_G3FLG	g3flg_addr.bit.toer_g3flg
#define		TNF_G3FLG	g3flg_addr.bit.tnf_g3flg

/*----------------------------------------------------*/
#pragma ADDRESS     hcnt_addr    01aeH      /* Group 3 high-speed HDLC transmit counter */
typedef union {
    struct{
        UINT8    low;                /* Low  8 bit */
        UINT8    high;               /* High 8 bit */
    } byte;
    UINT16  word;
} HCNT_ADDR;
HCNT_ADDR	hcnt_addr;

#define		HCNT        hcnt_addr.word     /* Group 3 high-speed HDLC transmit counter */
#define		HCNTL       hcnt_addr.byte.low
#define		HCNTH       hcnt_addr.byte.high

/*----------------------------------------------------*/
#pragma ADDRESS     hadr0_addr	 01b0H      /* Group 3 high-speed HDLC data compare register 0 */
typedef union {
    struct{
        UINT8    low;                /* Low  8 bit */
        UINT8    high;               /* High 8 bit */
    } byte;
    UINT16  word;
} HADR0_ADDR;
HADR0_ADDR	hadr0_addr;

#define		HADR0        hadr0_addr.word   /* Group 3 high-speed HDLC data compare register 0 */
#define		HADR0L       hadr0_addr.byte.low
#define		HADR0H       hadr0_addr.byte.high

/*----------------------------------------------------*/
#pragma ADDRESS     hmsk0_addr	 01b2H      /* Group 3 high-speed HDLC data mask register 0 */
typedef union {
    struct{
        UINT8    low;                /* Low  8 bit */
        UINT8    high;               /* High 8 bit */
    } byte;
    UINT16  word;
} HMSK0_ADDR;
HMSK0_ADDR	hmsk0_addr;

#define		HMSK0        hmsk0_addr.word   /* Group 3 high-speed HDLC data mask register 0 */
#define		HMSK0L       hmsk0_addr.byte.low
#define		HMSK0H       hmsk0_addr.byte.high

/*----------------------------------------------------*/
#pragma ADDRESS     hadr1_addr	 01b4H      /* Group 3 high-speed HDLC data compare register 1 */
typedef union {
    struct{
        UINT8    low;                /* Low  8 bit */
        UINT8    high;               /* High 8 bit */
    } byte;
    UINT16  word;
} HADR1_ADDR;
HADR1_ADDR	hadr1_addr;

#define		HADR1        hadr1_addr.word   /* Group 3 high-speed HDLC data compare register 1 */
#define		HADR1L       hadr1_addr.byte.low
#define		HADR1H       hadr1_addr.byte.high

/*----------------------------------------------------*/
#pragma ADDRESS     hmsk1_addr	 01b6H      /* Group 3 high-speed HDLC data mask register 1 */
typedef union {
    struct{
        UINT8    low;                /* Low  8 bit */
        UINT8    high;               /* High 8 bit */
    } byte;
    UINT16  word;
} HMSK1_ADDR;
HMSK1_ADDR	hmsk1_addr;

#define		HMSK1        hmsk1_addr.word   /* Group 3 high-speed HDLC data mask register 1 */
#define		HMSK1L       hmsk1_addr.byte.low
#define		HMSK1H       hmsk1_addr.byte.high

/*----------------------------------------------------*/
#pragma ADDRESS     hadr2_addr	 01b8H      /* Group 3 high-speed HDLC data compare register 2 */
typedef union {
    struct{
        UINT8    low;                /* Low  8 bit */
        UINT8    high;               /* High 8 bit */
    } byte;
    UINT16  word;
} HADR2_ADDR;
HADR2_ADDR	hadr2_addr;

#define		HADR2        hadr2_addr.word   /* Group 3 high-speed HDLC data compare register 2 */
#define		HADR2L       hadr2_addr.byte.low
#define		HADR2H       hadr2_addr.byte.high

/*----------------------------------------------------*/
#pragma ADDRESS     hmsk2_addr	 01baH      /* Group 3 high-speed HDLC data mask register 2 */
typedef union {
    struct{
        UINT8    low;                /* Low  8 bit */
        UINT8    high;               /* High 8 bit */
    } byte;
    UINT16  word;
} HMSK2_ADDR;
HMSK2_ADDR	hmsk2_addr;

#define		HMSK2        hmsk2_addr.word   /* Group 3 high-speed HDLC data mask register 2 */
#define		HMSK2L       hmsk2_addr.byte.low
#define		HMSK2H       hmsk2_addr.byte.high

/*----------------------------------------------------*/
#pragma ADDRESS     hadr3_addr	 01bcH      /* Group 3 high-speed HDLC data compare register 3 */
typedef union {
    struct{
        UINT8    low;                /* Low  8 bit */
        UINT8    high;               /* High 8 bit */
    } byte;
    UINT16  word;
} HADR3_ADDR;
HADR3_ADDR	hadr3_addr;

#define		HADR3        hadr3_addr.word   /* Group 3 high-speed HDLC data compare register 3 */
#define		HADR3L       hadr3_addr.byte.low
#define		HADR3H       hadr3_addr.byte.high

/*----------------------------------------------------*/
#pragma ADDRESS     hmsk3_addr 	 01beH      /* Group 3 high-speed HDLC data mask register 3 */
typedef union {
    struct{
        UINT8    low;                /* Low  8 bit */
        UINT8    high;               /* High 8 bit */
    } byte;
    UINT16  word;
} HMSK3_ADDR;
HMSK3_ADDR	hmsk3_addr;

#define		HMSK3        hmsk3_addr.word   /* Group 3 high-speed HDLC data mask register 3 */
#define		HMSK3L       hmsk3_addr.byte.low
#define		HMSK3H       hmsk3_addr.byte.high

/*----------------------------------------------------*/
#pragma ADDRESS     ad10_addr    01c0H      /* A-D1 register 0 */
typedef union {
    struct{
        UINT8    b0:1;
        UINT8    b1:1;
        UINT8    b2:1;
        UINT8    b3:1;
        UINT8    b4:1;
        UINT8    b5:1;
        UINT8    b6:1;
        UINT8    b7:1;
        UINT8    b8:1;
        UINT8    b9:1;
        UINT8    b10:1;
        UINT8    b11:1;
        UINT8    b12:1;
        UINT8    b13:1;
        UINT8    b14:1;
        UINT8    b15:1;
    } bit;
    struct{
        UINT8    low;                /* low  8 bit */
        UINT8    high;               /* high 8 bit */
    } byte;
    UINT16  word;
} AD10_ADDR;
AD10_ADDR	ad10_addr;

#define		AD10 ad10_addr.word           /* A-D1 register 0 16 bit */
#define		AD10L    ad10_addr.byte.low           /* A-D1 register 0 low  8 bit */
#define		AD10H    ad10_addr.byte.high          /* A-D1 register 0 high 8 bit */

/*----------------------------------------------------*/
#pragma ADDRESS     ad11_addr    01c2H      /* A-D1 register 1 */
typedef union {
    struct{
        UINT8    b0:1;
        UINT8    b1:1;
        UINT8    b2:1;
        UINT8    b3:1;
        UINT8    b4:1;
        UINT8    b5:1;
        UINT8    b6:1;
        UINT8    b7:1;
        UINT8    b8:1;
        UINT8    b9:1;
        UINT8    b10:1;
        UINT8    b11:1;
        UINT8    b12:1;
        UINT8    b13:1;
        UINT8    b14:1;
        UINT8    b15:1;
    } bit;
    struct{
        UINT8    low;                /* low  8 bit */
        UINT8    high;               /* high 8 bit */
    } byte;
    UINT16  word;
} AD11_ADDR;
AD11_ADDR	ad11_addr;

#define		AD11 ad11_addr.word           /* A-D1 register 1 16 bit */
#define		AD11L    ad11_addr.byte.low           /* A-D1 register 1 low  8 bit */
#define		AD11H    ad11_addr.byte.high          /* A-D1 register 1 high 8 bit */

/*----------------------------------------------------*/
#pragma ADDRESS     ad12_addr    01c4H      /* A-D1 register 2 */
typedef union {
    struct{
        UINT8    b0:1;
        UINT8    b1:1;
        UINT8    b2:1;
        UINT8    b3:1;
        UINT8    b4:1;
        UINT8    b5:1;
        UINT8    b6:1;
        UINT8    b7:1;
        UINT8    b8:1;
        UINT8    b9:1;
        UINT8    b10:1;
        UINT8    b11:1;
        UINT8    b12:1;
        UINT8    b13:1;
        UINT8    b14:1;
        UINT8    b15:1;
    } bit;
    struct{
        UINT8    low;                /* low  8 bit */
        UINT8    high;               /* high 8 bit */
    } byte;
    UINT16  word;
} AD12_ADDR;
AD12_ADDR	ad12_addr;

#define		AD12 ad12_addr.word           /* A-D1 register 2 16 bit */
#define		AD12L    ad12_addr.byte.low           /* A-D1 register 2 low  8 bit */
#define		AD12H    ad12_addr.byte.high          /* A-D1 register 2 high 8 bit */

/*----------------------------------------------------*/
#pragma ADDRESS     ad13_addr    01c6H      /* A-D1 register 3 */
typedef union {
    struct{
        UINT8    b0:1;
        UINT8    b1:1;
        UINT8    b2:1;
        UINT8    b3:1;
        UINT8    b4:1;
        UINT8    b5:1;
        UINT8    b6:1;
        UINT8    b7:1;
        UINT8    b8:1;
        UINT8    b9:1;
        UINT8    b10:1;
        UINT8    b11:1;
        UINT8    b12:1;
        UINT8    b13:1;
        UINT8    b14:1;
        UINT8    b15:1;
    } bit;
    struct{
        UINT8    low;                /* low  8 bit */
        UINT8    high;               /* high 8 bit */
    } byte;
    UINT16  word;
} AD13_ADDR;
AD13_ADDR	ad13_addr;

#define		AD13 ad13_addr.word           /* A-D1 register 3 16 bit */
#define		AD13L    ad13_addr.byte.low           /* A-D1 register 3 low  8 bit */
#define		AD13H    ad13_addr.byte.high          /* A-D1 register 3 high 8 bit */

/*----------------------------------------------------*/
#pragma ADDRESS     ad14_addr    01c8H      /* A-D1 register 4 */
typedef union {
    struct{
        UINT8    b0:1;
        UINT8    b1:1;
        UINT8    b2:1;
        UINT8    b3:1;
        UINT8    b4:1;
        UINT8    b5:1;
        UINT8    b6:1;
        UINT8    b7:1;
        UINT8    b8:1;
        UINT8    b9:1;
        UINT8    b10:1;
        UINT8    b11:1;
        UINT8    b12:1;
        UINT8    b13:1;
        UINT8    b14:1;
        UINT8    b15:1;
    } bit;
    struct{
        UINT8    low;                /* low  8 bit */
        UINT8    high;               /* high 8 bit */
    } byte;
    UINT16  word;
} AD14_ADDR;
AD14_ADDR	ad14_addr;

#define		AD14 ad14_addr.word           /* A-D1 register 4 16 bit */
#define		AD14L    ad14_addr.byte.low           /* A-D1 register 4 low  8 bit */
#define		AD14H    ad14_addr.byte.high          /* A-D1 register 4 high 8 bit */

/*----------------------------------------------------*/
#pragma ADDRESS     ad15_addr    01caH      /* A-D1 register 5 */
typedef union {
    struct{
        UINT8    b0:1;
        UINT8    b1:1;
        UINT8    b2:1;
        UINT8    b3:1;
        UINT8    b4:1;
        UINT8    b5:1;
        UINT8    b6:1;
        UINT8    b7:1;
        UINT8    b8:1;
        UINT8    b9:1;
        UINT8    b10:1;
        UINT8    b11:1;
        UINT8    b12:1;
        UINT8    b13:1;
        UINT8    b14:1;
        UINT8    b15:1;
    } bit;
    struct{
        UINT8    low;                /* low  8 bit */
        UINT8    high;               /* high 8 bit */
    } byte;
    UINT16  word;
} AD15_ADDR;
AD15_ADDR	ad15_addr;

#define		AD15 ad15_addr.word           /* A-D1 register 5 16 bit */
#define		AD15L    ad15_addr.byte.low           /* A-D1 register 5 low  8 bit */
#define		AD15H    ad15_addr.byte.high          /* A-D1 register 5 high 8 bit */

/*----------------------------------------------------*/
#pragma ADDRESS     ad16_addr    01ccH      /* A-D1 register 6 */
typedef union {
    struct{
        UINT8    b0:1;
        UINT8    b1:1;
        UINT8    b2:1;
        UINT8    b3:1;
        UINT8    b4:1;
        UINT8    b5:1;
        UINT8    b6:1;
        UINT8    b7:1;
        UINT8    b8:1;
        UINT8    b9:1;
        UINT8    b10:1;
        UINT8    b11:1;
        UINT8    b12:1;
        UINT8    b13:1;
        UINT8    b14:1;
        UINT8    b15:1;
    } bit;
    struct{
        UINT8    low;                /* low  8 bit */
        UINT8    high;               /* high 8 bit */
    } byte;
    UINT16  word;
} AD16_ADDR;
AD16_ADDR	ad16_addr;

#define		AD16 ad16_addr.word           /* A-D1 register 6 16 bit */
#define		AD16L    ad16_addr.byte.low           /* A-D1 register 6 low  8 bit */
#define		AD16H    ad16_addr.byte.high          /* A-D1 register 6 high 8 bit */

/*----------------------------------------------------*/
#pragma ADDRESS     ad17_addr    01ceH      /* A-D1 register 7 */
typedef union {
    struct{
        UINT8    b0:1;
        UINT8    b1:1;
        UINT8    b2:1;
        UINT8    b3:1;
        UINT8    b4:1;
        UINT8    b5:1;
        UINT8    b6:1;
        UINT8    b7:1;
        UINT8    b8:1;
        UINT8    b9:1;
        UINT8    b10:1;
        UINT8    b11:1;
        UINT8    b12:1;
        UINT8    b13:1;
        UINT8    b14:1;
        UINT8    b15:1;
    } bit;
    struct{
        UINT8    low;                /* low  8 bit */
        UINT8    high;               /* high 8 bit */
    } byte;
    UINT16  word;
} AD17_ADDR;
AD17_ADDR	ad17_addr;

#define		AD17 ad17_addr.word           /* A-D1 register 7 16 bit */
#define		AD17L    ad17_addr.byte.low           /* A-D1 register 7 low  8 bit */
#define		AD17H    ad17_addr.byte.high          /* A-D1 register 7 high 8 bit */

/*------------------------------------------------------
    A-D1 control register 2
------------------------------------------------------*/
#pragma ADDRESS     ad1con2_addr 01d4H      /* A-D1 control register 2 */
typedef union {
	struct{
		UINT8	smp_ad1con2:1;
		UINT8	aps0_ad1con2:1;
		UINT8	aps1_ad1con2:1;
		UINT8	b3:1;
		UINT8	b4:1;
		UINT8	trg0_ad1con2:1;
		UINT8	trg1_ad1con2:1;
		UINT8	b7:1;
	} bit;
	 UINT8 byte;
} AD1CON2_ADDR;
AD1CON2_ADDR	ad1con2_addr;

#define		AD1CON2		ad1con2_addr.byte

#define		SMP_AD1CON2	ad1con2_addr.bit.smp_ad1con2
#define		APS0_AD1CON2	ad1con2_addr.bit.aps0_ad1con2
#define		APS1_AD1CON2	ad1con2_addr.bit.aps1_ad1con2
#define		TRG0_AD1CON2	ad1con2_addr.bit.trg0_ad1con2
#define		TRG1_AD1CON2	ad1con2_addr.bit.trg1_ad1con2

/*------------------------------------------------------
    A-D1 control register 0
------------------------------------------------------*/
#pragma ADDRESS     ad1con0_addr 01d6H      /* A-D1 control register 0 */
typedef union {
	struct{
		UINT8	ch0_ad1con0:1;
		UINT8	ch1_ad1con0:1;
		UINT8	ch2_ad1con0:1;
		UINT8	md0_ad1con0:1;
		UINT8	md1_ad1con0:1;
		UINT8	trg_ad1con0:1;
		UINT8	adst_ad1con0:1;
		UINT8	cks0_ad1con0:1;
	} bit;
	 UINT8 byte;
} AD1CON0_ADDR;
AD1CON0_ADDR	ad1con0_addr;

#define		AD1CON0		ad1con0_addr.byte

#define		CH0_AD1CON0	ad1con0_addr.bit.ch0_ad1con0
#define		CH1_AD1CON0	ad1con0_addr.bit.ch1_ad1con0
#define		CH2_AD1CON0	ad1con0_addr.bit.ch2_ad1con0
#define		MD0_AD1CON0	ad1con0_addr.bit.md0_ad1con0
#define		MD1_AD1CON0	ad1con0_addr.bit.md1_ad1con0
#define		TRG_AD1CON0	ad1con0_addr.bit.trg_ad1con0
#define		ADST_AD1CON0	ad1con0_addr.bit.adst_ad1con0
#define		CKS0_AD1CON0	ad1con0_addr.bit.cks0_ad1con0

/*------------------------------------------------------
    A-D1 control  register 1
------------------------------------------------------*/
#pragma ADDRESS     ad1con1_addr 01d7H      /* A-D1 control register 1 */
typedef union {
	struct{
		UINT8	scan0_ad1con1:1;
		UINT8	scan1_ad1con1:1;
		UINT8	md2_ad1con1:1;
		UINT8	bits_ad1con1:1;
		UINT8	cks1_ad1con1:1;
		UINT8	vcut_ad1con1:1;
		UINT8	b6:1;
		UINT8	b7:1;
	} bit;
	 UINT8 byte;
} AD1CON1_ADDR;
AD1CON1_ADDR	ad1con1_addr;

#define		AD1CON1		ad1con1_addr.byte

#define		SCAN0_AD1CON1	ad1con1_addr.bit.scan0_ad1con1
#define		SCAN1_AD1CON1	ad1con1_addr.bit.scan1_ad1con1
#define		MD2_AD1CON1	ad1con1_addr.bit.md2_ad1con1
#define		BITS_AD1CON1	ad1con1_addr.bit.bits_ad1con1
#define		CKS1_AD1CON1	ad1con1_addr.bit.cks1_ad1con1
#define		VCUT_AD1CON1	ad1con1_addr.bit.vcut_ad1con1

/*------------------------------------------------------
    Can0 Messege Slot Buffer0 Data0	
------------------------------------------------------*/
#pragma ADDRESS		c0slot0_0_addr	01e0H	/* Can0 Messege Slot Buffer0 Data0 */
typedef union {
	struct{
		UINT8	sid6_c0slot0_0:1;
		UINT8	sid7_c0slot0_0:1;
		UINT8	sid8_c0slot0_0:1;
		UINT8	sid9_c0slot0_0:1;
		UINT8	sid10_c0slot0_0:1;
		UINT8	b5:1;
		UINT8	b6:1;
		UINT8	b7:1;
	} bit;
	 UINT8 byte;
} C0SLOT0_0_ADDR;
C0SLOT0_0_ADDR	c0slot0_0_addr;

#define		C0SLOT0_0	c0slot0_0_addr.byte

#define		SID6_C0SLOT0_0	c0slot0_0_addr.bit.sid6_c0slot0_0
#define		SID7_C0SLOT0_0	c0slot0_0_addr.bit.sid7_c0slot0_0
#define		SID8_C0SLOT0_0	c0slot0_0_addr.bit.sid8_c0slot0_0
#define		SID9_C0SLOT0_0	c0slot0_0_addr.bit.sid9_c0slot0_0
#define		SID10_C0SLOT0_0	c0slot0_0_addr.bit.sid10_c0slot0_0
/*------------------------------------------------------
    Can0 Messege Slot Buffer0 Data1
------------------------------------------------------*/
#pragma ADDRESS		c0slot0_1_addr	01e1H	/* Can0 Messege Slot Buffer0 Data1 */
typedef union {
	struct{
		UINT8	sid0_c0slot0_1:1;
		UINT8	sid1_c0slot0_1:1;
		UINT8	sid2_c0slot0_1:1;
		UINT8	sid3_c0slot0_1:1;
		UINT8	sid4_c0slot0_1:1;
		UINT8	sid5_c0slot0_1:1;
		UINT8	b6:1;
		UINT8	b7:1;
	} bit;
	 UINT8 byte;
} C0SLOT0_1_ADDR;
C0SLOT0_1_ADDR	c0slot0_1_addr;

#define		C0SLOT0_1	c0slot0_1_addr.byte

#define		SID0_C0SLOT0_1	c0slot0_1_addr.bit.sid0_c0slot0_1
#define		SID1_C0SLOT0_1	c0slot0_1_addr.bit.sid1_c0slot0_1
#define		SID2_C0SLOT0_1	c0slot0_1_addr.bit.sid2_c0slot0_1
#define		SID3_C0SLOT0_1	c0slot0_1_addr.bit.sid3_c0slot0_1
#define		SID4_C0SLOT0_1	c0slot0_1_addr.bit.sid4_c0slot0_1
#define		SID5_C0SLOT0_1	c0slot0_1_addr.bit.sid5_c0slot0_1
/*------------------------------------------------------
    Can0 Messege Slot Buffer0 Data2
------------------------------------------------------*/
#pragma ADDRESS		c0slot0_2_addr	01e2H	/* Can0 Messege Slot Buffer0 Data2 */
typedef union {
	struct{
		UINT8	eid14_c0slot0_2:1;
		UINT8	eid15_c0slot0_2:1;
		UINT8	eid16_c0slot0_2:1;
		UINT8	eid17_c0slot0_2:1;
		UINT8	b4:1;
		UINT8	b5:1;
		UINT8	b6:1;
		UINT8	b7:1;
	} bit;
	 UINT8 byte;
} C0SLOT0_2_ADDR;
C0SLOT0_2_ADDR	c0slot0_2_addr;

#define		C0SLOT0_2	c0slot0_2_addr.byte

#define		EID14_C0SLOT0_2	c0slot0_2_addr.bit.eid14_c0slot0_2
#define		EID15_C0SLOT0_2	c0slot0_2_addr.bit.eid15_c0slot0_2
#define		EID16_C0SLOT0_2	c0slot0_2_addr.bit.eid16_c0slot0_2
#define		EID17_C0SLOT0_2	c0slot0_2_addr.bit.eid17_c0slot0_2
/*------------------------------------------------------
    Can0 Messege Slot Buffer0 Data3
------------------------------------------------------*/
#pragma ADDRESS		c0slot0_3_addr	01e3H	/* Can0 Messege Slot Buffer0 Data3 */
typedef union {
	struct{
		UINT8	eid6_c0slot0_3:1;
		UINT8	eid7_c0slot0_3:1;
		UINT8	eid8_c0slot0_3:1;
		UINT8	eid9_c0slot0_3:1;
		UINT8	eid10_c0slot0_3:1;
		UINT8	eid11_c0slot0_3:1;
		UINT8	eid12_c0slot0_3:1;
		UINT8	eid13_c0slot0_3:1;
	} bit;
	 UINT8 byte;
} C0SLOT0_3_ADDR;
C0SLOT0_3_ADDR	c0slot0_3_addr;

#define		C0SLOT0_3	c0slot0_3_addr.byte

#define		EID6_C0SLOT0_3	c0slot0_3_addr.bit.eid6_c0slot0_3
#define		EID7_C0SLOT0_3	c0slot0_3_addr.bit.eid7_c0slot0_3
#define		EID8_C0SLOT0_3	c0slot0_3_addr.bit.eid8_c0slot0_3
#define		EID9_C0SLOT0_3	c0slot0_3_addr.bit.eid9_c0slot0_3
#define		EID10_C0SLOT0_3	c0slot0_3_addr.bit.eid10_c0slot0_3
#define		EID11_C0SLOT0_3	c0slot0_3_addr.bit.eid11_c0slot0_3
#define		EID12_C0SLOT0_3	c0slot0_3_addr.bit.eid12_c0slot0_3
#define		EID13_C0SLOT0_3	c0slot0_3_addr.bit.eid13_c0slot0_3
/*------------------------------------------------------
    Can0 Messege Slot Buffer0 Data4
------------------------------------------------------*/
#pragma ADDRESS		c0slot0_4_addr	01e4H	/* Can0 Messege Slot Buffer0 Data4 */
typedef union {
	struct{
		UINT8	eid0_c0slot0_4:1;
		UINT8	eid1_c0slot0_4:1;
		UINT8	eid2_c0slot0_4:1;
		UINT8	eid3_c0slot0_4:1;
		UINT8	eid4_c0slot0_4:1;
		UINT8	eid5_c0slot0_4:1;
		UINT8	b6:1;
		UINT8	b7:1;
	} bit;
	 UINT8 byte;
} C0SLOT0_4_ADDR;
C0SLOT0_4_ADDR	c0slot0_4_addr;

#define		C0SLOT0_4	c0slot0_4_addr.byte

#define		EID0_C0SLOT0_4	c0slot0_4_addr.bit.eid0_c0slot0_4
#define		EID1_C0SLOT0_4	c0slot0_4_addr.bit.eid1_c0slot0_4
#define		EID2_C0SLOT0_4	c0slot0_4_addr.bit.eid2_c0slot0_4
#define		EID3_C0SLOT0_4	c0slot0_4_addr.bit.eid3_c0slot0_4
#define		EID4_C0SLOT0_4	c0slot0_4_addr.bit.eid4_c0slot0_4
#define		EID5_C0SLOT0_4	c0slot0_4_addr.bit.eid5_c0slot0_4
/*------------------------------------------------------
    Can0 Messege Slot Buffer0 Data5
------------------------------------------------------*/
#pragma ADDRESS		c0slot0_5_addr	01e5H	/* Can0 Messege Slot Buffer0 Data5 */
typedef union {
	struct{
		UINT8	dlc0_c0slot0_5:1;
		UINT8	dlc1_c0slot0_5:1;
		UINT8	dlc2_c0slot0_5:1;
		UINT8	dlc3_c0slot0_5:1;
		UINT8	b4:1;
		UINT8	b5:1;
		UINT8	b6:1;
		UINT8	b7:1;
	} bit;
	 UINT8 byte;
} C0SLOT0_5_ADDR;
C0SLOT0_5_ADDR	c0slot0_5_addr;

#define		C0SLOT0_5	c0slot0_5_addr.byte

#define		DLC0_C0SLOT0_5	c0slot0_5_addr.bit.dlc0_c0slot0_5
#define		DLC1_C0SLOT0_5	c0slot0_5_addr.bit.dlc1_c0slot0_5
#define		DLC2_C0SLOT0_5	c0slot0_5_addr.bit.dlc2_c0slot0_5
#define		DLC3_C0SLOT0_5	c0slot0_5_addr.bit.dlc3_c0slot0_5
/*------------------------------------------------------
    Can0 Messege Slot Buffer0 Data6
------------------------------------------------------*/
#pragma ADDRESS		c0slot0_6_addr	01e6H	/* Can0 Messege Slot Buffer0 Data6 */
typedef union {
	struct{
		UINT8	b0:1;
		UINT8	b1:1;
		UINT8	b2:1;
		UINT8	b3:1;
		UINT8	b4:1;
		UINT8	b5:1;
		UINT8	b6:1;
		UINT8	b7:1;
	} bit;
	 UINT8 byte;
} C0SLOT0_6_ADDR;
C0SLOT0_6_ADDR	c0slot0_6_addr;

#define		C0SLOT0_6	c0slot0_6_addr.byte

/*------------------------------------------------------
    Can0 Messege Slot Buffer0 Data7
------------------------------------------------------*/
#pragma ADDRESS		c0slot0_7_addr	01e7H	/* Can0 Messege Slot Buffer0 Data7 */
typedef union {
	struct{
		UINT8	b0:1;
		UINT8	b1:1;
		UINT8	b2:1;
		UINT8	b3:1;
		UINT8	b4:1;
		UINT8	b5:1;
		UINT8	b6:1;
		UINT8	b7:1;
	} bit;
	 UINT8 byte;
} C0SLOT0_7_ADDR;
C0SLOT0_7_ADDR	c0slot0_7_addr;

#define		C0SLOT0_7	c0slot0_7_addr.byte

/*------------------------------------------------------
    Can0 Messege Slot Buffer0 Data8
------------------------------------------------------*/
#pragma ADDRESS		c0slot0_8_addr	01e8H	/* Can0 Messege Slot Buffer0 Data8 */
typedef union {
	struct{
		UINT8	b0:1;
		UINT8	b1:1;
		UINT8	b2:1;
		UINT8	b3:1;
		UINT8	b4:1;
		UINT8	b5:1;
		UINT8	b6:1;
		UINT8	b7:1;
	} bit;
	 UINT8 byte;
} C0SLOT0_8_ADDR;
C0SLOT0_8_ADDR	c0slot0_8_addr;

#define		C0SLOT0_8	c0slot0_8_addr.byte

/*------------------------------------------------------
    Can0 Messege Slot Buffer0 Data9
------------------------------------------------------*/
#pragma ADDRESS		c0slot0_9_addr	01e9H	/* Can0 Messege Slot Buffer0 Data9 */
typedef union {
	struct{
		UINT8	b0:1;
		UINT8	b1:1;
		UINT8	b2:1;
		UINT8	b3:1;
		UINT8	b4:1;
		UINT8	b5:1;
		UINT8	b6:1;
		UINT8	b7:1;
	} bit;
	 UINT8 byte;
} C0SLOT0_9_ADDR;
C0SLOT0_9_ADDR	c0slot0_9_addr;

#define		C0SLOT0_9	c0slot0_9_addr.byte

/*------------------------------------------------------
    Can0 Messege Slot Buffer0 Data10
------------------------------------------------------*/
#pragma ADDRESS		c0slot0_10_addr	01eaH	/* Can0 Messege Slot Buffer0 Data10 */
typedef union {
	struct{
		UINT8	b0:1;
		UINT8	b1:1;
		UINT8	b2:1;
		UINT8	b3:1;
		UINT8	b4:1;
		UINT8	b5:1;
		UINT8	b6:1;
		UINT8	b7:1;
	} bit;
	 UINT8 byte;
} C0SLOT0_10_ADDR;
C0SLOT0_10_ADDR	c0slot0_10_addr;

#define		C0SLOT0_10	c0slot0_10_addr.byte

/*------------------------------------------------------
    Can0 Messege Slot Buffer0 Data11
------------------------------------------------------*/
#pragma ADDRESS		c0slot0_11_addr	01ebH	/* Can0 Messege Slot Buffer0 Data11 */
typedef union {
	struct{
		UINT8	b0:1;
		UINT8	b1:1;
		UINT8	b2:1;
		UINT8	b3:1;
		UINT8	b4:1;
		UINT8	b5:1;
		UINT8	b6:1;
		UINT8	b7:1;
	} bit;
	 UINT8 byte;
} C0SLOT0_11_ADDR;
C0SLOT0_11_ADDR	c0slot0_11_addr;

#define		C0SLOT0_11	c0slot0_11_addr.byte

/*------------------------------------------------------
    Can0 Messege Slot Buffer0 Data12
------------------------------------------------------*/
#pragma ADDRESS		c0slot0_12_addr	01ecH	/* Can0 Messege Slot Buffer0 Data12 */
typedef union {
	struct{
		UINT8	b0:1;
		UINT8	b1:1;
		UINT8	b2:1;
		UINT8	b3:1;
		UINT8	b4:1;
		UINT8	b5:1;
		UINT8	b6:1;
		UINT8	b7:1;
	} bit;
	 UINT8 byte;
} C0SLOT0_12_ADDR;
C0SLOT0_12_ADDR	c0slot0_12_addr;

#define		C0SLOT0_12	c0slot0_12_addr.byte

/*------------------------------------------------------
    Can0 Messege Slot Buffer0 Data13
------------------------------------------------------*/
#pragma ADDRESS		c0slot0_13_addr	01edH	/* Can0 Messege Slot Buffer0 Data13 */
typedef union {
	struct{
		UINT8	b0:1;
		UINT8	b1:1;
		UINT8	b2:1;
		UINT8	b3:1;
		UINT8	b4:1;
		UINT8	b5:1;
		UINT8	b6:1;
		UINT8	b7:1;
	} bit;
	 UINT8 byte;
} C0SLOT0_13_ADDR;
C0SLOT0_13_ADDR	c0slot0_13_addr;

#define		C0SLOT0_13	c0slot0_13_addr.byte

/*------------------------------------------------------
    Can0 Messege Slot Buffer0 Data14
------------------------------------------------------*/
#pragma ADDRESS		c0slot0_14_addr	01eeH	/* Can0 Messege Slot Buffer0 Data14 */
typedef union {
	struct{
		UINT8	b0:1;
		UINT8	b1:1;
		UINT8	b2:1;
		UINT8	b3:1;
		UINT8	b4:1;
		UINT8	b5:1;
		UINT8	b6:1;
		UINT8	b7:1;
	} bit;
	 UINT8 byte;
} C0SLOT0_14_ADDR;
C0SLOT0_14_ADDR	c0slot0_14_addr;

#define		C0SLOT0_14	c0slot0_14_addr.byte

/*------------------------------------------------------
    Can0 Messege Slot Buffer0 Data15
------------------------------------------------------*/
#pragma ADDRESS		c0slot0_15_addr	01efH	/* Can0 Messege Slot Buffer0 Data15 */
typedef union {
	struct{
		UINT8	b0:1;
		UINT8	b1:1;
		UINT8	b2:1;
		UINT8	b3:1;
		UINT8	b4:1;
		UINT8	b5:1;
		UINT8	b6:1;
		UINT8	b7:1;
	} bit;
	 UINT8 byte;
} C0SLOT0_15_ADDR;
C0SLOT0_15_ADDR	c0slot0_15_addr;

#define		C0SLOT0_15	c0slot0_15_addr.byte

/*------------------------------------------------------
    Can0 Messege Slot Buffer1 Data0	
------------------------------------------------------*/
#pragma ADDRESS		c0slot1_0_addr	01f0H	/* Can0 Messege Slot Buffer1 Data0 */
typedef union {
	struct{
		UINT8	sid6_c0slot1_0:1;
		UINT8	sid7_c0slot1_0:1;
		UINT8	sid8_c0slot1_0:1;
		UINT8	sid9_c0slot1_0:1;
		UINT8	sid10_c0slot1_0:1;
		UINT8	b5:1;
		UINT8	b6:1;
		UINT8	b7:1;
	} bit;
	 UINT8 byte;
} C0SLOT1_0_ADDR;
C0SLOT1_0_ADDR	c0slot1_0_addr;

#define		C0SLOT1_0	c0slot1_0_addr.byte

#define		SID6_C0SLOT1_0	c0slot1_0_addr.bit.sid6_c0slot1_0
#define		SID7_C0SLOT1_0	c0slot1_0_addr.bit.sid7_c0slot1_0
#define		SID8_C0SLOT1_0	c0slot1_0_addr.bit.sid8_c0slot1_0
#define		SID9_C0SLOT1_0	c0slot1_0_addr.bit.sid9_c0slot1_0
#define		SID10_C0SLOT1_0	c0slot1_0_addr.bit.sid10_c0slot1_0
/*------------------------------------------------------
    Can0 Messege Slot Buffer1 Data1
------------------------------------------------------*/
#pragma ADDRESS		c0slot1_1_addr	01f1H	/* Can0 Messege Slot Buffer1 Data1 */
typedef union {
	struct{
		UINT8	sid0_c0slot1_1:1;
		UINT8	sid1_c0slot1_1:1;
		UINT8	sid2_c0slot1_1:1;
		UINT8	sid3_c0slot1_1:1;
		UINT8	sid4_c0slot1_1:1;
		UINT8	sid5_c0slot1_1:1;
		UINT8	b6:1;
		UINT8	b7:1;
	} bit;
	 UINT8 byte;
} C0SLOT1_1_ADDR;
C0SLOT1_1_ADDR	c0slot1_1_addr;

#define		C0SLOT1_1	c0slot1_1_addr.byte

#define		SID0_C0SLOT1_1	c0slot1_1_addr.bit.sid0_c0slot1_1
#define		SID1_C0SLOT1_1	c0slot1_1_addr.bit.sid1_c0slot1_1
#define		SID2_C0SLOT1_1	c0slot1_1_addr.bit.sid2_c0slot1_1
#define		SID3_C0SLOT1_1	c0slot1_1_addr.bit.sid3_c0slot1_1
#define		SID4_C0SLOT1_1	c0slot1_1_addr.bit.sid4_c0slot1_1
#define		SID5_C0SLOT1_1	c0slot1_1_addr.bit.sid5_c0slot1_1
/*------------------------------------------------------
    Can0 Messege Slot Buffer1 Data2
------------------------------------------------------*/
#pragma ADDRESS		c0slot1_2_addr	01f2H	/* Can0 Messege Slot Buffer1 Data2 */
typedef union {
	struct{
		UINT8	eid14_c0slot1_2:1;
		UINT8	eid15_c0slot1_2:1;
		UINT8	eid16_c0slot1_2:1;
		UINT8	eid17_c0slot1_2:1;
		UINT8	b4:1;
		UINT8	b5:1;
		UINT8	b6:1;
		UINT8	b7:1;
	} bit;
	 UINT8 byte;
} C0SLOT1_2_ADDR;
C0SLOT1_2_ADDR	c0slot1_2_addr;

#define		C0SLOT1_2	c0slot1_2_addr.byte

#define		EID14_C0SLOT1_2	c0slot1_2_addr.bit.eid14_c0slot1_2
#define		EID15_C0SLOT1_2	c0slot1_2_addr.bit.eid15_c0slot1_2
#define		EID16_C0SLOT1_2	c0slot1_2_addr.bit.eid16_c0slot1_2
#define		EID17_C0SLOT1_2	c0slot1_2_addr.bit.eid17_c0slot1_2
/*------------------------------------------------------
    Can0 Messege Slot Buffer1 Data3
------------------------------------------------------*/
#pragma ADDRESS		c0slot1_3_addr	01f3H	/* Can0 Messege Slot Buffer1 Data3 */
typedef union {
	struct{
		UINT8	eid6_c0slot1_3:1;
		UINT8	eid7_c0slot1_3:1;
		UINT8	eid8_c0slot1_3:1;
		UINT8	eid9_c0slot1_3:1;
		UINT8	eid10_c0slot1_3:1;
		UINT8	eid11_c0slot1_3:1;
		UINT8	eid12_c0slot1_3:1;
		UINT8	eid13_c0slot1_3:1;
	} bit;
	 UINT8 byte;
} C0SLOT1_3_ADDR;
C0SLOT1_3_ADDR	c0slot1_3_addr;

#define		C0SLOT1_3	c0slot1_3_addr.byte

#define		EID6_C0SLOT1_3	c0slot1_3_addr.bit.eid6_c0slot1_3
#define		EID7_C0SLOT1_3	c0slot1_3_addr.bit.eid7_c0slot1_3
#define		EID8_C0SLOT1_3	c0slot1_3_addr.bit.eid8_c0slot1_3
#define		EID9_C0SLOT1_3	c0slot1_3_addr.bit.eid9_c0slot1_3
#define		EID10_C0SLOT1_3	c0slot1_3_addr.bit.eid10_c0slot1_3
#define		EID11_C0SLOT1_3	c0slot1_3_addr.bit.eid11_c0slot1_3
#define		EID12_C0SLOT1_3	c0slot1_3_addr.bit.eid12_c0slot1_3
#define		EID13_C0SLOT1_3	c0slot1_3_addr.bit.eid13_c0slot1_3
/*------------------------------------------------------
    Can0 Messege Slot Buffer1 Data4
------------------------------------------------------*/
#pragma ADDRESS		c0slot1_4_addr	01f4H	/* Can0 Messege Slot Buffer1 Data4 */
typedef union {
	struct{
		UINT8	eid0_c0slot1_4:1;
		UINT8	eid1_c0slot1_4:1;
		UINT8	eid2_c0slot1_4:1;
		UINT8	eid3_c0slot1_4:1;
		UINT8	eid4_c0slot1_4:1;
		UINT8	eid5_c0slot1_4:1;
		UINT8	b6:1;
		UINT8	b7:1;
	} bit;
	 UINT8 byte;
} C0SLOT1_4_ADDR;
C0SLOT1_4_ADDR	c0slot1_4_addr;

#define		C0SLOT1_4	c0slot1_4_addr.byte

#define		EID0_C0SLOT1_4	c0slot1_4_addr.bit.eid0_c0slot1_4
#define		EID1_C0SLOT1_4	c0slot1_4_addr.bit.eid1_c0slot1_4
#define		EID2_C0SLOT1_4	c0slot1_4_addr.bit.eid2_c0slot1_4
#define		EID3_C0SLOT1_4	c0slot1_4_addr.bit.eid3_c0slot1_4
#define		EID4_C0SLOT1_4	c0slot1_4_addr.bit.eid4_c0slot1_4
#define		EID5_C0SLOT1_4	c0slot1_4_addr.bit.eid5_c0slot1_4
/*------------------------------------------------------
    Can0 Messege Slot Buffer1 Data5
------------------------------------------------------*/
#pragma ADDRESS		c0slot1_5_addr	01f5H	/* Can0 Messege Slot Buffer1 Data5 */
typedef union {
	struct{
		UINT8	dlc0_c0slot1_5:1;
		UINT8	dlc1_c0slot1_5:1;
		UINT8	dlc2_c0slot1_5:1;
		UINT8	dlc3_c0slot1_5:1;
		UINT8	b4:1;
		UINT8	b5:1;
		UINT8	b6:1;
		UINT8	b7:1;
	} bit;
	 UINT8 byte;
} C0SLOT1_5_ADDR;
C0SLOT1_5_ADDR	c0slot1_5_addr;

#define		C0SLOT1_5	c0slot1_5_addr.byte

#define		DLC0_C0SLOT1_5	c0slot1_5_addr.bit.dlc0_c0slot1_5
#define		DLC1_C0SLOT1_5	c0slot1_5_addr.bit.dlc1_c0slot1_5
#define		DLC2_C0SLOT1_5	c0slot1_5_addr.bit.dlc2_c0slot1_5
#define		DLC3_C0SLOT1_5	c0slot1_5_addr.bit.dlc3_c0slot1_5
/*------------------------------------------------------
    Can0 Messege Slot Buffer1 Data6
------------------------------------------------------*/
#pragma ADDRESS		c0slot1_6_addr	01f6H	/* Can0 Messege Slot Buffer1 Data6 */
typedef union {
	struct{
		UINT8	b0:1;
		UINT8	b1:1;
		UINT8	b2:1;
		UINT8	b3:1;
		UINT8	b4:1;
		UINT8	b5:1;
		UINT8	b6:1;
		UINT8	b7:1;
	} bit;
	 UINT8 byte;
} C0SLOT1_6_ADDR;
C0SLOT1_6_ADDR	c0slot1_6_addr;

#define		C0SLOT1_6	c0slot1_6_addr.byte

/*------------------------------------------------------
    Can0 Messege Slot Buffer1 Data7
------------------------------------------------------*/
#pragma ADDRESS		c0slot1_7_addr	01f7H	/* Can0 Messege Slot Buffer1 Data7 */
typedef union {
	struct{
		UINT8	b0:1;
		UINT8	b1:1;
		UINT8	b2:1;
		UINT8	b3:1;
		UINT8	b4:1;
		UINT8	b5:1;
		UINT8	b6:1;
		UINT8	b7:1;
	} bit;
	 UINT8 byte;
} C0SLOT1_7_ADDR;
C0SLOT1_7_ADDR	c0slot1_7_addr;

#define		C0SLOT1_7	c0slot1_7_addr.byte

/*------------------------------------------------------
    Can0 Messege Slot Buffer1 Data8
------------------------------------------------------*/
#pragma ADDRESS		c0slot1_8_addr	01f8H	/* Can0 Messege Slot Buffer1 Data8 */
typedef union {
	struct{
		UINT8	b0:1;
		UINT8	b1:1;
		UINT8	b2:1;
		UINT8	b3:1;
		UINT8	b4:1;
		UINT8	b5:1;
		UINT8	b6:1;
		UINT8	b7:1;
	} bit;
	 UINT8 byte;
} C0SLOT1_8_ADDR;
C0SLOT1_8_ADDR	c0slot1_8_addr;

#define		C0SLOT1_8	c0slot1_8_addr.byte

/*------------------------------------------------------
    Can0 Messege Slot Buffer1 Data9
------------------------------------------------------*/
#pragma ADDRESS		c0slot1_9_addr	01f9H	/* Can0 Messege Slot Buffer1 Data9 */
typedef union {
	struct{
		UINT8	b0:1;
		UINT8	b1:1;
		UINT8	b2:1;
		UINT8	b3:1;
		UINT8	b4:1;
		UINT8	b5:1;
		UINT8	b6:1;
		UINT8	b7:1;
	} bit;
	 UINT8 byte;
} C0SLOT1_9_ADDR;
C0SLOT1_9_ADDR	c0slot1_9_addr;

#define		C0SLOT1_9	c0slot1_9_addr.byte

/*------------------------------------------------------
    Can0 Messege Slot Buffer1 Data10
------------------------------------------------------*/
#pragma ADDRESS		c0slot1_10_addr	01faH	/* Can0 Messege Slot Buffer1 Data10 */
typedef union {
	struct{
		UINT8	b0:1;
		UINT8	b1:1;
		UINT8	b2:1;
		UINT8	b3:1;
		UINT8	b4:1;
		UINT8	b5:1;
		UINT8	b6:1;
		UINT8	b7:1;
	} bit;
	 UINT8 byte;
} C0SLOT1_10_ADDR;
C0SLOT1_10_ADDR	c0slot1_10_addr;

#define		C0SLOT1_10	c0slot1_10_addr.byte

/*------------------------------------------------------
    Can0 Messege Slot Buffer1 Data11
------------------------------------------------------*/
#pragma ADDRESS		c0slot1_11_addr	01fbH	/* Can0 Messege Slot Buffer1 Data11 */
typedef union {
	struct{
		UINT8	b0:1;
		UINT8	b1:1;
		UINT8	b2:1;
		UINT8	b3:1;
		UINT8	b4:1;
		UINT8	b5:1;
		UINT8	b6:1;
		UINT8	b7:1;
	} bit;
	 UINT8 byte;
} C0SLOT1_11_ADDR;
C0SLOT1_11_ADDR	c0slot1_11_addr;

#define		C0SLOT1_11	c0slot1_11_addr.byte

/*------------------------------------------------------
    Can0 Messege Slot Buffer1 Data12
------------------------------------------------------*/
#pragma ADDRESS		c0slot1_12_addr	01fcH	/* Can0 Messege Slot Buffer1 Data12 */
typedef union {
	struct{
		UINT8	b0:1;
		UINT8	b1:1;
		UINT8	b2:1;
		UINT8	b3:1;
		UINT8	b4:1;
		UINT8	b5:1;
		UINT8	b6:1;
		UINT8	b7:1;
	} bit;
	 UINT8 byte;
} C0SLOT1_12_ADDR;
C0SLOT1_12_ADDR	c0slot1_12_addr;

#define		C0SLOT1_12	c0slot1_12_addr.byte

/*------------------------------------------------------
    Can0 Messege Slot Buffer1 Data13
------------------------------------------------------*/
#pragma ADDRESS		c0slot1_13_addr	01fdH	/* Can0 Messege Slot Buffer1 Data13 */
typedef union {
	struct{
		UINT8	b0:1;
		UINT8	b1:1;
		UINT8	b2:1;
		UINT8	b3:1;
		UINT8	b4:1;
		UINT8	b5:1;
		UINT8	b6:1;
		UINT8	b7:1;
	} bit;
	 UINT8 byte;
} C0SLOT1_13_ADDR;
C0SLOT1_13_ADDR	c0slot1_13_addr;

#define		C0SLOT1_13	c0slot1_13_addr.byte

/*------------------------------------------------------
    Can0 Messege Slot Buffer1 Data14
------------------------------------------------------*/
#pragma ADDRESS		c0slot1_14_addr	01feH	/* Can0 Messege Slot Buffer1 Data14 */
typedef union {
	struct{
		UINT8	b0:1;
		UINT8	b1:1;
		UINT8	b2:1;
		UINT8	b3:1;
		UINT8	b4:1;
		UINT8	b5:1;
		UINT8	b6:1;
		UINT8	b7:1;
	} bit;
	 UINT8 byte;
} C0SLOT1_14_ADDR;
C0SLOT1_14_ADDR	c0slot1_14_addr;

#define		C0SLOT1_14	c0slot1_14_addr.byte

/*------------------------------------------------------
    Can0 Messege Slot Buffer1 Data15
------------------------------------------------------*/
#pragma ADDRESS		c0slot1_15_addr	01ffH	/* Can0 Messege Slot Buffer1 Data15 */
typedef union {
	struct{
		UINT8	b0:1;
		UINT8	b1:1;
		UINT8	b2:1;
		UINT8	b3:1;
		UINT8	b4:1;
		UINT8	b5:1;
		UINT8	b6:1;
		UINT8	b7:1;
	} bit;
	 UINT8 byte;
} C0SLOT1_15_ADDR;
C0SLOT1_15_ADDR	c0slot1_15_addr;

#define		C0SLOT1_15	c0slot1_15_addr.byte

/*------------------------------------------------------
     Can0 Control Register 0
------------------------------------------------------*/
#pragma ADDRESS		c0ctlr0_addr	0200H	/* Can0 Status Register */
typedef union {
    struct{
        UINT8    b0:1;
        UINT8    b1:1;
        UINT8    b2:1;
        UINT8    b3:1;
        UINT8    b4:1;
        UINT8    b5:1;
        UINT8    b6:1;
        UINT8    b7:1;
        UINT8    b8:1;
        UINT8    b9:1;
        UINT8    b10:1;
        UINT8    b11:1;
        UINT8    b12:1;
        UINT8    b13:1;
        UINT8    b14:1;
        UINT8    b15:1;
    } bit;
    struct{
        UINT8    low;                /* low  8 bit */
        UINT8    high;               /* high 8 bit */
    } byte;
    UINT16  word;
} C0CTLR0_ADDR;
C0CTLR0_ADDR	c0ctlr0_addr;

#define		C0CTLR0        c0ctlr0_addr.word
#define		C0CTLR0L       c0ctlr0_addr.byte.low
#define		C0CTLR0H       c0ctlr0_addr.byte.high

#define		RESET0_C0CTLR0		 c0ctlr0_addr.bit.b0
#define		LOOPBACK_C0CTLR0	 c0ctlr0_addr.bit.b1
//#define     CSS_c0ctlr0			 c0ctlr0_addr.bit.b2
#define		BASICCAN_C0CTLR0	 c0ctlr0_addr.bit.b3
#define		RESET1_C0CTLR0		 c0ctlr0_addr.bit.b4
#define		TSPRE0_C0CTLR0		 c0ctlr0_addr.bit.b8
#define		TSPRE1_C0CTLR0		 c0ctlr0_addr.bit.b9
#define		TSRESET_C0CTLR0		 c0ctlr0_addr.bit.b10
#define		ECRESET_C0CTLR0		 c0ctlr0_addr.bit.b11
//#define     css_c0ctlr0			 c0ctlr0_addr.bit.b2

/*------------------------------------------------------
     Can0 Status Register
------------------------------------------------------*/
#pragma ADDRESS		c0str_addr		0202H	/* Can0 Status Register */
typedef union {
    struct{
        UINT8    b0:1;
        UINT8    b1:1;
        UINT8    b2:1;
        UINT8    b3:1;
        UINT8    b4:1;
        UINT8    b5:1;
        UINT8    b6:1;
        UINT8    b7:1;
        UINT8    b8:1;
        UINT8    b9:1;
        UINT8    b10:1;
        UINT8    b11:1;
        UINT8    b12:1;
        UINT8    b13:1;
        UINT8    b14:1;
        UINT8    b15:1;
    } bit;
    struct{
        UINT8    low;                /* low  8 bit */
        UINT8    high;               /* high 8 bit */
    } byte;
    UINT16  word;
} C0STR_ADDR;
C0STR_ADDR	c0str_addr;

#define		C0STR        c0str_addr.word
#define		C0STRL       c0str_addr.byte.low
#define		C0STRH       c0str_addr.byte.high

#define		MBOX0_C0STR			  c0str_addr.bit.b0
#define		MBOX1_C0STR			  c0str_addr.bit.b1
#define		MBOX2_C0STR			  c0str_addr.bit.b2
#define		MBOX3_C0STR			  c0str_addr.bit.b3
#define		TRMSUCC_C0STR		  c0str_addr.bit.b4
#define		RECSUCC_C0STR		  c0str_addr.bit.b5
#define		TRMSTATE_C0STR		  c0str_addr.bit.b6
#define		RECSTATE_C0STR		  c0str_addr.bit.b7
#define		STATE_RESET_C0STR	  c0str_addr.bit.b8
#define		STATE_LOOPBACK_C0STR  c0str_addr.bit.b9
#define		STATE_BASICCAN_C0STR  c0str_addr.bit.b11
#define		STATE_BUSERROR_C0STR  c0str_addr.bit.b12
#define		STATE_ERRPAS_C0STR	  c0str_addr.bit.b13
#define		STATE_BUSOFF_C0STR	  c0str_addr.bit.b14

/*------------------------------------------------------
     Can0 Extended ID Register
------------------------------------------------------*/
#pragma ADDRESS		c0idr_addr		0204H	/* Can0 Extended ID Register */
typedef union {
    struct{
        UINT8    b0:1;
        UINT8    b1:1;
        UINT8    b2:1;
        UINT8    b3:1;
        UINT8    b4:1;
        UINT8    b5:1;
        UINT8    b6:1;
        UINT8    b7:1;
        UINT8    b8:1;
        UINT8    b9:1;
        UINT8    b10:1;
        UINT8    b11:1;
        UINT8    b12:1;
        UINT8    b13:1;
        UINT8    b14:1;
        UINT8    b15:1;
    } bit;
    struct{
        UINT8    low;                /* low  8 bit */
        UINT8    high;               /* high 8 bit */
    } byte;
    UINT16  word;
} C0IDR_ADDR;
C0IDR_ADDR	c0idr_addr;

#define		C0IDR        c0idr_addr.word
#define		C0IDRL       c0idr_addr.byte.low
#define		C0IDRH       c0idr_addr.byte.high

#define		IDE15_C0IDR		c0idr_addr.bit.b0
#define		IDE14_C0IDR		c0idr_addr.bit.b1
#define		IDE13_C0IDR		c0idr_addr.bit.b2
#define		IDE12_C0IDR		c0idr_addr.bit.b3
#define		IDE11_C0IDR		c0idr_addr.bit.b4
#define		IDE10_C0IDR		c0idr_addr.bit.b5
#define		IDE9_C0IDR		c0idr_addr.bit.b6
#define		IDE8_C0IDR		c0idr_addr.bit.b7
#define		IDE7_C0IDR		c0idr_addr.bit.b8
#define		IDE6_C0IDR		c0idr_addr.bit.b9
#define		IDE5_C0IDR		c0idr_addr.bit.b10
#define		IDE4_C0IDR		c0idr_addr.bit.b11
#define		IDE3_C0IDR		c0idr_addr.bit.b12
#define		IDE2_C0IDR		c0idr_addr.bit.b13
#define		IDE1_C0IDR		c0idr_addr.bit.b14
#define		IDE0_C0IDR		c0idr_addr.bit.b15

/*------------------------------------------------------
      Can0 Configration Register
------------------------------------------------------*/
#pragma ADDRESS		c0conr_addr		0206H	/* Can0 Configration Register */
typedef union {
    struct{
        UINT8    b0:1;
        UINT8    b1:1;
        UINT8    b2:1;
        UINT8    b3:1;
        UINT8    b4:1;
        UINT8    b5:1;
        UINT8    b6:1;
        UINT8    b7:1;
        UINT8    b8:1;
        UINT8    b9:1;
        UINT8    b10:1;
        UINT8    b11:1;
        UINT8    b12:1;
        UINT8    b13:1;
        UINT8    b14:1;
        UINT8    b15:1;
    } bit;
    struct{
        UINT8    low;                /* low  8 bit */
        UINT8    high;               /* high 8 bit */
    } byte;
    UINT16  word;
} C0CONR_ADDR;
C0CONR_ADDR	c0conr_addr;

#define		C0CONR        c0conr_addr.word
#define		C0CONRL       c0conr_addr.byte.low
#define		C0CONRH       c0conr_addr.byte.high

#define		SAM_C0CONR		c0conr_addr.bit.b4
#define		PTS0_C0CONR		c0conr_addr.bit.b5
#define		PTS1_C0CONR		c0conr_addr.bit.b6
#define		PTS2_C0CONR		c0conr_addr.bit.b7
#define		PBS10_C0CONR	c0conr_addr.bit.b8
#define		PBS11_C0CONR	c0conr_addr.bit.b9
#define		PBS12_C0CONR	c0conr_addr.bit.b10
#define		PBS20_C0CONR	c0conr_addr.bit.b11
#define		PBS21_C0CONR	c0conr_addr.bit.b12
#define		PBS22_C0CONR	c0conr_addr.bit.b13
#define		SJW0_C0CONR		c0conr_addr.bit.b14
#define		SJW1_C0CONR		c0conr_addr.bit.b15

/*------------------------------------------------------
      Can0 Time Stamp Register
------------------------------------------------------*/
#pragma ADDRESS		c0tsr_addr		0208H	/* Can0 Time Stamp Register */
typedef union {
    struct{
        UINT8    b0:1;
        UINT8    b1:1;
        UINT8    b2:1;
        UINT8    b3:1;
        UINT8    b4:1;
        UINT8    b5:1;
        UINT8    b6:1;
        UINT8    b7:1;
        UINT8    b8:1;
        UINT8    b9:1;
        UINT8    b10:1;
        UINT8    b11:1;
        UINT8    b12:1;
        UINT8    b13:1;
        UINT8    b14:1;
        UINT8    b15:1;
    } bit;
    struct{
        UINT8    low;                /* low  8 bit */
        UINT8    high;               /* high 8 bit */
    } byte;
    UINT16  word;
} C0TSR_ADDR;
C0TSR_ADDR	c0tsr_addr;

#define		C0TSR        c0tsr_addr.word
#define		C0TSRL       c0tsr_addr.byte.low
#define		C0TSRH       c0tsr_addr.byte.high

/*------------------------------------------------------
    Can0 Transmit Error Count Register
------------------------------------------------------*/
#pragma ADDRESS		c0tec_addr		020aH	/* Can0 Transmit Error Count Register */
typedef union {
	struct{
		UINT8	b0:1;
		UINT8	b1:1;
		UINT8	b2:1;
		UINT8	b3:1;
		UINT8	b4:1;
		UINT8	b5:1;
		UINT8	b6:1;
		UINT8	b7:1;
	} bit;
	 UINT8 byte;
} C0TEC_ADDR;
C0TEC_ADDR	c0tec_addr;

#define		C0TEC		c0tec_addr.byte

/*------------------------------------------------------
    Can0 Receive Error Count Register
------------------------------------------------------*/
#pragma ADDRESS		c0rec_addr		020bH	/* Can0 Receive Error Count Register */
typedef union {
	struct{
		UINT8	b0:1;
		UINT8	b1:1;
		UINT8	b2:1;
		UINT8	b3:1;
		UINT8	b4:1;
		UINT8	b5:1;
		UINT8	b6:1;
		UINT8	b7:1;
	} bit;
	 UINT8 byte;
} C0REC_ADDR;
C0REC_ADDR	c0rec_addr;

#define		C0REC		c0rec_addr.byte

/*------------------------------------------------------
     Can0 Slot Interrupt Status Register
------------------------------------------------------*/
#pragma ADDRESS		c0sistr_addr	020cH	/* Can0 Slot Interrupt Status Register	*/
typedef union {
    struct{
        UINT8    b0:1;
        UINT8    b1:1;
        UINT8    b2:1;
        UINT8    b3:1;
        UINT8    b4:1;
        UINT8    b5:1;
        UINT8    b6:1;
        UINT8    b7:1;
        UINT8    b8:1;
        UINT8    b9:1;
        UINT8    b10:1;
        UINT8    b11:1;
        UINT8    b12:1;
        UINT8    b13:1;
        UINT8    b14:1;
        UINT8    b15:1;
    } bit;
    struct{
        UINT8    low;                /* low  8 bit */
        UINT8    high;               /* high 8 bit */
    } byte;
    UINT16  word;
} C0SISTR_ADDR;
C0SISTR_ADDR	c0sistr_addr;

#define		C0SISTR        c0sistr_addr.word
#define		C0SISTRL       c0sistr_addr.byte.low
#define		C0SISTRH       c0sistr_addr.byte.high

#define		SIS15_C0SISTR		c0sistr_addr.bit.b0
#define		SIS14_C0SISTR		c0sistr_addr.bit.b1
#define		SIS13_C0SISTR		c0sistr_addr.bit.b2
#define		SIS12_C0SISTR		c0sistr_addr.bit.b3
#define		SIS11_C0SISTR		c0sistr_addr.bit.b4
#define		SIS10_C0SISTR		c0sistr_addr.bit.b5
#define		SIS9_C0SISTR		c0sistr_addr.bit.b6
#define		SIS8_C0SISTR		c0sistr_addr.bit.b7
#define		SIS7_C0SISTR		c0sistr_addr.bit.b8
#define		SIS6_C0SISTR		c0sistr_addr.bit.b9
#define		SIS5_C0SISTR		c0sistr_addr.bit.b10
#define		SIS4_C0SISTR		c0sistr_addr.bit.b11
#define		SIS3_C0SISTR		c0sistr_addr.bit.b12
#define		SIS2_C0SISTR		c0sistr_addr.bit.b13
#define		SIS1_C0SISTR		c0sistr_addr.bit.b14
#define		SIS0_C0SISTR		c0sistr_addr.bit.b15

/*------------------------------------------------------
     Can0 Slot Interrupt Mask Register
------------------------------------------------------*/
#pragma ADDRESS		c0simkr_addr	0210H	/* Can0 Slot Interrupt Mask Register */
typedef union {
    struct{
        UINT8    b0:1;
        UINT8    b1:1;
        UINT8    b2:1;
        UINT8    b3:1;
        UINT8    b4:1;
        UINT8    b5:1;
        UINT8    b6:1;
        UINT8    b7:1;
        UINT8    b8:1;
        UINT8    b9:1;
        UINT8    b10:1;
        UINT8    b11:1;
        UINT8    b12:1;
        UINT8    b13:1;
        UINT8    b14:1;
        UINT8    b15:1;
    } bit;
    struct{
        UINT8    low;                /* low  8 bit */
        UINT8    high;               /* high 8 bit */
    } byte;
    UINT16  word;
} C0SIMKR_ADDR;
C0SIMKR_ADDR	c0simkr_addr;

#define		C0SIMKR        c0simkr_addr.word
#define		C0SIMKRL       c0simkr_addr.byte.low
#define		C0SIMKRH       c0simkr_addr.byte.high

#define		SIM15_C0SIMKR		c0simkr_addr.bit.b0
#define		SIM14_C0SIMKR		c0simkr_addr.bit.b1
#define		SIM13_C0SIMKR		c0simkr_addr.bit.b2
#define		SIM12_C0SIMKR		c0simkr_addr.bit.b3
#define		SIM11_C0SIMKR		c0simkr_addr.bit.b4
#define		SIM10_C0SIMKR		c0simkr_addr.bit.b5
#define		SIM9_C0SIMKR		c0simkr_addr.bit.b6
#define		SIM8_C0SIMKR		c0simkr_addr.bit.b7
#define		SIM7_C0SIMKR		c0simkr_addr.bit.b8
#define		SIM6_C0SIMKR		c0simkr_addr.bit.b9
#define		SIM5_C0SIMKR		c0simkr_addr.bit.b10
#define		SIM4_C0SIMKR		c0simkr_addr.bit.b11
#define		SIM3_C0SIMKR		c0simkr_addr.bit.b12
#define		SIM2_C0SIMKR		c0simkr_addr.bit.b13
#define		SIM1_C0SIMKR		c0simkr_addr.bit.b14
#define		SIM0_C0SIMKR		c0simkr_addr.bit.b15

/*------------------------------------------------------
    Can0 Error Interrupt Mask Register
------------------------------------------------------*/
#pragma ADDRESS		c0eimkr_addr	0214H	/* Can0 Error Interrupt Mask Register */
typedef union {
	struct{
		UINT8	boim_c0eimkr:1;
		UINT8	epim_c0eimkr:1;
		UINT8	beim_c0eimkr:1;
		UINT8	b3:1;
		UINT8	b4:1;
		UINT8	b5:1;
		UINT8	b6:1;
		UINT8	b7:1;
	} bit;
	 UINT8 byte;
} C0EIMKR_ADDR;
C0EIMKR_ADDR	c0eimkr_addr;

#define		C0EIMKR		c0eimkr_addr.byte

#define		BOIM_C0EIMKR	c0eimkr_addr.bit.boim_c0eimkr
#define		EPIM_C0EIMKR	c0eimkr_addr.bit.epim_c0eimkr
#define		BEIM_C0EIMKR	c0eimkr_addr.bit.beim_c0eimkr

/*------------------------------------------------------
    Can0 Error Interrupt Status Register
------------------------------------------------------*/
#pragma ADDRESS		c0eistr_addr	0215H	/* Can0 Error Interrupt Status Register */
typedef union {
	struct{
		UINT8	bois_c0eistr:1;
		UINT8	epis_c0eistr:1;
		UINT8	beis_c0eistr:1;
		UINT8	b3:1;
		UINT8	b4:1;
		UINT8	b5:1;
		UINT8	b6:1;
		UINT8	b7:1;
	} bit;
	 UINT8 byte;
} C0EISTR_ADDR;
C0EISTR_ADDR	c0eistr_addr;

#define		C0EISTR		c0eistr_addr.byte

#define		BOIS_C0EISTR	c0eistr_addr.bit.bois_c0eistr
#define		EPIS_C0EISTR	c0eistr_addr.bit.epis_c0eistr
#define		BEIS_C0EISTR	c0eistr_addr.bit.beis_c0eistr

/*------------------------------------------------------
    Can0 Baud Rate Prescaler
------------------------------------------------------*/
#pragma ADDRESS		c0brp_addr		0217H	/* Can0 Baud Rate Prescaler */
typedef union {
	struct{
		UINT8	b0:1;
		UINT8	b1:1;
		UINT8	b2:1;
		UINT8	b3:1;
		UINT8	b4:1;
		UINT8	b5:1;
		UINT8	b6:1;
		UINT8	b7:1;
	} bit;
	 UINT8 byte;
} C0BRP_ADDR;
C0BRP_ADDR	c0brp_addr;

#define		C0BRP		c0brp_addr.byte

/*------------------------------------------------------
    Can0 Global Mask Register Standard ID0
------------------------------------------------------*/
#pragma ADDRESS		c0gmr0_addr		0228H	/* Can0 Global Mask Register Standard ID0 */
typedef union {
	struct{
		UINT8	sid6m_c0gmr0:1;
		UINT8	sid7m_c0gmr0:1;
		UINT8	sid8m_c0gmr0:1;
		UINT8	sid9m_c0gmr0:1;
		UINT8	sid10m_c0gmr0:1;
		UINT8	b5:1;
		UINT8	b6:1;
		UINT8	b7:1;
	} bit;
	 UINT8 byte;
} C0GMR0_ADDR;
C0GMR0_ADDR	c0gmr0_addr;

#define		C0GMR0		c0gmr0_addr.byte

#define		SID6M_C0GMR0	c0gmr0_addr.bit.sid6m_c0gmr0
#define		SID7M_C0GMR0	c0gmr0_addr.bit.sid7m_c0gmr0
#define		SID8M_C0GMR0	c0gmr0_addr.bit.sid8m_c0gmr0
#define		SID9M_C0GMR0	c0gmr0_addr.bit.sid9m_c0gmr0
#define		SID10M_C0GMR0	c0gmr0_addr.bit.sid10m_c0gmr0

/*------------------------------------------------------
    Can0 Global Mask Register Standard ID1
------------------------------------------------------*/
#pragma ADDRESS		c0gmr1_addr		0229H	/* Can0 Global Mask Register Standard ID1 */
typedef union {
	struct{
		UINT8	sid0m_c0gmr1:1;
		UINT8	sid1m_c0gmr1:1;
		UINT8	sid2m_c0gmr1:1;
		UINT8	sid3m_c0gmr1:1;
		UINT8	sid4m_c0gmr1:1;
		UINT8	sid5m_c0gmr1:1;
		UINT8	b6:1;
		UINT8	b7:1;
	} bit;
	 UINT8 byte;
} C0GMR1_ADDR;
C0GMR1_ADDR	c0gmr1_addr;

#define		C0GMR1		c0gmr1_addr.byte

#define		SID0M_C0GMR1	c0gmr1_addr.bit.sid0m_c0gmr1
#define		SID1M_C0GMR1	c0gmr1_addr.bit.sid1m_c0gmr1
#define		SID2M_C0GMR1	c0gmr1_addr.bit.sid2m_c0gmr1
#define		SID3M_C0GMR1	c0gmr1_addr.bit.sid3m_c0gmr1
#define		SID4M_C0GMR1	c0gmr1_addr.bit.sid4m_c0gmr1
#define		SID5M_C0GMR1	c0gmr1_addr.bit.sid5m_c0gmr1

/*------------------------------------------------------
    Can0 Global Mask Register Extended ID0
------------------------------------------------------*/
#pragma ADDRESS		c0gmr2_addr		022aH	/* Can0 Global Mask Register Extended ID0 */
typedef union {
	struct{
		UINT8	eid14m_c0gmr2:1;
		UINT8	eid15m_c0gmr2:1;
		UINT8	eid16m_c0gmr2:1;
		UINT8	eid17m_c0gmr2:1;
		UINT8	b4:1;
		UINT8	b5:1;
		UINT8	b6:1;
		UINT8	b7:1;
	} bit;
	 UINT8 byte;
} C0GMR2_ADDR;
C0GMR2_ADDR	c0gmr2_addr;

#define		C0GMR2		c0gmr2_addr.byte

#define		EID14M_C0GMR2	c0gmr2_addr.bit.eid14m_c0gmr2
#define		EID15M_C0GMR2	c0gmr2_addr.bit.eid15m_c0gmr2
#define		EID16M_C0GMR2	c0gmr2_addr.bit.eid16m_c0gmr2
#define		EID17M_C0GMR2	c0gmr2_addr.bit.eid17m_c0gmr2

/*------------------------------------------------------
    Can0 Global Mask Register Extended ID1
------------------------------------------------------*/
#pragma ADDRESS		c0gmr3_addr		022bH	/* Can0 Global Mask Register Extended ID1 */
typedef union {
	struct{
		UINT8	eid6m_c0gmr3:1;
		UINT8	eid7m_c0gmr3:1;
		UINT8	eid8m_c0gmr3:1;
		UINT8	eid9m_c0gmr3:1;
		UINT8	eid10m_c0gmr3:1;
		UINT8	eid11m_c0gmr3:1;
		UINT8	eid12m_c0gmr3:1;
		UINT8	eid13m_c0gmr3:1;
	} bit;
	 UINT8 byte;
} C0GMR3_ADDR;
C0GMR3_ADDR	c0gmr3_addr;

#define		C0GMR3		c0gmr3_addr.byte

#define		EID6M_C0GMR3	c0gmr3_addr.bit.eid6m_c0gmr3
#define		EID7M_C0GMR3	c0gmr3_addr.bit.eid7m_c0gmr3
#define		EID8M_C0GMR3	c0gmr3_addr.bit.eid8m_c0gmr3
#define		EID9M_C0GMR3	c0gmr3_addr.bit.eid9m_c0gmr3
#define		EID10M_C0GMR3	c0gmr3_addr.bit.eid10m_c0gmr3
#define		EID11M_C0GMR3	c0gmr3_addr.bit.eid11m_c0gmr3
#define		EID12M_C0GMR3	c0gmr3_addr.bit.eid12m_c0gmr3
#define		EID13M_C0GMR3	c0gmr3_addr.bit.eid13m_c0gmr3

/*------------------------------------------------------
    Can0 Global Mask Register Extended ID2
------------------------------------------------------*/
#pragma ADDRESS		c0gmr4_addr		022cH	/* Can0 Global Mask Register Extended ID2 */
typedef union {
	struct{
		UINT8	eid0m_c0gmr4:1;
		UINT8	eid1m_c0gmr4:1;
		UINT8	eid2m_c0gmr4:1;
		UINT8	eid3m_c0gmr4:1;
		UINT8	eid4m_c0gmr4:1;
		UINT8	eid5m_c0gmr4:1;
		UINT8	b6:1;
		UINT8	b7:1;
	} bit;
	 UINT8 byte;
} C0GMR4_ADDR;
C0GMR4_ADDR	c0gmr4_addr;

#define		C0GMR4		c0gmr4_addr.byte

#define		EID0M_C0GMR4	c0gmr4_addr.bit.eid0m_c0gmr4
#define		EID1M_C0GMR4	c0gmr4_addr.bit.eid1m_c0gmr4
#define		EID2M_C0GMR4	c0gmr4_addr.bit.eid2m_c0gmr4
#define		EID3M_C0GMR4	c0gmr4_addr.bit.eid3m_c0gmr4
#define		EID4M_C0GMR4	c0gmr4_addr.bit.eid4m_c0gmr4
#define		EID5M_C0GMR4	c0gmr4_addr.bit.eid5m_c0gmr4

/*------------------------------------------------------
    Can0 Messege Slot0 Control Register
------------------------------------------------------*/
#pragma ADDRESS		c0mctl0_addr	0230H	/* Can0 Messege Slot0 Control Register */
typedef union {
	struct{
		UINT8	SentData_c0mctl0:1;
		UINT8	TrmActive_c0mctl0:1;
		UINT8	MsgLost_c0mctl0:1;
		UINT8	RemActive_c0mctl0:1;
		UINT8	RspLock_c0mctl0:1;
		UINT8	Remote_c0mctl0:1;
		UINT8	RecReq_c0mctl0:1;
		UINT8	TrmReq_c0mctl0:1;
	} bit;
	 UINT8 byte;
} C0MCTL0_ADDR;
C0MCTL0_ADDR	c0mctl0_addr;

#define		C0MCTL0		c0mctl0_addr.byte

#define		SENTDATA_C0MCTL0	c0mctl0_addr.bit.SentData_c0mctl0
#define		TRMACTIVE_C0MCTL0	c0mctl0_addr.bit.TrmActive_c0mctl0
#define		MSGLOST_C0MCTL0	c0mctl0_addr.bit.MsgLost_c0mctl0
#define		REMACTIVE_C0MCTL0	c0mctl0_addr.bit.RemActive_c0mctl0
#define		RSPLOCK_C0MCTL0	c0mctl0_addr.bit.RspLock_c0mctl0
#define		REMOTE_C0MCTL0	c0mctl0_addr.bit.Remote_c0mctl0
#define		RECREQ_C0MCTL0	c0mctl0_addr.bit.RecReq_c0mctl0
#define		TRMREQ_C0MCTL0	c0mctl0_addr.bit.TrmReq_c0mctl0

/*------------------------------------------------------
    Can0 Local Mask RegisterA Standard ID0
------------------------------------------------------*/
#pragma ADDRESS		c0lmar0_addr	0230H	/* Can0 Local Mask RegisterA Standard ID0 */
typedef union {
	struct{
		UINT8	sid6m_c0lmar0:1;
		UINT8	sid7m_c0lmar0:1;
		UINT8	sid8m_c0lmar0:1;
		UINT8	sid9m_c0lmar0:1;
		UINT8	sid10m_c0lmar0:1;
		UINT8	b5:1;
		UINT8	b6:1;
		UINT8	b7:1;
	} bit;
	 UINT8 byte;
} C0LMAR0_ADDR;
C0LMAR0_ADDR	c0lmar0_addr;

#define		C0LMAR0		c0lmar0_addr.byte

#define		SID6M_C0LMAR0	c0lmar0_addr.bit.sid6m_c0lmar0
#define		SID7M_C0LMAR0	c0lmar0_addr.bit.sid7m_c0lmar0
#define		SID8M_C0LMAR0	c0lmar0_addr.bit.sid8m_c0lmar0
#define		SID9M_C0LMAR0	c0lmar0_addr.bit.sid9m_c0lmar0
#define		SID10M_C0LMAR0	c0lmar0_addr.bit.sid10m_c0lmar0

/*------------------------------------------------------
    Can0 Messege Slot1 Control Register	
------------------------------------------------------*/
#pragma ADDRESS		c0mctl1_addr	0231H	/* Can0 Messege Slot1 Control Register */
typedef union {
	struct{
		UINT8	SentData_c0mctl1:1;
		UINT8	TrmActive_c0mctl1:1;
		UINT8	MsgLost_c0mctl1:1;
		UINT8	RemActive_c0mctl1:1;
		UINT8	RspLock_c0mctl1:1;
		UINT8	Remote_c0mctl1:1;
		UINT8	RecReq_c0mctl1:1;
		UINT8	TrmReq_c0mctl1:1;
	} bit;
	 UINT8 byte;
} C0MCTL1_ADDR;
C0MCTL1_ADDR	c0mctl1_addr;

#define		C0MCTL1		c0mctl1_addr.byte

#define		SENTDATA_C0MCTL1	c0mctl1_addr.bit.SentData_c0mctl1
#define		TRMACTIVE_C0MCTL1	c0mctl1_addr.bit.TrmActive_c0mctl1
#define		MSGLOST_C0MCTL1	c0mctl1_addr.bit.MsgLost_c0mctl1
#define		REMACTIVE_C0MCTL1	c0mctl1_addr.bit.RemActive_c0mctl1
#define		RSPLOCK_C0MCTL1	c0mctl1_addr.bit.RspLock_c0mctl1
#define		REMOTE_C0MCTL1	c0mctl1_addr.bit.Remote_c0mctl1
#define		RECREQ_C0MCTL1	c0mctl1_addr.bit.RecReq_c0mctl1
#define		TRMREQ_C0MCTL1	c0mctl1_addr.bit.TrmReq_c0mctl1

/*------------------------------------------------------
    Can0 Local Mask RegisterA Standard ID1
------------------------------------------------------*/
#pragma ADDRESS		c0lmar1_addr	0231H	/* Can0 Local Mask RegisterA Standard ID1 */
typedef union {
	struct{
		UINT8	sid0m_c0lmar1:1;
		UINT8	sid1m_c0lmar1:1;
		UINT8	sid2m_c0lmar1:1;
		UINT8	sid3m_c0lmar1:1;
		UINT8	sid4m_c0lmar1:1;
		UINT8	sid5m_c0lmar1:1;
		UINT8	b6:1;
		UINT8	b7:1;
	} bit;
	 UINT8 byte;
} C0LMAR1_ADDR;
C0LMAR1_ADDR	c0lmar1_addr;

#define		C0LMAR1		c0lmar1_addr.byte

#define		SID0M_C0LMAR1	c0lmar1_addr.bit.sid0m_c0lmar1
#define		SID1M_C0LMAR1	c0lmar1_addr.bit.sid1m_c0lmar1
#define		SID2M_C0LMAR1	c0lmar1_addr.bit.sid2m_c0lmar1
#define		SID3M_C0LMAR1	c0lmar1_addr.bit.sid3m_c0lmar1
#define		SID4M_C0LMAR1	c0lmar1_addr.bit.sid4m_c0lmar1
#define		SID5M_C0LMAR1	c0lmar1_addr.bit.sid5m_c0lmar1

/*------------------------------------------------------
    Can0 Messege Slot2 Control Register
------------------------------------------------------*/
#pragma ADDRESS		c0mctl2_addr	0232H	/* Can0 Messege Slot2 Control Register */
typedef union {
	struct{
		UINT8	SentData_c0mctl2:1;
		UINT8	TrmActive_c0mctl2:1;
		UINT8	MsgLost_c0mctl2:1;
		UINT8	RemActive_c0mctl2:1;
		UINT8	RspLock_c0mctl2:1;
		UINT8	Remote_c0mctl2:1;
		UINT8	RecReq_c0mctl2:1;
		UINT8	TrmReq_c0mctl2:1;
	} bit;
	 UINT8 byte;
} C0MCTL2_ADDR;
C0MCTL2_ADDR	c0mctl2_addr;

#define		C0MCTL2		c0mctl2_addr.byte

#define		SENTDATA_C0MCTL2	c0mctl2_addr.bit.SentData_c0mctl2
#define		TRMACTIVE_C0MCTL2	c0mctl2_addr.bit.TrmActive_c0mctl2
#define		MSGLOST_C0MCTL2	c0mctl2_addr.bit.MsgLost_c0mctl2
#define		REMACTIVE_C0MCTL2	c0mctl2_addr.bit.RemActive_c0mctl2
#define		RSPLOCK_C0MCTL2	c0mctl2_addr.bit.RspLock_c0mctl2
#define		REMOTE_C0MCTL2	c0mctl2_addr.bit.Remote_c0mctl2
#define		RECREQ_C0MCTL2	c0mctl2_addr.bit.RecReq_c0mctl2
#define		TRMREQ_C0MCTL2	c0mctl2_addr.bit.TrmReq_c0mctl2

/*------------------------------------------------------
    Can0 Local Mask RegisterA Extended ID0
------------------------------------------------------*/
#pragma ADDRESS		c0lmar2_addr	0232H	/* Can0 Local Mask RegisterA Extended ID0 */
typedef union {
	struct{
		UINT8	eid14m_c0lmar2:1;
		UINT8	eid15m_c0lmar2:1;
		UINT8	eid16m_c0lmar2:1;
		UINT8	eid17m_c0lmar2:1;
		UINT8	b4:1;
		UINT8	b5:1;
		UINT8	b6:1;
		UINT8	b7:1;
	} bit;
	 UINT8 byte;
} C0LMAR2_ADDR;
C0LMAR2_ADDR	c0lmar2_addr;

#define		C0LMAR2		c0lmar2_addr.byte

#define		EID14M_C0LMAR2	c0lmar2_addr.bit.eid14m_c0lmar2
#define		EID15M_C0LMAR2	c0lmar2_addr.bit.eid15m_c0lmar2
#define		EID16M_C0LMAR2	c0lmar2_addr.bit.eid16m_c0lmar2
#define		EID17M_C0LMAR2	c0lmar2_addr.bit.eid17m_c0lmar2

/*------------------------------------------------------
    Can0 Messege Slot3 Control Register
------------------------------------------------------*/
#pragma ADDRESS		c0mctl3_addr	0233H	/* Can0 Messege Slot3 Control Register	*/
typedef union {
	struct{
		UINT8	SentData_c0mctl3:1;
		UINT8	TrmActive_c0mctl3:1;
		UINT8	MsgLost_c0mctl3:1;
		UINT8	RemActive_c0mctl3:1;
		UINT8	RspLock_c0mctl3:1;
		UINT8	Remote_c0mctl3:1;
		UINT8	RecReq_c0mctl3:1;
		UINT8	TrmReq_c0mctl3:1;
	} bit;
	 UINT8 byte;
} C0MCTL3_ADDR;
C0MCTL3_ADDR	c0mctl3_addr;

#define		C0MCTL3		c0mctl3_addr.byte

#define		SENTDATA_C0MCTL3	c0mctl3_addr.bit.SentData_c0mctl3
#define		TRMACTIVE_C0MCTL3	c0mctl3_addr.bit.TrmActive_c0mctl3
#define		MSGLOST_C0MCTL3	c0mctl3_addr.bit.MsgLost_c0mctl3
#define		REMACTIVE_C0MCTL3	c0mctl3_addr.bit.RemActive_c0mctl3
#define		RSPLOCK_C0MCTL3	c0mctl3_addr.bit.RspLock_c0mctl3
#define		REMOTE_C0MCTL3	c0mctl3_addr.bit.Remote_c0mctl3
#define		RECREQ_C0MCTL3	c0mctl3_addr.bit.RecReq_c0mctl3
#define		TRMREQ_C0MCTL3	c0mctl3_addr.bit.TrmReq_c0mctl3

/*------------------------------------------------------
    Can0 Local Mask RegisterA Extended ID1
------------------------------------------------------*/
#pragma ADDRESS		c0lmar3_addr	0233H	/* Can0 Local Mask RegisterA Extended ID1 */
typedef union {
	struct{
		UINT8	eid6m_c0lmar3:1;
		UINT8	eid7m_c0lmar3:1;
		UINT8	eid8m_c0lmar3:1;
		UINT8	eid9m_c0lmar3:1;
		UINT8	eid10m_c0lmar3:1;
		UINT8	eid11m_c0lmar3:1;
		UINT8	eid12m_c0lmar3:1;
		UINT8	eid13m_c0lmar3:1;
	} bit;
	 UINT8 byte;
} C0LMAR3_ADDR;
C0LMAR3_ADDR	c0lmar3_addr;

#define		C0LMAR3		c0lmar3_addr.byte

#define		EID6M_C0LMAR3	c0lmar3_addr.bit.eid6m_c0lmar3
#define		EID7M_C0LMAR3	c0lmar3_addr.bit.eid7m_c0lmar3
#define		EID8M_C0LMAR3	c0lmar3_addr.bit.eid8m_c0lmar3
#define		EID9M_C0LMAR3	c0lmar3_addr.bit.eid9m_c0lmar3
#define		EID10M_C0LMAR3	c0lmar3_addr.bit.eid10m_c0lmar3
#define		EID11M_C0LMAR3	c0lmar3_addr.bit.eid11m_c0lmar3
#define		EID12M_C0LMAR3	c0lmar3_addr.bit.eid12m_c0lmar3
#define		EID13M_C0LMAR3	c0lmar3_addr.bit.eid13m_c0lmar3

/*------------------------------------------------------
    Can0 Messege Slot4 Control Register
------------------------------------------------------*/
#pragma ADDRESS		c0mctl4_addr	0234H	/* Can0 Messege Slot4 Control Register	*/
typedef union {
	struct{
		UINT8	SentData_c0mctl4:1;
		UINT8	TrmActive_c0mctl4:1;
		UINT8	MsgLost_c0mctl4:1;
		UINT8	RemActive_c0mctl4:1;
		UINT8	RspLock_c0mctl4:1;
		UINT8	Remote_c0mctl4:1;
		UINT8	RecReq_c0mctl4:1;
		UINT8	TrmReq_c0mctl4:1;
	} bit;
	 UINT8 byte;
} C0MCTL4_ADDR;
C0MCTL4_ADDR	c0mctl4_addr;

#define		C0MCTL4		c0mctl4_addr.byte

#define		SENTDATA_C0MCTL4	c0mctl4_addr.bit.SentData_c0mctl4
#define		TRMACTIVE_C0MCTL4	c0mctl4_addr.bit.TrmActive_c0mctl4
#define		MSGLOST_C0MCTL4	c0mctl4_addr.bit.MsgLost_c0mctl4
#define		REMACTIVE_C0MCTL4	c0mctl4_addr.bit.RemActive_c0mctl4
#define		RSPLOCK_C0MCTL4	c0mctl4_addr.bit.RspLock_c0mctl4
#define		REMOTE_C0MCTL4	c0mctl4_addr.bit.Remote_c0mctl4
#define		RECREQ_C0MCTL4	c0mctl4_addr.bit.RecReq_c0mctl4
#define		TRMREQ_C0MCTL4	c0mctl4_addr.bit.TrmReq_c0mctl4

/*------------------------------------------------------
    Can0 Local Mask RegisterA Extended ID2
------------------------------------------------------*/
#pragma ADDRESS		c0lmar4_addr	0234H	/* Can0 Local Mask RegisterA Extended ID2 */
typedef union {
	struct{
		UINT8	eid0m_c0lmar4:1;
		UINT8	eid1m_c0lmar4:1;
		UINT8	eid2m_c0lmar4:1;
		UINT8	eid3m_c0lmar4:1;
		UINT8	eid4m_c0lmar4:1;
		UINT8	eid5m_c0lmar4:1;
		UINT8	b6:1;
		UINT8	b7:1;
	} bit;
	 UINT8 byte;
} C0LMAR4_ADDR;
C0LMAR4_ADDR	c0lmar4_addr;

#define		C0LMAR4		c0lmar4_addr.byte

#define		EID0M_C0LMAR4	c0lmar4_addr.bit.eid0m_c0lmar4
#define		EID1M_C0LMAR4	c0lmar4_addr.bit.eid1m_c0lmar4
#define		EID2M_C0LMAR4	c0lmar4_addr.bit.eid2m_c0lmar4
#define		EID3M_C0LMAR4	c0lmar4_addr.bit.eid3m_c0lmar4
#define		EID4M_C0LMAR4	c0lmar4_addr.bit.eid4m_c0lmar4
#define		EID5M_C0LMAR4	c0lmar4_addr.bit.eid5m_c0lmar4

/*------------------------------------------------------
    Can0 Messege Slot5 Control Register
------------------------------------------------------*/
#pragma ADDRESS		c0mctl5_addr	0235H	/* Can0 Messege Slot5 Control Register	*/
typedef union {
	struct{
		UINT8	SentData_c0mctl5:1;
		UINT8	TrmActive_c0mctl5:1;
		UINT8	MsgLost_c0mctl5:1;
		UINT8	RemActive_c0mctl5:1;
		UINT8	RspLock_c0mctl5:1;
		UINT8	Remote_c0mctl5:1;
		UINT8	RecReq_c0mctl5:1;
		UINT8	TrmReq_c0mctl5:1;
	} bit;
	 UINT8 byte;
} C0MCTL5_ADDR;
C0MCTL5_ADDR	c0mctl5_addr;

#define		C0MCTL5		c0mctl5_addr.byte

#define		SENTDATA_C0MCTL5	c0mctl5_addr.bit.SentData_c0mctl5
#define		TRMACTIVE_C0MCTL5	c0mctl5_addr.bit.TrmActive_c0mctl5
#define		MSGLOST_C0MCTL5	c0mctl5_addr.bit.MsgLost_c0mctl5
#define		REMACTIVE_C0MCTL5	c0mctl5_addr.bit.RemActive_c0mctl5
#define		RSPLOCK_C0MCTL5	c0mctl5_addr.bit.RspLock_c0mctl5
#define		REMOTE_C0MCTL5	c0mctl5_addr.bit.Remote_c0mctl5
#define		RECREQ_C0MCTL5	c0mctl5_addr.bit.RecReq_c0mctl5
#define		TRMREQ_C0MCTL5	c0mctl5_addr.bit.TrmReq_c0mctl5

/*------------------------------------------------------
    Can0 Messege Slot6 Control Register
------------------------------------------------------*/
#pragma ADDRESS		c0mctl6_addr	0236H	/* Can0 Messege Slot6 Control Register	*/
typedef union {
	struct{
		UINT8	SentData_c0mctl6:1;
		UINT8	TrmActive_c0mctl6:1;
		UINT8	MsgLost_c0mctl6:1;
		UINT8	RemActive_c0mctl6:1;
		UINT8	RspLock_c0mctl6:1;
		UINT8	Remote_c0mctl6:1;
		UINT8	RecReq_c0mctl6:1;
		UINT8	TrmReq_c0mctl6:1;
	} bit;
	 UINT8 byte;
} C0MCTL6_ADDR;
C0MCTL6_ADDR	c0mctl6_addr;

#define		C0MCTL6		c0mctl6_addr.byte

#define		SENTDATA_C0MCTL6	c0mctl6_addr.bit.SentData_c0mctl6
#define		TRMACTIVE_C0MCTL6	c0mctl6_addr.bit.TrmActive_c0mctl6
#define		MSGLOST_C0MCTL6	c0mctl6_addr.bit.MsgLost_c0mctl6
#define		REMACTIVE_C0MCTL6	c0mctl6_addr.bit.RemActive_c0mctl6
#define		RSPLOCK_C0MCTL6	c0mctl6_addr.bit.RspLock_c0mctl6
#define		REMOTE_C0MCTL6	c0mctl6_addr.bit.Remote_c0mctl6
#define		RECREQ_C0MCTL6	c0mctl6_addr.bit.RecReq_c0mctl6
#define		TRMREQ_C0MCTL6	c0mctl6_addr.bit.TrmReq_c0mctl6

/*------------------------------------------------------
    Can0 Messege Slot7 Control Register
------------------------------------------------------*/
#pragma ADDRESS		c0mctl7_addr	0237H	/* Can0 Messege Slot7 Control Register	*/
typedef union {
	struct{
		UINT8	SentData_c0mctl7:1;
		UINT8	TrmActive_c0mctl7:1;
		UINT8	MsgLost_c0mctl7:1;
		UINT8	RemActive_c0mctl7:1;
		UINT8	RspLock_c0mctl7:1;
		UINT8	Remote_c0mctl7:1;
		UINT8	RecReq_c0mctl7:1;
		UINT8	TrmReq_c0mctl7:1;
	} bit;
	 UINT8 byte;
} C0MCTL7_ADDR;
C0MCTL7_ADDR	c0mctl7_addr;

#define		C0MCTL7		c0mctl7_addr.byte

#define		SENTDATA_C0MCTL7	c0mctl7_addr.bit.SentData_c0mctl7
#define		TRMACTIVE_C0MCTL7	c0mctl7_addr.bit.TrmActive_c0mctl7
#define		MSGLOST_C0MCTL7	c0mctl7_addr.bit.MsgLost_c0mctl7
#define		REMACTIVE_C0MCTL7	c0mctl7_addr.bit.RemActive_c0mctl7
#define		RSPLOCK_C0MCTL7	c0mctl7_addr.bit.RspLock_c0mctl7
#define		REMOTE_C0MCTL7	c0mctl7_addr.bit.Remote_c0mctl7
#define		RECREQ_C0MCTL7	c0mctl7_addr.bit.RecReq_c0mctl7
#define		TRMREQ_C0MCTL7	c0mctl7_addr.bit.TrmReq_c0mctl7

/*------------------------------------------------------
    Can0 Messege Slot8 Control Register
------------------------------------------------------*/
#pragma ADDRESS		c0mctl8_addr	0238H	/* Can0 Messege Slot8 Control Register	*/
typedef union {
	struct{
		UINT8	SentData_c0mctl8:1;
		UINT8	TrmActive_c0mctl8:1;
		UINT8	MsgLost_c0mctl8:1;
		UINT8	RemActive_c0mctl8:1;
		UINT8	RspLock_c0mctl8:1;
		UINT8	Remote_c0mctl8:1;
		UINT8	RecReq_c0mctl8:1;
		UINT8	TrmReq_c0mctl8:1;
	} bit;
	 UINT8 byte;
} C0MCTL8_ADDR;
C0MCTL8_ADDR	c0mctl8_addr;

#define		C0MCTL8		c0mctl8_addr.byte

#define		SENTDATA_C0MCTL8	c0mctl8_addr.bit.SentData_c0mctl8
#define		TRMACTIVE_C0MCTL8	c0mctl8_addr.bit.TrmActive_c0mctl8
#define		MSGLOST_C0MCTL8	c0mctl8_addr.bit.MsgLost_c0mctl8
#define		REMACTIVE_C0MCTL8	c0mctl8_addr.bit.RemActive_c0mctl8
#define		RSPLOCK_C0MCTL8	c0mctl8_addr.bit.RspLock_c0mctl8
#define		REMOTE_C0MCTL8	c0mctl8_addr.bit.Remote_c0mctl8
#define		RECREQ_C0MCTL8	c0mctl8_addr.bit.RecReq_c0mctl8
#define		TRMREQ_C0MCTL8	c0mctl8_addr.bit.TrmReq_c0mctl8

/*------------------------------------------------------
    Can0 Local Mask RegisterB Standard ID0
------------------------------------------------------*/
#pragma ADDRESS		c0lmbr0_addr	0238H	/* Can0 Local Mask RegisterB Standard ID0 */
typedef union {
	struct{
		UINT8	sid6m_c0lmbr0:1;
		UINT8	sid7m_c0lmbr0:1;
		UINT8	sid8m_c0lmbr0:1;
		UINT8	sid9m_c0lmbr0:1;
		UINT8	sid10m_c0lmbr0:1;
		UINT8	b5:1;
		UINT8	b6:1;
		UINT8	b7:1;
	} bit;
	 UINT8 byte;
} C0LMBR0_ADDR;
C0LMBR0_ADDR	c0lmbr0_addr;

#define		C0LMBR0		c0lmbr0_addr.byte

#define		SID6M_C0LMBR0	c0lmbr0_addr.bit.sid6m_c0lmbr0
#define		SID7M_C0LMBR0	c0lmbr0_addr.bit.sid7m_c0lmbr0
#define		SID8M_C0LMBR0	c0lmbr0_addr.bit.sid8m_c0lmbr0
#define		SID9M_C0LMBR0	c0lmbr0_addr.bit.sid9m_c0lmbr0
#define		SID10M_C0LMBR0	c0lmbr0_addr.bit.sid10m_c0lmbr0

/*------------------------------------------------------
    Can0 Messege Slot9 Control Register
------------------------------------------------------*/
#pragma ADDRESS		c0mctl9_addr	0239H	/* Can0 Messege Slot9 Control Register	*/
typedef union {
	struct{
		UINT8	SentData_c0mctl9:1;
		UINT8	TrmActive_c0mctl9:1;
		UINT8	MsgLost_c0mctl9:1;
		UINT8	RemActive_c0mctl9:1;
		UINT8	RspLock_c0mctl9:1;
		UINT8	Remote_c0mctl9:1;
		UINT8	RecReq_c0mctl9:1;
		UINT8	TrmReq_c0mctl9:1;
	} bit;
	 UINT8 byte;
} C0MCTL9_ADDR;
C0MCTL9_ADDR	c0mctl9_addr;

#define		C0MCTL9		c0mctl9_addr.byte

#define		SENTDATA_C0MCTL9	c0mctl9_addr.bit.SentData_c0mctl9
#define		TRMACTIVE_C0MCTL9	c0mctl9_addr.bit.TrmActive_c0mctl9
#define		MSGLOST_C0MCTL9	c0mctl9_addr.bit.MsgLost_c0mctl9
#define		REMACTIVE_C0MCTL9	c0mctl9_addr.bit.RemActive_c0mctl9
#define		RSPLOCK_C0MCTL9	c0mctl9_addr.bit.RspLock_c0mctl9
#define		REMOTE_C0MCTL9	c0mctl9_addr.bit.Remote_c0mctl9
#define		RECREQ_C0MCTL9	c0mctl9_addr.bit.RecReq_c0mctl9
#define		TRMREQ_C0MCTL9	c0mctl9_addr.bit.TrmReq_c0mctl9

/*------------------------------------------------------
    Can0 Local Mask RegisterB Standard ID1
------------------------------------------------------*/
#pragma ADDRESS		c0lmbr1_addr	0239H	/* Can0 Local Mask RegisterB Standard ID1 */
typedef union {
	struct{
		UINT8	sid0m_c0lmbr1:1;
		UINT8	sid1m_c0lmbr1:1;
		UINT8	sid2m_c0lmbr1:1;
		UINT8	sid3m_c0lmbr1:1;
		UINT8	sid4m_c0lmbr1:1;
		UINT8	sid5m_c0lmbr1:1;
		UINT8	b6:1;
		UINT8	b7:1;
	} bit;
	 UINT8 byte;
} C0LMBR1_ADDR;
C0LMBR1_ADDR	c0lmbr1_addr;

#define		C0LMBR1		c0lmbr1_addr.byte

#define		SID0M_C0LMBR1	c0lmbr1_addr.bit.sid0m_c0lmbr1
#define		SID1M_C0LMBR1	c0lmbr1_addr.bit.sid1m_c0lmbr1
#define		SID2M_C0LMBR1	c0lmbr1_addr.bit.sid2m_c0lmbr1
#define		SID3M_C0LMBR1	c0lmbr1_addr.bit.sid3m_c0lmbr1
#define		SID4M_C0LMBR1	c0lmbr1_addr.bit.sid4m_c0lmbr1
#define		SID5M_C0LMBR1	c0lmbr1_addr.bit.sid5m_c0lmbr1

/*------------------------------------------------------
    Can0 Messege Slot10 Control Register
------------------------------------------------------*/
#pragma ADDRESS		c0mctl10_addr	023aH	/* Can0 Messege Slot10 Control Register */
typedef union {
	struct{
		UINT8	SentData_c0mctl10:1;
		UINT8	TrmActive_c0mctl10:1;
		UINT8	MsgLost_c0mctl10:1;
		UINT8	RemActive_c0mctl10:1;
		UINT8	RspLock_c0mctl10:1;
		UINT8	Remote_c0mctl10:1;
		UINT8	RecReq_c0mctl10:1;
		UINT8	TrmReq_c0mctl10:1;
	} bit;
	 UINT8 byte;
} C0MCTL10_ADDR;
C0MCTL10_ADDR	c0mctl10_addr;

#define		C0MCTL10	c0mctl10_addr.byte

#define		SENTDATA_C0MCTL10	c0mctl10_addr.bit.SentData_c0mctl10
#define		TRMACTIVE_C0MCTL10	c0mctl10_addr.bit.TrmActive_c0mctl10
#define		MSGLOST_C0MCTL10	c0mctl10_addr.bit.MsgLost_c0mctl10
#define		REMACTIVE_C0MCTL10	c0mctl10_addr.bit.RemActive_c0mctl10
#define		RSPLOCK_C0MCTL10	c0mctl10_addr.bit.RspLock_c0mctl10
#define		REMOTE_C0MCTL10	c0mctl10_addr.bit.Remote_c0mctl10
#define		RECREQ_C0MCTL10	c0mctl10_addr.bit.RecReq_c0mctl10
#define		TRMREQ_C0MCTL10	c0mctl10_addr.bit.TrmReq_c0mctl10

/*------------------------------------------------------
    Can0 Local Mask RegisterB Standard ID2
------------------------------------------------------*/
#pragma ADDRESS		c0lmbr2_addr	023aH	/* Can0 Local Mask RegisterB Extended ID2 */
typedef union {
	struct{
		UINT8	eid14m_c0lmbr2:1;
		UINT8	eid15m_c0lmbr2:1;
		UINT8	eid16m_c0lmbr2:1;
		UINT8	eid17m_c0lmbr2:1;
		UINT8	b4:1;
		UINT8	b5:1;
		UINT8	b6:1;
		UINT8	b7:1;
	} bit;
	 UINT8 byte;
} C0LMBR2_ADDR;
C0LMBR2_ADDR	c0lmbr2_addr;

#define		C0LMBR2		c0lmbr2_addr.byte

#define		EID14M_C0LMBR2	c0lmbr2_addr.bit.eid14m_c0lmbr2
#define		EID15M_C0LMBR2	c0lmbr2_addr.bit.eid15m_c0lmbr2
#define		EID16M_C0LMBR2	c0lmbr2_addr.bit.eid16m_c0lmbr2
#define		EID17M_C0LMBR2	c0lmbr2_addr.bit.eid17m_c0lmbr2

/*------------------------------------------------------
    Can0 Messege Slot11 Control Register
------------------------------------------------------*/
#pragma ADDRESS		c0mctl11_addr	023bH	/* Can0 Messege Slot11 Control Register */
typedef union {
	struct{
		UINT8	SentData_c0mctl11:1;
		UINT8	TrmActive_c0mctl11:1;
		UINT8	MsgLost_c0mctl11:1;
		UINT8	RemActive_c0mctl11:1;
		UINT8	RspLock_c0mctl11:1;
		UINT8	Remote_c0mctl11:1;
		UINT8	RecReq_c0mctl11:1;
		UINT8	TrmReq_c0mctl11:1;
	} bit;
	 UINT8 byte;
} C0MCTL11_ADDR;
C0MCTL11_ADDR	c0mctl11_addr;

#define		C0MCTL11	c0mctl11_addr.byte

#define		SENTDATA_C0MCTL11	c0mctl11_addr.bit.SentData_c0mctl11
#define		TRMACTIVE_C0MCTL11	c0mctl11_addr.bit.TrmActive_c0mctl11
#define		MSGLOST_C0MCTL11	c0mctl11_addr.bit.MsgLost_c0mctl11
#define		REMACTIVE_C0MCTL11	c0mctl11_addr.bit.RemActive_c0mctl11
#define		RSPLOCK_C0MCTL11	c0mctl11_addr.bit.RspLock_c0mctl11
#define		REMOTE_C0MCTL11	c0mctl11_addr.bit.Remote_c0mctl11
#define		RECREQ_C0MCTL11	c0mctl11_addr.bit.RecReq_c0mctl11
#define		TRMREQ_C0MCTL11	c0mctl11_addr.bit.TrmReq_c0mctl11

/*------------------------------------------------------
    Can0 Local Mask RegisterB Standard ID3
------------------------------------------------------*/
#pragma ADDRESS		c0lmbr3_addr	023bH	/* Can0 Local Mask RegisterB Extended ID3 */
typedef union {
	struct{
		UINT8	eid6m_c0lmbr3:1;
		UINT8	eid7m_c0lmbr3:1;
		UINT8	eid8m_c0lmbr3:1;
		UINT8	eid9m_c0lmbr3:1;
		UINT8	eid10m_c0lmbr3:1;
		UINT8	eid11m_c0lmbr3:1;
		UINT8	eid12m_c0lmbr3:1;
		UINT8	eid13m_c0lmbr3:1;
	} bit;
	 UINT8 byte;
} C0LMBR3_ADDR;
C0LMBR3_ADDR	c0lmbr3_addr;

#define		C0LMBR3		c0lmbr3_addr.byte

#define		EID6M_C0LMBR3	c0lmbr3_addr.bit.eid6m_c0lmbr3
#define		EID7M_C0LMBR3	c0lmbr3_addr.bit.eid7m_c0lmbr3
#define		EID8M_C0LMBR3	c0lmbr3_addr.bit.eid8m_c0lmbr3
#define		EID9M_C0LMBR3	c0lmbr3_addr.bit.eid9m_c0lmbr3
#define		EID10M_C0LMBR3	c0lmbr3_addr.bit.eid10m_c0lmbr3
#define		EID11M_C0LMBR3	c0lmbr3_addr.bit.eid11m_c0lmbr3
#define		EID12M_C0LMBR3	c0lmbr3_addr.bit.eid12m_c0lmbr3
#define		EID13M_C0LMBR3	c0lmbr3_addr.bit.eid13m_c0lmbr3

/*------------------------------------------------------
    Can0 Messege Slot12 Control Register
------------------------------------------------------*/
#pragma ADDRESS		c0mctl12_addr	023cH	/* Can0 Messege Slot12 Control Register */
typedef union {
	struct{
		UINT8	SentData_c0mctl12:1;
		UINT8	TrmActive_c0mctl12:1;
		UINT8	MsgLost_c0mctl12:1;
		UINT8	RemActive_c0mctl12:1;
		UINT8	RspLock_c0mctl12:1;
		UINT8	Remote_c0mctl12:1;
		UINT8	RecReq_c0mctl12:1;
		UINT8	TrmReq_c0mctl12:1;
	} bit;
	 UINT8 byte;
} C0MCTL12_ADDR;
C0MCTL12_ADDR	c0mctl12_addr;

#define		C0MCTL12	c0mctl12_addr.byte

#define		SENTDATA_C0MCTL12	c0mctl12_addr.bit.SentData_c0mctl12
#define		TRMACTIVE_C0MCTL12	c0mctl12_addr.bit.TrmActive_c0mctl12
#define		MSGLOST_C0MCTL12	c0mctl12_addr.bit.MsgLost_c0mctl12
#define		REMACTIVE_C0MCTL12	c0mctl12_addr.bit.RemActive_c0mctl12
#define		RSPLOCK_C0MCTL12	c0mctl12_addr.bit.RspLock_c0mctl12
#define		REMOTE_C0MCTL12	c0mctl12_addr.bit.Remote_c0mctl12
#define		RECREQ_C0MCTL12	c0mctl12_addr.bit.RecReq_c0mctl12
#define		TRMREQ_C0MCTL12	c0mctl12_addr.bit.TrmReq_c0mctl12

/*------------------------------------------------------
    Can0 Local Mask RegisterB Standard ID4
------------------------------------------------------*/
#pragma ADDRESS		c0lmbr4_addr	023cH	/* Can0 Local Mask RegisterB Extended ID4 */
typedef union {
	struct{
		UINT8	eid0m_c0lmbr4:1;
		UINT8	eid1m_c0lmbr4:1;
		UINT8	eid2m_c0lmbr4:1;
		UINT8	eid3m_c0lmbr4:1;
		UINT8	eid4m_c0lmbr4:1;
		UINT8	eid5m_c0lmbr4:1;
		UINT8	b6:1;
		UINT8	b7:1;
	} bit;
	 UINT8 byte;
} C0LMBR4_ADDR;
C0LMBR4_ADDR	c0lmbr4_addr;

#define		C0LMBR4		c0lmbr4_addr.byte

#define		EID0M_C0LMBR4	c0lmbr4_addr.bit.eid0m_c0lmbr4
#define		EID1M_C0LMBR4	c0lmbr4_addr.bit.eid1m_c0lmbr4
#define		EID2M_C0LMBR4	c0lmbr4_addr.bit.eid2m_c0lmbr4
#define		EID3M_C0LMBR4	c0lmbr4_addr.bit.eid3m_c0lmbr4
#define		EID4M_C0LMBR4	c0lmbr4_addr.bit.eid4m_c0lmbr4
#define		EID5M_C0LMBR4	c0lmbr4_addr.bit.eid5m_c0lmbr4

/*------------------------------------------------------
    Can0 Messege Slot13 Control Register
------------------------------------------------------*/
#pragma ADDRESS		c0mctl13_addr	023dH	/* Can0 Messege Slot13 Control Register */
typedef union {
	struct{
		UINT8	SentData_c0mctl13:1;
		UINT8	TrmActive_c0mctl13:1;
		UINT8	MsgLost_c0mctl13:1;
		UINT8	RemActive_c0mctl13:1;
		UINT8	RspLock_c0mctl13:1;
		UINT8	Remote_c0mctl13:1;
		UINT8	RecReq_c0mctl13:1;
		UINT8	TrmReq_c0mctl13:1;
	} bit;
	 UINT8 byte;
} C0MCTL13_ADDR;
C0MCTL13_ADDR	c0mctl13_addr;

#define		C0MCTL13	c0mctl13_addr.byte

#define		SENTDATA_C0MCTL13	c0mctl13_addr.bit.SentData_c0mctl13
#define		TRMACTIVE_C0MCTL13	c0mctl13_addr.bit.TrmActive_c0mctl13
#define		MSGLOST_C0MCTL13	c0mctl13_addr.bit.MsgLost_c0mctl13
#define		REMACTIVE_C0MCTL13	c0mctl13_addr.bit.RemActive_c0mctl13
#define		RSPLOCK_C0MCTL13	c0mctl13_addr.bit.RspLock_c0mctl13
#define		REMOTE_C0MCTL13	c0mctl13_addr.bit.Remote_c0mctl13
#define		RECREQ_C0MCTL13	c0mctl13_addr.bit.RecReq_c0mctl13
#define		TRMREQ_C0MCTL13	c0mctl13_addr.bit.TrmReq_c0mctl13

/*------------------------------------------------------
    Can0 Messege Slot14 Control Register
------------------------------------------------------*/
#pragma ADDRESS		c0mctl14_addr	023eH	/* Can0 Messege Slot14 Control Register */
typedef union {
	struct{
		UINT8	SentData_c0mctl14:1;
		UINT8	TrmActive_c0mctl14:1;
		UINT8	MsgLost_c0mctl14:1;
		UINT8	RemActive_c0mctl14:1;
		UINT8	RspLock_c0mctl14:1;
		UINT8	Remote_c0mctl14:1;
		UINT8	RecReq_c0mctl14:1;
		UINT8	TrmReq_c0mctl14:1;
	} bit;
	 UINT8 byte;
} C0MCTL14_ADDR;
C0MCTL14_ADDR	c0mctl14_addr;

#define		C0MCTL14	c0mctl14_addr.byte

#define		SENTDATA_C0MCTL14	c0mctl14_addr.bit.SentData_c0mctl14
#define		TRMACTIVE_C0MCTL14	c0mctl14_addr.bit.TrmActive_c0mctl14
#define		MSGLOST_C0MCTL14	c0mctl14_addr.bit.MsgLost_c0mctl14
#define		REMACTIVE_C0MCTL14	c0mctl14_addr.bit.RemActive_c0mctl14
#define		RSPLOCK_C0MCTL14	c0mctl14_addr.bit.RspLock_c0mctl14
#define		REMOTE_C0MCTL14	c0mctl14_addr.bit.Remote_c0mctl14
#define		RECREQ_C0MCTL14	c0mctl14_addr.bit.RecReq_c0mctl14
#define		TRMREQ_C0MCTL14	c0mctl14_addr.bit.TrmReq_c0mctl14

/*------------------------------------------------------
    Can0 Messege Slot15 Control Register
------------------------------------------------------*/
#pragma ADDRESS		c0mctl15_addr	023fH	/* Can0 Messege Slot15 Control Register */
typedef union {
	struct{
		UINT8	SentData_c0mctl15:1;
		UINT8	TrmActive_c0mctl15:1;
		UINT8	MsgLost_c0mctl15:1;
		UINT8	RemActive_c0mctl15:1;
		UINT8	RspLock_c0mctl15:1;
		UINT8	Remote_c0mctl15:1;
		UINT8	RecReq_c0mctl15:1;
		UINT8	TrmReq_c0mctl15:1;
	} bit;
	 UINT8 byte;
} C0MCTL15_ADDR;
C0MCTL15_ADDR	c0mctl15_addr;

#define		C0MCTL15	c0mctl15_addr.byte

#define		SENTDATA_C0MCTL15	c0mctl15_addr.bit.SentData_c0mctl15
#define		TRMACTIVE_C0MCTL15	c0mctl15_addr.bit.TrmActive_c0mctl15
#define		MSGLOST_C0MCTL15	c0mctl15_addr.bit.MsgLost_c0mctl15
#define		REMACTIVE_C0MCTL15	c0mctl15_addr.bit.RemActive_c0mctl15
#define		RSPLOCK_C0MCTL15	c0mctl15_addr.bit.RspLock_c0mctl15
#define		REMOTE_C0MCTL15	c0mctl15_addr.bit.Remote_c0mctl15
#define		RECREQ_C0MCTL15	c0mctl15_addr.bit.RecReq_c0mctl15
#define		TRMREQ_C0MCTL15	c0mctl15_addr.bit.TrmReq_c0mctl15

/*------------------------------------------------------
    Can0 Slot Buffer Select Register
------------------------------------------------------*/
#pragma ADDRESS		c0sbs_addr		0240H	/* Can0 Slot Buffer Select Register */
typedef union {
	struct{
		UINT8	sbs00_c0sbs:1;
		UINT8	sbs01_c0sbs:1;
		UINT8	sbs02_c0sbs:1;
		UINT8	sbs03_c0sbs:1;
		UINT8	sbs10_c0sbs:1;
		UINT8	sbs11_c0sbs:1;
		UINT8	sbs12_c0sbs:1;
		UINT8	sbs13_c0sbs:1;
	} bit;
	 UINT8 byte;
} C0SBS_ADDR;
C0SBS_ADDR	c0sbs_addr;

#define		C0SBS		c0sbs_addr.byte

#define		SBS00_C0SBS	c0sbs_addr.bit.sbs00_c0sbs
#define		SBS01_C0SBS	c0sbs_addr.bit.sbs01_c0sbs
#define		SBS02_C0SBS	c0sbs_addr.bit.sbs02_c0sbs
#define		SBS03_C0SBS	c0sbs_addr.bit.sbs03_c0sbs
#define		SBS10_C0SBS	c0sbs_addr.bit.sbs10_c0sbs
#define		SBS11_C0SBS	c0sbs_addr.bit.sbs11_c0sbs
#define		SBS12_C0SBS	c0sbs_addr.bit.sbs12_c0sbs
#define		SBS13_C0SBS	c0sbs_addr.bit.sbs13_c0sbs

/*------------------------------------------------------
   Can0 Control Register 1	
------------------------------------------------------*/
#pragma ADDRESS		c0ctlr1_addr		0241H	/* Can0 Control Register 1	*/
typedef union {
	struct{
		UINT8	b0:1;
		UINT8	b1:1;
		UINT8	b2:1;
		UINT8	banksel_c0ctlr1:1;
		UINT8	b4:1;
		UINT8	b5:1;
		UINT8	b6:1;
		UINT8	b7:1;
	} bit;
	 UINT8 byte;
} C0CTLR1_ADDR;
C0CTLR1_ADDR	c0ctlr1_addr;

#define		C0CTLR1		c0ctlr1_addr.byte

#define		BANKSEL_C0CTLR1	c0ctlr1_addr.bit.banksel_c0ctlr1

/*------------------------------------------------------
   Can0 Clock Stop Control Register
------------------------------------------------------*/
#pragma ADDRESS		c0slpr_addr		0242H	/* Can0 Clock Stop Control Register */
typedef union {
	struct{
		UINT8	sleep_c0slpr:1;
		UINT8	b1:1;
		UINT8	b2:1;
		UINT8	b3:1;
		UINT8	b4:1;
		UINT8	b5:1;
		UINT8	b6:1;
		UINT8	b7:1;
	} bit;
	 UINT8 byte;
} C0SLPR_ADDR;
C0SLPR_ADDR	c0slpr_addr;

#define		C0SLPR		c0slpr_addr.byte

#define		SLEEP_C0SLPR	c0slpr_addr.bit.sleep_c0slpr

/*------------------------------------------------------
   Can0 Acceptance Filtering Support Unit
------------------------------------------------------*/
#pragma ADDRESS		c0afs_addr		0244H	/* Can0 Acceptance Filtering Support Unit */
typedef union {
    struct{
        UINT8    low;                /* Low  8 bit */
        UINT8    high;               /* High 8 bit */
    } byte;
    UINT16  word;
} C0AFS_ADDR;
C0AFS_ADDR	c0afs_addr;

#define		C0AFS        c0afs_addr.word
#define		C0AFSL       c0afs_addr.byte.low
#define		C0AFSH       c0afs_addr.byte.high

/*----------------------------------------------------*/
#pragma ADDRESS     x0r_addr    02c0H       /* X0 register */
typedef union {
    struct{
        UINT8    b0:1;
        UINT8    b1:1;
        UINT8    b2:1;
        UINT8    b3:1;
        UINT8    b4:1;
        UINT8    b5:1;
        UINT8    b6:1;
        UINT8    b7:1;
        UINT8    b8:1;
        UINT8    b9:1;
        UINT8    b10:1;
        UINT8    b11:1;
        UINT8    b12:1;
        UINT8    b13:1;
        UINT8    b14:1;
        UINT8    b15:1;
    } bit;
    struct{
        UINT8    low;                /* low  8 bit */
        UINT8    high;               /* high 8 bit */
    } byte;
    UINT16  word;
} X0R_ADDR;
X0R_ADDR	x0r_addr;

#define		X0R     x0r_addr.word
#define		X0RL	x0r_addr.byte.low
#define		X0RH	x0r_addr.byte.high

/*----------------------------------------------------*/
#pragma ADDRESS     y0r_addr    02c0H       /* Y0 register */
typedef union {
    struct{
        UINT8    b0:1;
        UINT8    b1:1;
        UINT8    b2:1;
        UINT8    b3:1;
        UINT8    b4:1;
        UINT8    b5:1;
        UINT8    b6:1;
        UINT8    b7:1;
        UINT8    b8:1;
        UINT8    b9:1;
        UINT8    b10:1;
        UINT8    b11:1;
        UINT8    b12:1;
        UINT8    b13:1;
        UINT8    b14:1;
        UINT8    b15:1;
    } bit;
    struct{
        UINT8    low;                /* low  8 bit */
        UINT8    high;               /* high 8 bit */
    } byte;
    UINT16  word;
} Y0R_ADDR;
Y0R_ADDR	y0r_addr;

#define		Y0R     y0r_addr.word
#define		Y0RL	y0r_addr.byte.low
#define		Y0RH	y0r_addr.byte.high

/*----------------------------------------------------*/
#pragma ADDRESS     x1r_addr    02c2H       /* X1 register */
typedef union {
    struct{
        UINT8    b0:1;
        UINT8    b1:1;
        UINT8    b2:1;
        UINT8    b3:1;
        UINT8    b4:1;
        UINT8    b5:1;
        UINT8    b6:1;
        UINT8    b7:1;
        UINT8    b8:1;
        UINT8    b9:1;
        UINT8    b10:1;
        UINT8    b11:1;
        UINT8    b12:1;
        UINT8    b13:1;
        UINT8    b14:1;
        UINT8    b15:1;
    } bit;
    struct{
        UINT8    low;                /* low  8 bit */
        UINT8    high;               /* high 8 bit */
    } byte;
    UINT16  word;
} X1R_ADDR;
X1R_ADDR	x1r_addr;

#define		X1R     x1r_addr.word
#define		X1RL	x1r_addr.byte.low
#define		X1RH	x1r_addr.byte.high

/*----------------------------------------------------*/
#pragma ADDRESS     y1r_addr    02c2H       /* Y1 register */
typedef union {
    struct{
        UINT8    b0:1;
        UINT8    b1:1;
        UINT8    b2:1;
        UINT8    b3:1;
        UINT8    b4:1;
        UINT8    b5:1;
        UINT8    b6:1;
        UINT8    b7:1;
        UINT8    b8:1;
        UINT8    b9:1;
        UINT8    b10:1;
        UINT8    b11:1;
        UINT8    b12:1;
        UINT8    b13:1;
        UINT8    b14:1;
        UINT8    b15:1;
    } bit;
    struct{
        UINT8    low;                /* low  8 bit */
        UINT8    high;               /* high 8 bit */
    } byte;
    UINT16  word;
} Y1R_ADDR;
Y1R_ADDR	y1r_addr;

#define		Y1R     y1r_addr.word
#define		Y1RL	y1r_addr.byte.low
#define		Y1RH	y1r_addr.byte.high

/*----------------------------------------------------*/
#pragma ADDRESS     x2r_addr    02c4H       /* X2 register */
typedef union {
    struct{
        UINT8    b0:1;
        UINT8    b1:1;
        UINT8    b2:1;
        UINT8    b3:1;
        UINT8    b4:1;
        UINT8    b5:1;
        UINT8    b6:1;
        UINT8    b7:1;
        UINT8    b8:1;
        UINT8    b9:1;
        UINT8    b10:1;
        UINT8    b11:1;
        UINT8    b12:1;
        UINT8    b13:1;
        UINT8    b14:1;
        UINT8    b15:1;
    } bit;
    struct{
        UINT8    low;                /* low  8 bit */
        UINT8    high;               /* high 8 bit */
    } byte;
    UINT16  word;
} X2R_ADDR;
X2R_ADDR	x2r_addr;

#define		X2R     x2r_addr.word
#define		X2RL	x2r_addr.byte.low
#define		X2RH	x2r_addr.byte.high

/*----------------------------------------------------*/
#pragma ADDRESS     y2r_addr    02c4H       /* Y2 register */
typedef union {
    struct{
        UINT8    b0:1;
        UINT8    b1:1;
        UINT8    b2:1;
        UINT8    b3:1;
        UINT8    b4:1;
        UINT8    b5:1;
        UINT8    b6:1;
        UINT8    b7:1;
        UINT8    b8:1;
        UINT8    b9:1;
        UINT8    b10:1;
        UINT8    b11:1;
        UINT8    b12:1;
        UINT8    b13:1;
        UINT8    b14:1;
        UINT8    b15:1;
    } bit;
    struct{
        UINT8    low;                /* low  8 bit */
        UINT8    high;               /* high 8 bit */
    } byte;
    UINT16  word;
} Y2R_ADDR;
Y2R_ADDR	y2r_addr;

#define		Y2R     y2r_addr.word
#define		Y2RL	y2r_addr.byte.low
#define		Y2RH	y2r_addr.byte.high

/*----------------------------------------------------*/
#pragma ADDRESS     x3r_addr    02c6H       /* X3 register */
typedef union {
    struct{
        UINT8    b0:1;
        UINT8    b1:1;
        UINT8    b2:1;
        UINT8    b3:1;
        UINT8    b4:1;
        UINT8    b5:1;
        UINT8    b6:1;
        UINT8    b7:1;
        UINT8    b8:1;
        UINT8    b9:1;
        UINT8    b10:1;
        UINT8    b11:1;
        UINT8    b12:1;
        UINT8    b13:1;
        UINT8    b14:1;
        UINT8    b15:1;
    } bit;
    struct{
        UINT8    low;                /* low  8 bit */
        UINT8    high;               /* high 8 bit */
    } byte;
    UINT16  word;
} X3R_ADDR;
X3R_ADDR	x3r_addr;

#define		X3R     x3r_addr.word
#define		X3RL	x3r_addr.byte.low
#define		X3RH	x3r_addr.byte.high

/*----------------------------------------------------*/
#pragma ADDRESS     y3r_addr    02c6H       /* Y3 register */
typedef union {
    struct{
        UINT8    b0:1;
        UINT8    b1:1;
        UINT8    b2:1;
        UINT8    b3:1;
        UINT8    b4:1;
        UINT8    b5:1;
        UINT8    b6:1;
        UINT8    b7:1;
        UINT8    b8:1;
        UINT8    b9:1;
        UINT8    b10:1;
        UINT8    b11:1;
        UINT8    b12:1;
        UINT8    b13:1;
        UINT8    b14:1;
        UINT8    b15:1;
    } bit;
    struct{
        UINT8    low;                /* low  8 bit */
        UINT8    high;               /* high 8 bit */
    } byte;
    UINT16  word;
} Y3R_ADDR;
Y3R_ADDR	y3r_addr;

#define		Y3R     y3r_addr.word
#define		Y3RL	y3r_addr.byte.low
#define		Y3RH	y3r_addr.byte.high

/*----------------------------------------------------*/
#pragma ADDRESS     x4r_addr    02c8H       /* X4 register */
typedef union {
    struct{
        UINT8    b0:1;
        UINT8    b1:1;
        UINT8    b2:1;
        UINT8    b3:1;
        UINT8    b4:1;
        UINT8    b5:1;
        UINT8    b6:1;
        UINT8    b7:1;
        UINT8    b8:1;
        UINT8    b9:1;
        UINT8    b10:1;
        UINT8    b11:1;
        UINT8    b12:1;
        UINT8    b13:1;
        UINT8    b14:1;
        UINT8    b15:1;
    } bit;
    struct{
        UINT8    low;                /* low  8 bit */
        UINT8    high;               /* high 8 bit */
    } byte;
    UINT16  word;
} X4R_ADDR;
X4R_ADDR	x4r_addr;

#define		X4R     x4r_addr.word
#define		X4RL	x4r_addr.byte.low
#define		X4RH	x4r_addr.byte.high

/*----------------------------------------------------*/
#pragma ADDRESS     y4r_addr    02c8H       /* Y4 register */
typedef union {
    struct{
        UINT8    b0:1;
        UINT8    b1:1;
        UINT8    b2:1;
        UINT8    b3:1;
        UINT8    b4:1;
        UINT8    b5:1;
        UINT8    b6:1;
        UINT8    b7:1;
        UINT8    b8:1;
        UINT8    b9:1;
        UINT8    b10:1;
        UINT8    b11:1;
        UINT8    b12:1;
        UINT8    b13:1;
        UINT8    b14:1;
        UINT8    b15:1;
    } bit;
    struct{
        UINT8    low;                /* low  8 bit */
        UINT8    high;               /* high 8 bit */
    } byte;
    UINT16  word;
} Y4R_ADDR;
Y4R_ADDR	y4r_addr;

#define		Y4R     y4r_addr.word
#define		Y4RL	y4r_addr.byte.low
#define		Y4RH	y4r_addr.byte.high

/*----------------------------------------------------*/
#pragma ADDRESS     x5r_addr    02caH       /* X5 register */
typedef union {
    struct{
        UINT8    b0:1;
        UINT8    b1:1;
        UINT8    b2:1;
        UINT8    b3:1;
        UINT8    b4:1;
        UINT8    b5:1;
        UINT8    b6:1;
        UINT8    b7:1;
        UINT8    b8:1;
        UINT8    b9:1;
        UINT8    b10:1;
        UINT8    b11:1;
        UINT8    b12:1;
        UINT8    b13:1;
        UINT8    b14:1;
        UINT8    b15:1;
    } bit;
    struct{
        UINT8    low;                /* low  8 bit */
        UINT8    high;               /* high 8 bit */
    } byte;
    UINT16  word;
} X5R_ADDR;
X5R_ADDR	x5r_addr;

#define		X5R     x5r_addr.word
#define		X5RL	x5r_addr.byte.low
#define		X5RH	x5r_addr.byte.high

/*----------------------------------------------------*/
#pragma ADDRESS     y5r_addr    02caH       /* Y5 register */
typedef union {
    struct{
        UINT8    b0:1;
        UINT8    b1:1;
        UINT8    b2:1;
        UINT8    b3:1;
        UINT8    b4:1;
        UINT8    b5:1;
        UINT8    b6:1;
        UINT8    b7:1;
        UINT8    b8:1;
        UINT8    b9:1;
        UINT8    b10:1;
        UINT8    b11:1;
        UINT8    b12:1;
        UINT8    b13:1;
        UINT8    b14:1;
        UINT8    b15:1;
    } bit;
    struct{
        UINT8    low;                /* low  8 bit */
        UINT8    high;               /* high 8 bit */
    } byte;
    UINT16  word;
} Y5R_ADDR;
Y5R_ADDR	y5r_addr;

#define		Y5R     y5r_addr.word
#define		Y5RL	y5r_addr.byte.low
#define		Y5RH	y5r_addr.byte.high

/*----------------------------------------------------*/
#pragma ADDRESS     x6r_addr    02ccH       /* X6 register */
typedef union {
    struct{
        UINT8    b0:1;
        UINT8    b1:1;
        UINT8    b2:1;
        UINT8    b3:1;
        UINT8    b4:1;
        UINT8    b5:1;
        UINT8    b6:1;
        UINT8    b7:1;
        UINT8    b8:1;
        UINT8    b9:1;
        UINT8    b10:1;
        UINT8    b11:1;
        UINT8    b12:1;
        UINT8    b13:1;
        UINT8    b14:1;
        UINT8    b15:1;
    } bit;
    struct{
        UINT8    low;                /* low  8 bit */
        UINT8    high;               /* high 8 bit */
    } byte;
    UINT16  word;
} X6R_ADDR;
X6R_ADDR	x6r_addr;

#define		X6R     x6r_addr.word
#define		X6RL	x6r_addr.byte.low
#define		X6RH	x6r_addr.byte.high

/*----------------------------------------------------*/
#pragma ADDRESS     y6r_addr    02ccH       /* Y6 register */
typedef union {
    struct{
        UINT8    b0:1;
        UINT8    b1:1;
        UINT8    b2:1;
        UINT8    b3:1;
        UINT8    b4:1;
        UINT8    b5:1;
        UINT8    b6:1;
        UINT8    b7:1;
        UINT8    b8:1;
        UINT8    b9:1;
        UINT8    b10:1;
        UINT8    b11:1;
        UINT8    b12:1;
        UINT8    b13:1;
        UINT8    b14:1;
        UINT8    b15:1;
    } bit;
    struct{
        UINT8    low;                /* low  8 bit */
        UINT8    high;               /* high 8 bit */
    } byte;
    UINT16  word;
} Y6R_ADDR;
Y6R_ADDR	y6r_addr;

#define		Y6R     y6r_addr.word
#define		Y6RL	y6r_addr.byte.low
#define		Y6RH	y6r_addr.byte.high

/*----------------------------------------------------*/
#pragma ADDRESS     x7r_addr    02ceH       /* X7 register */
typedef union {
    struct{
        UINT8    b0:1;
        UINT8    b1:1;
        UINT8    b2:1;
        UINT8    b3:1;
        UINT8    b4:1;
        UINT8    b5:1;
        UINT8    b6:1;
        UINT8    b7:1;
        UINT8    b8:1;
        UINT8    b9:1;
        UINT8    b10:1;
        UINT8    b11:1;
        UINT8    b12:1;
        UINT8    b13:1;
        UINT8    b14:1;
        UINT8    b15:1;
    } bit;
    struct{
        UINT8    low;                /* low  8 bit */
        UINT8    high;               /* high 8 bit */
    } byte;
    UINT16  word;
} X7R_ADDR;
X7R_ADDR	x7r_addr;

#define		X7R     x7r_addr.word
#define		X7RL	x7r_addr.byte.low
#define		X7RH	x7r_addr.byte.high

/*----------------------------------------------------*/
#pragma ADDRESS     y7r_addr    02ceH       /* Y7 register */
typedef union {
    struct{
        UINT8    b0:1;
        UINT8    b1:1;
        UINT8    b2:1;
        UINT8    b3:1;
        UINT8    b4:1;
        UINT8    b5:1;
        UINT8    b6:1;
        UINT8    b7:1;
        UINT8    b8:1;
        UINT8    b9:1;
        UINT8    b10:1;
        UINT8    b11:1;
        UINT8    b12:1;
        UINT8    b13:1;
        UINT8    b14:1;
        UINT8    b15:1;
    } bit;
    struct{
        UINT8    low;                /* low  8 bit */
        UINT8    high;               /* high 8 bit */
    } byte;
    UINT16  word;
} Y7R_ADDR;
Y7R_ADDR	y7r_addr;

#define		Y7R     y7r_addr.word
#define		Y7RL	y7r_addr.byte.low
#define		Y7RH	y7r_addr.byte.high

/*----------------------------------------------------*/
#pragma ADDRESS     x8r_addr    02d0H       /* X8 register */
typedef union {
    struct{
        UINT8    b0:1;
        UINT8    b1:1;
        UINT8    b2:1;
        UINT8    b3:1;
        UINT8    b4:1;
        UINT8    b5:1;
        UINT8    b6:1;
        UINT8    b7:1;
        UINT8    b8:1;
        UINT8    b9:1;
        UINT8    b10:1;
        UINT8    b11:1;
        UINT8    b12:1;
        UINT8    b13:1;
        UINT8    b14:1;
        UINT8    b15:1;
    } bit;
    struct{
        UINT8    low;                /* low  8 bit */
        UINT8    high;               /* high 8 bit */
    } byte;
    UINT16  word;
} X8R_ADDR;
X8R_ADDR	x8r_addr;

#define		X8R     x8r_addr.word
#define		X8RL	x8r_addr.byte.low
#define		X8RH	x8r_addr.byte.high

/*----------------------------------------------------*/
#pragma ADDRESS     y8r_addr    02d0H       /* Y8 register */
typedef union {
    struct{
        UINT8    b0:1;
        UINT8    b1:1;
        UINT8    b2:1;
        UINT8    b3:1;
        UINT8    b4:1;
        UINT8    b5:1;
        UINT8    b6:1;
        UINT8    b7:1;
        UINT8    b8:1;
        UINT8    b9:1;
        UINT8    b10:1;
        UINT8    b11:1;
        UINT8    b12:1;
        UINT8    b13:1;
        UINT8    b14:1;
        UINT8    b15:1;
    } bit;
    struct{
        UINT8    low;                /* low  8 bit */
        UINT8    high;               /* high 8 bit */
    } byte;
    UINT16  word;
} Y8R_ADDR;
Y8R_ADDR	y8r_addr;

#define		Y8R     y8r_addr.word
#define		Y8RL	y8r_addr.byte.low
#define		Y8RH	y8r_addr.byte.high

/*----------------------------------------------------*/
#pragma ADDRESS     x9r_addr    02d2H       /* X9 register */
typedef union {
    struct{
        UINT8    b0:1;
        UINT8    b1:1;
        UINT8    b2:1;
        UINT8    b3:1;
        UINT8    b4:1;
        UINT8    b5:1;
        UINT8    b6:1;
        UINT8    b7:1;
        UINT8    b8:1;
        UINT8    b9:1;
        UINT8    b10:1;
        UINT8    b11:1;
        UINT8    b12:1;
        UINT8    b13:1;
        UINT8    b14:1;
        UINT8    b15:1;
    } bit;
    struct{
        UINT8    low;                /* low  8 bit */
        UINT8    high;               /* high 8 bit */
    } byte;
    UINT16  word;
} X9R_ADDR;
X9R_ADDR	x9r_addr;

#define		X9R     x9r_addr.word
#define		X9RL	x9r_addr.byte.low
#define		X9RH	x9r_addr.byte.high

/*----------------------------------------------------*/
#pragma ADDRESS     y9r_addr    02d2H       /* Y9 register */
typedef union {
    struct{
        UINT8    b0:1;
        UINT8    b1:1;
        UINT8    b2:1;
        UINT8    b3:1;
        UINT8    b4:1;
        UINT8    b5:1;
        UINT8    b6:1;
        UINT8    b7:1;
        UINT8    b8:1;
        UINT8    b9:1;
        UINT8    b10:1;
        UINT8    b11:1;
        UINT8    b12:1;
        UINT8    b13:1;
        UINT8    b14:1;
        UINT8    b15:1;
    } bit;
    struct{
        UINT8    low;                /* low  8 bit */
        UINT8    high;               /* high 8 bit */
    } byte;
    UINT16  word;
} Y9R_ADDR;
Y9R_ADDR	y9r_addr;

#define		Y9R     y9r_addr.word
#define		Y9RL	y9r_addr.byte.low
#define		Y9RH	y9r_addr.byte.high

/*----------------------------------------------------*/
#pragma ADDRESS     x10r_addr   02d4H       /* X10 register */
typedef union {
    struct{
        UINT8    b0:1;
        UINT8    b1:1;
        UINT8    b2:1;
        UINT8    b3:1;
        UINT8    b4:1;
        UINT8    b5:1;
        UINT8    b6:1;
        UINT8    b7:1;
        UINT8    b8:1;
        UINT8    b9:1;
        UINT8    b10:1;
        UINT8    b11:1;
        UINT8    b12:1;
        UINT8    b13:1;
        UINT8    b14:1;
        UINT8    b15:1;
    } bit;
    struct{
        UINT8    low;                /* low  8 bit */
        UINT8    high;               /* high 8 bit */
    } byte;
    UINT16  word;
} X10R_ADDR;
X10R_ADDR	x10r_addr;

#define		X10R    x10r_addr.word
#define		X10RL	x10r_addr.byte.low
#define		X10RH	x10r_addr.byte.high

/*----------------------------------------------------*/
#pragma ADDRESS     y10r_addr   02d4H       /* Y10 register */
typedef union {
    struct{
        UINT8    b0:1;
        UINT8    b1:1;
        UINT8    b2:1;
        UINT8    b3:1;
        UINT8    b4:1;
        UINT8    b5:1;
        UINT8    b6:1;
        UINT8    b7:1;
        UINT8    b8:1;
        UINT8    b9:1;
        UINT8    b10:1;
        UINT8    b11:1;
        UINT8    b12:1;
        UINT8    b13:1;
        UINT8    b14:1;
        UINT8    b15:1;
    } bit;
    struct{
        UINT8    low;                /* low  8 bit */
        UINT8    high;               /* high 8 bit */
    } byte;
    UINT16  word;
} Y10R_ADDR;
Y10R_ADDR	y10r_addr;

#define		Y10R    y10r_addr.word
#define		Y10RL	y10r_addr.byte.low
#define		Y10RH	y10r_addr.byte.high

/*----------------------------------------------------*/
#pragma ADDRESS     x11r_addr   02d6H       /* X11 register */
typedef union {
    struct{
        UINT8    b0:1;
        UINT8    b1:1;
        UINT8    b2:1;
        UINT8    b3:1;
        UINT8    b4:1;
        UINT8    b5:1;
        UINT8    b6:1;
        UINT8    b7:1;
        UINT8    b8:1;
        UINT8    b9:1;
        UINT8    b10:1;
        UINT8    b11:1;
        UINT8    b12:1;
        UINT8    b13:1;
        UINT8    b14:1;
        UINT8    b15:1;
    } bit;
    struct{
        UINT8    low;                /* low  8 bit */
        UINT8    high;               /* high 8 bit */
    } byte;
    UINT16  word;
} X11R_ADDR;
X11R_ADDR	x11r_addr;

#define		X11R    x11r_addr.word
#define		X11RL	x11r_addr.byte.low
#define		X11RH	x11r_addr.byte.high

/*----------------------------------------------------*/
#pragma ADDRESS     y11r_addr   02d6H       /* Y11 register */
typedef union {
    struct{
        UINT8    b0:1;
        UINT8    b1:1;
        UINT8    b2:1;
        UINT8    b3:1;
        UINT8    b4:1;
        UINT8    b5:1;
        UINT8    b6:1;
        UINT8    b7:1;
        UINT8    b8:1;
        UINT8    b9:1;
        UINT8    b10:1;
        UINT8    b11:1;
        UINT8    b12:1;
        UINT8    b13:1;
        UINT8    b14:1;
        UINT8    b15:1;
    } bit;
    struct{
        UINT8    low;                /* low  8 bit */
        UINT8    high;               /* high 8 bit */
    } byte;
    UINT16  word;
} Y11R_ADDR;
Y11R_ADDR	y11r_addr;

#define		Y11R    y11r_addr.word
#define		Y11RL	y11r_addr.byte.low
#define		Y11RH	y11r_addr.byte.high

/*----------------------------------------------------*/
#pragma ADDRESS     x12r_addr   02d8H       /* X12 register */
typedef union {
    struct{
        UINT8    b0:1;
        UINT8    b1:1;
        UINT8    b2:1;
        UINT8    b3:1;
        UINT8    b4:1;
        UINT8    b5:1;
        UINT8    b6:1;
        UINT8    b7:1;
        UINT8    b8:1;
        UINT8    b9:1;
        UINT8    b10:1;
        UINT8    b11:1;
        UINT8    b12:1;
        UINT8    b13:1;
        UINT8    b14:1;
        UINT8    b15:1;
    } bit;
    struct{
        UINT8    low;                /* low  8 bit */
        UINT8    high;               /* high 8 bit */
    } byte;
    UINT16  word;
} X12R_ADDR;
X12R_ADDR	x12r_addr;

#define		X12R    x12r_addr.word
#define		X12RL	x12r_addr.byte.low
#define		X12RH	x12r_addr.byte.high

/*----------------------------------------------------*/
#pragma ADDRESS     y12r_addr   02d8H       /* Y12 register */
typedef union {
    struct{
        UINT8    b0:1;
        UINT8    b1:1;
        UINT8    b2:1;
        UINT8    b3:1;
        UINT8    b4:1;
        UINT8    b5:1;
        UINT8    b6:1;
        UINT8    b7:1;
        UINT8    b8:1;
        UINT8    b9:1;
        UINT8    b10:1;
        UINT8    b11:1;
        UINT8    b12:1;
        UINT8    b13:1;
        UINT8    b14:1;
        UINT8    b15:1;
    } bit;
    struct{
        UINT8    low;                /* low  8 bit */
        UINT8    high;               /* high 8 bit */
    } byte;
    UINT16  word;
} Y12R_ADDR;
Y12R_ADDR	y12r_addr;

#define		Y12R    y12r_addr.word
#define		Y12RL	y12r_addr.byte.low
#define		Y12RH	y12r_addr.byte.high

/*----------------------------------------------------*/
#pragma ADDRESS     x13r_addr   02daH       /* X13 register */
typedef union {
    struct{
        UINT8    b0:1;
        UINT8    b1:1;
        UINT8    b2:1;
        UINT8    b3:1;
        UINT8    b4:1;
        UINT8    b5:1;
        UINT8    b6:1;
        UINT8    b7:1;
        UINT8    b8:1;
        UINT8    b9:1;
        UINT8    b10:1;
        UINT8    b11:1;
        UINT8    b12:1;
        UINT8    b13:1;
        UINT8    b14:1;
        UINT8    b15:1;
    } bit;
    struct{
        UINT8    low;                /* low  8 bit */
        UINT8    high;               /* high 8 bit */
    } byte;
    UINT16  word;
} X13R_ADDR;
X13R_ADDR	x13r_addr;

#define		X13R    x13r_addr.word
#define		X13RL	x13r_addr.byte.low
#define		X13RH	x13r_addr.byte.high

/*----------------------------------------------------*/
#pragma ADDRESS     y13r_addr   02daH       /* Y13 register */
typedef union {
    struct{
        UINT8    b0:1;
        UINT8    b1:1;
        UINT8    b2:1;
        UINT8    b3:1;
        UINT8    b4:1;
        UINT8    b5:1;
        UINT8    b6:1;
        UINT8    b7:1;
        UINT8    b8:1;
        UINT8    b9:1;
        UINT8    b10:1;
        UINT8    b11:1;
        UINT8    b12:1;
        UINT8    b13:1;
        UINT8    b14:1;
        UINT8    b15:1;
    } bit;
    struct{
        UINT8    low;                /* low  8 bit */
        UINT8    high;               /* high 8 bit */
    } byte;
    UINT16  word;
} Y13R_ADDR;
Y13R_ADDR	y13r_addr;

#define		Y13R    y13r_addr.word
#define		Y13RL	y13r_addr.byte.low
#define		Y13RH	y13r_addr.byte.high

/*----------------------------------------------------*/
#pragma ADDRESS     x14r_addr   02dcH       /* X14 register */
typedef union {
    struct{
        UINT8    b0:1;
        UINT8    b1:1;
        UINT8    b2:1;
        UINT8    b3:1;
        UINT8    b4:1;
        UINT8    b5:1;
        UINT8    b6:1;
        UINT8    b7:1;
        UINT8    b8:1;
        UINT8    b9:1;
        UINT8    b10:1;
        UINT8    b11:1;
        UINT8    b12:1;
        UINT8    b13:1;
        UINT8    b14:1;
        UINT8    b15:1;
    } bit;
    struct{
        UINT8    low;                /* low  8 bit */
        UINT8    high;               /* high 8 bit */
    } byte;
    UINT16  word;
} X14R_ADDR;
X14R_ADDR	x14r_addr;

#define		X14R    x14r_addr.word
#define		X14RL	x14r_addr.byte.low
#define		X14RH	x14r_addr.byte.high

/*----------------------------------------------------*/
#pragma ADDRESS     y14r_addr   02dcH       /* Y14 register */
typedef union {
    struct{
        UINT8    b0:1;
        UINT8    b1:1;
        UINT8    b2:1;
        UINT8    b3:1;
        UINT8    b4:1;
        UINT8    b5:1;
        UINT8    b6:1;
        UINT8    b7:1;
        UINT8    b8:1;
        UINT8    b9:1;
        UINT8    b10:1;
        UINT8    b11:1;
        UINT8    b12:1;
        UINT8    b13:1;
        UINT8    b14:1;
        UINT8    b15:1;
    } bit;
    struct{
        UINT8    low;                /* low  8 bit */
        UINT8    high;               /* high 8 bit */
    } byte;
    UINT16  word;
} Y14R_ADDR;
Y14R_ADDR	y14r_addr;

#define		Y14R    y14r_addr.word
#define		Y14RL	y14r_addr.byte.low
#define		Y14RH	y14r_addr.byte.high

/*----------------------------------------------------*/
#pragma ADDRESS     x15r_addr   02deH       /* X15 register */
typedef union {
    struct{
        UINT8    b0:1;
        UINT8    b1:1;
        UINT8    b2:1;
        UINT8    b3:1;
        UINT8    b4:1;
        UINT8    b5:1;
        UINT8    b6:1;
        UINT8    b7:1;
        UINT8    b8:1;
        UINT8    b9:1;
        UINT8    b10:1;
        UINT8    b11:1;
        UINT8    b12:1;
        UINT8    b13:1;
        UINT8    b14:1;
        UINT8    b15:1;
    } bit;
    struct{
        UINT8    low;                /* low  8 bit */
        UINT8    high;               /* high 8 bit */
    } byte;
    UINT16  word;
} X15R_ADDR;
X15R_ADDR	x15r_addr;

#define		X15R    x15r_addr.word
#define		X15RL	x15r_addr.byte.low
#define		X15RH	x15r_addr.byte.high

/*----------------------------------------------------*/
#pragma ADDRESS     y15r_addr   02deH       /* Y15 register */
typedef union {
    struct{
        UINT8    b0:1;
        UINT8    b1:1;
        UINT8    b2:1;
        UINT8    b3:1;
        UINT8    b4:1;
        UINT8    b5:1;
        UINT8    b6:1;
        UINT8    b7:1;
        UINT8    b8:1;
        UINT8    b9:1;
        UINT8    b10:1;
        UINT8    b11:1;
        UINT8    b12:1;
        UINT8    b13:1;
        UINT8    b14:1;
        UINT8    b15:1;
    } bit;
    struct{
        UINT8    low;                /* low  8 bit */
        UINT8    high;               /* high 8 bit */
    } byte;
    UINT16  word;
} Y15R_ADDR;
Y15R_ADDR	y15r_addr;

#define		Y15R    y15r_addr.word
#define		Y15RL	y15r_addr.byte.low
#define		Y15RH	y15r_addr.byte.high

/*------------------------------------------------------
    X-Y control register
------------------------------------------------------*/
#pragma ADDRESS     xyc_addr    02e0H       /* X-Y control register */
typedef union {
	struct{
		UINT8	xyc0:1;
		UINT8	xyc1:1;
		UINT8	b2:1;
		UINT8	b3:1;
		UINT8	b4:1;
		UINT8	b5:1;
		UINT8	b6:1;
		UINT8	b7:1;
	} bit;
	 UINT8 byte;
} XYC_ADDR;
XYC_ADDR	xyc_addr;

#define		XYC			xyc_addr.byte

#define		XYC0		xyc_addr.bit.xyc0
#define		XYC1		xyc_addr.bit.xyc1

/*------------------------------------------------------
     u1smr4
------------------------------------------------------*/
#pragma ADDRESS     u1smr4_addr 02e4H       /* UART1 special mode register 4 */
typedef union {
    struct{
        UINT8    stareq:1;
        UINT8    rstareq:1;
        UINT8    stpreq:1;
        UINT8    stspsel:1;
        UINT8    ackd:1;
        UINT8    ackc:1;
        UINT8    sclhi:1;
        UINT8    swc9:1;
    } bit;
    UINT8    byte;
} U1SMR4_ADDR;
U1SMR4_ADDR	u1smr4_addr;

#define		U1SMR4      u1smr4_addr.byte

#define		STAREQ_U1SMR4  u1smr4_addr.bit.stareq
#define		RSTAREQ_U1SMR4 u1smr4_addr.bit.rstareq
#define		STPREQ_U1SMR4 u1smr4_addr.bit.stpreq
#define		STSPSEL_U1SMR4 u1smr4_addr.bit.stspsel
#define		ACKD_U1SMR4  u1smr4_addr.bit.ackd
#define		ACKC_U1SMR4  u1smr4_addr.bit.ackc
#define		SCLHI_U1SMR4  u1smr4_addr.bit.sclhi
#define		SWC9_U1SMR4  u1smr4_addr.bit.swc9

/*------------------------------------------------------
     u1smr3
------------------------------------------------------*/
#pragma ADDRESS     u1smr3_addr 02e5H       /* UART1 special mode register 3 */
typedef union {
    struct{
        UINT8    sse:1;
        UINT8    ckph:1;
        UINT8    dinc:1;
        UINT8    nodc:1;
        UINT8    err:1;
        UINT8    dl0:1;
        UINT8    dl1:1;
        UINT8    dl2:1;
    } bit;
    UINT8    byte;
} U1SMR3_ADDR;
U1SMR3_ADDR	u1smr3_addr;

#define		U1SMR3      u1smr3_addr.byte

#define		SSE_U1SMR3  u1smr3_addr.bit.sse
#define		CKPH_U1SMR3 u1smr3_addr.bit.ckph
#define		DINC_U1SMR3 u1smr3_addr.bit.dinc
#define		NODC_U1SMR3 u1smr3_addr.bit.nodc
#define		ERR_U1SMR3  u1smr3_addr.bit.err
#define		DL0_U1SMR3  u1smr3_addr.bit.dl0
#define		DL1_U1SMR3  u1smr3_addr.bit.dl1
#define		DL2_U1SMR3  u1smr3_addr.bit.dl2

/*------------------------------------------------------
     u1smr2
------------------------------------------------------*/
#pragma ADDRESS     u1smr2_addr 02e6H       /* UART1 special mode register 2 */
typedef union {
    struct{
        UINT8    iicm2:1;
        UINT8    csc:1;
        UINT8    swc:1;
        UINT8    als:1;
        UINT8    stc:1;
        UINT8    swc2:1;
        UINT8    sdhi:1;
        UINT8    shtc:1;
    } bit;
    UINT8    byte;
} U1SMR2_ADDR;
U1SMR2_ADDR	u1smr2_addr;

#define		U1SMR2      u1smr2_addr.byte

#define		IICM2_U1SMR2    u1smr2_addr.bit.iicm2
#define		CSC_U1SMR2  u1smr2_addr.bit.csc
#define		SWC_U1SMR2  u1smr2_addr.bit.swc
#define		ALS_U1SMR2  u1smr2_addr.bit.als
#define		STC_U1SMR2  u1smr2_addr.bit.stc 
#define		SWC2_U1SMR2 u1smr2_addr.bit.swc2
#define		SDHI_U1SMR2 u1smr2_addr.bit.sdhi
#define		SU1HIM_U1SMR2 u1smr2_addr.bit.shtc

/*------------------------------------------------------
     u1smr
------------------------------------------------------*/
#pragma ADDRESS     u1smr_addr  02e7H       /* UART1 special mode register */
typedef union {
    struct{
        UINT8    iicm:1;
        UINT8    abc:1;
        UINT8    bbs:1;
        UINT8    lsyn:1;
        UINT8    abscs:1;
        UINT8    acse:1;
        UINT8    sss:1;
        UINT8    su1him:1;
    } bit;
    UINT8    byte;
} U1SMR_ADDR;
U1SMR_ADDR	u1smr_addr;

#define		U1SMR       u1smr_addr.byte

#define		IICM_U1SMR  u1smr_addr.bit.iicm 
#define		ABC_U1SMR   u1smr_addr.bit.abc
#define		BBS_U1SMR   u1smr_addr.bit.bbs
#define		LSYN_U1SMR  u1smr_addr.bit.lsyn
#define		ABSCS_U1SMR u1smr_addr.bit.abscs
#define		ACSE_U1SMR  u1smr_addr.bit.acse
#define		SSS_U1SMR   u1smr_addr.bit.sss
#define		SCLKDIV_U1SMR   u1smr_addr.bit.su1him

/*------------------------------------------------------
     u1mr
------------------------------------------------------*/
#pragma ADDRESS     u1mr_addr   02e8H       /* UART1 transmit/receive mode register */
typedef union {
    struct{
        UINT8    smd0:1;             /* Serial I/O mode select bit */
        UINT8    smd1:1;             /* Serial I/O mode select bit */
        UINT8    smd2:1;             /* Serial I/O mode select bit */
        UINT8    ckdir:1;            /* Internal/external clock select bit */
        UINT8    stps:1;             /* Stop bit length select bit */
        UINT8    pry:1;              /* Odd/even parity select bit */
        UINT8    prye:1;             /* Parity enable bit */
        UINT8    iopol:1;            /* TxD RxD I/O polarity reverse bit */
    } bit;
    UINT8    byte;
} U1MR_ADDR;
U1MR_ADDR	u1mr_addr;

#define		U1MR        u1mr_addr.byte

#define		SMD0_U1MR   u1mr_addr.bit.smd0  /* Serial I/O mode select bit */
#define		SMD1_U1MR   u1mr_addr.bit.smd1  /* Serial I/O mode select bit */
#define		SMD2_U1MR   u1mr_addr.bit.smd2  /* Serial I/O mode select bit */
#define		CKDIR_U1MR  u1mr_addr.bit.ckdir /* Internal/external clock select bit */
#define		STPS_U1MR   u1mr_addr.bit.stps  /* Stop bit length select bit */
#define		PRY_U1MR    u1mr_addr.bit.pry   /* Odd/even parity select bit */
#define		PRYE_U1MR   u1mr_addr.bit.prye  /* Parity enable bit */
#define		IOPOL_U1MR  u1mr_addr.bit.iopol  /* TxD RxD I/O polarity reverse bit */

/*------------------------------------------------------
    UART1 bit rate generators ; Use "MOV" instruction when writing to these registers.
------------------------------------------------------*/
#pragma ADDRESS     u1brg_addr  02e9H       /* UART1 bit rate generator */
UINT8 u1brg_addr;

#define		U1BRG       u1brg_addr

/*----------------------------------------------------*/
#pragma ADDRESS     u1tb_addr   02eaH       /* UART1 transmit buffer register */
typedef union {
    struct{
        UINT8    b0:1;
        UINT8    b1:1;
        UINT8    b2:1;
        UINT8    b3:1;
        UINT8    b4:1;
        UINT8    b5:1;
        UINT8    b6:1;
        UINT8    b7:1;
        UINT8    b8:1;
        UINT8    b9:1;
        UINT8    b10:1;
        UINT8    b11:1;
        UINT8    b12:1;
        UINT8    b13:1;
        UINT8    b14:1;
        UINT8    b15:1;
    } bit;
    struct{
        UINT8    low;                /* low  8 bit */
        UINT8    high;               /* high 8 bit */
    } byte;
    UINT16  word;
} U1TB_ADDR;
U1TB_ADDR	u1tb_addr;

#define		U1TB    u1tb_addr.word          /* UART1 Transmit buffer register 16 bit ; Use "MOV" instruction when writing to this register. */
#define		U1TBL   u1tb_addr.byte.low          /* UART1 Transmit buffer register low  8 bit */
#define		U1TBH   u1tb_addr.byte.high         /* UART1 Transmit buffer register high 8 bit */

/*------------------------------------------------------
     u1c0
------------------------------------------------------*/
#pragma ADDRESS     u1c0_addr   02ecH       /* UART1 transmit/receive control register 0 */
typedef union {
    struct{
        UINT8    clk0:1;         /* BRG count source select bit */
        UINT8    clk1:1;         /* BRG count source select bit */
        UINT8    crs:1;          /* CTS~/RTS~ function select bit */
        UINT8    txept:1;        /* Transmit register empty flag */
        UINT8    crd:1;          /* CTS~/RTS~ disable bit */
        UINT8    nch:1;          /* Data output select bit */
        UINT8    ckpol:1;        /* CLK polarity select bit */
        UINT8    uform:1;        /* Transfer format select bit */
    } bit;
    UINT8    byte;
} U1C0_ADDR;
U1C0_ADDR	u1c0_addr;

#define		U1C0        u1c0_addr.byte

#define		CLK0_U1C0   u1c0_addr.bit.clk0  /* BRG count source select bit */
#define		CLK1_U1C0   u1c0_addr.bit.clk1  /* BRG count source select bit */
#define		CRS_U1C0    u1c0_addr.bit.crs   /* CTS~/RTS~ function select bit */
#define		TXEPT_U1C0  u1c0_addr.bit.txept /* Transmit register empty flag */
#define		CRD_U1C0    u1c0_addr.bit.crd   /* CTS~/RTS~ disable bit */
#define		NCH_U1C0    u1c0_addr.bit.nch   /* Data output select bit */
#define		CKPOL_U1C0  u1c0_addr.bit.ckpol /* CLK polarity select bit */
#define		UFORM_U1C0  u1c0_addr.bit.uform /* Transfer format select bit */

/*------------------------------------------------------
    UART1 transmit/receive control register 1
------------------------------------------------------*/
#pragma ADDRESS     u1c1_addr   02edH       /* UART1 transmit/receive control register 1 */
typedef union {
	struct{
		UINT8	te_u1c1:1;
		UINT8	ti_u1c1:1;
		UINT8	re_u1c1:1;
		UINT8	ri_u1c1:1;
		UINT8	u1irs_u1c1:1;
		UINT8	u1rrm_u1c1:1;
		UINT8	u1lch_u1c1:1;
		UINT8	u1ere_u1c1:1;
	} bit;
	 UINT8 byte;
} U1C1_ADDR;
U1C1_ADDR	u1c1_addr;

#define		U1C1		u1c1_addr.byte

#define		TE_U1C1		u1c1_addr.bit.te_u1c1
#define		TI_U1C1		u1c1_addr.bit.ti_u1c1
#define		RE_U1C1		u1c1_addr.bit.re_u1c1
#define		RI_U1C1		u1c1_addr.bit.ri_u1c1
#define		U1IRS_U1C1	u1c1_addr.bit.u1irs_u1c1
#define		U1RRM_U1C1	u1c1_addr.bit.u1rrm_u1c1
#define		U1LCH_U1C1	u1c1_addr.bit.u1lch_u1c1
#define		U1ERE_U1C1	u1c1_addr.bit.u1ere_u1c1

/*------------------------------------------------------
     u1rb
------------------------------------------------------*/
#pragma ADDRESS     u1rb_addr   02eeH       /* UART1 receive buffer register */
typedef union {
    struct{
        UINT8    b0:1;
        UINT8    b1:1;
        UINT8    b2:1;
        UINT8    b3:1;
        UINT8    b4:1;
        UINT8    b5:1;
        UINT8    b6:1;
        UINT8    b7:1;
        UINT8    b8:1;
        UINT8    b9:1;
        UINT8    b10:1;
        UINT8    abt:1;              /* Arbitration lost detecting flag */
        UINT8    oer:1;              /* Overrun error flag */
        UINT8    fer:1;              /* Framing error flag */
        UINT8    per:1;              /* Parity error flag */
        UINT8    sum:1;              /* Error sum flag */
    } bit;
    struct{
        UINT8    low;                /* Low  8 bit */
        UINT8    high;               /* High 8 bit */
    } byte;
    UINT16  word;
} U1RB_ADDR;
U1RB_ADDR	u1rb_addr;

#define		U1RB        u1rb_addr.word
#define		U1RBL       u1rb_addr.byte.low
#define		U1RBH       u1rb_addr.byte.high

#define		ABT_U1RB    u1rb_addr.bit.abt   /* Arbitration lost detecting flag */
#define		OER_U1RB    u1rb_addr.bit.oer   /* Overrun error flag */
#define		FER_U1RB    u1rb_addr.bit.fer   /* Framing error flag */
#define		PER_U1RB    u1rb_addr.bit.per   /* Parity error flag */
#define		SUM_U1RB    u1rb_addr.bit.sum   /* Error sum flag */

/*------------------------------------------------------
     u4smr4
------------------------------------------------------*/
#pragma ADDRESS     u4smr4_addr 02f4H       /* UART4 special mode register 4 */
typedef union {
    struct{
        UINT8    stareq:1;
        UINT8    rstareq:1;
        UINT8    stpreq:1;
        UINT8    stspsel:1;
        UINT8    ackd:1;
        UINT8    ackc:1;
        UINT8    sclhi:1;
        UINT8    swc9:1;
    } bit;
    UINT8    byte;
} U4SMR4_ADDR;
U4SMR4_ADDR	u4smr4_addr;

#define		U4SMR4      u4smr4_addr.byte

#define		STAREQ_U4SMR4   u4smr4_addr.bit.stareq
#define		RSTAREQ_U4SMR4  u4smr4_addr.bit.rstareq
#define		STPREQ_U4SMR4   u4smr4_addr.bit.stpreq
#define		STSPSEL_U4SMR4  u4smr4_addr.bit.stspsel
#define		ACKD_U4SMR4     u4smr4_addr.bit.ackd
#define		ACKC_U4SMR4     u4smr4_addr.bit.ackc
#define		SCLHI_U4SMR4    u4smr4_addr.bit.sclhi
#define		SWC9_U4SMR4     u4smr4_addr.bit.swc9


/*------------------------------------------------------
     u4smr3
------------------------------------------------------*/
#pragma ADDRESS     u4smr3_addr 02f5H       /* UART4 special mode register 3 */
typedef union {
    struct{
        UINT8    sse:1;
        UINT8    ckph:1;
        UINT8    dinc:1;
        UINT8    nodc:1;
        UINT8    err:1;
        UINT8    dl0:1;
        UINT8    dl1:1;
        UINT8    dl2:1;
    } bit;
    UINT8    byte;
} U4SMR3_ADDR;
U4SMR3_ADDR	u4smr3_addr;

#define		U4SMR3      u4smr3_addr.byte

#define		SSE_U4SMR3  u4smr3_addr.bit.sse
#define		CKPH_U4SMR3 u4smr3_addr.bit.ckph
#define		DINC_U4SMR3 u4smr3_addr.bit.dinc
#define		NODC_U4SMR3 u4smr3_addr.bit.nodc
#define		ERR_U4SMR3  u4smr3_addr.bit.err
#define		DL0_U4SMR3  u4smr3_addr.bit.dl0
#define		DL1_U4SMR3  u4smr3_addr.bit.dl1
#define		DL2_U4SMR3  u4smr3_addr.bit.dl2

/*------------------------------------------------------
     u4smr2
------------------------------------------------------*/
#pragma ADDRESS     u4smr2_addr 02f6H       /* UART4 special mode register 2 */
typedef union {
    struct{
        UINT8    iicm2:1;
        UINT8    csc:1;
        UINT8    swc:1;
        UINT8    als:1;
        UINT8    stc:1;
        UINT8    swc2:1;
        UINT8    sdhi:1;
        UINT8    shtc:1;
    } bit;
    UINT8    byte;
} U4SMR2_ADDR;
U4SMR2_ADDR	u4smr2_addr;

#define		U4SMR2      u4smr2_addr.byte

#define		IICM2_U4SMR2    u4smr2_addr.bit.iicm2
#define		CSC_U4SMR2  	u4smr2_addr.bit.csc
#define		SWC_U4SMR2  	u4smr2_addr.bit.swc
#define		ALS_U4SMR2  	u4smr2_addr.bit.als
#define		STC_U4SMR2  	u4smr2_addr.bit.stc
#define		SWC2_U4SMR2 	u4smr2_addr.bit.swc2
#define		SDHI_U4SMR2 	u4smr2_addr.bit.sdhi
#define		SU1HIM_U4SMR2 	u4smr2_addr.bit.shtc


/*------------------------------------------------------
     u4smr
------------------------------------------------------*/
#pragma ADDRESS     u4smr_addr  02f7H       /* UART4 special mode register */
typedef union {
    struct{
        UINT8    iicm:1;
        UINT8    abc:1;
        UINT8    bbs:1;
        UINT8    lsyn:1;
        UINT8    abscs:1;
        UINT8    acse:1;
        UINT8    sss:1;
        UINT8    su1him:1;
    } bit;
    UINT8    byte;
} U4SMR_ADDR;
U4SMR_ADDR	u4smr_addr;

#define		U4SMR       u4smr_addr.byte

#define		IICM_U4SMR  	u4smr_addr.bit.iicm
#define		ABC_U4SMR   	u4smr_addr.bit.abc
#define		BBS_U4SMR   	u4smr_addr.bit.bbs
#define		LSYN_U4SMR  	u4smr_addr.bit.lsyn
#define		ABSCS_U4SMR 	u4smr_addr.bit.abscs
#define		ACSE_U4SMR  	u4smr_addr.bit.acse
#define		SSS_U4SMR	    u4smr_addr.bit.sss
#define		SCLKDIV_U4SMR   u4smr_addr.bit.su1him

/*------------------------------------------------------
     u4mr
------------------------------------------------------*/
#pragma ADDRESS     u4mr_addr   02f8H       /* UART4 transmit/receive mode register */
typedef union {
    struct{
        UINT8    smd0:1;             /* Serial I/O mode select bit */
        UINT8    smd1:1;             /* Serial I/O mode select bit */
        UINT8    smd2:1;             /* Serial I/O mode select bit */
        UINT8    ckdir:1;            /* Internal/external clock select bit */
        UINT8    stps:1;             /* Stop bit length select bit */
        UINT8    pry:1;              /* Odd/even parity select bit */
        UINT8    prye:1;             /* Parity enable bit */
        UINT8    iopol:1;            /* TxD RxD I/O polarity reverse bit */
    } bit;
    UINT8    byte;
} U4MR_ADDR;
U4MR_ADDR	u4mr_addr;

#define		U4MR        u4mr_addr.byte

#define		SMD0_U4MR   u4mr_addr.bit.smd0  /* Serial I/O mode select bit */
#define		SMD1_U4MR   u4mr_addr.bit.smd1  /* Serial I/O mode select bit */
#define		SMD2_U4MR   u4mr_addr.bit.smd2  /* Serial I/O mode select bit */
#define		CKDIR_U4MR  u4mr_addr.bit.ckdir /* Internal/external clock select bit */
#define		STPS_U4MR   u4mr_addr.bit.stps  /* Stop bit length select bit */
#define		PRY_U4MR    u4mr_addr.bit.pry   /* Odd/even parity select bit */
#define		PRYE_U4MR   u4mr_addr.bit.prye  /* Parity enable bit */
#define		IOPOL_U4MR  u4mr_addr.bit.iopol  /* TxD RxD I/O polarity reverse bit */

/*------------------------------------------------------
    UART4 bit rate generators ; Use "MOV" instruction when writing to these registers.
------------------------------------------------------*/
#pragma ADDRESS     u4brg_addr  02f9H       /* UART4 bit rate generator */
typedef union {
	struct{
		UINT8	b0:1;
		UINT8	b1:1;
		UINT8	b2:1;
		UINT8	b3:1;
		UINT8	b4:1;
		UINT8	b5:1;
		UINT8	b6:1;
		UINT8	b7:1;
	} bit;
	 UINT8 byte;
} U4BRG_ADDR;
U4BRG_ADDR	u4brg_addr;

#define		U4BRG		u4brg_addr.byte

/*----------------------------------------------------*/
#pragma ADDRESS     u4tb_addr   02faH       /* UART4 transmit buffer register */
typedef union {
    struct{
        UINT8    b0:1;
        UINT8    b1:1;
        UINT8    b2:1;
        UINT8    b3:1;
        UINT8    b4:1;
        UINT8    b5:1;
        UINT8    b6:1;
        UINT8    b7:1;
        UINT8    b8:1;
        UINT8    b9:1;
        UINT8    b10:1;
        UINT8    b11:1;
        UINT8    b12:1;
        UINT8    b13:1;
        UINT8    b14:1;
        UINT8    b15:1;
    } bit;
    struct{
        UINT8    low;                /* low  8 bit */
        UINT8    high;               /* high 8 bit */
    } byte;
    UINT16  word;
} U4TB_ADDR;
U4TB_ADDR	u4tb_addr;

#define		U4TB    u4tb_addr.word          /* UART4 Transmit buffer register 16 bit ; Use "MOV" instruction when writing to this register. */
#define		U4TBL   u4tb_addr.byte.low          /* UART4 Transmit buffer register low  8 bit */
#define		U4TBH   u4tb_addr.byte.high         /* UART4 Transmit buffer register high 8 bit */

/*------------------------------------------------------
     u4c0
------------------------------------------------------*/
#pragma ADDRESS     u4c0_addr   02fcH       /* UART4 transmit/receive control register 0 */
typedef union {
    struct{
        UINT8    clk0:1;         /* BRG count source select bit */
        UINT8    clk1:1;         /* BRG count source select bit */
        UINT8    crs:1;          /* CTS~/RTS~ function select bit */
        UINT8    txept:1;        /* Transmit register empty flag */
        UINT8    crd:1;          /* CTS~/RTS~ disable bit */
        UINT8    nch:1;          /* Data output select bit */
        UINT8    ckpol:1;        /* CLK polarity select bit */
        UINT8    uform:1;        /* Transfer format select bit */
    } bit;
    UINT8    byte;
} U4C0_ADDR;
U4C0_ADDR	u4c0_addr;

#define		U4C0        u4c0_addr.byte

#define		CLK0_U4C0   u4c0_addr.bit.clk0  /* BRG count source select bit */
#define		CLK1_U4C0   u4c0_addr.bit.clk1  /* BRG count source select bit */
#define		CRS_U4C0    u4c0_addr.bit.crs   /* CTS~/RTS~ function select bit */
#define		TXEPT_U4C0  u4c0_addr.bit.txept /* Transmit register empty flag */
#define		CRD_U4C0    u4c0_addr.bit.crd   /* CTS~/RTS~ disable bit */
#define		NCH_U4C0    u4c0_addr.bit.nch   /* Data output select bit */
#define		CKPOL_U4C0  u4c0_addr.bit.ckpol /* CLK polarity select bit */
#define		UFORM_U4C0  u4c0_addr.bit.uform /* Transfer format select bit */

/*------------------------------------------------------
    UART4 transmit/receive control register 1
------------------------------------------------------*/
#pragma ADDRESS     u4c1_addr   02fdH       /* UART4 transmit/receive control register 1 */
typedef union {
	struct{
		UINT8	te_u4c1:1;
		UINT8	ti_u4c1:1;
		UINT8	re_u4c1:1;
		UINT8	ri_u4c1:1;
		UINT8	u4irs_u4c1:1;
		UINT8	u4rrm_u4c1:1;
		UINT8	u4lch_u4c1:1;
		UINT8	u4ere_u4c1:1;
	} bit;
	 UINT8 byte;
} U4C1_ADDR;
U4C1_ADDR	u4c1_addr;

#define		U4C1		u4c1_addr.byte

#define		TE_U4C1		u4c1_addr.bit.te_u4c1
#define		TI_U4C1		u4c1_addr.bit.ti_u4c1
#define		RE_U4C1		u4c1_addr.bit.re_u4c1
#define		RI_U4C1		u4c1_addr.bit.ri_u4c1
#define		U4IRS_U4C1	u4c1_addr.bit.u4irs_u4c1
#define		U4RRM_U4C1	u4c1_addr.bit.u4rrm_u4c1
#define		U4LCH_U4C1	u4c1_addr.bit.u4lch_u4c1
#define		U4ERE_U4C1	u4c1_addr.bit.u4ere_u4c1

/*------------------------------------------------------
     u4rb
------------------------------------------------------*/
#pragma ADDRESS     u4rb_addr   02feH       /* UART4 receive buffer register */
typedef union {
    struct{
        UINT8    b0:1;
        UINT8    b1:1;
        UINT8    b2:1;
        UINT8    b3:1;
        UINT8    b4:1;
        UINT8    b5:1;
        UINT8    b6:1;
        UINT8    b7:1;
        UINT8    b8:1;
        UINT8    b9:1;
        UINT8    b10:1;
        UINT8    abt:1;              /* Arbitration lost detecting flag */
        UINT8    oer:1;              /* Overrun error flag */
        UINT8    fer:1;              /* Framing error flag */
        UINT8    per:1;              /* Parity error flag */
        UINT8    sum:1;              /* Error sum flag */
    } bit;
    struct{
        UINT8    low;                /* Low  8 bit */
        UINT8    high;               /* High 8 bit */
    } byte;
    UINT16  word;
} U4RB_ADDR;
U4RB_ADDR	u4rb_addr;

#define		U4RB        u4rb_addr.word
#define		U4RBL       u4rb_addr.byte.low
#define		U4RBH       u4rb_addr.byte.high

#define		ABT_U4RB    u4rb_addr.bit.abt   /* Arbitration lost detecting flag */
#define		OER_U4RB    u4rb_addr.bit.oer   /* Overrun error flag */
#define		FER_U4RB    u4rb_addr.bit.fer   /* Framing error flag */
#define		PER_U4RB    u4rb_addr.bit.per   /* Parity error flag */
#define		SUM_U4RB    u4rb_addr.bit.sum   /* Error sum flag */

/*------------------------------------------------------
    Timer B3,4,5 count start flag
------------------------------------------------------*/
#pragma ADDRESS     tbsr_addr   0300H       /* Timer B3,4,5 count start flag */
typedef union {
	struct{
		UINT8	b0:1;
		UINT8	b1:1;
		UINT8	b2:1;
		UINT8	b3:1;
		UINT8	b4:1;
		UINT8	tb3s:1;
		UINT8	tb4s:1;
		UINT8	tb5s:1;
	} bit;
	 UINT8 byte;
} TBSR_ADDR;
TBSR_ADDR	tbsr_addr;

#define		TBSR		tbsr_addr.byte

#define		TB3S		tbsr_addr.bit.tb3s
#define		TB4S		tbsr_addr.bit.tb4s
#define		TB5S		tbsr_addr.bit.tb5s

/*---------------------------------------------------------------------
    Timer A1-1 registers ; Read and write to this register in 16-bit units.
-----------------------------------------------------------------------*/
#pragma ADDRESS     ta11_addr   0302H       /* Timer A1-1 register */
UINT16   ta11_addr;             /* Timer A1-1 register */

#define		TA11     ta11_addr

/*---------------------------------------------------------------------
    Timer A2-1 registers ; Read and write to this register in 16-bit units.
-----------------------------------------------------------------------*/
#pragma ADDRESS     ta21_addr   0304H       /* Timer A2-1 register */
UINT16   ta21_addr;             /* Timer A2-1 register */

#define		TA21     ta21_addr

/*---------------------------------------------------------------------
    Timer A4-1 registers ; Read and write to this register in 16-bit units.
-----------------------------------------------------------------------*/
#pragma ADDRESS     ta41_addr   0306H       /* Timer A4-1 register */
UINT16   ta41_addr;             /* Timer A4-1 register */

#define		TA41     ta41_addr

/*------------------------------------------------------
    Three-phase PWM control regester 0
------------------------------------------------------*/
#pragma ADDRESS     invc0_addr  0308H       /* Three-phase PWM control regester 0 */
typedef union {
	struct{
		UINT8	inv00:1;
		UINT8	inv01:1;
		UINT8	inv02:1;
		UINT8	inv03:1;
		UINT8	inv04:1;
		UINT8	inv05:1;
		UINT8	inv06:1;
		UINT8	inv07:1;
	} bit;
	 UINT8 byte;
} INVC0_ADDR;
INVC0_ADDR	invc0_addr;

#define		INVC0		invc0_addr.byte

#define		INV00		invc0_addr.bit.inv00
#define		INV01		invc0_addr.bit.inv01
#define		INV02		invc0_addr.bit.inv02
#define		INV03		invc0_addr.bit.inv03
#define		INV04		invc0_addr.bit.inv04
#define		INV05		invc0_addr.bit.inv05
#define		INV06		invc0_addr.bit.inv06
#define		INV07		invc0_addr.bit.inv07

/*------------------------------------------------------
    Three-phase PWM control regester 1
------------------------------------------------------*/
#pragma ADDRESS     invc1_addr  0309H       /* Three-phase PWM control register 1 */
typedef union {
	struct{
		UINT8	inv10:1;
		UINT8	inv11:1;
		UINT8	inv12:1;
		UINT8	inv13:1;
		UINT8	inv14:1;
		UINT8	inv15:1;
		UINT8	b6:1;
		UINT8	inv17:1;
	} bit;
	 UINT8 byte;
} INVC1_ADDR;
INVC1_ADDR	invc1_addr;

#define		INVC1		invc1_addr.byte

#define		INV10		invc1_addr.bit.inv10
#define		INV11		invc1_addr.bit.inv11
#define		INV12		invc1_addr.bit.inv12
#define		INV13		invc1_addr.bit.inv13
#define		INV14		invc1_addr.bit.inv14
#define		INV15		invc1_addr.bit.inv15
#define		INV17		invc1_addr.bit.inv17

/*------------------------------------------------------
    Three-phase output buffer register 0
------------------------------------------------------*/
#pragma ADDRESS     idb0_addr   030aH       /* Three-phase output buffer register 0 */
typedef union {
	struct{
		UINT8	du0:1;
		UINT8	dub0:1;
		UINT8	dv0:1;
		UINT8	dvb0:1;
		UINT8	dw0:1;
		UINT8	dwb0:1;
		UINT8	b6:1;
		UINT8	b7:1;
	} bit;
	 UINT8 byte;
} IDB0_ADDR;
IDB0_ADDR	idb0_addr;

#define		IDB0		idb0_addr.byte

#define		DU0			idb0_addr.bit.du0
#define		DUB0		idb0_addr.bit.dub0
#define		DV0			idb0_addr.bit.dv0
#define		DVB0		idb0_addr.bit.dvb0
#define		DW0			idb0_addr.bit.dw0
#define		DWB0		idb0_addr.bit.dwb0

/*------------------------------------------------------
    Three-phase output buffer register 1
------------------------------------------------------*/
#pragma ADDRESS     idb1_addr   030bH       /* Three-phase output buffer register 1 */
typedef union {
	struct{
		UINT8	du1:1;
		UINT8	dub1:1;
		UINT8	dv1:1;
		UINT8	dvb1:1;
		UINT8	dw1:1;
		UINT8	dwb1:1;
		UINT8	b6:1;
		UINT8	b7:1;
	} bit;
	 UINT8 byte;
} IDB1_ADDR;
IDB1_ADDR	idb1_addr;

#define		IDB1		idb1_addr.byte

#define		DU1			idb1_addr.bit.du1
#define		DUB1		idb1_addr.bit.dub1
#define		DV1			idb1_addr.bit.dv1
#define		DVB1		idb1_addr.bit.dvb1
#define		DW1			idb1_addr.bit.dw1
#define		DWB1		idb1_addr.bit.dwb1

/*------------------------------------------------------
     Dead time timer ; Use "MOV" instruction when writing to this register.
------------------------------------------------------*/
#pragma ADDRESS     dtt_addr    030cH       /* Dead time timer */
typedef union {
	struct{
		UINT8	b0:1;
		UINT8	b1:1;
		UINT8	b2:1;
		UINT8	b3:1;
		UINT8	b4:1;
		UINT8	b5:1;
		UINT8	b6:1;
		UINT8	b7:1;
	} bit;
	 UINT8 byte;
} DTT_ADDR;
DTT_ADDR	dtt_addr;

#define		DTT			dtt_addr.byte

/*------------------------------------------------------
    Timer B2 interrupt occurrences frequency set counter ; Use "MOV" instruction when writing to this register.
------------------------------------------------------*/
#pragma ADDRESS     ictb2_addr  030dH       /* Timer B2 interrupt occurences frequency set counter */
typedef union {
	struct{
		UINT8	b0:1;
		UINT8	b1:1;
		UINT8	b2:1;
		UINT8	b3:1;
		UINT8	b4:1;
		UINT8	b5:1;
		UINT8	b6:1;
		UINT8	b7:1;
	} bit;
	 UINT8 byte;
} ICTB2_ADDR;
ICTB2_ADDR	ictb2_addr;

#define		ICTB2		ictb2_addr.byte

/*---------------------------------------------------------------------
    Timer B3 registers ; Read and write to this register in 16-bit units.
-----------------------------------------------------------------------*/
#pragma ADDRESS     tb3_addr    0310H       /* Timer B3 register */
UINT16   tb3_addr;              /* Timer B3 register */

#define		TB3     tb3_addr

/*---------------------------------------------------------------------
    Timer B4 registers ; Read and write to this register in 16-bit units.
-----------------------------------------------------------------------*/
#pragma ADDRESS     tb4_addr    0312H       /* Timer B4 register */
UINT16   tb4_addr;              /* Timer B4 register */

#define		TB4     tb4_addr

/*---------------------------------------------------------------------
    Timer B5 registers ; Read and write to this register in 16-bit units.
-----------------------------------------------------------------------*/
#pragma ADDRESS     tb5_addr    0314H       /* Timer B5 register */
UINT16   tb5_addr;              /* Timer B5 register */

#define		TB5     tb5_addr

/*------------------------------------------------------
     Timer B3 mode registers
------------------------------------------------------*/
#pragma ADDRESS     tb3mr_addr  031bH       /* Timer B3 mode register */
typedef union {
    struct{
        UINT8    tmod0:1;        /* Operation mode select bit */
        UINT8    tmod1:1;        /* Operation mode select bit */
        UINT8    mr0:1;
        UINT8    mr1:1;
        UINT8    mr2:1;
        UINT8    mr3:1;
        UINT8    tck0:1;         /* Count source select bit */
        UINT8    tck1:1;         /* Count source select bit */
    } bit;
    UINT8    byte;
} TB3MR_ADDR;
TB3MR_ADDR	tb3mr_addr;

#define		TB3MR       tb3mr_addr.byte

#define		TMOD0_TB3MR tb3mr_addr.bit.tmod0    /* Operation mode select bit */
#define		TMOD1_TB3MR tb3mr_addr.bit.tmod1    /* Operation mode select bit */
#define		MR0_TB3MR   tb3mr_addr.bit.mr0
#define		MR1_TB3MR   tb3mr_addr.bit.mr1
#define		MR2_TB3MR   tb3mr_addr.bit.mr2
#define		MR3_TB3MR   tb3mr_addr.bit.mr3
#define		TCK0_TB3MR  tb3mr_addr.bit.tck0 /* Count source select bit */
#define		TCK1_TB3MR  tb3mr_addr.bit.tck1 /* Count source select bit */

/*------------------------------------------------------
     Timer B4 mode registers
------------------------------------------------------*/
#pragma ADDRESS     tb4mr_addr  031cH       /* Timer B4 mode register */
typedef union {
    struct{
        UINT8    tmod0:1;        /* Operation mode select bit */
        UINT8    tmod1:1;        /* Operation mode select bit */
        UINT8    mr0:1;
        UINT8    mr1:1;
        UINT8    mr2:1;
        UINT8    mr3:1;
        UINT8    tck0:1;         /* Count source select bit */
        UINT8    tck1:1;         /* Count source select bit */
    } bit;
    UINT8    byte;
} TB4MR_ADDR;
TB4MR_ADDR	tb4mr_addr;

#define		TB4MR       tb4mr_addr.byte

#define		TMOD0_TB4MR tb4mr_addr.bit.tmod0    /* Operation mode select bit */
#define		TMOD1_TB4MR tb4mr_addr.bit.tmod1    /* Operation mode select bit */
#define		MR0_TB4MR   tb4mr_addr.bit.mr0
#define		MR1_TB4MR   tb4mr_addr.bit.mr1
#define		MR2_TB4MR	tb4mr_addr.bit.mr2
#define		MR3_TB4MR   tb4mr_addr.bit.mr3
#define		TCK0_TB4MR  tb4mr_addr.bit.tck0 /* Count source select bit */
#define		TCK1_TB4MR  tb4mr_addr.bit.tck1 /* Count source select bit */

/*------------------------------------------------------
     Timer B5 mode registers
------------------------------------------------------*/
#pragma ADDRESS     tb5mr_addr  031dH       /* Timer B5 mode register */
typedef union {
    struct{
        UINT8    tmod0:1;        /* Operation mode select bit */
        UINT8    tmod1:1;        /* Operation mode select bit */
        UINT8    mr0:1;
        UINT8    mr1:1;
        UINT8    mr2:1;
        UINT8    mr3:1;
        UINT8    tck0:1;         /* Count source select bit */
        UINT8    tck1:1;         /* Count source select bit */
    } bit;
    UINT8    byte;
} TB5MR_ADDR;
TB5MR_ADDR	tb5mr_addr;

#define		TB5MR       tb5mr_addr.byte

#define		TMOD0_TB5MR tb5mr_addr.bit.tmod0    /* Operation mode select bit */
#define		TMOD1_TB5MR tb5mr_addr.bit.tmod1    /* Operation mode select bit */
#define		MR0_TB5MR   tb5mr_addr.bit.mr0
#define		MR1_TB5MR   tb5mr_addr.bit.mr1
#define		MR2_TB5MR	tb5mr_addr.bit.mr2
#define		MR3_TB5MR   tb5mr_addr.bit.mr3
#define		TCK0_TB5MR  tb5mr_addr.bit.tck0 /* Count source select bit */
#define		TCK1_TB5MR  tb5mr_addr.bit.tck1 /* Count source select bit */

/*------------------------------------------------------
    Interrupt cause select register
------------------------------------------------------*/
#pragma ADDRESS     ifsr_addr   031fH       /* Interrupt cause select register */
typedef union {
	struct{
		UINT8	ifsr0:1;
		UINT8	ifsr1:1;
		UINT8	ifsr2:1;
		UINT8	ifsr3:1;
		UINT8	ifsr4:1;
		UINT8	ifsr5:1;
		UINT8	ifsr6:1;
		UINT8	ifsr7:1;
	} bit;
	 UINT8 byte;
} IFSR_ADDR;
IFSR_ADDR	ifsr_addr;

#define		IFSR		ifsr_addr.byte

#define		IFSR0		ifsr_addr.bit.ifsr0
#define		IFSR1		ifsr_addr.bit.ifsr1
#define		IFSR2		ifsr_addr.bit.ifsr2
#define		IFSR3		ifsr_addr.bit.ifsr3
#define		IFSR4		ifsr_addr.bit.ifsr4
#define		IFSR5		ifsr_addr.bit.ifsr5
#define		IFSR6		ifsr_addr.bit.ifsr6
#define		IFSR7		ifsr_addr.bit.ifsr7

/*------------------------------------------------------
     u3smr4
------------------------------------------------------*/
#pragma ADDRESS     u3smr4_addr 0324H       /* UART3 special mode register 4 */
typedef union {
    struct{
        UINT8    stareq:1;
        UINT8    rstareq:1;
        UINT8    stpreq:1;
        UINT8    stspsel:1;
        UINT8    ackd:1;
        UINT8    ackc:1;
        UINT8    sclhi:1;
        UINT8    swc9:1;
    } bit;
    UINT8    byte;
} U3SMR4_ADDR;
U3SMR4_ADDR	u3smr4_addr;

#define		U3SMR4      u3smr4_addr.byte

#define		STAREQ_U3SMR4  u3smr4_addr.bit.stareq
#define		RSTAREQ_U3SMR4 u3smr4_addr.bit.rstareq
#define		STPREQ_U3SMR4 u3smr4_addr.bit.stpreq
#define		STSPSEL_U3SMR4 u3smr4_addr.bit.stspsel
#define		ACKD_U3SMR4  u3smr4_addr.bit.ackd
#define		ACKC_U3SMR4  u3smr4_addr.bit.ackc
#define		SCLHI_U3SMR4  u3smr4_addr.bit.sclhi
#define		SWC9_U3SMR4  u3smr4_addr.bit.swc9

/*------------------------------------------------------
     u3smr3
------------------------------------------------------*/
#pragma ADDRESS     u3smr3_addr 0325H       /* UART3 special mode register 3 */
typedef union {
    struct{
        UINT8    sse:1;
        UINT8    ckph:1;
        UINT8    dinc:1;
        UINT8    nodc:1;
        UINT8    err:1;
        UINT8    dl0:1;
        UINT8    dl1:1;
        UINT8    dl2:1;
    } bit;
    UINT8    byte;
} U3SMR3_ADDR;
U3SMR3_ADDR	u3smr3_addr;

#define		U3SMR3      u3smr3_addr.byte

#define		SSE_U3SMR3  u3smr3_addr.bit.sse
#define		CKPH_U3SMR3 u3smr3_addr.bit.ckph
#define		DINC_U3SMR3 u3smr3_addr.bit.dinc
#define		NODC_U3SMR3 u3smr3_addr.bit.nodc
#define		ERR_U3SMR3  u3smr3_addr.bit.err
#define		DL0_U3SMR3  u3smr3_addr.bit.dl0
#define		DL1_U3SMR3  u3smr3_addr.bit.dl1
#define		DL2_U3SMR3  u3smr3_addr.bit.dl2

/*------------------------------------------------------
     u3smr2
------------------------------------------------------*/
#pragma ADDRESS     u3smr2_addr 0326H       /* UART3 special mode register 2 */
typedef union {
    struct{
        UINT8    iicm2:1;
        UINT8    csc:1;
        UINT8    swc:1;
        UINT8    als:1;
        UINT8    stc:1;
        UINT8    swc2:1;
        UINT8    sdhi:1;
        UINT8    shtc:1;
    } bit;
    UINT8    byte;
} U3SMR2_ADDR;
U3SMR2_ADDR	u3smr2_addr;

#define		U3SMR2      u3smr2_addr.byte

#define		IICM2_U3SMR2    u3smr2_addr.bit.iicm2
#define		CSC_U3SMR2  u3smr2_addr.bit.csc
#define		SWC_U3SMR2  u3smr2_addr.bit.swc
#define		ALS_U3SMR2  u3smr2_addr.bit.als
#define		STC_U3SMR2  u3smr2_addr.bit.stc
#define		SWC2_U3SMR2 u3smr2_addr.bit.swc2
#define		SDHI_U3SMR2 u3smr2_addr.bit.sdhi
#define		SU1HIM_U3SMR2 u3smr2_addr.bit.shtc

/*------------------------------------------------------
     u3smr
------------------------------------------------------*/
#pragma ADDRESS     u3smr_addr  0327H       /* UART3 special mode register */
typedef union {
    struct{
        UINT8    iicm:1;
        UINT8    abc:1;
        UINT8    bbs:1;
        UINT8    lsyn:1;
        UINT8    abscs:1;
        UINT8    acse:1;
        UINT8    sss:1;
        UINT8    su1him:1;
    } bit;
    UINT8    byte;
} U3SMR_ADDR;
U3SMR_ADDR	u3smr_addr;

#define		U3SMR       u3smr_addr.byte

#define		IICM_U3SMR  u3smr_addr.bit.iicm
#define		ABC_U3SMR   u3smr_addr.bit.abc
#define		BBS_U3SMR   u3smr_addr.bit.bbs
#define		LSYN_U3SMR  u3smr_addr.bit.lsyn
#define		ABSCS_U3SMR u3smr_addr.bit.abscs
#define		ACSE_U3SMR  u3smr_addr.bit.acse
#define		SSS_U3SMR   u3smr_addr.bit.sss
#define		SCLKDIV_U3SMR   u3smr_addr.bit.su1him

/*------------------------------------------------------
     u3mr
------------------------------------------------------*/
#pragma ADDRESS     u3mr_addr   0328H       /* UART3 transmit/receive mode register */
typedef union {
    struct{
        UINT8    smd0:1;             /* Serial I/O mode select bit */
        UINT8    smd1:1;             /* Serial I/O mode select bit */
        UINT8    smd2:1;             /* Serial I/O mode select bit */
        UINT8    ckdir:1;            /* Internal/external clock select bit */
        UINT8    stps:1;             /* Stop bit length select bit */
        UINT8    pry:1;              /* Odd/even parity select bit */
        UINT8    prye:1;             /* Parity enable bit */
        UINT8    iopol:1;            /* TxD RxD I/O polarity reverse bit */
    } bit;
    UINT8    byte;
} U3MR_ADDR;
U3MR_ADDR	u3mr_addr;

#define		U3MR        u3mr_addr.byte

#define		SMD0_U3MR   u3mr_addr.bit.smd0  /* Serial I/O mode select bit */
#define		SMD1_U3MR   u3mr_addr.bit.smd1  /* Serial I/O mode select bit */
#define		SMD2_U3MR   u3mr_addr.bit.smd2  /* Serial I/O mode select bit */
#define		CKDIR_U3MR  u3mr_addr.bit.ckdir /* Internal/external clock select bit */
#define		STPS_U3MR   u3mr_addr.bit.stps  /* Stop bit length select bit */
#define		PRY_U3MR    u3mr_addr.bit.pry   /* Odd/even parity select bit */
#define		PRYE_U3MR   u3mr_addr.bit.prye  /* Parity enable bit */
#define		IOPOL_U3MR  u3mr_addr.bit.iopol  /* TxD RxD I/O polarity reverse bit */

/*------------------------------------------------------
    UARTi bit rate generators ; Use "MOV" instruction when writing to these registers.
------------------------------------------------------*/
#pragma ADDRESS     u3brg_addr  0329H       /* UART3 bit rate generator */
UINT8 u3brg_addr;

#define		U3BRG       u3brg_addr

/*----------------------------------------------------*/
#pragma ADDRESS     u3tb_addr   032aH       /* UART3 transmit buffer register */
typedef union {
    struct{
        UINT8    b0:1;
        UINT8    b1:1;
        UINT8    b2:1;
        UINT8    b3:1;
        UINT8    b4:1;
        UINT8    b5:1;
        UINT8    b6:1;
        UINT8    b7:1;
        UINT8    b8:1;
        UINT8    b9:1;
        UINT8    b10:1;
        UINT8    b11:1;
        UINT8    b12:1;
        UINT8    b13:1;
        UINT8    b14:1;
        UINT8    b15:1;
    } bit;
    struct{
        UINT8    low;                /* low  8 bit */
        UINT8    high;               /* high 8 bit */
    } byte;
    UINT16  word;
} U3TB_ADDR;
U3TB_ADDR	u3tb_addr;

#define		U3TB    u3tb_addr.word          /* UART3 Transmit buffer register 16 bit ; Use "MOV" instruction when writing to this register. */
#define		U3TBL   u3tb_addr.byte.low          /* UART3 Transmit buffer register low  8 bit */
#define		U3TBH   u3tb_addr.byte.high         /* UART3 Transmit buffer register high 8 bit */

/*------------------------------------------------------
     u3c0
------------------------------------------------------*/
#pragma ADDRESS     u3c0_addr   032cH       /* UART3 transmit/receive control register 0 */
typedef union {
    struct{
        UINT8    clk0:1;         /* BRG count source select bit */
        UINT8    clk1:1;         /* BRG count source select bit */
        UINT8    crs:1;          /* CTS~/RTS~ function select bit */
        UINT8    txept:1;        /* Transmit register empty flag */
        UINT8    crd:1;          /* CTS~/RTS~ disable bit */
        UINT8    nch:1;          /* Data output select bit */
        UINT8    ckpol:1;        /* CLK polarity select bit */
        UINT8    uform:1;        /* Transfer format select bit */
    } bit;
    UINT8    byte;
} U3C0_ADDR;
U3C0_ADDR	u3c0_addr;

#define		U3C0        u3c0_addr.byte

#define		CLK0_U3C0   u3c0_addr.bit.clk0  /* BRG count source select bit */
#define		CLK1_U3C0   u3c0_addr.bit.clk1  /* BRG count source select bit */
#define		CRS_U3C0    u3c0_addr.bit.crs   /* CTS~/RTS~ function select bit */
#define		TXEPT_U3C0  u3c0_addr.bit.txept /* Transmit register empty flag */
#define		CRD_U3C0    u3c0_addr.bit.crd   /* CTS~/RTS~ disable bit */
#define		NCH_U3C0    u3c0_addr.bit.nch   /* Data output select bit */
#define		CKPOL_U3C0  u3c0_addr.bit.ckpol /* CLK polarity select bit */
#define		UFORM_U3C0  u3c0_addr.bit.uform /* Transfer format select bit */

/*------------------------------------------------------
    UART3 transmit/receive control register 1
------------------------------------------------------*/
#pragma ADDRESS     u3c1_addr   032dH       /* UART3 transmit/receive control register 1 */
typedef union {
	struct{
		UINT8	te_u3c1:1;
		UINT8	ti_u3c1:1;
		UINT8	re_u3c1:1;
		UINT8	ri_u3c1:1;
		UINT8	u3irs_u3c1:1;
		UINT8	u3rrm_u3c1:1;
		UINT8	u3lch_u3c1:1;
		UINT8	u3ere_u3c1:1;
	} bit;
	 UINT8 byte;
} U3C1_ADDR;
U3C1_ADDR	u3c1_addr;

#define		U3C1		u3c1_addr.byte

#define		TE_U3C1		u3c1_addr.bit.te_u3c1
#define		TI_U3C1		u3c1_addr.bit.ti_u3c1
#define		RE_U3C1		u3c1_addr.bit.re_u3c1
#define		RI_U3C1		u3c1_addr.bit.ri_u3c1
#define		U3IRS_U3C1	u3c1_addr.bit.u3irs_u3c1
#define		U3RRM_U3C1	u3c1_addr.bit.u3rrm_u3c1
#define		U3LCH_U3C1	u3c1_addr.bit.u3lch_u3c1
#define		U3ERE_U3C1	u3c1_addr.bit.u3ere_u3c1

/*------------------------------------------------------
    UART3 receive buffer register
------------------------------------------------------*/
#pragma ADDRESS     u3rb_addr   032eH       /* UART3 receive buffer register */
typedef union {
    struct{
        UINT8    b0:1;
        UINT8    b1:1;
        UINT8    b2:1;
        UINT8    b3:1;
        UINT8    b4:1;
        UINT8    b5:1;
        UINT8    b6:1;
        UINT8    b7:1;
        UINT8    b8:1;
        UINT8    b9:1;
        UINT8    b10:1;
        UINT8    abt:1;              /* Arbitration lost detecting flag */
        UINT8    oer:1;              /* Overrun error flag */
        UINT8    fer:1;              /* Framing error flag */
        UINT8    per:1;              /* Parity error flag */
        UINT8    sum:1;              /* Error sum flag */
    } bit;
    struct{
        UINT8    low;                /* Low  8 bit */
        UINT8    high;               /* High 8 bit */
    } byte;
    UINT16  word;
} U3RB_ADDR;
U3RB_ADDR	u3rb_addr;

#define		U3RB        u3rb_addr.word
#define		U3RBL       u3rb_addr.byte.low
#define		U3RBH       u3rb_addr.byte.high

#define		ABT_U3RB    u3rb_addr.bit.abt   /* Arbitration lost detecting flag */
#define		OER_U3RB    u3rb_addr.bit.oer   /* Overrun error flag */
#define		FER_U3RB    u3rb_addr.bit.fer   /* Framing error flag */
#define		PER_U3RB    u3rb_addr.bit.per   /* Parity error flag */
#define		SUM_U3RB    u3rb_addr.bit.sum   /* Error sum flag */

/*------------------------------------------------------
    UART2 special mode register 4
------------------------------------------------------*/
#pragma ADDRESS     u2smr4_addr 0334H       /* UART2 special mode register 4 */ 
typedef union {
    struct{
        UINT8    stareq:1;
        UINT8    rstareq:1;
        UINT8    stpreq:1;
        UINT8    stspsel:1;
        UINT8    ackd:1;
        UINT8    ackc:1;
        UINT8    sclhi:1;
        UINT8    swc9:1;
    } bit;
    UINT8    byte;
} U2SMR4_ADDR;
U2SMR4_ADDR	u2smr4_addr;

#define		U2SMR4      u2smr4_addr.byte

#define		STAREQ_U2SMR4  u2smr4_addr.bit.stareq
#define		RSTAREQ_U2SMR4 u2smr4_addr.bit.rstareq
#define		STPREQ_U2SMR4 u2smr4_addr.bit.stpreq
#define		STSPSEL_U2SMR4 u2smr4_addr.bit.stspsel
#define		ACKD_U2SMR4  u2smr4_addr.bit.ackd
#define		ACKC_U2SMR4  u2smr4_addr.bit.ackc
#define		SCLHI_U2SMR4  u2smr4_addr.bit.sclhi
#define		SWC9_U2SMR4  u2smr4_addr.bit.swc9

/*------------------------------------------------------
    UART2 special mode register 3
------------------------------------------------------*/
#pragma ADDRESS     u2smr3_addr 0335H       /* UART2 special mode register 3 */ 
typedef union {
    struct{
        UINT8    sse:1;
        UINT8    ckph:1;
        UINT8    dinc:1;
        UINT8    nodc:1;
        UINT8    err:1;
        UINT8    dl0:1;
        UINT8    dl1:1;
        UINT8    dl2:1;
    } bit;
    UINT8    byte;
} U2SMR3_ADDR;
U2SMR3_ADDR	u2smr3_addr;

#define		U2SMR3      u2smr3_addr.byte

#define		SSE_U2SMR3  u2smr3_addr.bit.sse
#define		CKPH_U2SMR3 u2smr3_addr.bit.ckph
#define		DINC_U2SMR3 u2smr3_addr.bit.dinc
#define		NODC_U2SMR3 u2smr3_addr.bit.nodc
#define		ERR_U2SMR3  u2smr3_addr.bit.err
#define		DL0_U2SMR3  u2smr3_addr.bit.dl0
#define		DL1_U2SMR3  u2smr3_addr.bit.dl1
#define		DL2_U2SMR3  u2smr3_addr.bit.dl2

/*------------------------------------------------------
    UART2 special mode register 2
------------------------------------------------------*/
#pragma ADDRESS     u2smr2_addr 0336H       /* UART2 special mode register 2 */
typedef union {
    struct{
        UINT8    iicm2:1;
        UINT8    csc:1;
        UINT8    swc:1;
        UINT8    als:1;
        UINT8    stc:1;
        UINT8    swc2:1;
        UINT8    sdhi:1;
        UINT8    shtc:1;
    } bit;
    UINT8    byte;
} U2SMR2_ADDR;
U2SMR2_ADDR	u2smr2_addr;

#define		U2SMR2      u2smr2_addr.byte

#define		IICM2_U2SMR2    u2smr2_addr.bit.iicm2
#define		CSC_U2SMR2  u2smr2_addr.bit.csc
#define		SWC_U2SMR2  u2smr2_addr.bit.swc
#define		ALS_U2SMR2  u2smr2_addr.bit.als
#define		STC_U2SMR2  u2smr2_addr.bit.stc 
#define		SWC2_U2SMR2 u2smr2_addr.bit.swc2
#define		SDHI_U2SMR2 u2smr2_addr.bit.sdhi
#define		SU1HIM_U2SMR2 u2smr2_addr.bit.shtc

/*------------------------------------------------------
    UART2 special mode registers
------------------------------------------------------*/
#pragma ADDRESS     u2smr_addr  0337H       /* UART2 special mode register */
typedef union {
    struct{
        UINT8    iicm:1;
        UINT8    abc:1;
        UINT8    bbs:1;
        UINT8    lsyn:1;
        UINT8    abscs:1;
        UINT8    acse:1;
        UINT8    sss:1;
        UINT8    su1him:1;
    } bit;
    UINT8    byte;
} U2SMR_ADDR;
U2SMR_ADDR	u2smr_addr;

#define		U2SMR       u2smr_addr.byte

#define		IICM_U2SMR  u2smr_addr.bit.iicm 
#define		ABC_U2SMR   u2smr_addr.bit.abc
#define		BBS_U2SMR   u2smr_addr.bit.bbs
#define		LSYN_U2SMR  u2smr_addr.bit.lsyn
#define		ABSCS_U2SMR u2smr_addr.bit.abscs
#define		ACSE_U2SMR  u2smr_addr.bit.acse
#define		SSS_U2SMR   u2smr_addr.bit.sss
#define		SCLKDIV_U2SMR   u2smr_addr.bit.su1him

/*------------------------------------------------------
    UART2 transmit/receive mode registers
------------------------------------------------------*/
#pragma ADDRESS     u2mr_addr   0338H       /* UART2 transmit/receive mode register */
typedef union {
    struct{
        UINT8    smd0:1;             /* Serial I/O mode select bit */
        UINT8    smd1:1;             /* Serial I/O mode select bit */
        UINT8    smd2:1;             /* Serial I/O mode select bit */
        UINT8    ckdir:1;            /* Internal/external clock select bit */
        UINT8    stps:1;             /* Stop bit length select bit */
        UINT8    pry:1;              /* Odd/even parity select bit */
        UINT8    prye:1;             /* Parity enable bit */
        UINT8    iopol:1;            /* TxD RxD I/O polarity reverse bit */
    } bit;
    UINT8    byte;
} U2MR_ADDR;
U2MR_ADDR	u2mr_addr;

#define		U2MR        u2mr_addr.byte

#define		SMD0_U2MR   u2mr_addr.bit.smd0  /* Serial I/O mode select bit */
#define		SMD1_U2MR   u2mr_addr.bit.smd1  /* Serial I/O mode select bit */
#define		SMD2_U2MR   u2mr_addr.bit.smd2  /* Serial I/O mode select bit */
#define		CKDIR_U2MR  u2mr_addr.bit.ckdir /* Internal/external clock select bit */
#define		STPS_U2MR   u2mr_addr.bit.stps  /* Stop bit length select bit */
#define		PRY_U2MR    u2mr_addr.bit.pry   /* Odd/even parity select bit */
#define		PRYE_U2MR   u2mr_addr.bit.prye  /* Parity enable bit */
#define		IOPOL_U2MR  u2mr_addr.bit.iopol  /* TxD RxD I/O polarity reverse bit */

/*------------------------------------------------------
    UART2 bit rate generators ; Use "MOV" instruction when writing to these registers.
------------------------------------------------------*/
#pragma ADDRESS     u2brg_addr  0339H       /* UART2 bit rate generator */
UINT8 u2brg_addr;

#define		U2BRG       u2brg_addr

/*----------------------------------------------------*/
#pragma ADDRESS     u2tb_addr   033aH       /* UART2 transmit buffer register */
typedef union {
    struct{
        UINT8    b0:1;
        UINT8    b1:1;
        UINT8    b2:1;
        UINT8    b3:1;
        UINT8    b4:1;
        UINT8    b5:1;
        UINT8    b6:1;
        UINT8    b7:1;
        UINT8    b8:1;
        UINT8    b9:1;
        UINT8    b10:1;
        UINT8    b11:1;
        UINT8    b12:1;
        UINT8    b13:1;
        UINT8    b14:1;
        UINT8    b15:1;
    } bit;
    struct{
        UINT8    low;                /* low  8 bit */
        UINT8    high;               /* high 8 bit */
    } byte;
    UINT16  word;
} U2TB_ADDR;
U2TB_ADDR	u2tb_addr;

#define		U2TB    u2tb_addr.word          /* UART2 Transmit buffer register 16 bit ; Use "MOV" instruction when writing to this register. */
#define		U2TBL   u2tb_addr.byte.low          /* UART2 Transmit buffer register low  8 bit */
#define		U2TBH   u2tb_addr.byte.high         /* UART2 Transmit buffer register high 8 bit */

/*------------------------------------------------------
    UART2 transmit/receive control register 0
------------------------------------------------------*/
#pragma ADDRESS     u2c0_addr   033cH       /* UART2 transmit/receive control register 0 */
typedef union {
    struct{
        UINT8    clk0:1;         /* BRG count source select bit */
        UINT8    clk1:1;         /* BRG count source select bit */
        UINT8    crs:1;          /* CTS~/RTS~ function select bit */
        UINT8    txept:1;        /* Transmit register empty flag */
        UINT8    crd:1;          /* CTS~/RTS~ disable bit */
        UINT8    nch:1;          /* Data output select bit */
        UINT8    ckpol:1;        /* CLK polarity select bit */
        UINT8    uform:1;        /* Transfer format select bit */
    } bit;
    UINT8    byte;
} U2C0_ADDR;
U2C0_ADDR	u2c0_addr;

#define		U2C0        u2c0_addr.byte

#define		CLK0_U2C0   u2c0_addr.bit.clk0  /* BRG count source select bit */
#define		CLK1_U2C0   u2c0_addr.bit.clk1  /* BRG count source select bit */
#define		CRS_U2C0    u2c0_addr.bit.crs   /* CTS~/RTS~ function select bit */
#define		TXEPT_U2C0  u2c0_addr.bit.txept /* Transmit register empty flag */
#define		CRD_U2C0    u2c0_addr.bit.crd   /* CTS~/RTS~ disable bit */
#define		CKPOL_U2C0  u2c0_addr.bit.ckpol /* CLK polarity select bit */
#define		UFORM_U2C0  u2c0_addr.bit.uform /* Transfer format select bit */

/*------------------------------------------------------
    UART2 transmit/receive control register 1
------------------------------------------------------*/
#pragma ADDRESS     u2c1_addr   033dH       /* UART2 transmit/receive control register 1 */
typedef union {
	struct{
		UINT8	te_u2c1:1;
		UINT8	ti_u2c1:1;
		UINT8	re_u2c1:1;
		UINT8	ri_u2c1:1;
		UINT8	u2irs_u2c1:1;
		UINT8	u2rrm_u2c1:1;
		UINT8	u2lch_u2c1:1;
		UINT8	u2ere_u2c1:1;
	} bit;
	 UINT8 byte;
} U2C1_ADDR;
U2C1_ADDR	u2c1_addr;

#define		U2C1		u2c1_addr.byte

#define		TE_U2C1		u2c1_addr.bit.te_u2c1
#define		TI_U2C1		u2c1_addr.bit.ti_u2c1
#define		RE_U2C1		u2c1_addr.bit.re_u2c1
#define		RI_U2C1		u2c1_addr.bit.ri_u2c1
#define		U2IRS_U2C1	u2c1_addr.bit.u2irs_u2c1
#define		U2RRM_U2C1	u2c1_addr.bit.u2rrm_u2c1
#define		U2LCH_U2C1	u2c1_addr.bit.u2lch_u2c1
#define		U2ERE_U2C1	u2c1_addr.bit.u2ere_u2c1

/*------------------------------------------------------
    UART2 receive buffer register
------------------------------------------------------*/
#pragma ADDRESS     u2rb_addr   033eH       /* UART2 receive buffer register */
typedef union {
    struct{
        UINT8    b0:1;
        UINT8    b1:1;
        UINT8    b2:1;
        UINT8    b3:1;
        UINT8    b4:1;
        UINT8    b5:1;
        UINT8    b6:1;
        UINT8    b7:1;
        UINT8    b8:1;
        UINT8    b9:1;
        UINT8    b10:1;
        UINT8    abt:1;              /* Arbitration lost detecting flag */
        UINT8    oer:1;              /* Overrun error flag */
        UINT8    fer:1;              /* Framing error flag */
        UINT8    per:1;              /* Parity error flag */
        UINT8    sum:1;              /* Error sum flag */
    } bit;
    struct{
        UINT8    low;                /* Low  8 bit */
        UINT8    high;               /* High 8 bit */
    } byte;
    UINT16  word;
} U2RB_ADDR;
U2RB_ADDR	u2rb_addr;

#define		U2RB        u2rb_addr.word
#define		U2RBL       u2rb_addr.byte.low
#define		U2RBH       u2rb_addr.byte.high

#define		ABT_U2RB    u2rb_addr.bit.abt   /* Arbitration lost detecting flag */
#define		OER_U2RB    u2rb_addr.bit.oer   /* Overrun error flag */
#define		FER_U2RB    u2rb_addr.bit.fer   /* Framing error flag */
#define		PER_U2RB    u2rb_addr.bit.per   /* Parity error flag */
#define		SUM_U2RB    u2rb_addr.bit.sum   /* Error sum flag */

/*------------------------------------------------------
    Count start flag
------------------------------------------------------*/
#pragma ADDRESS     tabsr_addr  0340H       /* Count start flag */
typedef union {
	struct{
		UINT8	ta0s:1;
		UINT8	ta1s:1;
		UINT8	ta2s:1;
		UINT8	ta3s:1;
		UINT8	ta4s:1;
		UINT8	tb0s:1;
		UINT8	tb1s:1;
		UINT8	tb2s:1;
	} bit;
	 UINT8 byte;
} TABSR_ADDR;
TABSR_ADDR	tabsr_addr;

#define		TABSR		tabsr_addr.byte

#define		TA0S		tabsr_addr.bit.ta0s
#define		TA1S		tabsr_addr.bit.ta1s
#define		TA2S		tabsr_addr.bit.ta2s
#define		TA3S		tabsr_addr.bit.ta3s
#define		TA4S		tabsr_addr.bit.ta4s
#define		TB0S		tabsr_addr.bit.tb0s
#define		TB1S		tabsr_addr.bit.tb1s
#define		TB2S		tabsr_addr.bit.tb2s

/*------------------------------------------------------
    Clock prescaler reset flag
------------------------------------------------------*/
#pragma ADDRESS     cpsrf_addr  0341H       /* Clock prescaler reset flag */
typedef union {
	struct{
		UINT8	b0:1;
		UINT8	b1:1;
		UINT8	b2:1;
		UINT8	b3:1;
		UINT8	b4:1;
		UINT8	b5:1;
		UINT8	b6:1;
		UINT8	cpsr:1;
	} bit;
	 UINT8 byte;
} CPSRF_ADDR;
CPSRF_ADDR	cpsrf_addr;

#define		CPSRF		cpsrf_addr.byte

#define		CPSR		cpsrf_addr.bit.cpsr

/*------------------------------------------------------
    One-shot start flag
------------------------------------------------------*/
#pragma ADDRESS     onsf_addr   0342H       /* One-shot start flag */
typedef union {
	struct{
		UINT8	ta0os:1;
		UINT8	ta1os:1;
		UINT8	ta2os:1;
		UINT8	ta3os:1;
		UINT8	ta4os:1;
		UINT8	tazie:1;
		UINT8	ta0tgl:1;
		UINT8	ta0tgh:1;
	} bit;
	 UINT8 byte;
} ONSF_ADDR;
ONSF_ADDR	onsf_addr;

#define		ONSF		onsf_addr.byte

#define		TA0OS		onsf_addr.bit.ta0os
#define		TA1OS		onsf_addr.bit.ta1os
#define		TA2OS		onsf_addr.bit.ta2os
#define		TA3OS		onsf_addr.bit.ta3os
#define		TA4OS		onsf_addr.bit.ta4os
#define		TAZIE		onsf_addr.bit.tazie
#define		TA0TGL		onsf_addr.bit.ta0tgl
#define		TA0TGH		onsf_addr.bit.ta0tgh

/*------------------------------------------------------
    Trigger select register
------------------------------------------------------*/
#pragma ADDRESS     trgsr_addr  0343H       /* Trigger select register */
typedef union {
	struct{
		UINT8	ta1tgl:1;
		UINT8	ta1tgh:1;
		UINT8	ta2tgl:1;
		UINT8	ta2tgh:1;
		UINT8	ta3tgl:1;
		UINT8	ta3tgh:1;
		UINT8	ta4tgl:1;
		UINT8	ta4tgh:1;
	} bit;
	 UINT8 byte;
} TRGSR_ADDR;
TRGSR_ADDR	trgsr_addr;

#define		TRGSR		trgsr_addr.byte

#define		TA1TGL		trgsr_addr.bit.ta1tgl
#define		TA1TGH		trgsr_addr.bit.ta1tgh
#define		TA2TGL		trgsr_addr.bit.ta2tgl
#define		TA2TGH		trgsr_addr.bit.ta2tgh
#define		TA3TGL		trgsr_addr.bit.ta3tgl
#define		TA3TGH		trgsr_addr.bit.ta3tgh
#define		TA4TGL		trgsr_addr.bit.ta4tgl
#define		TA4TGH		trgsr_addr.bit.ta4tgh

/*------------------------------------------------------
    Up Down Flag
------------------------------------------------------*/
#pragma ADDRESS     udf_addr    0344H       /* Up/down flag */
typedef union {
	struct{
		UINT8	ta0ud:1;
		UINT8	ta1ud:1;
		UINT8	ta2ud:1;
		UINT8	ta3ud:1;
		UINT8	ta4ud:1;
		UINT8	ta2p:1;
		UINT8	ta3p:1;
		UINT8	ta4p:1;
	} bit;
	 UINT8 byte;
} UDF_ADDR;
UDF_ADDR	udf_addr;

#define		UDF			udf_addr.byte

#define		TA0UD		udf_addr.bit.ta0ud
#define		TA1UD		udf_addr.bit.ta1ud
#define		TA2UD		udf_addr.bit.ta2ud
#define		TA3UD		udf_addr.bit.ta3ud
#define		TA4UD		udf_addr.bit.ta4ud
#define		TA2P		udf_addr.bit.ta2p
#define		TA3P		udf_addr.bit.ta3p
#define		TA4P		udf_addr.bit.ta4p

/*---------------------------------------------------------------------
    Timer A0 registers ; Read and write to this register in 16-bit units.
-----------------------------------------------------------------------*/
#pragma ADDRESS     ta0_addr    0346H       /* Timer A0 register */
UINT16   ta0_addr;              /* Timer A0 register */

#define		TA0     ta0_addr

/*---------------------------------------------------------------------
    Timer A1 registers ; Read and write to this register in 16-bit units.
-----------------------------------------------------------------------*/
#pragma ADDRESS     ta1_addr    0348H       /* Timer A1 register */
UINT16   ta1_addr;              /* Timer A1 register */

#define		TA1     ta1_addr

/*---------------------------------------------------------------------
    Timer A2 registers ; Read and write to this register in 16-bit units.
-----------------------------------------------------------------------*/
#pragma ADDRESS     ta2_addr    034aH       /* Timer A2 register */
UINT16   ta2_addr;              /* Timer A2 register */

#define		TA2     ta2_addr

/*---------------------------------------------------------------------
    Timer A3 registers ; Read and write to this register in 16-bit units.
-----------------------------------------------------------------------*/
#pragma ADDRESS     ta3_addr    034cH       /* Timer A3 register */
UINT16   ta3_addr;              /* Timer A3 register */

#define		TA3     ta3_addr

/*---------------------------------------------------------------------
    Timer A4 registers ; Read and write to this register in 16-bit units.
-----------------------------------------------------------------------*/
#pragma ADDRESS     ta4_addr    034eH       /* Timer A4 register */
UINT16   ta4_addr;              /* Timer A4 register */

#define		TA4     ta4_addr

/*---------------------------------------------------------------------
    Timer B0 registers ; Read and write to this register in 16-bit units.
-----------------------------------------------------------------------*/
#pragma ADDRESS     tb0_addr    0350H       /* Timer B0 register */
UINT16   tb0_addr;              /* Timer B0 register */

#define		TB0     tb0_addr

/*---------------------------------------------------------------------
    Timer B1 registers ; Read and write to this register in 16-bit units.
-----------------------------------------------------------------------*/
#pragma ADDRESS     tb1_addr    0352H       /* Timer B1 register */
UINT16   tb1_addr;              /* Timer B1 register */

#define		TB1     tb1_addr

/*---------------------------------------------------------------------
    Timer B2 registers ; Read and write to this register in 16-bit units.
-----------------------------------------------------------------------*/
#pragma ADDRESS     tb2_addr    0354H       /* Timer B2 register */
UINT16   tb2_addr;              /* Timer B2 register */

#define		TB2     tb2_addr

/*------------------------------------------------------
    Timer A0 mode registers
------------------------------------------------------*/
#pragma ADDRESS     ta0mr_addr  0356H       /* Timer A0 mode register */
typedef union {
    struct{
        UINT8    tmod0:1;        /* Operation mode select bit */
        UINT8    tmod1:1;        /* Operation mode select bit */
        UINT8    mr0:1;
        UINT8    mr1:1;
        UINT8    mr2:1;
        UINT8    mr3:1;
        UINT8    tck0:1;         /* Count source select bit */
        UINT8    tck1:1;         /* Count source select bit */
    } bit;
    UINT8    byte;
} TA0MR_ADDR;
TA0MR_ADDR	ta0mr_addr;

#define		TA0MR       ta0mr_addr.byte

#define		TMOD0_TA0MR ta0mr_addr.bit.tmod0    /* Operation mode select bit */
#define		TMOD1_TA0MR ta0mr_addr.bit.tmod1    /* Operation mode select bit */
//#define     mr0_ta0mr   ta0mr_addr.bit.mr0
#define		MR1_TA0MR   ta0mr_addr.bit.mr1
#define		MR2_TA0MR   ta0mr_addr.bit.mr2
#define		MR3_TA0MR   ta0mr_addr.bit.mr3
#define		TCK0_TA0MR  ta0mr_addr.bit.tck0 /* Count source select bit */
#define		TCK1_TA0MR  ta0mr_addr.bit.tck1 /* Count source select bit */

/*------------------------------------------------------
    Timer A1 mode registers
------------------------------------------------------*/
#pragma ADDRESS     ta1mr_addr  0357H       /* Timer A1 mode register */
typedef union {
    struct{
        UINT8    tmod0:1;        /* Operation mode select bit */
        UINT8    tmod1:1;        /* Operation mode select bit */
        UINT8    mr0:1;
        UINT8    mr1:1;
        UINT8    mr2:1;
        UINT8    mr3:1;
        UINT8    tck0:1;         /* Count source select bit */
        UINT8    tck1:1;         /* Count source select bit */
    } bit;
    UINT8    byte;
} TA1MR_ADDR;
TA1MR_ADDR	ta1mr_addr;

#define		TA1MR       ta1mr_addr.byte

#define		TMOD0_TA1MR ta1mr_addr.bit.tmod0    /* Operation mode select bit */
#define		TMOD1_TA1MR ta1mr_addr.bit.tmod1    /* Operation mode select bit */
//#define     mr0_ta1mr   ta1mr_addr.bit.mr0
#define		MR1_TA1MR   ta1mr_addr.bit.mr1
#define		MR2_TA1MR   ta1mr_addr.bit.mr2
#define		MR3_TA1MR   ta1mr_addr.bit.mr3
#define		TCK0_TA1MR  ta1mr_addr.bit.tck0 /* Count source select bit */
#define		TCK1_TA1MR  ta1mr_addr.bit.tck1 /* Count source select bit */

/*------------------------------------------------------
    Timer A2 mode registers
------------------------------------------------------*/
#pragma ADDRESS     ta2mr_addr  0358H       /* Timer A2 mode register */
typedef union {
    struct{
        UINT8    tmod0:1;        /* Operation mode select bit */
        UINT8    tmod1:1;        /* Operation mode select bit */
        UINT8    mr0:1;
        UINT8    mr1:1;
        UINT8    mr2:1;
        UINT8    mr3:1;
        UINT8    tck0:1;         /* Count source select bit */
        UINT8    tck1:1;         /* Count source select bit */
    } bit;
    UINT8    byte;
} TA2MR_ADDR;
TA2MR_ADDR	ta2mr_addr;

#define		TA2MR       ta2mr_addr.byte

#define		TMOD0_TA2MR ta2mr_addr.bit.tmod0    /* Operation mode select bit */
#define		TMOD1_TA2MR ta2mr_addr.bit.tmod1    /* Operation mode select bit */
//#define     mr0_ta2mr   ta2mr_addr.bit.mr0
#define		MR1_TA2MR   ta2mr_addr.bit.mr1
#define		MR2_TA2MR   ta2mr_addr.bit.mr2
#define		MR3_TA2MR   ta2mr_addr.bit.mr3
#define		TCK0_TA2MR  ta2mr_addr.bit.tck0 /* Count source select bit */
#define		TCK1_TA2MR  ta2mr_addr.bit.tck1 /* Count source select bit */

/*------------------------------------------------------
    Timer A3 mode registers
------------------------------------------------------*/
#pragma ADDRESS     ta3mr_addr  0359H       /* Timer A3 mode register */
typedef union {
    struct{
        UINT8    tmod0:1;        /* Operation mode select bit */
        UINT8    tmod1:1;        /* Operation mode select bit */
        UINT8    mr0:1;
        UINT8    mr1:1;
        UINT8    mr2:1;
        UINT8    mr3:1;
        UINT8    tck0:1;         /* Count source select bit */
        UINT8    tck1:1;         /* Count source select bit */
    } bit;
    UINT8    byte;
} TA3MR_ADDR;
TA3MR_ADDR	ta3mr_addr;

#define		TA3MR       ta3mr_addr.byte

#define		TMOD0_TA3MR ta3mr_addr.bit.tmod0    /* Operation mode select bit */
#define		TMOD1_TA3MR ta3mr_addr.bit.tmod1    /* Operation mode select bit */
//#define     mr0_ta3mr   ta3mr_addr.bit.mr0
#define		MR1_TA3MR   ta3mr_addr.bit.mr1
#define		MR2_TA3MR   ta3mr_addr.bit.mr2
#define		MR3_TA3MR   ta3mr_addr.bit.mr3
#define		TCK0_TA3MR  ta3mr_addr.bit.tck0 /* Count source select bit */
#define		TCK1_TA3MR  ta3mr_addr.bit.tck1 /* Count source select bit */

/*------------------------------------------------------
    Timer A4 mode registers
------------------------------------------------------*/
#pragma ADDRESS     ta4mr_addr  035aH       /* Timer A4 mode register */
typedef union {
    struct{
        UINT8    tmod0:1;        /* Operation mode select bit */
        UINT8    tmod1:1;        /* Operation mode select bit */
        UINT8    mr0:1;
        UINT8    mr1:1;
        UINT8    mr2:1;
        UINT8    mr3:1;
        UINT8    tck0:1;         /* Count source select bit */
        UINT8    tck1:1;         /* Count source select bit */
    } bit;
    UINT8    byte;
} TA4MR_ADDR;
TA4MR_ADDR	ta4mr_addr;

#define		TA4MR       ta4mr_addr.byte

#define		TMOD0_TA4MR ta4mr_addr.bit.tmod0    /* Operation mode select bit */
#define		TMOD1_TA4MR ta4mr_addr.bit.tmod1    /* Operation mode select bit */
//#define     mr0_ta4mr   ta4mr_addr.bit.mr0
#define		MR1_TA4MR   ta4mr_addr.bit.mr1
#define		MR2_TA4MR   ta4mr_addr.bit.mr2
#define		MR3_TA4MR   ta4mr_addr.bit.mr3
#define		TCK0_TA4MR  ta4mr_addr.bit.tck0 /* Count source select bit */
#define		TCK1_TA4MR  ta4mr_addr.bit.tck1 /* Count source select bit */

/*------------------------------------------------------
    Timer B0 mode registers
------------------------------------------------------*/
#pragma ADDRESS     tb0mr_addr  035bH       /* Timer B0 mode register */
typedef union {
    struct{
        UINT8    tmod0:1;        /* Operation mode select bit */
        UINT8    tmod1:1;        /* Operation mode select bit */
        UINT8    mr0:1;
        UINT8    mr1:1;
        UINT8    mr2:1;
        UINT8    mr3:1;
        UINT8    tck0:1;         /* Count source select bit */
        UINT8    tck1:1;         /* Count source select bit */
    } bit;
    UINT8    byte;
} TB0MR_ADDR;
TB0MR_ADDR	tb0mr_addr;

#define		TB0MR       tb0mr_addr.byte

#define		TMOD0_TB0MR tb0mr_addr.bit.tmod0    /* Operation mode select bit */
#define		TMOD1_TB0MR tb0mr_addr.bit.tmod1    /* Operation mode select bit */
#define		MR0_TB0MR   tb0mr_addr.bit.mr0
#define		MR1_TB0MR   tb0mr_addr.bit.mr1
#define		MR2_TB0MR   tb0mr_addr.bit.mr2
#define		MR3_TB0MR   tb0mr_addr.bit.mr3
#define		TCK0_TB0MR  tb0mr_addr.bit.tck0 /* Count source select bit */
#define		TCK1_TB0MR  tb0mr_addr.bit.tck1 /* Count source select bit */

/*------------------------------------------------------
    Timer B1 mode registers
------------------------------------------------------*/
#pragma ADDRESS     tb1mr_addr  035cH       /* Timer B1 mode register */
typedef union {
    struct{
        UINT8    tmod0:1;        /* Operation mode select bit */
        UINT8    tmod1:1;        /* Operation mode select bit */
        UINT8    mr0:1;
        UINT8    mr1:1;
        UINT8    mr2:1;
        UINT8    mr3:1;
        UINT8    tck0:1;         /* Count source select bit */
        UINT8    tck1:1;         /* Count source select bit */
    } bit;
    UINT8    byte;
} TB1MR_ADDR;
TB1MR_ADDR	tb1mr_addr;

#define		TB1MR       tb1mr_addr.byte

#define		TMOD0_TB1MR tb1mr_addr.bit.tmod0    /* Operation mode select bit */
#define		TMOD1_TB1MR tb1mr_addr.bit.tmod1    /* Operation mode select bit */
#define		MR0_TB1MR   tb1mr_addr.bit.mr0
#define		MR1_TB1MR   tb1mr_addr.bit.mr1
#define		MR2_TB1MR	tb1mr_addr.bit.mr2
#define		MR3_TB1MR   tb1mr_addr.bit.mr3
#define		TCK0_TB1MR  tb1mr_addr.bit.tck0 /* Count source select bit */
#define		TCK1_TB1MR  tb1mr_addr.bit.tck1 /* Count source select bit */

/*------------------------------------------------------
    Timer B2 mode registers
------------------------------------------------------*/
#pragma ADDRESS     tb2mr_addr  035dH       /* Timer B2 mode register */
typedef union {
    struct{
        UINT8    tmod0:1;        /* Operation mode select bit */
        UINT8    tmod1:1;        /* Operation mode select bit */
        UINT8    mr0:1;
        UINT8    mr1:1;
        UINT8    mr2:1;
        UINT8    mr3:1;
        UINT8    tck0:1;         /* Count source select bit */
        UINT8    tck1:1;         /* Count source select bit */
    } bit;
    UINT8    byte;
} TB2MR_ADDR;
TB2MR_ADDR	tb2mr_addr;

#define		TB2MR       tb2mr_addr.byte

#define		TMOD0_TB2MR tb2mr_addr.bit.tmod0    /* Operation mode select bit */
#define		TMOD1_TB2MR tb2mr_addr.bit.tmod1    /* Operation mode select bit */
#define		MR0_TB2MR   tb2mr_addr.bit.mr0
#define		MR1_TB2MR   tb2mr_addr.bit.mr1
#define		MR2_TB2MR	tb2mr_addr.bit.mr2
#define		MR3_TB2MR   tb2mr_addr.bit.mr3
#define		TCK0_TB2MR  tb2mr_addr.bit.tck0 /* Count source select bit */
#define		TCK1_TB2MR  tb2mr_addr.bit.tck1 /* Count source select bit */

/*------------------------------------------------------
    Timer B2 special mode register
------------------------------------------------------*/
#pragma ADDRESS     tb2sc_addr  035eH       /* Timer B2 special mode register */
typedef union {
	struct{
		UINT8	pwcon:1;
		UINT8	b1:1;
		UINT8	b2:1;
		UINT8	b3:1;
		UINT8	b4:1;
		UINT8	b5:1;
		UINT8	b6:1;
		UINT8	b7:1;
	} bit;
	 UINT8 byte;
} TB2SC_ADDR;
TB2SC_ADDR	tb2sc_addr;

#define		TB2SC		tb2sc_addr.byte

#define		PWCON		tb2sc_addr.bit.pwcon

/*------------------------------------------------------
   Count source prescaler register
------------------------------------------------------*/
#pragma ADDRESS     tcspr_addr  035fH       /* Count source prescaler register */
typedef union {
	struct{
		UINT8	cnt0:1;
		UINT8	cnt1:1;
		UINT8	cnt2:1;
		UINT8	cnt3:1;
		UINT8	b4:1;
		UINT8	b5:1;
		UINT8	b6:1;
		UINT8	cst:1;
	} bit;
	 UINT8 byte;
} TCSPR_ADDR;
TCSPR_ADDR	tcspr_addr;

#define		TCSPR		tcspr_addr.byte

#define		CNT0		tcspr_addr.bit.cnt0
#define		CNT1		tcspr_addr.bit.cnt1
#define		CNT2		tcspr_addr.bit.cnt2
#define		CNT3		tcspr_addr.bit.cnt3
#define		CST			tcspr_addr.bit.cst

/*------------------------------------------------------
    UART0 special mode register 4
------------------------------------------------------*/
#pragma ADDRESS     u0smr4_addr 0364H       /* UART0 special mode register 4 */ 
typedef union {
    struct{
        UINT8    stareq:1;
        UINT8    rstareq:1;
        UINT8    stpreq:1;
        UINT8    stspsel:1;
        UINT8    ackd:1;
        UINT8    ackc:1;
        UINT8    sclhi:1;
        UINT8    swc9:1;
    } bit;
    UINT8    byte;
} U0SMR4_ADDR;
U0SMR4_ADDR	u0smr4_addr;

#define		U0SMR4      u0smr4_addr.byte

#define		STAREQ_U0SMR4  u0smr4_addr.bit.stareq
#define		RSTAREQ_U0SMR4 u0smr4_addr.bit.rstareq
#define		STPREQ_U0SMR4 u0smr4_addr.bit.stpreq
#define		STSPSEL_U0SMR4 u0smr4_addr.bit.stspsel
#define		ACKD_U0SMR4  u0smr4_addr.bit.ackd
#define		ACKC_U0SMR4  u0smr4_addr.bit.ackc
#define		SCLHI_U0SMR4  u0smr4_addr.bit.sclhi
#define		SWC9_U0SMR4  u0smr4_addr.bit.swc9

/*------------------------------------------------------
    UART0 special mode register 3
------------------------------------------------------*/
#pragma ADDRESS     u0smr3_addr 0365H       /* UART0 special mode register 3 */ 
typedef union {
    struct{
        UINT8    sse:1;
        UINT8    ckph:1;
        UINT8    dinc:1;
        UINT8    nodc:1;
        UINT8    err:1;
        UINT8    dl0:1;
        UINT8    dl1:1;
        UINT8    dl2:1;
    } bit;
    UINT8    byte;
} U0SMR3_ADDR;
U0SMR3_ADDR	u0smr3_addr;

#define		U0SMR3      u0smr3_addr.byte

#define		SSE_U0SMR3  u0smr3_addr.bit.sse
#define		CKPH_U0SMR3 u0smr3_addr.bit.ckph
#define		DINC_U0SMR3 u0smr3_addr.bit.dinc
#define		NODC_U0SMR3 u0smr3_addr.bit.nodc
#define		ERR_U0SMR3  u0smr3_addr.bit.err
#define		DL0_U0SMR3  u0smr3_addr.bit.dl0
#define		DL1_U0SMR3  u0smr3_addr.bit.dl1
#define		DL2_U0SMR3  u0smr3_addr.bit.dl2

/*------------------------------------------------------
    UART0 special mode register 2
------------------------------------------------------*/
#pragma ADDRESS     u0smr2_addr 0366H       /* UART0 special mode register 2 */
typedef union {
    struct{
        UINT8    iicm2:1;
        UINT8    csc:1;
        UINT8    swc:1;
        UINT8    als:1;
        UINT8    stc:1;
        UINT8    swc2:1;
        UINT8    sdhi:1;
        UINT8    shtc:1;
    } bit;
    UINT8    byte;
} U0SMR2_ADDR;
U0SMR2_ADDR	u0smr2_addr;

#define		U0SMR2      u0smr2_addr.byte

#define		IICM2_U0SMR2    u0smr2_addr.bit.iicm2
#define		CSC_U0SMR2  u0smr2_addr.bit.csc
#define		SWC_U0SMR2  u0smr2_addr.bit.swc
#define		ALS_U0SMR2  u0smr2_addr.bit.als
#define		STC_U0SMR2  u0smr2_addr.bit.stc 
#define		SWC2_U0SMR2 u0smr2_addr.bit.swc2
#define		SDHI_U0SMR2 u0smr2_addr.bit.sdhi
#define		SU1HIM_U0SMR2 u0smr2_addr.bit.shtc

/*------------------------------------------------------
    UART0 special mode registers
------------------------------------------------------*/
#pragma ADDRESS     u0smr_addr  0367H       /* UART0 special mode register */
typedef union {
    struct{
        UINT8    iicm:1;
        UINT8    abc:1;
        UINT8    bbs:1;
        UINT8    lsyn:1;
        UINT8    abscs:1;
        UINT8    acse:1;
        UINT8    sss:1;
        UINT8    su1him:1;
    } bit;
    UINT8    byte;
} U0SMR_ADDR;
U0SMR_ADDR	u0smr_addr;

#define		U0SMR       u0smr_addr.byte

#define		IICM_U0SMR  u0smr_addr.bit.iicm 
#define		ABC_U0SMR   u0smr_addr.bit.abc
#define		BBS_U0SMR   u0smr_addr.bit.bbs
#define		LSYN_U0SMR  u0smr_addr.bit.lsyn
#define		ABSCS_U0SMR u0smr_addr.bit.abscs
#define		ACSE_U0SMR  u0smr_addr.bit.acse
#define		SSS_U0SMR   u0smr_addr.bit.sss
#define		SCLKDIV_U0SMR   u0smr_addr.bit.su1him

/*------------------------------------------------------
    UART0 transmit/receive mode registers
------------------------------------------------------*/
#pragma ADDRESS     u0mr_addr   0368H       /* UART0 transmit/receive mode register */
typedef union {
    struct{
        UINT8    smd0:1;             /* Serial I/O mode select bit */
        UINT8    smd1:1;             /* Serial I/O mode select bit */
        UINT8    smd2:1;             /* Serial I/O mode select bit */
        UINT8    ckdir:1;            /* Internal/external clock select bit */
        UINT8    stps:1;             /* Stop bit length select bit */
        UINT8    pry:1;              /* Odd/even parity select bit */
        UINT8    prye:1;             /* Parity enable bit */
        UINT8    iopol:1;            /* TxD RxD I/O polarity reverse bit */
    } bit;
    UINT8    byte;
} U0MR_ADDR;
U0MR_ADDR	u0mr_addr;

#define		U0MR        u0mr_addr.byte

#define		SMD0_U0MR   u0mr_addr.bit.smd0  /* Serial I/O mode select bit */
#define		SMD1_U0MR   u0mr_addr.bit.smd1  /* Serial I/O mode select bit */
#define		SMD2_U0MR   u0mr_addr.bit.smd2  /* Serial I/O mode select bit */
#define		CKDIR_U0MR  u0mr_addr.bit.ckdir /* Internal/external clock select bit */
#define		STPS_U0MR   u0mr_addr.bit.stps  /* Stop bit length select bit */
#define		PRY_U0MR    u0mr_addr.bit.pry   /* Odd/even parity select bit */
#define		PRYE_U0MR   u0mr_addr.bit.prye  /* Parity enable bit */
#define		IOPOL_U0MR  u0mr_addr.bit.iopol  /* TxD RxD I/O polarity reverse bit */

/*------------------------------------------------------
    UART0 bit rate generators ; Use "MOV" instruction when writing to these registers.
------------------------------------------------------*/
#pragma ADDRESS     u0brg_addr  0369H       /* UART0 bit rate generator */
UINT8 u0brg_addr;

#define		U0BRG       u0brg_addr

/*----------------------------------------------------*/
#pragma ADDRESS     u0tb_addr   036aH       /* UART0 transmit buffer register */
typedef union {
    struct{
        UINT8    b0:1;
        UINT8    b1:1;
        UINT8    b2:1;
        UINT8    b3:1;
        UINT8    b4:1;
        UINT8    b5:1;
        UINT8    b6:1;
        UINT8    b7:1;
        UINT8    b8:1;
        UINT8    b9:1;
        UINT8    b10:1;
        UINT8    b11:1;
        UINT8    b12:1;
        UINT8    b13:1;
        UINT8    b14:1;
        UINT8    b15:1;
    } bit;
    struct{
        UINT8    low;                /* low  8 bit */
        UINT8    high;               /* high 8 bit */
    } byte;
    UINT16  word;
} U0TB_ADDR;
U0TB_ADDR	u0tb_addr;

#define		U0TB    u0tb_addr.word          /* UART0 Transmit buffer register 16 bit ; Use "MOV" instruction when writing to this register. */
#define		U0TBL   u0tb_addr.byte.low          /* UART0 Transmit buffer register low  8 bit */
#define		U0TBH   u0tb_addr.byte.high         /* UART0 Transmit buffer register high 8 bit */

/*------------------------------------------------------
    UART0 transmit/receive control register 0
------------------------------------------------------*/
#pragma ADDRESS     u0c0_addr   036cH       /* UART0 transmit/receive control register 0 */
typedef union {
    struct{
        UINT8    clk0:1;         /* BRG count source select bit */
        UINT8    clk1:1;         /* BRG count source select bit */
        UINT8    crs:1;          /* CTS~/RTS~ function select bit */
        UINT8    txept:1;        /* Transmit register empty flag */
        UINT8    crd:1;          /* CTS~/RTS~ disable bit */
        UINT8    nch:1;          /* Data output select bit */
        UINT8    ckpol:1;        /* CLK polarity select bit */
        UINT8    uform:1;        /* Transfer format select bit */
    } bit;
    UINT8    byte;
} U0C0_ADDR;
U0C0_ADDR	u0c0_addr;

#define		U0C0        u0c0_addr.byte

#define		CLK0_U0C0   u0c0_addr.bit.clk0  /* BRG count source select bit */
#define		CLK1_U0C0   u0c0_addr.bit.clk1  /* BRG count source select bit */
#define		CRS_U0C0    u0c0_addr.bit.crs   /* CTS~/RTS~ function select bit */
#define		TXEPT_U0C0  u0c0_addr.bit.txept /* Transmit register empty flag */
#define		CRD_U0C0    u0c0_addr.bit.crd   /* CTS~/RTS~ disable bit */
#define		NCH_U0C0    u0c0_addr.bit.nch   /* Data output select bit */
#define		CKPOL_U0C0  u0c0_addr.bit.ckpol /* CLK polarity select bit */
#define		UFORM_U0C0  u0c0_addr.bit.uform /* Transfer format select bit */

/*------------------------------------------------------
    UART0 transmit/receive control register 1
------------------------------------------------------*/
#pragma ADDRESS     u0c1_addr   036dH       /* UART0 transmit/receive control register 1 */
typedef union {
	struct{
		UINT8	te_u0c1:1;
		UINT8	ti_u0c1:1;
		UINT8	re_u0c1:1;
		UINT8	ri_u0c1:1;
		UINT8	u0irs_u0c1:1;
		UINT8	u0rrm_u0c1:1;
		UINT8	u0lch_u0c1:1;
		UINT8	u0ere_u0c1:1;
	} bit;
	 UINT8 byte;
} U0C1_ADDR;
U0C1_ADDR	u0c1_addr;

#define		U0C1		u0c1_addr.byte

#define		TE_U0C1		u0c1_addr.bit.te_u0c1
#define		TI_U0C1		u0c1_addr.bit.ti_u0c1
#define		RE_U0C1		u0c1_addr.bit.re_u0c1
#define		RI_U0C1		u0c1_addr.bit.ri_u0c1
#define		U0IRS_U0C1	u0c1_addr.bit.u0irs_u0c1
#define		U0RRM_U0C1	u0c1_addr.bit.u0rrm_u0c1
#define		U0LCH_U0C1	u0c1_addr.bit.u0lch_u0c1
#define		U0ERE_U0C1	u0c1_addr.bit.u0ere_u0c1

/*------------------------------------------------------
    UART0 receive buffer register
------------------------------------------------------*/
#pragma ADDRESS     u0rb_addr   036eH       /* UART0 receive buffer register */
typedef union {
    struct{
        UINT8    b0:1;
        UINT8    b1:1;
        UINT8    b2:1;
        UINT8    b3:1;
        UINT8    b4:1;
        UINT8    b5:1;
        UINT8    b6:1;
        UINT8    b7:1;
        UINT8    b8:1;
        UINT8    b9:1;
        UINT8    b10:1;
        UINT8    abt:1;              /* Arbitration lost detecting flag */
        UINT8    oer:1;              /* Overrun error flag */
        UINT8    fer:1;              /* Framing error flag */
        UINT8    per:1;              /* Parity error flag */
        UINT8    sum:1;              /* Error sum flag */
    } bit;
    struct{
        UINT8    low;                /* Low  8 bit */
        UINT8    high;               /* High 8 bit */
    } byte;
    UINT16  word;
} U0RB_ADDR;
U0RB_ADDR	u0rb_addr;

#define		U0RB        u0rb_addr.word
#define		U0RBL       u0rb_addr.byte.low
#define		U0RBH       u0rb_addr.byte.high

#define		ABT_U0RB    u0rb_addr.bit.abt   /* Arbitration lost detecting flag */
#define		OER_U0RB    u0rb_addr.bit.oer   /* Overrun error flag */
#define		FER_U0RB    u0rb_addr.bit.fer   /* Framing error flag */
#define		PER_U0RB    u0rb_addr.bit.per   /* Parity error flag */
#define		SUM_U0RB    u0rb_addr.bit.sum   /* Error sum flag */

/*------------------------------------------------------
    PLL control register 0
------------------------------------------------------*/
#pragma ADDRESS     plc0_addr   0376H       /* PLL control register 0 */
typedef union {
	struct{
		UINT8	plc00:1;
		UINT8	plc01:1;
		UINT8	plc02:1;
		UINT8	b3:1;
		UINT8	plc04:1;
		UINT8	plc05:1;
		UINT8	b6:1;
		UINT8	plc07:1;
	} bit;
	 UINT8 byte;
} PLC0_ADDR;
PLC0_ADDR	plc0_addr;

#define		PLC0		plc0_addr.byte

#define		PLC00		plc0_addr.bit.plc00
#define		PLC01		plc0_addr.bit.plc01
#define		PLC02		plc0_addr.bit.plc02
#define		PLC04		plc0_addr.bit.plc04
#define		PLC05		plc0_addr.bit.plc05
#define		PLC07		plc0_addr.bit.plc07

/*------------------------------------------------------
    PLL control register 1
------------------------------------------------------*/
#pragma ADDRESS     plc1_addr   0377H       /* PLL control register 1 */
typedef union {
	struct{
		UINT8	b0:1;
		UINT8	plc11:1;
		UINT8	b2:1;
		UINT8	b3:1;
		UINT8	b4:1;
		UINT8	b5:1;
		UINT8	b6:1;
		UINT8	b7:1;
	} bit;
	 UINT8 byte;
} PLC1_ADDR;
PLC1_ADDR	plc1_addr;

#define		PLC1		plc1_addr.byte

#define		PLC11		plc1_addr.bit.plc11

/*------------------------------------------------------
    DMA0 request cause register
------------------------------------------------------*/
#pragma ADDRESS     dm0sl_addr  0378H       /* DMA0 cause select register */
typedef union {
    struct{
        UINT8    dsel0:1;            /* DMA request cause select bit */
        UINT8    dsel1:1;            /* DMA request cause select bit */
        UINT8    dsel2:1;            /* DMA request cause select bit */
        UINT8    dsel3:1;            /* DMA request cause select bit */
        UINT8    dsel4:1;            /* DMA request cause select bit */
        UINT8    dsr:1;              /* Software DMA request bit */
        UINT8    b6:1;
        UINT8    drq:1;              /* DMA request bit */
    } bit;
    UINT8    byte;
} DM0SL_ADDR;
DM0SL_ADDR	dm0sl_addr;

#define		DM0SL       dm0sl_addr.byte

#define		DSEL0_DM0SL dm0sl_addr.bit.dsel0    /* DMA request cause select bit */
#define		DSEL1_DM0SL dm0sl_addr.bit.dsel1    /* DMA request cause select bit */
#define		DSEL2_DM0SL dm0sl_addr.bit.dsel2    /* DMA request cause select bit */
#define		DSEL3_DM0SL dm0sl_addr.bit.dsel3    /* DMA request cause select bit */
#define		DSEL4_DM0SL dm0sl_addr.bit.dsel4    /* DMA request cause select bit */
#define		DSR_DM0SL   dm0sl_addr.bit.dsr      /* Software DMA request bit */
#define		DRQ_DM0SL   dm0sl_addr.bit.drq      /* DMA request bit */

/*------------------------------------------------------
    DMA1 request cause register
------------------------------------------------------*/
#pragma ADDRESS     dm1sl_addr  0379H       /* DMA1 cause select register */
typedef union {
    struct{
        UINT8    dsel0:1;            /* DMA request cause select bit */
        UINT8    dsel1:1;            /* DMA request cause select bit */
        UINT8    dsel2:1;            /* DMA request cause select bit */
        UINT8    dsel3:1;            /* DMA request cause select bit */
        UINT8    dsel4:1;            /* DMA request cause select bit */
        UINT8    dsr:1;              /* Software DMA request bit */
        UINT8    b6:1;
        UINT8    drq:1;              /* DMA request bit */
    } bit;
    UINT8    byte;
} DM1SL_ADDR;
DM1SL_ADDR	dm1sl_addr;

#define		DM1SL       dm1sl_addr.byte

#define		DSEL0_DM1SL dm1sl_addr.bit.dsel0    /* DMA request cause select bit */
#define		DSEL1_DM1SL dm1sl_addr.bit.dsel1    /* DMA request cause select bit */
#define		DSEL2_DM1SL dm1sl_addr.bit.dsel2    /* DMA request cause select bit */
#define		DSEL3_DM1SL dm1sl_addr.bit.dsel3    /* DMA request cause select bit */
#define		DSEL4_DM1SL dm1sl_addr.bit.dsel4    /* DMA request cause select bit */
#define		DSR_DM1SL   dm1sl_addr.bit.dsr      /* Software DMA request bit */
#define		DRQ_DM1SL   dm1sl_addr.bit.drq      /* DMA request bit */

/*------------------------------------------------------
    DMA2 request cause register
------------------------------------------------------*/
#pragma ADDRESS     dm2sl_addr  037aH       /* DMA1 cause select register */
typedef union {
    struct{
        UINT8    dsel0:1;            /* DMA request cause select bit */
        UINT8    dsel1:1;            /* DMA request cause select bit */
        UINT8    dsel2:1;            /* DMA request cause select bit */
        UINT8    dsel3:1;            /* DMA request cause select bit */
        UINT8    dsel4:1;            /* DMA request cause select bit */
        UINT8    dsr:1;              /* Software DMA request bit */
        UINT8    b6:1;
        UINT8    drq:1;              /* DMA request bit */
    } bit;
    UINT8    byte;
} DM2SL_ADDR;
DM2SL_ADDR	dm2sl_addr;

#define		DM2SL       dm2sl_addr.byte

#define		DSEL0_DM2SL dm2sl_addr.bit.dsel0    /* DMA request cause select bit */
#define		DSEL1_DM2SL dm2sl_addr.bit.dsel1    /* DMA request cause select bit */
#define		DSEL2_DM2SL dm2sl_addr.bit.dsel2    /* DMA request cause select bit */
#define		DSEL3_DM2SL dm2sl_addr.bit.dsel3    /* DMA request cause select bit */
#define		DSEL4_DM2SL dm2sl_addr.bit.dsel4    /* DMA request cause select bit */
#define		DSR_DM2SL   dm2sl_addr.bit.dsr      /* Software DMA request bit */
#define		DRQ_DM2SL   dm2sl_addr.bit.drq      /* DMA request bit */

/*------------------------------------------------------
    DMA3 request cause register
------------------------------------------------------*/
#pragma ADDRESS     dm3sl_addr  037bH       /* DMA1 cause select register */
typedef union {
    struct{
        UINT8    dsel0:1;            /* DMA request cause select bit */
        UINT8    dsel1:1;            /* DMA request cause select bit */
        UINT8    dsel2:1;            /* DMA request cause select bit */
        UINT8    dsel3:1;            /* DMA request cause select bit */
        UINT8    dsel4:1;            /* DMA request cause select bit */
        UINT8    dsr:1;              /* Software DMA request bit */
        UINT8    b6:1;
        UINT8    drq:1;              /* DMA request bit */
    } bit;
    UINT8    byte;
} DM3SL_ADDR;
DM3SL_ADDR	dm3sl_addr;

#define		DM3SL       dm3sl_addr.byte

#define		DSEL0_DM3SL dm3sl_addr.bit.dsel0    /* DMA request cause select bit */
#define		DSEL1_DM3SL dm3sl_addr.bit.dsel1    /* DMA request cause select bit */
#define		DSEL2_DM3SL dm3sl_addr.bit.dsel2    /* DMA request cause select bit */
#define		DSEL3_DM3SL dm3sl_addr.bit.dsel3    /* DMA request cause select bit */
#define		DSEL4_DM3SL dm3sl_addr.bit.dsel4    /* DMA request cause select bit */
#define		DSR_DM3SL   dm3sl_addr.bit.dsr      /* Software DMA request bit */
#define		DRQ_DM3SL   dm3sl_addr.bit.drq      /* DMA request bit */

/*----------------------------------------------------*/
#pragma ADDRESS     crcd_addr   037cH       /* CRC data register */
typedef union {
    struct{
        UINT8    b0:1;
        UINT8    b1:1;
        UINT8    b2:1;
        UINT8    b3:1;
        UINT8    b4:1;
        UINT8    b5:1;
        UINT8    b6:1;
        UINT8    b7:1;
        UINT8    b8:1;
        UINT8    b9:1;
        UINT8    b10:1;
        UINT8    b11:1;
        UINT8    b12:1;
        UINT8    b13:1;
        UINT8    b14:1;
        UINT8    b15:1;
    } bit;
    struct{
        UINT8    low;                /* low  8 bit */
        UINT8    high;               /* high 8 bit */
    } byte;
    UINT16  word;
} CRCD_ADDR;
CRCD_ADDR	crcd_addr;

#define		CRCD    crcd_addr.word          /* CRC data register 16 bit */
#define		CRCDL   crcd_addr.byte.low          /* CRC data register low  8 bit */
#define		CRCDH   crcd_addr.byte.high         /* CRC data register high 8 bit */

/*------------------------------------------------------
    CRC input register
------------------------------------------------------*/
#pragma ADDRESS     crcin_addr  037eH       /* CRC input register */
typedef union {
	struct{
		UINT8	b0:1;
		UINT8	b1:1;
		UINT8	b2:1;
		UINT8	b3:1;
		UINT8	b4:1;
		UINT8	b5:1;
		UINT8	b6:1;
		UINT8	b7:1;
	} bit;
	 UINT8 byte;
} CRCIN_ADDR;
CRCIN_ADDR	crcin_addr;

#define		CRCIN		crcin_addr.byte

/*----------------------------------------------------*/
#pragma ADDRESS     ad00_addr   0380H       /* A-D0 register 0 */
typedef union {
    struct{
        UINT8    b0:1;
        UINT8    b1:1;
        UINT8    b2:1;
        UINT8    b3:1;
        UINT8    b4:1;
        UINT8    b5:1;
        UINT8    b6:1;
        UINT8    b7:1;
        UINT8    b8:1;
        UINT8    b9:1;
        UINT8    b10:1;
        UINT8    b11:1;
        UINT8    b12:1;
        UINT8    b13:1;
        UINT8    b14:1;
        UINT8    b15:1;
    } bit;
    struct{
        UINT8    low;                /* low  8 bit */
        UINT8    high;               /* high 8 bit */
    } byte;
    UINT16  word;
} AD00_ADDR;
AD00_ADDR	ad00_addr;

#define		AD00 ad00_addr.word           /* A-D0 register 0 16 bit */
#define		AD00L    ad00_addr.byte.low           /* A-D0 register 0 low  8 bit */
#define		AD00H    ad00_addr.byte.high          /* A-D0 register 0 high 8 bit */

/*----------------------------------------------------*/
#pragma ADDRESS     ad01_addr   0382H       /* A-D0 register 1 */
typedef union {
    struct{
        UINT8    b0:1;
        UINT8    b1:1;
        UINT8    b2:1;
        UINT8    b3:1;
        UINT8    b4:1;
        UINT8    b5:1;
        UINT8    b6:1;
        UINT8    b7:1;
        UINT8    b8:1;
        UINT8    b9:1;
        UINT8    b10:1;
        UINT8    b11:1;
        UINT8    b12:1;
        UINT8    b13:1;
        UINT8    b14:1;
        UINT8    b15:1;
    } bit;
    struct{
        UINT8    low;                /* low  8 bit */
        UINT8    high;               /* high 8 bit */
    } byte;
    UINT16  word;
} AD01_ADDR;
AD01_ADDR	ad01_addr;

#define		AD01 ad01_addr.word           /* A-D0 register 1 16 bit */
#define		AD01L    ad01_addr.byte.low           /* A-D0 register 1 low  8 bit */
#define		AD01H    ad01_addr.byte.high          /* A-D0 register 1 high 8 bit */

/*----------------------------------------------------*/
#pragma ADDRESS     ad02_addr   0384H       /* A-D0 register 2 */
typedef union {
    struct{
        UINT8    b0:1;
        UINT8    b1:1;
        UINT8    b2:1;
        UINT8    b3:1;
        UINT8    b4:1;
        UINT8    b5:1;
        UINT8    b6:1;
        UINT8    b7:1;
        UINT8    b8:1;
        UINT8    b9:1;
        UINT8    b10:1;
        UINT8    b11:1;
        UINT8    b12:1;
        UINT8    b13:1;
        UINT8    b14:1;
        UINT8    b15:1;
    } bit;
    struct{
        UINT8    low;                /* low  8 bit */
        UINT8    high;               /* high 8 bit */
    } byte;
    UINT16  word;
} AD02_ADDR;
AD02_ADDR	ad02_addr;

#define		AD02 ad02_addr.word           /* A-D0 register 2 16 bit */
#define		AD02L    ad02_addr.byte.low           /* A-D0 register 2 low  8 bit */
#define		AD02H    ad02_addr.byte.high          /* A-D0 register 2 high 8 bit */

/*----------------------------------------------------*/
#pragma ADDRESS     ad03_addr   0386H       /* A-D0 register 3 */
typedef union {
    struct{
        UINT8    b0:1;
        UINT8    b1:1;
        UINT8    b2:1;
        UINT8    b3:1;
        UINT8    b4:1;
        UINT8    b5:1;
        UINT8    b6:1;
        UINT8    b7:1;
        UINT8    b8:1;
        UINT8    b9:1;
        UINT8    b10:1;
        UINT8    b11:1;
        UINT8    b12:1;
        UINT8    b13:1;
        UINT8    b14:1;
        UINT8    b15:1;
    } bit;
    struct{
        UINT8    low;                /* low  8 bit */
        UINT8    high;               /* high 8 bit */
    } byte;
    UINT16  word;
} AD03_ADDR;
AD03_ADDR	ad03_addr;

#define		AD03 ad03_addr.word           /* A-D0 register 3 16 bit */
#define		AD03L    ad03_addr.byte.low           /* A-D0 register 3 low  8 bit */
#define		AD03H    ad03_addr.byte.high          /* A-D0 register 3 high 8 bit */

/*----------------------------------------------------*/
#pragma ADDRESS     ad04_addr   0388H       /* A-D0 register 4 */
typedef union {
    struct{
        UINT8    b0:1;
        UINT8    b1:1;
        UINT8    b2:1;
        UINT8    b3:1;
        UINT8    b4:1;
        UINT8    b5:1;
        UINT8    b6:1;
        UINT8    b7:1;
        UINT8    b8:1;
        UINT8    b9:1;
        UINT8    b10:1;
        UINT8    b11:1;
        UINT8    b12:1;
        UINT8    b13:1;
        UINT8    b14:1;
        UINT8    b15:1;
    } bit;
    struct{
        UINT8    low;                /* low  8 bit */
        UINT8    high;               /* high 8 bit */
    } byte;
    UINT16  word;
} AD04_ADDR;
AD04_ADDR	ad04_addr;

#define		AD04 ad04_addr.word           /* A-D0 register 4 16 bit */
#define		AD04L    ad04_addr.byte.low           /* A-D0 register 4 low  8 bit */
#define		AD04H    ad04_addr.byte.high          /* A-D0 register 4 high 8 bit */

/*----------------------------------------------------*/
#pragma ADDRESS     ad05_addr   038aH       /* A-D0 register 5 */
typedef union {
    struct{
        UINT8    b0:1;
        UINT8    b1:1;
        UINT8    b2:1;
        UINT8    b3:1;
        UINT8    b4:1;
        UINT8    b5:1;
        UINT8    b6:1;
        UINT8    b7:1;
        UINT8    b8:1;
        UINT8    b9:1;
        UINT8    b10:1;
        UINT8    b11:1;
        UINT8    b12:1;
        UINT8    b13:1;
        UINT8    b14:1;
        UINT8    b15:1;
    } bit;
    struct{
        UINT8    low;                /* low  8 bit */
        UINT8    high;               /* high 8 bit */
    } byte;
    UINT16  word;
} AD05_ADDR;
AD05_ADDR	ad05_addr;

#define		AD05 ad05_addr.word           /* A-D0 register 5 16 bit */
#define		AD05L    ad05_addr.byte.low           /* A-D0 register 5 low  8 bit */
#define		AD05H    ad05_addr.byte.high          /* A-D0 register 5 high 8 bit */

/*----------------------------------------------------*/
#pragma ADDRESS     ad06_addr   038cH       /* A-D0 register 6 */
typedef union {
    struct{
        UINT8    b0:1;
        UINT8    b1:1;
        UINT8    b2:1;
        UINT8    b3:1;
        UINT8    b4:1;
        UINT8    b5:1;
        UINT8    b6:1;
        UINT8    b7:1;
        UINT8    b8:1;
        UINT8    b9:1;
        UINT8    b10:1;
        UINT8    b11:1;
        UINT8    b12:1;
        UINT8    b13:1;
        UINT8    b14:1;
        UINT8    b15:1;
    } bit;
    struct{
        UINT8    low;                /* low  8 bit */
        UINT8    high;               /* high 8 bit */
    } byte;
    UINT16  word;
} AD06_ADDR;
AD06_ADDR	ad06_addr;

#define		AD06 ad06_addr.word           /* A-D0 register 6 16 bit */
#define		AD06L    ad06_addr.byte.low           /* A-D0 register 6 low  8 bit */
#define		AD06H    ad06_addr.byte.high          /* A-D0 register 6 high 8 bit */

/*----------------------------------------------------*/
#pragma ADDRESS     ad07_addr   038eH       /* A-D0 register 7 */
typedef union {
    struct{
        UINT8    b0:1;
        UINT8    b1:1;
        UINT8    b2:1;
        UINT8    b3:1;
        UINT8    b4:1;
        UINT8    b5:1;
        UINT8    b6:1;
        UINT8    b7:1;
        UINT8    b8:1;
        UINT8    b9:1;
        UINT8    b10:1;
        UINT8    b11:1;
        UINT8    b12:1;
        UINT8    b13:1;
        UINT8    b14:1;
        UINT8    b15:1;
    } bit;
    struct{
        UINT8    low;                /* low  8 bit */
        UINT8    high;               /* high 8 bit */
    } byte;
    UINT16  word;
} AD07_ADDR;
AD07_ADDR	ad07_addr;

#define		AD07 ad07_addr.word           /* A-D0 register 7 16 bit */
#define		AD07L    ad07_addr.byte.low           /* A-D0 register 7 low  8 bit */
#define		AD07H    ad07_addr.byte.high          /* A-D0 register 7 high 8 bit */

/*------------------------------------------------------
    A-D0 control register 2
------------------------------------------------------*/
#pragma ADDRESS     ad0con2_addr 0394H      /* A-D0 control register 2 */
typedef union {
	struct{
		UINT8	smp_ad0con2:1;
		UINT8	b1:1;
		UINT8	b2:1;
		UINT8	b3:1;
		UINT8	ads_ad0con2:1;
		UINT8	trg0_ad0con2:1;
		UINT8	trg1_ad0con2:1;
		UINT8	pst_ad0con2:1;
	} bit;
	 UINT8 byte;
} AD0CON2_ADDR;
AD0CON2_ADDR	ad0con2_addr;

#define		AD0CON2		ad0con2_addr.byte

#define		SMP_AD0CON2	ad0con2_addr.bit.smp_ad0con2
#define		ADS_AD0CON2	ad0con2_addr.bit.ads_ad0con2
#define		TRG0_AD0CON2	ad0con2_addr.bit.trg0_ad0con2
#define		TRG1_AD0CON2	ad0con2_addr.bit.trg1_ad0con2
#define		PST_AD0CON2	ad0con2_addr.bit.pst_ad0con2

/*------------------------------------------------------
    A-D0 control register 0
------------------------------------------------------*/
#pragma ADDRESS     ad0con0_addr 0396H      /* A-D0 control register 0 */
typedef union {
	struct{
		UINT8	ch0_ad0con0:1;
		UINT8	ch1_ad0con0:1;
		UINT8	ch2_ad0con0:1;
		UINT8	md0_ad0con0:1;
		UINT8	md1_ad0con0:1;
		UINT8	trg_ad0con0:1;
		UINT8	adst_ad0con0:1;
		UINT8	cks0_ad0con0:1;
	} bit;
	 UINT8 byte;
} AD0CON0_ADDR;
AD0CON0_ADDR	ad0con0_addr;

#define		AD0CON0		ad0con0_addr.byte

#define		CH0_AD0CON0	ad0con0_addr.bit.ch0_ad0con0
#define		CH1_AD0CON0	ad0con0_addr.bit.ch1_ad0con0
#define		CH2_AD0CON0	ad0con0_addr.bit.ch2_ad0con0
#define		MD0_AD0CON0	ad0con0_addr.bit.md0_ad0con0
#define		MD1_AD0CON0	ad0con0_addr.bit.md1_ad0con0
#define		TRG_AD0CON0	ad0con0_addr.bit.trg_ad0con0
#define		ADST_AD0CON0	ad0con0_addr.bit.adst_ad0con0
#define		CKS0_AD0CON0	ad0con0_addr.bit.cks0_ad0con0

/*------------------------------------------------------
    A-D0 control  register 1
------------------------------------------------------*/
#pragma ADDRESS     ad0con1_addr 0397H      /* A-D0 control register 1 */
typedef union {
	struct{
		UINT8	scan0_ad0con1:1;
		UINT8	scan1_ad0con1:1;
		UINT8	md2_ad0con1:1;
		UINT8	bits_ad0con1:1;
		UINT8	cks1_ad0con1:1;
		UINT8	vcut_ad0con1:1;
		UINT8	opa0_ad0con1:1;
		UINT8	opa1_ad0con1:1;
	} bit;
	 UINT8 byte;
} AD0CON1_ADDR;
AD0CON1_ADDR	ad0con1_addr;

#define		AD0CON1		ad0con1_addr.byte

#define		SCAN0_AD0CON1	ad0con1_addr.bit.scan0_ad0con1
#define		SCAN1_AD0CON1	ad0con1_addr.bit.scan1_ad0con1
#define		MD2_AD0CON1	ad0con1_addr.bit.md2_ad0con1
#define		BITS_AD0CON1	ad0con1_addr.bit.bits_ad0con1
#define		CKS1_AD0CON1	ad0con1_addr.bit.cks1_ad0con1
#define		VCUT_AD0CON1	ad0con1_addr.bit.vcut_ad0con1
#define		OPA0_AD0CON1	ad0con1_addr.bit.opa0_ad0con1
#define		OPA1_AD0CON1	ad0con1_addr.bit.opa1_ad0con1

/*------------------------------------------------------
    D-A register 0
------------------------------------------------------*/
#pragma ADDRESS     da0_addr    0398H       /* D-A register 0 */
UINT8   da0_addr;               /* D-A register 0 */

#define		DA0     da0_addr

/*------------------------------------------------------
    D-A register 1
------------------------------------------------------*/
#pragma ADDRESS     da1_addr    039aH       /* D-A register 1 */
UINT8   da1_addr;               /* D-A register 1 */

#define		DA1     da1_addr

/*------------------------------------------------------
    D-A control register
------------------------------------------------------*/
#pragma ADDRESS     dacon_addr  039cH       /* D-A control register */
typedef union {
	struct{
		UINT8	da0e:1;
		UINT8	da1e:1;
		UINT8	b2:1;
		UINT8	b3:1;
		UINT8	b4:1;
		UINT8	b5:1;
		UINT8	b6:1;
		UINT8	b7:1;
	} bit;
	 UINT8 byte;
} DACON_ADDR;
DACON_ADDR	dacon_addr;

#define		DACON		dacon_addr.byte

#define		DA0E		dacon_addr.bit.da0e
#define		DA1E		dacon_addr.bit.da1e

/*------------------------------------------------------
    Function select register A8
------------------------------------------------------*/
#pragma ADDRESS     ps8_addr    03a0H       /* Function select register A8 */
typedef union {
	struct{
		UINT8	ps8_0:1;
		UINT8	ps8_1:1;
		UINT8	ps8_2:1;
		UINT8	ps8_3:1;
		UINT8	b4:1;
		UINT8	b5:1;
		UINT8	b6:1;
		UINT8	b7:1;
	} bit;
	 UINT8 byte;
} PS8_ADDR;
PS8_ADDR	ps8_addr;

#define		PS8			ps8_addr.byte

#define		PS8_0		ps8_addr.bit.ps8_0
#define		PS8_1		ps8_addr.bit.ps8_1
#define		PS8_2		ps8_addr.bit.ps8_2
#define		PS8_3		ps8_addr.bit.ps8_3

/*------------------------------------------------------
    Function select register A9
------------------------------------------------------*/
#pragma ADDRESS     ps9_addr    03a1H       /* Function select register A9 */
typedef union {
	struct{
		UINT8	ps9_0:1;
		UINT8	ps9_1:1;
		UINT8	b2:1;
		UINT8	b3:1;
		UINT8	ps9_4:1;
		UINT8	ps9_5:1;
		UINT8	b6:1;
		UINT8	b7:1;
	} bit;
	 UINT8 byte;
} PS9_ADDR;
PS9_ADDR	ps9_addr;

#define		PS9			ps9_addr.byte

#define		PS9_0		ps9_addr.bit.ps9_0
#define		PS9_1		ps9_addr.bit.ps9_1
#define		PS9_4		ps9_addr.bit.ps9_4
#define		PS9_5		ps9_addr.bit.ps9_5

/*------------------------------------------------------
    Function select register C
------------------------------------------------------*/
#pragma ADDRESS     psc_addr    03afH       /* Function select register C */
typedef union {
	struct{
		UINT8	psc_0:1;
		UINT8	psc_1:1;
		UINT8	psc_2:1;
		UINT8	psc_3:1;
		UINT8	psc_4:1;
		UINT8	b5:1;
		UINT8	psc_6:1;
		UINT8	psc_7:1;
	} bit;
	 UINT8 byte;
} PSC_ADDR;
PSC_ADDR	psc_addr;

#define		PSC			psc_addr.byte

#define		PSC_0		psc_addr.bit.psc_0
#define		PSC_1		psc_addr.bit.psc_1
#define		PSC_2		psc_addr.bit.psc_2
#define		PSC_3		psc_addr.bit.psc_3
#define		PSC_4		psc_addr.bit.psc_4
#define		PSC_6		psc_addr.bit.psc_6
#define		PSC_7		psc_addr.bit.psc_7

/*------------------------------------------------------
    Function select register A0
------------------------------------------------------*/
#pragma ADDRESS     ps0_addr    03b0H       /* Function select register A0 */
typedef union {
	struct{
		UINT8	ps0_0:1;
		UINT8	ps0_1:1;
		UINT8	ps0_2:1;
		UINT8	ps0_3:1;
		UINT8	ps0_4:1;
		UINT8	ps0_5:1;
		UINT8	ps0_6:1;
		UINT8	ps0_7:1;
	} bit;
	 UINT8 byte;
} PS0_ADDR;
PS0_ADDR	ps0_addr;

#define		PS0			ps0_addr.byte

#define		PS0_0		ps0_addr.bit.ps0_0
#define		PS0_1		ps0_addr.bit.ps0_1
#define		PS0_2		ps0_addr.bit.ps0_2
#define		PS0_3		ps0_addr.bit.ps0_3
#define		PS0_4		ps0_addr.bit.ps0_4
#define		PS0_5		ps0_addr.bit.ps0_5
#define		PS0_6		ps0_addr.bit.ps0_6
#define		PS0_7		ps0_addr.bit.ps0_7

/*------------------------------------------------------
    Function select register A1
------------------------------------------------------*/
#pragma ADDRESS     ps1_addr    03b1H       /* Function select register A1 */
typedef union {
	struct{
		UINT8	ps1_0:1;
		UINT8	ps1_1:1;
		UINT8	ps1_2:1;
		UINT8	ps1_3:1;
		UINT8	ps1_4:1;
		UINT8	ps1_5:1;
		UINT8	ps1_6:1;
		UINT8	ps1_7:1;
	} bit;
	 UINT8 byte;
} PS1_ADDR;
PS1_ADDR	ps1_addr;

#define		PS1			ps1_addr.byte

#define		PS1_0		ps1_addr.bit.ps1_0
#define		PS1_1		ps1_addr.bit.ps1_1
#define		PS1_2		ps1_addr.bit.ps1_2
#define		PS1_3		ps1_addr.bit.ps1_3
#define		PS1_4		ps1_addr.bit.ps1_4
#define		PS1_5		ps1_addr.bit.ps1_5
#define		PS1_6		ps1_addr.bit.ps1_6
#define		PS1_7		ps1_addr.bit.ps1_7

/*------------------------------------------------------
    Function select register B0
------------------------------------------------------*/
#pragma ADDRESS     psl0_addr   03b2H       /* Function select register B0 */
typedef union {
	struct{
		UINT8	b0:1;
		UINT8	b1:1;
		UINT8	psl0_2:1;
		UINT8	b3:1;
		UINT8	psl0_4:1;
		UINT8	b5:1;
		UINT8	psl0_6:1;
		UINT8	b7:1;
	} bit;
	 UINT8 byte;
} PSL0_ADDR;
PSL0_ADDR	psl0_addr;

#define		PSL0		psl0_addr.byte

#define		PSL0_2		psl0_addr.bit.psl0_2
#define		PSL0_4		psl0_addr.bit.psl0_4
#define		PSL0_6		psl0_addr.bit.psl0_6

/*------------------------------------------------------
    Function select register B1
------------------------------------------------------*/
#pragma ADDRESS     psl1_addr   03b3H       /* Function select register B1 */
typedef union {
	struct{
		UINT8	psl1_0:1;
		UINT8	psl1_1:1;
		UINT8	psl1_2:1;
		UINT8	psl1_3:1;
		UINT8	psl1_4:1;
		UINT8	psl1_5:1;
		UINT8	psl1_6:1;
		UINT8	b7:1;
	} bit;
	 UINT8 byte;
} PSL1_ADDR;
PSL1_ADDR	psl1_addr;

#define		PSL1		psl1_addr.byte

#define		PSL1_0		psl1_addr.bit.psl1_0
#define		PSL1_1		psl1_addr.bit.psl1_1
#define		PSL1_2		psl1_addr.bit.psl1_2
#define		PSL1_3		psl1_addr.bit.psl1_3
#define		PSL1_4		psl1_addr.bit.psl1_4
#define		PSL1_5		psl1_addr.bit.psl1_5
#define		PSL1_6		psl1_addr.bit.psl1_6

/*------------------------------------------------------
    Function select register A2
------------------------------------------------------*/
#pragma ADDRESS     ps2_addr    03b4H       /* Function select register A2 */
typedef union {
	struct{
		UINT8	ps2_0:1;
		UINT8	ps2_1:1;
		UINT8	ps2_2:1;
		UINT8	b3:1;
		UINT8	b4:1;
		UINT8	b5:1;
		UINT8	b6:1;
		UINT8	b7:1;
	} bit;
	 UINT8 byte;
} PS2_ADDR;
PS2_ADDR	ps2_addr;

#define		PS2			ps2_addr.byte

#define		PS2_0		ps2_addr.bit.ps2_0
#define		PS2_1		ps2_addr.bit.ps2_1
#define		PS2_2		ps2_addr.bit.ps2_2

/*------------------------------------------------------
    Function select register A3
------------------------------------------------------*/
#pragma ADDRESS     ps3_addr    03b5H       /* Function select register A3 */
typedef union {
	struct{
		UINT8	ps3_0:1;
		UINT8	ps3_1:1;
		UINT8	ps3_2:1;
		UINT8	ps3_3:1;
		UINT8	ps3_4:1;
		UINT8	ps3_5:1;
		UINT8	ps3_6:1;
		UINT8	ps3_7:1;
	} bit;
	 UINT8 byte;
} PS3_ADDR;
PS3_ADDR	ps3_addr;

#define		PS3			ps3_addr.byte

#define		PS3_0		ps3_addr.bit.ps3_0
#define		PS3_1		ps3_addr.bit.ps3_1
#define		PS3_2		ps3_addr.bit.ps3_2
#define		PS3_3		ps3_addr.bit.ps3_3
#define		PS3_4		ps3_addr.bit.ps3_4
#define		PS3_5		ps3_addr.bit.ps3_5
#define		PS3_6		ps3_addr.bit.ps3_6
#define		PS3_7		ps3_addr.bit.ps3_7

/*------------------------------------------------------
    Function select register B2
------------------------------------------------------*/
#pragma ADDRESS     psl2_addr   03b6H       /* Function select register B2 */
typedef union {
	struct{
		UINT8	psl2_0:1;
		UINT8	psl2_1:1;
		UINT8	psl2_2:1;
		UINT8	b3:1;
		UINT8	b4:1;
		UINT8	b5:1;
		UINT8	b6:1;
		UINT8	b7:1;
	} bit;
	 UINT8 byte;
} PSL2_ADDR;
PSL2_ADDR	psl2_addr;

#define		PSL2		psl2_addr.byte

#define		PSL2_0		psl2_addr.bit.psl2_0
#define		PSL2_1		psl2_addr.bit.psl2_1
#define		PSL2_2		psl2_addr.bit.psl2_2
/*------------------------------------------------------
    Function select register B3
------------------------------------------------------*/
#pragma ADDRESS     psl3_addr   03b7H       /* Function select register B3 */
typedef union {
	struct{
		UINT8	b0:1;
		UINT8	psl3_1:1;
		UINT8	psl3_2:1;
		UINT8	psl3_3:1;
		UINT8	psl3_4:1;
		UINT8	psl3_5:1;
		UINT8	psl3_6:1;
		UINT8	psl3_7:1;
	} bit;
	 UINT8 byte;
} PSL3_ADDR;
PSL3_ADDR	psl3_addr;

#define		PSL3		psl3_addr.byte

#define		PSL3_1		psl3_addr.bit.psl3_1
#define		PSL3_2		psl3_addr.bit.psl3_2
#define		PSL3_3		psl3_addr.bit.psl3_3
#define		PSL3_4		psl3_addr.bit.psl3_4
#define		PSL3_5		psl3_addr.bit.psl3_5
#define		PSL3_6		psl3_addr.bit.psl3_6
#define		PSL3_7		psl3_addr.bit.psl3_7

/*------------------------------------------------------
    Function select register A5
------------------------------------------------------*/
#pragma ADDRESS     ps5_addr    03b9H       /* Function select register A5 */
typedef union {
	struct{
		UINT8	ps5_0:1;
		UINT8	ps5_1:1;
		UINT8	ps5_2:1;
		UINT8	ps5_3:1;
		UINT8	b4:1;
		UINT8	b5:1;
		UINT8	b6:1;
		UINT8	b7:1;
	} bit;
	 UINT8 byte;
} PS5_ADDR;
PS5_ADDR	ps5_addr;

#define		PS5			ps5_addr.byte

#define		PS5_0		ps5_addr.bit.ps5_0
#define		PS5_1		ps5_addr.bit.ps5_1
#define		PS5_2		ps5_addr.bit.ps5_2
#define		PS5_3		ps5_addr.bit.ps5_3

/*------------------------------------------------------
    Function select register A6
------------------------------------------------------*/
#pragma ADDRESS     ps6_addr    03bcH       /* Function select register A6 */
typedef union {
	struct{
		UINT8	ps6_0:1;
		UINT8	ps6_1:1;
		UINT8	ps6_2:1;
		UINT8	ps6_3:1;
		UINT8	ps6_4:1;
		UINT8	ps6_5:1;
		UINT8	ps6_6:1;
		UINT8	ps6_7:1;
	} bit;
	 UINT8 byte;
} PS6_ADDR;
PS6_ADDR	ps6_addr;

#define		PS6			ps6_addr.byte

#define		PS6_0		ps6_addr.bit.ps6_0
#define		PS6_1		ps6_addr.bit.ps6_1
#define		PS6_2		ps6_addr.bit.ps6_2
#define		PS6_3		ps6_addr.bit.ps6_3
#define		PS6_4		ps6_addr.bit.ps6_4
#define		PS6_5		ps6_addr.bit.ps6_5
#define		PS6_6		ps6_addr.bit.ps6_6
#define		PS6_7		ps6_addr.bit.ps6_7

/*------------------------------------------------------
    Function select register A7
------------------------------------------------------*/
#pragma ADDRESS     ps7_addr    03bdH       /* Function select register A7 */
typedef union {
	struct{
		UINT8	ps7_0:1;
		UINT8	ps7_1:1;
		UINT8	ps7_2:1;
		UINT8	ps7_3:1;
		UINT8	ps7_4:1;
		UINT8	ps7_5:1;
		UINT8	ps7_6:1;
		UINT8	ps7_7:1;
	} bit;
	 UINT8 byte;
} PS7_ADDR;
PS7_ADDR	ps7_addr;

#define		PS7			ps7_addr.byte

#define		PS7_0		ps7_addr.bit.ps7_0
#define		PS7_1		ps7_addr.bit.ps7_1
#define		PS7_2		ps7_addr.bit.ps7_2
#define		PS7_3		ps7_addr.bit.ps7_3
#define		PS7_4		ps7_addr.bit.ps7_4
#define		PS7_5		ps7_addr.bit.ps7_5
#define		PS7_6		ps7_addr.bit.ps7_6
#define		PS7_7		ps7_addr.bit.ps7_7

/*------------------------------------------------------
    Port P6
------------------------------------------------------*/
#pragma ADDRESS     p6_addr     03c0H       /* Port P6 register */
typedef union {
	struct{
		UINT8	p6_0:1;
		UINT8	p6_1:1;
		UINT8	p6_2:1;
		UINT8	p6_3:1;
		UINT8	p6_4:1;
		UINT8	p6_5:1;
		UINT8	p6_6:1;
		UINT8	p6_7:1;
	} bit;
	 UINT8 byte;
} P6_ADDR;
P6_ADDR	p6_addr;

#define		P6			p6_addr.byte

#define		P6_0		p6_addr.bit.p6_0
#define		P6_1		p6_addr.bit.p6_1
#define		P6_2		p6_addr.bit.p6_2
#define		P6_3		p6_addr.bit.p6_3
#define		P6_4		p6_addr.bit.p6_4
#define		P6_5		p6_addr.bit.p6_5
#define		P6_6		p6_addr.bit.p6_6
#define		P6_7		p6_addr.bit.p6_7

/*------------------------------------------------------
    Port P7
------------------------------------------------------*/
#pragma ADDRESS     p7_addr     03c1H       /* Port P7 register */
typedef union {
	struct{
		UINT8	p7_0:1;
		UINT8	p7_1:1;
		UINT8	p7_2:1;
		UINT8	p7_3:1;
		UINT8	p7_4:1;
		UINT8	p7_5:1;
		UINT8	p7_6:1;
		UINT8	p7_7:1;
	} bit;
	 UINT8 byte;
} P7_ADDR;
P7_ADDR	p7_addr;

#define		P7			p7_addr.byte

#define		P7_0		p7_addr.bit.p7_0
#define		P7_1		p7_addr.bit.p7_1
#define		P7_2		p7_addr.bit.p7_2
#define		P7_3		p7_addr.bit.p7_3
#define		P7_4		p7_addr.bit.p7_4
#define		P7_5		p7_addr.bit.p7_5
#define		P7_6		p7_addr.bit.p7_6
#define		P7_7		p7_addr.bit.p7_7

/*------------------------------------------------------
    Port P6 direction register
------------------------------------------------------*/
#pragma ADDRESS     pd6_addr    03c2H       /* Port P6 direction register */
typedef union {
	struct{
		UINT8	pd6_0:1;
		UINT8	pd6_1:1;
		UINT8	pd6_2:1;
		UINT8	pd6_3:1;
		UINT8	pd6_4:1;
		UINT8	pd6_5:1;
		UINT8	pd6_6:1;
		UINT8	pd6_7:1;
	} bit;
	 UINT8 byte;
} PD6_ADDR;
PD6_ADDR	pd6_addr;

#define		PD6			pd6_addr.byte

#define		PD6_0		pd6_addr.bit.pd6_0
#define		PD6_1		pd6_addr.bit.pd6_1
#define		PD6_2		pd6_addr.bit.pd6_2
#define		PD6_3		pd6_addr.bit.pd6_3
#define		PD6_4		pd6_addr.bit.pd6_4
#define		PD6_5		pd6_addr.bit.pd6_5
#define		PD6_6		pd6_addr.bit.pd6_6
#define		PD6_7		pd6_addr.bit.pd6_7

/*------------------------------------------------------
    Port P7 direction register
------------------------------------------------------*/
#pragma ADDRESS     pd7_addr    03c3H       /* Port P7 direction register */
typedef union {
	struct{
		UINT8	pd7_0:1;
		UINT8	pd7_1:1;
		UINT8	pd7_2:1;
		UINT8	pd7_3:1;
		UINT8	pd7_4:1;
		UINT8	pd7_5:1;
		UINT8	pd7_6:1;
		UINT8	pd7_7:1;
	} bit;
	 UINT8 byte;
} PD7_ADDR;
PD7_ADDR	pd7_addr;

#define		PD7			pd7_addr.byte

#define		PD7_0		pd7_addr.bit.pd7_0
#define		PD7_1		pd7_addr.bit.pd7_1
#define		PD7_2		pd7_addr.bit.pd7_2
#define		PD7_3		pd7_addr.bit.pd7_3
#define		PD7_4		pd7_addr.bit.pd7_4
#define		PD7_5		pd7_addr.bit.pd7_5
#define		PD7_6		pd7_addr.bit.pd7_6
#define		PD7_7		pd7_addr.bit.pd7_7

/*------------------------------------------------------
    Port P8
------------------------------------------------------*/
#pragma ADDRESS     p8_addr     03c4H       /* Port P8 register */
typedef union {
	struct{
		UINT8	p8_0:1;
		UINT8	p8_1:1;
		UINT8	p8_2:1;
		UINT8	p8_3:1;
		UINT8	p8_4:1;
		UINT8	p8_5:1;
		UINT8	p8_6:1;
		UINT8	p8_7:1;
	} bit;
	 UINT8 byte;
} P8_ADDR;
P8_ADDR	p8_addr;

#define		P8			p8_addr.byte

#define		P8_0		p8_addr.bit.p8_0
#define		P8_1		p8_addr.bit.p8_1
#define		P8_2		p8_addr.bit.p8_2
#define		P8_3		p8_addr.bit.p8_3
#define		P8_4		p8_addr.bit.p8_4
#define		P8_5		p8_addr.bit.p8_5
#define		P8_6		p8_addr.bit.p8_6
#define		P8_7		p8_addr.bit.p8_7

/*------------------------------------------------------
    Port P9
------------------------------------------------------*/
#pragma ADDRESS     p9_addr     03c5H       /* Port P9 register */
typedef union {
	struct{
		UINT8	p9_0:1;
		UINT8	p9_1:1;
		UINT8	p9_2:1;
		UINT8	p9_3:1;
		UINT8	p9_4:1;
		UINT8	p9_5:1;
		UINT8	p9_6:1;
		UINT8	p9_7:1;
	} bit;
	 UINT8 byte;
} P9_ADDR;
P9_ADDR	p9_addr;

#define		P9			p9_addr.byte

#define		P9_0		p9_addr.bit.p9_0
#define		P9_1		p9_addr.bit.p9_1
#define		P9_2		p9_addr.bit.p9_2
#define		P9_3		p9_addr.bit.p9_3
#define		P9_4		p9_addr.bit.p9_4
#define		P9_5		p9_addr.bit.p9_5
#define		P9_6		p9_addr.bit.p9_6
#define		P9_7		p9_addr.bit.p9_7

/*------------------------------------------------------
    Port P8 direction register
------------------------------------------------------*/
#pragma ADDRESS     pd8_addr    03c6H       /* Port P8 direction register */
typedef union {
	struct{
		UINT8	pd8_0:1;
		UINT8	pd8_1:1;
		UINT8	pd8_2:1;
		UINT8	pd8_3:1;
		UINT8	pd8_4:1;
		UINT8	b5:1;
		UINT8	pd8_6:1;
		UINT8	pd8_7:1;
	} bit;
	 UINT8 byte;
} PD8_ADDR;
PD8_ADDR	pd8_addr;

#define		PD8			pd8_addr.byte

#define		PD8_0		pd8_addr.bit.pd8_0
#define		PD8_1		pd8_addr.bit.pd8_1
#define		PD8_2		pd8_addr.bit.pd8_2
#define		PD8_3		pd8_addr.bit.pd8_3
#define		PD8_4		pd8_addr.bit.pd8_4
#define		PD8_6		pd8_addr.bit.pd8_6
#define		PD8_7		pd8_addr.bit.pd8_7

/*------------------------------------------------------
    Port P9 direction register
------------------------------------------------------*/
#pragma ADDRESS     pd9_addr    03c7H       /* Port P9 direction register */
typedef union {
	struct{
		UINT8	pd9_0:1;
		UINT8	pd9_1:1;
		UINT8	pd9_2:1;
		UINT8	pd9_3:1;
		UINT8	pd9_4:1;
		UINT8	pd9_5:1;
		UINT8	pd9_6:1;
		UINT8	pd9_7:1;
	} bit;
	 UINT8 byte;
} PD9_ADDR;
PD9_ADDR	pd9_addr;

#define		PD9			pd9_addr.byte

#define		PD9_0		pd9_addr.bit.pd9_0
#define		PD9_1		pd9_addr.bit.pd9_1
#define		PD9_2		pd9_addr.bit.pd9_2
#define		PD9_3		pd9_addr.bit.pd9_3
#define		PD9_4		pd9_addr.bit.pd9_4
#define		PD9_5		pd9_addr.bit.pd9_5
#define		PD9_6		pd9_addr.bit.pd9_6
#define		PD9_7		pd9_addr.bit.pd9_7

/*------------------------------------------------------
    Port P10
------------------------------------------------------*/
#pragma ADDRESS     p10_addr    03c8H       /* Port P10 register */
typedef union {
	struct{
		UINT8	p10_0:1;
		UINT8	p10_1:1;
		UINT8	p10_2:1;
		UINT8	p10_3:1;
		UINT8	p10_4:1;
		UINT8	p10_5:1;
		UINT8	p10_6:1;
		UINT8	p10_7:1;
	} bit;
	 UINT8 byte;
} P10_ADDR;
P10_ADDR	p10_addr;

#define		P10			p10_addr.byte

#define		P10_0		p10_addr.bit.p10_0
#define		P10_1		p10_addr.bit.p10_1
#define		P10_2		p10_addr.bit.p10_2
#define		P10_3		p10_addr.bit.p10_3
#define		P10_4		p10_addr.bit.p10_4
#define		P10_5		p10_addr.bit.p10_5
#define		P10_6		p10_addr.bit.p10_6
#define		P10_7		p10_addr.bit.p10_7

/*------------------------------------------------------
    Port P11
------------------------------------------------------*/
#pragma ADDRESS     p11_addr    03c9H       /* Port P11 register */
typedef union {
	struct{
		UINT8	p11_0:1;
		UINT8	p11_1:1;
		UINT8	p11_2:1;
		UINT8	p11_3:1;
		UINT8	p11_4:1;
		UINT8	b5:1;
		UINT8	b6:1;
		UINT8	b7:1;
	} bit;
	 UINT8 byte;
} P11_ADDR;
P11_ADDR	p11_addr;

#define		P11			p11_addr.byte

#define		P11_0		p11_addr.bit.p11_0
#define		P11_1		p11_addr.bit.p11_1
#define		P11_2		p11_addr.bit.p11_2
#define		P11_3		p11_addr.bit.p11_3
#define		P11_4		p11_addr.bit.p11_4

/*------------------------------------------------------
    Port P10 direction register
------------------------------------------------------*/
#pragma ADDRESS     pd10_addr   03caH       /* Port P10 direction register */
typedef union {
	struct{
		UINT8	pd10_0:1;
		UINT8	pd10_1:1;
		UINT8	pd10_2:1;
		UINT8	pd10_3:1;
		UINT8	pd10_4:1;
		UINT8	pd10_5:1;
		UINT8	pd10_6:1;
		UINT8	pd10_7:1;
	} bit;
	 UINT8 byte;
} PD10_ADDR;
PD10_ADDR	pd10_addr;

#define		PD10		pd10_addr.byte

#define		PD10_0		pd10_addr.bit.pd10_0
#define		PD10_1		pd10_addr.bit.pd10_1
#define		PD10_2		pd10_addr.bit.pd10_2
#define		PD10_3		pd10_addr.bit.pd10_3
#define		PD10_4		pd10_addr.bit.pd10_4
#define		PD10_5		pd10_addr.bit.pd10_5
#define		PD10_6		pd10_addr.bit.pd10_6
#define		PD10_7		pd10_addr.bit.pd10_7

/*------------------------------------------------------
    Port P11 direction register
------------------------------------------------------*/
#pragma ADDRESS     pd11_addr   03cbH       /* Port P11 direction register */
typedef union {
	struct{
		UINT8	pd11_0:1;
		UINT8	pd11_1:1;
		UINT8	pd11_2:1;
		UINT8	pd11_3:1;
		UINT8	pd11_4:1;
		UINT8	b5:1;
		UINT8	b6:1;
		UINT8	b7:1;
	} bit;
	 UINT8 byte;
} PD11_ADDR;
PD11_ADDR	pd11_addr;

#define		PD11		pd11_addr.byte

#define		PD11_0		pd11_addr.bit.pd11_0
#define		PD11_1		pd11_addr.bit.pd11_1
#define		PD11_2		pd11_addr.bit.pd11_2
#define		PD11_3		pd11_addr.bit.pd11_3
#define		PD11_4		pd11_addr.bit.pd11_4

/*------------------------------------------------------
    Port P12
------------------------------------------------------*/
#pragma ADDRESS     p12_addr    03ccH       /* Port P12 register */
typedef union {
	struct{
		UINT8	p12_0:1;
		UINT8	p12_1:1;
		UINT8	p12_2:1;
		UINT8	p12_3:1;
		UINT8	p12_4:1;
		UINT8	p12_5:1;
		UINT8	p12_6:1;
		UINT8	p12_7:1;
	} bit;
	 UINT8 byte;
} P12_ADDR;
P12_ADDR	p12_addr;

#define		P12			p12_addr.byte

#define		P12_0		p12_addr.bit.p12_0
#define		P12_1		p12_addr.bit.p12_1
#define		P12_2		p12_addr.bit.p12_2
#define		P12_3		p12_addr.bit.p12_3
#define		P12_4		p12_addr.bit.p12_4
#define		P12_5		p12_addr.bit.p12_5
#define		P12_6		p12_addr.bit.p12_6
#define		P12_7		p12_addr.bit.p12_7

/*------------------------------------------------------
    Port P13
------------------------------------------------------*/
#pragma ADDRESS     p13_addr    03cdH       /* Port P13 register */
typedef union {
	struct{
		UINT8	p13_0:1;
		UINT8	p13_1:1;
		UINT8	p13_2:1;
		UINT8	p13_3:1;
		UINT8	p13_4:1;
		UINT8	p13_5:1;
		UINT8	p13_6:1;
		UINT8	p13_7:1;
	} bit;
	 UINT8 byte;
} P13_ADDR;
P13_ADDR	p13_addr;

#define		P13			p13_addr.byte

#define		P13_0		p13_addr.bit.p13_0
#define		P13_1		p13_addr.bit.p13_1
#define		P13_2		p13_addr.bit.p13_2
#define		P13_3		p13_addr.bit.p13_3
#define		P13_4		p13_addr.bit.p13_4
#define		P13_5		p13_addr.bit.p13_5
#define		P13_6		p13_addr.bit.p13_6
#define		P13_7		p13_addr.bit.p13_7

/*------------------------------------------------------
    Port P12 direction register
------------------------------------------------------*/
#pragma ADDRESS     pd12_addr   03ceH       /* Port P12 direction register */
typedef union {
	struct{
		UINT8	pd12_0:1;
		UINT8	pd12_1:1;
		UINT8	pd12_2:1;
		UINT8	pd12_3:1;
		UINT8	pd12_4:1;
		UINT8	pd12_5:1;
		UINT8	pd12_6:1;
		UINT8	pd12_7:1;
	} bit;
	 UINT8 byte;
} PD12_ADDR;
PD12_ADDR	pd12_addr;

#define		PD12		pd12_addr.byte

#define		PD12_0		pd12_addr.bit.pd12_0
#define		PD12_1		pd12_addr.bit.pd12_1
#define		PD12_2		pd12_addr.bit.pd12_2
#define		PD12_3		pd12_addr.bit.pd12_3
#define		PD12_4		pd12_addr.bit.pd12_4
#define		PD12_5		pd12_addr.bit.pd12_5
#define		PD12_6		pd12_addr.bit.pd12_6
#define		PD12_7		pd12_addr.bit.pd12_7

/*------------------------------------------------------
    Port P13 direction register
------------------------------------------------------*/
#pragma ADDRESS     pd13_addr   03cfH       /* Port P13 direction register */
typedef union {
	struct{
		UINT8	pd13_0:1;
		UINT8	pd13_1:1;
		UINT8	pd13_2:1;
		UINT8	pd13_3:1;
		UINT8	pd13_4:1;
		UINT8	pd13_5:1;
		UINT8	pd13_6:1;
		UINT8	pd13_7:1;
	} bit;
	 UINT8 byte;
} PD13_ADDR;
PD13_ADDR	pd13_addr;

#define		PD13		pd13_addr.byte

#define		PD13_0		pd13_addr.bit.pd13_0
#define		PD13_1		pd13_addr.bit.pd13_1
#define		PD13_2		pd13_addr.bit.pd13_2
#define		PD13_3		pd13_addr.bit.pd13_3
#define		PD13_4		pd13_addr.bit.pd13_4
#define		PD13_5		pd13_addr.bit.pd13_5
#define		PD13_6		pd13_addr.bit.pd13_6
#define		PD13_7		pd13_addr.bit.pd13_7

/*------------------------------------------------------
    Port P14
------------------------------------------------------*/
#pragma ADDRESS     p14_addr    03d0H       /* Port P14 register */
typedef union {
	struct{
		UINT8	p14_0:1;
		UINT8	p14_1:1;
		UINT8	p14_2:1;
		UINT8	p14_3:1;
		UINT8	p14_4:1;
		UINT8	p14_5:1;
		UINT8	p14_6:1;
		UINT8	b7:1;
	} bit;
	 UINT8 byte;
} P14_ADDR;
P14_ADDR	p14_addr;

#define		P14			p14_addr.byte

#define		P14_0		p14_addr.bit.p14_0
#define		P14_1		p14_addr.bit.p14_1
#define		P14_2		p14_addr.bit.p14_2
#define		P14_3		p14_addr.bit.p14_3
#define		P14_4		p14_addr.bit.p14_4
#define		P14_5		p14_addr.bit.p14_5
#define		P14_6		p14_addr.bit.p14_6

/*------------------------------------------------------
    Port P15
------------------------------------------------------*/
#pragma ADDRESS     p15_addr    03d1H       /* Port P15 register */
typedef union {
	struct{
		UINT8	p15_0:1;
		UINT8	p15_1:1;
		UINT8	p15_2:1;
		UINT8	p15_3:1;
		UINT8	p15_4:1;
		UINT8	p15_5:1;
		UINT8	p15_6:1;
		UINT8	p15_7:1;
	} bit;
	 UINT8 byte;
} P15_ADDR;
P15_ADDR	p15_addr;

#define		P15			p15_addr.byte

#define		P15_0		p15_addr.bit.p15_0
#define		P15_1		p15_addr.bit.p15_1
#define		P15_2		p15_addr.bit.p15_2
#define		P15_3		p15_addr.bit.p15_3
#define		P15_4		p15_addr.bit.p15_4
#define		P15_5		p15_addr.bit.p15_5
#define		P15_6		p15_addr.bit.p15_6
#define		P15_7		p15_addr.bit.p15_7

/*------------------------------------------------------
    Port P14 direction register
------------------------------------------------------*/
#pragma ADDRESS     pd14_addr   03d2H       /* Port P14 direction register */
typedef union {
	struct{
		UINT8	pd14_0:1;
		UINT8	pd14_1:1;
		UINT8	pd14_2:1;
		UINT8	pd14_3:1;
		UINT8	pd14_4:1;
		UINT8	pd14_5:1;
		UINT8	pd14_6:1;
		UINT8	b7:1;
	} bit;
	 UINT8 byte;
} PD14_ADDR;
PD14_ADDR	pd14_addr;

#define		PD14		pd14_addr.byte

#define		PD14_0		pd14_addr.bit.pd14_0
#define		PD14_1		pd14_addr.bit.pd14_1
#define		PD14_2		pd14_addr.bit.pd14_2
#define		PD14_3		pd14_addr.bit.pd14_3
#define		PD14_4		pd14_addr.bit.pd14_4
#define		PD14_5		pd14_addr.bit.pd14_5
#define		PD14_6		pd14_addr.bit.pd14_6

/*------------------------------------------------------
    Port P15 direction register
------------------------------------------------------*/
#pragma ADDRESS     pd15_addr   03d3H       /* Port P15 direction register */
typedef union {
	struct{
		UINT8	pd15_0:1;
		UINT8	pd15_1:1;
		UINT8	pd15_2:1;
		UINT8	pd15_3:1;
		UINT8	pd15_4:1;
		UINT8	pd15_5:1;
		UINT8	pd15_6:1;
		UINT8	pd15_7:1;
	} bit;
	 UINT8 byte;
} PD15_ADDR;
PD15_ADDR	pd15_addr;

#define		PD15		pd15_addr.byte

#define		PD15_0		pd15_addr.bit.pd15_0
#define		PD15_1		pd15_addr.bit.pd15_1
#define		PD15_2		pd15_addr.bit.pd15_2
#define		PD15_3		pd15_addr.bit.pd15_3
#define		PD15_4		pd15_addr.bit.pd15_4
#define		PD15_5		pd15_addr.bit.pd15_5
#define		PD15_6		pd15_addr.bit.pd15_6
#define		PD15_7		pd15_addr.bit.pd15_7

/*------------------------------------------------------
    Pull-up control register 2
------------------------------------------------------*/
#pragma ADDRESS     pur2_addr   03daH       /* Pull-up control register 2 */
typedef union {
	struct{
		UINT8	pu20:1;
		UINT8	pu21:1;
		UINT8	pu22:1;
		UINT8	pu23:1;
		UINT8	pu24:1;
		UINT8	pu25:1;
		UINT8	pu26:1;
		UINT8	pu27:1;
	} bit;
	 UINT8 byte;
} PUR2_ADDR;
PUR2_ADDR	pur2_addr;

#define		PUR2		pur2_addr.byte

#define		PU20		pur2_addr.bit.pu20
#define		PU21		pur2_addr.bit.pu21
#define		PU22		pur2_addr.bit.pu22
#define		PU23		pur2_addr.bit.pu23
#define		PU24		pur2_addr.bit.pu24
#define		PU25		pur2_addr.bit.pu25
#define		PU26		pur2_addr.bit.pu26
#define		PU27		pur2_addr.bit.pu27

/*------------------------------------------------------
    Pull-up control register 3
------------------------------------------------------*/
#pragma ADDRESS     pur3_addr   03dbH       /* Pull-up control register 3 */
typedef union {
	struct{
		UINT8	pu30:1;
		UINT8	pu31:1;
		UINT8	pu32:1;
		UINT8	pu33:1;
		UINT8	pu34:1;
		UINT8	pu35:1;
		UINT8	pu36:1;
		UINT8	pu37:1;
	} bit;
	 UINT8 byte;
} PUR3_ADDR;
PUR3_ADDR	pur3_addr;

#define		PUR3		pur3_addr.byte

#define		PU30		pur3_addr.bit.pu30
#define		PU31		pur3_addr.bit.pu31
#define		PU32		pur3_addr.bit.pu32
#define		PU33		pur3_addr.bit.pu33
#define		PU34		pur3_addr.bit.pu34
#define		PU35		pur3_addr.bit.pu35
#define		PU36		pur3_addr.bit.pu36
#define		PU37		pur3_addr.bit.pu37

/*------------------------------------------------------
    Pull-up control register 4
------------------------------------------------------*/
#pragma ADDRESS     pur4_addr   03dcH       /* Pull-up control register 4 */
typedef union {
	struct{
		UINT8	pu40:1;
		UINT8	pu41:1;
		UINT8	pu42:1;
		UINT8	pu43:1;
		UINT8	b4:1;
		UINT8	b5:1;
		UINT8	b6:1;
		UINT8	b7:1;
	} bit;
	 UINT8 byte;
} PUR4_ADDR;
PUR4_ADDR	pur4_addr;

#define		PUR4		pur4_addr.byte

#define		PU40		pur4_addr.bit.pu40
#define		PU41		pur4_addr.bit.pu41
#define		PU42		pur4_addr.bit.pu42
#define		PU43		pur4_addr.bit.pu43

/*------------------------------------------------------
    Port P0
------------------------------------------------------*/
#pragma ADDRESS     p0_addr     03e0H       /* Port P0 register */
typedef union {
	struct{
		UINT8	p0_0:1;
		UINT8	p0_1:1;
		UINT8	p0_2:1;
		UINT8	p0_3:1;
		UINT8	p0_4:1;
		UINT8	p0_5:1;
		UINT8	p0_6:1;
		UINT8	p0_7:1;
	} bit;
	 UINT8 byte;
} P0_ADDR;
P0_ADDR	p0_addr;

#define		P0			p0_addr.byte

#define		P0_0		p0_addr.bit.p0_0
#define		P0_1		p0_addr.bit.p0_1
#define		P0_2		p0_addr.bit.p0_2
#define		P0_3		p0_addr.bit.p0_3
#define		P0_4		p0_addr.bit.p0_4
#define		P0_5		p0_addr.bit.p0_5
#define		P0_6		p0_addr.bit.p0_6
#define		P0_7		p0_addr.bit.p0_7

/*------------------------------------------------------
    Port P1
------------------------------------------------------*/
#pragma ADDRESS     p1_addr     03e1H       /* Port P1 register */
typedef union {
	struct{
		UINT8	p1_0:1;
		UINT8	p1_1:1;
		UINT8	p1_2:1;
		UINT8	p1_3:1;
		UINT8	p1_4:1;
		UINT8	p1_5:1;
		UINT8	p1_6:1;
		UINT8	p1_7:1;
	} bit;
	 UINT8 byte;
} P1_ADDR;
P1_ADDR	p1_addr;

#define		P1			p1_addr.byte

#define		P1_0		p1_addr.bit.p1_0
#define		P1_1		p1_addr.bit.p1_1
#define		P1_2		p1_addr.bit.p1_2
#define		P1_3		p1_addr.bit.p1_3
#define		P1_4		p1_addr.bit.p1_4
#define		P1_5		p1_addr.bit.p1_5
#define		P1_6		p1_addr.bit.p1_6
#define		P1_7		p1_addr.bit.p1_7

/*------------------------------------------------------
    Port P0 direction register
------------------------------------------------------*/
#pragma ADDRESS     pd0_addr    03e2H       /* Port P0 direction register */
typedef union {
	struct{
		UINT8	pd0_0:1;
		UINT8	pd0_1:1;
		UINT8	pd0_2:1;
		UINT8	pd0_3:1;
		UINT8	pd0_4:1;
		UINT8	pd0_5:1;
		UINT8	pd0_6:1;
		UINT8	pd0_7:1;
	} bit;
	 UINT8 byte;
} PD0_ADDR;
PD0_ADDR	pd0_addr;

#define		PD0			pd0_addr.byte

#define		PD0_0		pd0_addr.bit.pd0_0
#define		PD0_1		pd0_addr.bit.pd0_1
#define		PD0_2		pd0_addr.bit.pd0_2
#define		PD0_3		pd0_addr.bit.pd0_3
#define		PD0_4		pd0_addr.bit.pd0_4
#define		PD0_5		pd0_addr.bit.pd0_5
#define		PD0_6		pd0_addr.bit.pd0_6
#define		PD0_7		pd0_addr.bit.pd0_7

/*------------------------------------------------------
    Port P1 direction register
------------------------------------------------------*/
#pragma ADDRESS     pd1_addr    03e3H       /* Port P1 direction register */
typedef union {
	struct{
		UINT8	pd1_0:1;
		UINT8	pd1_1:1;
		UINT8	pd1_2:1;
		UINT8	pd1_3:1;
		UINT8	pd1_4:1;
		UINT8	pd1_5:1;
		UINT8	pd1_6:1;
		UINT8	pd1_7:1;
	} bit;
	 UINT8 byte;
} PD1_ADDR;
PD1_ADDR	pd1_addr;

#define		PD1			pd1_addr.byte

#define		PD1_0		pd1_addr.bit.pd1_0
#define		PD1_1		pd1_addr.bit.pd1_1
#define		PD1_2		pd1_addr.bit.pd1_2
#define		PD1_3		pd1_addr.bit.pd1_3
#define		PD1_4		pd1_addr.bit.pd1_4
#define		PD1_5		pd1_addr.bit.pd1_5
#define		PD1_6		pd1_addr.bit.pd1_6
#define		PD1_7		pd1_addr.bit.pd1_7

/*------------------------------------------------------
    Port P2
------------------------------------------------------*/
#pragma ADDRESS     p2_addr     03e4H       /* Port P2 register */
typedef union {
	struct{
		UINT8	p2_0:1;
		UINT8	p2_1:1;
		UINT8	p2_2:1;
		UINT8	p2_3:1;
		UINT8	p2_4:1;
		UINT8	p2_5:1;
		UINT8	p2_6:1;
		UINT8	p2_7:1;
	} bit;
	 UINT8 byte;
} P2_ADDR;
P2_ADDR	p2_addr;

#define		P2			p2_addr.byte

#define		P2_0		p2_addr.bit.p2_0
#define		P2_1		p2_addr.bit.p2_1
#define		P2_2		p2_addr.bit.p2_2
#define		P2_3		p2_addr.bit.p2_3
#define		P2_4		p2_addr.bit.p2_4
#define		P2_5		p2_addr.bit.p2_5
#define		P2_6		p2_addr.bit.p2_6
#define		P2_7		p2_addr.bit.p2_7

/*------------------------------------------------------
    Port P3
------------------------------------------------------*/
#pragma ADDRESS     p3_addr     03e5H       /* Port P3 register */
typedef union {
	struct{
		UINT8	p3_0:1;
		UINT8	p3_1:1;
		UINT8	p3_2:1;
		UINT8	p3_3:1;
		UINT8	p3_4:1;
		UINT8	p3_5:1;
		UINT8	p3_6:1;
		UINT8	p3_7:1;
	} bit;
	 UINT8 byte;
} P3_ADDR;
P3_ADDR	p3_addr;

#define		P3			p3_addr.byte

#define		P3_0		p3_addr.bit.p3_0
#define		P3_1		p3_addr.bit.p3_1
#define		P3_2		p3_addr.bit.p3_2
#define		P3_3		p3_addr.bit.p3_3
#define		P3_4		p3_addr.bit.p3_4
#define		P3_5		p3_addr.bit.p3_5
#define		P3_6		p3_addr.bit.p3_6
#define		P3_7		p3_addr.bit.p3_7

/*------------------------------------------------------
    Port P2 direction register
------------------------------------------------------*/
#pragma ADDRESS     pd2_addr    03e6H       /* Port P2 direction register */
typedef union {
	struct{
		UINT8	pd2_0:1;
		UINT8	pd2_1:1;
		UINT8	pd2_2:1;
		UINT8	pd2_3:1;
		UINT8	pd2_4:1;
		UINT8	pd2_5:1;
		UINT8	pd2_6:1;
		UINT8	pd2_7:1;
	} bit;
	 UINT8 byte;
} PD2_ADDR;
PD2_ADDR	pd2_addr;

#define		PD2			pd2_addr.byte

#define		PD2_0		pd2_addr.bit.pd2_0
#define		PD2_1		pd2_addr.bit.pd2_1
#define		PD2_2		pd2_addr.bit.pd2_2
#define		PD2_3		pd2_addr.bit.pd2_3
#define		PD2_4		pd2_addr.bit.pd2_4
#define		PD2_5		pd2_addr.bit.pd2_5
#define		PD2_6		pd2_addr.bit.pd2_6
#define		PD2_7		pd2_addr.bit.pd2_7

/*------------------------------------------------------
    Port P3 direction register
------------------------------------------------------*/
#pragma ADDRESS     pd3_addr    03e7H       /* Port P3 direction register */
typedef union {
	struct{
		UINT8	pd3_0:1;
		UINT8	pd3_1:1;
		UINT8	pd3_2:1;
		UINT8	pd3_3:1;
		UINT8	pd3_4:1;
		UINT8	pd3_5:1;
		UINT8	pd3_6:1;
		UINT8	pd3_7:1;
	} bit;
	 UINT8 byte;
} PD3_ADDR;
PD3_ADDR	pd3_addr;

#define		PD3			pd3_addr.byte

#define		PD3_0		pd3_addr.bit.pd3_0
#define		PD3_1		pd3_addr.bit.pd3_1
#define		PD3_2		pd3_addr.bit.pd3_2
#define		PD3_3		pd3_addr.bit.pd3_3
#define		PD3_4		pd3_addr.bit.pd3_4
#define		PD3_5		pd3_addr.bit.pd3_5
#define		PD3_6		pd3_addr.bit.pd3_6
#define		PD3_7		pd3_addr.bit.pd3_7

/*------------------------------------------------------
    Port P4
------------------------------------------------------*/
#pragma ADDRESS     p4_addr     03e8H       /* Port P4 register */
typedef union {
	struct{
		UINT8	p4_0:1;
		UINT8	p4_1:1;
		UINT8	p4_2:1;
		UINT8	p4_3:1;
		UINT8	p4_4:1;
		UINT8	p4_5:1;
		UINT8	p4_6:1;
		UINT8	p4_7:1;
	} bit;
	 UINT8 byte;
} P4_ADDR;
P4_ADDR	p4_addr;

#define		P4			p4_addr.byte

#define		P4_0		p4_addr.bit.p4_0
#define		P4_1		p4_addr.bit.p4_1
#define		P4_2		p4_addr.bit.p4_2
#define		P4_3		p4_addr.bit.p4_3
#define		P4_4		p4_addr.bit.p4_4
#define		P4_5		p4_addr.bit.p4_5
#define		P4_6		p4_addr.bit.p4_6
#define		P4_7		p4_addr.bit.p4_7

/*------------------------------------------------------
    Port P5
------------------------------------------------------*/
#pragma ADDRESS     p5_addr     03e9H       /* Port P5 register */
typedef union {
	struct{
		UINT8	p5_0:1;
		UINT8	p5_1:1;
		UINT8	p5_2:1;
		UINT8	p5_3:1;
		UINT8	p5_4:1;
		UINT8	p5_5:1;
		UINT8	p5_6:1;
		UINT8	p5_7:1;
	} bit;
	 UINT8 byte;
} P5_ADDR;
P5_ADDR	p5_addr;

#define		P5			p5_addr.byte

#define		P5_0		p5_addr.bit.p5_0
#define		P5_1		p5_addr.bit.p5_1
#define		P5_2		p5_addr.bit.p5_2
#define		P5_3		p5_addr.bit.p5_3
#define		P5_4		p5_addr.bit.p5_4
#define		P5_5		p5_addr.bit.p5_5
#define		P5_6		p5_addr.bit.p5_6
#define		P5_7		p5_addr.bit.p5_7

/*------------------------------------------------------
    Port P4 direction register
------------------------------------------------------*/
#pragma ADDRESS     pd4_addr    03eaH       /* Port P4 direction register */
typedef union {
	struct{
		UINT8	pd4_0:1;
		UINT8	pd4_1:1;
		UINT8	pd4_2:1;
		UINT8	pd4_3:1;
		UINT8	pd4_4:1;
		UINT8	pd4_5:1;
		UINT8	pd4_6:1;
		UINT8	pd4_7:1;
	} bit;
	 UINT8 byte;
} PD4_ADDR;
PD4_ADDR	pd4_addr;

#define		PD4			pd4_addr.byte

#define		PD4_0		pd4_addr.bit.pd4_0
#define		PD4_1		pd4_addr.bit.pd4_1
#define		PD4_2		pd4_addr.bit.pd4_2
#define		PD4_3		pd4_addr.bit.pd4_3
#define		PD4_4		pd4_addr.bit.pd4_4
#define		PD4_5		pd4_addr.bit.pd4_5
#define		PD4_6		pd4_addr.bit.pd4_6
#define		PD4_7		pd4_addr.bit.pd4_7

/*------------------------------------------------------
    Port P5 direction register
------------------------------------------------------*/
#pragma ADDRESS     pd5_addr    03ebH       /* Port P5 direction register */
typedef union {
	struct{
		UINT8	pd5_0:1;
		UINT8	pd5_1:1;
		UINT8	pd5_2:1;
		UINT8	pd5_3:1;
		UINT8	pd5_4:1;
		UINT8	pd5_5:1;
		UINT8	pd5_6:1;
		UINT8	pd5_7:1;
	} bit;
	 UINT8 byte;
} PD5_ADDR;
PD5_ADDR	pd5_addr;

#define		PD5			pd5_addr.byte

#define		PD5_0		pd5_addr.bit.pd5_0
#define		PD5_1		pd5_addr.bit.pd5_1
#define		PD5_2		pd5_addr.bit.pd5_2
#define		PD5_3		pd5_addr.bit.pd5_3
#define		PD5_4		pd5_addr.bit.pd5_4
#define		PD5_5		pd5_addr.bit.pd5_5
#define		PD5_6		pd5_addr.bit.pd5_6
#define		PD5_7		pd5_addr.bit.pd5_7

/*------------------------------------------------------
    Pull-up control register 0
------------------------------------------------------*/
#pragma ADDRESS     pur0_addr   03f0H       /* Pull-up control register 0 */
typedef union {
	struct{
		UINT8	pu00:1;
		UINT8	pu01:1;
		UINT8	pu02:1;
		UINT8	pu03:1;
		UINT8	pu04:1;
		UINT8	pu05:1;
		UINT8	pu06:1;
		UINT8	pu07:1;
	} bit;
	 UINT8 byte;
} PUR0_ADDR;
PUR0_ADDR	pur0_addr;

#define		PUR0		pur0_addr.byte

#define		PU00		pur0_addr.bit.pu00
#define		PU01		pur0_addr.bit.pu01
#define		PU02		pur0_addr.bit.pu02
#define		PU03		pur0_addr.bit.pu03
#define		PU04		pur0_addr.bit.pu04
#define		PU05		pur0_addr.bit.pu05
#define		PU06		pur0_addr.bit.pu06
#define		PU07		pur0_addr.bit.pu07

/*------------------------------------------------------
    Pull-up control register 1
------------------------------------------------------*/
#pragma ADDRESS     pur1_addr   03f1H       /* Pull-up control register 1 */
typedef union {
	struct{
		UINT8	pu10:1;
		UINT8	pu11:1;
		UINT8	pu12:1;
		UINT8	pu13:1;
		UINT8	b4:1;
		UINT8	b5:1;
		UINT8	b6:1;
		UINT8	b7:1;
	} bit;
	 UINT8 byte;
} PUR1_ADDR;
PUR1_ADDR	pur1_addr;

#define		PUR1		pur1_addr.byte

#define		PU10		pur1_addr.bit.pu10
#define		PU11		pur1_addr.bit.pu11
#define		PU12		pur1_addr.bit.pu12
#define		PU13		pur1_addr.bit.pu13

/*------------------------------------------------------
    Port control register
------------------------------------------------------*/
#pragma ADDRESS     pcr_addr    03ffH       /* Port control register */
typedef union {
	struct{
		UINT8	pcr0:1;
		UINT8	b1:1;
		UINT8	b2:1;
		UINT8	b3:1;
		UINT8	b4:1;
		UINT8	b5:1;
		UINT8	b6:1;
		UINT8	b7:1;
	} bit;
	 UINT8 byte;
} PCR_ADDR;
PCR_ADDR	pcr_addr;

#define		PCR			pcr_addr.byte

#define		PCR0		pcr_addr.bit.pcr0


#endif	/* _SFR_M32C_83_H_	*/

