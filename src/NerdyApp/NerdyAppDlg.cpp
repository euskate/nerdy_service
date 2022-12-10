
// NerdyAppDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "NerdyApp.h"
#include "NerdyAppDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
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


// CNerdyAppDlg 대화 상자



CNerdyAppDlg::CNerdyAppDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_NERDYAPP_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CNerdyAppDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CNerdyAppDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
	ON_WM_CREATE()
END_MESSAGE_MAP()


// CNerdyAppDlg 메시지 처리기

BOOL CNerdyAppDlg::OnInitDialog()
{
	m_bitDraw.LoadBitmap(IDB_INTRO2_BACK);
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	MoveWindow(0, 0, RESOLUTION_WIDTH, RESOLUTION_HEIGHT);
	CenterWindow();

	initScreen();

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CNerdyAppDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CNerdyAppDlg::OnPaint()
{
	//if (IsIconic())
	//{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

	//	SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

	//	// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
	//	int cxIcon = GetSystemMetrics(SM_CXICON);
	//	int cyIcon = GetSystemMetrics(SM_CYICON);
	//	CRect rect;
	//	GetClientRect(&rect);
	//	int x = (rect.Width() - cxIcon + 1) / 2;
	//	int y = (rect.Height() - cyIcon + 1) / 2;

	//	// 아이콘을 그립니다.
	//	dc.DrawIcon(x, y, m_hIcon);

		DrawScreen(&dc);
	//}
	//else
	//{
	//	CDialogEx::OnPaint();
	//}

	
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CNerdyAppDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



BOOL CNerdyAppDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (pMsg->message == WM_KEYDOWN)
	{
		if (pMsg->wParam == VK_RETURN || pMsg->wParam == VK_ESCAPE)
			return TRUE;
	}

	//if (pMsg->message == WM_SYSKEYDOWN && pMsg->wParam == VK_F4)
	//{
	//	return TRUE;
	//}
	return CDialogEx::PreTranslateMessage(pMsg);
}


void CNerdyAppDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	//SendMessage(WM_NCLBUTTONDOWN, HTCAPTION, 0);
	CDialogEx::OnLButtonDown(nFlags, point);
}

void CNerdyAppDlg::DrawScreen(CDC* pDC)
{
	RECT rect;
	GetClientRect(&rect);

	CDC mdcOffScreen;           // 더블버퍼링을 위한 메모리 그림 버퍼이다.

	CDC memDC;
	CBitmap* oldbitmap;
	CBitmap bmpOffScreen;

	mdcOffScreen.CreateCompatibleDC(pDC);				// pDC와 그림 영역을 연결한다.
	bmpOffScreen.CreateCompatibleBitmap(pDC, RESOLUTION_WIDTH, RESOLUTION_HEIGHT); // 빈 그림을 공간 800x480의 그림 공간을 만든다. 
	memDC.CreateCompatibleDC(pDC);

	oldbitmap = mdcOffScreen.SelectObject(&bmpOffScreen);
	///////////////////////////////////////////////////////////
	// 지금 부터는 메모리에 이미지를 복사하거나 문자를 쓰거나 기타 이미지 조작을 한다. 
	// 일반 메모리에 조작하는 것이기에 디버깅을 하더라도 결과 윈도우에는 표시되지 않는다.
	// 이제 2번째 그림 버퍼을 이용하여 전체 버퍼에 복사 한다. 아직 화면에는 표시되지 않는다.
	// 배경그림
	memDC.SelectObject(&m_bitDraw);  // 배경 그림을 선택 한다.
	mdcOffScreen.BitBlt(0, 0, RESOLUTION_WIDTH, RESOLUTION_HEIGHT, &memDC, 0, 0, SRCCOPY); // 그리고 복사

	// 서브 배경 표시 그림
	//memDC.SelectObject(&m_bitDrawSub);
	//mdcOffScreen.BitBlt(75, 136, 749, 310, &memDC, 0, 0, SRCCOPY);

	// 기타 화면 구성에 필요한 요소들을 조작 한다.

	/////////////////////////////////////////////////////////////////
	// 이제 화면에 그리기 한다. 이제서야 화면에 그림이 표시 된다.
	//
	pDC->BitBlt(0, 0, RESOLUTION_WIDTH, RESOLUTION_HEIGHT, &mdcOffScreen, 0, 0, SRCCOPY);

	// 그림 완료 되었으므로, 각가의 요소들을 제거 한다.
	// 이제 사용한 버퍼와 object을 제거 한다.
	mdcOffScreen.SelectObject(oldbitmap);
	bmpOffScreen.DeleteObject();

	memDC.DeleteDC();
	mdcOffScreen.DeleteDC();

	ReleaseDC(&memDC);
	ReleaseDC(&mdcOffScreen);

}

void CNerdyAppDlg::initScreen(void)
{
	int		w_ii = 0;
	int		w_X, w_Y, w_W, w_H;
	CRect	w_ButtonRc, w_cliRect;
	CString w_title = _T("");

	w_X = 183;
	w_Y = 512;
	w_W = 119;
	w_H = 38;
	w_ButtonRc = CRect(w_X, w_Y, w_X + w_W, w_Y + w_H);
	if (!m_btnNext.GetSafeHwnd()) {
		m_btnNext.Create(NULL, WS_VISIBLE | WS_TABSTOP, w_ButtonRc, this, MAIN_NEXT_BTN);
		m_btnNext.SetSkin(IDB_BTN_NEXT_NORM, IDB_BTN_NEXT_DOWN, IDB_BTN_NEXT_NORM, 0, 0, 0, 0, 0, 0);
		m_btnNext.MoveWindow(&w_ButtonRc);
	}

	w_X = 56;
	w_Y = 512;
	w_W = 119;
	w_H = 38;
	w_ButtonRc = CRect(w_X, w_Y, w_X + w_W, w_Y + w_H);
	if (!m_btnSkeep.GetSafeHwnd()) {
		m_btnSkeep.Create(NULL, WS_VISIBLE | WS_TABSTOP, w_ButtonRc, this, MAIN_SKEEP_BTN);
		m_btnSkeep.SetSkin(IDB_BTN_SKEEP_NORM, IDB_BTN_SKEEP_DOWN, IDB_BTN_SKEEP_NORM, 0, 0, 0, 0, 0, 0);
		m_btnSkeep.MoveWindow(&w_ButtonRc);
	}


}

LRESULT CNerdyAppDlg::DefWindowProc(UINT message, WPARAM wParam, LPARAM lParam)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	switch (message)
	{
		case WM_REDRAWMENU:
			//DisplayDeviceReadData((int)wParam, (int)lParam);
			break;
		case WM_COMMAND:
			switch (LOWORD(wParam))
			{
				case MAIN_NEXT_BTN:
				{
					TRACE(_T("NEXT\n"));
					if (m_SubDlg.GetSafeHwnd())
					{
						m_SubDlg.ShowWindow(TRUE);
					}
				}
				break;
				case MAIN_SKEEP_BTN:
					//m_listDevice.Print();
					break;
			}
			break;
	}
	return CDialogEx::DefWindowProc(message, wParam, lParam);
}

int CNerdyAppDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.

	m_SubDlg.Create(CNerdyMainDlg::IDD, this);
	m_SubDlg.SetDlgCtrlID(IDD_NERDY_MAIN_DIALOG);
	m_SubDlg.ShowWindow(SW_HIDE);

	return 0;
}
