// linenum_testView.cpp : Clinenum_testView ���ʵ��
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
	// ��׼��ӡ����
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

// Clinenum_testView ����/����


Clinenum_testView::Clinenum_testView()
{
	// TODO: �ڴ˴���ӹ������

}

Clinenum_testView::~Clinenum_testView()
{
}

BOOL Clinenum_testView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ
	return CRichEditView::PreCreateWindow(cs);
}

void Clinenum_testView::OnInitialUpdate()
{
	CRichEditView::OnInitialUpdate();


	// ���ô�ӡ�߾�(720 � = 1/2 Ӣ��)
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


// Clinenum_testView ��ӡ

BOOL Clinenum_testView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}


void Clinenum_testView::OnDestroy()
{
	// ����ʱͣ�ô������
	// ʹ�ò����ͼʱ�ǳ���Ҫ 
   COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
   if (pActiveItem != NULL && pActiveItem->GetActiveView() == this)
   {
      pActiveItem->Deactivate();
      ASSERT(GetDocument()->GetInPlaceActiveItem(this) == NULL);
   }
   CRichEditView::OnDestroy();
}



// Clinenum_testView ���

#ifdef _DEBUG
void Clinenum_testView::AssertValid() const
{
	CRichEditView::AssertValid();
}

void Clinenum_testView::Dump(CDumpContext& dc) const
{
	CRichEditView::Dump(dc);
}

Clinenum_testDoc* Clinenum_testView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Clinenum_testDoc)));
	return (Clinenum_testDoc*)m_pDocument;
}
#endif //_DEBUG


// Clinenum_testView ��Ϣ�������

LRESULT Clinenum_testView::WindowProc(UINT message, WPARAM wParam, LPARAM lParam)
{
	// TODO: �ڴ����ר�ô����/����û���
	if( message == WM_PAINT )
	{
	//CallWindowProc( lpEditProc, hWnd, uMsg, wParam, lParam);
	//PAINTSTRUCT ps;
	//BeginPaint(&ps);
	//���к��������ʾ�кŵĹ���
	
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

	// TODO:  �ڴ������ר�õĴ�������
	
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
	���ܣ���ʾ�ı���������
	������ 
	hEdit��Ҫ��ʾ�кŵ��ı�����ͨ��Edit�ؼ�û�в��Թ�������ֻ��RichEdit

	����ֵ��û�С�
	--------------------------------------------------------------------------------
	*/
	RECT     ClientRect;     //RichEdit�Ŀͻ�����С
	HDC      hdcEdit;         //RichEdit��Dc���豸������
	HDC      hdcCpb;          //��RichEdit���ݵ�Dc
	HBITMAP  hdcBmp;      //RichEdit���ݵ�λͼdc
	//int      CharHeight;      //�ַ��ĸ߶�
	int      chHeight;        //�ַ��ĸ߶ȣ����� 
	int      FirstLine;       //�ı����еĵ�һ���ɼ��е��кš�
	int      ClientHeight;    //RichEdit�Ŀͻ����߶� 
	int      LineCount;       //�ı��������� 
	int		 width=30;
	RECT	 numrc;
	wchar_t     countBuf[10];   //��ʾ�кŵĻ�����
	CHARFORMAT     CharFmt;  //RichEdit�е�һ���ṹ�����ڻ�ȡ�ַ���һϵ����Ϣ������ֻ��������ȡ�ַ��߶�
	
	//��ȡRichEdit��Dc
	hdcEdit = ::GetDC( hEdit);
	::GetClientRect( hEdit, &ClientRect);
	//��ȡRichEdit�Ŀͻ����߶�
	ClientHeight = ClientRect.bottom - ClientRect.top;
	//������RichEdit���ݵ�Dc
	numrc=ClientRect;
	hdcCpb = CreateCompatibleDC( hdcEdit );
	//������RichEdit���ݵ�λͼDc������������ʾ�к��õġ�
	hdcBmp = CreateCompatibleBitmap( hdcEdit, width, ClientHeight );
	//��λͼdcѡ��RichEdit������
	SelectObject( hdcCpb, hdcBmp );
	//�����ʾ�к�dc�ı�����ɫ����ҿ�������������ɫ
	FillRect( hdcCpb, &ClientRect, CreateSolidBrush(0x8080ff) );
	SetBkMode( hdcCpb, TRANSPARENT );
	//��ȡ��ǰRichEdit�ı��е�������
	LineCount = ::SendMessage( this->m_hWnd, EM_GETLINECOUNT, 0, 0 );

	RtlZeroMemory( &CharFmt, sizeof(CharFmt) );
	CharFmt.cbSize = sizeof( CharFmt );
	::SendMessage( m_hWnd, EM_GETCHARFORMAT, TRUE, (long)&CharFmt );
	//��ȡ�ַ��߶ȣ���Ӣ��Ϊ��λ����ת��Ϊ����ֻҪ����20�͵õ����ߴ硣
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
	//������ʾ�кŵ�ǰ��ɫ
	SetTextColor( hdcCpb, 0x000000 );
	//��ȡ�ı����е�һ���ɼ����е��кţ�û������кţ���ʾ��������ı��Ĺ�����������
	FirstLine = ::SendMessage( m_hWnd, EM_GETFIRSTVISIBLELINE, 0, 0 );
	FirstLine++;
	//��λͼdc��ѭ������к�
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
	//����"����"��λͼ����"��"��RichEdit��
	BitBlt( hdcEdit, 0, 0, width, ClientHeight, hdcCpb, 0, 0, SRCCOPY );
	DeleteDC( hdcCpb );
	::ReleaseDC( hEdit, hdcEdit );
	DeleteObject( hdcBmp );

}
BOOL Clinenum_testView::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���
	

	//if( pMsg->message == WM_PAINT )
	//{
	//CallWindowProc( lpEditProc, hWnd, uMsg, wParam, lParam);
	//PAINTSTRUCT ps;
	//BeginPaint(&ps);
	//���к��������ʾ�кŵĹ���
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
//	// TODO: �ڴ����ר�ô����/����û���
//
//	return CRichEditView::Create(lpszClassName, lpszWindowName, dwStyle, rect, pParentWnd, nID, pContext);
//}

void Clinenum_testView::OnSizing(UINT fwSide, LPRECT pRect)
{
	CRichEditView::OnSizing(fwSide, pRect);

	// TODO: �ڴ˴������Ϣ����������
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
	// TODO: �ڴ˴������Ϣ����������
}

//void Clinenum_testView::OnPaint()
//{
//	CPaintDC dc(this); // device context for painting
//	// TODO: �ڴ˴������Ϣ����������
//	CRichEditView::OnPaint();
//}




BOOL Clinenum_testView::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	TRACE(_T("nFlags=%d "), nPos);
	CRichEditView::OnHScroll(nSBCode, nPos, pScrollBar);
}

void Clinenum_testView::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
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
	 //TODO: �ڴ����ר�ô����/����û���
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
