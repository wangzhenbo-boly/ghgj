#pragma once

#pragma once
//crc-16.h 头文件

#pragma once

class CRC_16
{
public:
	//CRC_16 多项式
	int CRC_polynomial;

	int Check_CRC_16(unsigned char *data, char length);
	void Set_Polynomial(int crc_polynomial);
};

extern CRC_16 *checkCRC_16;