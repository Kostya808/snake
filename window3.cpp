#include "window3.h"
#include "ui_window3.h"

Window3::Window3(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Window3)
{
    ui->setupUi(this);
}

Window3::~Window3()
{
    delete ui;
}
