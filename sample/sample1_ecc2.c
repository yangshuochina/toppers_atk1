/*
 *  TOPPERS Automotive Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 *      Automotive Kernel
 * 
 *  Copyright (C) 2000-2003 by Embedded and Real-Time Systems Laboratory
 *                              Toyohashi Univ. of Technology, JAPAN
 *  Copyright (C) 2004 by Embedded and Real-Time Systems Laboratory
 *              Graduate School of Information Science, Nagoya Univ., JAPAN
 *  Copyright (C) 2004-2006 by Witz Corporation, JAPAN
 * 
 *  ��L���쌠�҂́C�ȉ��� (1)�`(4) �̏������CFree Software Foundation 
 *  �ɂ���Č��\����Ă��� GNU General Public License �� Version 2 �ɋL
 *  �q����Ă�������𖞂����ꍇ�Ɍ���C�{�\�t�g�E�F�A�i�{�\�t�g�E�F�A
 *  �����ς������̂��܂ށD�ȉ������j���g�p�E�����E���ρE�Ĕz�z�i�ȉ��C
 *  ���p�ƌĂԁj���邱�Ƃ𖳏��ŋ�������D
 *  (1) �{�\�t�g�E�F�A���\�[�X�R�[�h�̌`�ŗ��p����ꍇ�ɂ́C��L�̒���
 *      ���\���C���̗��p��������щ��L�̖��ۏ؋K�肪�C���̂܂܂̌`�Ń\�[
 *      �X�R�[�h���Ɋ܂܂�Ă��邱�ƁD
 *  (2) �{�\�t�g�E�F�A���C���C�u�����`���ȂǁC���̃\�t�g�E�F�A�J���Ɏg
 *      �p�ł���`�ōĔz�z����ꍇ�ɂ́C�Ĕz�z�ɔ����h�L�������g�i���p
 *      �҃}�j���A���Ȃǁj�ɁC��L�̒��쌠�\���C���̗��p��������щ��L
 *      �̖��ۏ؋K����f�ڂ��邱�ƁD
 *  (3) �{�\�t�g�E�F�A���C�@��ɑg�ݍ��ނȂǁC���̃\�t�g�E�F�A�J���Ɏg
 *      �p�ł��Ȃ��`�ōĔz�z����ꍇ�ɂ́C���̂����ꂩ�̏����𖞂�����
 *      �ƁD
 *    (a) �Ĕz�z�ɔ����h�L�������g�i���p�҃}�j���A���Ȃǁj�ɁC��L�̒�
 *        �쌠�\���C���̗��p��������щ��L�̖��ۏ؋K����f�ڂ��邱�ƁD
 *    (b) �Ĕz�z�̌`�Ԃ��C�ʂɒ�߂���@�ɂ���āCTOPPERS�v���W�F�N�g��
 *        �񍐂��邱�ƁD
 *  (4) �{�\�t�g�E�F�A�̗��p�ɂ�蒼�ړI�܂��͊ԐړI�ɐ����邢���Ȃ鑹
 *      �Q������C��L���쌠�҂����TOPPERS�v���W�F�N�g��Ɛӂ��邱�ƁD
 * 
 *  �{�\�t�g�E�F�A�́C���ۏ؂Œ񋟂���Ă�����̂ł���D��L���쌠�҂�
 *  ���TOPPERS�v���W�F�N�g�́C�{�\�t�g�E�F�A�Ɋւ��āC���̓K�p�\����
 *  �܂߂āC�����Ȃ�ۏ؂��s��Ȃ��D�܂��C�{�\�t�g�E�F�A�̗��p�ɂ�蒼
 *  �ړI�܂��͊ԐړI�ɐ����������Ȃ鑹�Q�Ɋւ��Ă��C���̐ӔC�𕉂�Ȃ��D
 * 
 */

