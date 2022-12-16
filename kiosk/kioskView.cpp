
// kioskView.cpp: CkioskView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "kiosk.h"
#endif

#include "kioskDoc.h"
#include "kioskView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CkioskView

IMPLEMENT_DYNCREATE(CkioskView, CView)

BEGIN_MESSAGE_MAP(CkioskView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEHOVER()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// 민지원 ------------------------------------------------------------------------
#include "CRectMenu.h"
#include "CRectTab.h"
#include "CRectNow.h"
#include "Paymentbox.h"  //김성내
#include <iostream>
#define NOWMAX 8
#define MAIN 1
#define MENU 2
#define PAY 3
CRectMenu *menu[6][12];
CRectTab *tab[6];
CRectNow* now[NOWMAX];
Paymentbox* p_now[NOWMAX]; //김성내
// 민지원 ------------------------------------------------------------------------

CkioskView::CkioskView() noexcept
{	
	// TODO: 여기에 생성 코드를 추가합니다.
	// 민지원 ------------------------------------------------------------------------
	m_nowTab = 0;
	m_total = 0;
	m_numNow = 0;
	m_status = MAIN;

	CString menus[6][12][3] = {
		{
			{L"커피", L"아메리카노", L"2500"},
			{L"커피", L"아이스 바닐라라떼", L"3000"},
			{L"커피", L"아이스 아메리카노", L"2500"},
			{L"커피", L"아이스 카라멜 마끼야또", L"3500"},
			{L"커피", L"아이스 카페라떼", L"3000"},
			{L"커피", L"아이스 카페모카", L"3500"},
			{L"커피", L"아인슈페너", L"3500"},
			{L"커피", L"아포가토", L"4000"},
			{L"커피", L"콜드브루 비엔나", L"4000"},
			{L"커피", L"콜드브루 아메리카노", L"3500"},
			{L"커피", L"화이트 초코모카", L"3500"},
			{L"커피", L"흑당 버블티", L"4500"}
		},
		{
			{L"플랫치노", L"꿀복숭아 플랫치노", L"3500"},
			{L"플랫치노", L"녹차 플랫치노", L"3500"},
			{L"플랫치노", L"딸기요거트 플랫치노", L"4000"},
			{L"플랫치노", L"망고 플랫치노", L"3500"},
			{L"플랫치노", L"모카 플랫치노", L"3500"},
			{L"플랫치노", L"민트초코 플랫치노", L"4500"},
			{L"플랫치노", L"블루베리 플랫치노", L"4000"},
			{L"플랫치노", L"자몽 플랫치노", L"3500"},
			{L"플랫치노", L"초콜릿칩 플랫치노", L"4500"},
			{L"플랫치노", L"카라멜 플랫치노", L"4000"},
			{L"플랫치노", L"커피 플랫치노", L"4000"},
			{L"플랫치노", L"플레인 요거트 플랫치노", L"3500"}
		},
		{
			{L"블렌딩 티", L"그린루이보스", L"3500"},
			{L"블렌딩 티", L"레몬차", L"3500"},
			{L"블렌딩 티", L"밀크티", L"3500"},
			{L"블렌딩 티", L"복숭아 아이스티", L"2500"},
			{L"블렌딩 티", L"샤인 히비스커스", L"4000"},
			{L"블렌딩 티", L"아이스 석류", L"3500"},
			{L"블렌딩 티", L"유자차", L"3500"},
			{L"블렌딩 티", L"자몽 오렌지", L"3500"},
			{L"블렌딩 티", L"캐모마일", L"3500"},
			{L"블렌딩 티", L"페퍼민트", L"3500"},
			{L"블렌딩 티", L"프레시 그린티", L"3500"},
			{L"블렌딩 티", L"피치얼그레이", L"3500"}
		},
		{
			{L"쉐이크 에이드", L"딸기쉐이크", L"4000"},
			{L"쉐이크 에이드", L"레몬에이드 L", L"4000"},
			{L"쉐이크 에이드", L"레몬에이드 S", L"3500"},
			{L"쉐이크 에이드", L"오리진 쉐이크", L"3500"},
			{L"쉐이크 에이드", L"자몽에이드 L", L"4000"},
			{L"쉐이크 에이드", L"자몽에이드 S", L"3500"},
			{L"쉐이크 에이드", L"청포도에이드 L", L"4500"},
			{L"쉐이크 에이드", L"청포도에이드 S", L"4000"},
			{L"쉐이크 에이드", L"초코쿠키 쉐이크", L"4500"},
			{L"쉐이크 에이드", L"a", L"0"},
			{L"쉐이크 에이드", L"a", L"0"},
			{L"쉐이크 에이드", L"a", L"0"}
		},
		{
			{L"음료", L"골드키위주스", L"4000"},
			{L"음료", L"녹차라떼", L"4000"},
			{L"음료", L"달고나라떼", L"4500"},
			{L"음료", L"딸기주스", L"4000"},
			{L"음료", L"버블크림 밀크티", L"4000"},
			{L"음료", L"생강차", L"3500"},
			{L"음료", L"쌍화차", L"3500"},
			{L"음료", L"연유 카페라떼", L"4000"},
			{L"음료", L"이곡라떼", L"4000"},
			{L"음료", L"초콜릿", L"4000"},
			{L"음료", L"화이트 초콜릿", L"4000"},
			{L"음료", L"흑당라떼", L"4500"}
		},
		{
			{L"디저트", L"딸기 마카롱", L"3000"},
			{L"디저트", L"바닐라 마카롱", L"3000"},
			{L"디저트", L"블루베리 머핀", L"3000"},
			{L"디저트", L"초코 마카롱", L"3000"},
			{L"디저트", L"초코 티라미수", L"4000"},
			{L"디저트", L"초코칩 머핀", L"3000"},
			{L"디저트", L"초콜릿 케이크", L"4000"},
			{L"디저트", L"초콜릿쿠키", L"2500"},
			{L"디저트", L"치즈 케이크", L"4000"},
			{L"디저트", L"크로플", L"3000"},
			{L"디저트", L"크루아상", L"3000"},
			{L"디저트", L"허니 브레드", L"4500"}
		}
	};
	LPCTSTR tabs[6] = {
		L"커피", L"플랫치노", L"블렌딩 티", L"쉐이크, 에이드", L"음료", L"디저트"
	};

	for (int i = 0; i < 6; i++) {

		tab[i] = new CRectTab(CPoint(i * 245, 0), 245, 100, tabs[i]);

		for (int j = 0; j < 12; j++) {
			menu[i][j] = new CRectMenu(CPoint(20 + ((j % 4) * 360), 150 + ((j / 4) * 260)), 352, 252, menus[i][j][0], menus[i][j][1], menus[i][j][2]);
		}
	}
	// 민지원 ------------------------------------------------------------------------
}

CkioskView::~CkioskView()
{
}

BOOL CkioskView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CkioskView 그리기

void CkioskView::OnDraw(CDC* pDC)
{

	CkioskDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	// 민지원 ------------------------------------------------------------------------
	CBrush brush(RGB(255, 255, 255));
	pDC->SelectObject(&brush);

	if (m_status == MAIN) {
		CImage background;
		background.Load(L"res/background.png");
		background.Draw(*pDC, 0, 0, 1920, 950);
	}
	else{
		CPen pen2;
		pen2.CreatePen(PS_SOLID, 4, RGB(146, 216, 240));
		pDC->SelectObject(&pen2);

		pDC->MoveTo(0, 100);
		pDC->LineTo(1470, 100);

		pDC->MoveTo(1470, 0);
		pDC->LineTo(1470, 950);

		CRect nowBox(1480, 10, 1910, 800);
		pDC->Rectangle(nowBox);

		CFont font;
		font.CreatePointFont(400, _T("맑은고딕"));
		pDC->SelectObject(&font);

		CRect payBox(1480, 810, 1910, 940);
		pDC->Rectangle(payBox);
		pDC->DrawText(L"결     제", payBox, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

		CPen pen1;
		pen1.CreatePen(PS_SOLID, 2, RGB(146, 216, 240));
		pDC->SelectObject(&pen1);

		for (int i = 0; i < 6; i++) {

			if (m_nowTab != i) {
				CPen* oldPen = pDC->SelectObject(&pen2);
				tab[i]->draw(pDC);
				pDC->SelectObject(oldPen);
			}
			CPen pen3(PS_SOLID, 7, RGB(57, 117, 135));
			CPen* oldPen = pDC->SelectObject(&pen3);
			tab[m_nowTab]->draw(pDC);
			pDC->SelectObject(oldPen);
		}

		pDC->SelectObject(&pen1);

		m_total = 0;
		for (int i = 0; i < m_numNow; i++) {
			now[i]->draw(pDC);
			m_total += _ttoi(now[i]->menu->price) * now[i]->count; // 김현준, 민지원
		}

		CFont font2;
		font2.CreatePointFont(300, _T("맑은고딕"));
		pDC->SelectObject(&font2);

		CRect totalBox(1490, 700, 1900, 790);
		pDC->Rectangle(totalBox);
		CString totalStr;
		totalStr.Format(_T("%d 원"), m_total);
		CRect totalBox2(1493, 703, 1897, 787);
		pDC->DrawText(totalStr, totalBox2, DT_RIGHT | DT_VCENTER | DT_SINGLELINE);

		for (int i = 0; i < 12; i++) {
			menu[m_nowTab][i]->draw(pDC);
		}
		// 민지원 ------------------------------------------------------------------------

		// 김성내 ------------------------------------------------------------------------
		CBrush brush1(RGB(146, 216, 240));
		CBrush* oldBrush1 = pDC->SelectObject(&brush1);
		CRect paywindow(200, 50, 1500, 900);

		CPen pen4;
		pen4.CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
		CPen* oldpen4 = pDC->SelectObject(&pen4);
		CRect paywindow_line(200, 50, 1500, 900);

		CRect pay_x(1400, 800, 1500, 900);

		CRect pay_success(1150, 150, 1450, 700);

		if (m_status==PAY)
		{

			pDC->Rectangle(paywindow);
			pDC->SelectObject(paywindow);

			pDC->Rectangle(paywindow_line);
			pDC->SelectObject(paywindow_line);

			CBrush brush2(RGB(255, 255, 255));
			CBrush* oldBrush2 = pDC->SelectObject(&brush2);
			pDC->Rectangle(pay_x);
			pDC->SelectObject(pay_x);
			pDC->DrawText(L"X", pay_x, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			pDC->SetTextColor(RGB(0, 0, 0));
			pDC->SelectObject(pay_success);
			pDC->Rectangle(pay_success);
			pDC->DrawText(L"결제하기", pay_success, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			for (int i = 0; i < m_numNow; i++)
			{
				p_now[i]->draw(pDC);
			}
		}
		// 김성내 ------------------------------------------------------------------------
	}
}

// CkioskView 인쇄

BOOL CkioskView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CkioskView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CkioskView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CkioskView 진단

#ifdef _DEBUG
void CkioskView::AssertValid() const
{
	CView::AssertValid();
}

void CkioskView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CkioskDoc* CkioskView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CkioskDoc)));
	return (CkioskDoc*)m_pDocument;
}
#endif //_DEBUG


