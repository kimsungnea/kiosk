#pragma once
class CRectMenu
{
public:
	CPoint pos; // 메뉴 위치(좌상단)
	int width; // 메뉴 너비
	int height; // 메뉴 높이
	CString kind; // 메뉴 종류(ex. 커피, 티, 스무디...)
	CString name; // 메뉴 이름
	CString price; // 메뉴 가격

public:
	CRectMenu::CRectMenu();
	CRectMenu::CRectMenu(CPoint p, int w, int h, CString k, CString  n, CString pr); // 생성자
	void CRectMenu::draw(CDC* pDC); // 화면에 그리는 함수
	bool CRectMenu::checkClick(CPoint p); // 클릭판단 함수
};

