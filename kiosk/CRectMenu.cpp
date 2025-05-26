#include "pch.h"
#include "CRectMenu.h"
#include "string"
// ¹ÎÁö¿ø ------------------------------------------------------------------------
CRectMenu::CRectMenu() {};

CRectMenu::CRectMenu(CPoint p, int w, int h, CString k, CString n, CString pr) {
	pos = p;
	width = w;
	height = h;
	kind = k;
	name = n;
	price = pr;
	border = RGB(146, 216, 240);
};

void CRectMenu::draw(CDC* pDC){

	CPen pen(PS_SOLID, 3, border);
	pDC->SelectObject(&pen);
	CPen* oldPen = pDC->SelectObject(&pen);

	CRect Rect(pos, CPoint(pos.x + width, pos.y + height));
	pDC->SelectObject(Rect);
	pDC->Rectangle(&Rect);

	pDC->SelectObject(&oldPen);

	CImage img;
	img.Load(L"res/" + kind + L"/" + name + L" " + price + L".png");
	img.Draw(*pDC, pos.x+1, pos.y+1);
};

bool CRectMenu::checkClick(CPoint p) {
	if (p.x < (pos.x + width) && pos.x < p.x && p.y < (pos.y + height) && pos.y < p.y) {
		return true;
	}
	return false;
}
// ¹ÎÁö¿ø ------------------------------------------------------------------------