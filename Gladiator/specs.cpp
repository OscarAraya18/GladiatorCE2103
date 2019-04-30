#include "game.h"
#include "specs.h"
#include <QBrush>
#include <QPen>

extern Game *game;

Specs::Specs(QGraphicsItem *parent){
    setRect(0,0,300,275);
    QBrush brush;

    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::black);
    setBrush(brush);
    QPen pen;
    pen.setStyle(Qt::SolidLine);
    pen.setWidth(1.5);
    setPen(pen);


}

void Specs::crearSpecs()
{
    QBrush brush;

    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::gray);

    //para el ID
    Id = new QGraphicsRectItem();
    Id->setRect(x()+5,y()+5,290, 30);
    Id->setBrush(brush);
    IdT = new QGraphicsTextItem();
    IdT->setPlainText("ID");
    IdT->setPos(x() +10, y() +10);
    game->scene->addItem(Id);
    game->scene->addItem(IdT);

    //Para la edad
    edad = new QGraphicsRectItem();
    edad->setRect(x() +5, y() + 30, 290,30);
    edad->setBrush(brush);
    edadT = new QGraphicsTextItem();
    edadT->setPlainText("EDAD");
    edadT->setPos(x()+10, y() + 35);
    game->scene->addItem(edad);
    game->scene->addItem(edadT);

   //Para la probabilidad de supervivencia
    probSuper = new QGraphicsRectItem();
    probSuper->setRect(x() +5, y() + 60, 290, 30);
    probSuper->setBrush(brush);
    probSuperT = new QGraphicsTextItem();
    probSuperT->setPlainText("PROBABILIDAD SUPER");
    probSuperT->setPos(x()+10, y() + 65);
    game->scene->addItem(probSuper);
    game->scene->addItem(probSuperT);

    //para las generaciones esperadas
    genEsperadas = new QGraphicsRectItem();
    genEsperadas->setRect(x()+5, y()+ 90, 290, 30);
    genEsperadas->setBrush(brush);
    genEsperadasT = new QGraphicsTextItem();
    genEsperadasT->setPlainText("GEN ESPERADAS");
    genEsperadasT->setPos(x()+10, y()+ 95);
    game->scene->addItem(genEsperadas);
    game->scene->addItem(genEsperadasT);

    //para la inteligencia emocional
    iEmocional = new QGraphicsRectItem();
    iEmocional->setRect(x()+5, y()+ 120, 290, 30);
    iEmocional->setBrush(brush);
    iEmocionalT = new QGraphicsTextItem();
    iEmocionalT->setPlainText("I EMOCIONAL");
    iEmocionalT->setPos(x()+10, y()+ 125);
    game->scene->addItem(iEmocional);
    game->scene->addItem(iEmocionalT);

    //para la  condicion fisica
    condFisica = new QGraphicsRectItem();
    condFisica->setRect(x()+5, y() + 150, 290, 30);
    condFisica->setBrush(brush);
    condFisicaT = new QGraphicsTextItem();
    condFisicaT->setPlainText("COND FISICA");
    condFisicaT->setPos(x()+10, y() + 155);
    game->scene->addItem(condFisica);
    game->scene->addItem(condFisicaT);

    //para la fuerza en tronco superior
    fTroncoSup = new QGraphicsRectItem();
    fTroncoSup->setRect(x()+5, y()+ 180, 290, 30);
    fTroncoSup->setBrush(brush);
    fTroncoSupT = new QGraphicsTextItem();
    fTroncoSupT->setPlainText("TRONCO SUPERIOR");
    fTroncoSupT->setPos(x()+10, y()+ 185);
    game->scene->addItem(fTroncoSup);
    game->scene->addItem(fTroncoSupT);

    //para el tronco inferior
    fTroncoInf = new QGraphicsRectItem();
    fTroncoInf->setRect(x()+5, y() + 210, 290,30);
    fTroncoInf->setBrush(brush);
    fTroncoInfT = new QGraphicsTextItem();
    fTroncoInfT->setPlainText("TRONCO INFERIOR");
    fTroncoInfT->setPos(x()+10 ,y() + 215);
    game->scene->addItem(fTroncoInf);
    game->scene->addItem(fTroncoInfT);

    //para la resistencia
    resistencia = new QGraphicsRectItem();
    resistencia->setRect(x()+5, y() + 240, 290,30);
    resistencia->setBrush(brush);
    resistenciaT = new QGraphicsTextItem();
    resistenciaT->setPlainText("RESISTENCIA");
    resistenciaT->setPos(x()+10, y() + 245);
    game->scene->addItem(resistencia);
    game->scene->addItem(resistenciaT);

}

void Specs::setVida(QString vida)
{
    resistenciaT->setPlainText("Resistencia: " + vida);
}


