#ifndef SPECS_H
#define SPECS_H
#include <QGraphicsRectItem>

class Specs: public QGraphicsRectItem
{
public:
    Specs(QGraphicsItem *parent = 0);
    void crearSpecs();
    QGraphicsRectItem *resistencia;
    QGraphicsTextItem *resistenciaT;

    QGraphicsRectItem *Id;
    QGraphicsTextItem *IdT;

    QGraphicsRectItem *edad;
    QGraphicsTextItem *edadT;

    QGraphicsRectItem *probSuper;
    QGraphicsTextItem *probSuperT;

    QGraphicsRectItem *genEsperadas;
    QGraphicsTextItem *genEsperadasT;

    QGraphicsRectItem *iEmocional;
    QGraphicsTextItem *iEmocionalT;

    QGraphicsRectItem *condFisica;
    QGraphicsTextItem *condFisicaT;

    QGraphicsRectItem *fTroncoSup;
    QGraphicsTextItem *fTroncoSupT;

    QGraphicsRectItem *fTroncoInf;
    QGraphicsTextItem *fTroncoInfT;

    void setVida(QString edad);


};

#endif // SPECS_H
