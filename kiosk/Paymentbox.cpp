#include "pch.h"
#include "Paymentbox.h"
// ±è¼º³» ------------------------------------------------------------------------
Paymentbox::Paymentbox() {}

Paymentbox::Paymentbox(CPoint p, CRectMenu* m)
{
	width = 850;
	height = 100;
	pos = p;
	menu = m;
	count = 1; // ¹ÎÁö¿ø
}
void Paymentbox::draw(CDC* pDC)
{
	CRect rect1(pos.x, pos.y + 20, pos.x + width, pos.y + height);
	CRect rect2(pos.x + 3, pos.y, pos.x + width - 3, pos.y + height - 3);
	pDC->SelectObject(rect1);
	pDC->Rectangle(rect1);

	CString priceStr; // ¹ÎÁö¿ø
	priceStr.Format(_T("%d ¿ø"), _ttoi(menu->price) * count); // ¹ÎÁö¿ø
	pDC->DrawText(priceStr, rect2, DT_RIGHT | DT_BOTTOM | DT_SINGLELINE); // ±è¼º³», ¹ÎÁö¿ø

	CString countStr; // ¹ÎÁö¿ø
	countStr.Format(_T("    %d °³"), count); // ¹ÎÁö¿ø
	pDC->DrawText(menu->name+countStr, rect2, DT_LEFT | DT_BOTTOM | DT_SINGLELINE); // ±è¼º³», ¹ÎÁö¿ø

}
// ±è¼º³» ------------------------------------------------------------------------