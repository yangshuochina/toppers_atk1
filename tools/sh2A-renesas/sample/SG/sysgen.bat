@SET SGTFILE=config\sh2A-renesas\sh2A_72513.sgt
DEL kernel_support.src
DEL kernel_cfg.c
DEL kernel_id.h
..\..\..\..\sg\sg.exe -template=..\..\..\..\%SGTFILE% -I ..\..\..\..\sg\impl_oil -odep=kernel_support.src -os=ECC2 %1 %2 %3 
