#pragma once
class CRectTab
{
public:
	CPoint pos; // 탭 위치(좌상단)
	int width; // 탭 너비
	int height; // 탭 높이
	LPCTSTR name; // 탭 이름(음료 종류 ex.커피, 티...)

public:
	CRectTab::CRectTab(); 
	CRectTab::CRectTab(CPoint p, int w, int h, LPCTSTR n); // 생성자
	void CRectTab::draw(CDC* pDC); // 화면에 그리는 함수
	bool CRectTab::checkClick(CPoint p); // 클릭판단 함수
};

