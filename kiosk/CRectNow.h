#pragma once
#include "CRectMenu.h"
class CRectNow
{
public:
	// นฮม๖ฟ๘ ------------------------------------------------------------------------
	CRectMenu* menu;
	CPoint pos;
	int width;
	int height;
	// นฮม๖ฟ๘ ------------------------------------------------------------------------

	int count; // ฑ่ว๖มุ

public:
	// นฮม๖ฟ๘ ------------------------------------------------------------------------
	CRectNow::CRectNow();
	CRectNow::CRectNow(CPoint p, CRectMenu* m);
	void CRectNow::draw(CDC* pDC);
	bool CRectNow::checkClick(CPoint p);
	// นฮม๖ฟ๘ ------------------------------------------------------------------------

	// ฑ่ว๖มุ ------------------------------------------------------------------------
	bool CRectNow::checkClick2(CPoint p);
	bool CRectNow::checkClick3(CPoint p);
	// ฑ่ว๖มุ ------------------------------------------------------------------------
};

