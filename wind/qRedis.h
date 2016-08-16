#ifndef QREDIS_H
#define QREDIS_H

#include <QObject>
#include "qReader.h"
#include <QStringList>
#include <QEventLoop>
class qRedis : public QObject
{
    Q_OBJECT
public:
    explicit qRedis(QString host,int port,QObject *parent=0);
    ~qRedis();
    typedef struct Reply
    {
        QString type;
        QString message;
        QString pattern;
        QString channel;
        QVariant value;
    }Reply;

    bool openConnection();
    bool closeConnection();
    bool isConnected();

    void publish(QString,QString);//发布
    void subscribe(QString);//订阅
    void unsubscribe(QString);//取消订阅
    void psubscribe(QString);//匹配模式订阅
      void punsubscribe(QString);//匹配模式取消订阅

    Reply command(QString);
  int append(QString key, QString value);
    int lpush(QString key, QString value);

      bool exists(QString key);
      QString get(QString key);
      bool set(QString key, QString value);


signals:
   void disconnected();
   void connected();
   void returnData(qRedis::Reply);

public slots:
    void connectHost(const QString &host,const quint16 port=6379);
    void disconnectHost();
private slots:
    void slotConnected();
    void slotDisconnected();
    void response(QVariant);



private:
    qReader *reader;
    QString host;
       int port;
      QStringList responseData;


};

#endif // QREDIS_H
