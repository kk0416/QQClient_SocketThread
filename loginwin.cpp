#include "loginwin.h"
#include "ui_loginwin.h"

LoginWin::LoginWin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginWin)
{
    ui->setupUi(this);
    //初始化单例类对象\聊天窗口\数组\信号和槽
    this->sc=SocketConnect::getInstance();
    this->rt=ReadThread::getInstance(this->sc->getSocketfd());
    this->wt=WriteThread::getInstance(this->sc->getSocketfd());
    this->chatWin=new ChatWin1();
    memset(this->buf,0,sizeof(this->buf));

    connect(this->rt,SIGNAL(SendSign(int)),this,SLOT(FmrCheckres(int)));
}

LoginWin::~LoginWin()
{
    delete ui;
}
//
void LoginWin::FmrCheckres(int flag)
{
    if(flag==1)//登录成功
    {
        QMessageBox::information(NULL,"title","登录成功！");
        //登录成功后把当前用户名传给聊天界面
        this->chatWin->setUsername(user.username);

        this->hide();
        this->chatWin->show();
    }
    else if(flag==0)
    {
        //此处应该根据服务端验证结果进行提示，看是什么原因（帐号密码错误，用户不存在）
        QMessageBox::information(NULL,"title","登录错误");
    }

}

//将通信协议头和用户信息写给服务器＼打通网络＼开启读写线程＼将数据传给写线程
void LoginWin::on_BtnOK_clicked()
{
    //临时变量接收用户帐号密码，后续转为ｃｈａｒ型
    QString usrname=ui->Editusrid->text();
    QString usrpwd=ui->Editusrpwd->text();
    if(usrname.length()>0&&usrpwd.length()>0)
    {
        const char *pusrname=usrname.toStdString().c_str();
        const char *pusrpwd=usrpwd.toStdString().c_str();
        //赋给用户信息结构体属性
        memcpy(this->user.username,pusrname,sizeof (pusrname));
        memcpy(this->user.userpwd,pusrpwd,sizeof (pusrpwd));

        qDebug()<<"user.username = "<<user.username;
        qDebug()<<"user.password = "<<user.userpwd;
        qDebug()<<"sizeof(head.businesslen) = "<< sizeof(this->user);

        this->pro.businesstype=1;
        this->pro.businesslength=sizeof (this->user);
        qDebug()<<"pro.businesslength = "<<this->pro.businesslength;
        memset(buf,0,sizeof (buf));
        memcpy(this->buf,&(this->pro),sizeof(PROTOCOL));
        qDebug()<<"sizeof(this->pro) = "<<sizeof(this->pro);
        qDebug()<<"bufsize1 = "<<sizeof (buf);
        memcpy(this->buf+sizeof(PROTOCOL),&(this->user),sizeof(this->user));//指针偏移，存两个结构体
        qDebug()<<"sizeof(this->user) = "<<sizeof(this->user);
        qDebug()<<"bufsize = "<<sizeof (buf);

        this->sc->CreateConnect();//初始化网络
        this->rt->start();
        this->wt->setData(&(this->buf),sizeof(this->buf));//要发送的数据传给写线程进行ｗｒｉｔｅ
        this->wt->start();

    }
}

void LoginWin::on_BtnCancel_clicked()
{
    this->sc->Close();
    this->close();
}
