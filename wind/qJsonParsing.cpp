#include "qJsonParsing.h"
#include "QJsonObject"
#include "QJsonArray"
#include "QByteArray"
#include "QJsonParseError"
#include "QJsonDocument"
#include <QDebug>
#include "qConfig.h"

qJsonParsing::qJsonParsing()
{

}

/*jsonobject数据解析封装成map
 * @brief qJsonParsing::setJson
 * @param key
 * @return map
 */
QMap<QString,QString> qJsonParsing::setMap(QString key)
{

    QJsonValue key_value=jsonUtil.getObjectValueByKey(key);
      // qDebug()<<QString("Redis_host--%1").arg(key_value.toString());
   QStringList strlist=key_value.toString().split(":");
   int listCount=strlist.size();
      QMap<QString,QString> m_map;

    for (int i = 0; i < listCount; i++)
    {
      QString value=strlist[i];
        // qDebug()<<QString("value--%1").arg(value);
         if(key==K_redis_host)
         {
             if(i==0)
             {
                 m_map.insert(K_redis_ip_url, value);
             }
             if(i==1)
             {
                 m_map.insert(K_redis_port, value);
             }

         }
         if(key==K_mysql_conn)
         {
             if(i==0)
             {
                 m_map.insert(K_userName, value);
             }
             if(i==1)
             {
                 m_map.insert(K_pwd, value);
             }
             if(i==2)
             {
                 m_map.insert(K_mysql_hostName, value);
             }
             if(i==3)
             {
                 m_map.insert(K_mysql_port, value);
             }

         }
    }

    return  m_map;

}


/**array数组解析封装成map
 * @brief qJsonParsing::setJson
 * @param key
 * @return map
 */
QMap<QString,QString> qJsonParsing::setMapArrsy(QString key)
{

    QJsonArray array=jsonUtil.getArrayValuebyKey(key);
      // qDebug()<<QString("Redis_host--%1").arg(key_value.toString());

   int listCount=array.size();
      QMap<QString,QString> m_map;

    for (int i = 0; i < listCount; i++)
    {
      QString value=array.at(i).toString();

         if(key==K_dbName)
         {
               m_map.insert(value, value);
         }
    }

    return  m_map;

}
