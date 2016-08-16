#ifndef QREACHABILITY_H
#define QREACHABILITY_H

#include <QObject>
#include "qDbManager.h"
#include "qRedisConfig.h"

class qReachability : public QObject
{
    Q_OBJECT
public:
    explicit qReachability(QObject *parent = 0);
    void network();
    void initReachability();

signals:

public slots:
      void timerUpDate();
private:
      bool isConnect;
      qDbManager db;
       qRedisConfig redisConfig;
};

#endif // QREACHABILITY_H