/* 
 *  �T���v���v���O����(1) ECC2�̖{��
 *
 *  TOPPERS Automotive Kernel�̊�{�I�ȓ�����m�F���邽�߂̃T���v���v���O�����D
 *
 *  �v���O�����̊T�v�FPC�ƃ{�[�h�ԂŃV���A���ʐM���s���C���[�U����
 *  �R�}���h�ɉ���������ƃ��O�o�͂��s�Ȃ��D
 *
 *  ���R�}���h�ꗗ��
 *  �E�^�X�N�w��
 *    '1' : �ȍ~�̃R�}���h�� Task1 �ɑ΂��čs���D
 *    '2' : �ȍ~�̃R�}���h�� Task2 �ɑ΂��čs���D
 *    '3' : �ȍ~�̃R�}���h�� Task3 �ɑ΂��čs���D
 *    '4' : �ȍ~�̃R�}���h�� Task4 �ɑ΂��čs���D
 *    '5' : �ȍ~�̃R�}���h�� Task5 �ɑ΂��čs���D
 *  �E�^�X�N�Ǘ��@�\
 *    'a' : ActivateTask �ɂă^�X�N���N������D
 *    'A' : TerminateTask �ɂă^�X�N���I������D
 *    '!'(Shift+1) : ChainTask �ɂă^�X�N���I�����CTask1 ���N������D
 *    '"'(Shift+2) : ChainTask �ɂă^�X�N���I�����CTask2 ���N������D
 *    '#'(Shift+3) : ChainTask �ɂă^�X�N���I�����CTask3 ���N������D
 *    '$'(Shift+4) : ChainTask �ɂă^�X�N���I�����CTask4 ���N������D
 *    '%'(Shift+5) : ChainTask �ɂă^�X�N���I�����CTask5 ���N������D
 *    's' : �m���v���G���v�e�B�u�����ł���^�X�N MainTask �ɂčō�
 *          �D��x�^�X�N HighPriorityTask ���N�����CSchedule �ɂ�
 *          �ăX�P�W���[�����O���s���D
 *    'S' : �m���v���G���v�e�B�u�^�X�N NonPriTask ���N������D
 *          �m���v���G���v�e�B�u�^�X�N NonPriTask �ɂčō��D��x
 *          �^�X�N HighPriorityTask ���N�����C�^�X�N�I������D
 *    'z' : GetTaskID �ɂĎ��^�X�N��ID���擾����D
 *    'Z' : GetTaskState �ɂă^�X�N��Ԃ��擾����D
 *  �E�����݊Ǘ��@�\
 *    'd' : DisableAllInterrupts �����s��C�n�[�h�E�F�A�J�E���^�l��
 *          3��\�����C EnableAllInterrupts �����s����D
 *    'D' : SuspendAllInterrupts �����s��C�n�[�h�E�F�A�J�E���^�l��
 *          3��\�����C����� SuspendAllInterrupts �����s��A�n�[�h
 *          �E�F�A�J�E���^�l��3��\�����CResumeAllInterrupts �����s��A
 *          �n�[�h�E�F�A�J�E���^�l��3��\�����CResumeAllInterrupts ��
 *          ���s����D
 *    'f' : SuspendOSInterrupts �����s��C�n�[�h�E�F�A�J�E���^�l��
 *          3��\�����C����� SuspendOSInterrupts �����s��A�n�[�h
 *          �E�F�A�J�E���^�l��3��\�����C����� SuspendAllInterrupts
 *          �����s��C�n�[�h�E�F�A�J�E���^�l��3��\�����C
 *          ResumeAllInterrupts �����s��A�n�[�h�E�F�A�J�E���^��3��
 *          �\�����CResumeOSInterrupts �����s��n�[�h�E�F�A�J�E���^
 *          �l��3��\�����CResumeOSInterrupts �����s����D
 *    'T' : �n�[�h�E�F�A�J�E���^�l��3��\������D
 *  �E���\�[�X�Ǘ��@�\
 *    'k' : GetResource �ɂă��\�[�X TskLevelRes ���擾����D�Ȃ��C
 *          Task3 �́A���̃��\�[�X���D��x���������߃G���[�ƂȂ�D
 *    'K' : ReleaseResource �ɂă��\�[�X TskLevelRes ���������D
 *    'l' : GetResource �ɂăX�P�W���[�����\�[�X���擾��C�ō��D��x
 *          �^�X�N HighPriorityTask ���N�����CReleaseResource �ɂ�
 *          �X�P�W���[�����\�[�X���������D
 *    'i' : GetResource �ɂă��\�[�X IntLevelRes ���擾��C�n�[�h
 *          �E�F�A�J�E���^�l��3��\�����CReleaseResource �ɂ�
 *          ���\�[�X IntLevelRes ���������D
 *  �E�C�x���g����@�\
 *    'e' : SetEvent �ɂăC�x���g��ݒ肷��DTask2 �� Task3 �ȊO��
 *          ���蓖�Ă��Ȃ����߃G���[�ƂȂ�D
 *    'w' : ClearEvent �ɂĎ��^�X�N�̃C�x���g���N���A����DTask2 ��
 *          Task3 �ȊO�͊��蓖�Ă��Ȃ����߃G���[�ƂȂ�D
 *    'E' : GetEvent �ɂăC�x���g��Ԃ��擾����DTask2 �� Task3
 *          �ȊO�͊��蓖�Ă��Ȃ����߃G���[�ƂȂ�D
 *    'W' : WaitEvent �ɂĎ��^�X�N�̃C�x���g��҂DTask3 �� Task4
 *          �ȊO�̓G���[�ƂȂ�D
 *  �E�A���[���@�\
 *    'b' : GetAlarmBase �ɂăA���[�� MainCycArm �̃A���[���x�[�X
 *          �����擾����D
 *    'B' : GetAlarm �ɂăA���[�� MainCycArm �̎c��J�E���g�l��2��
 *          �A���Ŏ擾����D
 *    'v' : SetRelAlarm �ɂăA���[�� ActTskArm ���N�����C500ms ���
 *          �^�X�N Task1 ���N������D
 *    'V' : SetRelAlarm �ɂăA���[�� SetEvtArm ���N�����C500ms ���
 *          �C�x���g T3Evt ��ݒ肷��D
 *    'n' : SetRelAlarm �ɂăA���[�� CallBackArm ���C�p�����[�^
 *          900ms ��ɖ����E�P���A���[���w��Őݒ肷��D
 *    'N' : SetRelAlarm �ɂăA���[�� CallBackArm ���C�p�����[�^
 *          900ms ��ɖ����E 500ms �����A���[���w��Őݒ肷��D
 *    'm' : SetAbsAlarm �ɂăA���[�� CallBackArm ���C�p�����[�^
 *          �J�E���^�l900�ɖ����E�P���A���[���w��Őݒ肷��D
 *    'M' : SetAbsAlarm �ɂăA���[�� CallBackArm ���C�p�����[�^
 *          �J�E���^�l900�ɖ����E 500ms �����A���[���Őݒ肷��D
 *    'h' : CancelAlarm �ɂăA���[�� CallBackArm ���L�����Z������D
 *  �E�J�E���^����@�\�iOSEK�d�l�O�j
 *    'c' : �J�E���^�ʒm�p�����݂��N�����C�����ݓ��ɂ� SignalCounter
 *          �����s���C�J�E���^ SampleCnt �ɃV�O�i���ʒm����D
 *          1 �V�O�i���ŃA���[�� SampleArm ���������C�R�[���o�b�N��
 *          ���s����D
 *  �EOS���s����@�\
 *    'p' : GetActiveApplicationMode �ɂăA�v���P�[�V�������[�h��
 *          �擾����D
 *    'q' : ShutdownOS ���R�[�h E_OK �Ŏ��s���C�T���v���v���O������
 *          �I������D
 *    'Q' : ShutdownOS ���R�[�h E_OS_STATE �Ŏ��s���C�T���v���v���O����
 *          ���I������D
 *  
 *  ���I�u�W�F�N�g�ꗗ��
 *  �EOS
 *    �X�^�[�g�A�b�v�t�b�N�F�g�p
 *    �V���b�g�_�E���t�b�N�F�g�p
 *    �G���[�t�b�N�F�g�p
 *    �v���^�X�N�t�b�N�F���g�p
 *    �|�X�g�^�X�N�t�b�N�F���g�p
 *    �X�P�W���[�����\�[�X�F�g�p
 *  �E�^�X�N
 *  ���C���^�X�N
 *    �^�X�NID�FMainTask
 *    �D��x�F14
 *    ���d�N�����F1
 *    �X�P�W���[���F�m���v���G���v�e�B�u
 *    �����N���FAppMode1, AppMode2, AppMode3
 *    �T�v�F���[�U�C���^�t�F�[�X�i�V���A��IO���R�}���h����M���C
 *          ����ɑΉ�����������s�Ȃ��D�j
 *          �����A���[�� MainCycArm �ɂ��C100ms���Ƃɑ҂�������
 *          �R�}���h�̎�M�L�����|�[�����O����D
 *          �C�x���g�iID�FMainEvt�j���֘A�t���Ă���D
 *  �ō��D��x�^�X�N
 *    �^�X�NID�FHighPriorityTask
 *    �D��x�F15
 *    ���d�N�����F1
 *    �X�P�W���[���F�t���v���G���v�e�B�u
 *    �����N���F�Ȃ�
 *    �T�v�F�N�����O���o�͂��ďI������D�m���v���G���v�e�B�u�^�X�N
 *          ����N������C�v���G���v�g���Ă��邩�ǂ����̊m�F�p�D
 *  �m���v���G���v�e�B�u�^�X�N
 *    �^�X�NID�FNonPriTask
 *    �D��x�F1
 *    ���d�N�����F8
 *    �X�P�W���[���F�m���v���G���v�e�B�u
 *    �����N���F�Ȃ�
 *    �T�v�F�N�����O���o�͂��C�ō��D��x�^�X�N HighPriorityTask ��
 *          �N����C�I�����O���o�͂��ă^�X�N���I������D
 *  �^�X�N1
 *    �^�X�NID�FTask1
 *    �D��x�F4
 *    �X�P�W���[���F�t���v���G���v�e�B�u
 *    �����N���FAppMode2
 *    ���d�N�����F8
 *    �T�v�F���񏈗��^�X�N�i���C���^�X�N����̎w�߂ɂ�蓮��j�D
 *          �N�����ꂷ��Ɩ������[�v�ɓ���C�R�}���h���������s����D
 *          ���\�[�X TskLevelRes ���֘A�t���Ă���D
 *          ���\�[�X IntLevelRes ���֘A�t���Ă���D
 *  �^�X�N2
 *    �^�X�NID�FTask2
 *    �D��x�F7
 *    ���d�N�����F1
 *    �X�P�W���[���F�t���v���G���v�e�B�u
 *    �����N���F�Ȃ�
 *    �T�v�F���񏈗��^�X�N�i���C���^�X�N����̎w�߂ɂ�蓮��j�D
 *          �N�����ꂷ��Ɩ������[�v�ɓ���C�R�}���h���������s����D
 *          ���\�[�X TskLevelRes ���֘A�t���Ă���D
 *          ���\�[�X IntLevelRes ���֘A�t���Ă���D
 *          �C�x���g T2Evt ���֘A�t���Ă���D
 *  �^�X�N3
 *    �^�X�NID�FTask3
 *    �D��x�F12
 *    ���d�N�����F1
 *    �X�P�W���[���F�t���v���G���v�e�B�u
 *    �����N���FAppMode3
 *    �T�v�F���񏈗��^�X�N�i���C���^�X�N����̎w�߂ɂ�蓮��j�D
 *          �N�����ꂷ��Ɩ������[�v�ɓ���C�R�}���h���������s����D
 *          �C�x���g�҂����邱�Ƃ��\�ł���D
 *          ���\�[�X IntLevelRes ���֘A�t���Ă���D
 *          �C�x���g T3Evt ���֘A�t���Ă���D
 *  �^�X�N4
 *    �^�X�NID�FTask4
 *    �D��x�F6
 *    ���d�N�����F5
 *    �X�P�W���[���F�t���v���G���v�e�B�u
 *    �����N���F�Ȃ�
 *    �T�v�F���񏈗��^�X�N�i���C���^�X�N����̎w�߂ɂ�蓮��j�D
 *          �N�����ꂷ��Ɩ������[�v�ɓ���C�R�}���h���������s����D
 *          ���\�[�X TskLevelRes ���֘A�t���Ă���D
 *          ���\�[�X IntLevelRes ���֘A�t���Ă���D
 *          �������\�[�X GroupRes ���֘A�t���Ă���D
 *  �^�X�N5
 *    �^�X�NID�FTask5
 *    �D��x�F9
 *    ���d�N�����F5
 *    �X�P�W���[���F�t���v���G���v�e�B�u
 *    �����N���F�Ȃ�
 *    �T�v�F���񏈗��^�X�N�i���C���^�X�N����̎w�߂ɂ�蓮��j�D
 *          �N�����ꂷ��Ɩ������[�v�ɓ���C�R�}���h���������s����D
 *          ���\�[�X TskLevelRes ���֘A�t���Ă���D
 *          ���\�[�X IntLevelRes ���֘A�t���Ă���D
 *          �������\�[�X GroupRes ���֘A�t���Ă���D
 *  �E�����݃T�[�r�X���[�`��
 *  �V���A��IO��M������
 *    ISRID�FRxHwSerialInt
 *    �D��x�F6
 *    �J�e�S���F1
 *    �T�v�F�R�}���h����M����D
 *  �n�[�h�E�F�A�J�E���^1������
 *    ISRID�FHwCnt1Int
 *    �D��x�F5
 *    �J�e�S���F1
 *    �T�v�F�����݋֎~�m�F�p�J�E���^1�����Z����D
 *  �V�X�e���^�C�}������
 *    ISRID�FSysTimerInt
 *    �D��x�F4
 *    �J�e�S���F2
 *    �T�v�FSignalCounter(SysTimerCnt) �����s����D
 *  �J�E���^�\�[�X������
 *    ISRID�FCounterInt
 *    �D��x�F3
 *    �J�e�S���F2
 *    �T�v�FSignalCounter(SampleCnt) �����s����D
 *  �n�[�h�E�F�A�J�E���^2������
 *    ISRID�FHwCnt1Int
 *    �D��x�F2
 *    �J�e�S���F2
 *    �T�v�F�����݋֎~�m�F�p�J�E���^2�����Z����D
 *          ���\�[�X�iID�FIntLevelRes�j���֘A�t���Ă���D
 *  �E���\�[�X
 *  �^�X�N���x�����\�[�X
 *    ���\�[�XID�FTskLevelRes
 *    �v���p�e�B�F�W��
 *  �����݃��x�����\�[�X
 *    ���\�[�XID�FIntLevelRes
 *    �v���p�e�B�F�W��
 *  �^�X�N�O���[�v���\�[�X
 *    ���\�[�XID�FGroupRes
 *    �v���p�e�B�F����
 *  �E�C�x���g
 *  ���C���^�X�N�C�x���g
 *    �C�x���gID�FMainEvt
 *  �^�X�N2�C�x���g
 *    �C�x���gID�FT2Evt
 *  �^�X�N3�C�x���g
 *    �C�x���gID�FT3Evt
 *  �E�J�E���^
 *  �V�X�e���^�C�}�J�E���^
 *    �J�E���^ID�FSysTimerCnt
 *    �J�E���g�l�F0�`999
 *    ���Z�l�F1
 *  �T���v���J�E���^
 *    �J�E���^ID�FSampleCnt
 *    �J�E���g�l�F0�`99
 *    ���Z�l�F10
 *  �E�A���[��
 *  ���C�������A���[��
 *    �A���[��ID�FMainCycArm
 *    �x�[�X�J�E���^ID�FSysTimerCnt
 *    �A�N�V�����F�C�x���g�ݒ� MainEvt
 *    �����N���FAppMode1, AppMode2, AppMode3
 *    �ݒ�F�J�E���^100�C����100
 *  �^�X�N�N���A���[��
 *    �A���[��ID�FActTskArm
 *    �x�[�X�J�E���^ID�FSysTimerCnt
 *    �A�N�V�����F�^�X�N�N�� Task1
 *    �����N���F�Ȃ�
 *  �C�x���g�ݒ�A���[��
 *    �A���[��ID�FSetEvtArm
 *    �x�[�X�J�E���^ID�FSysTimerCnt
 *    �A�N�V�����F�C�x���g�ݒ� T3Evt
 *    �����N���F�Ȃ�
 *  �R�[���o�b�N���s�A���[��
 *    �A���[��ID�FCallBackArm
 *    �x�[�X�J�E���^ID�FSysTimerCnt
 *    �A�N�V�����F�R�[���o�b�N�֐����s
 *    �����N���F�Ȃ�
 *  SignalCounter�m�F�p�A���[��
 *    �A���[��ID�FSampleArm
 *    �x�[�X�J�E���^ID�FSampleCnt
 *    �A�N�V�����F�R�[���o�b�N�֐����s
 *    �����N���F�Ȃ�
 *  �E�A�v���P�[�V�������[�h
 *  �����N���Ȃ����[�h
 *    �A�v���P�[�V�������[�hID�FAppMode1
 *  Task1�����N�����[�h
 *    �A�v���P�[�V�������[�hID�FAppMode2
 *  Task3�����N�����[�h
 *    �A�v���P�[�V�������[�hID�FAppMode3
 *
 */

