/********************************************************************************
** Form generated from reading UI file 'loginwin.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWIN_H
#define UI_LOGINWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWin
{
public:
    QWidget *centralwidget;
    QPushButton *BtnOK;
    QPushButton *BtnRgs;
    QPushButton *BtnCancel;
    QLineEdit *Editusrid;
    QLineEdit *Editusrpwd;
    QLabel *labusrid;
    QLabel *labusrpwd;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LoginWin)
    {
        if (LoginWin->objectName().isEmpty())
            LoginWin->setObjectName(QStringLiteral("LoginWin"));
        LoginWin->resize(470, 331);
        centralwidget = new QWidget(LoginWin);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        BtnOK = new QPushButton(centralwidget);
        BtnOK->setObjectName(QStringLiteral("BtnOK"));
        BtnOK->setGeometry(QRect(70, 190, 89, 25));
        BtnRgs = new QPushButton(centralwidget);
        BtnRgs->setObjectName(QStringLiteral("BtnRgs"));
        BtnRgs->setGeometry(QRect(180, 190, 89, 25));
        BtnCancel = new QPushButton(centralwidget);
        BtnCancel->setObjectName(QStringLiteral("BtnCancel"));
        BtnCancel->setGeometry(QRect(290, 190, 89, 25));
        Editusrid = new QLineEdit(centralwidget);
        Editusrid->setObjectName(QStringLiteral("Editusrid"));
        Editusrid->setGeometry(QRect(170, 80, 191, 31));
        Editusrpwd = new QLineEdit(centralwidget);
        Editusrpwd->setObjectName(QStringLiteral("Editusrpwd"));
        Editusrpwd->setGeometry(QRect(170, 130, 191, 31));
        labusrid = new QLabel(centralwidget);
        labusrid->setObjectName(QStringLiteral("labusrid"));
        labusrid->setGeometry(QRect(80, 90, 67, 17));
        labusrpwd = new QLabel(centralwidget);
        labusrpwd->setObjectName(QStringLiteral("labusrpwd"));
        labusrpwd->setGeometry(QRect(80, 140, 67, 17));
        LoginWin->setCentralWidget(centralwidget);
        menubar = new QMenuBar(LoginWin);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 470, 28));
        LoginWin->setMenuBar(menubar);
        statusbar = new QStatusBar(LoginWin);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        LoginWin->setStatusBar(statusbar);

        retranslateUi(LoginWin);

        QMetaObject::connectSlotsByName(LoginWin);
    } // setupUi

    void retranslateUi(QMainWindow *LoginWin)
    {
        LoginWin->setWindowTitle(QApplication::translate("LoginWin", "MainWindow", Q_NULLPTR));
        BtnOK->setText(QApplication::translate("LoginWin", "\347\231\273\345\275\225", Q_NULLPTR));
        BtnRgs->setText(QApplication::translate("LoginWin", "\346\263\250\345\206\214", Q_NULLPTR));
        BtnCancel->setText(QApplication::translate("LoginWin", "\345\217\226\346\266\210", Q_NULLPTR));
        labusrid->setText(QApplication::translate("LoginWin", "\345\270\220\345\217\267", Q_NULLPTR));
        labusrpwd->setText(QApplication::translate("LoginWin", "\345\257\206\347\240\201", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LoginWin: public Ui_LoginWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWIN_H
