// linenum_testDoc.h : Clinenum_testDoc ��Ľӿ�
//


#pragma once


class Clinenum_testDoc : public CRichEditDoc
{
protected: // �������л�����
	Clinenum_testDoc();
	DECLARE_DYNCREATE(Clinenum_testDoc)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual CRichEditCntrItem* CreateClientItem(REOBJECT* preo) const;

// ʵ��
public:
	virtual ~Clinenum_testDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};


