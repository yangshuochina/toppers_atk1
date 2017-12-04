/*
 *  TOPPERS Automotive Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 *      Automotive Kernel
 *
 *  Copyright (C) 2006 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN   
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

#ifndef _H8_36057_H_
#define _H8_36057_H_

/*
 *  H8/36057 の IO定義
 */ 


typedef volatile unsigned char  IOREG;
typedef volatile unsigned short LIOREG;


/*
 * Serial Communication Interface (SCI)
 */

#define SCI3                    0xffa8ul       

/* address offset */

#define SMR                   0ul
#define BRR                   1ul
#define SCR                   2ul
#define TDR                   3ul
#define SSR                   4ul
#define RDR                   5ul

#define SCI3_SMR               *((IOREG *)(0xffa8))
#define SCI3_BRR               *((IOREG *)(0xffa9))
#define SCI3_SCR               *((IOREG *)(0xffaa))
#define SCI3_TDR               *((IOREG *)(0xffab))
#define SCI3_SSR               *((IOREG *)(0xffac))
#define SCI3_RDR               *((IOREG *)(0xffad))

/* SCI Serial Mode Register (SMR) */

#define SMR_CA_BIT            7u
#define SMR_CHR_BIT           6u
#define SMR_PE_BIT            5u
#define SMR_PM_BIT            4u
#define SMR_STOP_BIT          3u
#define SMR_MP_BIT            2u
#define SMR_CKS1_BIT          1u
#define SMR_CKS0_BIT          0u

#define SMR_CA                (1u<<SMR_CA_BIT)
#define SMR_CHR               (1u<<SMR_CHR_BIT)
#define SMR_PE                (1u<<SMR_PE_BIT)
#define SMR_PM                (1u<<SMR_OE_BIT)
#define SMR_STOP              (1u<<SMR_STOP_BIT)
#define SMR_MP                (1u<<SMR_MP_BIT)
#define SMR_CKS1              (1u<<SMR_CKS1_BIT)
#define SMR_CKS0              (1u<<SMR_CKS0_BIT)
#define SMR_CKS_MASK          (SMR_CKS1|SMR_CKS0)

/* SCI Serial Control Register (SCR) */

#define SCR_TIE_BIT           7u
#define SCR_RIE_BIT           6u
#define SCR_TE_BIT            5u
#define SCR_RE_BIT            4u
#define SCR_MPIE_BIT          3u
#define SCR_TEIE_BIT          2u
#define SCR_CKE1_BIT          1u
#define SCR_CKE0_BIT          0u

#define SCR_TIE               (1u<<SCR_TIE_BIT)
#define SCR_RIE               (1u<<SCR_RIE_BIT)
#define SCR_TE                (1u<<SCR_TE_BIT)
#define SCR_RE                (1u<<SCR_RE_BIT)
#define SCR_MPIE              (1u<<SCR_MPIE_BIT)
#define SCR_TEIE              (1u<<SCR_TEIE_BIT)
#define SCR_CKE1              (1u<<SCR_CKE1_BIT)
#define SCR_CKE0              (1u<<SCR_CKE0_BIT)
#define SCR_CKE_MASK          (SCR_CKE1|SCR_CKE0)
#define SCR_IE                (SCR_TIE|SCR_RIE|SCR_MPIE|SCR_TEIE)

/* SCI Serial Status Register (SSR) */

#define SSR_TDRE_BIT          7u
#define SSR_RDRF_BIT          6u
#define SSR_ORER_BIT          5u
#define SSR_FER_BIT           4u
#define SSR_PER_BIT           3u
#define SSR_TEND_BIT          2u
#define SSR_MPB_BIT           1u
#define SSR_MPBT_BIT          0u

