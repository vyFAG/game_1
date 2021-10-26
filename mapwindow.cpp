#include "mapwindow.h"

MapWindow::MapWindow(QWidget *parent) : QWidget(parent)
{
    player = new Character();

    forestMap = new QPushButton("Forest", this);
    connect(forestMap, SIGNAL(clicked()), this, SLOT(forestMapOpened()));
    sewerageMap = new QPushButton("Sewerage", this);
    connect(sewerageMap, SIGNAL(clicked()), this, SLOT(sewereMapOpened()));

    upgradeWindow = new QPushButton("UPGRADE", this);
    connect(upgradeWindow, SIGNAL(clicked()), this, SLOT(upgradeOpened()));

    mainLayout = new QVBoxLayout(this);

    ExpLabel = new QLabel(expLabelText(), this);
    LvlLabel = new QLabel(lvlLabelText(), this);

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
