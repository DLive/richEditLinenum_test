// linenum_test.h : linenum_test Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// Clinenum_testApp:
// �йش����ʵ�֣������ linenum_test.cpp
//

class Clinenum_testApp : public CWinApp
{
public:
	Clinenum_testApp();


// ��д
public:
	virtual BOOL InitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Clinenum_testApp theApp;