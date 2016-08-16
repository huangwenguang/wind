#include "qReadisExample.h"
#include <QDebug>
#include <QTime>
#include "qNetWork.h"
#include "qGlobals.h"



qReadisTest::qReadisTest(QObject *parent) : QObject(parent)
{

}

qReadisTest::~qReadisTest()
{

}
void qReadisTest::start()
{
  jsonObject=new qJsonObject(this);
    jsonObject->readJson();
    QObject::connect(jsonObject, SIGNAL(returnData1(QString)), this, SLOT(slot_receive(QString)));
}

void qReadisTest::slot_receive(QString result)
{

     qGlobals::jsonFile=result;
      if(result.length()>0)
      {
          QTime qt;
          qt.start();
          qDebug()<<QString("start widnA");
          reach.initReachability();

          if(!db.createConnection()) return;
          QTime ret;
          ret.start();
          qDebug()<<QString("redis");
          redis=redisConfig.redisReconnection();
          qDebug()<<QString("end redis启动使用了多少毫秒_%1 ms").arg(ret.elapsed());
          QTime jsont;
          jsont.start();
          qDebug()<<QString("start json数据");
          db.addDataRedis(redis);
          qDebug()<<QString("end插入json数据使用多少毫秒_%1 ms%1").arg(jsont.elapsed());
          qDebug()<<QString("end widnA _%1 ms").arg(qt.elapsed());

      }
      // qDebug()<<result;
      // return  byteArray;
}


