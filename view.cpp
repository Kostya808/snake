#include "view.h"
#include <QDebug>

View::View()
{
    setRenderHint(QPainter::Antialiasing);
    setCacheMode(QGraphicsView::CacheBackground);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setWindowTitle("Snake");
    setFrameStyle(0);
    setSceneRect(0, 0, 900, 900);
    setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));
    setFixedSize(900, 900);
    mScene.setItemIndexMethod(QGraphicsScene::NoIndex);

    setScene(&mScene);
    _init_view_elements();
}

void View::_init_view_elements() {
    mBtnPause.setPos(45, 45);
    mBtnPause.setGeometry(100, 50);
    connect(&mBtnPause, &button::btnMouseReleaseEvent, this, &View::btn_Pause_clicked);
    mBtnRestart.setPos(150, 45);
    mBtnRestart.setGeometry(100, 50);
    connect(&mBtnRestart, &button::btnMouseReleaseEvent, this, &View::btn_Restart_clicked);
    mScene.addItem(&mBtnPause);
    mScene.addItem(&mBtnRestart);
}

void View::btn_Pause_clicked(Qt::MouseButton) {
    qWarning() <<"yt";
}

void View::btn_Restart_clicked(Qt::MouseButton) {
    qWarning() <<"ty";
}

