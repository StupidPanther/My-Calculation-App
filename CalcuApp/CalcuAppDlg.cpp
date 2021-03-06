
// CalcuAppDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "CalcuApp.h"
#include "CalcuAppDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

enum CON
{
	ZERO,
	NUM1,
	NUM2,
};
CON signal;

double ans;
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


// CCalcuAppDlg 对话框



CCalcuAppDlg::CCalcuAppDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALCUAPP_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalcuAppDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_ope, ope);
}

BEGIN_MESSAGE_MAP(CCalcuAppDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_equal, &CCalcuAppDlg::OnBnClickedequal)
	ON_BN_CLICKED(IDC_b1, &CCalcuAppDlg::OnBnClickedb1)
	ON_BN_CLICKED(IDC_b2, &CCalcuAppDlg::OnBnClickedb2)
	ON_BN_CLICKED(IDC_b3, &CCalcuAppDlg::OnBnClickedb3)
	ON_BN_CLICKED(IDC_b4, &CCalcuAppDlg::OnBnClickedb4)
	ON_BN_CLICKED(IDC_b5, &CCalcuAppDlg::OnBnClickedb5)
	ON_BN_CLICKED(IDC_b6, &CCalcuAppDlg::OnBnClickedb6)
	ON_BN_CLICKED(IDC_b7, &CCalcuAppDlg::OnBnClickedb7)
	ON_BN_CLICKED(IDC_b8, &CCalcuAppDlg::OnBnClickedb8)
	ON_BN_CLICKED(IDC_b9, &CCalcuAppDlg::OnBnClickedb9)
	ON_BN_CLICKED(IDC_b0, &CCalcuAppDlg::OnBnClickedb0)
	ON_BN_CLICKED(IDC_pi, &CCalcuAppDlg::OnBnClickedpi)
	ON_BN_CLICKED(IDC_e, &CCalcuAppDlg::OnBnClickede)
	ON_BN_CLICKED(IDC_plus, &CCalcuAppDlg::OnBnClickedplus)
	ON_BN_CLICKED(IDC_sub, &CCalcuAppDlg::OnBnClickedsub)
	ON_BN_CLICKED(IDC_mult, &CCalcuAppDlg::OnBnClickedmult)
	ON_BN_CLICKED(IDC_div, &CCalcuAppDlg::OnBnClickeddiv)
	ON_BN_CLICKED(IDC_point, &CCalcuAppDlg::OnBnClickedpoint)
	ON_BN_CLICKED(IDC_ans, &CCalcuAppDlg::OnBnClickedans)
END_MESSAGE_MAP()


// CCalcuAppDlg 消息处理程序

BOOL CCalcuAppDlg::OnInitDialog()
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
	signal = ZERO;
	ope.SetCurSel(4);
	SetDlgItemText(IDC_ope, L"+");

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CCalcuAppDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCalcuAppDlg::OnPaint()
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
HCURSOR CCalcuAppDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCalcuAppDlg::OnBnClickedequal()
{
	// TODO: 在此添加控件通知处理程序代码
	double num1, num2, rst;
	CString strnum1, strnum2, strrst;

	GetDlgItem(IDC_num1)->GetWindowText(strnum1);
	GetDlgItem(IDC_num2)->GetWindowText(strnum2);
	num1 = _wtof(strnum1);
	num2 = _wtof(strnum2);

	int select = ope.GetCurSel();

	switch (select)
	{
	case 0:rst = num1 + num2; ans = rst; break;
	case 1:rst = num1 - num2; ans = rst; break;
	case 2:rst = num1 * num2; ans = rst; break;
	case 3:rst = num1 / num2; ans = rst; break;
	}

	strrst.Format(_T("%lf"), ans);
	SetDlgItemText(IDC_rst, strrst);

	
	CString placeholder;
	switch (select)
	{
	case 0:placeholder = L"+"; break;
	case 1:placeholder = L"-"; break;
	case 2:placeholder = L"*"; break;
	case 3:placeholder = L"/"; break;
	}
	ope.SetCurSel(4);
	SetDlgItemText(IDC_ope, placeholder);
	signal = ZERO;
}


