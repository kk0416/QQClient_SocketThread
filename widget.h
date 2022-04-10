#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_BtnOK_clicked();

    void on_Btncancel_clicked();

    void on_Btnrgs_clicked();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
