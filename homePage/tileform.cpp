#include "tileform.h"
#include "ui_tileform.h"

TileForm::TileForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TileForm)
{
    ui->setupUi(this);
    ui->label->setScaledContents(true);
    ui->label_2->setScaledContents(true);
}

TileForm::~TileForm()
{
    delete ui;
}

#include <QMouseEvent>
#include <QDebug>
void TileForm::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        auto pos = event->pos();
        auto pos1_x = ui->label_2->x();
        auto pos1_y = ui->label->y() + ui->label->height();
        if(pos.x() < pos1_x && pos.y() < pos1_y){
            qDebug()<<"第一幅图1111111111111";
        }else{
            qDebug()<<"第二幅图2222222222222";
        }
    }
}

