#include "qDbManager.h"
#include <QTimer>
#include <QTime>
#include <QtSql>
#include <QSqlQuery>
#include "qConfig.h"


qDbManager::qDbManager(QObject *parent) : QObject(parent)
{

}
qDbManager::~qDbManager()
{
     delete m_redis;
}

/**连接数据库
 * @brief qReadisTest::createConnection
 * @return
 */
bool qDbManager::createConnection()
{

     QTime dbt;
     dbt.start();
     qDebug()<<QString("start db");
     m_dbmap=jsonParsing.setMapArrsy(K_dbName);
     m_mysqlmap=jsonParsing.setMap(K_mysql_conn);
   //3
     AUDJPY=QSqlDatabase(QSqlDatabase::addDatabase(K_qMYSQL,m_dbmap[K_AUDJPY]));
     AUDJPY.setHostName(m_mysqlmap[K_mysql_hostName]);
     AUDJPY.setPort(m_mysqlmap[K_mysql_port].toInt());
     AUDJPY.setDatabaseName(m_dbmap[K_AUDJPY]);
     AUDJPY.setUserName( m_mysqlmap[K_userName] );
     AUDJPY.setPassword(m_mysqlmap[K_pwd] );
    if (!AUDJPY.open())
    {
        AUDJPY.open();
        if(!AUDJPY.open())
        {
           qDebug()<<QObject::tr("AUDJPY database connection failed\n");
            return false;
        }

     }else
    {
          qDebug()<<QObject::tr("AUDJPY connection is successful\n");
    }



    //4
     AUDNZD=QSqlDatabase(QSqlDatabase::addDatabase(K_qMYSQL,m_dbmap[K_AUDNZD]));

      AUDNZD.setHostName(m_mysqlmap[K_mysql_hostName]);
      AUDNZD.setPort(m_mysqlmap[K_mysql_port].toInt());
      AUDNZD.setDatabaseName(m_dbmap[K_AUDNZD]);
      AUDNZD.setUserName( m_mysqlmap[K_userName] );

      AUDNZD.setPassword( m_mysqlmap[K_pwd] );
     if (!AUDNZD.open())
     {
         AUDNZD.open();
         if(!AUDNZD.open())
         {
             qDebug()<<QObject::tr("AUDNZD database connection failed\n");
             return false;
         }

      }else
     {
           qDebug()<<QObject::tr("AUDNZD connection is successful\n");
     }



     //5
      AUDUSD=QSqlDatabase(QSqlDatabase::addDatabase(K_qMYSQL,m_dbmap[K_AUDUSD]));

       AUDUSD.setHostName(m_mysqlmap[K_mysql_hostName]);
       AUDUSD.setPort(m_mysqlmap[K_mysql_port].toInt());
       AUDUSD.setDatabaseName(m_dbmap[K_AUDUSD]);
       AUDUSD.setUserName( m_mysqlmap[K_userName] );

       AUDUSD.setPassword( m_mysqlmap[K_pwd] );
      if (!AUDUSD.open())
      {
          AUDUSD.open();
          if(!AUDUSD.open())
          {
            qDebug()<<QObject::tr("AUDUSD database connection failed\n");
              return false;
          }
       }else
      {
            qDebug()<<QObject::tr("AUDUSD connection is successful\n");
      }




      //6
       BUND=QSqlDatabase(QSqlDatabase::addDatabase(K_qMYSQL,m_dbmap[K_BUND]));

        BUND.setHostName(m_mysqlmap[K_mysql_hostName]);
        BUND.setPort(m_mysqlmap[K_mysql_port].toInt());
        BUND.setDatabaseName(m_dbmap[K_BUND]);
        BUND.setUserName( m_mysqlmap[K_userName] );

        BUND.setPassword( m_mysqlmap[K_pwd] );
       if (!BUND.open())
       {
           BUND.open();
           if(!BUND.open())
           {
             qDebug()<<QObject::tr("BUND database connection failed\n");
               return false;
           }
        }else
       {
             qDebug()<<QObject::tr("BUND connection is successful\n");
       }



       //7
        CADCHF=QSqlDatabase(QSqlDatabase::addDatabase(K_qMYSQL,m_dbmap[K_CADCHF]));

         CADCHF.setHostName(m_mysqlmap[K_mysql_hostName]);
         CADCHF.setPort(m_mysqlmap[K_mysql_port].toInt());
         CADCHF.setDatabaseName(m_dbmap[K_CADCHF]);
         CADCHF.setUserName( m_mysqlmap[K_userName] );

         CADCHF.setPassword( m_mysqlmap[K_pwd] );
        if (!CADCHF.open())
        {
            CADCHF.open();
            if(!CADCHF.open())
            {
                   qDebug()<<QObject::tr("CADCHF database connection failed\n");
                return false;
            }
         }else
        {
              qDebug()<<QObject::tr("CADCHF connection is successful\n");
        }






         //9
          COPPER=QSqlDatabase(QSqlDatabase::addDatabase(K_qMYSQL,m_dbmap[K_COPPER]));

           COPPER.setHostName(m_mysqlmap[K_mysql_hostName]);
           COPPER.setPort(m_mysqlmap[K_mysql_port].toInt());
           COPPER.setDatabaseName(m_dbmap[K_COPPER]);
           COPPER.setUserName( m_mysqlmap[K_userName] );

           COPPER.setPassword( m_mysqlmap[K_pwd] );
          if (!COPPER.open())
          {
              COPPER.open();
              if(!COPPER.open())
              {
                    qDebug()<<QObject::tr("COPPER database connection failed\n");
                  return false;
              }
           }else
          {
                qDebug()<<QObject::tr("COPPER connection is successful\n");
          }



          //10
           EURAUD=QSqlDatabase(QSqlDatabase::addDatabase(K_qMYSQL,m_dbmap[K_EURAUD]));

            EURAUD.setHostName(m_mysqlmap[K_mysql_hostName]);
            EURAUD.setPort(m_mysqlmap[K_mysql_port].toInt());
            EURAUD.setDatabaseName(m_dbmap[K_EURAUD]);
            EURAUD.setUserName( m_mysqlmap[K_userName] );

            EURAUD.setPassword( m_mysqlmap[K_pwd] );
           if (!EURAUD.open())
           {
               COPPER.open();
               if(!COPPER.open())
               {
                 qDebug()<<QObject::tr("EURAUD database connection failed\n");
                   return false;
               }
            }else
           {
                 qDebug()<<QObject::tr("EURAUD connection is successful\n");
           }


           //11
            EURCAD=QSqlDatabase(QSqlDatabase::addDatabase(K_qMYSQL,m_dbmap[K_EURCAD]));

             EURCAD.setHostName(m_mysqlmap[K_mysql_hostName]);
             EURCAD.setPort(m_mysqlmap[K_mysql_port].toInt());
             EURCAD.setDatabaseName(m_dbmap[K_EURCAD]);
             EURCAD.setUserName( m_mysqlmap[K_userName] );

             EURCAD.setPassword( m_mysqlmap[K_pwd] );
            if (!EURCAD.open())
            {
                EURCAD.open();
                if(!EURCAD.open())
                {
                   qDebug()<<QObject::tr("EURCAD database connection failed\n");
                    return false;
                }
             }else
            {
                  qDebug()<<QObject::tr("EURCAD connection is successful\n");
            }


            //12
             EURCHF=QSqlDatabase(QSqlDatabase::addDatabase(K_qMYSQL,m_dbmap[K_EURCHF]));

              EURCHF.setHostName(m_mysqlmap[K_mysql_hostName]);
              EURCHF.setPort(m_mysqlmap[K_mysql_port].toInt());
              EURCHF.setDatabaseName(m_dbmap[K_EURCHF]);
              EURCHF.setUserName( m_mysqlmap[K_userName] );

              EURCHF.setPassword( m_mysqlmap[K_pwd] );
             if (!EURCHF.open())
             {
                 EURCHF.open();
                 if(!EURCHF.open())
                 {
                   qDebug()<<QObject::tr("EURCHF database connection failed\n");
                     return false;
                 }
              }else
             {
                   qDebug()<<QObject::tr("EURCHF connection is successful\n");
             }



             //13
              EURGBP=QSqlDatabase(QSqlDatabase::addDatabase(K_qMYSQL,m_dbmap[K_EURGBP]));

               EURGBP.setHostName(m_mysqlmap[K_mysql_hostName]);
               EURGBP.setPort(m_mysqlmap[K_mysql_port].toInt());
               EURGBP.setDatabaseName(m_dbmap[K_EURGBP]);
               EURGBP.setUserName( m_mysqlmap[K_userName] );

               EURGBP.setPassword( m_mysqlmap[K_pwd] );
              if (!EURGBP.open())
              {
                  EURGBP.open();
                  if(!EURGBP.open())
                  {
                  qDebug()<<QObject::tr("EURGBP database connection failed\n");
                      return false;
                  }
               }else
              {
                    qDebug()<<QObject::tr("EURGBP connection is successful\n");
              }



              //14
               EURJPY=QSqlDatabase(QSqlDatabase::addDatabase(K_qMYSQL,m_dbmap[K_EURJPY]));

                EURJPY.setHostName(m_mysqlmap[K_mysql_hostName]);
                EURJPY.setPort(m_mysqlmap[K_mysql_port].toInt());
                EURJPY.setDatabaseName(m_dbmap[K_EURJPY]);
                EURJPY.setUserName( m_mysqlmap[K_userName] );

                EURJPY.setPassword( m_mysqlmap[K_pwd] );
               if (!EURJPY.open())
               {
                   EURJPY.open();
                   if(!EURJPY.open())
                   {
                 qDebug()<<QObject::tr("EURJPY database connection failed\n");
                       return false;
                   }
                }else
               {
                     qDebug()<<QObject::tr("EURJPY connection is successful\n");
               }





                //16
                 EURNZD=QSqlDatabase(QSqlDatabase::addDatabase(K_qMYSQL,m_dbmap[K_EURNZD]));

                  EURNZD.setHostName(m_mysqlmap[K_mysql_hostName]);
                  EURNZD.setPort(m_mysqlmap[K_mysql_port].toInt());
                  EURNZD.setDatabaseName(m_dbmap[K_EURNZD]);
                  EURNZD.setUserName( m_mysqlmap[K_userName] );

                  EURNZD.setPassword( m_mysqlmap[K_pwd] );
                 if (!EURNZD.open())
                 {
                     EURNZD.open();
                     if(!EURNZD.open())
                     {
                     qDebug()<<QObject::tr("EURNZD database connection failed\n");
                         return false;
                     }
                  }else
                 {
                       qDebug()<<QObject::tr("EURNZD connection is successful\n");
                 }





                   //19
                    EURUSD=QSqlDatabase(QSqlDatabase::addDatabase(K_qMYSQL,m_dbmap[K_EURUSD]));

                     EURUSD.setHostName(m_mysqlmap[K_mysql_hostName]);
                     EURUSD.setPort(m_mysqlmap[K_mysql_port].toInt());
                     EURUSD.setDatabaseName(m_dbmap[K_EURUSD]);
                     EURUSD.setUserName( m_mysqlmap[K_userName] );

                     EURUSD.setPassword( m_mysqlmap[K_pwd] );
                    if (!EURUSD.open())
                    {
                        EURUSD.open();
                        if(!EURUSD.open())
                        {
                          qDebug()<<QObject::tr("EURUSD database connection failed\n");
                            return false;
                        }
                     }else
                    {
                          qDebug()<<QObject::tr("EURUSD connection is successful\n");
                    }



                    //20
                     GBPAUD=QSqlDatabase(QSqlDatabase::addDatabase(K_qMYSQL,m_dbmap[K_GBPAUD]));

                      GBPAUD.setHostName(m_mysqlmap[K_mysql_hostName]);
                      GBPAUD.setPort(m_mysqlmap[K_mysql_port].toInt());
                      GBPAUD.setDatabaseName(m_dbmap[K_GBPAUD]);
                      GBPAUD.setUserName( m_mysqlmap[K_userName] );

                      GBPAUD.setPassword( m_mysqlmap[K_pwd] );
                     if (!GBPAUD.open())
                     {
                         EURUSD.open();
                         if(!GBPAUD.open())
                         {
                           qDebug()<<QObject::tr("GBPAUD database connection failed\n");
                             return false;
                         }
                      }else
                     {
                           qDebug()<<QObject::tr("GBPAUD connection is successful\n");
                     }


                     //21
                      GBPCAD=QSqlDatabase(QSqlDatabase::addDatabase(K_qMYSQL,m_dbmap[K_GBPCAD]));

                       GBPCAD.setHostName(m_mysqlmap[K_mysql_hostName]);
                       GBPCAD.setPort(m_mysqlmap[K_mysql_port].toInt());
                       GBPCAD.setDatabaseName(m_dbmap[K_GBPCAD]);
                       GBPCAD.setUserName( m_mysqlmap[K_userName] );

                       GBPCAD.setPassword( m_mysqlmap[K_pwd] );
                      if (!GBPCAD.open())
                      {
                          GBPCAD.open();
                          if(!GBPCAD.open())
                          {
                           qDebug()<<QObject::tr("GBPCAD database connection failed\n");
                              return false;
                          }
                       }else
                      {
                            qDebug()<<QObject::tr("GBPCAD connection is successful\n");
                      }


                      //22
                       GBPCHF=QSqlDatabase(QSqlDatabase::addDatabase(K_qMYSQL,m_dbmap[K_GBPCHF]));

                        GBPCHF.setHostName(m_mysqlmap[K_mysql_hostName]);
                        GBPCHF.setPort(m_mysqlmap[K_mysql_port].toInt());
                        GBPCHF.setDatabaseName(m_dbmap[K_GBPCHF]);
                        GBPCHF.setUserName( m_mysqlmap[K_userName] );

                        GBPCHF.setPassword( m_mysqlmap[K_pwd] );
                       if (!GBPCHF.open())
                       {
                           GBPCHF.open();
                           if(!GBPCHF.open())
                           {
                            qDebug()<<QObject::tr("GBPCHF database connection failed\n");
                               return false;
                           }
                        }else
                       {
                             qDebug()<<QObject::tr("GBPCHF connection is successful\n");
                       }


                       //23
                        GBPJPY=QSqlDatabase(QSqlDatabase::addDatabase(K_qMYSQL,m_dbmap[K_GBPJPY]));

                         GBPJPY.setHostName(m_mysqlmap[K_mysql_hostName]);
                         GBPJPY.setPort(m_mysqlmap[K_mysql_port].toInt());
                         GBPJPY.setDatabaseName(m_dbmap[K_GBPJPY]);
                         GBPJPY.setUserName( m_mysqlmap[K_userName] );

                         GBPJPY.setPassword( m_mysqlmap[K_pwd] );
                        if (!GBPJPY.open())
                        {
                            GBPJPY.open();
                            if(!GBPJPY.open())
                            {
                               qDebug()<<QObject::tr("GBPJPY database connection failed\n");
                                return false;
                            }
                         }else
                        {
                              qDebug()<<QObject::tr("GBPJPY connection is successful\n");
                        }


                        //24
                         GBPNZD=QSqlDatabase(QSqlDatabase::addDatabase(K_qMYSQL,m_dbmap[K_GBPNZD]));

                          GBPNZD.setHostName(m_mysqlmap[K_mysql_hostName]);
                          GBPNZD.setPort(m_mysqlmap[K_mysql_port].toInt());
                          GBPNZD.setDatabaseName(m_dbmap[K_GBPNZD]);
                          GBPNZD.setUserName( m_mysqlmap[K_userName] );

                          GBPNZD.setPassword( m_mysqlmap[K_pwd] );
                         if (!GBPNZD.open())
                         {
                             GBPNZD.open();
                             if(!GBPNZD.open())
                             {
                               qDebug()<<QObject::tr("GBPNZD database connection failed\n");
                               return false;
                           }
                          }else
                         {
                               qDebug()<<QObject::tr("GBPNZD connection is successful\n");
                         }



                         //25
                          GBPUSD=QSqlDatabase(QSqlDatabase::addDatabase(K_qMYSQL,m_dbmap[K_GBPUSD]));

                           GBPUSD.setHostName(m_mysqlmap[K_mysql_hostName]);
                           GBPUSD.setPort(m_mysqlmap[K_mysql_port].toInt());
                           GBPUSD.setDatabaseName(m_dbmap[K_GBPUSD]);
                           GBPUSD.setUserName( m_mysqlmap[K_userName] );

                           GBPUSD.setPassword( m_mysqlmap[K_pwd] );
                          if (!GBPUSD.open())
                          {
                              GBPUSD.open();
                              if(!GBPUSD.open())
                              {
                               qDebug()<<QObject::tr("GBPUSD database connection failed\n");
                                return false;
                            }
                           }else
                          {
                                qDebug()<<QObject::tr("GBPUSD connection is successful\n");
                          }


                          //26
                           NGAS=QSqlDatabase(QSqlDatabase::addDatabase(K_qMYSQL,m_dbmap[K_NGAS]));

                            NGAS.setHostName(m_mysqlmap[K_mysql_hostName]);
                            NGAS.setPort(m_mysqlmap[K_mysql_port].toInt());
                            NGAS.setDatabaseName(m_dbmap[K_NGAS]);
                            NGAS.setUserName( m_mysqlmap[K_userName] );

                            NGAS.setPassword( m_mysqlmap[K_pwd] );
                           if (!NGAS.open())
                           {
                               NGAS.open();
                               if(!NGAS.open())
                               {
                                qDebug()<<QObject::tr("NGAS database connection failed\n");
                                 return false;
                             }
                            }else
                           {
                                 qDebug()<<QObject::tr("NGAS connection is successful\n");
                           }


                           //27
                            NZDCAD=QSqlDatabase(QSqlDatabase::addDatabase(K_qMYSQL,m_dbmap[K_NZDCAD]));

                             NZDCAD.setHostName(m_mysqlmap[K_mysql_hostName]);
                             NZDCAD.setPort(m_mysqlmap[K_mysql_port].toInt());
                             NZDCAD.setDatabaseName(m_dbmap[K_NZDCAD]);
                             NZDCAD.setUserName( m_mysqlmap[K_userName] );

                             NZDCAD.setPassword( m_mysqlmap[K_pwd] );
                            if (!NZDCAD.open())
                            {
                                NZDCAD.open();
                                if(!NZDCAD.open())
                                {
                                 qDebug()<<QObject::tr("NZDCAD database connection failed\n");
                                  return false;
                              }

                             }else
                            {
                                  qDebug()<<QObject::tr("NZDCAD connection is successful\n");
                            }


                            //28
                             NZDCHF=QSqlDatabase(QSqlDatabase::addDatabase(K_qMYSQL,m_dbmap[K_NZDCHF]));

                              NZDCHF.setHostName(m_mysqlmap[K_mysql_hostName]);
                              NZDCHF.setPort(m_mysqlmap[K_mysql_port].toInt());
                              NZDCHF.setDatabaseName(m_dbmap[K_NZDCHF]);
                              NZDCHF.setUserName( m_mysqlmap[K_userName] );

                              NZDCHF.setPassword( m_mysqlmap[K_pwd] );
                             if (!NZDCHF.open())
                             {
                                 NZDCHF.open();
                                 if(!NZDCHF.open())
                                 {
                                qDebug()<<QObject::tr("NZDCHF database connection failed\n");
                                   return false;
                               }
                              }else
                             {
                                   qDebug()<<QObject::tr("NZDCHF connection is successful\n");
                             }

                             //29
                              NZDJPY=QSqlDatabase(QSqlDatabase::addDatabase(K_qMYSQL,m_dbmap[K_NZDJPY]));

                               NZDJPY.setHostName(m_mysqlmap[K_mysql_hostName]);
                               NZDJPY.setPort(m_mysqlmap[K_mysql_port].toInt());
                               NZDJPY.setDatabaseName(m_dbmap[K_NZDJPY]);
                               NZDJPY.setUserName( m_mysqlmap[K_userName] );

                               NZDJPY.setPassword( m_mysqlmap[K_pwd] );
                              if (!NZDJPY.open())
                              {
                                  NZDJPY.open();
                                  if(!NZDJPY.open())
                                  {
                                 qDebug()<<QObject::tr("NZDJPY database connection failed\n");
                                    return false;
                                }
                               }else
                              {
                                    qDebug()<<QObject::tr("NZDJPY connection is successful\n");
                              }


                              //30
                               NZDUSD=QSqlDatabase(QSqlDatabase::addDatabase(K_qMYSQL,m_dbmap[K_NZDUSD]));

                                NZDUSD.setHostName(m_mysqlmap[K_mysql_hostName]);
                                NZDUSD.setPort(m_mysqlmap[K_mysql_port].toInt());
                                NZDUSD.setDatabaseName(m_dbmap[K_NZDUSD]);
                                NZDUSD.setUserName( m_mysqlmap[K_userName] );

                                NZDUSD.setPassword( m_mysqlmap[K_pwd] );
                               if (!NZDUSD.open())
                               {
                                   NZDUSD.open();
                                   if(!NZDUSD.open())
                                   {
                                qDebug()<<QObject::tr("NZDUSD database connection failed\n");
                                     return false;
                                 }
                                }else
                               {
                                     qDebug()<<QObject::tr("NZDUSD connection is successful\n");
                               }


                               //31
                                UKOIL=QSqlDatabase(QSqlDatabase::addDatabase(K_qMYSQL,m_dbmap[K_UKOIL]));

                                 UKOIL.setHostName(m_mysqlmap[K_mysql_hostName]);
                                 UKOIL.setPort(m_mysqlmap[K_mysql_port].toInt());
                                 UKOIL.setDatabaseName(m_dbmap[K_UKOIL]);
                                 UKOIL.setUserName( m_mysqlmap[K_userName] );

                                 UKOIL.setPassword( m_mysqlmap[K_pwd] );
                                if (!UKOIL.open())
                                {
                                    UKOIL.open();
                                    if(!UKOIL.open())
                                    {
                                   qDebug()<<QObject::tr("UKOIL database connection failed\n");
                                      return false;
                                  }
                                 }else
                                {
                                      qDebug()<<QObject::tr("UKOIL connection is successful\n");
                                }


                                //32
                                 USDCAD=QSqlDatabase(QSqlDatabase::addDatabase(K_qMYSQL,m_dbmap[K_USDCAD]));

                                  USDCAD.setHostName(m_mysqlmap[K_mysql_hostName]);
                                  USDCAD.setPort(m_mysqlmap[K_mysql_port].toInt());
                                  USDCAD.setDatabaseName(m_dbmap[K_USDCAD]);
                                  USDCAD.setUserName( m_mysqlmap[K_userName] );

                                  USDCAD.setPassword( m_mysqlmap[K_pwd] );
                                 if (!USDCAD.open())
                                 {
                                     USDCAD.open();
                                     if(!USDCAD.open())
                                     {
                                      qDebug()<<QObject::tr("USDCAD database connection failed\n");
                                       return false;
                                   }
                                  }else
                                 {
                                       qDebug()<<QObject::tr("USDCAD connection is successful\n");
                                 }

                                 //33
                                  USDCHF=QSqlDatabase(QSqlDatabase::addDatabase(K_qMYSQL,m_dbmap[K_USDCHF]));

                                   USDCHF.setHostName(m_mysqlmap[K_mysql_hostName]);
                                   USDCHF.setPort(m_mysqlmap[K_mysql_port].toInt());
                                   USDCHF.setDatabaseName(m_dbmap[K_USDCHF]);
                                   USDCHF.setUserName( m_mysqlmap[K_userName] );

                                   USDCHF.setPassword( m_mysqlmap[K_pwd] );
                                  if (!USDCHF.open())
                                  {
                                      USDCHF.open();
                                      if(!USDCHF.open())
                                      {
                                       qDebug()<<QObject::tr("USDCHF database connection failed\n");
                                        return false;
                                    }
                                   }else
                                  {
                                        qDebug()<<QObject::tr("USDCHF connection is successful\n");
                                  }

                                  //34
                                   USDCNH=QSqlDatabase(QSqlDatabase::addDatabase(K_qMYSQL,m_dbmap[K_USDCNH]));

                                    USDCNH.setHostName(m_mysqlmap[K_mysql_hostName]);
                                    USDCNH.setPort(m_mysqlmap[K_mysql_port].toInt());
                                    USDCNH.setDatabaseName(m_dbmap[K_USDCNH]);
                                    USDCNH.setUserName( m_mysqlmap[K_userName] );

                                    USDCNH.setPassword( m_mysqlmap[K_pwd] );
                                   if (!USDCNH.open())
                                   {
                                       USDCNH.open();
                                       if(!USDCNH.open())
                                       {
                                        qDebug()<<QObject::tr("USDCNH database connection failed\n");
                                         return false;
                                     }

                                    }else
                                   {
                                         qDebug()<<QObject::tr("USDCNH connection is successful\n");
                                   }

                                   //35
                                    USDHKD=QSqlDatabase(QSqlDatabase::addDatabase(K_qMYSQL,m_dbmap[K_USDHKD]));

                                     USDHKD.setHostName(m_mysqlmap[K_mysql_hostName]);
                                     USDHKD.setPort(m_mysqlmap[K_mysql_port].toInt());
                                     USDHKD.setDatabaseName(m_dbmap[K_USDHKD]);
                                     USDHKD.setUserName( m_mysqlmap[K_userName] );

                                     USDHKD.setPassword( m_mysqlmap[K_pwd] );
                                    if (!USDHKD.open())
                                    {
                                        USDHKD.open();
                                        if(!USDHKD.open())
                                        {
                                       qDebug()<<QObject::tr("USDHKD database connection failed\n");
                                          return false;
                                      }
                                     }else
                                    {
                                          qDebug()<<QObject::tr("USDHKD connection is successful\n");
                                    }


                                    //36
                                     USDJPY=QSqlDatabase(QSqlDatabase::addDatabase(K_qMYSQL,m_dbmap[K_USDJPY]));

                                      USDJPY.setHostName(m_mysqlmap[K_mysql_hostName]);
                                      USDJPY.setPort(m_mysqlmap[K_mysql_port].toInt());
                                      USDJPY.setDatabaseName(m_dbmap[K_USDJPY]);
                                      USDJPY.setUserName( m_mysqlmap[K_userName] );

                                      USDJPY.setPassword( m_mysqlmap[K_pwd] );
                                     if (!USDJPY.open())
                                     {
                                         USDJPY.open();
                                         if(!USDJPY.open())
                                         {
                                      qDebug()<<QObject::tr("USDJPY database connection failed\n");
                                           return false;
                                       }
                                      }else
                                     {
                                           qDebug()<<QObject::tr("USDJPY connection is successful\n");
                                     }


                                     //37
                                      USDMXN=QSqlDatabase(QSqlDatabase::addDatabase(K_qMYSQL,m_dbmap[K_USDMXN]));

                                       USDMXN.setHostName(m_mysqlmap[K_mysql_hostName]);
                                       USDMXN.setPort(m_mysqlmap[K_mysql_port].toInt());
                                       USDMXN.setDatabaseName(m_dbmap[K_USDMXN]);
                                       USDMXN.setUserName( m_mysqlmap[K_userName] );

                                       USDMXN.setPassword( m_mysqlmap[K_pwd] );
                                      if (!USDMXN.open())
                                      {
                                          USDMXN.open();
                                          if(!USDMXN.open())
                                          {
                                         qDebug()<<QObject::tr("USDMXN database connection failed\n");
                                            return false;
                                        }
                                       }else
                                      {
                                            qDebug()<<QObject::tr("USDMXN connection is successful\n");
                                      }


                                      //38
                                       USDNOK=QSqlDatabase(QSqlDatabase::addDatabase(K_qMYSQL,m_dbmap[K_USDNOK]));

                                        USDNOK.setHostName(m_mysqlmap[K_mysql_hostName]);
                                        USDNOK.setPort(m_mysqlmap[K_mysql_port].toInt());
                                        USDNOK.setDatabaseName(m_dbmap[K_USDNOK]);
                                        USDNOK.setUserName( m_mysqlmap[K_userName] );

                                        USDNOK.setPassword( m_mysqlmap[K_pwd] );
                                       if (!USDNOK.open())
                                       {
                                           USDNOK.open();
                                           if(!USDNOK.open())
                                           {
                                           qDebug()<<QObject::tr("USDNOK database connection failed\n");
                                             return false;
                                         }
                                        }else
                                       {
                                             qDebug()<<QObject::tr("USDNOK connection is successful\n");
                                       }


                                       //39
                                        USDSEK=QSqlDatabase(QSqlDatabase::addDatabase(K_qMYSQL,m_dbmap[K_USDSEK]));

                                         USDSEK.setHostName(m_mysqlmap[K_mysql_hostName]);
                                         USDSEK.setPort(m_mysqlmap[K_mysql_port].toInt());
                                         USDSEK.setDatabaseName(m_dbmap[K_USDSEK]);
                                         USDSEK.setUserName( m_mysqlmap[K_userName] );

                                         USDSEK.setPassword( m_mysqlmap[K_pwd] );
                                        if (!USDSEK.open())
                                        {
                                            USDSEK.open();
                                            if(!USDSEK.open())
                                            {
                                           qDebug()<<QObject::tr("USDSEK database connection failed\n");
                                              return false;
                                          }
                                         }else
                                        {
                                              qDebug()<<QObject::tr("USDSEK connection is successful\n");
                                        }


                                        //40
                                         USDTRY=QSqlDatabase(QSqlDatabase::addDatabase(K_qMYSQL,m_dbmap[K_USDTRY]));

                                          USDTRY.setHostName(m_mysqlmap[K_mysql_hostName]);
                                          USDTRY.setPort(m_mysqlmap[K_mysql_port].toInt());
                                          USDTRY.setDatabaseName(m_dbmap[K_USDTRY]);
                                          USDTRY.setUserName( m_mysqlmap[K_userName] );

                                          USDTRY.setPassword( m_mysqlmap[K_pwd] );
                                         if (!USDTRY.open())
                                         {
                                             USDTRY.open();
                                             if(!USDTRY.open())
                                             {
                                           qDebug()<<QObject::tr("USDTRY database connection failed\n");
                                               return false;
                                           }
                                          }else
                                         {
                                               qDebug()<<QObject::tr("USDTRY connection is successful\n");
                                         }


                                         //41
                                          USDZAR=QSqlDatabase(QSqlDatabase::addDatabase(K_qMYSQL,m_dbmap[K_USDZAR]));

                                           USDZAR.setHostName(m_mysqlmap[K_mysql_hostName]);
                                           USDZAR.setPort(m_mysqlmap[K_mysql_port].toInt());
                                           USDZAR.setDatabaseName(m_dbmap[K_USDZAR]);
                                           USDZAR.setUserName( m_mysqlmap[K_userName] );

                                           USDZAR.setPassword( m_mysqlmap[K_pwd] );
                                          if (!USDZAR.open())
                                          {
                                              USDZAR.open();
                                              if(!USDZAR.open())
                                              {
                                            qDebug()<<QObject::tr("USDZAR database connection failed\n");
                                                return false;
                                            }
                                           }else
                                          {
                                                qDebug()<<QObject::tr("USDZAR connection is successful\n");
                                          }


                                          //42
                                           USOIL=QSqlDatabase(QSqlDatabase::addDatabase(K_qMYSQL,m_dbmap[K_USOIL]));

                                            USOIL.setHostName(m_mysqlmap[K_mysql_hostName]);
                                            USOIL.setPort(m_mysqlmap[K_mysql_port].toInt());
                                            USOIL.setDatabaseName(m_dbmap[K_USOIL]);
                                            USOIL.setUserName( m_mysqlmap[K_userName] );

                                            USOIL.setPassword( m_mysqlmap[K_pwd] );
                                           if (!USOIL.open())
                                           {
                                               USOIL.open();
                                               if(!USOIL.open())
                                               {
                                           qDebug()<<QObject::tr("USOIL database connection failed\n");
                                                 return false;
                                             }
                                            }else
                                           {
                                                 qDebug()<<QObject::tr("USOIL connection is successful\n");
                                           }

                                           //43
                                            XAGUSD=QSqlDatabase(QSqlDatabase::addDatabase(K_qMYSQL,m_dbmap[K_XAGUSD]));

                                             XAGUSD.setHostName(m_mysqlmap[K_mysql_hostName]);
                                             XAGUSD.setPort(m_mysqlmap[K_mysql_port].toInt());
                                             XAGUSD.setDatabaseName(m_dbmap[K_XAGUSD]);
                                             XAGUSD.setUserName( m_mysqlmap[K_userName] );

                                             XAGUSD.setPassword( m_mysqlmap[K_pwd] );
                                            if (!XAGUSD.open())
                                            {
                                                XAGUSD.open();
                                                if(!XAGUSD.open())
                                                {
                                             qDebug()<<QObject::tr("XAGUSD database connection failed\n");
                                                  return false;
                                              }
                                             }else
                                            {
                                                  qDebug()<<QObject::tr("XAGUSD connection is successful\n");
                                            }



                                            //44
                                             XAUUSD=QSqlDatabase(QSqlDatabase::addDatabase(K_qMYSQL,m_dbmap[K_XAUUSD]));

                                              XAUUSD.setHostName(m_mysqlmap[K_mysql_hostName]);
                                              XAUUSD.setPort(m_mysqlmap[K_mysql_port].toInt());
                                              XAUUSD.setDatabaseName(m_dbmap[K_XAUUSD]);
                                              XAUUSD.setUserName( m_mysqlmap[K_userName] );

                                              XAUUSD.setPassword( m_mysqlmap[K_pwd] );
                                             if (!XAUUSD.open())
                                             {
                                                 XAUUSD.open();
                                                 if(!XAUUSD.open())
                                                 {
                                                  qDebug()<<QObject::tr("XAUUSD database connection failed\n");
                                                   return false;
                                               }
                                              }else
                                             {
                                                   qDebug()<<QObject::tr("XAUUSD connection is successful\n");
                                             }



                                             //45
                                              XPDUSD=QSqlDatabase(QSqlDatabase::addDatabase(K_qMYSQL,m_dbmap[K_XPDUSD]));

                                               XPDUSD.setHostName(m_mysqlmap[K_mysql_hostName]);
                                               XPDUSD.setPort(m_mysqlmap[K_mysql_port].toInt());
                                               XPDUSD.setDatabaseName(m_dbmap[K_XPDUSD]);
                                               XPDUSD.setUserName( m_mysqlmap[K_userName] );

                                               XPDUSD.setPassword( m_mysqlmap[K_pwd] );
                                              if (!XPDUSD.open())
                                              {
                                                  XPDUSD.open();
                                                  if(!XPDUSD.open())
                                                  {
                                                      qDebug()<<QObject::tr("XPDUSD database connection failed\n");


                                                      return false;
                                                  }

                                               }else
                                              {
                                                    qDebug()<<QObject::tr("XPDUSD connection is successful\n");
                                                    XPDUSD.open();
                                              }



                                              //46
                                               XPTUSD=QSqlDatabase(QSqlDatabase::addDatabase(K_qMYSQL,m_dbmap[K_XPTUSD]));

                                                XPTUSD.setHostName(m_mysqlmap[K_mysql_hostName]);
                                                XPTUSD.setPort(m_mysqlmap[K_mysql_port].toInt());
                                                XPTUSD.setDatabaseName(m_dbmap[K_XPTUSD]);
                                                XPTUSD.setUserName( m_mysqlmap[K_userName] );

                                                XPTUSD.setPassword( m_mysqlmap[K_pwd] );
                                               if (!XPTUSD.open())
                                               {
                                                   XPTUSD.open();
                                                   if(!XPTUSD.open())
                                                   {
                                                    qDebug()<<QObject::tr("XPTUSD database connection failed\n");
                                                       return false;
                                                   }
                                                }else
                                               {
                                                     qDebug()<<QObject::tr("XPTUSD connection is successful\n");
                                               }

                                                  qDebug()<<QString("end db %1 ms").arg(dbt.elapsed());


return true;
}


