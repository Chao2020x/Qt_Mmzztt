#include "bottomform.h"
#include "ui_bottomform.h"

BottomForm::BottomForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BottomForm)
{
    ui->setupUi(this);

    ui->widget_2->setStyleSheet(".QWidget{background:#FFFFFF;border:1px solid #FFFFFF;border-radius:20px;}");

}

BottomForm::~BottomForm()
{
    delete ui;
}
