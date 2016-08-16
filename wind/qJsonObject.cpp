#include "qJsonObject.h"
#include "QJsonObject"
#include "QJsonArray"
#include "QByteArray"
#include "QJsonParseError"
#include "QJsonDocument"
#include <QDebug>
#include "QFile"
#include <QtNetwork>
#include "qConfig.h"
#include "qGlobals.h"



//static QString fileNameP="D:\\youyong\\data1.txt"; //win
static QString jsonFile="//Users//wenguanghuang//Documents//work//QT//config.json"; //mac

qJsonObject::qJsonObject(QObject *parent) : QObject(parent)
{

}

/**获取key的数组值
 * @brief qJsonObject::getArrayValuebyKey
 * @param key
 * @return
 */
QJsonArray qJsonObject::getArrayValuebyKey(QString key)
{
    QJsonArray jsonArray;
    QStringList keyList=key.split(QString::SplitBehavior::SkipEmptyParts);
    byteArray=qGlobals::jsonFile.toLatin1();
    if(byteArray.length()==0)
    {
        readJson();
    }
    jsonArray=getArrayLastValueByKey(keyList,byteArray);
     return jsonArray;
}
void qJsonObject::slot_receive(QString result)
{
     m_result=result;
     qGlobals::jsonFile=m_result;
     emit returnData1(m_result);
}
QJsonArray qJsonObject::getArrayLastValueByKey(QStringList keyList, QByteArray byteArray)
{

    QJsonArray jsonArray;
    QJsonParseError json_error;
    QJsonDocument pare_doucment=QJsonDocument::fromJson(byteArray,&json_error);
    if(json_error.error==QJsonParseError::NoError)
    {
        if(!pare_doucment.isEmpty()||pare_doucment.isNull())
        {
            QJsonObject jsonObject=pare_doucment.object();
            jsonArray=jsonObject.value(keyList.at(0)).toArray();
        }
    }
      return jsonArray;
}
/**获取key的值
 * @brief qJsonObject::getObjectValueByKey
 * @param key
 * @return
 */
QJsonValue qJsonObject::getObjectValueByKey(QString key)
{

    QStringList keyList=key.split("/",QString::SplitBehavior::SkipEmptyParts);
    byteArray=qGlobals::jsonFile.toLatin1();
    if(byteArray.length()==0)
    {
      readJson();
    }
   QJsonValue jsonValue=getLastObjectValueByKey(keyList,byteArray);
     return jsonValue;
}
QJsonValue qJsonObject::getLastObjectValueByKey(QStringList key, QByteArray byteArray)
{
    QJsonValue key_value;
    QJsonParseError json_error;
    QJsonDocument pare_doucment=QJsonDocument::fromJson(byteArray,&json_error);
    if(json_error.error==QJsonParseError::NoError)
    {
        if(!pare_doucment.isEmpty()||pare_doucment.isNull())
        {
       if(pare_doucment.isObject())
       {
           QJsonObject obj = pare_doucment.object();

           if(obj.contains(key.at(0)))
           {
        key_value = obj.take(key.at(0));
      // qDebug()<<QString("key_value--%1").arg(key_value.toString());
        }
        }

    }
    }
     return key_value;

}


/**读取网络url，返回json格式
 * @brief qJsonObject::readJson
 * @return
 */
void qJsonObject::readJson()
{
    netWork=new qNetWork(this);
    netWork->startRequest(K_jsonURL);
    QObject::connect(netWork, SIGNAL(returnData(QString)), this, SLOT(slot_receive(QString)));


}

/**读取本地config.json文件
 * @brief qJsonObject::readJson
 * @return
 */
QByteArray qJsonObject::readJsonFile()
{
    QByteArray byte_array;
  QFile *file=new QFile(jsonFile);
  bool isNotExist=!file->exists();
  if(isNotExist)
  {
      qDebug()<<"file not exist";

  }
  if(!file->open(QIODevice::ReadOnly))
  {
    qDebug()<<"file jsonFile.json error";
  }
  byte_array=file->readAll();
  file->close();

   return  byte_array;
}

/**读取数组
 * @brief qReadisTest::getDbNames
 * @param key
 * @return
 */
QVector<QString> qJsonObject::getArray(QString key)
{
    QJsonArray jsonArray=getArrayValuebyKey(key);
    int total=jsonArray.count();
       QVector<QString> strArrays;
    for (int i = 0; i < total; i++) {
        QString value =jsonArray.at(i).toString();
         strArrays.append(value);
    }
 return   strArrays;
}