/**重新打开数据库数据库
 * @brief qReadisTest::openDB
 */
void qDbManager::openDB()
{
    QTime t;
    t.start();
    qDebug()<<"重新start db";



    //1
    if(QSqlDatabase::contains(m_dbmap[K_AUDJPY]))
    {
        AUDJPY = QSqlDatabase::database(m_dbmap[K_AUDJPY]);
    }
      else
    {
       AUDJPY = QSqlDatabase::addDatabase(K_qMYSQL,m_dbmap[K_AUDJPY]);
    }
  //  AUDJPY.open();
      if (!AUDJPY.open())
      {
            qDebug()<<QObject::tr("AUDJPY database connection failed\n");
           return ;
       }else
      {
            qDebug()<<QObject::tr("AUDJPY connection is successful\n");
      }



        //2
      if(QSqlDatabase::contains(m_dbmap[K_AUDNZD]))
      {
          AUDNZD = QSqlDatabase::database(m_dbmap[K_AUDNZD]);
      }
        else
      {
         AUDNZD = QSqlDatabase::addDatabase(K_qMYSQL,m_dbmap[K_AUDNZD]);
        // AUDNZD->setDatabaseName(m_dbmap[K_AUDNZD]);
      }


       if (!AUDNZD.open())
       {
             qDebug()<<QObject::tr("AUDNZD database connection failed\n");
            return ;
        }else
       {
             qDebug()<<QObject::tr("AUDNZD connection is successful\n");
       }
       //3
       if(QSqlDatabase::contains(m_dbmap[K_AUDUSD]))
       {
           AUDUSD = QSqlDatabase::database(m_dbmap[K_AUDUSD]);
       }
         else
       {
          AUDUSD=QSqlDatabase(QSqlDatabase::addDatabase(K_qMYSQL,m_dbmap[K_AUDUSD]));
       }
        if (!AUDUSD.open())
        {
              qDebug()<<QObject::tr("AUDUSD database connection failed\n");
              return ;
         }else
        {
              qDebug()<<QObject::tr("AUDUSD connection is successful\n");
        }
        //4
        if(QSqlDatabase::contains(m_dbmap[K_BUND]))
        {
            BUND = QSqlDatabase::database(m_dbmap[K_BUND]);
        }
          else
        {
           BUND=QSqlDatabase(QSqlDatabase::addDatabase(K_qMYSQL,m_dbmap[K_BUND]));
        }

         if (!BUND.open())
         {
               qDebug()<<QObject::tr("BUND database connection failed\n");

               return ;
          }else
         {
               qDebug()<<QObject::tr("BUND connection is successful\n");
         }

          //5
         if(QSqlDatabase::contains(m_dbmap[K_CADCHF]))
         {
             CADCHF = QSqlDatabase::database(m_dbmap[K_CADCHF]);
         }
           else
         {
            CADCHF=QSqlDatabase(QSqlDatabase::addDatabase(K_qMYSQL,m_dbmap[K_CADCHF]));
         }

          if (!CADCHF.open())
          {
                qDebug()<<QObject::tr("CADCHF database connection failed\n");

                return ;
           }else
          {
                qDebug()<<QObject::tr("CADCHF connection is successful\n");
          }

          //6
         if(QSqlDatabase::contains(m_dbmap[K_COPPER]))
         {
             COPPER = QSqlDatabase::database(m_dbmap[K_COPPER]);
         }
           else
         {
            COPPER=QSqlDatabase(QSqlDatabase::addDatabase(K_qMYSQL,m_dbmap[K_COPPER]));
         }
            if (!COPPER.open())
            {
                  qDebug()<<QObject::tr("COPPER database connection failed\n");

                  return ;
             }else
            {
                  qDebug()<<QObject::tr("COPPER connection is successful\n");
            }

            //7
           if(QSqlDatabase::contains(m_dbmap[K_EURAUD]))
           {
               EURAUD = QSqlDatabase::database(m_dbmap[K_EURAUD]);
           }
             else
           {
               EURAUD=QSqlDatabase(QSqlDatabase::addDatabase(K_qMYSQL,m_dbmap[K_EURAUD]));


           }
             if (!EURAUD.open())
             {
                   qDebug()<<QObject::tr("EURAUD database connection failed\n");

                   return ;
              }else
             {
                   qDebug()<<QObject::tr("EURAUD connection is successful\n");
             }


             //8
 if(QSqlDatabase::contains(m_dbmap[K_EURCAD]))
 {
     EURCAD = QSqlDatabase::database(m_dbmap[K_EURCAD]);
 }
   else
 {
      EURCAD=QSqlDatabase(QSqlDatabase::addDatabase(K_qMYSQL,m_dbmap[K_EURCAD]));


 }

              if (!EURCAD.open())
              {
                    qDebug()<<QObject::tr("EURCAD database connection failed\n");

                    return ;
               }else
              {
                    qDebug()<<QObject::tr("EURCAD connection is successful\n");
              }



              //9
  if(QSqlDatabase::contains(m_dbmap[K_EURCHF]))
  {
              EURCHF = QSqlDatabase::database(m_dbmap[K_EURCHF]);
  }
    else
  {
                 EURCHF=QSqlDatabase(QSqlDatabase::addDatabase(K_qMYSQL,m_dbmap[K_EURCHF]));


  }
               if (!EURCHF.open())
               {
                     qDebug()<<QObject::tr("EURCHF database connection failed\n");

                     return ;
                }else
               {
                     qDebug()<<QObject::tr("EURCHF connection is successful\n");
               }



  //10
if(QSqlDatabase::contains(m_dbmap[K_EURGBP]))
{
  EURGBP = QSqlDatabase::database(m_dbmap[K_EURGBP]);
}
else
{
     EURGBP=QSqlDatabase(QSqlDatabase::addDatabase(K_qMYSQL,m_dbmap[K_EURGBP]));


}

                if (!EURGBP.open())
                {
                      qDebug()<<QObject::tr("EURGBP database connection failed\n");

                      return ;
                 }else
                {
                      qDebug()<<QObject::tr("EURGBP connection is successful\n");
                }
                //11
              if(QSqlDatabase::contains(m_dbmap[K_EURJPY]))
              {
                EURJPY = QSqlDatabase::database(m_dbmap[K_EURJPY]);
              }
              else
              {
                 EURJPY=QSqlDatabase(QSqlDatabase::addDatabase(K_qMYSQL,m_dbmap[K_EURJPY]));


              }
                 if (!EURJPY.open())
                 {
                       qDebug()<<QObject::tr("EURJPY database connection failed\n");

                       return ;
                  }else
                 {
                       qDebug()<<QObject::tr("EURJPY connection is successful\n");
                 }
                 //12
               if(QSqlDatabase::contains(m_dbmap[K_EURNZD]))
               {
                   EURNZD = QSqlDatabase::database(m_dbmap[K_EURNZD]);
               }
               else
               {
                    EURNZD=QSqlDatabase(QSqlDatabase::addDatabase(K_qMYSQL,m_dbmap[K_EURNZD]));


               }
                   if (!EURNZD.open())
                   {
                         qDebug()<<QObject::tr("EURNZD database connection failed\n");

                         return ;
                    }else
                   {
                         qDebug()<<QObject::tr("EURNZD connection is successful\n");
                   }

                   //13
                 if(QSqlDatabase::contains(m_dbmap[K_EURUSD]))
                 {
                     EURUSD = QSqlDatabase::database(m_dbmap[K_EURUSD]);
                 }
                 else
                 {
                 EURUSD=QSqlDatabase(QSqlDatabase::addDatabase(K_qMYSQL,m_dbmap[K_EURUSD]));


                 }
                      if (!EURUSD.open())
                      {
                            qDebug()<<QObject::tr("EURUSD database connection failed\n");

                            return ;
                       }else
                      {
                            qDebug()<<QObject::tr("EURUSD connection is successful\n");
                      }

                      //14
                    if(QSqlDatabase::contains(m_dbmap[K_GBPAUD]))
                    {
                        GBPAUD = QSqlDatabase::database(m_dbmap[K_GBPAUD]);
                    }
                    else
                    {
                 GBPAUD=QSqlDatabase(QSqlDatabase::addDatabase(K_qMYSQL,m_dbmap[K_GBPAUD]));


                    }
                       if (!GBPAUD.open())
                       {
                             qDebug()<<QObject::tr("GBPAUD database connection failed\n");

                             return ;
                        }else
                       {
                             qDebug()<<QObject::tr("GBPAUD connection is successful\n");
                       }


  //15
if(QSqlDatabase::contains(m_dbmap[K_GBPCAD]))
{
    GBPCAD = QSqlDatabase::database(m_dbmap[K_GBPCAD]);
}
else
{
  GBPCAD=QSqlDatabase(QSqlDatabase::addDatabase(K_qMYSQL,m_dbmap[K_GBPCAD]));

}
                        if (!GBPCAD.open())
                        {
                              qDebug()<<QObject::tr("GBPCAD database connection failed\n");

                              return ;
                         }else
                        {
                              qDebug()<<QObject::tr("GBPCAD connection is successful\n");
                        }
                        //16
                      if(QSqlDatabase::contains(m_dbmap[K_GBPCHF]))
                      {
                          GBPCHF = QSqlDatabase::database(m_dbmap[K_GBPCHF]);
                      }
                      else
                      {
                       GBPCHF=QSqlDatabase(QSqlDatabase::addDatabase(K_qMYSQL,m_dbmap[K_GBPCHF]));

                      }
                         if (!GBPCHF.open())
                         {
                               qDebug()<<QObject::tr("GBPCHF database connection failed\n");

                               return ;
                          }else
                         {
                               qDebug()<<QObject::tr("GBPCHF connection is successful\n");
                         }
                         //17
                       if(QSqlDatabase::contains(m_dbmap[K_GBPJPY]))
                       {
                           GBPJPY = QSqlDatabase::database(m_dbmap[K_GBPJPY]);
                       }
                       else
                       {
                         GBPJPY=QSqlDatabase(QSqlDatabase::addDatabase(K_qMYSQL,m_dbmap[K_GBPJPY]));

                       }
                          if (!GBPJPY.open())
                          {
                                qDebug()<<QObject::tr("GBPJPY database connection failed\n");

                                return ;
                           }else
                          {
                                qDebug()<<QObject::tr("GBPJPY connection is successful\n");
                          }
                          //18
                        if(QSqlDatabase::contains(m_dbmap[K_GBPNZD]))
                        {
                            GBPNZD = QSqlDatabase::database(m_dbmap[K_GBPNZD]);
                        }
                        else
                        {
                           GBPNZD=QSqlDatabase(QSqlDatabase::addDatabase(K_qMYSQL,m_dbmap[K_GBPNZD]));

                        }
                           if (!GBPNZD.open())
                           {
                                 qDebug()<<QObject::tr("GBPNZD database connection failed\n");

                                 return ;
                            }else
                           {
                                 qDebug()<<QObject::tr("GBPNZD connection is successful\n");
                           }

                           //19
                         if(QSqlDatabase::contains(m_dbmap[K_GBPUSD]))
                         {
                             GBPUSD = QSqlDatabase::database(m_dbmap[K_GBPUSD]);
                         }
                         else
                         {
                             GBPUSD=QSqlDatabase(QSqlDatabase::addDatabase(K_qMYSQL,m_dbmap[K_GBPUSD]));

                         }
                            if (!GBPUSD.open())
                            {
                                  qDebug()<<QObject::tr("GBPUSD database connection failed\n");

                                  return ;
                             }else
                            {
                                  qDebug()<<QObject::tr("GBPUSD connection is successful\n");
                            }

                            //20
                          if(QSqlDatabase::contains(m_dbmap[K_NGAS]))
                          {
                              NGAS = QSqlDatabase::database(m_dbmap[K_NGAS]);
                          }
                          else
                          {
                               NGAS=QSqlDatabase(QSqlDatabase::addDatabase(K_qMYSQL,m_dbmap[K_NGAS]));

                          }
                             if (!NGAS.open())
                             {
                                   qDebug()<<QObject::tr("NGAS database connection failed\n");

                                   return ;
                              }else
                             {
                                   qDebug()<<QObject::tr("NGAS connection is successful\n");
                             }
                             //21
                           if(QSqlDatabase::contains(m_dbmap[K_NZDCAD]))
                           {
                               NZDCAD = QSqlDatabase::database(m_dbmap[K_NZDCAD]);
                           }
                           else
                           {
                                NZDCAD=QSqlDatabase(QSqlDatabase::addDatabase(K_qMYSQL,m_dbmap[K_NZDCAD]));

                           }
                              if (!NZDCAD.open())
                              {
                                    qDebug()<<QObject::tr("NZDCAD database connection failed\n");

                                    return ;
                               }else
                              {
                                    qDebug()<<QObject::tr("NZDCAD connection is successful\n");
                              }
                              //22
                            if(QSqlDatabase::contains(m_dbmap[K_NZDCHF]))
                            {
                                NZDCHF = QSqlDatabase::database(m_dbmap[K_NZDCHF]);
                            }
                            else
                            {
                                 NZDCHF=QSqlDatabase(QSqlDatabase::addDatabase(K_qMYSQL,m_dbmap[K_NZDCHF]));

                            }
                               if (!NZDCHF.open())
                               {
                                     qDebug()<<QObject::tr("NZDCHF database connection failed\n");

                                     return ;
                                }else
                               {
                                     qDebug()<<QObject::tr("NZDCHF connection is successful\n");
                               }

                                //23
                              if(QSqlDatabase::contains(m_dbmap[K_NZDJPY]))
                              {
                                  NZDJPY = QSqlDatabase::database(m_dbmap[K_NZDJPY]);
                              }
                              else
                              {
                                  NZDJPY=QSqlDatabase(QSqlDatabase::addDatabase(K_qMYSQL,m_dbmap[K_NZDJPY]));

                              }
                                if (!NZDJPY.open())
                                {
                                      qDebug()<<QObject::tr("NZDJPY database connection failed\n");

                                      return ;
                                 }else
                                {
                                      qDebug()<<QObject::tr("NZDJPY connection is successful\n");
                                }
                                //24
                              if(QSqlDatabase::contains(m_dbmap[K_NZDUSD]))
                              {
                                  NZDUSD = QSqlDatabase::database(m_dbmap[K_NZDUSD]);
                              }
                              else
                              {
                                  NZDUSD=QSqlDatabase(QSqlDatabase::addDatabase(K_qMYSQL,m_dbmap[K_NZDUSD]));

                              }
                                 if (!NZDUSD.open())
                                 {
                                       qDebug()<<QObject::tr("NZDUSD database connection failed\n");

                                       return ;
                                  }else
                                 {
                                       qDebug()<<QObject::tr("NZDUSD connection is successful\n");
                                 }
                                 //25
                               if(QSqlDatabase::contains(m_dbmap[K_UKOIL]))
                               {
                                   UKOIL = QSqlDatabase::database(m_dbmap[K_UKOIL]);
                               }
                               else
                               {
                                    UKOIL=QSqlDatabase(QSqlDatabase::addDatabase(K_qMYSQL,m_dbmap[K_UKOIL]));
                               }
                                  if (!UKOIL.open())
                                  {
                                        qDebug()<<QObject::tr("UKOIL database connection failed\n");

                                        return ;
                                   }else
                                  {
                                        qDebug()<<QObject::tr("UKOIL connection is successful\n");
                                  }
                                  //26
                                if(QSqlDatabase::contains(m_dbmap[K_USDCAD]))
                                {
                                    USDCAD = QSqlDatabase::database(m_dbmap[K_USDCAD]);
                                }
                                else
                                {
                                     USDCAD=QSqlDatabase(QSqlDatabase::addDatabase(K_qMYSQL,m_dbmap[K_USDCAD]));
                                }
                                   if (!USDCAD.open())
                                   {
                                         qDebug()<<QObject::tr("USDCAD database connection failed\n");

                                         return ;
                                    }else
                                   {
                                         qDebug()<<QObject::tr("USDCAD connection is successful\n");
                                   }
                                   //27
                                 if(QSqlDatabase::contains(m_dbmap[K_USDCHF]))
                                 {
                                     USDCHF = QSqlDatabase::database(m_dbmap[K_USDCHF]);
                                 }
                                 else
                                 {
                                      USDCHF=QSqlDatabase(QSqlDatabase::addDatabase(K_qMYSQL,m_dbmap[K_USDCHF]));
                                 }
                                    if (!USDCHF.open())
                                    {
                                          qDebug()<<QObject::tr("USDCHF database connection failed\n");

                                          return ;
                                     }else
                                    {
                                          qDebug()<<QObject::tr("USDCHF connection is successful\n");
                                    }
                                    //28
                                  if(QSqlDatabase::contains(m_dbmap[K_USDCNH]))
                                  {
                                      USDCNH = QSqlDatabase::database(m_dbmap[K_USDCNH]);
                                  }
                                  else
                                  {
                                       USDCNH=QSqlDatabase(QSqlDatabase::addDatabase(K_qMYSQL,m_dbmap[K_USDCNH]));
                                  }
                                     if (!USDCNH.open())
                                     {
                                           qDebug()<<QObject::tr("USDCNH database connection failed\n");

                                           return ;
                                      }else
                                     {
                                           qDebug()<<QObject::tr("USDCNH connection is successful\n");
                                     }

                                     //29
                                   if(QSqlDatabase::contains(m_dbmap[K_USDHKD]))
                                   {
                                       USDHKD = QSqlDatabase::database(m_dbmap[K_USDHKD]);
                                   }
                                   else
                                   {

                                       USDHKD=QSqlDatabase(QSqlDatabase::addDatabase(K_qMYSQL,m_dbmap[K_USDHKD]));
                                     }

                                      if (!USDHKD.open())
                                      {
                                            qDebug()<<QObject::tr("USDHKD database connection failed\n");

                                            return ;
                                       }else
                                      {
                                            qDebug()<<QObject::tr("USDHKD connection is successful\n");
                                      }
                                      //30
                                    if(QSqlDatabase::contains(m_dbmap[K_USDJPY]))
                                    {
                                        USDJPY = QSqlDatabase::database(m_dbmap[K_USDJPY]);
                                    }
                                    else
                                    {

                                        USDJPY=QSqlDatabase(QSqlDatabase::addDatabase(K_qMYSQL,m_dbmap[K_USDJPY]));
                                      }
                                       if (!USDJPY.open())
                                       {
                                             qDebug()<<QObject::tr("USDJPY database connection failed\n");

                                             return ;
                                        }else
                                       {
                                             qDebug()<<QObject::tr("USDJPY connection is successful\n");
                                       }
                                       //31
                                     if(QSqlDatabase::contains(m_dbmap[K_USDMXN]))
                                     {
                                         USDMXN = QSqlDatabase::database(m_dbmap[K_USDMXN]);
                                     }
                                     else
                                     {

                                        USDMXN=QSqlDatabase(QSqlDatabase::addDatabase(K_qMYSQL,m_dbmap[K_USDMXN]));
                                     }
                                        if (!USDMXN.open())
                                        {
                                              qDebug()<<QObject::tr("USDMXN database connection failed\n");

                                              return ;
                                         }else
                                        {
                                              qDebug()<<QObject::tr("USDMXN connection is successful\n");
                                        }
                                        //32
                                      if(QSqlDatabase::contains(m_dbmap[K_USDNOK]))
                                      {
                                          USDNOK = QSqlDatabase::database(m_dbmap[K_USDNOK]);
                                      }
                                      else
                                      {

                                        USDNOK=QSqlDatabase(QSqlDatabase::addDatabase(K_qMYSQL,m_dbmap[K_USDNOK]));
                                      }
                                         if (!USDNOK.open())
                                         {
                                               qDebug()<<QObject::tr("USDNOK database connection failed\n");

                                               return ;
                                          }else
                                         {
                                               qDebug()<<QObject::tr("USDNOK connection is successful\n");
                                         }
                                         //33
                                       if(QSqlDatabase::contains(m_dbmap[K_USDSEK]))
                                       {
                                           USDSEK = QSqlDatabase::database(m_dbmap[K_USDSEK]);
                                       }
                                       else
                                       {

                                        USDSEK=QSqlDatabase(QSqlDatabase::addDatabase(K_qMYSQL,m_dbmap[K_USDSEK]));
                                       }
                                          if (!USDSEK.open())
                                          {
                                                qDebug()<<QObject::tr("USDSEK database connection failed\n");

                                                return ;
                                           }else
                                          {
                                                qDebug()<<QObject::tr("USDSEK connection is successful\n");
                                          }
                                          //34
                                        if(QSqlDatabase::contains(m_dbmap[K_USDTRY]))
                                        {
                                            USDTRY = QSqlDatabase::database(m_dbmap[K_USDTRY]);
                                        }
                                        else
                                        {

                                         USDTRY=QSqlDatabase(QSqlDatabase::addDatabase(K_qMYSQL,m_dbmap[K_USDTRY]));
                                        }
                                           if (!USDTRY.open())
                                           {
                                                 qDebug()<<QObject::tr("USDTRY database connection failed\n");

                                                 return ;
                                            }else
                                           {
                                                 qDebug()<<QObject::tr("USDTRY connection is successful\n");
                                           }
                                           //35
                                         if(QSqlDatabase::contains(m_dbmap[K_USDZAR]))
                                         {
                                             USDZAR = QSqlDatabase::database(m_dbmap[K_USDZAR]);
                                         }
                                         else
                                         {
                                          USDZAR=QSqlDatabase(QSqlDatabase::addDatabase(K_qMYSQL,m_dbmap[K_USDZAR]));
                                         }
                                            if (!USDZAR.open())
                                            {
                                                  qDebug()<<QObject::tr("USDZAR database connection failed\n");

                                                  return ;
                                             }else
                                            {
                                                  qDebug()<<QObject::tr("USDZAR connection is successful\n");
                                            }
                                            //36
                                          if(QSqlDatabase::contains(m_dbmap[K_USOIL]))
                                          {
                                              USOIL = QSqlDatabase::database(m_dbmap[K_USOIL]);
                                          }
                                          else
                                          {
                                        USOIL=QSqlDatabase(QSqlDatabase::addDatabase(K_qMYSQL,m_dbmap[K_USOIL]));
                                          }
                                             if (!USOIL.open())
                                             {
                                                   qDebug()<<QObject::tr("USOIL database connection failed\n");

                                                   return ;
                                              }else
                                             {
                                                   qDebug()<<QObject::tr("USOIL connection is successful\n");
                                             }
                                             //37
                                           if(QSqlDatabase::contains(m_dbmap[K_XAGUSD]))
                                           {
                                               XAGUSD = QSqlDatabase::database(m_dbmap[K_XAGUSD]);
                                           }
                                           else
                                           {
                                              XAGUSD=QSqlDatabase(QSqlDatabase::addDatabase(K_qMYSQL,m_dbmap[K_XAGUSD]));
                                           }
                                              if (!XAGUSD.open())
                                              {
                                                    qDebug()<<QObject::tr("XAGUSD database connection failed\n");

                                                    return ;
                                               }else
                                              {
                                                    qDebug()<<QObject::tr("XAGUSD connection is successful\n");
                                              }
                                              //38
                                            if(QSqlDatabase::contains(m_dbmap[K_XAUUSD]))
                                            {
                                                XAUUSD = QSqlDatabase::database(m_dbmap[K_XAUUSD]);
                                            }
                                            else
                                            {
                                              XAUUSD=QSqlDatabase(QSqlDatabase::addDatabase(K_qMYSQL,m_dbmap[K_XAUUSD]));
                                            }
                                               if (!XAUUSD.open())
                                               {
                                                     qDebug()<<QObject::tr("XAUUSD database connection failed\n");

                                                     return ;
                                                }else
                                               {
                                                     qDebug()<<QObject::tr("XAUUSD connection is successful\n");
                                               }
                                               //39
                                             if(QSqlDatabase::contains(m_dbmap[K_XPDUSD]))
                                             {
                                                 XPDUSD = QSqlDatabase::database(m_dbmap[K_XPDUSD]);
                                             }
                                             else
                                             {
                                              XPDUSD=QSqlDatabase(QSqlDatabase::addDatabase(K_qMYSQL,m_dbmap[K_XPDUSD]));
                                             }

                                                if (!XPDUSD.open())
                                                {
                                                      qDebug()<<QObject::tr("XPDUSD database connection failed\n");

                                                      return ;
                                                 }else
                                                {
                                                      qDebug()<<QObject::tr("XPDUSD connection is successful\n");
                                                }
                                                //40
                                              if(QSqlDatabase::contains(m_dbmap[K_XPTUSD]))
                                              {
                                                  XPTUSD = QSqlDatabase::database(m_dbmap[K_XPTUSD]);
                                              }
                                              else
                                              {
                                                XPTUSD=QSqlDatabase(QSqlDatabase::addDatabase(K_qMYSQL,m_dbmap[K_XPTUSD]));
                                              }

                                                  XPTUSD.open();
                                                 if (!XPTUSD.open())
                                                 {
                                                       qDebug()<<QObject::tr("XPTUSD database connection failed\n");

                                                       return ;
                                                  }else
                                                 {
                                                       qDebug()<<QObject::tr("XPTUSD connection is successful\n");
                                                 }
                                                   qDebug()<<QObject::tr("end重新db：%1 ms").arg(t.elapsed());

}

