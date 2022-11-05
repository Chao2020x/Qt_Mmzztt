#ifndef BOTTOMRIGHTFORM_H
#define BOTTOMRIGHTFORM_H

#include <QWidget>

namespace Ui {
class BottomRightForm;
}

class BottomRightForm : public QWidget
{
    Q_OBJECT

public:
    explicit BottomRightForm(QWidget *parent = nullptr);
    ~BottomRightForm();

private:
    Ui::BottomRightForm *ui;

    void initForm();
};

#endif // BOTTOMRIGHTFORM_H
