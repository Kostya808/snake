#ifndef CLASS_HEAD_H
#define CLASS_HEAD_H

#include "base_class.h"
#include <QObject>
#include <QGraphicsItem>
#include <QPixmap>
#include <QTimer>
#include <QVector>

// смотри класс Head

class Body : public QObject, public QGraphicsItem
{
    Q_OBJECT

    enum class eStateBody {
        BMoving
        ,BMove_left
        ,BMove_right
        ,BMove_dawn
        ,BEat
        ,BEnd
    };

    struct spriteDataBody {
        int mWidth{16};
        int mHeight{16};
        int mFrames{1};
        int mCurrentFrame{0};
        int mOffset{16};
        int mBorder{0};
    };

public:
    Body();

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    void move_body();
    void move_left_body();
    void move_right_body();
    void move_dawn_body();
    void eat();
    void end();

private slots:
    void next_frame_body();

private:
    const spriteDataBody &_csd() const;
    qreal mDx{2.};
    eStateBody mStateBody{eStateBody::BMoving};

    int mCurrentFrame{0};
    QTimer mTimerBody;

    QVector<QPair<QPixmap, spriteDataBody>> mvPixmapsBody;
};

class Head : /*public Base,*/ public QObject, public QGraphicsItem
{
    Q_OBJECT

enum class eState { // состояния бошки:
    Moving          // движение вверх
    ,Move_left      // налево
    ,Move_right     // направо
    ,Move_dawn      // вниз
    ,Eat            // похавал
    ,End            // умер
};

struct spriteData {         // параметры спрайта:
    int mWidth{16};         // ширина
    int mHeight{16};        // высота
    int mFrames{1};         // кол-во спрайтов
    int mCurrentFrame{0};   // текущий спрайт
    int mOffset{16};        // сдвиг
    int mBorder{0};         // кол-во пикселей меджу спрайтами
};

public:
    Head();

    QRectF boundingRect() const override;   // прямоугольник, ограничивающий объект на графической сцене (функция boundingRect() перегружена (override))
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;    // отрисовка объекта на графической сцене

    void move();
    void move_left();
    void move_right();
    void move_dawn();
    void eat();
    void end();

private slots:
    void next_frame();

private:
    Body body;  // пыталась замутить тело
    const spriteData &_csd() const;
    qreal mDx{2.};  // шаг передвижения
    eState mState{eState::Moving};  // текущее состояние

    int mCurrentFrame{0};   // текущий спрайт
    QTimer mTimer;          // таймер

    QVector<QPair<QPixmap, spriteData>> mvPixmaps;  // вектор пар <картинка, ее данные>
};
// иди в class_head.cpp
#endif