/**关闭数据库
 * @brief qReadisTest::closeDB
 */
void qDbManager::closeDB()
{
    AUDNZD.close();
    QSqlDatabase::removeDatabase("AUDNZD");

}
/**数据库保存
 * @brief qDbManager::createDBArray
 * @return
 */
QVector<QSqlDatabase> qDbManager::createDBArray()

{

    QVector<QSqlDatabase> strArray;

     strArray.append(AUDJPY);
     strArray.append(AUDNZD);
     strArray.append(AUDUSD);
     strArray.append(BUND);
     strArray.append(CADCHF);


     strArray.append(COPPER);
     strArray.append(EURAUD);
     strArray.append(EURCAD);
     strArray.append(EURCHF);

     strArray.append(EURGBP);
     strArray.append(EURJPY);

     strArray.append(EURNZD);

     strArray.append(EURUSD);
     strArray.append(GBPAUD);

     strArray.append(GBPCAD);
     strArray.append(GBPCHF);
     strArray.append(GBPJPY);
     strArray.append(GBPNZD);

     strArray.append(GBPUSD);
     strArray.append(NGAS);
     strArray.append(NZDCAD);
     strArray.append(NZDCHF);

     strArray.append(NZDJPY);
     strArray.append(NZDUSD);
     strArray.append(UKOIL);
     strArray.append(USDCAD);

     strArray.append(USDCHF);
     strArray.append(USDCNH);
     strArray.append(USDHKD);
     strArray.append(USDJPY);

     strArray.append(USDMXN);
     strArray.append(USDNOK);
     strArray.append(USDSEK);
     strArray.append(USDTRY);
     strArray.append(USDZAR);
     strArray.append(USOIL);
     strArray.append(XAGUSD);
     strArray.append(XAUUSD);

     strArray.append(XPDUSD);
     strArray.append(XPTUSD);
        return strArray;
}

