
// MFCApplication1Dlg.cpp: 实现文件
//

#include "stdafx.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"
#include "SerialPort.h"
#include "CRC-16.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication1Dlg 对话框



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
	, Cont_noodle(0)
	, Time_noodle(0)
	//, v_radio(FALSE)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_comboCom);
	DDX_Text(pDX, IDC_EDIT2, Cont_noodle);
	DDX_Text(pDX, IDC_EDIT1, Time_noodle);
	DDX_Control(pDX, IDC_COMBO2, Combox_Object);
	DDX_Control(pDX, IDC_RADIO1, Radio_button);
	//DDX_Radio(pDX, IDC_RADIO1, v_radio);
	//DDX_Control(pDX, IDC_RADIO2, Radio2);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_DROPDOWN(IDC_COMBO1, &CMFCApplication1Dlg::OnCbnDropdownCombo1)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication1Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDOK, &CMFCApplication1Dlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication1Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_RADIO1, &CMFCApplication1Dlg::OnBnClickedRadio1)
//	ON_NOTIFY(BCN_HOTITEMCHANGE, IDC_RADIO1, &CMFCApplication1Dlg::OnBnHotItemChangeRadio1)
//ON_BN_CLICKED(IDC_RADIO2, &CMFCApplication1Dlg::OnBnClickedRadio2)
ON_BN_CLICKED(IDC_BUTTON4, &CMFCApplication1Dlg::OnBnClickedButton4)
ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplication1Dlg::OnBnClickedButton3)
ON_BN_CLICKED(IDC_BUTTON5, &CMFCApplication1Dlg::OnBnClickedButton5)
ON_BN_CLICKED(IDC_BUTTON6, &CMFCApplication1Dlg::OnBnClickedButton6)
ON_BN_CLICKED(IDC_BUTTON7, &CMFCApplication1Dlg::OnBnClickedButton7)
ON_BN_CLICKED(IDC_BUTTON8, &CMFCApplication1Dlg::OnBnClickedButton8)
ON_BN_CLICKED(IDC_BUTTON9, &CMFCApplication1Dlg::OnBnClickedButton9)
END_MESSAGE_MAP()


// CMFCApplication1Dlg 消息处理程序

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	CWinThread* thread = AfxBeginThread(ThreadFun, (void*)this);
	GetDlgItem(IDC_EDIT2)->SetWindowText(_T("1"));
	GetDlgItem(IDC_EDIT1)->SetWindowText(_T("240"));
	//this->Combox_Object.AddString(L"1");
	GetDlgItem(IDC_COMBO2)->SetWindowText(_T("1"));
	//Combox_Object.editable
	//((CButton *)GetDlgItem(IDC_RADIO1))->SetCheck(TRUE);
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCApplication1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCApplication1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplication1Dlg::OnCbnDropdownCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
	m_comboCom.ResetContent();
	FindCommPort(&m_comboCom);
}


void CMFCApplication1Dlg::FindCommPort(CComboBox *pComboBox)
{
	HKEY hKey;

	//#ifdef _DEBUG
	//	ASSERT(pComboBox != NULL);
	//	//pComboBox->AssertValid();
	//	pComboBox.AssertValid();
	//#endif
	//
	LONG nRetVal = RegOpenKeyEx(HKEY_LOCAL_MACHINE,
		_T("Hardware\\DeviceMap\\SerialComm"), NULL,
		KEY_READ, &hKey);
	if (nRetVal == ERROR_SUCCESS)
	{
		int i = 0;
		char portName[256], commName[256];
		DWORD dwLong, dwSize;
		while (1)
		{
			dwLong = dwSize = sizeof(portName);
			nRetVal = RegEnumValue(hKey, i, (LPWSTR)portName, &dwLong, NULL, NULL, (PUCHAR)commName, &dwSize);
			if (nRetVal == ERROR_NO_MORE_ITEMS) // 枚举串口
				break;

			CString strCommName;
			strCommName.Format(_T("%s"), commName);
			//strCommName += _T("(可用)");
			pComboBox->AddString(strCommName); // commName：串口名字
			i++;
		}
		if (pComboBox->GetCount() == 0)
		{
			AfxMessageBox(_T("[HKEY_LOCAL_MACHINE:Hardware\\DeviceMap\\SerialComm]里无串口!"));
		}
		RegCloseKey(hKey);
	}
}

void CMFCApplication1Dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString temp;
	GetDlgItem(IDC_BUTTON1)->GetWindowText(temp);
	if (temp == L"打开串口")
	{
		m_comboCom.GetLBText(m_comboCom.GetCurSel(), strChoosed);
		if (strChoosed.GetLength() > 4)
		{
			strChoosed = _T("\\\\.\\") + strChoosed;
		}
		if (OpenSerialPort())
		{
			State_Comm = TRUE;
			CString ttemp = L"关闭串口";
			GetDlgItem(IDC_BUTTON1)->SetWindowText(ttemp);
		}
	}
	else
	{
		CString ttemp = L"打开串口";
		State_Comm = FALSE;
		GetDlgItem(IDC_BUTTON1)->SetWindowText(ttemp);
		CloseHandle(hCom);
		
	}
}


