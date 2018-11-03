#include "class_head.h"
#include "base_class.h"
#include <QPainter>
#include <cstdio>

//Body::Body(int set_x, int set_y) {
//    mPixMap.load(":/Snake.png");

//    mWidth = 64;
//    mHeight = 64;
//    mFrames = 16;
//    mOffset = 65;
//    mBorder = 0;
////    next = nullptr;
////    set_x(set_x);
////    set_y(set_y);
////    setx(set_x);
////    sety(set_y);
//    connect(&mTimer, &QTimer::timeout, this, &Body::next_frame);
//    mTimer.start(100);
//}

//void Body::setx(int set_x) {
//    coox = set_x;
//}
//void Body::sety(int set_y) {
//    cooy = set_y;
//}

////int Body::get_x() {
////    return coox;
////}
//Head::
////void Body::get_y() {

////}

//Body::~Body() {
//    delete next;
//}

////void Body::next_frame() {

////    QGraphicsItem::update;
////}

Head::Head(/*int add_x, int add_y, int t1, int t2*/) /*: new_x(add_x), new_y(add_y), score(0), type_body(t2), type_head(t1)*/ {
//    x = add_x;
//    y = add_y;
//    course = 't';
//    tail = new Body(add_x, add_y);
//    score = 0;
    mvPixmaps.reserve((int)eState::End);

    QPair<QPixmap, spriteData> tmp;

    tmp.first.load(":/Snake.png");
    tmp.second.mWidth = 16;
    tmp.second.mHeight = 32;
    tmp.second.mCurrentFrame = 0;
    tmp.second.mFrames = 1;
    tmp.second.mOffset = 16;
    tmp.second.mBorder = 0;
    mvPixmaps.push_back(tmp);

    connect(&mTimer, &QTimer::timeout, this, &Head::next_frame);
    mTimer.start(100);
}

QRectF Head::boundingRect() const {
    return QRectF(0, 0, 16, 32);
}

void Head::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) {
    painter->drawPixmap(0, 0, mvPixmaps[0].first,
            (_csd().mOffset * mCurrentFrame + _csd().mBorder), 0, _csd().mWidth, _csd().mHeight);
}

const Head::spriteData &Head::_csd()const {
    return mvPixmaps[(int)mState].second;
}

void Head::next_frame() {
    switch (mState)
    {
    case eState::Moving: {
        move();
        break;
    }
    case eState::Eat: {
        break;
    }
    case eState::End: {
        break;
    }
    }
    mCurrentFrame++;
    if (mCurrentFrame >= mvPixmaps[(int)mState].second.mFrames) {
        mCurrentFrame = 0;
    }
    QGraphicsItem::update();
}

void Head::set_left_direction() {

}

void Head::set_right_direction() {

}

void Head::move() {
    setPos(pos().x(), pos().y() - mDx);
    mState = eState::Moving;
}

//void Head::lerotate() {

//}

void Head::eat() {

}

void Head::end() {

}



//Head::~Head()	{
//    delete tail;
//    delete next;
//}
