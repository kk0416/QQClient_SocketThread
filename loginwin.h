#ifndef LOGINWIN_H
#define LOGINWIN_H

#include <QMainWindow>
#include <string.h>
#include <QMessageBox>
#include "socketconnect.h"
#include "readthread.h"
#include "writethread.h"
#include "protocol.h"
#include "chatwin1.h"
namespace Ui {
class LoginWin;
}

class LoginWin : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoginWin(QWidget *parent = nullptr);
    ~LoginWin();
public slots:
    void FmrCheckres(int flag);//读线程自定义信号对应的槽
private slots:

    void on_BtnOK_clicked();

    void on_BtnCancel_clicked();

private:
    Ui::LoginWin *ui;
    SocketConnect *sc;
    ReadThread * rt;
    WriteThread * wt;
    PROTOCOL pro;
    USERINFO user;
    char buf[2000];
    ChatWin1 * chatWin;

};

#endif // LOGINWIN_H
