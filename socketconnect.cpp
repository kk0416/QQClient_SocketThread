#include "socketconnect.h"

SocketConnect * SocketConnect::sc=nullptr;//静态变量初始化
//编写socket函数，定义socketfd
SocketConnect::SocketConnect()
{
    //初始化变量
    this->socketfd=socket(AF_INET, SOCK_STREAM, 0);
    this->length=sizeof (this->s_addr);
}


SocketConnect::~SocketConnect()
{

}
//静态函数：用来获取对象
SocketConnect *SocketConnect::getInstance()
{
    if(SocketConnect::sc==nullptr)
    {
        SocketConnect::sc=new SocketConnect();
    }
    return  SocketConnect::sc;
}

//用来准备客户端网络连接
void SocketConnect::CreateConnect()
{
    //判断初始化网络是否成功
    if(this->socketfd==-1)
    {
        perror("socket error");
    }
    else {
        //协议
        this->s_addr.sin_family=AF_INET;
        //端口号
        this->s_addr.sin_port=htons(20086);
        //ｉｐ
        this->s_addr.sin_addr.s_addr=inet_addr("127.0.0.1");

        //地址长度
        this->length=sizeof (this->s_addr);

        if(connect(this->socketfd,(struct sockaddr*)&(this->s_addr),this->length)==-1)
        {

            perror("connect error");
        }
    }
}
//关闭socketfd
void SocketConnect::Close(){
    if(this->socketfd==-1)
    {
        perror("socket error");
    }
    else
    {
        close(this->socketfd);
    }
}
//
int SocketConnect::getSocketfd() const
{
    return this->socketfd;
}
//
void SocketConnect::setSocketfd(int value)
{
    this->socketfd = value;
}
