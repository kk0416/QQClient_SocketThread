#ifndef CHATWIN1_H
#define CHATWIN1_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QToolButton>
#include <QTextBrowser>
#include <QTextEdit>
#include <QPushButton>
#include <QSpacerItem>
#include <QComboBox>
#include <QSpinBox>
#include <QFontComboBox>
#include <QTableWidget>
#include <QPainter>
#include <QStandardItemModel>
#include <QDebug>

#include "socketconnect.h"
#include "protocol.h"
#include "readthread.h"
#include "writethread.h"
#include <string.h>
namespace Ui {
class ChatWin1;
}

class ChatWin1 : public QWidget
{
    Q_OBJECT

public:
    explicit ChatWin1(QWidget *parent = nullptr);
    ~ChatWin1();
    void setUsername(char * username);
private:
    Ui::ChatWin1 *ui;
    WriteThread * wt;
    ReadThread * rt;
    SocketConnect * sc;
    CHATMSG msg;
    PROTOCOL head;
    char buf[2000];
    char username[20];
private slots:

    void on_BtnSendmsg_clicked();

public slots:
    void FmrSendCres(CHATMSG * chatmsg);
};

#endif // CHATWIN1_H
