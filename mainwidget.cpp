#include "mainwidget.h"
#include "ui_mainwidget.h"
#include "utils/utils.h"
#define WIDGETPAGE_homePage   0           //首页
#define WIDGETPAGE_photoPage  1           //写真馆
#define WIDGETPAGE_beautyPage 2           //潮拍馆
MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    this->setWindowTitle(QString::fromUtf8("美之图(MMZZTT.COM)"));
    this->initMainWidgetHead();

    Utils::createPage22StackedWidget<HomePageForm>(WIDGETPAGE_homePage,m_homePageFrom,ui->stackedWidget);
}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::NavbuttonClick6()
{
    NavButton *b = (NavButton *)sender();
#if DEBUG_FUNC
    qDebug()<< Q_FUNC_INFO << __LINE__
            << "当前按下:" << b->text();
#endif
    {
        QString tt_sql = "当前按下[导航栏]中:";
        tt_sql.append(b->text());

    }

    for (int i = 0; i < btns6.count(); i++) {
        NavButton *btn = btns6.at(i);
        btn->setChecked(b == btn);

//        if(b == ui->AboutMe){
//            emit sig_ClickedAboutMePage();
//        }

//        if(b == btn){
//            if(i > ui->stackedWidget_OtherUI->count()) continue;
//            ui->stackedWidget_OtherUI->setCurrentIndex(i);
//            ui->stackedWidget_OtherUI->currentWidget()->setFocusPolicy(Qt::StrongFocus);
//        }
    }
}

void MainWidget::initMainWidgetHead()
{
#if DEBUG_FUNC
    qDebug()<<Q_FUNC_INFO<<__LINE__;
#endif
    QColor normalBgColor = QColor("#FFFFFF");
    QColor hoverBgColor = QColor("#FFFFFF");
    QColor checkBgColor = QColor("#FFFFFF");

    QColor normalTextColor = QColor("#999");
    QColor hoverTextColor = Qt::black;
    QColor checkTextColor = QColor("#333");

    //头部背景色
    ui->widgetNav6->setStyleSheet("color:#292929; background-color: #FFFFFF;");
    // 首页-写真馆-潮拍馆
    btns6 <<ui->homePage <<ui->photoPage <<ui->beautyPage;
    for (int i = 0; i < btns6.count(); i++) {
        NavButton *btn = btns6.at(i);
        btn->setPaddingLeft(20);
        btn->setShowLine(false);
        btn->setTextAlign(NavButton::TextAlign_Center);
        btn->setLinePosition(NavButton::LinePosition_Bottom);

        btn->setNormalBgColor(normalBgColor);
        btn->setHoverBgColor(hoverBgColor);
        btn->setCheckBgColor(checkBgColor);
        btn->setNormalTextColor(normalTextColor);
        btn->setHoverTextColor(hoverTextColor);
        btn->setCheckTextColor(checkTextColor);

        connect(btn, SIGNAL(clicked(bool)), this, SLOT(NavbuttonClick6()));
    }
    //设置整体圆角
    ui->widgetNav6->setStyleSheet(".QWidget{background:#FFFFFF;border:1px solid #FFFFFF;border-radius:20px;}");

    for(auto each_page : ui->stackedWidget->findChildren<QWidget*>()){

        ui->stackedWidget->removeWidget(each_page);
        each_page->deleteLater();
    }

    ui->label_title->setToolTip("宅男圣地美之图，满足你的所有幻想");
}

#include <QResizeEvent>
void MainWidget::resizeEvent(QResizeEvent *event)
{

}

