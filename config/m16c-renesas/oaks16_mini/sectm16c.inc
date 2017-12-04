;
;  TOPPERS Automotive Kernel
;      Toyohashi Open Platform for Embedded Real-Time Systems
;      Automotive Kernel
; 
;  Copyright (C) 2006 by Witz Corporation, JAPAN
; 
;  ��L���쌠�҂́C�ȉ��� (1)�`(4) �̏������CFree Software Foundation 
;  �ɂ���Č��\����Ă��� GNU General Public License �� Version 2 �ɋL
;  �q����Ă�������𖞂����ꍇ�Ɍ���C�{�\�t�g�E�F�A�i�{�\�t�g�E�F�A
;  �����ς������̂��܂ށD�ȉ������j���g�p�E�����E���ρE�Ĕz�z�i�ȉ��C
;  ���p�ƌĂԁj���邱�Ƃ𖳏��ŋ�������D
;  (1) �{�\�t�g�E�F�A���\�[�X�R�[�h�̌`�ŗ��p����ꍇ�ɂ́C��L�̒���
;      ���\���C���̗��p��������щ��L�̖��ۏ؋K�肪�C���̂܂܂̌`�Ń\�[
;      �X�R�[�h���Ɋ܂܂�Ă��邱�ƁD
;  (2) �{�\�t�g�E�F�A���C���C�u�����`���ȂǁC���̃\�t�g�E�F�A�J���Ɏg
;      �p�ł���`�ōĔz�z����ꍇ�ɂ́C�Ĕz�z�ɔ����h�L�������g�i���p
;      �҃}�j���A���Ȃǁj�ɁC��L�̒��쌠�\���C���̗��p��������щ��L
;      �̖��ۏ؋K����f�ڂ��邱�ƁD
;  (3) �{�\�t�g�E�F�A���C�@��ɑg�ݍ��ނȂǁC���̃\�t�g�E�F�A�J���Ɏg
;      �p�ł��Ȃ��`�ōĔz�z����ꍇ�ɂ́C���̂����ꂩ�̏����𖞂�����
;      �ƁD
;    (a) �Ĕz�z�ɔ����h�L�������g�i���p�҃}�j���A���Ȃǁj�ɁC��L�̒�
;        �쌠�\���C���̗��p��������щ��L�̖��ۏ؋K����f�ڂ��邱�ƁD
;    (b) �Ĕz�z�̌`�Ԃ��C�ʂɒ�߂���@�ɂ���āCTOPPERS�v���W�F�N�g��
;        �񍐂��邱�ƁD
;  (4) �{�\�t�g�E�F�A�̗��p�ɂ�蒼�ړI�܂��͊ԐړI�ɐ����邢���Ȃ鑹
;      �Q������C��L���쌠�҂����TOPPERS�v���W�F�N�g��Ɛӂ��邱�ƁD
; 
;  �{�\�t�g�E�F�A�́C���ۏ؂Œ񋟂���Ă�����̂ł���D��L���쌠�҂�
;  ���TOPPERS�v���W�F�N�g�́C�{�\�t�g�E�F�A�Ɋւ��āC���̓K�p�\����
;  �܂߂āC�����Ȃ�ۏ؂��s��Ȃ��D�܂��C�{�\�t�g�E�F�A�̗��p�ɂ�蒼
;  �ړI�܂��͊ԐړI�ɐ����������Ȃ鑹�Q�Ɋւ��Ă��C���̐ӔC�𕉂�Ȃ��D
; 
;

;
;  �^�[�Q�b�g�V�X�e���ˑ��Z�N�V������`�t�@�C��(OAKS16-mini�p)
;

;
;  �Z�N�V�����̒�`
;

	;
	; �����l�L��f�[�^�̈�̃Z�N�V����
	;
	.section	data_NE,DATA
	.org	0400H
	.section	data_NO,DATA,ALIGN

	;
	; �����l�����f�[�^�̈�̃Z�N�V����
	;
	.section	bss_NE,DATA,ALIGN
	.section	bss_NO,DATA,ALIGN

	;
	; �J�[�l���X�^�b�N�̈�̃Z�N�V����
	;
	.section	stack,DATA
	.org	0B00H
	.blkb	0100H
	.glb	STACK_TOP
STACK_TOP:

	;
	; CODE�̈�̃Z�N�V����
	;
	.section	program,CODE
	.org	0F0000H

	;
	; RO�f�[�^�̈�̃Z�N�V����
	;
	.section	rom_FE,ROMDATA,ALIGN
	.section	rom_FO,ROMDATA,ALIGN

	;
	; DATA�̈�̏����l
	;
	.section	data_NEI,ROMDATA,ALIGN
	.section	data_NOI,ROMDATA,ALIGN

	;
	; �σx�N�^�e�[�u���̈�̃Z�N�V����
	;
	.section	vvector,CODE
	.org	0FFEDCH
	.glb	VVECTOR_TOP
VVECTOR_TOP:

	;
	; �Œ�x�N�^�e�[�u���̈�̃Z�N�V����
	;
	.section	fvector,CODE
	.org	0FFFDCH