void CCalcuAppDlg::OnBnClickedb1()
{
	// TODO: 在此添加控件通知处理程序代码
	int cursel = ope.GetCurSel();
	int curID;

	switch (cursel)
	{
	case 0:
	case 1:
	case 2:
	case 3:curID = IDC_num2; break;
	case 4:curID = IDC_num1; break;
	}

	if (signal==ZERO)
	{
		GetDlgItem(IDC_num1)->SetWindowText(L"");
		GetDlgItem(IDC_num2)->SetWindowText(L"");
		signal = NUM1;
	}

	CString Temp;
	GetDlgItem(curID)->GetWindowText(Temp);
	Temp += "1";
	GetDlgItem(curID)->SetWindowText(Temp);
}

void CCalcuAppDlg::OnBnClickedb2()
{
	// TODO: 在此添加控件通知处理程序代码
	int cursel = ope.GetCurSel();
	int curID;

	switch (cursel)
	{
	case 0:
	case 1:
	case 2:
	case 3:curID = IDC_num2; break;
	case 4:curID = IDC_num1; break;
	}

	if (signal == ZERO)
	{
		GetDlgItem(IDC_num1)->SetWindowText(L"");
		GetDlgItem(IDC_num2)->SetWindowText(L"");
		signal = NUM1;
	}

	CString Temp;
	GetDlgItem(curID)->GetWindowText(Temp);
	Temp += "2";
	GetDlgItem(curID)->SetWindowText(Temp);
}


void CCalcuAppDlg::OnBnClickedb3()
{
	// TODO: 在此添加控件通知处理程序代码
	int cursel = ope.GetCurSel();
	int curID;

	switch (cursel)
	{
	case 0:
	case 1:
	case 2:
	case 3:curID = IDC_num2; break;
	case 4:curID = IDC_num1; break;
	}

	if (signal == ZERO)
	{
		GetDlgItem(IDC_num1)->SetWindowText(L"");
		GetDlgItem(IDC_num2)->SetWindowText(L"");
		signal = NUM1;
	}

	CString Temp;
	GetDlgItem(curID)->GetWindowText(Temp);
	Temp += "3";
	GetDlgItem(curID)->SetWindowText(Temp);
}


void CCalcuAppDlg::OnBnClickedb4()
{
	// TODO: 在此添加控件通知处理程序代码
	int cursel = ope.GetCurSel();
	int curID;

	switch (cursel)
	{
	case 0:
	case 1:
	case 2:
	case 3:curID = IDC_num2; break;
	case 4:curID = IDC_num1; break;
	}

	if (signal == ZERO)
	{
		GetDlgItem(IDC_num1)->SetWindowText(L"");
		GetDlgItem(IDC_num2)->SetWindowText(L"");
		signal = NUM1;
	}

	CString Temp;
	GetDlgItem(curID)->GetWindowText(Temp);
	Temp += "4";
	GetDlgItem(curID)->SetWindowText(Temp);
}


void CCalcuAppDlg::OnBnClickedb5()
{
	// TODO: 在此添加控件通知处理程序代码
	int cursel = ope.GetCurSel();
	int curID;

	switch (cursel)
	{
	case 0:
	case 1:
	case 2:
	case 3:curID = IDC_num2; break;
	case 4:curID = IDC_num1; break;
	}

	if (signal == ZERO)
	{
		GetDlgItem(IDC_num1)->SetWindowText(L"");
		GetDlgItem(IDC_num2)->SetWindowText(L"");
		signal = NUM1;
	}

	CString Temp;
	GetDlgItem(curID)->GetWindowText(Temp);
	Temp += "5";
	GetDlgItem(curID)->SetWindowText(Temp);
}


