#ifndef QREDISCONFIG_H
#define QREDISCONFIG_H

#include <QObject>
#include "qJsonParsing.h"
#include "qConfig.h"
#include "qRedis.h"

class qRedisConfig : public QObject
{
    Q_OBJECT
public:
    explicit qRedisConfig(QObject *parent = 0);
~qRedisConfig();
    qRedis* redisReconnection();

signals:


public slots:
    void slotMessage(qRedis::Reply);
private:
       qJsonParsing jsonParsing;
       QMap<QString,QString> m_redismap;
       QMap<QString,QString> m_dbmap;
       qRedis *redis;
};

#endif // QREDISCONFIG_H
