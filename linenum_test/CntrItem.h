// CntrItem.h : Clinenum_testCntrItem 类的接口
//

#pragma once

class Clinenum_testDoc;
class Clinenum_testView;

class Clinenum_testCntrItem : public CRichEditCntrItem
{
	DECLARE_SERIAL(Clinenum_testCntrItem)

// 构造函数
public:
	Clinenum_testCntrItem(REOBJECT* preo = NULL, Clinenum_testDoc* pContainer = NULL);
		// 注意: 允许 pContainer 为 NULL 以启用 IMPLEMENT_SERIALIZE
		//  IMPLEMENT_SERIALIZE 要求类具有带零
		//  参数的构造函数。OLE 项通常是用
		//  非 NULL 文档指针构造的

// 属性
public:
	Clinenum_testDoc* GetDocument()
		{ return reinterpret_cast<Clinenum_testDoc*>(CRichEditCntrItem::GetDocument()); }
	Clinenum_testView* GetActiveView()
		{ return reinterpret_cast<Clinenum_testView*>(CRichEditCntrItem::GetActiveView()); }

	public:
	protected:

// 实现
public:
	~Clinenum_testCntrItem();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