#include "kernel.h"
#include "sys_timer.h"
#include "serial.h"
#include "sample_config.h"
#include "kernel_id.h"
#include "sample1_com_ecc2.h"

/*
 *	�����֐��v���g�^�C�v�錾
 */
int main( void );
TASK( MainTask );
TASK( HighPriorityTask );
TASK( NonPriTask );
TASK( Task1 );
TASK( Task2 );
TASK( Task3 );
TASK( Task4 );
TASK( Task5 );
ALARMCALLBACK( SysTimerAlmCb );
static void		TaskProk( UINT8 task_no );

static volatile UINT8 cur_task_no = 0;

/*
 *������s�^�X�N��
 */
#define PARALLEL_TASK_NUM	5

/*
 *  �����f�[�^�o�b�t�@
 */
static volatile UINT8	command_tbl[8];	/* �R�}���h���n���e�[�u��	*/

extern const UINT8	*task_name_tbl[];


/*
 *  ���[�U���C���֐�
 *
 *  �A�v���P�[�V�������[�h�̔��f�ƁC�J�[�l���N���D
 */
int main( void )
{
	AppModeType	crt_app_mode;

	/*
	 *  �A�v���P�[�V�������[�h�̔��f
	 */
	switch( GetAppModeInfo() ){
	case 0:
		crt_app_mode = AppMode1;
		break;
	case 1:
		crt_app_mode = AppMode2;
		break;
	default:
		crt_app_mode = AppMode3;
		break;
	}

	/*
	 *  �J�[�l���N��
	 */
	StartOS( crt_app_mode );

	while( 1 );
}	/* main	*/


