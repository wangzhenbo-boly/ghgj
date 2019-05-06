
#include "StdAfx.h"
#include "SerialPort.h"

HANDLE hCom; //全局变量，串口句柄
CString strChoosed;

BOOL OpenSerialPort()   //初始化串口
{
	//打开并设置COM1
	hCom = CreateFile(strChoosed, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);  //COM3这里可以弄一个combobox选择
	if (hCom == (HANDLE)-1)
	{
		AfxMessageBox(L"打开串口失败");
		return false;
	}
	else
	{
		COMMTIMEOUTS TimeOuts;
		//设定读超时
		TimeOuts.ReadIntervalTimeout = MAXDWORD;
		TimeOuts.ReadTotalTimeoutMultiplier = 0;
		TimeOuts.ReadTotalTimeoutConstant = 0;
		//在读一次输入缓冲区的内容后读操作就立即返回，
		//而不管是否读入了要求的字符。


		//设定写超时
		TimeOuts.WriteTotalTimeoutMultiplier = 100;
		TimeOuts.WriteTotalTimeoutConstant = 500;
		SetCommTimeouts(hCom, &TimeOuts); //设置超时
		SetupComm(hCom, 100, 100); //输入缓冲区和输出缓冲区的大小都是1024
		DCB wdcb;
		GetCommState(hCom, &wdcb);
		wdcb.BaudRate = 115200;//波特率：115200，其他：不变
		wdcb.ByteSize = 8;   //每个字节8位
		wdcb.Parity = NOPARITY;  //无停止位
		SetCommState(hCom, &wdcb);
		PurgeComm(hCom, PURGE_TXCLEAR | PURGE_RXCLEAR);
	}
	return true;
}
