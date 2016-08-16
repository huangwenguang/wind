#include "qRedisConfig.h"
#include "QTime"

qRedisConfig::qRedisConfig(QObject *parent) : QObject(parent)
{

}
qRedisConfig::~qRedisConfig()
{
    delete redis;
}
void qRedisConfig::slotMessage(qRedis::Reply reply)
{
    QTime time;
    qDebug() << time.currentTime();
    qDebug() << "Channel:" << reply.channel << "Pattern:" << reply.pattern;
    qDebug() << reply.value.toString();
}


//qRedis::Reply qRedis::
/**redis连接
 * @brief MainWindow::redisReconnection
 */
qRedis* qRedisConfig::redisReconnection()
{

    qDebug()<<QObject::tr("reids start");

    m_redismap=jsonParsing.setMap(K_redis_host);
    redis = new qRedis(m_redismap[K_redis_ip_url],m_redismap[K_redis_port].toInt());
    connect(redis, SIGNAL(returnData(qRedis::Reply)), this, SLOT(slotMessage(qRedis::Reply)));
    if (!redis->openConnection())
    {
        qDebug() << "Could not connect to server...reids";
    }

    qDebug() << "Connected to server...redis";
    return redis;

}



//192.168.169.128  ubuntu
//192.168.169.129  win7
//www.huangwenguang.com   CenOS
//192.168.2.235   win10
//192.168.1.123   mac
// redisObjects.take(K_ip_url).toString()


