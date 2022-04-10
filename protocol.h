#ifndef PROTOCOL_H
#define PROTOCOL_H

/*请求包通信协议头*/
typedef struct protocolHead
{
    int businesstype;//业务类型 1：登录 2：聊天
    int businesslength;//业务长度 登录：40 聊天：140
}PROTOCOL;
/*请求包通信协议体*/
//登录
typedef struct userinfp
{
    char username[40];//用户名
    char userpwd[40];//用户密码
}USERINFO;
//聊天
typedef struct chatmsg
{
    char senid[20];//"我是谁"-要发送消息的客户端所对应的编号
    char rcvid[20];//"跟谁聊"-接收信息的客户端的acceptfd
    char content[500];//"聊什么"-传递的数据
}CHATMSG;
/*反馈包通信协议头*/
typedef struct feedbackHead
{
    int businesstype;//业务类型 1：登录 2：聊天
    int businesslenth;//业务长度 登录：40 聊天：140
    int flag;//flag判断是否登录成功
}FEEDBACK;


#endif // PROTOCOL_H
