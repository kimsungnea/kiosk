#pragma once
#include "CRectMenu.h"
class CRectNow
{
public:
	// ������ ------------------------------------------------------------------------
	CRectMenu* menu;
	CPoint pos;
	int width;
	int height;
	// ������ ------------------------------------------------------------------------

	int count; // ������

public:
	// ������ ------------------------------------------------------------------------
	CRectNow::CRectNow();
	CRectNow::CRectNow(CPoint p, CRectMenu* m);
	void CRectNow::draw(CDC* pDC);
	bool CRectNow::checkClick(CPoint p);
	// ������ ------------------------------------------------------------------------

	// ������ ------------------------------------------------------------------------
	bool CRectNow::checkClick2(CPoint p);
	bool CRectNow::checkClick3(CPoint p);
	// ������ ------------------------------------------------------------------------
};