/*
 *  ���C���^�X�N
 *
 *  ���[�U�R�}���h�̎�M�ƁC�R�}���h���Ƃ̏������s�D
 */
TASK( MainTask )
{
	UINT8		command;
	UINT8		task_no;
	UINT8		echo[] = { " \r\n" };
	UINT8		command_error[] = { "Not ASCII character\r\n" };
	UINT8		init_lpcnt;

	/*
	 *  �^�X�N�ԍ��E�R�}���h�o�b�t�@������
	 */
	task_no = (UINT8)( 0 );

	for( init_lpcnt=0; init_lpcnt<PARALLEL_TASK_NUM; init_lpcnt++ ){
		command_tbl[init_lpcnt] = (UINT8)( 0 );
	}

	/*
	 *  �R�}���h���s���[�v
	 */
	while( 1 ){
		WaitEvent( MainEvt );	/* 100ms�̍�Ǝ��ԑ҂�	*/
		ClearEvent( MainEvt );

		/*
		 *  ���̓R�}���h�擾
		 */
		RecvPolSerialChar( &command );	/* ��M�o�b�t�@�|�[�����O	*/

		/*
		 *  ���̓R�}���h�`�F�b�N
		 */
		if(command != 0 && 
			(( command <= (UINT8)( 0x1f ) ) || ( command >= (UINT8)( 0x80 ) ) )){
			PutSysLog( (const UINT8 *)command_error );
		}
		else{
			echo[0] = command;
			PutSysLog( (const UINT8 *)echo );

			/*
			 *  �R�}���h����
			 */
			switch( command ){
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
				/*
				 *  �����Ώۃ^�X�N�̕ύX
				 */
				task_no = (UINT8)( command - '1' );
				break;
			case 'A':
			case '!':
			case '"':
			case '#':
			case '$':
			case '%':
			case 'z':
			case 'k':
			case 'K':
			case 'l':
			case 'i':
			case 'w':
			case 'W':
				/*
				 *  �^�X�N�ւ̃R�}���h�ʒm
				 */
				command_tbl[task_no] = command;
				break;
			case 0:
				command_tbl[cur_task_no] = 0xFF;
				break;
				/*
				 *  �ȍ~�̓��C���^�X�N�ŃR�}���h����
				 */
			case 'a':
				PutActTsk( task_no );
				break;
			case 's':
				PutSchedule();
				break;
			case 'S':
				PutActNonPriTsk();
				break;
			case 'Z':
				PutTaskState( task_no );
				break;
			case 'd':
				PutDisAllInt();
				break;
			case 'D':
				PutSusAllInt();
				break;
			case 'f':
				PutSusOSInt();
				break;
			case 'T':
				PutHwCnt3();
				break;
			case 'e':
				PutSetEvt( task_no );
				break;
			case 'E':
				PutGetEvt( task_no );
				break;
			case 'b':
				PutArmBase();
				break;
			case 'B':
				PutArmTick();
				PutArmTick();
				break;
			case 'v':
				/* SetRelAlarm( ActTskArm, 500, 0 );	*/
				PutSetRel(0, 0, 0);
				break;
			case 'V':
				/* SetRelAlarm( SetEvtArm, 500, 0 );	*/
				PutSetRel(1, 0, 0);
				break;
			case 'n':
				/* SetRelAlarm( CallBackArm, 900, 0 );	*/
				PutSetRel(2, 1, 0);
				break;
			case 'N':
				/* SetRelAlarm( CallBackArm, 900, 500 );	*/
				PutSetRel(2, 1, 1);
				break;
			case 'm':
				/* SetAbsAlarm( CallBackArm, 900, 0 );		*/
				PutSetAbs(2, 1, 0);
				break;
			case 'M':
				/* SetAbsAlarm( CallBackArm, 900, 500 );	*/
				PutSetAbs(2, 1, 1);
				break;
			case 'h':
				/* CancelAlarm( CallBackArm );				*/
				PutCanArm();
				break;
			case 'c':
				PutSysLog( (const UINT8 *)
							"Call SignalCounter(SampleCnt)\r\n" );
				ActCounterInt();
				break;
			case 'p':
				PutAppMode();
				break;
			case 'q':
				ShutdownOS( E_OK );
				break;
			case 'Q':
				ShutdownOS( E_OS_STATE );
				break;
			default:
				break;
			}
		}
	}

	/*
	 *  �����ɂ͂��Ȃ��D
	 */
	PutSysLog( (const UINT8 *)"MainTask TERMINATE\r\n" );
	error_log( TerminateTask() );
}	/* TASK( MainTask )	*/


