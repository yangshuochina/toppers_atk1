/*
 *  kernel_id.h
 *  Fri Oct 31 14:54:27 2008
 *  SG Version 2.10
 *  sg.exe sample1_ecc2.oil -template=..¥..¥..¥config¥m32c-renesas¥oaks32¥m32c83.sgt -I..¥..¥..¥sg¥impl_oil -I..¥..¥..¥syslib -I..¥..¥..¥syslib¥m32c-renesas¥oaks32 -os=ECC2
 */
#ifndef KERNEL_ID_H
#define KERNEL_ID_H

 /****** Object OS ******/

#define USE_STARTUPHOOK
#define USE_SHUTDOWNHOOK
#define USE_ERRORHOOK

 /****** Object TASK ******/

 /****** Object COUNTER ******/

 /****** Object ALARM ******/

 /****** Object RESOURCE ******/

 /****** Object EVENT ******/

 /****** Object ISR ******/

 /****** Object APPMODE ******/

#define AppMode1	(AppModeType)( 1U << 0 )
#define AppMode2	(AppModeType)( 1U << 1 )
#define AppMode3	(AppModeType)( 1U << 2 )

#endif	/* ! KERNEL_ID_H */

