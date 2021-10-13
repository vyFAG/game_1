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
    connect(game, SIGNAL(windowClosed()), this, SLOT(showWindow()));
    game->show();
    this->hide();
<<<<<<< HEAD
=======
    connect(game, SIGNAL(windowClosed), this, SLOT(showWindow()));
>>>>>>> parent of 68ec649 (enemy_stats_reballanced)
}

void MapWindow::showWindow() {
    this->show();
    delete game;
}