#define SSR_TDRE              (1u<<SSR_TDRE_BIT)
#define SSR_RDRF              (1u<<SSR_RDRF_BIT)
#define SSR_ORER              (1u<<SSR_ORER_BIT)
#define SSR_FER               (1u<<SSR_FER_BIT)
#define SSR_PER               (1u<<SSR_PER_BIT)
#define SSR_TEND              (1u<<SSR_TEND_BIT)
#define SSR_MPB               (1u<<SSR_MPB_BIT)
#define SSR_MPBT              (1u<<SSR_MPBT_BIT)



/*
 * I/O Port
 */ 
#define IO_PMR1                *((IOREG *)(0xffe0))

#define IO_PMR1_IRQ3_BIT        7u
#define IO_PMR1_IRQ2_BIT        6u
#define IO_PMR1_IRQ1_BIT        5u
#define IO_PMR1_IRQ0_BIT        4u
#define IO_PMR1_TXD2_BIT        3u
#define IO_PMR1_TXD_BIT         1u

#define IO_PMR1_IRQ3            (1u<<IO_PMR1_IRQ3_BIT)
#define IO_PMR1_IRQ2            (1u<<IO_PMR1_IRQ2_BIT)
#define IO_PMR1_IRQ1            (1u<<IO_PMR1_IRQ1_BIT)
#define IO_PMR1_IRQ0            (1u<<IO_PMR1_IRQ0_BIT)
#define IO_PMR1_TXD2            (1u<<IO_PMR1_TXD2_BIT)
#define IO_PMR1_TXD             (1u<<IO_PMR1_TXD_BIT)



/*
 * Timer Z
 */ 
#define TZ_TSTR     *((IOREG *)0xf720)
#define TZ_TMDR     *((IOREG *)0xf721)
#define TZ_TPMR     *((IOREG *)0xf722)
#define TZ_TFCR     *((IOREG *)0xf723)
#define TZ_TOER     *((IOREG *)0xf724)
#define TZ_TOCR     *((IOREG *)0xf725)

#define TZ_TCR_0    *((IOREG *)0xf700)
#define TZ_TIORA_0  *((IOREG *)0xf701)
#define TZ_TIORC_0  *((IOREG *)0xf702)
#define TZ_TSR_0    *((IOREG *)0xf703)
#define TZ_TIER_0   *((IOREG *)0xf704)
#define TZ_POCR_0   *((IOREG *)0xf705)
#define TZ_TCNT_0   *((LIOREG *)0xf706)
#define TZ_GRA_0    *((LIOREG *)0xf708)
#define TZ_GRB_0    *((LIOREG *)0xf70a)
#define TZ_GRC_0    *((LIOREG *)0xf70c)
#define TZ_GRD_0    *((LIOREG *)0xf70e)

#define TZ_TCR_1    *((IOREG *)0xf710)
#define TZ_TIORA_1  *((IOREG *)0xf711)
#define TZ_TIORC_1  *((IOREG *)0xf712)
#define TZ_TSR_1    *((IOREG *)0xf713)
#define TZ_TIER_1   *((IOREG *)0xf714)
#define TZ_POCR_1   *((IOREG *)0xf715)
#define TZ_TCNT_1   *((LIOREG *)0xf716)
#define TZ_GRA_1    *((LIOREG *)0xf718)
#define TZ_GRB_1    *((LIOREG *)0xf71a)
#define TZ_GRC_1    *((LIOREG *)0xf71c)
#define TZ_GRD_1    *((LIOREG *)0xf71e)


#define TZ_TSTR_STR1_BIT       1u
#define TZ_TSTR_STR0_BIT       0u

#define TZ_TSTR_STR1           (1u<<TZ_TSTR_STR1_BIT)
#define TZ_TSTR_STR0           (1u<<TZ_TSTR_STR0_BIT)

#define TZ_TIER_OVIE_BIT       4u
#define TZ_TIER_IMIED_BIT      3u
#define TZ_TIER_IMIEC_BIT      2u
#define TZ_TIER_IMIEB_BIT      1u
#define TZ_TIER_IMIEA_BIT      0u

