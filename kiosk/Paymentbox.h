#pragma once
#include "CRectMenu.h"
#include "CRectNow.h"
// �輺�� ------------------------------------------------------------------------
class Paymentbox
{
public:
	CRectMenu* menu; 
	CPoint pos; 
	int width; 
	int height; 
	CRectNow* now;
	int count; // ������
public:
	Paymentbox::Paymentbox();
	Paymentbox::Paymentbox(CPoint p, CRectMenu* m);
	Paymentbox::Paymentbox(CPoint p, CRectNow* n);
	void Paymentbox::draw(CDC* pDC);
};

// �輺�� ------------------------------------------------------------------------