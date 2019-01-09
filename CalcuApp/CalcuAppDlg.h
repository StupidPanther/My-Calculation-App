
// CalcuAppDlg.h: 头文件
//

#pragma once


// CCalcuAppDlg 对话框
class CCalcuAppDlg : public CDialogEx
{
// 构造
public:
	CCalcuAppDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCUAPP_DIALOG };
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
	afx_msg void OnBnClickedplus16();
	afx_msg void OnBnClickedequal();
	CComboBox ope;
	afx_msg void OnBnClickedb1();
	afx_msg void OnBnClickedb2();
	afx_msg void OnBnClickedb3();
	afx_msg void OnBnClickedb4();
	afx_msg void OnBnClickedb5();
	afx_msg void OnBnClickedb6();
	afx_msg void OnBnClickedb7();
	afx_msg void OnBnClickedb8();
	afx_msg void OnBnClickedb9();
	afx_msg void OnBnClickedb0();
	afx_msg void OnBnClickedpi();
	afx_msg void OnBnClickede();
	afx_msg void OnBnClickedplus();
	afx_msg void OnBnClickedsub();
	afx_msg void OnBnClickedmult();
	afx_msg void OnBnClickeddiv();
	afx_msg void OnBnClickedpoint();
	afx_msg void OnBnClickedans();
};