/**插入数据到redis
* @brief qReadisTest::josnStr
*/
void qDbManager::addDataRedis(qRedis *redis)
{
   m_redis=redis;
   QVector<QString> strDBArray=jsonUtil.getArray(K_dbName);
   qDebug()<<QString("%1%2").arg("shuzu").arg(strDBArray.count());
       int totle=strDBArray.size();
       for (int f = 0; f < totle; f++) {
           QString DB=strDBArray[f];
          // qDebug()<<QString("数据库%1").arg(DB);
          // QVector<QString> tableArray= this->tabelName(DB);
          QVector<QString> typeOptionsArray=jsonUtil.getArray(K_typeOptions);
         int numOptionsArray=typeOptionsArray.count();
          for (int h = 0; h < numOptionsArray; h++) {
              // QString tableName=tableArray[h];
                QString type=typeOptionsArray[h];
                strJson="";
               this->addText(f,type);


          }
       }

}

/**封装redis格式的文本
 * @brief qReadisTest::addJson
 * @param tableName
 */
void qDbManager::addText(int dbindex,const QString &type)
{
    //if(tableName.length()>0)
    //{

                QVector<QSqlDatabase> dbArray=createDBArray();
                QSqlDatabase db=dbArray[dbindex];
                QString dbName=db.databaseName();
             if(db.isValid())
             {
                     this->selectDateFrist(dbName,db,type);
                     this->selectDateSeconde(dbName,db,type);
             }
   // }
}

