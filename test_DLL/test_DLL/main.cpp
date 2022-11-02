#include<iostream>
#include <stdlib.h>
//引入mfc dll动态库的头文件
#include <opencv2\opencv.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\core\core.hpp>
#include <Windows.h>
#include <stdio.h>
#include <time.h>
#include"mfcAPI.h"
#include "Video_thread.h"
using namespace std;
using namespace cv;


int main()
{
	videoThread *video = new videoThread();
	if(video->open_capture())
	{
		cout<<"videoCapture is open success!"<<endl;
	}
	video->createThread();
	Sleep(5000);
	//cout<<video->get_frame().size()<<endl;
	//Mat mat = video->get_frame().clone();
	//imshow("frame1",mat);
	//waitKey(100);
	/*for(int i=0 ;i<100;i++)
	{
		video->isrun_thread();
		Sleep(30);
	}
	Mat mat1 = video->get_frame().clone();
	imshow("frame2",mat);
	waitKey(0);*/
	video->keep_picture("黑白图","png","D:/a_vs_workspace/test_DLL/test_DLL/image","121212");
	system("pause");
	return 0;
}