#define TZ_TIER_OVIE           (1u<<TZ_TIER_OVIE_BIT)       
#define TZ_TIER_IMIED          (1u<<TZ_TIER_IMIED_BIT)      
#define TZ_TIER_IMIEC          (1u<<TZ_TIER_IMIEC_BIT)      
#define TZ_TIER_IMIEB          (1u<<TZ_TIER_IMIEB_BIT)      
#define TZ_TIER_IMIEA          (1u<<TZ_TIER_IMIEA_BIT)

#define TZ_TSR_UDR_BIT        5u
#define TZ_TSR_OVF_BIT        4u
#define TZ_TSR_IMFD_BIT       3u
#define TZ_TSR_IMFC_BIT       2u
#define TZ_TSR_IMFB_BIT       1u
#define TZ_TSR_IMFA_BIT       0u

#define TZ_TSR_UDR            (1u<<TZ_TSR_UDR_BIT)
#define TZ_TSR_OVF            (1u<<TZ_TSR_OVF_BIT)
#define TZ_TSR_IMFD           (1u<<TZ_TSR_IMFD_BIT)
#define TZ_TSR_IMFC           (1u<<TZ_TSR_IMFC_BIT)
#define TZ_TSR_IMFB           (1u<<TZ_TSR_IMFB_BIT)
#define TZ_TSR_IMFA           (1u<<TZ_TSR_IMFA_BIT)

#define TZ_TCR_CCLR2_BIT         7u
#define TZ_TCR_CCLR1_BIT         6u
#define TZ_TCR_CCLR0_BIT         5u
#define TZ_TCR_CKEG1_BIT         4u
#define TZ_TCR_CKEG0_BIT         3u
#define TZ_TCR_TPSC2_BIT         2u
#define TZ_TCR_TPSC1_BIT         1u
#define TZ_TCR_TPSC0_BIT         0u

#define TZ_TCR_CCLR2             (1u<<TZ_TCR_CCLR2_BIT)
#define TZ_TCR_CCLR1             (1u<<TZ_TCR_CCLR1_BIT)
#define TZ_TCR_CCLR0             (1u<<TZ_TCR_CCLR0_BIT)
#define TZ_TCR_CKEG1             (1u<<TZ_TCR_CKEG1_BIT)
#define TZ_TCR_CKEG0             (1u<<TZ_TCR_CKEG0_BIT)
#define TZ_TCR_TPSC2             (1u<<TZ_TCR_TPSC2_BIT)
#define TZ_TCR_TPSC1             (1u<<TZ_TCR_TPSC1_BIT)
#define TZ_TCR_TPSC0             (1u<<TZ_TCR_TPSC0_BIT)




/*
 * Timer V
 */
#define TV_TCRV0     *((IOREG *)0xffa0)
#define TV_TCSRV     *((IOREG *)0xffa1)
#define TV_TCORA     *((IOREG *)0xffa2)
#define TV_TCORB     *((IOREG *)0xffa3)
#define TV_TCNTV     *((IOREG *)0xffa4)
#define TV_TCRV1     *((IOREG *)0xffa5)

#define TV_TCRV0_CMIEB_BIT      7u
#define TV_TCRV0_CMIEA_BIT      6u
#define TV_TCRV0_OVIE_BIT       5u
#define TV_TCRV0_CCLR1_BIT      4u
#define TV_TCRV0_CCLR0_BIT      3u
#define TV_TCRV0_CKS2_BIT       2u
#define TV_TCRV0_CKS1_BIT       1u
#define TV_TCRV0_CKS0_BIT       0u

#define TV_TCRV0_CMIEB         (1u<<TV_TCRV0_CMIEB_BIT)
#define TV_TCRV0_CMIEA         (1u<<TV_TCRV0_CMIEA_BIT)
#define TV_TCRV0_OVIE          (1u<<TV_TCRV0_OVIE_BIT)
#define TV_TCRV0_CCLR1         (1u<<TV_TCRV0_CCLR1_BIT)
#define TV_TCRV0_CCLR0         (1u<<TV_TCRV0_CCLR0_BIT)
#define TV_TCRV0_CKS2          (1u<<TV_TCRV0_CKS2_BIT)
#define TV_TCRV0_CKS1          (1u<<TV_TCRV0_CKS1_BIT)
#define TV_TCRV0_CKS0          (1u<<TV_TCRV0_CKS0_BIT)

