
// kioskView.h: CkioskView 클래스의 인터페이스
//

#pragma once


class CkioskView : public CView
{
protected: // serialization에서만 만들어집니다.
	CkioskView() noexcept;
	DECLARE_DYNCREATE(CkioskView)

// 특성입니다.
public:
	CkioskDoc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CkioskView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	// 민지원 ------------------------------------------------------------------------
	int m_nowTab;
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	int m_total;
	int m_numNow;
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	int m_status;
	// 민지원 ------------------------------------------------------------------------
};

#ifndef _DEBUG  // kioskView.cpp의 디버그 버전
inline CkioskDoc* CkioskView::GetDocument() const
   { return reinterpret_cast<CkioskDoc*>(m_pDocument); }
#endif

