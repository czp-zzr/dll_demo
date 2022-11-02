// MFC_DLL_demo.cpp : 定义 DLL 的初始化例程。
//
#include "stdafx.h"
#include "MFC_DLL_demo.h"

#include "mfcAPI.h"
#include "Video_thread.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO: 如果此 DLL 相对于 MFC DLL 是动态链接的，
//		则从此 DLL 导出的任何调入
//		MFC 的函数必须将 AFX_MANAGE_STATE 宏添加到
//		该函数的最前面。
//
//		例如:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// 此处为普通函数体
//		}
//
//		此宏先于任何 MFC 调用
//		出现在每个函数中十分重要。这意味着
//		它必须作为函数中的第一个语句
//		出现，甚至先于所有对象变量声明，
//		这是因为它们的构造函数可能生成 MFC
//		DLL 调用。
//
//		有关其他详细信息，
//		请参阅 MFC 技术说明 33 和 58。
//

// CMFC_DLL_demoApp

BEGIN_MESSAGE_MAP(CMFC_DLL_demoApp, CWinApp)
END_MESSAGE_MAP()


// CMFC_DLL_demoApp 构造

CMFC_DLL_demoApp::CMFC_DLL_demoApp()
{
	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 CMFC_DLL_demoApp 对象

CMFC_DLL_demoApp theApp;


// CMFC_DLL_demoApp 初始化

BOOL CMFC_DLL_demoApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

//编写mfc dll函数的实现
Mat _stdcall open_Videocapture()
{
	//AFX_MANAGE_STATE这句代码是用于模块切换时的状态保护，最好加上这一句
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	//定义函数体
	static int i = 0;
	if(i==0)
	{
		capture.open(0);
		i++;
	}
	capture.read(frame);
	return frame;
	
}

string get_nowTime()
{
	time_t timep;
    time(&timep);
    char tmp[256] = "0";
	string str;
	strftime(tmp, sizeof(tmp), "%Y_%m_%d %H_%M_%S", localtime(&timep));
	str += tmp;
    return str;
}

//BOOL _stdcall keep_picture(Mat &frame,string format)
//{
//	if(frame.data)
//	{
//		string path = "D:/a_vs_workspace/test_DLL/test_DLL/image/";
//		string time(get_nowTime());
//		path += time;
//		if(format == "jpg")
//		{
//			path += ".jpg";
//		}else if(format == "bmp")
//		{
//			path += ".bmp";
//		}else if(format == "png")
//		{
//			path += ".png";
//		}
//		imwrite(path,frame);
//		return true;
//	}else
//	{
//		return false;
//	}
//	
//}
