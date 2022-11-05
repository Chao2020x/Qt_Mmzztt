#ifndef RESQUESTS_H
#define RESQUESTS_H
#include "common.h"
#include <QObject>

class Resquests:public QObject
{
    Q_OBJECT

private:
    QString User_Agent;

    //网络四件套
    QNetworkAccessManager *tt_manager;
    QNetworkRequest tt_request;
    QNetworkReply *tt_reply;
    QEventLoop tt_loop;

public:

    QByteArray ContentArray;

    Resquests(QObject *parent = nullptr);
    ~Resquests();
    void Get(const QString &_url);
    QByteArray Text();

    void SetRawHeader(const QByteArray &headerName, const QByteArray &value);
    QPixmap ToPixmap();

signals:
    void sig_RequestSuccess();
    void sig_RequestFailure();

public slots:
    void slot_RequestFinished(QNetworkReply *_reply);

};

#endif // RESQUESTS_H
