#include "view.h"
#include <QDebug>
#include <QKeyEvent>
#include <QGraphicsItem>
#include <QPointF>

View::View()
{
    // в конструкторе мутим графическую сцену
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

void View::_init_view_elements() {  // инициализация элементов графической сцены
    // кнопка "Pause"
    mBtnPause.setPos(45, 45);
    mBtnPause.setGeometry(100, 50);
    connect(&mBtnPause, &button::btnMouseReleaseEvent, this, &View::btn_Pause_clicked);
    // змея
    Ssnake.setPos(100, 300); // позиция (координаты) на сцене
    mScene.addItem(&mBtnPause); // добавление кнопки
    mScene.addItem(&Ssnake);    // добавление змеи
}

void View::btn_Pause_clicked(Qt::MouseButton) { // обработка событий при нажатии на "Pause"
    pause_menu = new Window3(this);
    pause_menu->show();
}

void View::keyReleaseEvent(QKeyEvent *apEvent) { // обработка событий при нажатии на клавиши
    switch (apEvent->key()) {
    case Qt::Key_A: {
        Ssnake.move_left();
        break;
    }
    case Qt::Key_D: {
        Ssnake.move_right();
        break;
    }
    case Qt::Key_W: {
        Ssnake.move();
        break;
    }
    case Qt::Key_S: {
        Ssnake.move_dawn();
        break;
    }
    }
}