// CkioskView 메시지 처리기


void CkioskView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	// 민지원 ------------------------------------------------------------------------
	bool isClicked = false;
	if (m_status == MAIN) {
		m_status = MENU;
		isClicked = true;
	}

	if (m_status == MENU && !isClicked) {  //김성내
		for (int i = 0; i < 6; i++) {
			if (tab[i]->checkClick(point)) {
				m_nowTab = i;
				break;
			}
		}
		for (int i = 0; i < 12; i++) {
			if (menu[m_nowTab][i]->checkClick(point) && (menu[m_nowTab][i]->price != L"0")) {
				bool isInNow = false;
				for (int j = 0; j < m_numNow; j++) {
					if (menu[m_nowTab][i] == now[j]->menu) {
						now[j]->count++;
						p_now[j]->count++;
						isInNow = true;
						break;
					}
				}
				if (isInNow || m_numNow >= NOWMAX) break;
				now[m_numNow] = new CRectNow(CPoint(1490, 20 + 80 * m_numNow), menu[m_nowTab][i]);
				p_now[m_numNow] = new Paymentbox(CPoint(250, 100 * m_numNow + 70), menu[m_nowTab][i]); //김성내
				m_status = MENU;
				isClicked = true;
				m_numNow++;
				break;
			}
		}
		for (int i = 0; i < m_numNow; i++) {
			if (now[i]->checkClick(point)) {
				for (int j = i; j < m_numNow - 1; j++) {
					now[j]->menu = now[j + 1]->menu;
				}
				m_numNow--;
				break;
			}
		}
		// 민지원 ------------------------------------------------------------------------

		// 김현준 ------------------------------------------------------------------------
		for (int i = 0; i < m_numNow; i++) {
			if (now[i]->checkClick2(point)) {
				now[i]->count++;
				p_now[i]->count++; // 민지원
				break;
			}
		}

		for (int i = 0; i < m_numNow; i++) {
			if (now[i]->checkClick3(point) && now[i]->count > 1) {
				now[i]->count--;
				p_now[i]->count--; // 민지원
				break;
			}
		}
	
	// 김현준 -------------------------------------------------------------------------------

	//김성내---------------------------------------------------------------------
		if (point.x > 1480 && point.x < 1910 && point.y > 810 && point.y < 940 && m_total!=0) // 김성내, 민지원
		{
			m_status = PAY;
			isClicked = true; // 민지원
		}
	}
	if (m_status == PAY &&  !isClicked)
	{
		if (point.x > 1400 && point.x < 1500 && point.y > 800 && point.y < 900)
		{
			m_status = MENU;
			isClicked = true; // 민지원
		}
		CString str;
		str.Format(_T("%d원"), m_total);
			if (point.x > 1150 && point.x < 1450 && point.y > 150 && point.y < 700 && MessageBox(str))
			{
				m_numNow = 0;
				m_status = MAIN;
				m_nowTab = 0; // 민지원
				isClicked = true; // 민지원
			}
	}
	//김성내-------------------------------------------------------------------- -
	Invalidate();
	CView::OnLButtonDown(nFlags, point);
}


void CkioskView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	
	// 민지원 ------------------------------------------------------------------------
	if (m_status == MENU) {
		for (int i = 0; i < 12; i++) {
			if (menu[m_nowTab][i]->checkClick(point)) {
				menu[m_nowTab][i]->border = RGB(50, 50, 250);
			}
			else {
				menu[m_nowTab][i]->border = RGB(146, 216, 240);
			}
			Invalidate(false);
		}
	}
	// 민지원 ------------------------------------------------------------------------
	CView::OnMouseMove(nFlags, point);
}