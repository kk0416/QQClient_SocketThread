/********************************************************************************
** Form generated from reading UI file 'chatwin1.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATWIN1_H
#define UI_CHATWIN1_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatWin1
{
public:
    QListWidget *listWidget;
    QTextEdit *EditShowmsg;
    QTextEdit *EditSendmsg;
    QPushButton *BtnSendmsg;

    void setupUi(QWidget *ChatWin1)
    {
        if (ChatWin1->objectName().isEmpty())
            ChatWin1->setObjectName(QStringLiteral("ChatWin1"));
        ChatWin1->resize(862, 572);
        listWidget = new QListWidget(ChatWin1);
        QIcon icon;
        icon.addFile(QStringLiteral("../QQChatClient_t/img/1003.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        QFont font;
        font.setFamily(QStringLiteral("Waree"));
        font.setPointSize(20);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(listWidget);
        __qlistwidgetitem->setFont(font);
        __qlistwidgetitem->setIcon(icon);
        QIcon icon1;
        icon1.addFile(QStringLiteral("../QQChatClient_t/img/1002.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem1 = new QListWidgetItem(listWidget);
        __qlistwidgetitem1->setFont(font);
        __qlistwidgetitem1->setIcon(icon1);
        QIcon icon2;
        icon2.addFile(QStringLiteral("../QQChatClient_t/img/1001.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem2 = new QListWidgetItem(listWidget);
        __qlistwidgetitem2->setFont(font);
        __qlistwidgetitem2->setIcon(icon2);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(10, 10, 256, 351));
        EditShowmsg = new QTextEdit(ChatWin1);
        EditShowmsg->setObjectName(QStringLiteral("EditShowmsg"));
        EditShowmsg->setGeometry(QRect(280, 10, 421, 351));
        EditSendmsg = new QTextEdit(ChatWin1);
        EditSendmsg->setObjectName(QStringLiteral("EditSendmsg"));
        EditSendmsg->setGeometry(QRect(280, 370, 421, 171));
        BtnSendmsg = new QPushButton(ChatWin1);
        BtnSendmsg->setObjectName(QStringLiteral("BtnSendmsg"));
        BtnSendmsg->setGeometry(QRect(80, 500, 89, 25));

        retranslateUi(ChatWin1);

        QMetaObject::connectSlotsByName(ChatWin1);
    } // setupUi

    void retranslateUi(QWidget *ChatWin1)
    {
        ChatWin1->setWindowTitle(QApplication::translate("ChatWin1", "Form", Q_NULLPTR));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("ChatWin1", "1001", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("ChatWin1", "1002", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem2 = listWidget->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("ChatWin1", "1003", Q_NULLPTR));
        listWidget->setSortingEnabled(__sortingEnabled);

        BtnSendmsg->setText(QApplication::translate("ChatWin1", "\345\217\221\351\200\201", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ChatWin1: public Ui_ChatWin1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATWIN1_H
