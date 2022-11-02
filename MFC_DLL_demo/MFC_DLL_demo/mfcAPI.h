#pragma once

#include <opencv2\opencv.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\core\core.hpp>
using namespace cv;

//定义导出函数接口声明
//输出VideoCapture获取的Mat
_declspec(dllexport) Mat _stdcall open_Videocapture();

//保存Mat到本地  参数一：要保存的图片  参数二：图片格式
//_declspec(dllexport) BOOL _stdcall keep_picture(Mat &frame,string format);
