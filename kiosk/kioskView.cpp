
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
END_MESSAGE_MAP()

// CkioskView 생성/소멸
#include "CRectMenu.h"
#include "CRectTab.h"
#include "CRectNow.h"
#include <iostream>
#define NOWMAX 8 // 담을 수 있는 음료 최대 개수
CRectMenu *menu[6][12]; // 메뉴 객체
CRectTab *tab[6]; // 탭 객체 (상단 음료 종류)
CRectNow* now[NOWMAX]; // 현재 담은 음료 객체

CkioskView::CkioskView() noexcept
{	
	// TODO: 여기에 생성 코드를 추가합니다.
	// 맴버변수 초기화
	m_nowTab = 0;
	m_total = 0;
	m_numNow = 0;

	// 음료 정보 배열
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
		// 탭 초기화(객체 생성)
		tab[i] = new CRectTab(CPoint(i * 245, 0), 245, 100, tabs[i]);

		// 메뉴 초기화(객체 생성)
		for (int j = 0; j < 12; j++) {
			menu[i][j] = new CRectMenu(CPoint(20 + ((j % 4) * 360), 150 + ((j / 4) * 260)), 352, 252, menus[i][j][0], menus[i][j][1], menus[i][j][2]);
		}
	}
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
	
	// 굵은 펜
	CPen pen2;
	pen2.CreatePen(PS_SOLID, 4, RGB(146, 216, 240));
	pDC->SelectObject(&pen2);

	// 가로 선
	pDC->MoveTo(0, 100);
	pDC->LineTo(1470, 100);

	// 세로 선
	pDC->MoveTo(1470, 0);
	pDC->LineTo(1470, 950);

	// 현황 박스 (담은 음료 정보가 들어갈 큰 박스)
	CRect nowBox(1480, 10, 1910, 800);
	pDC->Rectangle(nowBox);
	
	// 폰트
	CFont font;
	font.CreatePointFont(400, _T("맑은고딕"));
	pDC->SelectObject(&font);

	// 결제 박스(버튼)
	CRect payBox(1480, 810, 1910, 940);
	pDC->Rectangle(payBox);
	pDC->DrawText(L"결     제", payBox, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	// 얇은 펜
	CPen pen1;
	pen1.CreatePen(PS_SOLID, 2, RGB(146, 216, 240));
	pDC->SelectObject(&pen1);

	// 탭 박스(상단 바 ex.커피, 스무디...)
	for (int i = 0; i < 6; i++) {
		// 선택된 탭을 색칠(구현 중)
		if (m_nowTab == i) {
			CBrush brush1(RGB(146, 216, 240));
			CBrush *oldBrush = pDC->SelectObject(&brush1);
			tab[i]->draw(pDC);
			pDC->SelectObject(oldBrush);
		}
		else {
			// 화면에 탭을 그림
			tab[i]->draw(pDC);
		}
	}

	// 화면에 메뉴를 그림
	for (int i = 0; i < 12; i++) {
		menu[m_nowTab][i]->draw(pDC);
	}
	
	// 현황 (담은 음료)
	m_total = 0;
	for (int i = 0; i < m_numNow; i++) {
		// 화면에 현황을 그림
		now[i]->draw(pDC);

		//총액 계산
		m_total += _ttoi(now[i]->menu->price);
	}

	// 폰트
	CFont font2;
	font2.CreatePointFont(300, _T("맑은고딕"));
	pDC->SelectObject(&font2);

	// 합계 박스
	CRect totalBox(1490, 700, 1900, 790);
	pDC->Rectangle(totalBox);
	CString totalStr;
	totalStr.Format(_T("%d 원"), m_total);
	CRect totalBox2(1493, 703, 1897, 787);
	pDC->DrawText(totalStr, totalBox2, DT_RIGHT | DT_VCENTER | DT_SINGLELINE);
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
	// 탭 클릭 이벤트
	for (int i = 0; i < 6; i++) {
		if (tab[i]->checkClick(point)) {
			m_nowTab = i;
			break;
		}
	}

	// 메뉴 클릭 이벤트(현황 추가)
	for (int i = 0; i < 12; i++) {
		if (menu[m_nowTab][i]->checkClick(point)&&m_numNow<NOWMAX) {
			now[m_numNow] = new CRectNow(CPoint(1490, 20 + 80 * m_numNow), menu[m_nowTab][i]);
			m_numNow++;
			break;
		}
	}

	// 현황 취소 이벤트
	for (int i = 0; i < m_numNow; i++) {
		if (now[i]->checkClick(point)) {
			for (int j = i; j < m_numNow - 1; j++) {
				now[j]->menu = now[j+1]->menu;
			}
			m_numNow--;
			break;
		}
	}
	Invalidate(false);
	CView::OnLButtonDown(nFlags, point);
}
