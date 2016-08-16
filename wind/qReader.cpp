#include "qReader.h"
#include "QDebug"


qReader::qReader(QString host, int port)
{
    this->host = host;
    this->port = port;

    socket = new QTcpSocket;
    reading = false;

    connect(socket, SIGNAL(connected()), this, SLOT(socketConnected()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(socketConnectionClosed()));
    connect(socket, SIGNAL(readyRead()), this, SLOT(socketReadyRead()));
    connect(socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(socketError(QAbstractSocket::SocketError)));
}

qReader::~qReader()
{

    delete socket;
}




/**连接Ip
 * @brief qReader::connectHost
 * @param host
 * @param port
 */
void qReader::connectHost(const QString &host, quint16 port)
{
    if(reading)
        return;
    socket->connectToHost(host,port);
}

/**是否连接
 * @brief qReader::isConnected
 */
bool qReader::isConnected() const
{
    return reading;
}
/**断开连接
 * @brief qReader::disconnectHost
 */
void qReader::disconnectHost()
{
    socket->disconnectFromHost();
}
/**socket正在连接
 * @brief qReader::socketConnected
 */
void qReader::socketConnected()
{
    reading=true;
    emit connected();

}
/**socket正在关闭连接
 * @brief qReader::socketConnectionClosed
 */
void qReader::socketConnectionClosed()
{
    reading=false;
    emit disconnected();
}

/**接收数据
 * @brief qReader::socketReadyRead
 */
void qReader::socketReadyRead()
{
    QString reply("");
    reply.append(socket->readAll());
    readLine(reply);
}
/**Socket错误
 * @brief qReader::socketError
 */
void qReader::socketError(QAbstractSocket::SocketError e)
{
     emit error(e);

}
/**发送数据
 * @brief qReader::sendData
 * @param data
 */
void qReader::sendData(const QString &data)
{
    if(!reading)
        return;
    QTextStream stream(socket);

    QString test(data);
    int k;
    QChar c,next;
    QStringList parts;
    QString buffer="";
    bool open=false;
    for (k = 0; k < test.length(); k++) {

        c=test.at(k);//取数组的坐标
        if(open)
        {
            next=k<test.length()-1?test.at(k+1):' ';
         qDebug()<<next;
            if(c=='\\'&&next=='"')
            {
                buffer+='"';
                k++;

            }else if(c=='"')
           open=false;
            else
                buffer+=c;

        }else
        {
            if(!c.isSpace())//匹配空格字符  如果空白字或者空格字符串
            {
                if(c=='"')
                    open=true;
                else
                    buffer+=c;


            }else if(!buffer.isEmpty())//不为空
            {
                parts<<buffer;
               buffer="";

            }
        }
    }


    if(!buffer.isEmpty())
    {
        parts<<buffer;

    }
    QString bin="";
    bin.append(QString("*%1\r\n").arg(parts.length()));
    int i;
    for (i=0;i<parts.length(); i++) {

        bin.append(QString("$%1\r\n").arg(parts.at(i).length()));
       bin.append(QString("%1\r\n").arg(parts.at(i)));

    }
    stream<<bin;
    stream.flush();
}
/**在线读取
 * @brief qReader::readLine
 * @param reply
 */
void qReader::readLine(const QString &reply)
{
    QChar first=reply.at(0);
    QString value;
    QStringList result;
    if(first=='+')
    {
        value=reply.mid(1);//截取1后面的字符串
        value.chop(2);
        result<<"string"<<value;
    }else if(first=='-')
    {
        value=reply.mid(1);
        value.chop(2);
        result<<"error"<<value;

    }else if(first==':')
    {
        value=reply.mid(1);
        value.chop(2);
        result<<"integer"<<value;
    }else if(first=='$')
    {
        int index=reply.indexOf("\r\n");//从字符串里查找相同的某个字符串str
        int len=reply.mid(1,index-1).toInt();//截取1后面的几个字符
        if(len==-1)

            value="NULL";
        else
            value=reply.mid(index+2,len);
            result<<"bulk"<<value;

    }else if(first=='*')
    {
        int index=reply.indexOf("\r\n");
        int count=reply.mid(1,index-1).toInt();
        int i;
        int len;
        int pos=index+2;
        result<<"list";
        for (i= 0; i < count; i++) {

            index=reply.indexOf("\r\n",pos);
            len=reply.mid(pos+1,index-pos-1).toInt();
            if(len==-1)

                result<<"NULL";
            else
                result<<reply.mid(index+2,len);
            pos=index+2+len+2;
        }

    }
    emit  response(result);


}


