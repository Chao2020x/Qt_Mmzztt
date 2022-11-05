#include "homemmtag.h"
#include "ui_homemmtag.h"

HomeMMTag::HomeMMTag(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HomeMMTag)
{
    ui->setupUi(this);
    ui->label_title->setStyleSheet("QLabel:hover{background-color:transparent;color: #ff0000;}");
    ui->label_title->setText(QString("简直无敌了！国内情趣写真的天花板：杨晨晨"));
    ui->label_time->setText(QString("2022-06-04 20:26:34"));
}

HomeMMTag::~HomeMMTag()
{
    delete ui;
}

void HomeMMTag::ShowHomeMMTagContent(const QString &url, const QString &title, const QString &time)
{
    Q_UNUSED(url);
    ui->label_title->setText(title);
    ui->label_time->setText(time);
}

QSize HomeMMTag::sizeHint() const
{
    return QSize(720,600);
}


