#ifndef HOMEMMTAG_H
#define HOMEMMTAG_H

#include <QWidget>

namespace Ui {
class HomeMMTag;
}

class HomeMMTag : public QWidget
{
    Q_OBJECT

public:
    explicit HomeMMTag(QWidget *parent = nullptr);
    ~HomeMMTag();


    void ShowHomeMMTagContent(const QString &url, const QString &title, const QString &time);


    QSize sizeHint() const override;
private:
    Ui::HomeMMTag *ui;

};

#endif // HOMEMMTAG_H
