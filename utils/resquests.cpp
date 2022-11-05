#include "resquests.h"
#include "utils.h"
Resquests::Resquests(QObject *parent):QObject(parent),
    User_Agent(Resquest::User_Agent())
//    tt_manager(new QNetworkAccessManager)
{
    tt_manager = new QNetworkAccessManager;
    bool bSupp = QSslSocket::supportsSsl();
    QString buildVersion = QSslSocket::sslLibraryBuildVersionString();
    QString version = QSslSocket::sslLibraryVersionString();
    qDebug()<< __FUNCTION__ << bSupp << buildVersion << version;

    tt_request.setRawHeader("User-Agent",this->User_Agent.toLatin1());

    tt_request.setRawHeader("Keep-Alive","300");
    tt_request.setRawHeader("Connection","keep-alive");
    tt_request.setRawHeader("Accept","text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8");
    tt_request.setRawHeader("Accept-Language","zh-CN,en-US,zh,en;q=0.9");
    tt_request.setRawHeader("Accept-Encoding","deflate");
    tt_request.setRawHeader("Referer","https://mmzztt.com/");
//    tt_request.setRawHeader("Remote Address","58.218.199.83:443");

    connect(tt_manager, SIGNAL(finished(QNetworkReply *)), this,SLOT(slot_RequestFinished(QNetworkReply *)));
    qDebug()<<__FUNCTION__<<__LINE__;
}

Resquests::~Resquests()
{
    delete  tt_reply;
    delete  tt_manager;
}

#include <QFileDialog>
#include <QSize>
#include <QPainter>
#include <QImage>
#include <QBuffer>
void Resquests::Get(const QString &_url)
{
    ContentArray.clear();
    tt_request.setUrl(QUrl(_url));
    tt_reply = tt_manager->get(tt_request);
}

void Resquests::SetRawHeader(const QByteArray &headerName, const QByteArray &value)
{
    tt_request.setRawHeader(headerName,value);
}

QPixmap Resquests::ToPixmap()
{
    QPixmap image999;
    if(!ContentArray.isEmpty()){
        image999.loadFromData(ContentArray);
        return image999;
    }
    return QPixmap();
}


#include <QtXmlPatterns/QXmlQuery>
void Resquests::slot_RequestFinished(QNetworkReply *_reply)
{
    //判断网页是否存在，是否有效
    int statusCode = _reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    qDebug()<<"Status code is: "<<statusCode;
    ContentArray.clear();
    switch (statusCode) {
    case 200:
        ContentArray.append(_reply->readAll());
        emit sig_RequestSuccess();
        break;
    default:
        emit sig_RequestFailure();
    }
    _reply->deleteLater();

    QDomDocument doc("mydocument");
    doc.setContent(ContentArray);

    //打印所有的节点
    QDomElement docElem = doc.documentElement();
    qDebug()<<docElem.nodeName()<<docElem.nodeType()<<docElem.nodeValue();

    QXmlQuery query(QXmlQuery::XSLT20);
    query.setQuery(ContentArray, QUrl("/html/body/section[2]/div/div/main"));

    if(!query.isValid()){
        qDebug()<<"参数查询有误";
    }else{
        QString result;
        query.evaluateTo(&result);
        qDebug()<<result;
    }
    qDebug()<<"OK";
}
