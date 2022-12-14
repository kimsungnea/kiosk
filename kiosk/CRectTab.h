#pragma once
// ¹ÎÁö¿ø ------------------------------------------------------------------------
class CRectTab
{
public:
	CPoint pos;
	int width;
	int height;
	LPCTSTR name;

public:
	CRectTab::CRectTab(); 
	CRectTab::CRectTab(CPoint p, int w, int h, LPCTSTR n);
	void CRectTab::draw(CDC* pDC); 
	bool CRectTab::checkClick(CPoint p); 
};
// ¹ÎÁö¿ø ------------------------------------------------------------------------
