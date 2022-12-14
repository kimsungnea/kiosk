#include "pch.h"
#include "CRectTab.h"
// ¹ÎÁö¿ø ------------------------------------------------------------------------

CRectTab::CRectTab() {}

CRectTab::CRectTab(CPoint p, int w, int h, LPCTSTR n) {
	pos = p; 
	width = w; 
	height = h; 
	name = n; 
}

void CRectTab::draw(CDC* pDC) {

	CRect Rect(pos, CPoint(pos.x + width, pos.y + height));
	pDC->SelectObject(Rect);
	pDC->Rectangle(&Rect);

	CFont font;
	font.CreatePointFont(200, _T("¸¼Àº°íµñ"));
	pDC->SelectObject(&font);

	pDC->DrawText(name, &Rect, DT_CENTER|DT_VCENTER|DT_SINGLELINE);
}

bool CRectTab::checkClick(CPoint p) {
	if (p.x <( pos.x + width) && pos.x < p.x && p.y < (pos.y + height) && pos.y < p.y) {
		return true;
	}
	return false;
}

// ¹ÎÁö¿ø ------------------------------------------------------------------------