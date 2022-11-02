// MFC_DLL_demo.h : MFC_DLL_demo DLL 的主头文件
//

#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"		// 主符号
#include <opencv2\opencv.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\core\core.hpp>
#include <string.h>
#include <time.h>
using namespace cv;


// CMFC_DLL_demoApp
// 有关此类实现的信息，请参阅 MFC_DLL_demo.cpp
//

Mat frame;
VideoCapture capture;

class CMFC_DLL_demoApp : public CWinApp
{
public:
	CMFC_DLL_demoApp();

// 重写
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};