void CMFCApplication1Dlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
//	CDialogEx::OnOK();
	if (State_Comm)
	{
		Send_Flag = 1;
		MessageBox(_T("指令下发成功！"));
	}
	else
	{
		MessageBox(_T("串口未打开！"));
	}
	
}


void CMFCApplication1Dlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	CloseHandle(hCom);
	CDialogEx::OnClose();
	PostMessage(WM_CLOSE);
}


void CMFCApplication1Dlg::OnBnClickedRadio1()
{
	// TODO: 在此添加控件通知处理程序代码
	
	if (Radio_button.GetCheck())
	{
		
		Radio_button.SetCheck(0);
		//Radio_button = 0;
		Value_button = 0;

	}
	else
	{
		Radio_button.SetCheck(1);
		Value_button = 1;
	}
	//else
	//{
	//	//v_radio = TRUE;
	//	Radio_button.SetCheck(1);
	//}
	
		//((CButton *)GetDlgItem(IDC_RADIO1))->SetCheck(FALSE);	
	//else
	
		//((CButton *)GetDlgItem(IDC_RADIO1))->SetCheck(TRUE);
}


//void CMFCApplication1Dlg::OnBnHotItemChangeRadio1(NMHDR *pNMHDR, LRESULT *pResult)
//{
//	// 此功能要求 Internet Explorer 6 或更高版本。
//	// 符号 _WIN32_IE 必须是 >= 0x0600。
//	LPNMBCHOTITEM pHotItem = reinterpret_cast<LPNMBCHOTITEM>(pNMHDR);
//	// TODO: 在此添加控件通知处理程序代码
//	*pResult = 0;
//}

//
//void CMFCApplication1Dlg::OnBnClickedRadio2()
//{
//	// TODO: 在此添加控件通知处理程序代码
//	if (Radio2.GetCheck())
//	{
//		Radio2.SetCheck(0);
//	}
//	else
//	{
//		Radio2.SetCheck(1);
//	}
//}


void CMFCApplication1Dlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	CString s,t;
	GetDlgItem(IDC_EDIT2)->GetWindowText(s);
	UINT8 i = _ttoi(s);
	
	if (--i==0)
	{
		MessageBox(_T("份数最小为1"));
		i = 1;
	}
	t.Format(_T("%d"), i);
	GetDlgItem(IDC_EDIT2)->SetWindowText(t);
}


void CMFCApplication1Dlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	CString s, t;
	GetDlgItem(IDC_EDIT2)->GetWindowText(s);
	UINT8 i = _ttoi(s);

	if (++i == 21)
	{
		MessageBox(_T("份数最大为20"));
		i = 20;
	}
	t.Format(_T("%d"), i);
	GetDlgItem(IDC_EDIT2)->SetWindowText(t);
}


void CMFCApplication1Dlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	CString s, t;
	GetDlgItem(IDC_EDIT1)->GetWindowText(s);
	INT16 i = _ttoi(s);
	i -= 10;
	if (i <= 0)
	{
		MessageBox(_T("时间最小为0"));
		i = 0;
	}
	t.Format(_T("%d"), i);
	GetDlgItem(IDC_EDIT1)->SetWindowText(t);
}


void CMFCApplication1Dlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	CString s, t;
	GetDlgItem(IDC_EDIT1)->GetWindowText(s);
	INT16 i = _ttoi(s);
	i += 10;
	if (i >= 600)
	{
		MessageBox(_T("煮面时间太长"));
		
	}
	t.Format(_T("%d"), i);
	GetDlgItem(IDC_EDIT1)->SetWindowText(t);
}


void CMFCApplication1Dlg::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	CString s, t;
	GetDlgItem(IDC_COMBO2)->GetWindowText(s);
	INT16 i = _ttoi(s);
	i -= 1;
	if (i == 0)
	{
		MessageBox(_T("主料号最小为1"));
		i = 1;
	}
	t.Format(_T("%d"), i);
	GetDlgItem(IDC_COMBO2)->SetWindowText(t);
}


void CMFCApplication1Dlg::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码
	CString s, t;
	GetDlgItem(IDC_COMBO2)->GetWindowText(s);
	INT16 i = _ttoi(s);
	i += 1;
	if (i == 5)
	{
		MessageBox(_T("主料号最大为4"));
		i = 4;
	}
	t.Format(_T("%d"), i);
	GetDlgItem(IDC_COMBO2)->SetWindowText(t);
}


