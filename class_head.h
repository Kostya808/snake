#ifndef CLASS_HEAD_H
#define CLASS_HEAD_H

#include "base_class.h"
#include <QObject>
#include <QGraphicsItem>
#include <QPixmap>
#include <QTimer>
#include <QVector>

//class Body : public Base, public QObject, public QGraphicsItem
//{
//    Q_OBJECT

//public:
//    Body(int, int);
//    void setx(int);
//    void sety(int);
//    ~Body() override;

//private slots:
//    void next_frame();

//private:
//    int mWidth{0};
//    int mHeight{0};
//    int mFrames{0};
//    int mCurrent{0};
//    int mOffset{0};
//    int mBorder{0};

//    QPixmap mPixMap;
//    QTimer mTimer;

//    int coox;
//    int cooy;
//    Body *next;
//};

class Head : /*public Base,*/ public QObject, public QGraphicsItem
{
    Q_OBJECT

enum class eState {
    Moving
    ,Eat
    ,End
};

struct spriteData {
    int mWidth{0};
    int mHeight{0};
    int mFrames{0};
    int mCurrentFrame{0};
    int mOffset{0};
    int mBorder{0};
};

public:
    Head(/*int, int, int, int*/);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    void set_left_direction();
    void set_right_direction();
    void move();
    void eat();
    void end();

private slots:
    void next_frame();

private:
    const spriteData &_csd() const;
    qreal mDx{2.};
    eState mState{eState::Moving};

    int mCurrentFrame{0};
    QTimer mTimer;

    QVector<QPair<QPixmap, spriteData>> mvPixmaps;

//    int new_x, new_y, score, type_body, type_head;
//    char course;
//    Body *next;
//    Body *tail;

};

#endif
