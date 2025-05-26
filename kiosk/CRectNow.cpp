#include "pch.h"
#include "CRectNow.h"

CRectNow::CRectNow() {}
CRectNow::CRectNow(CPoint p, CRectMenu* m) {
	// ������ ------------------------------------------------------------------------
	pos = p;
	menu = m;
	width = 410;
	height = 70;
	// ������ ------------------------------------------------------------------------

	count = 1;  // ������
}
void CRectNow::draw(CDC* pDC) {

	// ������ ------------------------------------------------------------------------
	CFont font1;
	font1.CreatePointFont(170, _T("�������"));
	pDC->SelectObject(&font1);

	CRect rect1(pos.x, pos.y, pos.x+width, pos.y+height);
	pDC->Rectangle(rect1);

	CRect rect2(pos.x+3, pos.y+3, pos.x + width-3, pos.y + height-3);

	pDC->DrawText(menu->name, rect2, DT_LEFT|DT_SINGLELINE);
	pDC->DrawText(menu->price+L" ��", rect2, DT_LEFT | DT_BOTTOM | DT_SINGLELINE);

	CRect rect3(pos.x + 340, pos.y + 10, pos.x + 390, pos.y + 60);
	pDC->Rectangle(rect3);
	// ������ ------------------------------------------------------------------------
	
	// ������ ------------------------------------------------------------------------
	CRect rect4(pos.x + 200, pos.y + 30, pos.x + 230, pos.y + 60);
	pDC->Rectangle(rect4);
	pDC->DrawText(L"+", rect4, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	CRect rect5(pos.x + 270, pos.y + 30, pos.x + 300, pos.y + 60);
	pDC->Rectangle(rect5);
	pDC->DrawText(L"-", rect5, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	CRect rect6(pos.x + 235, pos.y + 30, pos.x + 265, pos.y + 60);
	pDC->Rectangle(rect6);
	CString countStr;
	countStr.Format(_T("%d"), count);
	pDC->DrawText(countStr, rect6, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	// ������ ------------------------------------------------------------------------

	// ������ ------------------------------------------------------------------------
	CFont font2;
	font2.CreatePointFont(300, _T("�������"));
	pDC->SelectObject(&font2);
	pDC->SetTextColor(RGB(255, 30, 30));

	pDC->DrawText(L"X", rect3, DT_CENTER|DT_VCENTER|DT_SINGLELINE);
	pDC->SetTextColor(RGB(0, 0, 0));
	// ������ ------------------------------------------------------------------------
}
// ������ ------------------------------------------------------------------------
bool CRectNow::checkClick(CPoint p) {
	if (p.x < (pos.x + 390) && pos.x + 340 < p.x && p.y < (pos.y + 60) && pos.y + 10 < p.y) {
		return true;
	}
	return false;
}
// ������ ------------------------------------------------------------------------

// ������ ------------------------------------------------------------------------
bool CRectNow::checkClick2(CPoint p) {
	if (p.x < (pos.x + 230) && pos.x + 200 < p.x && p.y < (pos.y + 60) && pos.y + 30 < p.y) {
		return true;
	}
	return false;
}

bool CRectNow::checkClick3(CPoint p) {
	if (p.x < (pos.x + 300) && pos.x + 270 < p.x && p.y < (pos.y + 60) && pos.y + 30 < p.y) {
		return true;
	}
	return false;
}
// ������ ------------------------------------------------------------------------