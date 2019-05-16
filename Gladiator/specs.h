#ifndef SPECS_H
#define SPECS_H
#include <QGraphicsRectItem>
/**
 * @brief The Specs class proporciona un panel que muestra la informacion de los gladiadores en pantalla.
 */
class Specs: public QGraphicsRectItem
{
public:
    /**
     * @brief Specs Constructor de la clase Specs.
     * @param parent
     */
    Specs(QGraphicsItem *parent = 0);
    /**
     * @brief crearSpecs Crea el panel en la pantalla.
     */
    void crearSpecs();
    /**
     * @brief setResistenciaT Modifica el valor de la resistencia en la pantalla.
     * @param value El nuevo valor de la resistencia.
     */
    void setResistenciaT(QString value);
    /**
     * @brief setIdT Modifica el valor del ID en la pantalla.
     * @param value El nuevo valor del ID.
     */
    void setIdT(QString value);
    /**
     * @brief setEdadT Modifica el valor de la edad en la pantalla.
     * @param value El nuevo valor de la edad en la pantalla.
     */
    void setEdadT(QString value);
    /**
     * @brief setProbSuperT Modifica el valor de la probavilidad de supervivencia en la pantalla.
     * @param value El nuevo valor de la probabilidad de supervivencia.
     */
    void setProbSuperT(QString value);
    /**
     * @brief setGenEsperadasT Modifica el valor de las generaciones esperadas.
     * @param value El nuevo valor de las generaciones esperadas.
     */
    void setGenEsperadasT(QString value);
    /**
     * @brief setIEmocionalT Modifica el valor de la inteligencia emocional en la pantalla.
     * @param value El nuevo valor de la inteligencia emocional.
     */
    void setIEmocionalT(QString value);
    /**
     * @brief setCondFisicaT Modifica el valor de la condicion fisica en la pantalla.
     * @param value El nuevo valor de la condicion fisica.
     */
    void setCondFisicaT(QString value);
    /**
     * @brief setFTroncoSupT Modifica el valor de la fuerza en el tronco superior en la pantalla.
     * @param value El nuevo valor de la fuerza en el tronco superior.
     */
    void setFTroncoSupT(QString value);
    /**
     * @brief setFTroncoInfT Modifica el valor de la fuerza en el tronco inferior en la pantalla.
     * @param value El nuevo valor de la fuerza en el tronco inferior.
     */
    void setFTroncoInfT(QString value);

private:
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
    /**
     * @brief setVida Modifica el valor de la vida en la pantalla.
     * @param edad El nuevo valor de la vida.
     */
    void setVida(QString edad);


};

#endif // SPECS_H
