#pragma once

#include <opencv2\opencv.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\core\core.hpp>
using namespace cv;

//���嵼�������ӿ�����
//���VideoCapture��ȡ��Mat
_declspec(dllexport) Mat _stdcall open_Videocapture();

//����Mat������  ����һ��Ҫ�����ͼƬ  ��������ͼƬ��ʽ
//_declspec(dllexport) BOOL _stdcall keep_picture(Mat &frame,string format);
