#include "bottomleftform.h"
#include "ui_bottomleftform.h"
#include <QList>
#include "homemmtag.h"
BottomLeftForm::BottomLeftForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BottomLeftForm)
{
    ui->setupUi(this);
    this->initBottomLeftForm();
    ui->pushButton->setStyleSheet("background-color:transparent");

    QStringList qss;
    qss.append(QString("QPushButton{border-style:none;color:%1;background:%2;}")
               .arg("#000000").arg("transparent"));
    qss.append(QString("QPushButton:hover{color:%1;background:%2;}")
               .arg("#ff0000").arg("transparent"));
    qss.append(QString("QPushButton:pressed{color:%1;background:%2;}")
               .arg("#ffffff").arg("transparent"));
    ui->pushButton->setStyleSheet(qss.join(""));
}

BottomLeftForm::~BottomLeftForm()
{
    delete ui;
}

void BottomLeftForm::initBottomLeftForm()
{

    QList<QWidget *> widgets1;
    int columnCount1 = 2;
    for (int i = 0; i < 10; i ++) {
         HomeMMTag *tag = new HomeMMTag;
         tag->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);
         widgets1.append(tag);
    }

    ui->widget_2->setWidget(widgets1,columnCount1);
    ui->widget_2->setMargin(2);

    ui->widget_2->setBorder(0,"");
}
