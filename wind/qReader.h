#ifndef QREADER_H
#define QREADER_H

#include <QObject>
#include <QVariant>
#include <QStringList>
#include <QTcpSocket>
#include <QSocketNotifier>
#include <QByteArray>

class qReader : public QObject
{
    Q_OBJECT
public:
     qReader(QString host, int port);
   // explicit qReader(QObject *parent = 0);
     ~qReader();
       void connectHost(const QString &host, quint16 port);
          bool isConnected() const;
           void disconnectHost();


signals:
        void response(QVariant);
        void connected();
        void disconnected();
         void error(QAbstractSocket::SocketError);




public slots:
       void socketConnected();
       void socketConnectionClosed();
      void socketReadyRead();
       void socketError(QAbstractSocket::SocketError);
       void sendData(const QString &);
        void readLine(const QString &); // const 保护被修饰的变量，防止程序中意外修改
   private:
     QString host;  //IP
     int port;      //端口
     QTcpSocket *socket;
     bool reading; //是否正在读取
};

#endif // QREADER_H
