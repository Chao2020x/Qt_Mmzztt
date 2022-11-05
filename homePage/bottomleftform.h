#ifndef BOTTOMLEFTFORM_H
#define BOTTOMLEFTFORM_H

#include <QWidget>

namespace Ui {
class BottomLeftForm;
}

class BottomLeftForm : public QWidget
{
    Q_OBJECT

public:
    explicit BottomLeftForm(QWidget *parent = nullptr);
    ~BottomLeftForm();

private:
    Ui::BottomLeftForm *ui;

    void initBottomLeftForm();
};

#endif // BOTTOMLEFTFORM_H
