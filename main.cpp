#include "chatwin1.h"
#include <QApplication>
#include "loginwin.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    LoginWin w;
//    ChatWin1 w;
    w.show();

    return a.exec();
}
