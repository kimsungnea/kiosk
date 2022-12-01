#include "pch.h"
#include "CRectTab.h"

CRectTab::CRectTab() {}

CRectTab::CRectTab(CPoint p, int w, int h, LPCTSTR n) {
	pos = p; 
	width = w; 
	height = h; 
	name = n; 
}

void CRectTab::draw(CDC* pDC) {
	
	// 펜
	CPen pen;
	pen.CreatePen(PS_SOLID, 3, RGB(146, 216, 240));
	pDC->SelectObject(&pen);

	// 탭 박스 생성
	CRect Rect(pos, CPoint(pos.x + width, pos.y + height));
	pDC->SelectObject(Rect);
	pDC->Rectangle(&Rect);

	// 폰트
	CFont font;
	font.CreatePointFont(200, _T("맑은고딕"));
	pDC->SelectObject(&font);

	// 탭 이름 표시(음료 종류)
	pDC->DrawText(name, &Rect, DT_CENTER|DT_VCENTER|DT_SINGLELINE);
}

// 클릭 이벤트 발생 시 커서의 위치가 해당 탭 박스 내에 있다면 true를 리턴, 아니면 false 리턴
bool CRectTab::checkClick(CPoint p) {
	if (p.x <( pos.x + width) && pos.x < p.x && p.y < (pos.y + height) && pos.y < p.y) {
		return true;
	}
	return false;
}