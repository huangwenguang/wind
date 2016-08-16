#ifndef QNETWORK_H
#define QNETWORK_H

#include <QObject>
#include <QUrl>

class QFile;
class QNetworkReply;
class QNetworkAccessManager;

class qNetWork : public QObject
{
    Q_OBJECT
public:

      explicit qNetWork(QObject *parent = 0);
     ~qNetWork();
      void   startRequest(QString url);
      QString result;

signals:
      void returnData(QString result);

public slots:
    void  replyFinished(QNetworkReply *);

private:
    QNetworkAccessManager *manager;
    QNetworkReply *reply;
    QString strurl;
    QString m_result;

};

#endif // QNETWORK_H