/*
 *  �ō��D��x�^�X�N
 *
 *  �e�^�X�N�̃v���G���v�g�m�F�p�D
 */
TASK( HighPriorityTask )
{
	PutSysLog( (const UINT8 *)"HighPriorityTask ACTIVATE\r\n" );

	error_log( TerminateTask() );
}	/* TASK( HighPriorityTask )	*/


/*
 *  �m���v���G���v�e�B�u�^�X�N
 *
 *  ���s���̓v���G���v�g���Ȃ����Ƃ̊m�F�p�D
 */
TASK( NonPriTask )
{
	PutSysLog( (const UINT8 *)"NonPriTask ACTIVATE\r\n" );
	PutSysLog( (const UINT8 *)
				"Call ActivateTask(HighPriorityTask)\r\n" );
	error_log( ActivateTask( HighPriorityTask ) );
	PutSysLog( (const UINT8 *)"NonPriTask TERMINATE\r\n" );

	error_log( TerminateTask() );
}	/* TASK( NonPriTask )	*/


/*
 *  ������s�^�X�N1
 */
TASK( Task1 )
{
	TaskProk( 0 );
}	/* TASK( Task1 )	*/


/*
 *  ������s�^�X�N2
 */
TASK( Task2 )
{
	TaskProk( 1 );
}	/* TASK( Task2 )	*/


