#include "chatwin1.h"
#include "ui_chatwin1.h"

ChatWin1::ChatWin1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChatWin1)
{
    ui->setupUi(this);
    ui->EditShowmsg->setFocusPolicy(Qt::NoFocus);//当前文本框（聊天内容显示框）失去焦点，不可编辑
    ui->listWidget->setIconSize(QSize(70,70));//图标大小
    this->sc = SocketConnect::getInstance();
    this->wt = WriteThread::getInstance(this->sc->getSocketfd());
    this->rt = ReadThread::getInstance(this->sc->getSocketfd());
    memset(this->buf,0,sizeof(this->buf));
    connect(this->rt,SIGNAL(SendChatmsg(CHATMSG*)),this,SLOT(FmrSendCres(CHATMSG *)));
}

ChatWin1::~ChatWin1()
{
    delete ui;
}

void ChatWin1::setUsername(char *username)
{
    strcpy(this->username,username);
}

void ChatWin1::FmrSendCres(CHATMSG * chatmsg)
{
    qDebug()<<"FmrSendCres chatmsg->senid="<<chatmsg->senid;
    qDebug()<<"FmrSendCres chatmsg->rcvid="<<chatmsg->rcvid;

    if(strcmp(chatmsg->senid,this->username)==0)//如果该帐号和聊天发送者一致
    {
        QString send="我说：";
        QString content=QString(chatmsg->content);
        send+=content;
        qDebug()<<"chatwin f11 ----chatmsg->senid="<<chatmsg->senid;

        qDebug()<<"chatwin f11 ----chatmsg->content="<<chatmsg->content;
        ui->EditShowmsg->append(send);//?append意思

    }
    else if (strcmp(chatmsg->rcvid,this->username)==0)
    {
        QString send = QString(chatmsg->senid);
        QString mid=" 对我说:";
        QString cont = QString(chatmsg->content);
        qDebug()<<"chatwin f11 ----chatmsg->senid="<<send;
        qDebug()<<"chatwin f22 ----chatmsg->content="<<chatmsg->content;
        send+=mid;
        send+=cont;
        ui->EditShowmsg->append(send);
    }
     qDebug()<<"cstrcmp(chatmsg->rcvid,this->username==1";
    update();//??
}

void ChatWin1::on_BtnSendmsg_clicked()
{
    const char *arr=ui->listWidget->currentItem()->text().toStdString().c_str();//获取点击图元的帐号？
    QString Sendtext=ui->EditSendmsg->document()->toPlainText();//?
    memcpy(msg.rcvid,arr,sizeof(msg.rcvid));//将选中要聊天的用户帐号传给聊天结构体的接收者
    memcpy(msg.senid,this->username,sizeof (msg.senid));
    memcpy(msg.content,Sendtext.toStdString().c_str(),sizeof (msg.content));

    this->head.businesstype=2;
    this->head.businesslength=sizeof (this->msg);
    qDebug()<<"head.businesstype(2) = "<<head.businesstype;
    qDebug()<<"on_BtnSendmsg_clicked sizeof (this->msg)="<<sizeof (this->msg);
    //传递头和聊天信息给ｂｕｆ
    memcpy(this->buf,&(this->head),sizeof (this->head));
    memcpy(this->buf+sizeof (this->head),&(this->msg),sizeof (this->msg));
    qDebug()<<"on_BtnSendmsg_clicked strlen (this->buf)="<<strlen (this->buf);
    //将ｂｕｆ传给写线程去ｗｒｉｔｅ
    this->wt->setData(&(this->buf),sizeof (this->buf));

    //清空输入窗口
    ui->EditSendmsg->setPlainText("");


}
