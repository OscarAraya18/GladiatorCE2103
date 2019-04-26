#include "game.h"
#include "piece.h"

extern Game *game;

Piece::Piece(QGraphicsItem *parent):QGraphicsRectItem (parent)
{
    setRect(0,0,70,70);
    QBrush brush;

    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::white);
    setBrush(brush);
    QPen pen;
    pen.setStyle(Qt::SolidLine);
    pen.setWidth(2);

    setPen(pen);
}
