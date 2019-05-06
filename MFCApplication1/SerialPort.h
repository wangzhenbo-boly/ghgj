#pragma once
#ifndef _SERIAL_PORT_CONTROL_H
#define _SERIAL_PORT_CONTROL_H



extern HANDLE hCom; //全局变量，串口句柄
extern CString strChoosed;

//打开并设置PC串口1(COM1)
extern BOOL OpenSerialPort();

#endif
