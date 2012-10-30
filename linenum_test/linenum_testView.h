// linenum_testView.h : Clinenum_testView ��Ľӿ�
//


#pragma once

class Clinenum_testCntrItem;
class Clinenum_testDoc;

class Clinenum_testView : public CRichEditView
{
protected: // �������л�����
	Clinenum_testView();
	DECLARE_DYNCREATE(Clinenum_testView)

// ����
public:
	Clinenum_testDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // ������һ�ε���
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);

// ʵ��
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

// ���ɵ���Ϣӳ�亯��
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

#ifndef _DEBUG  // linenum_testView.cpp �еĵ��԰汾
inline Clinenum_testDoc* Clinenum_testView::GetDocument() const
   { return reinterpret_cast<Clinenum_testDoc*>(m_pDocument); }
#endif

