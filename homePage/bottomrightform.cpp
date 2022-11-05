#include "bottomrightform.h"
#include "ui_bottomrightform.h"

BottomRightForm::BottomRightForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BottomRightForm)
{
    ui->setupUi(this);
    this->initForm();
}

BottomRightForm::~BottomRightForm()
{
    delete ui;
}

void BottomRightForm::initForm()
{
    QString item = "街拍;自拍;明星";
    ui->widget_category->setLineWidth(4);
    ui->widget_category->setLineColor(Qt::red);
    ui->widget_category->setBgColorStart(Qt::transparent);
    ui->widget_category->setBgColorEnd(Qt::transparent);
    ui->widget_category->setBarColorStart(Qt::transparent);
    ui->widget_category->setBarColorEnd(Qt::transparent);
    ui->widget_category->setTextNormalColor(QColor(50, 50, 50));
    ui->widget_category->setTextSelectColor(QColor(255, 107, 107));
    ui->widget_category->setBarStyle(SliderBar::BarStyle_Line_Bottom);
    ui->widget_category->setItems(item);

    ui->widget_category->setCurrentIndex(2);

    ui->widget_category->setStyleSheet("border:4px solid #873;border-radius:20px;");
}
