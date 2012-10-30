// linenum_testView.cpp : Clinenum_testView 类的实现
//

#include "stdafx.h"
#include "linenum_test.h"

#include "linenum_testDoc.h"
#include "CntrItem.h"
#include "linenum_testView.h"

#include "MainFrm.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Clinenum_testView

IMPLEMENT_DYNCREATE(Clinenum_testView, CRichEditView)

BEGIN_MESSAGE_MAP(Clinenum_testView, CRichEditView)
	ON_WM_DESTROY()
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CRichEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CRichEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CRichEditView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_WM_SIZING()
	ON_WM_SIZE()
//	ON_WM_PAINT()
ON_WM_MOUSEWHEEL()
ON_WM_HSCROLL()
ON_WM_VSCROLL()
END_MESSAGE_MAP()

// Clinenum_testView 构造/析构


Clinenum_testView::Clinenum_testView()
{
	// TODO: 在此处添加构造代码

}

Clinenum_testView::~Clinenum_testView()
{
}

BOOL Clinenum_testView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式
	return CRichEditView::PreCreateWindow(cs);
}

void Clinenum_testView::OnInitialUpdate()
{
	CRichEditView::OnInitialUpdate();


	// 设置打印边距(720 缇 = 1/2 英寸)
	//SetMargins(CRect(720, 720, 720, 720));
	SetMargins(CRect(0,0,0,0));
	//rc=this->GetMargins();
	//this->SetMargins(rc);
	//this->GetRichEditCtrl().GetClientRect(rc);
	//this->GetRichEditCtrl().GetRect(rc);
	CRect rc;
	this->GetRichEditCtrl().GetClientRect(rc);
	rc.left=20;
	rc.right+=5;
	
	//SCROLLINFO si;
	//this->GetScrollInfo(SB_VERT,&si);
	//si.cbSize=sizeof(si);
	//si.nPage=20;
	//si.fMask=SIF_PAGE|SIF_TRACKPOS;
	//si.nMin=20;
	//si.nTrackPos=20;
	//this->SetScrollInfo(SB_VERT,&si);
	//this->GetRichEditCtrl().getp
	//::SetWindowPos(this->GetRichEditCtrl().m_hWnd,HWND_TOP,rc.left,rc.top,rc.Width(),rc.Height(),SWP_NOREDRAW);
	//this->GetRichEditCtrl().SetWindowPos(&wndTop,rc.left,rc.top,rc.Width(),rc.Height(),SWP_SHOWWINDOW);
	//this->MoveWindow(rc);
	//long style=GetWindowLong(this->GetRichEditCtrl().m_hWnd,GWL_STYLE);
	//style&=~(WS_MAXIMIZE|WS_CLIPSIBLINGS );
	//SetWindowLong(this->GetRichEditCtrl().m_hWnd,GWL_STYLE,style);
}


// Clinenum_testView 打印

BOOL Clinenum_testView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}


void Clinenum_testView::OnDestroy()
{
	// 析构时停用此项；这在
	// 使用拆分视图时非常重要 
   COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
   if (pActiveItem != NULL && pActiveItem->GetActiveView() == this)
   {
      pActiveItem->Deactivate();
      ASSERT(GetDocument()->GetInPlaceActiveItem(this) == NULL);
   }
   CRichEditView::OnDestroy();
}



// Clinenum_testView 诊断

#ifdef _DEBUG
void Clinenum_testView::AssertValid() const
{
	CRichEditView::AssertValid();
}

void Clinenum_testView::Dump(CDumpContext& dc) const
{
	CRichEditView::Dump(dc);
}

Clinenum_testDoc* Clinenum_testView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Clinenum_testDoc)));
	return (Clinenum_testDoc*)m_pDocument;
}
#endif //_DEBUG


// Clinenum_testView 消息处理程序

