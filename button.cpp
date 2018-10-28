#include "button.h"
#include <QPainter>
#include <QApplication>
#include <QDebug>
#include <QGraphicsSceneMouseEvent>

button::button()
{
    setAcceptHoverEvents(true);
    setAcceptedMouseButtons(Qt::LeftButton);
}

QRectF button::boundingRect() const {
    return QRectF(0, 0, mWidth, mHeight);
}

void button::paint(QPainter *painter, const QStyleOptionGraphicsItem */*option*/, QWidget */*widget*/) {
    if (mHover) {
        painter->setBrush(QColor(0, 255, 0));
        //painter->setPen(QColor(225, 0, 0));
    }
        painter->drawRoundedRect(0, 0, mWidth, mHeight, 5, 5);
}

void button::setGeometry(int aWidth, int aHeight) {
    mWidth = aWidth;
    mHeight = aHeight;
}

void button::hoverEnterEvent(QGraphicsSceneHoverEvent*) {
    //qWarning() << "Enter";
    mHover = true;
    QGraphicsItem::update();
}

void button::hoverLeaveEvent(QGraphicsSceneHoverEvent*) {
    //qWarning() << "Leave";
    mHover = false;
    QGraphicsItem::update();
}

void button::mousePressEvent(QGraphicsSceneMouseEvent *) {
    qWarning() << "ef";
}

void button::mouseReleaseEvent(QGraphicsSceneMouseEvent *apEvent) {
    emit btnMouseReleaseEvent(apEvent->button());
    qWarning() << "release";
}
