
// CScrollBarDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CScrollBar.h"
#include "CScrollBarDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CCScrollBarDlg �Ի���




CCScrollBarDlg::CCScrollBarDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CCScrollBarDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCScrollBarDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_HORI_SCROLLBAR, m_horiScrollbar);
}

BEGIN_MESSAGE_MAP(CCScrollBarDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(NM_THEMECHANGED, IDC_HORI_SCROLLBAR, &CCScrollBarDlg::OnNMThemeChangedHoriScrollbar)
	ON_WM_HSCROLL()
END_MESSAGE_MAP()


// CCScrollBarDlg ��Ϣ�������

BOOL CCScrollBarDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	//����ˮƽ�������Ĺ�����ΧΪ1��100
	m_horiScrollbar.SetScrollRange(1,100);
	//����ˮƽ�������ĳ�ʼλ��Ϊ20
	m_horiScrollbar.SetScrollPos(20);
	//�ڱ༭������ʾ20
	SetDlgItemInt(IDC_HSCROLL_EDIT,20);
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CCScrollBarDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CCScrollBarDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CCScrollBarDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCScrollBarDlg::OnNMThemeChangedHoriScrollbar(NMHDR *pNMHDR, LRESULT *pResult)
{
	// �ù���Ҫ��ʹ�� Windows XP ����߰汾��
	// ���� _WIN32_WINNT ���� >= 0x0501��
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
}


void CCScrollBarDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	//��ȡˮƽ�������ĵ�ǰλ��
	int pos=m_horiScrollbar.GetScrollPos();
	switch(nSBCode)
	{
		//����������һ�У���pos��1
	    case SB_LINEUP:
		pos-=1;
		break;
		//������ҹ���һ�У���pos��1
	    case SB_LINEDOWN:
		pos+=1;
		break;
		//���ҹ���һҳ����pos��10
	    case SB_PAGEUP:
		pos-=10;
		break;
	    //�������һҳ����pos��10
	    case SB_PAGEDOWN:
	    pos+=10;
		break;
		//�������posΪ1
		case SB_TOP:
			pos=1;
			break;
	     //���Ҷ���posΪ100
		case SB_BOTTOM:
			pos=100;
			break;
         //����϶���ָ����λ�ã���pos��ֵΪnPos��ֵ
		case SB_THUMBPOSITION:
			pos=nPos;
			break;
        //�����m_horiScrollbar.SetScrollPos(pos);ִ��ʱ��ڶ��ν���˺�����
	   //����ȷ���������λ�ã����һ�ֱ�ӵ�default��֧�������ڴ˴����ñ༭��
	   //����ʾ��ֵ
		default:
			SetDlgItemInt(IDC_HSCROLL_EDIT,pos);
			return;

	}
	//���û�����λ��
	m_horiScrollbar.SetScrollPos(pos);
	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}