#define TV_TCSRV_CMFB_BIT      7u
#define TV_TCSRV_CMFA_BIT      6u
#define TV_TCSRV_OVF_BIT       5u
#define TV_TCSRV_OS3_BIT       3u
#define TV_TCSRV_OS2_BIT       2u
#define TV_TCSRV_OS1_BIT       1u
#define TV_TCSRV_OS0_BIT       0u

#define TV_TCSRV_CMFB          (1u<<TV_TCSRV_CMFB_BIT)
#define TV_TCSRV_CMFA          (1u<<TV_TCSRV_CMFA_BIT)
#define TV_TCSRV_OVF           (1u<<TV_TCSRV_OVF_BIT)
#define TV_TCSRV_OS3           (1u<<TV_TCSRV_OS3_BIT)
#define TV_TCSRV_OS2           (1u<<TV_TCSRV_OS2_BIT)
#define TV_TCSRV_OS1           (1u<<TV_TCSRV_OS1_BIT)
#define TV_TCSRV_OS0           (1u<<TV_TCSRV_OS0_BIT)

#define TV_TCRV1_TVEG1_BIT     4u
#define TV_TCRV1_TVEG0_BIT     3u
#define TV_TCRV1_TRGE_BIT      2u
#define TV_TCRV1_ICKS0_BIT     0u

#define TV_TCRV1_TVEG1         (1u<<TV_TCRV1_TVEG1_BIT)
#define TV_TCRV1_TVEG0         (1u<<TV_TCRV1_TVEG0_BIT)
#define TV_TCRV1_TRGE          (1u<<TV_TCRV1_TRGE_BIT)
#define TV_TCRV1_ICKS0         (1u<<TV_TCRV1_ICKS0_BIT)


/*
 * Timer B1
 */
#define TB1_TMB1                  *((IOREG *)0xf760)
#define TB1_TCB1                  *((IOREG *)0xf761)
#define TB1_TLB1                  *((IOREG *)0xf761)

#define TB1_TMB1_RLD_BIT          7u
#define TB1_TMB1_CKS2_BIT         2u
#define TB1_TMB1_CKS1_BIT         1u
#define TB1_TMB1_CKS0_BIT         0u

#define TB1_TMB1_RLD              (1u<<TB1_TMB1_RLD_BIT)
#define TB1_TMB1_CKS2             (1u<<TB1_TMB1_CKS2_BIT) 
#define TB1_TMB1_CKS1             (1u<<TB1_TMB1_CKS1_BIT) 
#define TB1_TMB1_CKS0             (1u<<TB1_TMB1_CKS0_BIT)



/*
 * Interrupt Contolller
 */

#define IEGR1                 *((IOREG *)0xfff2u)
#define IEGR2                 *((IOREG *)0xfff3u)
#define IENR1                 *((IOREG *)0xfff4u)
#define IENR2                 *((IOREG *)0xfff5u)
#define IRR1                  *((IOREG *)0xfff6u)
#define IRR2                  *((IOREG *)0xfff7u)
#define IWPR                  *((IOREG *)0xfff8u)

#define IEGR1_NMIEG_BIT       7u
#define IEGR1_IEG3_BIT        3u
#define IEGR1_IEG2_BIT        2u
#define IEGR1_IEG1_BIT        1u
#define IEGR1_IEG0_BIT        0u

