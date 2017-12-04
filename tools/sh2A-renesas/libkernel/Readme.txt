-------- PROJECT GENERATOR --------
PROJECT NAME :	libkernel
PROJECT DIRECTORY :	D:\TOPPERS-SRC\tools\sh2e-renesas\toppers_osek\libkernel
CPU SERIES :	SH-2E
CPU TYPE :	SH7058F
TOOLCHAIN NAME :	Hitachi SuperH RISC engine Standard Toolchain
TOOLCHAIN VERSION :	7.1.3.0
GENERATION FILES :
    D:\TOPPERS-SRC\tools\sh2e-renesas\toppers_osek\libkernel\dbsct.c
        Setting of B,R Section
    D:\TOPPERS-SRC\tools\sh2e-renesas\toppers_osek\libkernel\iodefine.h
        Definition of I/O Register
    D:\TOPPERS-SRC\tools\sh2e-renesas\toppers_osek\libkernel\intprg.c
        Interrupt Program
    D:\TOPPERS-SRC\tools\sh2e-renesas\toppers_osek\libkernel\vecttbl.c
        Initialize of Vector Table
    D:\TOPPERS-SRC\tools\sh2e-renesas\toppers_osek\libkernel\vect.h
        Definition of Vector
    D:\TOPPERS-SRC\tools\sh2e-renesas\toppers_osek\libkernel\resetprg.c
        Reset Program
    D:\TOPPERS-SRC\tools\sh2e-renesas\toppers_osek\libkernel\hwsetup.c
        Hardware Setup file
    D:\TOPPERS-SRC\tools\sh2e-renesas\toppers_osek\libkernel\stacksct.h
        Setting of Stack area
START ADDRESS OF SECTION :
    H'000000000	DVECTTBL,DINTTBL,PIntPRG
    H'000000A00	PResetPRG
    H'000001000	P,C,C$BSEC,C$DSEC,D
    H'0FFFF0000	B,R
    H'0FFFFBBF0	S

* When the user program is executed,
* the interrupt mask has been masked.
* 
* Program start H'1000.
* RAM start H'FFFF0000.

DATE & TIME : 2006/10/19 9:59:58
