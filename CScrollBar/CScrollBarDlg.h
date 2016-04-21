
// CScrollBarDlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// CCScrollBarDlg 对话框
class CCScrollBarDlg : public CDialogEx
{
// 构造
public:
	CCScrollBarDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_CSCROLLBAR_DIALOG };

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
	afx_msg void OnNMThemeChangedHoriScrollbar(NMHDR *pNMHDR, LRESULT *pResult);
	CScrollBar m_horiScrollbar;
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
};
