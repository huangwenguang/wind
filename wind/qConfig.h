#ifndef QCONFIGCONSTANT_H
#define QCONFIGCONSTANT_H
#include "QDebug"

#endif // QCONFIGCONSTANT_H
#define K_dbName "DbNames"
#define K_redis_host "Redis_host"
#define K_redis_ip_url "redis_ip_url"
#define K_redis_port "redis_port"
#define K_qMYSQL "QMYSQL"
#define K_mysql_conn "Mysql_conn"
#define K_userName "username"
#define K_pwd "pwd"
#define K_mysql_hostName "mysql_hostname"
#define K_mysql_port "mysql_port"
#define K_typeOptions "TypeOptions"


#define K_AUDJPY "AUDJPY"
#define K_AUDNZD "AUDNZD"
#define K_AUDUSD "AUDUSD"
#define K_BUND   "BUND"
#define K_CADCHF "CADCHF"
#define K_COPPER "COPPER"
#define K_EURAUD "EURAUD"
#define K_EURCAD "EURCAD"
#define K_EURCHF "EURCHF"
#define K_EURGBP "EURGBP"

#define K_EURJPY "EURJPY"
#define K_EURNZD "EURNZD"
#define K_EURUSD "EURUSD"
#define K_GBPAUD "GBPAUD"
#define K_GBPCAD "GBPCAD"
#define K_GBPCHF "GBPCHF"
#define K_GBPJPY "GBPJPY"
#define K_GBPNZD "GBPNZD"
#define K_GBPUSD "GBPUSD"
#define K_NGAS "NGAS"

#define K_NZDCAD "NZDCAD"
#define K_NZDCHF "NZDCHF"
#define K_NZDJPY "NZDJPY"
#define K_NZDUSD "NZDUSD"
#define K_UKOIL "UKOIL"
#define K_USDCAD "USDCAD"
#define K_USDCHF "USDCHF"
#define K_USDCNH "USDCNH"
#define K_USDHKD "USDHKD"
#define K_USDJPY "USDJPY"

#define K_USDMXN "USDMXN"
#define K_USDNOK "USDNOK"
#define K_USDSEK "USDSEK"
#define K_USDTRY "USDTRY"
#define K_USDZAR "USDZAR"
#define K_USOIL  "USOIL"
#define K_XAGUSD "XAGUSD"
#define K_XAUUSD "XAUUSD"
#define K_XPDUSD "XPDUSD"
#define K_XPTUSD "XPTUSD"



//release和Debug
#ifdef QT_NO_DEBUG

#define K_jsonURL "http://www.huangwenguang.com/config.json" //win

#else

#define K_jsonURL  "http://127.0.0.1:8081/config.json"
#endif



#define kForExportProject 1

#if kForExportProject

#else

#endif



//#define ISShow_qDebug 1 发布时注释
//#ifdef ISShow_qDebug
//#define qDebug(format, ...)  \
//qDebug(@"file:%s line:%d\nNSLog:" format,strrchr(__FILE__,'/'),__LINE__, ## __VA_ARGS__)
//#else
//#define qDebug(format, ...)
//#endif
