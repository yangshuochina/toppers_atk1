/*
 *  kernel_id.h
 *  Fri Nov 14 08:54:54 2008
 *  SG Version 2.10
 *  sg.exe -template=..\..\..\..\config\sh2A-renesas\sh2A_72513.sgt -I ..\..\..\..\sg\impl_oil -odep=kernel_support.src -os=ECC2 D:\toppers_automotive_kernel\tools\sh2A-renesas\sample\SG\sample1.oil
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

