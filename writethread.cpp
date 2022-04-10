#include "writethread.h"
WriteThread* WriteThread::writethread=nullptr;
WriteThread::WriteThread(int socketfd)
{
    //初始化类属性socketfd\data(memset)
    this->socketfd=socketfd;
    memset(this->data,0,sizeof(this->data));
}

WriteThread::~WriteThread()
{

}
//单例函数
WriteThread* WriteThread::getInstance(int socketfd)
{
    if(WriteThread::writethread==nullptr)
    {
        WriteThread::writethread=new WriteThread(socketfd);
    }
    return WriteThread::writethread;

}
//不断写入数据
void WriteThread::run()
{
    while(1)
    {
        if(strlen(this->data)>0)
        {
            int res=write(this->socketfd,this->data,sizeof(this->data));
            if(res>0)
            {
                qDebug()<<"send success, res = "<<res;
            }
            bzero(this->data,sizeof(this->data));
        }
    }
}
//把要传递的信息传给ｄａｔａ
void WriteThread::setData(void *value, int size)
{

    memcpy(this->data,value,size);
}


