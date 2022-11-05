#ifndef UTILS_H
#define UTILS_H
#include "common.h"
namespace Utils {
    //文件目录是否存在
    inline bool PathExists(const QString &_path)
    {return ((!_path.isEmpty()) && QFileInfo(_path).exists());}
    //创建文件夹
    bool CreateDir(const QString &_dirName);

    template<typename T>
    void createPage22StackedWidget(int page_num,T *tt_page,QStackedWidget*tt_Stacked)
    {
        qDebug()<<Q_FUNC_INFO<<__LINE__;
        tt_page = new T();
        tt_Stacked->addWidget(tt_page);
        tt_Stacked->insertWidget(page_num,tt_page);
        return;
    }

    //删除文件夹下所有文件
    void deleteDirectory(const QString &path);
    //判断IP地址及端口是否在线
    bool ipLive(const QString &ip, int port, int timeout = 1000);
    //判断是否通外网
    bool isWebOk();

    QString byteArrayToHexStr(const QByteArray &data);
    char hexStrToChar(char data);
    QByteArray hexStrToByteArray(const QString &data);

    QString MD5_Str(const QString &source);
    QString appPath();

}

namespace Resquest {
QString User_Agent();
}
#endif // UTILS_H