void qDbManager::selectDateFrist(const QString &dbName,const QSqlDatabase &db,const QString &type)
{

      QSqlQuery query(db);
      QString sql=QString("select * from %1_%2 order by id desc limit 0,2").arg(dbName.toLower()).arg(type);
      query.exec(sql);
     // QSqlRecord rec = query.record();
       strJson="[";
       while(query.next())
         {
                    strJson=strJson.append("[");
                    int ptime = query.record().indexOf("ptime");
                    if(ptime>0)
                    {

                    QDateTime time = query.value("ptime").toDateTime();
                    int ptime = time.toTime_t();   //将当前时间转为时间戳
                    strJson=strJson.append("%1%2").arg(ptime).arg(",");
                    }
                    int open = query.record().indexOf("open");
                    if(open>0)
                    {
                    float open=query.value("open").toFloat();
                    strJson=strJson.append("%1%2").arg(QString("%1").arg(open)).arg(",");
                    }

                    int close = query.record().indexOf("close");
                    if(close>0)
                    {
                     float close=query.value("close").toFloat();
                     strJson=strJson.append("%1%2").arg(QString("%1").arg(close)).arg(",");
                    }

                    int high = query.record().indexOf("high");
                    if(high>0)
                    {
                     float high=query.value("high").toFloat();
                     strJson=strJson.append("%1%2").arg(QString("%1").arg(high)).arg(",");
                    }

                    int low = query.record().indexOf("low");
                    if(low>0)
                    {
                     float low=query.value("low").toFloat();
                     strJson=strJson.append("%1%2").arg(QString("%1").arg(low)).arg(",");
                    }

                    int volume = query.record().indexOf("volume");
                    if(volume>0)
                    {
                     int volume=query.value("volume").toInt();
                     strJson=strJson.append("%1").arg(QString("%1").arg(volume));
                    }else
                    {
                      strJson = strJson.left(strJson.length() - 1);
                    }
                      strJson=strJson.append("],");
         }
          if(strJson.length()>1)
          {
                   strJson = strJson.left(strJson.length() - 1);
          }
                   strJson=strJson.append("]");
           if(strJson.length()>2)
           {
                  // qDebug()<<QString("文本封装结束%1").arg(strJson);
                   QString key=QString("%1__%2").arg(dbName.toLower()).arg(type);
                   m_redis->set(key,QString("%1").arg(strJson));
           }
}