/*
 *  ������s�^�X�N3
 */
TASK( Task3 )
{
	TaskProk( 2 );
}	/* TASK( Task3 )	*/


/*
 *  ������s�^�X�N4
 */
TASK( Task4 )
{
	TaskProk( 3 );
}	/* TASK( Task4 )	*/


/*
 *  ������s�^�X�N5
 */
TASK( Task5 )
{
	TaskProk( 4 );
}	/* TASK( Task5 )	*/


/*
 *  ������s�^�X�N��������
 *
 *  ���C���^�X�N����ʒm���ꂽ�R�}���h���Ƃ̏������s�D
 */
static void
TaskProk( UINT8 task_no )
{
	UINT8		command;	/* �R�}���h�ޔ��o�b�t�@	*/
	UINT8		count = 0;

	/*
	 *  �^�X�N�N�����O�o��
	 */
	PutSysLog( task_name_tbl[task_no] );
	PutSysLog( (const UINT8 *)" ACTIVATE\r\n" );

	/*
	 *  �R�}���h���s���[�v
	 */
	while( 1 ){

		/*
		 *  �R�}���h�擾
		 */
		while( command_tbl[task_no] == 0 ) {
			cur_task_no = task_no;
		}
		command = command_tbl[task_no];
		command_tbl[task_no] = 0;

		/*
		 *  �R�}���h����
		 */
		switch( command ){
		case 'A':
			PutTermTsk( task_no );
			break;
		case '!':
		case '"':
		case '#':
		case '$':
		case '%':
			PutChainTsk( task_no, ( command - '!' ) );
			break;
		case 'z':
			PutTaskID();
			break;
		case 'k':
			PutGetTskRes();
			break;
		case 'K':
			PutRelTskRes();
			break;
		case 'l':
			PutGetSchedRes();
			break;
		case 'i':
			PutGetIntRes();
			break;
		case 'w':
			PutClrEvt( task_no );
			break;
		case 'W':
			PutWaitEvt( task_no );
			break;
		default:
			count ++;
			if (count >= 5) {
				PutSysLog( task_name_tbl[task_no] );
				PutSysLog( (const UINT8 *)" is running\r\n" );
				count = 0;
			}
			break;
		}
	}
}	/* TaskProk	*/



/*
 *  �G���[�t�b�N���[�`��
 */
