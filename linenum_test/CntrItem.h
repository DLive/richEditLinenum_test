// CntrItem.h : Clinenum_testCntrItem ��Ľӿ�
//

#pragma once

class Clinenum_testDoc;
class Clinenum_testView;

class Clinenum_testCntrItem : public CRichEditCntrItem
{
	DECLARE_SERIAL(Clinenum_testCntrItem)

// ���캯��
public:
	Clinenum_testCntrItem(REOBJECT* preo = NULL, Clinenum_testDoc* pContainer = NULL);
		// ע��: ���� pContainer Ϊ NULL ������ IMPLEMENT_SERIALIZE
		//  IMPLEMENT_SERIALIZE Ҫ������д���
		//  �����Ĺ��캯����OLE ��ͨ������
		//  �� NULL �ĵ�ָ�빹���

// ����
public:
	Clinenum_testDoc* GetDocument()
		{ return reinterpret_cast<Clinenum_testDoc*>(CRichEditCntrItem::GetDocument()); }
	Clinenum_testView* GetActiveView()
		{ return reinterpret_cast<Clinenum_testView*>(CRichEditCntrItem::GetActiveView()); }

	public:
	protected:

// ʵ��
public:
	~Clinenum_testCntrItem();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