void qDbManager::selectDateSeconde(const QString &dbName,const QSqlDatabase &db,const QString &type)
{

    QSqlQuery query(db);
    QString sql=QString("select * from %1_%2 order by id desc limit 0,100").arg(dbName.toLower()).arg(type);
    query.exec(sql);
       strJson="[";
       while(query.next())
         {
                    strJson=strJson.append("[");
                    int ptime = query.record().indexOf("ptime");
                    if(ptime>0)
                    {
                    QDateTime time = query.value("ptime").toDateTime();   //获取当前时间
                    int ptime = time.toTime_t();   //将当前时间转为时间戳
                     strJson=strJson.append("%1%2").arg(ptime).arg(",");
                    }


                    int open = query.record().indexOf("open");
                    if(open>0)
                    {
                    float open=query.value("open").toFloat();
                    strJson=strJson.append("%1%2").arg(QString("%1").arg(open)).arg(",");
                    }


                    int close = query.record().indexOf("close");
                    if(close>0)
                    {
                        float close=query.value("close").toFloat();
                         strJson=strJson.append("%1%2").arg(QString("%1").arg(close)).arg(",");
                    }


                    int high = query.record().indexOf("high");
                    if(high>0)
                    {
                        float high=query.value("high").toFloat();
                         strJson=strJson.append("%1%2").arg(QString("%1").arg(high)).arg(",");
                    }

                    int low = query.record().indexOf("low");
                    if(low>0)
                    {
                        float low=query.value("low").toFloat();
                         strJson=strJson.append("%1%2").arg(QString("%1").arg(low)).arg(",");
                    }

                    int volume = query.record().indexOf("volume");
                    if(volume>0)
                    {
                        int volume=query.value("volume").toInt();
                         strJson=strJson.append("%1").arg(QString("%1").arg(volume));
                    }else
                    {
                         strJson = strJson.left(strJson.length() - 1);
                    }

                         strJson=strJson.append("],");
         }
          if(strJson.length()>1)
          {
                   strJson = strJson.left(strJson.length() - 1);
           }
          strJson=strJson.append("]");
           if(strJson.length()>2)
           {
            QString key=QString("%1_%2").arg(dbName.toLower()).arg(type);
           m_redis->lpush(key,QString("%1").arg(strJson));
           }
}



