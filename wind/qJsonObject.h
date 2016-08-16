#ifndef JSONOBJECT_H
#define JSONOBJECT_H

#include <QObject>
#include "QVector"
#include "qNetWork.h"

class qJsonObject : public QObject
{
    Q_OBJECT
public:
    explicit qJsonObject(QObject *parent = 0);

    QJsonArray getArrayValuebyKey(QString key);
    QJsonArray getArrayLastValueByKey(QStringList keyList,QByteArray byteArray);
    QJsonValue getObjectValueByKey(QString key);
    QJsonValue getLastObjectValueByKey(QStringList key,QByteArray byteArray);
    void readJson();
    QVector<QString> getArray(QString key);
    QByteArray readJsonFile();

signals:
          void returnData1(QString result);

public slots:
     void slot_receive(QString result);
private:
    QByteArray byteArray;
    qNetWork *netWork;
    QString m_result;
};

#endif // JSONOBJECT_H
