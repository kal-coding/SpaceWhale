#include "game.h"
#include "whalea.h"
#include <QDebug>
#include "space.h"
#include <QBrush>
#include <QColor>

Game::Game(QWidget *parent){
    this->setMouseTracking(true);
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1000,800);


    QBrush *brush=new QBrush();
    brush->setStyle(Qt::SolidPattern);
    brush->setColor(QColor(45,45,45,255));
    scene->setBackgroundBrush(*brush);
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1100,900);

    // start global timer
    timer = new QTimer();
    // start the timer
    timer->start(17);

}

void Game::start(){
    space = new Space();
    space->animateStarfield();
    whale = new WhaleA();
    whale->drawWhale();
    whale->animateWhale();
}

void Game::mouseMoveEvent(QMouseEvent *event){
    qDebug() << "mouse detected";
    qDebug() << event->pos();
    whale->updateTargetMousePosition(event);
    space->updateTargetMousePosition(event);
}

void Game::mousePressEvent(QMouseEvent *event)
{
    switch(event->button()){
        case Qt::LeftButton: {
            qDebug() << "mouse Left";
            whale->leftBarrelRoll();
            break;
        }
        case Qt::MiddleButton: {
            qDebug() << "mouse Middle";
            break;
        }
        case Qt::RightButton: {
            qDebug() << "mouse Right";
            whale->rightBarrelRoll();
            break;
        }
    }
}
