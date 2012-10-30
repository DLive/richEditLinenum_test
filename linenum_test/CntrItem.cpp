// CntrItem.cpp : Clinenum_testCntrItem 类的实现
//

#include "stdafx.h"
#include "linenum_test.h"

#include "linenum_testDoc.h"
#include "linenum_testView.h"
#include "CntrItem.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Clinenum_testCntrItem 的实现

IMPLEMENT_SERIAL(Clinenum_testCntrItem, CRichEditCntrItem, 0)

Clinenum_testCntrItem::Clinenum_testCntrItem(REOBJECT* preo, Clinenum_testDoc* pContainer)
	: CRichEditCntrItem(preo, pContainer)
{
	// TODO: 在此添加一次性构造代码
}

Clinenum_testCntrItem::~Clinenum_testCntrItem()
{
	// TODO: 在此处添加清理代码
}


// Clinenum_testCntrItem 诊断

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

