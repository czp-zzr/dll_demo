// MFC_DLL_demo.h : MFC_DLL_demo DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������
#include <opencv2\opencv.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\core\core.hpp>
#include <string.h>
#include <time.h>
using namespace cv;


// CMFC_DLL_demoApp
// �йش���ʵ�ֵ���Ϣ������� MFC_DLL_demo.cpp
//

Mat frame;
VideoCapture capture;

class CMFC_DLL_demoApp : public CWinApp
{
public:
	CMFC_DLL_demoApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};