// CntrItem.cpp : Clinenum_testCntrItem ���ʵ��
//

#include "stdafx.h"
#include "linenum_test.h"

#include "linenum_testDoc.h"
#include "linenum_testView.h"
#include "CntrItem.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Clinenum_testCntrItem ��ʵ��

IMPLEMENT_SERIAL(Clinenum_testCntrItem, CRichEditCntrItem, 0)

Clinenum_testCntrItem::Clinenum_testCntrItem(REOBJECT* preo, Clinenum_testDoc* pContainer)
	: CRichEditCntrItem(preo, pContainer)
{
	// TODO: �ڴ����һ���Թ������
}

Clinenum_testCntrItem::~Clinenum_testCntrItem()
{
	// TODO: �ڴ˴�����������
}


// Clinenum_testCntrItem ���

#ifdef _DEBUG
void Clinenum_testCntrItem::AssertValid() const
{
	CRichEditCntrItem::AssertValid();
}

void Clinenum_testCntrItem::Dump(CDumpContext& dc) const
{
	CRichEditCntrItem::Dump(dc);
}
#endif

