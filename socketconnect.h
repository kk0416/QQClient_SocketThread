#ifndef SOCKETCONNECT_H
#define SOCKETCONNECT_H

#include <QThread>
#include <QDebug>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

//网络连接单例类

class SocketConnect
{
public:
    ~SocketConnect();
    static SocketConnect *getInstance();//静态公有获取对象方法

    void CreateConnect();
    void Close();

    int getSocketfd() const;
    void setSocketfd(int value);

private:
    SocketConnect();//构建私有化，编写socket函数，定义socketfd
    static SocketConnect *sc;//创建静态私有变量
    int socketfd;
    struct sockaddr_in s_addr;//结构体．后面还需要强转
    int length;//地址长度，ｂｉｎｄ参数
};
#endif // SOCKETCONNECT_H
