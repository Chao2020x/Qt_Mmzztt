#ifndef BOTTOMFORM_H
#define BOTTOMFORM_H

#include <QWidget>

namespace Ui {
class BottomForm;
}

class BottomForm : public QWidget
{
    Q_OBJECT

public:
    explicit BottomForm(QWidget *parent = nullptr);
    ~BottomForm();

private:
    Ui::BottomForm *ui;
};

#endif // BOTTOMFORM_H
