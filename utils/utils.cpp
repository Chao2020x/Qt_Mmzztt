#include "utils.h"

bool Utils::CreateDir(const QString &_dirName)
{
    QDir gg_dir(_dirName);
    if(gg_dir.exists()) {return true;}
    return gg_dir.mkpath(_dirName);
}

void Utils::deleteDirectory(const QString &path)
{
    QDir dir(path);
    if (!dir.exists()) {
        return;
    }

    dir.setFilter(QDir::AllEntries | QDir::NoDotAndDotDot);
    QFileInfoList fileList = dir.entryInfoList();

    for (QFileInfo &fi: fileList) {
        if (fi.isFile()) {
            fi.dir().remove(fi.fileName());
        } else {
            deleteDirectory(fi.absoluteFilePath());
            dir.rmdir(fi.absoluteFilePath());
        }
    }
}


#include <QEventLoop>
#include <QTimer>
#include <QTcpSocket>
#include <QObject>
bool Utils::ipLive(const QString &ip, int port, int timeout)
{
    //局部的事件循环,不卡主界面
    QEventLoop eventLoop;

    //设置超时
    QTimer timer;
    QObject::connect(&timer, SIGNAL(timeout()), &eventLoop, SLOT(quit()));
    timer.setSingleShot(true);
    timer.start(timeout);

    QTcpSocket tcpSocket;
    QObject::connect(&tcpSocket, SIGNAL(connected()), &eventLoop, SLOT(quit()));
    tcpSocket.connectToHost(ip, port);
    eventLoop.exec();
    bool ok = (tcpSocket.state() == QAbstractSocket::ConnectedState);
    return ok;
}



bool Utils::isWebOk()
{
    //能接通百度IP 115.239.211.112 说明可以通外网
    return ipLive("www.baidu.com", 80);
}

QString Utils::byteArrayToHexStr(const QByteArray &data)
{
    QString temp = "";
    QString hex = data.toHex();

    for (int i = 0; i < hex.length(); i = i + 2)
    {
        temp += hex.mid(i, 2) + " ";
    }

    return temp.trimmed().toUpper();
}

char Utils::hexStrToChar(char data)
{
    if ((data >= '0') && (data <= '9'))
    {
        return data - 0x30;
    }
    else if ((data >= 'A') && (data <= 'F'))
    {
        return data - 'A' + 10;
    }
    else if ((data >= 'a') && (data <= 'f'))
    {
        return data - 'a' + 10;
    }
    else
    {
        return (-1);
    }
}

QByteArray Utils::hexStrToByteArray(const QString &data)
{
    QByteArray senddata;
    int hexdata, lowhexdata;
    int hexdatalen = 0;
    int len = data.length();
    senddata.resize(len / 2);
    char lstr, hstr;

    for (int i = 0; i < len;)
    {
        hstr = data.at(i).toLatin1();
        if (hstr == ' ')
        {
            i++;
            continue;
        }

        i++;
        if (i >= len)
        {
            break;
        }

        lstr = data.at(i).toLatin1();
        hexdata = hexStrToChar(hstr);
        lowhexdata = hexStrToChar(lstr);

        if ((hexdata == 16) || (lowhexdata == 16))
        {
            break;
        }
        else
        {
            hexdata = hexdata * 16 + lowhexdata;
        }

        i++;
        senddata[hexdatalen] = (char)hexdata;
        hexdatalen++;
    }

    senddata.resize(hexdatalen);
    return senddata;
}

#include <QCryptographicHash>
QString Utils::MD5_Str(const QString &source)
{
    QByteArray value;

    value = QCryptographicHash::hash(source.toLocal8Bit(),QCryptographicHash::Md5);

    return value.toHex().data();
}

#include <QApplication>
QString Utils::appPath()
{
#ifdef Q_OS_ANDROID
    //return QString("/sdcard/Android/%1").arg(appName());
    return QString("/storage/emulated/0/%1").arg(appName());
#else
    return qApp->applicationDirPath();
#endif
}

QString Resquest::User_Agent()
{
    QFile file(":/Chrome.txt");
    if(file.open(QIODevice::ReadOnly)){
        QList<QByteArray> User_Agent_List = file.readAll().split('\n');
        qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
        int index =qrand()%User_Agent_List.length();

        file.close();
        return User_Agent_List.at(index).trimmed();
    }
    return QString("Mozilla/5.0 (Windows NT 10.0; Win64; x64) \
AppleWebKit/537.36 (KHTML, like Gecko) Chrome/99.0.4844.84 Safari/537.36");
}
