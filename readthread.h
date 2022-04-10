#ifndef READTHREAD_H
#define READTHREAD_H

#include <QObject>
#include <QThread>
#include <QDebug>
#include "protocol.h"
#include <QDebug>
#include "socketconnect.h"
class ReadThread : public QThread
{
    Q_OBJECT
public:
    virtual ~ReadThread();
    static ReadThread* getInstance(int socketfd);//把socketfd作为参数传给构造函数
    void run();
    char *getUserid();//获取登录用户的帐号，传给聊天界面
private:
    ReadThread(int socketfd);

    int socketfd;
    static ReadThread* readthread;
    char userid[20];
    PROTOCOL data;
    FEEDBACK fedbk;
    CHATMSG chatmsg;
    USERINFO userinfo;
signals:
    void SendSign(int flag);//flag判断是否登录成功
    void SendChatmsg(CHATMSG *chatmsg);
};
#endif // READTHREAD_H
