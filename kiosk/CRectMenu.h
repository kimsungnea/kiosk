#pragma once
// ¹ÎÁö¿ø ------------------------------------------------------------------------
class CRectMenu
{
public:
	CPoint pos;
	int width;
	int height;
	CString kind;
	CString name;
	CString price;
	COLORREF border;
public:
	CRectMenu::CRectMenu();
	CRectMenu::CRectMenu(CPoint p, int w, int h, CString k, CString  n, CString pr); 
	void CRectMenu::draw(CDC* pDC); 
	bool CRectMenu::checkClick(CPoint p); 
};
// ¹ÎÁö¿ø ------------------------------------------------------------------------

