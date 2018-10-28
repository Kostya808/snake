#ifndef VIEW_H
#define VIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>

#include "button.h"

class View : public QGraphicsView
{
public:
    View();

private slots:
    void btn_Pause_clicked(Qt::MouseButton);
    void btn_Restart_clicked(Qt::MouseButton);

private:
    void _init_view_elements();
    button mBtnPause;
    button mBtnRestart;
    QGraphicsScene mScene;
};

#endif // VIEW_H
