#include "readthread.h"
ReadThread *ReadThread::readthread=nullptr;
ReadThread::ReadThread(int socketfd)
{
    this->socketfd=socketfd;
}

ReadThread *ReadThread::getInstance(int socketfd)
{
    if(ReadThread::readthread==nullptr)
    {
        ReadThread::readthread=new ReadThread(socketfd);
    }
    return ReadThread::readthread;

}
ReadThread::~ReadThread()
{


}
//不断读取服务器端反馈过来的信息
void ReadThread::run()
{
    qDebug()<<"run1";
    while(1)
    {
        qDebug()<<"run2";
        read(this->socketfd,&(this->fedbk),sizeof(FEEDBACK));//读取服务器端反馈的信息
        qDebug()<<"fedbk.businesstype　＝　"<<this->fedbk.businesstype;
        //根据ｔｙｐｅ判断是进行登录还是聊天
        if(fedbk.businesstype==1)//登录
        {
            qDebug()<<"flag = "<<this->fedbk.flag;
            emit SendSign(this->fedbk.flag);//触发信号，到登录界面信号槽，将登录是否成功传到登录界面
        }
        else if (this->fedbk.businesstype==2)//聊天业务
        {
            read(this->socketfd,&this->chatmsg,sizeof(CHATMSG));
            qDebug()<<"run chatmsg->sender="<<chatmsg.senid;
            qDebug()<<"run chatmsg->recipient="<<chatmsg.rcvid;
            qDebug()<<"run chatmsg->recipient="<<chatmsg.content;
            emit SendChatmsg(&this->chatmsg);//触发信号，将聊天结构体传给聊天界面


        }
    }


}

char *ReadThread::getUserid()
{

    return  this->userid;

}
