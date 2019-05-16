#ifndef BOTON_H
#define BOTON_H
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
/**
 * @brief The Boton class Provee metodos que permiten colocar botones en la pantalla
 * del juego. Con una personalizaciòn facil de definir.
 */
class Boton:public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    /**
     * @brief Boton Constructor de la clase boton.
     * @param nombre El nombre del boton.
     * @param parent
     */
    Boton(QString nombre, QGraphicsItem* parent = NULL);

    /**
     * @brief mousePressEvent Evento al presionar el boton.
     * @param evento Evento.
     */
    void mousePressEvent(QGraphicsSceneMouseEvent* evento);
    /**
     * @brief hoverEnterEvent Evento para cuando el cursor entra en las dimensiones
     * del boton.
     * @param evento Evento.
     */
    void hoverEnterEvent(QGraphicsSceneHoverEvent* evento);
    /**
     * @brief hoverLeaveEvent Evento para cuando el cursor sale de las dimensiones
     * del boton.
     * @param evento Evento.
     */
    void hoverLeaveEvent(QGraphicsSceneHoverEvent* evento);
signals:
    /**
     * @brief clicked Cuando se clickea el boton.
     */
    void clicked();
private:
    QGraphicsTextItem *texto;

};

#endif // BOTON_H
