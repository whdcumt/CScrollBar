
// CScrollBarDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CCScrollBarDlg �Ի���
class CCScrollBarDlg : public CDialogEx
{
// ����
public:
	CCScrollBarDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_CSCROLLBAR_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