#define IEGR1_NMIEG       (1u<<IEGR1_NMIEG_BIT)
#define IEGR1_IEG3        (1u<<IEGR1_IEG3_BIT)
#define IEGR1_IEG2        (1u<<IEGR1_IEG2_BIT)
#define IEGR1_IEG1        (1u<<IEGR1_IEG1_BIT)
#define IEGR1_IEG0        (1u<<IEGR1_IEG0_BIT)

#define IEGR1_WPEG5_BIT       5u
#define IEGR1_WPEG4_BIT       4u
#define IEGR1_WPEG3_BIT       3u
#define IEGR1_WPEG2_BIT       2u
#define IEGR1_WPEG1_BIT       1u
#define IEGR1_WPEG0_BIT       0u

#define IEGR1_WPEG5       (1u<<IEGR1_WPEG5_BIT)
#define IEGR1_WPEG4       (1u<<IEGR1_WPEG4_BIT)
#define IEGR1_WPEG3       (1u<<IEGR1_WPEG3_BIT)
#define IEGR1_WPEG2       (1u<<IEGR1_WPEG2_BIT)
#define IEGR1_WPEG1       (1u<<IEGR1_WPEG1_BIT)
#define IEGR1_WPEG0       (1u<<IEGR1_WPEG0_BIT)

#define IENR1_IENDT_BIT   7u
#define IENR1_IENWP_BIT   5u
#define IENR1_IEN3_BIT    3u
#define IENR1_IEN2_BIT    2u
#define IENR1_IEN1_BIT    1u
#define IENR1_IEN0_BIT    0u

#define IENR1_IENDT       (1u<<IENR1_IENDT_BIT)
#define IENR1_IENWP       (1u<<IENR1_IENWP_BIT)
#define IENR1_IEN3        (1u<<IENR1_IEN3_BIT)
#define IENR1_IEN2        (1u<<IENR1_IEN2_BIT)
#define IENR1_IEN1        (1u<<IENR1_IEN1_BIT)
#define IENR1_IEN0        (1u<<IENR1_IEN0_BIT)

#define IENR2_IENTB1_BIT   5u

#define IENR2_IENTB1      (1u<<IENR2_IENTB1_BIT)

#define IRR1_IRRDT_BIT    7u
#define IRR1_IRRI3_BIT    3u
#define IRR1_IRRI2_BIT    2u
#define IRR1_IRRI1_BIT    1u
#define IRR1_IRRI0_BIT    0u

#define IRR1_IRRDT        (1u<<IRR1_IRRDT_BIT)
#define IRR1_IRRI3        (1u<<IRR1_IRRI3_BIT)
#define IRR1_IRRI2        (1u<<IRR1_IRRI2_BIT)
#define IRR1_IRRI1        (1u<<IRR1_IRRI1_BIT)
#define IRR1_IRRI0        (1u<<IRR1_IRRI0_BIT)

#define IRR2_IRRTB1_BIT   5u

#define IRR2_IRRTB1       (1u<<IRR2_IRRTB1_BIT)


/*
 *  割込み番号の定義
 */
#define IRQ_NMI                 7u               /* NMI */

#define IRQ_EXT0                14u              /* IRQ0 */
#define IRQ_EXT1                15u              /* IRQ1 */
#define IRQ_EXT2                16u              /* IRQ2 */
#define IRQ_EXT3                17u              /* IRQ3 */
#define IRQ_EXT4                18u              /* WKP  */
#define IRQ_TIM_V               22u              /* Timer V */
#define IRQ_SCI3                23u              /* SCI3    */
#define IRQ_ADI                 25u              /* A/D     */
#define IRQ_TIM_Z_A0D0          26u              /* Timer Z */
#define IRQ_TIM_Z_A1D1          27u              /* Timer Z */
#define IRQ_TIM_B               29u              /* Timer B */
#define IRQ_SCI3_2              32u              /* SCI3    */
#define IRQ_CAN                 34u              /* TinyCAN */
#define IRQ_SSU                 35u              /* SSU     */
#define IRQ_SUB_TIMER           36u              /* Sub Timer */


#endif /* _H8_36057_H_ */
