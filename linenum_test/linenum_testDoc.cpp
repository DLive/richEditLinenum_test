// linenum_testDoc.cpp : Clinenum_testDoc ���ʵ��
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
	// ����Ĭ�ϵ� OLE ����ʵ��
	ON_UPDATE_COMMAND_UI(ID_OLE_EDIT_LINKS, &CRichEditDoc::OnUpdateEditLinksMenu)
	ON_COMMAND(ID_OLE_EDIT_LINKS, &CRichEditDoc::OnEditLinks)
	ON_UPDATE_COMMAND_UI_RANGE(ID_OLE_VERB_FIRST, ID_OLE_VERB_LAST, &CRichEditDoc::OnUpdateObjectVerbMenu)
END_MESSAGE_MAP()


// Clinenum_testDoc ����/����

Clinenum_testDoc::Clinenum_testDoc()
{
	// TODO: �ڴ����һ���Թ������

}

Clinenum_testDoc::~Clinenum_testDoc()
{
}

BOOL Clinenum_testDoc::OnNewDocument()
{
	if (!CRichEditDoc::OnNewDocument())
		return FALSE;

	// TODO: �ڴ�������³�ʼ������
	// (SDI �ĵ������ø��ĵ�)

	return TRUE;
}

CRichEditCntrItem* Clinenum_testDoc::CreateClientItem(REOBJECT* preo) const
{
	return new Clinenum_testCntrItem(preo, const_cast<Clinenum_testDoc*>(this));
}




// Clinenum_testDoc ���л�

void Clinenum_testDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}

	// ���û��� CRichEditDoc ������
	//  �����ĵ��� COleClientItem ��������л���
	// TODO: �����Ϊ�ı��������л��������� CRichEditDoc::m_bRTF = FALSE
	CRichEditDoc::Serialize(ar);
}


// Clinenum_testDoc ���

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


// Clinenum_testDoc ����
