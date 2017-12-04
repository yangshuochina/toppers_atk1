/*
 *  TOPPERS Automotive Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems
 *      Automotive Kernel
 * 
 *  Copyright (C) 2006 by Witz Corporation, JAPAN
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
 *	�T���v�������V���A��IO���W���[��
 */

#include	"hw_serial.h"
#include	"serial.h"


/*
 *  ��M�p�f�[�^
 */
static UINT8	rx_char;
static BOOL		rx_flag;

/*
 *  �V���A��IO���W���[������������
 *
 *  �����݋֎~��ԂŌďo�����ƁD
 */
void
InitSerial( void )
{
	/*
	 *  ��M�t���O������
	 */
	rx_flag = FALSE;

	/*
	 *  �ˑ����������������s
	 */
	InitHwSerial();
}	/* InitSerial	*/

/*
 *  �V���A��IO���W���[����~����
 *
 *  �o�͂��������Ă��邱�Ƃ͕ۏႵ�Ȃ��i�f�b�h���b�N�h�~�j�D
 *  �R���e�L�X�g���b�N���ďo�͂���̂ŁC�قږ��Ȃ��i�Ō�̂Q�����̂݁j�D
 *
 *  �����݋֎~��ԂŌďo�����ƁD
 */
void
TermSerial( void )
{
	/*
	 *  �ˑ����������������s
	 */
	TermHwSerial();

	/*
	 *  ��M�f�[�^������
	 */
	rx_flag = FALSE;
}	/* TermSerial	*/

/*
 *  �����񑗐M����
 */
void
SendSerialStr( const UINT8 * str )
{
	/*
	 *  �����݋֎~��Ԃɂ��āC�����ݒ������񑗐M�������s
	 */
	SuspendAllInterrupts();
	SendIntSerialStr( str );
	ResumeAllInterrupts();
}	/* SendSerialStr	*/

/*
 *  �����ݒ������񑗐M����
 */
void
SendIntSerialStr( const UINT8 * str )
{
	/*
	 *  �ˑ��������o�͏����ɂđS�f�[�^�𑗐M
	 */
	while( *str != '\0' ){
		PutHwChar( *str );
		str++;
	}
}	/* SendIntSerialStr	*/

/*
 *  ������M����
 */
void RecvPolSerialChar( UINT8 * character )
{
	if( rx_flag == TRUE ){
	/*
	 *  �����݋֎~�ɂ��Ď�M�f�[�^�擾�E�t���O�N���A
	 */
		SuspendAllInterrupts();
		*character = rx_char;
		rx_flag = FALSE;
		ResumeAllInterrupts();
	}
	else{
	/*
	 *  ��M�f�[�^���Ȃ��ꍇ��'\0'��Ԃ�
	 */
		*character = '\0';
	}
}	/* RecvPolSerialChar	*/

/*
 *  ��M�R�[���o�b�N�֐�
 */
void
RxSerialInt( UINT8 character )
{
	/*
	 *  �����݋֎~�ɂ��Ď�M�f�[�^�ێ��E�t���O�N���A
	 */
	SuspendAllInterrupts();
	rx_char = character;
	rx_flag = TRUE;
	ResumeAllInterrupts();
}	/* RxSerialInt	*/

/*
 *  32bit���l -> 10�i��������ϊ��֐�
 */
void
ConvLong2DecStr( UINT8 *dst, UINT32 src )
{
	UINT32	temp;	/* �����Z�o�p�e���|����	*/

	/*
	 *  �\�������Z�o
	 */
	temp = src;
	while( ( temp /= 10 ) != 0 ){
		dst++;
	}
	
	dst[1] = '\0';	/* ������I�[�R�[�h�ݒ�	*/

	/*
	 *  �����ɕϊ�
	 */
	do{
		*dst-- = (UINT8)( ( src % 10 ) + '0' );
	} while( ( src /= 10 ) != 0 );
}	/* ConvLong2DecStr	*/

/*
 *  16bit���l -> 10�i��������ϊ��֐�
 */
void
ConvShort2DecStr( UINT8 *dst, UINT16 src )
{
	UINT16	temp;	/* �����Z�o�p�e���|����	*/

	/*
	 *  �\�������Z�o
	 */
	temp = src;
	while( ( temp /= 10 ) != 0 ){
		dst++;
	}
	
	dst[1] = '\0';	/* ������I�[�R�[�h�ݒ�	*/

	/*
	 *  �����ɕϊ�
	 */
	do{
		*dst-- = (UINT8)( ( src % 10 ) + '0' );
	} while( ( src /= 10 ) != 0 );
}	/* ConvShort2DecStr	*/