#ifdef USE_ERRORHOOK
void ErrorHook( StatusType ercd )
{
	UINT8	str_buf[16];	/* ���O�����񐶐��o�b�t�@	*/

	/*
	 *  �G���[�R�[�h���O�o��
	 */
	PutSysLog( (const UINT8 *)"Error:" );
	PutSysLog( ercd_tbl[ercd] );

	/*
	 *  �G���[�v�����Ƃ̃p�����[�^���O�o��
	 */
	switch( OSErrorGetServiceId() ){
	case OSServiceId_ActivateTask:
		PutSysLog( (const UINT8 *)"=ActivateTask(" );
		ConvByte2DecStr( str_buf, OSError_ActivateTask_TaskID() );
		PutSysLog( (const UINT8 *)str_buf );
		break;
	case OSServiceId_TerminateTask:
		PutSysLog( (const UINT8 *)"=TerminateTask(" );
		break;
	case OSServiceId_ChainTask:
		PutSysLog( (const UINT8 *)"=ChainTask(" );
		ConvByte2DecStr( str_buf, OSError_ChainTask_TaskID() );
		PutSysLog( (const UINT8 *)str_buf );
		break;
	case OSServiceId_Schedule:
		PutSysLog( (const UINT8 *)"=Schedule(" );
		break;
	case OSServiceId_GetTaskID:
		PutSysLog( (const UINT8 *)"=GetTaskID(0x" );
		ConvLong2HexStr( str_buf, (UINT32)OSError_GetTaskID_TaskID() );
		PutSysLog( (const UINT8 *)str_buf );
		break;
	case OSServiceId_GetTaskState:
		PutSysLog( (const UINT8 *)"=GetTaskState(" );
		ConvByte2DecStr( str_buf, OSError_GetTaskState_TaskID() );
		PutSysLog( (const UINT8 *)str_buf );
		PutSysLog( (const UINT8 *)",0x" );
		ConvLong2HexStr( str_buf, (UINT32)OSError_GetTaskState_State() );
		PutSysLog( (const UINT8 *)str_buf );
		break;
	case OSServiceId_EnableAllInterrupts:
		PutSysLog( (const UINT8 *)"=EnableAllInterrupts(" );
		break;
	case OSServiceId_DisableAllInterrupts:
		PutSysLog( (const UINT8 *)"=DisableAllInterrupts(" );
		break;
	case OSServiceId_ResumeAllInterrupts:
		PutSysLog( (const UINT8 *)"=ResumeAllInterrupts(" );
		break;
	case OSServiceId_SuspendAllInterrupts:
		PutSysLog( (const UINT8 *)"=SuspendAllInterrupts(" );
		break;
	case OSServiceId_ResumeOSInterrupts:
		PutSysLog( (const UINT8 *)"=ResumeOSInterrupts(" );
		break;
	case OSServiceId_SuspendOSInterrupts:
		PutSysLog( (const UINT8 *)"=SuspendOSInterrupts(" );
		break;
	case OSServiceId_GetResource:
		PutSysLog( (const UINT8 *)"=GetResource(" );
		ConvByte2DecStr( str_buf, OSError_GetResource_ResID() );
		PutSysLog( (const UINT8 *)str_buf );
		break;
	case OSServiceId_ReleaseResource:
		PutSysLog( (const UINT8 *)"=ReleaseResource(" );
		ConvByte2DecStr( str_buf, OSError_ReleaseResource_ResID() );
		PutSysLog( (const UINT8 *)str_buf );
		break;
	case OSServiceId_SetEvent:
		PutSysLog( (const UINT8 *)"=SetEvent(" );
		ConvByte2DecStr( str_buf, OSError_SetEvent_TaskID() );
		PutSysLog( (const UINT8 *)str_buf );
		PutSysLog( (const UINT8 *)",0x" );
		ConvLong2HexStr( str_buf, OSError_SetEvent_Mask() );
		PutSysLog( (const UINT8 *)str_buf );
		break;
	case OSServiceId_ClearEvent:
		PutSysLog( (const UINT8 *)"=ClearEvent(0x" );
		ConvLong2HexStr( str_buf, OSError_ClearEvent_Mask() );
		PutSysLog( (const UINT8 *)str_buf );
		break;
	case OSServiceId_GetEvent:
		PutSysLog( (const UINT8 *)"=GetEvent(" );
		ConvByte2DecStr( str_buf, OSError_GetEvent_TaskID() );
		PutSysLog( (const UINT8 *)str_buf );
		PutSysLog( (const UINT8 *)",0x" );
		ConvLong2HexStr( str_buf, (UINT32)OSError_GetEvent_Mask() );
		PutSysLog( (const UINT8 *)str_buf );
		break;
	case OSServiceId_WaitEvent:
		PutSysLog( (const UINT8 *)"=WaitEvent(0x" );
		ConvLong2HexStr( str_buf, OSError_WaitEvent_Mask() );
		PutSysLog( (const UINT8 *)str_buf );
		break;
	case OSServiceId_GetAlarmBase:
		PutSysLog( (const UINT8 *)"=GetAlarmBase(" );
		ConvByte2DecStr( str_buf, OSError_GetAlarmBase_AlarmID() );
		PutSysLog( (const UINT8 *)str_buf );
		PutSysLog( (const UINT8 *)",0x" );
		ConvLong2HexStr( str_buf, (UINT32)OSError_GetAlarmBase_Info() );
		PutSysLog( (const UINT8 *)str_buf );
		break;
	case OSServiceId_GetAlarm:
		PutSysLog( (const UINT8 *)"=GetAlarm(" );
		ConvByte2DecStr( str_buf, OSError_GetAlarm_AlarmID() );
		PutSysLog( (const UINT8 *)str_buf );
		PutSysLog( (const UINT8 *)"," );
		ConvLong2DecStr( str_buf, (UINT32)OSError_GetAlarm_Tick() );
		PutSysLog( (const UINT8 *)str_buf );
		break;
	case OSServiceId_SetRelAlarm:
		PutSysLog( (const UINT8 *)"=SetRelAlarm(" );
		ConvByte2DecStr( str_buf, OSError_SetRelAlarm_AlarmID() );
		PutSysLog( (const UINT8 *)str_buf );
		PutSysLog( (const UINT8 *)"," );
		ConvLong2DecStr( str_buf, OSError_SetRelAlarm_increment() );
		PutSysLog( (const UINT8 *)str_buf );
		PutSysLog( (const UINT8 *)"," );
		ConvLong2DecStr( str_buf, OSError_SetRelAlarm_cycle() );
		PutSysLog( (const UINT8 *)str_buf );
		break;
	case OSServiceId_SetAbsAlarm:
		PutSysLog( (const UINT8 *)"=SetAbsAlarm(" );
		ConvByte2DecStr( str_buf, OSError_SetAbsAlarm_AlarmID() );
		PutSysLog( (const UINT8 *)str_buf );
		PutSysLog( (const UINT8 *)"," );
		ConvLong2DecStr( str_buf, OSError_SetAbsAlarm_start() );
		PutSysLog( (const UINT8 *)str_buf );
		PutSysLog( (const UINT8 *)"," );
		ConvLong2DecStr( str_buf, OSError_SetAbsAlarm_cycle() );
		PutSysLog( (const UINT8 *)str_buf );
		break;
	case OSServiceId_CancelAlarm:
		PutSysLog( (const UINT8 *)"=CancelAlarm(" );
		ConvByte2DecStr( str_buf, OSError_CancelAlarm_AlarmID() );
		PutSysLog( (const UINT8 *)str_buf );
		break;
	case OSServiceId_GetActiveApplicationMode:
		PutSysLog( (const UINT8 *)"=GetActiveApplicationMode(" );
		break;
	case OSServiceId_StartOS:
		PutSysLog( (const UINT8 *)"=StartOS(" );
		break;
	case OSServiceId_ShutdownOS:
		PutSysLog( (const UINT8 *)"=ShutdownOS(" );
		break;
	case OSServiceId_SignalCounter:
		PutSysLog( (const UINT8 *)"=SignalCounter(" );
		ConvByte2DecStr( str_buf, OSError_SignalCounter_CounterID() );
		PutSysLog( (const UINT8 *)str_buf );
		break;
	default:
		PutSysLog( (const UINT8 *)"=UnKnownFunc(" );
		break;
	}

	PutSysLog( (const UINT8 *)")\r\n" );
}	/* ErrorHook	*/
#endif /* USE_ERRORHOOK */

