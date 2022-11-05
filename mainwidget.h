#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include "navbutton.h"
#include "homepageform.h"

#include "utils/common.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWidget; }
QT_END_NAMESPACE

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

private slots:
    void NavbuttonClick6();

private:
    Ui::MainWidget *ui;
    QList<NavButton *> btns6;
    void initMainWidgetHead(void);

    HomePageForm *m_homePageFrom;

    void resizeEvent(QResizeEvent *event) override;
};
#endif // MAINWIDGET_H
