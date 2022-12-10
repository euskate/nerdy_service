// CNerdyMainDlg.cpp: 구현 파일
//

#include "pch.h"
#include "NerdyApp.h"
#include "CNerdyMainDlg.h"
#include "afxdialogex.h"


// CNerdyMainDlg 대화 상자

IMPLEMENT_DYNAMIC(CNerdyMainDlg, CDialog)

CNerdyMainDlg::CNerdyMainDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_NERDY_MAIN_DIALOG, pParent)
{

}

CNerdyMainDlg::~CNerdyMainDlg()
{
}

void CNerdyMainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CNerdyMainDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// CNerdyMainDlg 메시지 처리기


LRESULT CNerdyMainDlg::DefWindowProc(UINT message, WPARAM wParam, LPARAM lParam)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	return CDialog::DefWindowProc(message, wParam, lParam);
}


BOOL CNerdyMainDlg::OnInitDialog()
{
	m_bitDraw.LoadBitmap(IDB_MAIN_BACK);
	CDialog::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	MoveWindow(0, 0, RESOLUTION_WIDTH, RESOLUTION_HEIGHT);
	CenterWindow();

	initScreen();
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CNerdyMainDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: 여기에 메시지 처리기 코드를 추가합니다.
					   // 그리기 메시지에 대해서는 CDialogEx::OnPaint()을(를) 호출하지 마십시오.

	DrawScreen(&dc);
}


void CNerdyMainDlg::DrawScreen(CDC* pDC)
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

void CNerdyMainDlg::initScreen(void)
{
	int		w_ii = 0;
	int		w_X, w_Y, w_W, w_H;
	CRect	w_ButtonRc, w_cliRect;
	CString w_title = _T("");

	w_X = 45;
	w_Y = 122;
	w_W = 60;
	w_H = 57;
	w_ButtonRc = CRect(w_X, w_Y, w_X + w_W, w_Y + w_H);
	if (!m_btn01.GetSafeHwnd()) {
		m_btn01.Create(NULL, WS_VISIBLE | WS_TABSTOP, w_ButtonRc, this, SUB_01_BTN);
		m_btn01.SetSkin(IDB_BTN_01_NORM, IDB_BTN_01_DOWN, IDB_BTN_01_NORM, 0, 0, 0, 0, 0, 0);
		m_btn01.MoveWindow(&w_ButtonRc);
	}

	w_X = 115;
	w_Y = 122;
	w_W = 60;
	w_H = 57;
	w_ButtonRc = CRect(w_X, w_Y, w_X + w_W, w_Y + w_H);
	if (!m_btn02.GetSafeHwnd()) {
		m_btn02.Create(NULL, WS_VISIBLE | WS_TABSTOP, w_ButtonRc, this, SUB_02_BTN);
		m_btn02.SetSkin(IDB_BTN_02_NORM, IDB_BTN_02_DOWN, IDB_BTN_02_NORM, 0, 0, 0, 0, 0, 0);
		m_btn02.MoveWindow(&w_ButtonRc);
	}

	w_X = 185;
	w_Y = 122;
	w_W = 60;
	w_H = 57;
	w_ButtonRc = CRect(w_X, w_Y, w_X + w_W, w_Y + w_H);
	if (!m_btn03.GetSafeHwnd()) {
		m_btn03.Create(NULL, WS_VISIBLE | WS_TABSTOP, w_ButtonRc, this, SUB_03_BTN);
		m_btn03.SetSkin(IDB_BTN_03_NORM, IDB_BTN_03_DOWN, IDB_BTN_03_NORM, 0, 0, 0, 0, 0, 0);
		m_btn03.MoveWindow(&w_ButtonRc);
	}

	w_X = 255;
	w_Y = 122;
	w_W = 60;
	w_H = 57;
	w_ButtonRc = CRect(w_X, w_Y, w_X + w_W, w_Y + w_H);
	if (!m_btn04.GetSafeHwnd()) {
		m_btn04.Create(NULL, WS_VISIBLE | WS_TABSTOP, w_ButtonRc, this, SUB_04_BTN);
		m_btn04.SetSkin(IDB_BTN_04_NORM, IDB_BTN_04_DOWN, IDB_BTN_04_NORM, 0, 0, 0, 0, 0, 0);
		m_btn04.MoveWindow(&w_ButtonRc);
	}


}

BOOL CNerdyMainDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	return CDialog::PreTranslateMessage(pMsg);
}


void CNerdyMainDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	//SendMessage(WM_NCLBUTTONDOWN, HTCAPTION, 0);
	CDialog::OnLButtonDown(nFlags, point);
}
