#pragma once

#include "xSkinButton.h"

#define	SUB_01_BTN				10000
#define SUB_02_BTN				SUB_01_BTN+1
#define SUB_03_BTN				SUB_01_BTN+2
#define SUB_04_BTN				SUB_01_BTN+3

// CNerdyMainDlg 대화 상자

class CNerdyMainDlg : public CDialog
{
	DECLARE_DYNAMIC(CNerdyMainDlg)

public:
	CNerdyMainDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CNerdyMainDlg();

	// 대화 상자 데이터입니다.
	enum { IDD = IDD_NERDY_MAIN_DIALOG};

public:
	CBitmap			m_bitDraw;							//main background image

	//버튼
	CxSkinButton	m_btn01;
	CxSkinButton	m_btn02;
	CxSkinButton	m_btn03;
	CxSkinButton	m_btn04;

	void			initScreen(void);
	void			DrawScreen(CDC* pDC);

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_NERDY_MAIN_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
	virtual LRESULT DefWindowProc(UINT message, WPARAM wParam, LPARAM lParam);
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};
