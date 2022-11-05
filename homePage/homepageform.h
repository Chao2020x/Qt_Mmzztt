#ifndef HOMEPAGEFORM_H
#define HOMEPAGEFORM_H

#include <QWidget>
#include "tileform.h"

namespace Ui {
class HomePageForm;
}

class HomePageForm : public QWidget
{
    Q_OBJECT

public:
    explicit HomePageForm(QWidget *parent = nullptr);
    ~HomePageForm();

private:
    Ui::HomePageForm *ui;

    TileForm *m_tileFrom;

    void initHomePageForm(void);

    void resizeEvent(QResizeEvent *event) override;
};

#endif // HOMEPAGEFORM_H
