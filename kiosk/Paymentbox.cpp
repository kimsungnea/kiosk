#include "pch.h"
#include "Paymentbox.h"
// �輺�� ------------------------------------------------------------------------
Paymentbox::Paymentbox() {}

Paymentbox::Paymentbox(CPoint p, CRectMenu* m)
{
	width = 850;
	height = 100;
	pos = p;
	menu = m;
	count = 1; // ������
}
void Paymentbox::draw(CDC* pDC)
{
	CRect rect1(pos.x, pos.y + 20, pos.x + width, pos.y + height);
	CRect rect2(pos.x + 3, pos.y, pos.x + width - 3, pos.y + height - 3);
	pDC->SelectObject(rect1);
	pDC->Rectangle(rect1);

	CString priceStr;
	priceStr.Format(_T("%d ��"), _ttoi(menu->price) * count);
	pDC->DrawText(priceStr, rect2, DT_RIGHT | DT_BOTTOM | DT_SINGLELINE);

	CString countStr;
	countStr.Format(_T("    %d ��"), count);
	pDC->DrawText(menu->name+countStr, rect2, DT_LEFT | DT_BOTTOM | DT_SINGLELINE);

}
// �輺�� ------------------------------------------------------------------------