// MainFrm.cpp : CMainFrame ���ʵ��
//

#include "stdafx.h"
#include "linenum_test.h"

#include "MainFrm.h"

#include "linenum_testView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CMDIFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CMDIFrameWnd)
	ON_WM_CREATE()
	ON_COMMAND(ID_FILE_OPEN, &CMainFrame::OnFileOpen)
	ON_COMMAND(ID_FILE_SAVE, &CMainFrame::OnFileSave)
	ON_COMMAND(ID_APP_EXIT, &CMainFrame::OnAppExit)
	ON_COMMAND(ID_APP_ABOUT, &CMainFrame::OnAppAbout)
	ON_COMMAND(ID_32771, &CMainFrame::On32771)
	ON_COMMAND(ID_32772, &CMainFrame::On32772)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // ״̬��ָʾ��
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};


// CMainFrame ����/����

CMainFrame::CMainFrame()
{
	// TODO: �ڴ���ӳ�Ա��ʼ������
}

CMainFrame::~CMainFrame()
{
}


int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CMDIFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("δ�ܴ���������\n");
		return -1;      // δ�ܴ���
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("δ�ܴ���״̬��\n");
		return -1;      // δ�ܴ���
	}

	// TODO: �������Ҫ��ͣ������������ɾ��������
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CMDIFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return TRUE;
}


// CMainFrame ���

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CMDIFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CMDIFrameWnd::Dump(dc);
}

#endif //_DEBUG


// CMainFrame ��Ϣ�������




void CMainFrame::OnFileOpen()
{
	// TODO: �ڴ���������������
	CMainFrame *pWnd = (CMainFrame*)AfxGetMainWnd();
	Clinenum_testView   *pView = (Clinenum_testView*)pWnd->GetActiveView();
	if(pView);
}

void CMainFrame::OnFileSave()
{
	// TODO: �ڴ���������������
	CMainFrame *pWnd = (CMainFrame*)AfxGetMainWnd();
	Clinenum_testView   *pView = (Clinenum_testView*)pWnd->GetActiveView();
	if(pView);
}

void CMainFrame::OnAppExit()
{
	// TODO: �ڴ���������������
	CMainFrame *pWnd = (CMainFrame*)AfxGetMainWnd();
	Clinenum_testView   *pView = (Clinenum_testView*)pWnd->GetActiveView();
	if(pView);
}

void CMainFrame::OnAppAbout()
{
	// TODO: �ڴ���������������
	CMainFrame *pWnd = (CMainFrame*)AfxGetMainWnd();
	Clinenum_testView   *pView = (Clinenum_testView*)pWnd->GetActiveView();
	if(pView);
}

void CMainFrame::On32771()
{
	// TODO: �ڴ���������������
	CMainFrame *pWnd = (CMainFrame*)AfxGetMainWnd();
	Clinenum_testView   *pView = (Clinenum_testView*)pWnd->GetActiveView();
	if(pView);
}

void CMainFrame::On32772()
{
	// TODO: �ڴ���������������
	CMainFrame *pWnd = (CMainFrame*)AfxGetMainWnd();
	Clinenum_testView   *pView = (Clinenum_testView*)pWnd->GetActiveView();
	if(pView);
}
