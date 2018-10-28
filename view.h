#ifndef VIEW_H
#define VIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>

class View : public QGraphicsView
{
public:
    View();

private:
    void _init_view_elements();
    QGraphicsScene mScene;
};

#endif // VIEW_H
