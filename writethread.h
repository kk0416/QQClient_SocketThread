#ifndef WRITETHREAD_H
#define WRITETHREAD_H

#include <QObject>
#include <QThread>
#include <QDebug>
#include <string.h>
#include <unistd.h>
#include "protocol.h"
//写线程单例类
class WriteThread : public QThread
{
    Q_OBJECT
public:

    virtual ~WriteThread();
    static WriteThread *getInstance(int socketfd);
    void run();
    void setData(void *value,int size);
private:
    int socketfd;
    char data[1024];
    WriteThread(int socketfd);
    static WriteThread *writethread;
};
#endif // WRITETHREAD_H
