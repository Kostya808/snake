#include "class_head.h"
#include "base_class.h"
#include <QPainter>
#include <cstdio>

Head::Head() {

    mvPixmaps.reserve((int)eState::End);    // размер вектора соответствует кол-ву состояний

    QPair<QPixmap, spriteData> tmp;         // буферная пара

    tmp.first.load(":/move_head_up.png");   // загрузка спрайта в пару
    mvPixmaps.push_back(tmp);               // добавление пары в вектор класса (далее то же самое)

    tmp.first.load(":/move_head_left.png");
    mvPixmaps.push_back(tmp);

    tmp.first.load(":/move_head_right.png");
    mvPixmaps.push_back(tmp);

    tmp.first.load(":/move_head_dawn.png");
    mvPixmaps.push_back(tmp);

    connect(&mTimer, &QTimer::timeout, this, &Head::next_frame);    // Соединяет сигнал от объекта отправителя с методом этого объекта (next_frame)
    mTimer.start(100);  // Запуск или перезапуск таймера с интервалом времени ожидания в 100 миллисекунд
}

QRectF Head::boundingRect() const {
    return QRectF(0, 0, 16, 16);    // ограничивающий прамоугольник
}

void Head::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) {
    painter->drawPixmap(0, 0, mvPixmaps[(int)mState].first,
            (_csd().mOffset * mCurrentFrame + _csd().mBorder), 0, _csd().mWidth, _csd().mHeight);   // drawPixmap - метод класса QPainter (почитай)
}

const Head::spriteData &Head::_csd()const {
    return mvPixmaps[(int)mState].second;
}

void Head::next_frame() {
    switch (mState) // текущее состояние
    {
    case eState::Moving: { // если состояние "движение вверх", то работает функция для движения вверх (остальное аналогично)
        move();
        break;
    }
    case eState::Move_left: {
        move_left();
        break;
    }
    case eState::Move_right: {
        move_right();
        break;
    }
    case eState::Move_dawn: {
        move_dawn();
        break;
    }
    case eState::Eat: { // потом напишу
        break;
    }
    case eState::End: { // потом напишу
        break;
    }
    }
    QGraphicsItem::update();    // обновление графической сцены
}

void Head::move() { // движение вверх
    if (mState != eState::Move_dawn) {  // если бошка не движется вниз
        setPos(pos().x(), pos().y() - mDx); // передвигаем бошку (посмотри функции)
        mState = eState::Moving;    // и меняем текущее состояние
    }
}

void Head::move_left() { // остальное аналогично предыдущей функции
    if (mState != eState::Move_right) {
        setPos(pos().x() - mDx, pos().y());
        mState = eState::Move_left;
    }
}

void Head::move_right() {
    if (mState != eState::Move_left) {
        setPos(pos().x() + mDx, pos().y());
        mState = eState::Move_right;
    }
}

void Head::move_dawn() {
    if (mState != eState::Moving) {
        setPos(pos().x(), pos().y() + mDx);
        mState = eState::Move_dawn;
    }
}

void Head::eat() {

}

void Head::end() {

}

Body::Body() { // эт я быталась замутить тело, но как-то не але (тут все то же, что и в классе хэд, кроме спрайтов) // дальше иди в файл view.cpp

    mvPixmapsBody.reserve((int)eStateBody::BEnd);

    QPair<QPixmap, spriteDataBody> tmp;

    tmp.first.load(":/move_body_up.png");
    mvPixmapsBody.push_back(tmp);

    tmp.first.load(":/move_body_left.png");
    mvPixmapsBody.push_back(tmp);

    tmp.first.load(":/move_body_left.png");
    mvPixmapsBody.push_back(tmp);

    tmp.first.load(":/move_body_up.png");
    mvPixmapsBody.push_back(tmp);

    connect(&mTimerBody, &QTimer::timeout, this, &Body::next_frame_body);
    mTimerBody.start(100);
}
QRectF Body::boundingRect() const {
    return QRectF(0, 0, 16, 16);
}

void Body::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) {
    painter->drawPixmap(0, 0, mvPixmapsBody[(int)mStateBody].first,
            (_csd().mOffset * mCurrentFrame + _csd().mBorder), 0, _csd().mWidth, _csd().mHeight);
}

const Body::spriteDataBody &Body::_csd()const {
    return mvPixmapsBody[(int)mStateBody].second;
}

void Body::next_frame_body() {
    switch (mStateBody)
    {
    case eStateBody::BMoving: {
        move_body();
        break;
    }
    case eStateBody::BMove_left: {
        move_left_body();
        break;
    }
    case eStateBody::BMove_right: {
        move_right_body();
        break;
    }
    case eStateBody::BMove_dawn: {
        move_dawn_body();
        break;
    }
    case eStateBody::BEat: {
        break;
    }
    case eStateBody::BEnd: {
        break;
    }
    }
    QGraphicsItem::update();
}


void Body::move_body() {
    setPos(pos().x(), pos().y() - mDx);
    mStateBody = eStateBody::BMoving;
}

void Body::move_left_body() {
    setPos(pos().x() - mDx, pos().y());
    mStateBody = eStateBody::BMove_left;
}

void Body::move_right_body() {
    setPos(pos().x() + mDx, pos().y());
    mStateBody = eStateBody::BMove_right;
}

void Body::move_dawn_body() {
    setPos(pos().x(), pos().y() + mDx);
    mStateBody = eStateBody::BMove_dawn;
}
