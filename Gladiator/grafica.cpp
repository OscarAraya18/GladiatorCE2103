#include "grafica.h"
#include "ui_grafica.h"
#include "qcustomplot.h"
Grafica::Grafica(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Grafica)
{
    ui->setupUi(this);
}

Grafica::~Grafica()
{
    delete ui;
}

void Grafica::desplegarGrafica(QVector<double> gen1, QVector<double> fitness1, QVector<double> gen2, QVector<double> fitness2)
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
