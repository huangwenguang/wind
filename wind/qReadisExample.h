#ifndef qReadisTest_H
#define qReadisTest_H

#include <QObject>
#include <QSqlDatabase>

#include "qRedis.h"

#include "QMap"
#include "qDbManager.h"
#include "qJsonParsing.h"
#include "qRedisConfig.h"
#include "qReachability.h"
#include "qJsonObject.h"




class qReadisTest : public QObject
{
    Q_OBJECT
public:
    explicit qReadisTest(QObject *parent = 0);
    ~qReadisTest();
    void start();

signals:

public slots:
     void slot_receive(QString result);

private:
      qRedis *redis;
      qDbManager db;
      qJsonParsing jsonParsing;
      qRedisConfig redisConfig;
      qReachability reach;
      qJsonObject *jsonObject;



};

#endif // qReadisTest_H
