#pragma once
#ifndef _SERIAL_PORT_CONTROL_H
#define _SERIAL_PORT_CONTROL_H



extern HANDLE hCom; //ȫ�ֱ��������ھ��
extern CString strChoosed;

//�򿪲�����PC����1(COM1)
extern BOOL OpenSerialPort();

#endif
