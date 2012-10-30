// linenum_testDoc.cpp : Clinenum_testDoc 类的实现
//

#include "stdafx.h"
#include "linenum_test.h"

#include "linenum_testDoc.h"
#include "CntrItem.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Clinenum_testDoc

IMPLEMENT_DYNCREATE(Clinenum_testDoc, CRichEditDoc)

BEGIN_MESSAGE_MAP(Clinenum_testDoc, CRichEditDoc)
	// 启用默认的 OLE 容器实现
	ON_UPDATE_COMMAND_UI(ID_OLE_EDIT_LINKS, &CRichEditDoc::OnUpdateEditLinksMenu)
	ON_COMMAND(ID_OLE_EDIT_LINKS, &CRichEditDoc::OnEditLinks)
	ON_UPDATE_COMMAND_UI_RANGE(ID_OLE_VERB_FIRST, ID_OLE_VERB_LAST, &CRichEditDoc::OnUpdateObjectVerbMenu)
END_MESSAGE_MAP()


// Clinenum_testDoc 构造/析构

Clinenum_testDoc::Clinenum_testDoc()
{
	// TODO: 在此添加一次性构造代码

}

Clinenum_testDoc::~Clinenum_testDoc()
{
}

BOOL Clinenum_testDoc::OnNewDocument()
{
	if (!CRichEditDoc::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)

	return TRUE;
}

CRichEditCntrItem* Clinenum_testDoc::CreateClientItem(REOBJECT* preo) const
{
	return new Clinenum_testCntrItem(preo, const_cast<Clinenum_testDoc*>(this));
}




// Clinenum_testDoc 序列化

void Clinenum_testDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}

	// 调用基类 CRichEditDoc 将启用
	//  容器文档的 COleClientItem 对象的序列化。
	// TODO: 如果作为文本进行序列化，则设置 CRichEditDoc::m_bRTF = FALSE
	CRichEditDoc::Serialize(ar);
}


// Clinenum_testDoc 诊断

#ifdef _DEBUG
void Clinenum_testDoc::AssertValid() const
{
	CRichEditDoc::AssertValid();
}

void Clinenum_testDoc::Dump(CDumpContext& dc) const
{
	CRichEditDoc::Dump(dc);
}
#endif //_DEBUG


// Clinenum_testDoc 命令
