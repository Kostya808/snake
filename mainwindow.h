#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "window2.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    Window2 *window;
};

#endif // MAINWINDOW_H
