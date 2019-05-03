#ifndef BOTON_H
#define BOTON_H
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>

class Boton:public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    //constructores
    Boton(QString nombre, QGraphicsItem* parent = NULL);

    //metodos publicos
    void mousePressEvent(QGraphicsSceneMouseEvent* evento);
    void hoverEnterEvent(QGraphicsSceneHoverEvent* evento);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent* evento);

signals:
    void clicked();


private:
    QGraphicsTextItem *texto;

};

#endif // BOTON_H
