#ifndef BUTTON_H
#define BUTTON_H

#include <QGraphicsItem>
#include <QObject>

class button : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    button();
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void hoverEnterEvent(QGraphicsSceneHoverEvent*) override;
    void hoverLeaveEvent(QGraphicsSceneHoverEvent*) override;
    void setGeometry(int, int);
    void mousePressEvent(QGraphicsSceneMouseEvent *) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *) override;

signals:
    void btnMouseReleaseEvent(Qt::MouseButton);

private:
    int mWidth{0};
    int mHeight{0};
    bool mHover{false};
};

#endif // BUTTON_H
