
// NerdyAppDlg.h: 헤더 파일
//

#pragma once

#include "xSkinButton.h"
#include "CNerdyMainDlg.h"

#define	MAIN_NEXT_BTN				10000
#define MAIN_SKEEP_BTN				MAIN_NEXT_BTN+1

// CNerdyAppDlg 대화 상자
class CNerdyAppDlg : public CDialogEx
{
// 생성입니다.
public:
	CNerdyAppDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_NERDYAPP_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.

public:
	CNerdyMainDlg	m_SubDlg;

public:
	CBitmap			m_bitDraw;							//main background image

	//버튼
	CxSkinButton	m_btnNext;
	CxSkinButton	m_btnSkeep;

	void			initScreen(void);
	void			DrawScreen(CDC* pDC);


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	virtual LRESULT DefWindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};
