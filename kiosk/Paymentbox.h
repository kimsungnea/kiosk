#pragma once
#include "CRectMenu.h"
#include "CRectNow.h"
// ±è¼º³» ------------------------------------------------------------------------
class Paymentbox
{
public:
	CRectMenu* menu; 
	CPoint pos; 
	int width; 
	int height; 
	CRectNow* now;
	int count; // ¹ÎÁö¿ø
public:
	Paymentbox::Paymentbox();
	Paymentbox::Paymentbox(CPoint p, CRectMenu* m);
	Paymentbox::Paymentbox(CPoint p, CRectNow* n);
	void Paymentbox::draw(CDC* pDC);
};

// ±è¼º³» ------------------------------------------------------------------------