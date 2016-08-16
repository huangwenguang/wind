#include "qNetWork.h"
#include <QtNetwork>
#include "QtDebug"

//定义函数回调指针
//typedef void (CALLBACK *FunCallBack)(QString *result);
////定义回调函数
//FunCallBack OnEvent=NULL;
////定义回调参数
//QString *result;
/**初始化 new
 * @brief qNetWork::qNetWork
 * @param parent
 */
qNetWork::qNetWork(QObject *parent) : QObject(parent)
{
    manager = new QNetworkAccessManager(this);
}
qNetWork::~qNetWork()
{}
/**开始请求
 * @brief qNetWork::startRequest
 * @param strurl
 */
void qNetWork::startRequest(QString strurl)
{
    this->strurl=strurl;
    connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(replyFinished(QNetworkReply*)));
    QUrl url;
    url.setUrl(this->strurl);
    QNetworkRequest request(this->strurl);
    manager->get(request);
}




/**完成请求
 * @brief qNetWork::replyFinished
 * @param reply
 */
void  qNetWork::replyFinished(QNetworkReply *reply)
{
      switch(reply->error())
      {
      case QNetworkReply::NoError:
          qDebug()<<"no error";
      {
          QTextCodec * cod=QTextCodec::codecForName("utf-8");
         QString str=cod->toUnicode(reply->readAll());

          emit returnData(str);

      }
          break;
      case QNetworkReply::ContentNotFoundError:
      {
          QUrl failedUrl;
          failedUrl = reply->request().url();
          int httpStatus = reply->attribute(
                      QNetworkRequest::HttpStatusCodeAttribute).toInt();
          QString reason = reply->attribute( QNetworkRequest::HttpReasonPhraseAttribute ).toString();
          qDebug()<<"url"<<failedUrl <<httpStatus<<"   "<<reason;
      }
          break;
      default:
      {
          qDebug()<<"Have error"<<reply->errorString()<<" error "<<reply->error();
      }
      }
      qDebug()<<"finished";
      delete reply;
}






