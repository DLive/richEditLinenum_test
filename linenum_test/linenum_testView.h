// linenum_testView.h : Clinenum_testView 类的接口
//


#pragma once

class Clinenum_testCntrItem;
class Clinenum_testDoc;

class Clinenum_testView : public CRichEditView
{
protected: // 仅从序列化创建
	Clinenum_testView();
	DECLARE_DYNCREATE(Clinenum_testView)

// 属性
public:
	Clinenum_testDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // 构造后第一次调用
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);

// 实现
public:
	virtual ~Clinenum_testView();

	void ShowLineNum( HWND hEdit );
	long CALLBACK SubEditProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam );
	long lpEditProc;

#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	afx_msg void OnDestroy();
	DECLARE_MESSAGE_MAP()
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
//	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	afx_msg void OnSizing(UINT fwSide, LPRECT pRect);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	
//	afx_msg void OnPaint();
	//afx_msg BOOL OnMouseHWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
protected:
	virtual void OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView);
};

#ifndef _DEBUG  // linenum_testView.cpp 中的调试版本
inline Clinenum_testDoc* Clinenum_testView::GetDocument() const
   { return reinterpret_cast<Clinenum_testDoc*>(m_pDocument); }
#endif