/*
 *  �v���^�X�N�t�b�N���[�`��
 *
 *  �{�T���v���ł͖��g�p�D
 */
#ifdef USE_PRETASKHOOK
void PreTaskHook( void )
{
}	/* PreTaskHook	*/
#endif /* USE_PRETASKHOOK */

/*
 *  �|�X�g�^�X�N�t�b�N���[�`��
 *
 *  �{�T���v���ł͖��g�p�D
 */
#ifdef USE_POSTTASKHOOK
void PostTaskHook( void )
{
}	/* PostTaskHook	*/
#endif /* USE_POSTTASKHOOK */

/*
 *  �X�^�[�g�A�b�v�t�b�N���[�`��
 */
#ifdef USE_STARTUPHOOK
void StartupHook( void )
{
	InitSerial();		/* �V���A��IO���W���[��������		*/
	/* �N�����O�o��	*/
	PutIntSysLog( (const UINT8 *)
					"\r\nTOPPERS Automotive Kernel Release 1.0" );
#if defined( TARGET_NAME )
	PutIntSysLog( (const UINT8 *)" for " );
	PutIntSysLog( TARGET_NAME );
#endif	/* TARGET_NAME	*/
	PutIntSysLog( (const UINT8 *)
					"\r\nECC2 Sample System StartUp\r\n\r\n" );
	InitSysTimer();		/* �V�X�e���^�C�}�N��				*/
	InitCounterInt();	/* SignalCounter���s�p�����ݏ�����	*/
	InitHwCntInt();		/* �����݌��ؗp�J�E���^�N��			*/
}	/* StartupHook	*/
#endif /* USE_STARTUPHOOK */

/*
 *  �V���b�g�_�E���t�b�N���[�`��
 */
#ifdef USE_SHUTDOWNHOOK
void ShutdownHook( StatusType ercd )
{
	TermHwCntInt();		/* �����݌��ؗp�J�E���^��~			*/
	TermCounterInt();	/* SignalCounter���s�p�����ݒ�~	*/
	TermSysTimer();		/* �V�X�e���^�C�}��~				*/
	/* �I�����O�o��	*/
	PutIntSysLog( (const UINT8 *)
					"\r\nECC2 Sample System ShutDown\r\nShutDownCode:" );
	PutIntSysLog( ercd_tbl[ercd] );
	PutIntSysLog( (const UINT8 *)"\r\n\r\n" );
	TermSerial();		/* �V���A��IO���W���[����~			*/
}	/* ShutdownHook	*/
#endif /* USE_SHUTDOWNHOOK */

/*
 *  �V�X�e���^�C�}�ɂ��A���[���R�[���o�b�N
 */
ALARMCALLBACK( SysTimerAlmCb )
{
	/*
	 *  �R�[���o�b�N���s���O�o��
	 */
	PutSysLog( (const UINT8 *)"CallBackArm Expire\r\n" );
}	/* ALARMCALLBACK(SysTimerAlmCb)	*/

/*
 *  SignalCounter�m�F�p�A���[���R�[���o�b�N
 */
ALARMCALLBACK( SampleAlmCb )
{
	/*
	 *  �R�[���o�b�N���s���O�o��
	 */
	PutSysLog( (const UINT8 *)"SampleArm Expire\r\n" );
}	/* ALARMCALLBACK( SampleAlmCb )	*/


