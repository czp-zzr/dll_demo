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
	//�����߳�
	void createThread();

	//������ͷ
	BOOL open_capture();
	//�ر�����ͷ
	void close_capture();
	//���Matͼ��
	Mat get_frame();
	//�˳��߳�
	void exit_thread();
	//�߳���ͣ����ʼ
	void isrun_thread();

	//����ͼƬ ����һ��ͼƬ���ͣ��Ҷȡ��ڰס���ɫ��	��������ͼƬ��ʽ��jpg\bmp\png��	��������ͼƬ����λ��	�����ģ�ͼƬ��
	BOOL keep_picture(string picture_type,string picture_format,string picture_path,string picture_name);

	//�߳�ִ�к���
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

