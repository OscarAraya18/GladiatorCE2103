#include "grafico.h"
#include "ui_grafico.h"

grafico::grafico(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::grafico)
{
    ui->setupUi(this);

    QVector<double> gen1, fitness1, gen2, fitness2;
    gen1 << 1 << 2 << 3 << 4 << 5 << 6 << 7 << 8 << 9 << 10 << 11 << 12 << 13 << 14 << 15 << 16 << 17 << 18 << 19 << 20;
    gen2 << 1 << 2 << 3 << 4 << 5 << 6 << 7 << 8 << 9 << 10 << 11 << 12 << 13 << 14 << 15 << 16 << 17 << 18 << 19 << 20;
    fitness1 << 1.23 << 1.89 << 2.43  << 4.65 << 6.32 << 25.32 << 30.56 << 43.23 << 54.24 << 57.23 << 63.78 << 63.78 << 68.9 << 72.13 << 76.23 << 81.48 << 87.23 << 93.45 << 94.2 << 97.32;
    fitness2 << 1.34 << 2.45 << 10.43  << 16.67 << 18.45 << 24.23 << 26.67 << 45.23 << 50.23 << 55.7 << 55.9 << 57.98 << 60.34 << 64.33 << 66.45 << 75.67 << 82.45 << 86.34 << 95.34 << 96.45;
    grafico::desplegarGrafica(gen1,fitness1,gen2,fitness2);
}

grafico::~grafico()
{
    delete ui;
}

void grafico::desplegarGrafica(QVector<double> gen1, QVector<double> fitness1, QVector<double> gen2, QVector<double> fitness2)
{
    QLinearGradient plotGradient;
    plotGradient.setStart(0, 0);
    plotGradient.setFinalStop(0, 350);
    plotGradient.setColorAt(0, QColor(80, 80, 80));
    plotGradient.setColorAt(1, QColor(50, 50, 50));
    ui->customPlot->setBackground(plotGradient);
    //primer Grafico
    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setLineStyle(QCPGraph::lsLine);
    QPen pen;
    pen.setColor(QColor(255, 200, 20, 200));
    pen.setWidthF(2.5);
    ui->customPlot->graph(0)->setPen(pen);
    ui->customPlot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 10));
    ui->customPlot->graph(0)->setName("Avance del fitness de la primera poblaciòn");
    //segundo grafico
    ui->customPlot->addGraph();
    ui->customPlot->graph(1)->setLineStyle(QCPGraph::lsLine);
    QPen pen2;
    pen2.setColor(QColor(0, 10, 12, 255));
    pen2.setWidthF(2.5);
    ui->customPlot->graph(1)->setPen(pen2);
    ui->customPlot->graph(1)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssDisc, 10));
    ui->customPlot->graph(1)->setName("Avance del fitness de la segunda poblaciòn");
    // Agregarle los datos a las dos lineas

    //agregar datos a la linea de la primera poblacion
    ui->customPlot->graph(0)->setData(gen1, fitness1);
    //agregar datos a la linea de la segunda poblacion
    ui->customPlot->graph(1)->setData(gen2,fitness2);

    // set title of plot:
    ui-> customPlot->plotLayout()->insertRow(0);
    ui->customPlot->plotLayout()->addElement(0, 0, new QCPTextElement(ui->customPlot, "Fitness en funcion de las generaciones de gladiadores", QFont("sans", 12, QFont::Bold)));
    // axis configurations:
    ui->customPlot->xAxis->setLabel("GENERACION");
    ui->customPlot->yAxis->setLabel("FITNESS");
    ui->customPlot->xAxis2->setVisible(true);
    ui->customPlot->yAxis2->setVisible(true);
    ui->customPlot->xAxis2->setTickLabels(false);
    ui->customPlot->yAxis2->setTickLabels(false);
    ui->customPlot->xAxis2->setTicks(false);
    ui->customPlot->yAxis2->setTicks(false);
    ui->customPlot->xAxis2->setSubTicks(false);
    ui->customPlot->yAxis2->setSubTicks(false);
    ui->customPlot->xAxis->setRange(0, 20);
    ui->customPlot->yAxis->setRange(0, 100);
    // setup legend:
    ui->customPlot->legend->setFont(QFont(font().family(), 7));
    ui->customPlot->legend->setIconSize(50, 20);
    ui->customPlot->legend->setVisible(true);
    ui->customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignLeft | Qt::AlignTop);
}
