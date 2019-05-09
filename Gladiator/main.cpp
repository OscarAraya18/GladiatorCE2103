#include "game.h"
#include "mainwindow.h"
#include <QApplication>
#include "grafico.h"

Game *game;
grafico *Grafico;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    game = new Game();
    game->board->drawBoard();

    game->show();
    Grafico = new grafico();



    return a.exec();
}
