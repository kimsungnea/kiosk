#pragma once
#include "CRectMenu.h"
class CRectNow
{
public:
	CRectMenu* menu; // 추가한 메뉴 객체(포인터)
	CPoint pos; // 추가한 메뉴를 표시할 위치(좌상단)
	int width; // 현황표시박스 너비
	int height; // 현황표시박스 높이

public:
	CRectNow::CRectNow();
	CRectNow::CRectNow(CPoint p, CRectMenu* m);	// 생성자
	void CRectNow::draw(CDC* pDC); // 화면에 그리는 함수
	bool CRectNow::checkClick(CPoint p); // 클릭판단 함수
};

