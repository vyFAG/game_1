#include "mapwindow.h"

MapWindow::MapWindow(QWidget *parent) : QWidget(parent)
{
    player = new Character();

    forestMap = new QPushButton("Forest", this);
    connect(forestMap, SIGNAL(clicked()), this, SLOT(mapOpened()));
    sewerageMap = new QPushButton("Sewerage", this);

    mainLayout = new QVBoxLayout(this);

    ExpLabel = new QLabel("exp", this);
    LvlLabel = new QLabel("lvl", this);

    playerExp = new QHBoxLayout(this);
    playerExp->addWidget(ExpLabel);
    playerExp->addWidget(LvlLabel);

    mapsLayout = new QHBoxLayout(this);
    mapsScrollArea = new QScrollArea(this);

    mainLayout->addLayout(playerExp);

    mapsLayout->addWidget(forestMap);
    mapsLayout->addWidget(sewerageMap);
    QWidget* widget = new QWidget;
    widget -> setLayout(mapsLayout);
    mapsScrollArea -> setWidget(widget);
    mapsScrollArea->show();
    mapsScrollArea->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    mainLayout->addWidget(mapsScrollArea);
}

void MapWindow::mapOpened() {
    game = new GameWindow(*player);
    game->show();
    this->hide();
    connect(game, SIGNAL(windowClosed()), this, SLOT(showWindow()));
}

void MapWindow::showWindow() {

    this->show();
    //delete game;
}
