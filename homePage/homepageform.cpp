#include "homepageform.h"
#include "ui_homepageform.h"

HomePageForm::HomePageForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HomePageForm)
{
    ui->setupUi(this);
    this->initHomePageForm();
}

HomePageForm::~HomePageForm()
{
    delete ui;
}

void HomePageForm::initHomePageForm()
{

}

#include <QResizeEvent>
#include <QDebug>
void HomePageForm::resizeEvent(QResizeEvent *event)
{
//    int height = event->size().height();
    int width = event->size().width();
    int now_h = int(double(width) * 0.168);
    ui->widget_type->setMaximumHeight(now_h);
//    qDebug()<<"大傻逼";

}
