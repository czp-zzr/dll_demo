#include "stdafx.h"
#include "Video_thread.h"

videoThread::videoThread()
{
	this->isstop = false;
	this->isrun = true;
}

videoThread::~videoThread()
{
	//CloseHandle(handle);
}

void videoThread::createThread()
{
	this->handle = CreateThread(NULL,0,run,this,0,&(this->dwThreadId));
	if(NULL == handle)
    {
        cout<<"Create Thread failed !"<<endl;
		//createThread();
    }
}

DWORD WINAPI videoThread::run(LPVOID lpParameter)
{
	DWORD dwThreadId = GetCurrentThreadId();
	videoThread *p = (videoThread *)lpParameter;
	cout<<"进入摄像头线程......"<<endl;
	while(!p->isstop)
	{

		//cout<<"isrun = "<<p->isrun<<endl;
		//线程暂停
		if(p->isrun)
		{
			if(p->capture.isOpened())
			{
				//p->capture.read(p->frame);
				p->capture>>(p->frame);
				//p->dstframe = p->frame.clone();
				p->isrun_thread();
			}
		}
		Sleep(20);
		
	}
	cout<<"摄像头线程run结束......"<<endl;
	return 0;
}

void videoThread::isrun_thread()
{
	if(this->isrun)
	{
		this->isrun = false;
	}else
	{
		this->isrun = true;
	}
}

Mat videoThread::get_frame()
{
	return this->frame;
}

void videoThread::exit_thread()
{
	this->isstop = true;
	CloseHandle(this->handle);
}

BOOL videoThread::keep_picture(string picture_type,string picture_format,string picture_path,string picture_name)
{
	string file = picture_path + "/" + picture_name + "." + picture_format;
	if(picture_type == "灰度图")
	{
		cvtColor(this->frame,this->outputFrame,CV_BGR2GRAY);
		imwrite(file,this->outputFrame);
		return true;
	}else if(picture_type == "黑白图")
	{
		cvtColor(this->frame,this->outputFrame,CV_BGR2GRAY);
		threshold(this->outputFrame, this->outputFrame, 175, 255, cv::THRESH_BINARY  ); //二值化
		imwrite(file,this->outputFrame);
		return true;
	}else if(picture_type == "彩色图")
	{
		imwrite(file,this->frame);
		return true;
	}
	return false;
}

//打开摄像头
BOOL videoThread::open_capture()
{
	this->capture.open(0);
	if(!this->capture.isOpened())  
    {  
        return false;  
    }
	int i = 10;
	while(i>0)
	{
		this->capture>>(this->frame);
		i--;
	}
	return true;
}

//关闭摄像头
void videoThread::close_capture()
{
	this->capture.release();
}