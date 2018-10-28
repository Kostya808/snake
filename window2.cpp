#include "window2.h"
#include "ui_window2.h"
#include "view.h"

Window2::Window2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Window2)
{
    ui->setupUi(this);
}

Window2::~Window2()
{
    delete ui;
}

void Window2::on_pushButton_clicked()
{
    View v;
    v.show();
    //QGraphicsView->QGraphicsScene->QGraphicsItem
}
