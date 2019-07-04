
// MFCApplication1Dlg.h: 头文件
//

#pragma once


// CMFCApplication1Dlg 对话框
class CMFCApplication1Dlg : public CDialogEx
{
// 构造
public:
	CMFCApplication1Dlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCbnDropdownCombo1();
	CComboBox m_comboCom;
	void CMFCApplication1Dlg::FindCommPort(CComboBox *pComboBox);
	afx_msg void OnBnClickedButton1();
	
	int Cont_noodle;
	int Time_noodle;
	UINT16 Order_Cont = 1;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton2();
	CComboBox Combox_Object;
	afx_msg void OnBnClickedRadio1();
	bool Flag_Radio = TRUE;
	bool State_Comm = FALSE;
	CButton Radio_button;
	UINT8 Value_button = 0;
	//BOOL v_radio;
//	afx_msg void OnBnHotItemChangeRadio1(NMHDR *pNMHDR, LRESULT *pResult);
	//CButton Radio2;
	//afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	static UINT __cdecl ThreadFun(LPVOID pParam);//传入线程函数
	void UseFun();//实现功能函数
	bool Send_Flag = 0;
	bool Order_Flag = 0;
	afx_msg void OnBnClickedButton9();
};
