// linenum_testDoc.h : Clinenum_testDoc 类的接口
//


#pragma once


class Clinenum_testDoc : public CRichEditDoc
{
protected: // 仅从序列化创建
	Clinenum_testDoc();
	DECLARE_DYNCREATE(Clinenum_testDoc)

// 属性
public:

// 操作
public:

// 重写
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual CRichEditCntrItem* CreateClientItem(REOBJECT* preo) const;

// 实现
public:
	virtual ~Clinenum_testDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};