BOOL CMFCApplication1Dlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	if (pMsg->message == WM_KEYDOWN)
	{
		switch (pMsg->wParam)
		{
		case VK_RETURN:
			//MessageBox(_T("回车键按下"));
			return TRUE;
		case VK_ESCAPE:
			//MessageBox(_T("ESC键按下"));
			return TRUE;
		default:
			break;
		}
	}

	return CDialogEx::PreTranslateMessage(pMsg);
}
UINT __cdecl CMFCApplication1Dlg::ThreadFun(LPVOID pParam)
{
	CMFCApplication1Dlg *dlg = (CMFCApplication1Dlg *)pParam;
	while (true)
	{
		Sleep(10);
		dlg->UseFun();//类中要调用的函数
	}
}

void CMFCApplication1Dlg::UseFun()
{
	//ADD YOUR CODE
	//下单函数
	if (Send_Flag&State_Comm)
	{
		SYSTEMTIME st;

		CString  strTime;
		static CString SHOW_TEXT;
		DWORD wCount = 0;
		CString r, s, t;
		GetDlgItem(IDC_EDIT2)->GetWindowText(r);
		GetDlgItem(IDC_EDIT1)->GetWindowText(s);
		GetDlgItem(IDC_COMBO2)->GetWindowText(t);
		unsigned char p[30] = { 0xFF,0x10,0x9C,0x41,0x00,0x09,0x00,0x00,0x01,0x01,
								0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
								0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00 };
		p[6] = Order_Cont / 65535;
		p[7] = Order_Cont % 65535 / 256;
		p[8] = Order_Cont % 256;
		p[14] = Value_button / 256;
		p[15] = Value_button % 256;
		p[16] = _ttoi(s) / 256;
		p[17] = _ttoi(s) % 256;
		p[20] = _ttoi(t) / 256;
		p[21] = _ttoi(t) % 256;
		p[24] = checkCRC_16->Check_CRC_16(p, 24) / 256;
		p[25] = checkCRC_16->Check_CRC_16(p, 24) % 256;
		if (State_Comm)
		{
			for (size_t i = 1; i <= _ttoi(r); i++)
			{
				p[9] = i;
				WriteFile(hCom, p, 26, &wCount, NULL);
				Sleep(1000);
			}
			Send_Flag = 0;
			Order_Cont++;
			if (Order_Cont > 999)
			{
				Order_Cont = 0;
			}
			GetLocalTime(&st);

			strTime.Format(_T("%2d时%2d分%2d秒 : %2d份面\r\n"), st.wHour, st.wMinute, st.wSecond, _ttoi(r));
			SHOW_TEXT += strTime;
			GetDlgItem(IDC_EDIT3)->SetWindowText(SHOW_TEXT);
		}
		else
		{
			MessageBox(_T("串口未打开!"));
		}
	}
	//点餐机点单函数
	if (Order_Flag&State_Comm)
	{
		SYSTEMTIME st;
		UINT32 COMMAND_NUMBER = 0;
		static UINT32 COMMAND_LAGE_NUMBER = 1;
		CString  strTime;
		static CString SHOW_TEXT;
		DWORD wCount = 0;
		UINT8 cont = 6;
		CString r, s, t;
		GetDlgItem(IDC_EDIT2)->GetWindowText(r);
		GetDlgItem(IDC_EDIT1)->GetWindowText(s);
		GetDlgItem(IDC_COMBO2)->GetWindowText(t);
		unsigned char p[100];
		p[0] = 0x5a;
		p[1] = 0xa5;
		p[2] = 0x01;
		p[3] = 0x01;
		p[4] = (_ttoi(r)*10) / 256;
		p[5] = (_ttoi(r)*10) % 256;
		COMMAND_NUMBER = COMMAND_LAGE_NUMBER++ * 100;
		for (UINT16 i = 1; i <= _ttoi(r); i++)
		{
			
			p[cont++] = ((COMMAND_NUMBER  + i)>>18 )&0XFF;
			p[cont++] = ((COMMAND_NUMBER  + i) >>16)&0XFF;
			p[cont++] = ((COMMAND_NUMBER + i)>>8 )&0XFF;
			p[cont++] = ((COMMAND_NUMBER + i) )%256;
			p[cont++] = _ttoi(s) / 256;
			p[cont++] = _ttoi(s) % 256;
			p[cont++] = Value_button;
			p[cont++] = 2;//主料号
			p[cont++] = 0x01;
			p[cont++] = 0x1e;
		}
		p[cont++] = checkCRC_16->Check_CRC_16(p, cont-1) / 256;
		p[cont++] = checkCRC_16->Check_CRC_16(p, cont-2) % 256;
		if (State_Comm)
		{
			
				WriteFile(hCom, p, cont, &wCount, NULL);
				Order_Flag = 0;
				
		}
		else
		{
			MessageBox(_T("串口未打开!"));
		}
	}
		
	
}


void CMFCApplication1Dlg::OnBnClickedButton9()
{
	// TODO: 在此添加控件通知处理程序代码
	if (State_Comm)
	{
		Order_Flag = 1;		
	}
	else
	{
		MessageBox(_T("串口未打开！"));
	}
}