/*
 *  8bit���l -> 10�i��������ϊ��֐�
 */
void
ConvByte2DecStr( UINT8 *dst, UINT8 src )
{
	UINT8	temp;	/* �����Z�o�p�e���|����	*/

	/*
	 *  �\�������Z�o
	 */
	temp = src;
	while( ( temp /= 10 ) != 0 ){
		dst++;
	}
	
	dst[1] = '\0';	/* ������I�[�R�[�h�ݒ�	*/

	/*
	 *  �����ɕϊ�
	 */
	do{
		*dst-- = (UINT8)( ( src % 10 ) + '0' );
	} while( ( src /= 10 ) != 0 );
}	/* ConvByte2DecStr	*/

/*
 *  32bit���l -> 16�i��������ϊ��֐�
 *
 *  �{�֐��̏o�̓o�b�t�@�i*dst���w��������j�� 9Byte�i8��+�����I�[�R�[�h�j
 *  �ȏ�ێ����邱�Ƃ�O��Ƃ���D
 */
void
ConvLong2HexStr( UINT8 *dst, UINT32 src )
{
	UINT8	mod;
	INT8	idx = 8;
	/*
	 *  8��0�l�߂�16�i��������ɕϊ�
	 */

	dst[idx--] = '\0';	/* ������I�[�R�[�h�ݒ�	*/

	/*
	 *  16�i�����ɕϊ�
	 */
	do{
		mod = (UINT8)( src & (UINT32)0x0000000f );
		if( mod < 10 ){
			dst[idx--] = (UINT8)( mod + '0' );
		}
		else{
			dst[idx--] = (UINT8)( ( mod - 10 ) + 'A' );
		}
	} while( ( src >>= 4 ) != 0 );

	/*
	 *  �c��̌���0�l��
	 */
	while( idx >= 0 ){
		dst[idx--] = (UINT8)'0';
	}
}	/* ConvLong2HexStr	*/

/*
 *  16bit���l -> 16�i��������ϊ��֐�
 *
 *  �{�֐��̏o�̓o�b�t�@�i*dst���w��������j�� 5Byte�i4��+�����I�[�R�[�h�j
 *  �ȏ�ێ����邱�Ƃ�O��Ƃ���D
 */
void
ConvShort2HexStr( UINT8 *dst, UINT16 src )
{
	UINT8	mod;
	INT8	idx = 4;
	/*
	 *  4��0�l�߂�16�i��������ɕϊ�
	 */

	dst[idx--] = '\0';	/* ������I�[�R�[�h�ݒ�	*/

	/*
	 *  16�i�����ɕϊ�
	 */
	do{
		mod = (UINT8)( src & (UINT16)0x000f );
		if( mod < 10 ){
			dst[idx--] = (UINT8)( mod + '0' );
		}
		else{
			dst[idx--] = (UINT8)( ( mod - 10 ) + 'A' );
		}
	} while( ( src >>= 4 ) != 0 );

	/*
	 *  �c��̌���0�l��
	 */
	while( idx >= 0 ){
		dst[idx--] = (UINT8)'0';
	}
}	/* ConvShort2HexStr	*/

/*
 *  8bit���l -> 16�i��������ϊ��֐�
 *
 *  �{�֐��̏o�̓o�b�t�@�i*dst���w��������j�� 3Byte�i2��+�����I�[�R�[�h�j
 *  �ȏ�ێ����邱�Ƃ�O��Ƃ���D
 */
void
ConvByte2HexStr( UINT8 *dst, UINT8 src )
{
	UINT8	mod;
	INT8	idx = 2;
	/*
	 *  2��0�l�߂�16�i��������ɕϊ�
	 */

	dst[idx--] = '\0';	/* ������I�[�R�[�h�ݒ�	*/

	/*
	 *  16�i�����ɕϊ�
	 */
	do{
		mod = (UINT8)( src & (UINT8)0x0f );
		if( mod < 10 ){
			dst[idx--] = (UINT8)( mod + '0' );
		}
		else{
			dst[idx--] = (UINT8)( ( mod - 10 ) + 'A' );
		}
	} while( ( src >>= 4 ) != 0 );

	/*
	 *  �c��̌���0�l��
	 */
	while( idx >= 0 ){
		dst[idx--] = (UINT8)'0';
	}
}	/* ConvByte2HexStr	*/