void CCalcuAppDlg::OnBnClickedb6()
{
	// TODO: 在此添加控件通知处理程序代码
	int cursel = ope.GetCurSel();
	int curID;

	switch (cursel)
	{
	case 0:
	case 1:
	case 2:
	case 3:curID = IDC_num2; break;
	case 4:curID = IDC_num1; break;
	}

	if (signal == ZERO)
	{
		GetDlgItem(IDC_num1)->SetWindowText(L"");
		GetDlgItem(IDC_num2)->SetWindowText(L"");
		signal = NUM1;
	}

	CString Temp;
	GetDlgItem(curID)->GetWindowText(Temp);
	Temp += "6";
	GetDlgItem(curID)->SetWindowText(Temp);
}


void CCalcuAppDlg::OnBnClickedb7()
{
	// TODO: 在此添加控件通知处理程序代码
	int cursel = ope.GetCurSel();
	int curID;

	switch (cursel)
	{
	case 0:
	case 1:
	case 2:
	case 3:curID = IDC_num2; break;
	case 4:curID = IDC_num1; break;
	}

	if (signal == ZERO)
	{
		GetDlgItem(IDC_num1)->SetWindowText(L"");
		GetDlgItem(IDC_num2)->SetWindowText(L"");
		signal = NUM1;
	}

	CString Temp;
	GetDlgItem(curID)->GetWindowText(Temp);
	Temp += "7";
	GetDlgItem(curID)->SetWindowText(Temp);
}


void CCalcuAppDlg::OnBnClickedb8()
{
	// TODO: 在此添加控件通知处理程序代码
	int cursel = ope.GetCurSel();
	int curID;

	switch (cursel)
	{
	case 0:
	case 1:
	case 2:
	case 3:curID = IDC_num2; break;
	case 4:curID = IDC_num1; break;
	}

	if (signal == ZERO)
	{
		GetDlgItem(IDC_num1)->SetWindowText(L"");
		GetDlgItem(IDC_num2)->SetWindowText(L"");
		signal = NUM1;
	}

	CString Temp;
	GetDlgItem(curID)->GetWindowText(Temp);
	Temp += "8";
	GetDlgItem(curID)->SetWindowText(Temp);
}


void CCalcuAppDlg::OnBnClickedb9()
{
	// TODO: 在此添加控件通知处理程序代码
	int cursel = ope.GetCurSel();
	int curID;

	switch (cursel)
	{
	case 0:
	case 1:
	case 2:
	case 3:curID = IDC_num2; break;
	case 4:curID = IDC_num1; break;
	}

	if (signal == ZERO)
	{
		GetDlgItem(IDC_num1)->SetWindowText(L"");
		GetDlgItem(IDC_num2)->SetWindowText(L"");
		signal = NUM1;
	}

	CString Temp;
	GetDlgItem(curID)->GetWindowText(Temp);
	Temp += "9";
	GetDlgItem(curID)->SetWindowText(Temp);
}


void CCalcuAppDlg::OnBnClickedb0()
{
	// TODO: 在此添加控件通知处理程序代码
	int cursel = ope.GetCurSel();
	int curID;

	switch (cursel)
	{
	case 0:
	case 1:
	case 2:
	case 3:curID = IDC_num2; break;
	case 4:curID = IDC_num1; break;
	}

	if (signal == ZERO)
	{
		GetDlgItem(IDC_num1)->SetWindowText(L"");
		GetDlgItem(IDC_num2)->SetWindowText(L"");
		signal = NUM1;
	}

	CString Temp;
	GetDlgItem(curID)->GetWindowText(Temp);
	Temp += "0";
	GetDlgItem(curID)->SetWindowText(Temp);
}


void CCalcuAppDlg::OnBnClickedpi()
{
	// TODO: 在此添加控件通知处理程序代码
	if (signal == ZERO)
	{
		GetDlgItem(IDC_num1)->SetWindowText(L"");
		GetDlgItem(IDC_num2)->SetWindowText(L"");
		signal = NUM1;
	}

	int cursel = ope.GetCurSel();
	int curID;
	if (cursel == 4)
		curID = IDC_num1;
	else
		curID = IDC_num2;

	GetDlgItem(curID)->SetWindowText(L"3.141593");
}


