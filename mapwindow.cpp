#include "mapwindow.h"

MapWindow::MapWindow(QWidget *parent) : QWidget(parent)
{
    forestMap = new QPushButton("Forest", this);
    connect(forestMap, SIGNAL(clicked()), this, SLOT(mapOpened()));
    sewerageMap = new QPushButton("Sewerage", this);

    mapsLayout = new QHBoxLayout(this);
    mapsScrollArea = new QScrollArea(this);

    mapsLayout->addWidget(forestMap);
    mapsLayout->addWidget(sewerageMap);
    QWidget* widget = new QWidget;
    widget -> setLayout(mapsLayout);
    mapsScrollArea -> setWidget(widget);
    mapsScrollArea->show();
}

void MapWindow::mapOpened() {
    game = new GameWindow();
    game->show();
    this->hide();
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
    connect(game, SIGNAL(windowClosed), this, SLOT(showWindow()));
}

void MapWindow::showWindow() {
    this->show();
    //delete game;
=======
    connect(game, SIGNAL(windowClosed()), this, SLOT(showWindow()));
}

void MapWindow::showWindow() {
    delete game;
    this->show();
>>>>>>> parent of 4cd9885 (Update mapwindow.cpp)
=======
    connect(game, SIGNAL(windowClosed()), this, SLOT(showWindow()));
=======
    connect(game, SIGNAL(windowClosed), this, SLOT(showWindow()));
>>>>>>> parent of c0d1d8e (Revert "returned")
=======
    connect(game, SIGNAL(windowClosed), this, SLOT(showWindow()));
>>>>>>> parent of c0d1d8e (Revert "returned")
}

void MapWindow::showWindow() {
    delete game;
    this->show();
>>>>>>> parent of 4cd9885 (Update mapwindow.cpp)
}
