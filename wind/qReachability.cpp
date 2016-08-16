#include "qReachability.h"
#include <QDebug>
#include <QtNetwork/QHostInfo>
#include <QTimer>
#include "QDateTime"

qReachability::qReachability(QObject *parent) : QObject(parent)
{

}

void qReachability::initReachability()
{
       isConnect=true;
    QTimer *timer = new QTimer(this);
     connect(timer,SIGNAL(timeout()),this,SLOT(timerUpDate()));
     timer->start(1000);
}

void qReachability::timerUpDate()
{
    QDateTime time = QDateTime::currentDateTime();
    QString str = time.toString("yyyy-MM-dd hh:mm:ss dddd");
    network();

}
void qReachability::network()
{
    QHostInfo info =QHostInfo::fromName(QString("www.baidu.com"));

     if(info.addresses().isEmpty())
     {
           qDebug()<<"0000-无网络";
           isConnect=false;
     }else
     {
         if(!isConnect)
         {
             db.openDB();
             redisConfig.redisReconnection();
             isConnect=true;
         }
           qDebug()<<"1111-有网络";

     }
}


