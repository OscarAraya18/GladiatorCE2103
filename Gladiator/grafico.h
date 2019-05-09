#ifndef GRAFICO_H
#define GRAFICO_H
#include <QMainWindow>
namespace Ui {
class grafico;
}
/**
 * @brief The grafico class Clase que  despliega un grafico para representar los avences
 * de las dos poblaciones.
 */
class grafico : public QMainWindow
{
    Q_OBJECT
public:
    /**
     * @brief grafico Constructor de la clase Grafico.
     * @param parent
     */
    explicit grafico(QWidget *parent = nullptr);
    ~grafico();
public slots:
    /**
     * @brief desplegarGrafica Construye la grafica con los datos de las poblaciones.
     * @param gen1 Las generaciones de la primera poblacion.
     * @param fitness1 Los promedios del fitness de las generaciones de la primera poblacion.
     * @param gen2 Las generaciones de la segunda poblacion.
     * @param fitness2 Los promedios del fitness de las generaciones de la segunda poblacion.
     */
    void desplegarGrafica(QVector<double> gen1, QVector<double> fitness1, QVector<double> gen2, QVector<double> fitness2);
private:
    Ui::grafico *ui;
};

#endif // GRAFICO_H
