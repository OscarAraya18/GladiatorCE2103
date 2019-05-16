#ifndef GRAFICA_H
#define GRAFICA_H

#include <QWidget>

namespace Ui {
class Grafica;
}

class Grafica : public QWidget
{
    Q_OBJECT

public:
    explicit Grafica(QWidget *parent = nullptr);
    ~Grafica();

private slots:

    void desplegarGrafica(QVector<double> gen1, QVector<double> fitness1, QVector<double> gen2, QVector<double> fitness2);

private:
    Ui::Grafica *ui;
};

#endif // GRAFICA_H