void CCalcuAppDlg::OnBnClickede()
{
	// TODO: 在此添加控件通知处理程序代码
	if (signal == ZERO)
	{
		GetDlgItem(IDC_num1)->SetWindowText(L"");
		GetDlgItem(IDC_num2)->SetWindowText(L"");
		signal = NUM1;
	}

	int cursel = ope.GetCurSel();
	int curID;
	if (cursel == 4)
		curID = IDC_num1;
	else
		curID = IDC_num2;

	GetDlgItem(curID)->SetWindowText(L"2.718282");
}


void CCalcuAppDlg::OnBnClickedplus()
{
	// TODO: 在此添加控件通知处理程序代码
	ope.SetCurSel(0);

	if (signal == ZERO)
	{
		CString Temp;
		Temp.Format(_T("%lf"), ans);
		GetDlgItem(IDC_num1)->SetWindowText(Temp);
		GetDlgItem(IDC_num2)->SetWindowText(L"");
	}
	signal = NUM2;
}


void CCalcuAppDlg::OnBnClickedsub()
{
	// TODO: 在此添加控件通知处理程序代码
	ope.SetCurSel(1);

	if (signal == ZERO)
	{
		CString Temp;
		Temp.Format(_T("%lf"), ans);
		GetDlgItem(IDC_num1)->SetWindowText(Temp);
		GetDlgItem(IDC_num2)->SetWindowText(L"");
	}
	signal = NUM2;
}


void CCalcuAppDlg::OnBnClickedmult()
{
	// TODO: 在此添加控件通知处理程序代码
	ope.SetCurSel(2);

	if (signal == ZERO)
	{
		CString Temp;
		Temp.Format(_T("%lf"), ans);
		GetDlgItem(IDC_num1)->SetWindowText(Temp);
		GetDlgItem(IDC_num2)->SetWindowText(L"");
	}
	signal = NUM2;
}


void CCalcuAppDlg::OnBnClickeddiv()
{
	// TODO: 在此添加控件通知处理程序代码
	ope.SetCurSel(3);

	if (signal == ZERO)
	{
		CString Temp;
		Temp.Format(_T("%lf"), ans);
		GetDlgItem(IDC_num1)->SetWindowText(Temp);
		GetDlgItem(IDC_num2)->SetWindowText(L"");
	}
	signal = NUM2;
}


void CCalcuAppDlg::OnBnClickedpoint()
{
	// TODO: 在此添加控件通知处理程序代码
	int cursel = ope.GetCurSel();
	int curID;

	switch (cursel)
	{
	case 0:
	case 1:
	case 2:
	case 3:curID = IDC_num2; break;
	case 4:curID = IDC_num1; break;
	}

	if (signal == ZERO)
	{
		GetDlgItem(IDC_num1)->SetWindowText(L"");
		GetDlgItem(IDC_num2)->SetWindowText(L"");
		signal = NUM1;
	}

	CString Temp;
	GetDlgItem(curID)->GetWindowText(Temp);
	Temp += ".";
	GetDlgItem(curID)->SetWindowText(Temp);
}


void CCalcuAppDlg::OnBnClickedans()
{
	// TODO: 在此添加控件通知处理程序代码
	if (signal == ZERO)
	{
		GetDlgItem(IDC_num1)->SetWindowText(L"");
		GetDlgItem(IDC_num2)->SetWindowText(L"");
	}

	int cursel = ope.GetCurSel();
	int curID;
	if (cursel == 4)
		curID = IDC_num1;
	else
		curID = IDC_num2;

	CString Temp;
	Temp.Format(_T("%lf"), ans);
	GetDlgItem(curID)->SetWindowText(Temp);
}
