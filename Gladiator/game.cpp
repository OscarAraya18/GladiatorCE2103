#include "board.h"
#include "boton.h"
#include "game.h"
#include "grafico.h"
#include <QMediaPlayer>
extern grafico *Grafico;
Game::Game(QWidget *parent){

    scene = new QGraphicsScene();

    scene->setSceneRect(0,0,1200,800);
    setBackgroundBrush(QBrush(QImage(":/images/fondo.jpg")));

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1200,800);
    setScene(scene);

    board = new Board();
    QMediaPlayer *music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/music.mp3"));
    music->play();

    Boton* nuevoJuego = new Boton(QString("Iniciar Iteración"));
    int bxPos = 350;
    int byPos = 633;
    nuevoJuego->setPos(bxPos,byPos);
    connect(nuevoJuego,SIGNAL(clicked()),this,SLOT(iniciarIteracion()));
    scene->addItem(nuevoJuego);

    converter = Converter::getInstance();

    conexion = new Cliente();
    iniciarConexion();

    show();

}

void Game::iniciarConexion()
{
    if(conexion->conectar()){
        connect(conexion, SIGNAL(NewMensaje(QString)), SLOT(recibirMensaje(QString)));
        cout << "Conexion exitosa" << endl;
    }
    else{
        cout << "Error al conectarse" << endl;
    }
}

void Game::sendMessage(string m)
{
    conexion->setMensaje(m.c_str());
}


void Game::recibirMensaje(QString mensaje)
{
    cout << mensaje.toStdString() << endl;

    converter->funcionGeneral(mensaje.toStdString().c_str());

}
void Game::iniciarIteracion()
{
    string mensaje = converter->iniciarIte();
   sendMessage(mensaje);
}
