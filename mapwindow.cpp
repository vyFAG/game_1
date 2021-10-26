#include "mapwindow.h"

MapWindow::MapWindow(QWidget *parent) : QWidget(parent)
{
    setMinimumSize(320, 240);
    setMaximumSize(320, 240);

    player = new Character();

    forestMap = new QPushButton("Forest", this);
    forestMap->setMinimumHeight(80);
    connect(forestMap, SIGNAL(clicked()), this, SLOT(forestMapOpened()));
    sewerageMap = new QPushButton("Sewerage", this);
    sewerageMap->setMinimumHeight(80);
    connect(sewerageMap, SIGNAL(clicked()), this, SLOT(sewereMapOpened()));
    mountainMap = new QPushButton("Mountain", this);
    mountainMap->setMinimumHeight(80);
    connect(mountainMap, SIGNAL(clicked()), this, SLOT(mountainMapOpened()));
    caveMap = new QPushButton("Cave", this);
    caveMap->setMinimumHeight(80);
    connect(caveMap, SIGNAL(clicked()), this, SLOT(caveMapOpened()));
    darkValleyMap = new QPushButton("Dark Valley", this);
    darkValleyMap->setMinimumHeight(80);
    connect(darkValleyMap, SIGNAL(clicked()), this, SLOT(darkValleyMapOpened()));
    ancientCastleMap = new QPushButton("Ancient Castle", this);
    ancientCastleMap->setMinimumHeight(80);
    connect(ancientCastleMap, SIGNAL(clicked()), this, SLOT(ancientCastleMapOpened()));
    diabloThroneMap = new QPushButton("Diablo's Throne", this);
    diabloThroneMap->setMinimumHeight(80);
    connect(diabloThroneMap, SIGNAL(clicked()), this, SLOT(diabloThroneMapOpened()));

    upgradeWindow = new QPushButton("UPGRADE", this);
    upgradeWindow->setMaximumHeight(50);
    upgradeWindow->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    connect(upgradeWindow, SIGNAL(clicked()), this, SLOT(upgradeOpened()));

    mainLayout = new QVBoxLayout(this);

    ExpLabel = new QLabel(expLabelText(), this);
    ExpLabel->setAlignment(Qt::AlignCenter);
    LvlLabel = new QLabel(lvlLabelText(), this);
    LvlLabel->setAlignment(Qt::AlignCenter);

    playerExp = new QHBoxLayout(this);
    playerExp->addWidget(ExpLabel);
    playerExp->addWidget(LvlLabel);

    mapsLayout = new QHBoxLayout(this);
    mapsScrollArea = new QScrollArea(this);

    mainLayout->addLayout(playerExp);

    mapsLayout->addWidget(forestMap);
    mapsLayout->addWidget(sewerageMap);
    mapsLayout->addWidget(mountainMap);
    mapsLayout->addWidget(caveMap);
    mapsLayout->addWidget(darkValleyMap);
    mapsLayout->addWidget(ancientCastleMap);
    mapsLayout->addWidget(diabloThroneMap);

    QWidget* widget = new QWidget;
    widget -> setLayout(mapsLayout);
    mapsScrollArea -> setWidget(widget);
    mapsScrollArea->show();
    mapsScrollArea->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QLabel* inforamtionLabel = new QLabel("Choose the map", this);
    inforamtionLabel->setAlignment(Qt::AlignCenter);

    mainLayout->addWidget(inforamtionLabel);
    mainLayout->addWidget(mapsScrollArea);
    mainLayout->addWidget(upgradeWindow);
}

void MapWindow::forestMapOpened() {
    gameTab = new GameWindow(*player, 7);
    gameTab->show();
    this->hide();
    connect(gameTab, SIGNAL(windowClosed()), this, SLOT(showWindow()));
}

void MapWindow::sewereMapOpened() {
    gameTab = new GameWindow(*player, 10);
    gameTab->show();
    this->hide();
    connect(gameTab, SIGNAL(windowClosed()), this, SLOT(showWindow()));
}

void MapWindow::mountainMapOpened() {
    gameTab = new GameWindow(*player, 15);
    gameTab->show();
    this->hide();
    connect(gameTab, SIGNAL(windowClosed()), this, SLOT(showWindow()));
}

void MapWindow::caveMapOpened() {
    gameTab = new GameWindow(*player, 22);
    gameTab->show();
    this->hide();
    connect(gameTab, SIGNAL(windowClosed()), this, SLOT(showWindow()));
}

void MapWindow::darkValleyMapOpened() {
    gameTab = new GameWindow(*player, 30);
    gameTab->show();
    this->hide();
    connect(gameTab, SIGNAL(windowClosed()), this, SLOT(showWindow()));
}

void MapWindow::ancientCastleMapOpened() {
    gameTab = new GameWindow(*player, 45);
    gameTab->show();
    this->hide();
    connect(gameTab, SIGNAL(windowClosed()), this, SLOT(showWindow()));
}

void MapWindow::diabloThroneMapOpened() {
    gameTab = new GameWindow(*player, 72);
    gameTab->show();
    this->hide();
    connect(gameTab, SIGNAL(windowClosed()), this, SLOT(showWindow()));
}

void MapWindow::showWindow() {
    ExpLabel->setText(expLabelText());
    LvlLabel->setText(lvlLabelText());
    player->setPlayerHealth(player->getPlayerMaxHealth());
    this->show();
    //gameTab = nullptr;
}

void MapWindow::upgradeOpened() {
    upgradeTab = new SkillsWindow(*player);
    upgradeTab->show();
}

QString MapWindow::expLabelText() {
    return QString("EXP: " + QString::number(player->getPlayerExp()));
}

QString MapWindow::lvlLabelText() {
    return QString("LVL: " + QString::number(player->getPlayerLvl()));
}