LRESULT Clinenum_testView::WindowProc(UINT message, WPARAM wParam, LPARAM lParam)
{
	// TODO: 在此添加专用代码和/或调用基类
	if( message == WM_PAINT )
	{
	//CallWindowProc( lpEditProc, hWnd, uMsg, wParam, lParam);
	//PAINTSTRUCT ps;
	//BeginPaint(&ps);
	//下列函数完成显示行号的功能
	
	ShowLineNum(this->GetParent()->m_hWnd); 
	//EndPaint(&ps);
		//CRect rc;
		//this->GetClientRect(rc);
		//this->GetParent()->GetClientRect(rc);
		//rc.left=20;
		//rc.right+=5;
		//this->GetRichEditCtrl().MoveWindow(rc,0);
		//HWND hh=this->GetRichEditCtrl().m_hWnd;
		//
		//::SetWindowPos(this->m_hWnd,HWND_TOP,rc.left,rc.top,rc.Width(),rc.Height(),SWP_NOREDRAW);
		//rc.left=20;
	}

	return CRichEditView::WindowProc(message, wParam, lParam);
}

int Clinenum_testView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CRichEditView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	
	//rc=this->GetMargins();
	//rc.left=100;
	//this->SetMargins(rc);
	//this->GetRichEditCtrl().GetClientRect(rc);
	//this->GetRichEditCtrl().GetRect(rc);
	//lpEditProc = SetWindowLong(this->m_hWnd, GWL_WNDPROC,(long)&SubEditProc );
	return 0;
}
long CALLBACK Clinenum_testView::SubEditProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam )
{
	if( uMsg == WM_PAINT )
	{
		PAINTSTRUCT ps;
		CallWindowProc( (WNDPROC)lpEditProc, hWnd, uMsg, wParam, lParam);

		//ShowLineNum( hWinEdit ); 

		return ::EndPaint( hWnd, &ps);

	}
	
	return CallWindowProc( (WNDPROC)lpEditProc, hWnd, uMsg, wParam, lParam);

}
void Clinenum_testView::ShowLineNum( HWND hEdit )
{
	/*
	功能：显示文本的总行数
	参数： 
	hEdit：要显示行号的文本框，普通的Edit控件没有测试过，这里只用RichEdit

	返回值：没有。
	--------------------------------------------------------------------------------
	*/
	RECT     ClientRect;     //RichEdit的客户区大小
	HDC      hdcEdit;         //RichEdit的Dc（设备环境）
	HDC      hdcCpb;          //与RichEdit兼容的Dc
	HBITMAP  hdcBmp;      //RichEdit兼容的位图dc
	//int      CharHeight;      //字符的高度
	int      chHeight;        //字符的高度，常量 
	int      FirstLine;       //文本框中的第一个可见行的行号。
	int      ClientHeight;    //RichEdit的客户区高度 
	int      LineCount;       //文本的总行数 
	int		 width=30;
	RECT	 numrc;
	wchar_t     countBuf[10];   //显示行号的缓冲区
	CHARFORMAT     CharFmt;  //RichEdit中的一个结构，用于获取字符的一系列信息，这里只用它来获取字符高度
	
	//获取RichEdit的Dc
	hdcEdit = ::GetDC( hEdit);
	::GetClientRect( hEdit, &ClientRect);
	//获取RichEdit的客户区高度
	ClientHeight = ClientRect.bottom - ClientRect.top;
	//创建与RichEdit兼容的Dc
	numrc=ClientRect;
	hdcCpb = CreateCompatibleDC( hdcEdit );
	//创建与RichEdit兼容的位图Dc，我们用来显示行号用的。
	hdcBmp = CreateCompatibleBitmap( hdcEdit, width, ClientHeight );
	//将位图dc选入RichEdit环境中
	SelectObject( hdcCpb, hdcBmp );
	//填充显示行号dc的背景颜色。大家可以试试其它颜色
	FillRect( hdcCpb, &ClientRect, CreateSolidBrush(0x8080ff) );
	SetBkMode( hdcCpb, TRANSPARENT );
	//获取当前RichEdit文本中的总行数
	LineCount = ::SendMessage( this->m_hWnd, EM_GETLINECOUNT, 0, 0 );

	RtlZeroMemory( &CharFmt, sizeof(CharFmt) );
	CharFmt.cbSize = sizeof( CharFmt );
	::SendMessage( m_hWnd, EM_GETCHARFORMAT, TRUE, (long)&CharFmt );
	//获取字符高度，以英寸为单位，需转化为磅，只要除以20就得到磅尺寸。
	chHeight = CharFmt.yHeight / 20; 
	CFont *fn;
	fn=this->GetRichEditCtrl().GetFont();
	LOGFONT lfn;
	if(fn)
	{
		fn->GetLogFont(&lfn);
	}
	TEXTMETRIC tm;
	
	GetTextMetrics(::GetDC(this->GetRichEditCtrl().m_hWnd),&tm);
	//设置显示行号的前景色
	SetTextColor( hdcCpb, 0x000000 );
	//获取文本框中第一个可见的行的行号，没有这个行号，显示不会跟着文本的滚动而滚动。
	FirstLine = ::SendMessage( m_hWnd, EM_GETFIRSTVISIBLELINE, 0, 0 );
	FirstLine++;
	//在位图dc中循环输出行号
	numrc.top=2;
	//numrc.bottom=numrc.top+chHeight+chHeight/2;
	numrc.bottom=tm.tmHeight+tm.tmDescent+tm.tmInternalLeading;
	//this->GetRichEditCtrl().LineScroll(FirstLine);
	PARAFORMAT2 pf2;
	pf2.cbSize = sizeof(PARAFORMAT2);
	pf2.dwMask=PFM_LINESPACING|PFM_STYLE;
	this->GetRichEditCtrl().GetParaFormat(pf2);
	TRACE(_T("charH=%d,tmHeitht=%d ,tmLeading=%d tmEleading=%d rcHeight=%d lineSpacing=%d linerule=%d \n"),chHeight,tm.tmHeight,tm.tmInternalLeading,tm.tmExternalLeading,numrc.bottom-numrc.top,pf2.dyLineSpacing,pf2.bLineSpacingRule);
	int color=40;
	int col2=50;
	
	while( FirstLine <= LineCount )
	{
		COLORREF col=RGB(100,col2,color);
		color+=5;
		col2+=7;
		FillRect( hdcCpb, &numrc,CreateSolidBrush(col) );
		DrawText(hdcCpb,countBuf,wsprintf( countBuf, TEXT("%4u"), FirstLine++ ),&numrc,DT_VCENTER|DT_SINGLELINE);
		//TextOut( hdcCpb,0, CharHeight, countBuf, wsprintf( countBuf, TEXT("%4u"), FirstLine++ ));
		numrc.top+=tm.tmHeight+tm.tmDescent+tm.tmInternalLeading;
		numrc.bottom+=tm.tmHeight+tm.tmDescent+tm.tmInternalLeading;
		//numrc.top+=chHeight+chHeight/2;
		//numrc.bottom+=chHeight+chHeight/2;
		if(numrc.bottom > ClientRect.bottom ) break;
	}
	//将已"画好"的位图真正"贴"到RichEdit中
	BitBlt( hdcEdit, 0, 0, width, ClientHeight, hdcCpb, 0, 0, SRCCOPY );
	DeleteDC( hdcCpb );
	::ReleaseDC( hEdit, hdcEdit );
	DeleteObject( hdcBmp );

}
BOOL Clinenum_testView::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	

	//if( pMsg->message == WM_PAINT )
	//{
	//CallWindowProc( lpEditProc, hWnd, uMsg, wParam, lParam);
	//PAINTSTRUCT ps;
	//BeginPaint(&ps);
	//下列函数完成显示行号的功能
	//ShowLineNum(this->GetParent()->m_hWnd); 

	//EndPaint(&ps);
		//CRect rc;
		//this->GetClientRect(rc);
		//this->GetParent()->GetClientRect(rc);
		//rc.left=20;
		//rc.right+=5;
		//this->GetRichEditCtrl().MoveWindow(rc,0);
		//HWND hh=this->GetRichEditCtrl().m_hWnd;
		//
		//::SetWindowPos(this->m_hWnd,HWND_TOP,rc.left,rc.top,rc.Width(),rc.Height(),SWP_NOREDRAW);
		//rc.left=20;
	//}
	return CRichEditView::PreTranslateMessage(pMsg);
}

