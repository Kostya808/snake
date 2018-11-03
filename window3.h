#ifndef WINDOW3_H
#define WINDOW3_H

#include <QDialog>

namespace Ui {
class Window3;
}

class Window3 : public QDialog
{
    Q_OBJECT

public:
    explicit Window3(QWidget *parent = nullptr);
    ~Window3();

private:
    Ui::Window3 *ui;
};

#endif // WINDOW3_H