/**查询数据库的表
 * @brief qDbManager::tabelName
 * @param db
 * @return
 */
QVector<QString> qDbManager::tabelName(const QString &db)
{
     QVector<QString> tabelArray;
     QVector<QSqlDatabase> dbArray=createDBArray();
    // QVector<QString> dbstr=readFile();
     int sum=dbArray.count();
     for (int g =0;  g< sum; g++)
     {
      QSqlDatabase dbase=dbArray[g];
         QSqlQuery query(dbase);
         query.exec(QString("select table_name from information_schema.tables where table_schema='%1'").arg(db));
         while(query.next())
         {
             QString str=query.value(0).toString();
             if(str.indexOf("_")!=-1)
             {
                  tabelArray.append(query.value(0).toString());
             }
         }
           return tabelArray;

     }
     return tabelArray;
}

/**查询表
 * @brief qDbManager::getselect
 */
void qDbManager::getselect()
{
    qDebug()<<"aaa";
    QSqlQuery query;
    query.exec("select * from factory order by id desc limit 0,2");
    int row = 0;
     QJsonObject nestedMap;
    while(query.next())
    {
        row++;
     QJsonObject factory;
     int Did=query.value("id").toInt();
     factory.insert("id",Did);
     QString manufactory=query.value("manufactory").toString();
     factory.insert("manufactory",manufactory);
     QString address=query.value("address").toString();
     factory.insert("address",address);
      qDebug()<<Did;
      qDebug()<<address;

     nestedMap.insert(QString::number(row, 10),factory);
    }


    QJsonDocument document;
    document.setObject(nestedMap);
    QByteArray byte_array = document.toJson(QJsonDocument::Compact);
    QString json_str(byte_array);
    qDebug()<<json_str;
    qDebug()<<"bbb";
}


