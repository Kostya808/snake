#ifndef WIDGET_H
#define WIDGET_H

#include <QDialog>
#include <QWidget>
#include <QGraphicsScene>
#include <class_head.h>
#include <QDebug>
#include <QTimer>

namespace Ui {
class Widget;
}

class Widget : public QDialog
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    QGraphicsScene *scene;
    Body *sbody, *kbody;
    Head *shead, *khead;
    QTimer *timer;
};

#endif // WIDGET_H
