#ifndef QDBMANAGER_H
#define QDBMANAGER_H

#include <QObject>
#include <QSqlDatabase>
#include "QVector"
#include "qJsonObject.h"
#include "qJsonParsing.h"
#include "qRedis.h"
#include "qReader.h"

class qDbManager : public QObject
{
    Q_OBJECT
public:
    explicit qDbManager(QObject *parent = 0);
      ~qDbManager();
    bool createConnection();
    void openDB();
    void closeDB();
    void addDataRedis(qRedis *redis);
    void addText(int dbindex,const QString &type);
    QVector<QString> tabelName(const QString &db);
    void getselect();
    QVector<QSqlDatabase> createDBArray();
    void selectDateFrist(const QString &dbName,const QSqlDatabase &db,const QString &type);
    void selectDateSeconde(const QString &dbName,const QSqlDatabase &db,const QString &type);





signals:

public slots:
    public:
    QSqlDatabase AUDJPY;
    QSqlDatabase AUDNZD;
    QSqlDatabase AUDUSD;
    QSqlDatabase BUND;
    QSqlDatabase CADCHF;


    QSqlDatabase COPPER;
    QSqlDatabase EURAUD;
    QSqlDatabase EURCAD;
    QSqlDatabase EURCHF;
    QSqlDatabase EURGBP;

    QSqlDatabase EURJPY;
    QSqlDatabase EURNZD;
    QSqlDatabase EURUSD;
    QSqlDatabase GBPAUD;
    QSqlDatabase GBPCAD;
    QSqlDatabase GBPCHF;
    QSqlDatabase GBPJPY;
    QSqlDatabase GBPNZD;
    QSqlDatabase GBPUSD;
    QSqlDatabase NGAS;

    QSqlDatabase NZDCAD;
    QSqlDatabase NZDCHF;
    QSqlDatabase NZDJPY;
    QSqlDatabase NZDUSD;
    QSqlDatabase UKOIL;
    QSqlDatabase USDCAD;
    QSqlDatabase USDCHF;
    QSqlDatabase USDCNH;
    QSqlDatabase USDHKD;
    QSqlDatabase USDJPY;

    QSqlDatabase USDMXN;
    QSqlDatabase USDNOK;
    QSqlDatabase USDSEK;
    QSqlDatabase USDTRY;
    QSqlDatabase USDZAR;
    QSqlDatabase USOIL;
    QSqlDatabase XAGUSD;
    QSqlDatabase XAUUSD;
    QSqlDatabase XPDUSD;
    QSqlDatabase XPTUSD;

   qJsonObject jsonUtil;
   qJsonParsing jsonParsing;
   QMap<QString,QString> m_redismap;
   QMap<QString,QString> m_dbmap;
   QMap<QString,QString> m_mysqlmap;

   QString strJson;
    qRedis *m_redis;
     qReader *reader;

};

#endif // QDBMANAGER_H
