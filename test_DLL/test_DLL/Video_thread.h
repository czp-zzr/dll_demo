#ifndef VIDEO_THREAD_H
#define VIDEO_THREAD_H
#include <Windows.h>
#include <iostream>
#include <stdlib.h>
#include <opencv2\opencv.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\core\core.hpp>
using namespace std;
using namespace cv;

#ifdef VIDEO_THREAD_H
#define _DLL_API _declspec(dllexport)
#else
#define _DLL_API _declspec(dllimport)
#endif

class _DLL_API videoThread
{
public:
	videoThread();
	~videoThread();
	//创建线程
	void createThread();

	//打开摄像头
	BOOL open_capture();
	//关闭摄像头
	void close_capture();
	//输出Mat图像
	Mat get_frame();
	//退出线程
	void exit_thread();
	//线程暂停、开始
	void isrun_thread();

	//保存图片 参数一：图片类型（灰度、黑白、彩色）	参数二：图片格式（jpg\bmp\png）	参数三：图片保存位置	参数四：图片名
	BOOL keep_picture(string picture_type,string picture_format,string picture_path,string picture_name);

	//线程执行函数
	static DWORD WINAPI run(LPVOID lpParameter);

private:
	VideoCapture capture;
	Mat frame;
	Mat outputFrame;
	HANDLE handle;
	DWORD dwThreadId;
	BOOL isstop;
	BOOL isrun;
};

#endif

