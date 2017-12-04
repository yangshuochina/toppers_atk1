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
 *  サンプル用 IO 定義 SH72513 用
 */


#ifndef _SH72513_H
#define _SH72513_H

/* BSC */
#define CS0BCR	(*(volatile unsigned long *) 0xFFFC0004u)
#define CS2BCR	(*(volatile unsigned long *) 0xFFFC000Cu)
#define CS0WCR	(*(volatile unsigned long *) 0xFFFC0028u)

/* PORTB PFC */
#define PBCR2	(*(volatile unsigned short *)0xFFFE3894u)

/* PORTC PFC */
#define PCCR4	(*(volatile unsigned short *)0xFFFE3910u)
#define PCCR3	(*(volatile unsigned short *)0xFFFE3912u)
#define PCCR2	(*(volatile unsigned short *)0xFFFE3914u)
#define PCCR1	(*(volatile unsigned short *)0xFFFE3916u)

/* PORTJ PFC */
#define PJCR1	(*(volatile unsigned short *)0xFFFFC872u)

/* ROM */
#define RCCR	(*(volatile unsigned long  *)0xFFFC1400u)

/* RAM */
#define RAMACYC	(*(volatile unsigned short *)0xFFFF0812u)
#define RAMWEN	(*(volatile unsigned short *)0xFFFF0802u)
#define RAMERR	(*(volatile unsigned char  *)0xFFFF0806u)

/* ATU-III */
#define ATUENR	(*(volatile unsigned short *)0xFFFFF000u)
#define	ATUENR_TDE	(0x0010)
#define	ATUENR_PSCE	(0x0001)

#define PSCR0	(*(volatile unsigned short  *)0xFFFFF100u)
#define PSCR1	(*(volatile unsigned short  *)0xFFFFF102u)
#define PSCR2	(*(volatile unsigned short  *)0xFFFFF104u)
#define PSCR3	(*(volatile unsigned short  *)0xFFFFF106u)

#define	TSTRD	(*(volatile unsigned char  *)0xFFFFF500u)
#define	TSTRD_STRD0	(0x01)
#define	TSTRD_STRD1	(0x02)

#define	TCRD0	(*(volatile unsigned short *)0xFFFFF52Cu)
#define	TCRD1	(*(volatile unsigned short *)0xFFFFF53Cu)
#define	TCRD0_DCSELD0		(0x0001)	/* ダウンカウントクロック クロックバス１ (10MHz) */
#define	TCRD1_DCSELD1		(0x0001)	/* ダウンカウントクロック クロックバス１ (10MHz) */

#define	DSTRD0	(*(volatile unsigned char  *)0xFFFFF585u)
#define	DSTRD1	(*(volatile unsigned char  *)0xFFFFF5C5u)
#define	DSTRD0_DSTD00	(0x01)
#define	DSTRD1_DSTD10	(0x01)

#define	TSRD0	(*(volatile unsigned short *)0xFFFFF58Cu)
#define	TSRD1	(*(volatile unsigned short *)0xFFFFF5CCu)
#define	TSRD0_UDFD00	(0x0100)
#define	TSRD1_UDFD10	(0x0100)

#define	TIERD0	(*(volatile unsigned short *)0xFFFFF58Eu)
#define	TIERD1	(*(volatile unsigned short *)0xFFFFF5CEu)
#define	TIERD0_UDED00	(0x0100)
#define	TIERD1_UDED10	(0x0100)

#define	DCNTD00	(*(volatile unsigned long  *)0xFFFFF5B0u)
#define	DCNTD10	(*(volatile unsigned long  *)0xFFFFF5F0u)


/* CMT */
#define CMSTR	(*(volatile unsigned short *)0xFFFEC000u)
#define CMCR_0	(*(volatile unsigned char  *)0xFFFEC010u)
#define CMSR_0	(*(volatile unsigned char  *)0xFFFEC011u)
#define CMCNT_0	(*(volatile unsigned short *)0xFFFEC012u)
#define CMCOR_0	(*(volatile unsigned short *)0xFFFEC014u)

#define CMCR_1	(*(volatile unsigned char  *)0xFFFEC020u)
#define CMSR_1	(*(volatile unsigned char  *)0xFFFEC021u)
#define CMCNT_1	(*(volatile unsigned short *)0xFFFEC022u)
#define CMCOR_1	(*(volatile unsigned short *)0xFFFEC024u)

/* INTC */
#define	IPR05	(*(volatile unsigned short *)0xFFFE0C04u)
#define	IPR06	(*(volatile unsigned short *)0xFFFE0C06u)
#define	IPR10	(*(volatile unsigned short *)0xFFFE0C0Eu)
#define	IPR11	(*(volatile unsigned short *)0xFFFE0C10u)
#define	IPR26	(*(volatile unsigned short *)0xFFFE0C2Eu)
#define	IBCR	(*(volatile unsigned short *)0xFFFE080Cu)
#define	IBNR	(*(volatile unsigned short *)0xFFFE080Eu)

/* SCI A  */
#define	SCSMR1A	(*(volatile unsigned char  *)0xFFFF8000u)
#define	SCBRR1A	(*(volatile unsigned char  *)0xFFFF8004u)
#define	SCSCR1A	(*(volatile unsigned char  *)0xFFFF8008u)
#define	SCTDR1A	(*(volatile unsigned char  *)0xFFFF800Cu)
#define	SCSSR1A	(*(volatile unsigned char  *)0xFFFF8010u)
#define	SCRDR1A	(*(volatile unsigned char  *)0xFFFF8014u)

#endif   /* _SH72513_H */
