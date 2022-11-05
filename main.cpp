#include "mainwidget.h"

#include <QApplication>
#include "utils/utils.h"
#include "utils/resquests.h"
#include <QString>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qDebug()<<Resquest::User_Agent();
    MainWidget w;
    Resquests kk;
//    kk.Get("https://s.iimzt.com/thumb/69723/480.jpg");
    kk.Get("https://mmzztt.com/");
    w.show();

    return a.exec();
}
