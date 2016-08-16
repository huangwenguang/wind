#include "qRedis.h"

qRedis::qRedis(QString host,int port, QObject *parent) : QObject(parent)
{
    this->host=host;
    this->port=port;
    reader=new qReader(host,port);
    connect(reader,SIGNAL(response(QVariant)),this,SLOT(response(QVariant)));

}


qRedis::~qRedis()
{
   delete reader;
}

/**打开连接
 * @brief qRedis::openConnection
 * @return
 */
bool qRedis::openConnection()
{
  connectHost(host,port);
  QEventLoop loop;
  connect(reader,SIGNAL(connected()),&loop,SLOT(quit()));
  loop.exec();
  if(!reader->isConnected())
  {
     return false;

  }
  return true;
}

/**连接Ip
 * @brief qRedis::connectHost
 * @param host
 * @param port
 */
void qRedis::connectHost(const QString &host, const quint16 port)
{
    reader->connectHost(host,port);
    connect(reader,SIGNAL(connected()),this,SLOT(slotConnected()));

}

/**断开连接
 * @brief qRedis::disconnectHost
 */
void qRedis::disconnectHost()
{
 reader->disconnectHost();
}
/**连接槽
 * @brief qRedis::slotConnected
 */
void qRedis::slotConnected()
{
    connect(reader,SIGNAL(disconnected()),this,SLOT(slotDisconnected()));
         emit connected();
}
/**断开槽
 * @brief qRedis::slotDisconnected
 */
void qRedis::slotDisconnected()
{
    emit disconnected();

}
/**Redis Public API
 * @brief qRedis::publish
 * @param channel 通道
 * @param message 消息
 */
void qRedis::publish(QString channel, QString message)
{
    QString cmd;
    cmd.append("PUBLISH ");
    cmd.append(channel);
    cmd.append(" ");
    cmd.append(message);
    reader->sendData(cmd);


}

/**响应
 * @brief qRedis::response
 * @param response
 */
void qRedis::response(QVariant response)
{
    QStringList res=response.toStringList();
    Reply reply;
    if(res[1]=="message")
    {
        reply.type=res[0];
        reply.message=res[1];
        reply.channel=res[2];
        reply.value=res[3];
        emit returnData(reply); //返回数据
    }else if(res[1]=="")
    {
        reply.type=res[0];
         reply.message=res[1];
         reply.pattern=res[2];//模式
         reply.channel=res[3];
         reply.value=res[4];
         emit returnData(reply);

    }else
    {
        responseData=res;
    }

}

/**命令
 * @brief qRedis::command
 * @param cmd
 * @return
 */
qRedis::Reply qRedis::command(QString cmd)
{
    Reply reply;
    reader->sendData(cmd);
    QEventLoop  loop;//QEventLoop类为我们提供了一种进入和退出事件循环的方法。在任何时候，你都可以创建一个QEventLoop实例，并通过调用exec()来启动一个事件循环。在循环期间，主动调用exit()可以使exec()强制返回
    connect(reader,SIGNAL(response(QVariant)),&loop,SLOT(quit()));
    loop.exec();
    if(responseData[0]=="integer")
    {
        reply.type=responseData[0];
        reply.value=responseData[1].toInt();
    }else if(responseData[0]=="list")
    {
        reply.type=responseData[0];
        QStringList list;
        for (int i = 0;  i< responseData.length(); i++) {
            list<<responseData[i];
        }
        reply.value=list;

    }else
    {
        reply.type=responseData[0];
        reply.value=responseData[1];
    }
    return reply;

}


/**追加字符串
 * @brief qRedis::append
 * @param key
 * @param value
 * @return
 */
int qRedis::append(QString key, QString value)
{
    QString cmd("APPEND ");
    cmd.append(key);
    cmd.append(" ");
    cmd.append(value);
    Reply reply=command(cmd);
    return reply.value.toInt();
}
int qRedis::lpush(QString key, QString value)
{
    QString cmd("LPUSH ");
    cmd.append(key);
    cmd.append(" ");
    cmd.append(value);
    Reply reply=command(cmd);
    return reply.value.toInt();
}

/**key 是否存在
 * @brief qRedis::exists
 * @param key
 * @return
 */
bool qRedis::exists(QString key)
{
    QString cmd("EXISTS ");
    cmd.append(key);
    Reply reply=command(cmd);
    return reply.value.toBool();
}
/**获得key
 * @brief qRedis::get
 * @param key
 */
QString qRedis::get(QString key)
{
    QString cmd("GET ");
    cmd.append(key);
    Reply reply=command(cmd);

    return reply.value.toString();

}
bool qRedis::set(QString key, QString value)
{
    QString cmd("SET ");
    cmd.append(key);
    cmd.append(" ");
    cmd.append(value);

    Reply reply = command(cmd);

    if(reply.value.toString() == "OK")
        return true;

    return false;


}

