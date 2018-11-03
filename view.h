#ifndef VIEW_H
#define VIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>

#include "button.h"
#include "window3.h"
#include "class_head.h"

class View : public QGraphicsView
{
public:
    View();

private slots:
    void btn_Pause_clicked(Qt::MouseButton);
    void keyReleaseEvent(QKeyEvent*) override;
    //void btn_Restart_clicked(Qt::MouseButton);

private:
    void _init_view_elements();
    button mBtnPause;
    //button mBtnRestart;
    Head Ssnake;
    QGraphicsScene mScene;
    Window3 *pause_menu;
};

#endif // VIEW_H
