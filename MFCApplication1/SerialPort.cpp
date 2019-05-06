
#include "StdAfx.h"
#include "SerialPort.h"

HANDLE hCom; //ȫ�ֱ��������ھ��
CString strChoosed;

BOOL OpenSerialPort()   //��ʼ������
{
	//�򿪲�����COM1
	hCom = CreateFile(strChoosed, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);  //COM3�������Ūһ��comboboxѡ��
	if (hCom == (HANDLE)-1)
	{
		AfxMessageBox(L"�򿪴���ʧ��");
		return false;
	}
	else
	{
		COMMTIMEOUTS TimeOuts;
		//�趨����ʱ
		TimeOuts.ReadIntervalTimeout = MAXDWORD;
		TimeOuts.ReadTotalTimeoutMultiplier = 0;
		TimeOuts.ReadTotalTimeoutConstant = 0;
		//�ڶ�һ�����뻺���������ݺ���������������أ�
		//�������Ƿ������Ҫ����ַ���


		//�趨д��ʱ
		TimeOuts.WriteTotalTimeoutMultiplier = 100;
		TimeOuts.WriteTotalTimeoutConstant = 500;
		SetCommTimeouts(hCom, &TimeOuts); //���ó�ʱ
		SetupComm(hCom, 100, 100); //���뻺����������������Ĵ�С����1024
		DCB wdcb;
		GetCommState(hCom, &wdcb);
		wdcb.BaudRate = 115200;//�����ʣ�115200������������
		wdcb.ByteSize = 8;   //ÿ���ֽ�8λ
		wdcb.Parity = NOPARITY;  //��ֹͣλ
		SetCommState(hCom, &wdcb);
		PurgeComm(hCom, PURGE_TXCLEAR | PURGE_RXCLEAR);
	}
	return true;
}
