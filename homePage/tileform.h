#ifndef TILEFORM_H
#define TILEFORM_H

#include <QWidget>

namespace Ui {
class TileForm;
}

class TileForm : public QWidget
{
    Q_OBJECT

public:
    explicit TileForm(QWidget *parent = nullptr);
    ~TileForm();

private:
    Ui::TileForm *ui;

    void mousePressEvent(QMouseEvent *event) override;
};

#endif // TILEFORM_H
