// MFC_DLL_demo.cpp : ���� DLL �ĳ�ʼ�����̡�
//
#include "stdafx.h"
#include "MFC_DLL_demo.h"

#include "mfcAPI.h"
#include "Video_thread.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO: ����� DLL ����� MFC DLL �Ƕ�̬���ӵģ�
//		��Ӵ� DLL �������κε���
//		MFC �ĺ������뽫 AFX_MANAGE_STATE ����ӵ�
//		�ú�������ǰ�档
//
//		����:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// �˴�Ϊ��ͨ������
//		}
//
//		�˺������κ� MFC ����
//		������ÿ��������ʮ����Ҫ������ζ��
//		��������Ϊ�����еĵ�һ�����
//		���֣������������ж������������
//		������Ϊ���ǵĹ��캯���������� MFC
//		DLL ���á�
//
//		�й�������ϸ��Ϣ��
//		����� MFC ����˵�� 33 �� 58��
//

// CMFC_DLL_demoApp

BEGIN_MESSAGE_MAP(CMFC_DLL_demoApp, CWinApp)
END_MESSAGE_MAP()


// CMFC_DLL_demoApp ����

CMFC_DLL_demoApp::CMFC_DLL_demoApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CMFC_DLL_demoApp ����

CMFC_DLL_demoApp theApp;


// CMFC_DLL_demoApp ��ʼ��

BOOL CMFC_DLL_demoApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

//��дmfc dll������ʵ��
Mat _stdcall open_Videocapture()
{
	//AFX_MANAGE_STATE������������ģ���л�ʱ��״̬��������ü�����һ��
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	//���庯����
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
