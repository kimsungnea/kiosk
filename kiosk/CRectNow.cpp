#include "pch.h"
#include "CRectNow.h"

CRectNow::CRectNow() {}
CRectNow::CRectNow(CPoint p, CRectMenu* m) {
	pos = p;
	menu = m;
	width = 410;
	height = 70;
}
void CRectNow::draw(CDC* pDC) {
	// 폰트
	CFont font1;
	font1.CreatePointFont(170, _T("맑은고딕"));
	pDC->SelectObject(&font1);

	// 큰 박스(보이는 박스)
	CRect rect1(pos.x, pos.y, pos.x+width, pos.y+height);
	pDC->Rectangle(rect1);

	// 작은 박스(안보이는 박스; 문자때문에 테두리가 짤리는 현상 때문에 생성)
	CRect rect2(pos.x+3, pos.y+3, pos.x + width-3, pos.y + height-3);

	// 메뉴 이름, 가격 표시
	pDC->DrawText(menu->name, rect2, DT_LEFT|DT_SINGLELINE);
	pDC->DrawText(menu->price+L" 원", rect2, DT_LEFT | DT_BOTTOM | DT_SINGLELINE);

	// 삭제 버튼(X) 박스 생성
	CRect rect3(pos.x + 340, pos.y + 10, pos.x + 390, pos.y + 60);
	pDC->Rectangle(rect3);

	// 폰트
	CFont font2;
	font2.CreatePointFont(300, _T("맑은고딕"));
	pDC->SelectObject(&font2);
	pDC->SetTextColor(RGB(255, 30, 30));

	// X글자 표시
	pDC->DrawText(L"X", rect3, DT_CENTER|DT_VCENTER|DT_SINGLELINE);
	pDC->SetTextColor(RGB(0, 0, 0));
}

bool CRectNow::checkClick(CPoint p) {
	// 클릭이벤트 발생 시 커서의 위치가 삭제 버튼 내에 있을 시 true를 리턴, 아니면 false 리턴
	if (p.x < (pos.x + 390) && pos.x + 340 < p.x && p.y < (pos.y + 60) && pos.y + 10 < p.y) {
		return true;
	}
	return false;
}