//BOOL Clinenum_testView::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext)
//{
//	// TODO: 在此添加专用代码和/或调用基类
//
//	return CRichEditView::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
//}

void Clinenum_testView::OnSizing(UINT fwSide, LPRECT pRect)
{
	CRichEditView::OnSizing(fwSide, pRect);

	// TODO: 在此处添加消息处理程序代码
}

void Clinenum_testView::OnSize(UINT nType, int cx, int cy)
{

	CRichEditView::OnSize(nType, cx, cy);
	
	if(nType==SIZE_MAXIMIZED)
	{
		CRect rc;
		int width=30;
		//this->GetClientRect(rc);
		this->GetParent()->GetClientRect(rc);
		rc.left=width;
		//rc.right+=5;
		//this->GetRichEditCtrl().MoveWindow(rc,0);
		HWND hh=this->GetRichEditCtrl().m_hWnd;
		
		::SetWindowPos(this->m_hWnd,HWND_TOP,rc.left,rc.top,rc.Width(),rc.Height(),SWP_NOREDRAW);
	}
	//
	//GetRichEditCtrl().SetWindowPos(&wndTop,rc.left,rc.top,rc.Width(),rc.Height(),SWP_SHOWWINDOW);
	// TODO: 在此处添加消息处理程序代码
}

