
//头文件
#include "stdafx.h"
#include "CRC-16.h"


CRC_16 *checkCRC_16 = new CRC_16;


//设置多项式
void CRC_16::Set_Polynomial(int crc_polynomial)
{
	CRC_16::CRC_polynomial = crc_polynomial;
}


//CRC校验，生成CRC_16校验码
int CRC_16::Check_CRC_16(unsigned char *data, char length)
{
	unsigned  short  reg_crc;
	unsigned  short  s_crcchk;
	s_crcchk = 0;
	reg_crc = 0xffff;

	Set_Polynomial(0xA001);

	while (length--)
	{
		reg_crc ^= *data++;
		for (s_crcchk = 0; s_crcchk < 8; s_crcchk++)
		{
			if (reg_crc & 0x01)
			{
				reg_crc = (reg_crc >> 1) ^ CRC_16::CRC_polynomial;
			}
			else
			{
				reg_crc = reg_crc >> 1;
			}
		}
	}
	return  reg_crc;
	//unsigned int  IX, IY, CRC;
	//CRC = 0xFFFF;//set all 1
	//unsigned char Rcvbuf[2];
	//if (length <= 0)
	//	CRC = 0;
	//else
	//{
	//	length--;
	//	for (IX = 0; IX <= length; IX++)
	//	{
	//		CRC = CRC ^ (unsigned int)(data[IX]);
	//		for (IY = 0; IY <= 7; IY++)
	//		{
	//			if ((CRC & 1) != 0)
	//				CRC = (CRC >> 1) ^ 0xA001;
	//			else
	//				CRC = CRC >> 1;    //
	//		}
	//	}

	//}
	//Rcvbuf[0] = (CRC & 0xff00) >> 8;//高位置
	//Rcvbuf[1] = (CRC & 0x00ff);  //低位置

	//CRC = Rcvbuf[0] << 8;
	//CRC += Rcvbuf[1];
	//return CRC;
}