//void Clinenum_testView::OnPaint()
//{
//	CPaintDC dc(this); // device context for painting
//	// TODO: 在此处添加消息处理程序代码
//	CRichEditView::OnPaint();
//}




BOOL Clinenum_testView::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(nFlags==0)
	{
		int FirstLine = ::SendMessage( m_hWnd, EM_GETFIRSTVISIBLELINE, 0, 0 );
		if(zDelta>0)
			FirstLine=-1;
		else
			FirstLine=1;	
		this->GetRichEditCtrl().LineScroll(FirstLine);
		//this->GetRichEditCtrl().LineIndex(FirstLine);
		 TRACE(_T("nFlags=%d zDelta=%d x=%d y=%d   line=%d\n"), nFlags, zDelta, pt.x, pt.y, FirstLine);
	}
	return TRUE;
	return CRichEditView::OnMouseWheel(nFlags, zDelta, pt);
}

void Clinenum_testView::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	TRACE(_T("nFlags=%d "), nPos);
	CRichEditView::OnHScroll(nSBCode, nPos, pScrollBar);
}

void Clinenum_testView::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//CRect rc;
	//this->GetRichEditCtrl().GetClientRect(&rc);
	//this->GetWindowRect(&rc);
	//this->GetRichEditCtrl().getr
	SCROLLINFO si;
	this->GetScrollInfo(SB_VERT,&si);
	//si.cbSize=sizeof(si);
	//si.nPage=20;
	//si.fMask=SIF_PAGE|SIF_TRACKPOS;
	//si.nMin=20;
	//si.nTrackPos=20;
	int count=this->GetRichEditCtrl().GetLineCount();
	if(nPos!=si.nPos && nPos!=0)
	{
		
		int lineAvg=si.nMax/count;
		//if((nPos%lineAvg)>(lineAvg/2))
		//	nPos=(nPos/lineAvg)+lineAvg;
		//else
		//	nPos=(nPos/lineAvg)*lineAvg;
		TRACE(_T("npos=%d pbarpos=%d npage=%d mi=%d,mx=%d count=%d avg=%d \n"), nPos,si.nPos,si.nPage,si.nMin,si.nMax,count,(si.nMax)/count);
		int dir=nPos-si.nPos;
		if(dir>=lineAvg/2)
			this->GetRichEditCtrl().LineScroll(1);
		else if(dir<=-(lineAvg/2) && dir<0)
			this->GetRichEditCtrl().LineScroll(-1);
	}

	//CRichEditView::OnVScroll(nSBCode, nPos, pScrollBar);
}

void Clinenum_testView::OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView)
{
	 //TODO: 在此添加专用代码和/或调用基类
	if(!bActivate && ::IsWindow(this->m_hWnd))
	{
		CMainFrame *pWnd = (CMainFrame*)AfxGetMainWnd();
		//pWnd->SetActiveView(this);
		Clinenum_testView* pview=(Clinenum_testView*)pWnd->GetActiveFrame()->GetActiveView();
		TRACE(_T("ad \n"));
	//Clinenum_testView   *pView = (Clinenum_testView*)pWnd->GetActiveView();
	}

	CRichEditView::OnActivateView(bActivate, pActivateView, pDeactiveView);
	//if(bActivate)
	//{
	//	CMainFrame *pWnd = (CMainFrame*)AfxGetMainWnd();
	//	pWnd->SetActiveView(this);
	//	TRACE(_T("ad \n"));
	////Clinenum_testView   *pView = (Clinenum_testView*)pWnd->GetActiveView();
	//}
}
