#include "mapwindow.h"

MapWindow::MapWindow(QWidget *parent) : QWidget(parent)
{
    QApplication::setStyle("cleanlooks");

    QPixmap* backgroundImage = new QPixmap("C:\\Users\\vovch\\Desktop\\qt_projects\\game_1\\sprites\\background_image.png");
    QPalette* palette = new QPalette();
    palette->setBrush(QPalette::Window, *backgroundImage);
    this->setPalette(*palette);

    //this->setMinimumSize(480, 360);
    this->setFixedSize(640, 480);
    //this->setContentsMargins(0, 0, 0, 0);

    player = new Character();

    //frameImage = new QPixmap("C:\\Users\\vovch\\Desktop\\qt_projects\\game_1\\sprites\\map_side_frame.png");

    //leftFrame = new QLabel(this);
    //leftFrame->setPixmap(*frameImage);
    //leftFrame->setFixedSize(48, 1080);
    //leftFrame->show();

    //rightFrame = new QLabel(this);
    //rightFrame->setPixmap(*frameImage);
    //rightFrame->setFixedSize(48, 1080);
    //rightFrame->show();

    frameLayout = new QHBoxLayout();

    forestMap = new QPushButton(this);
    forestMap->setFixedSize(160, 160);
    forestMap->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    forestMap->setIcon(QIcon("C:\\Users\\vovch\\Desktop\\qt_projects\\game_1\\sprites\\forest_map.png"));
    forestMap->setIconSize(QSize(160, 160));
    connect(forestMap, SIGNAL(clicked()), this, SLOT(forestMapOpened()));

    sewerageMap = new QPushButton(this);
    sewerageMap->setFixedSize(160, 160);
    sewerageMap->setIcon(QIcon("C:\\Users\\vovch\\Desktop\\qt_projects\\game_1\\sprites\\sewerage_map.png"));
    sewerageMap->setIconSize(QSize(160, 160));
    connect(sewerageMap, SIGNAL(clicked()), this, SLOT(sewereMapOpened()));

    mountainMap = new QPushButton(this);
    mountainMap->setFixedSize(160, 160);
    mountainMap->setIcon(QIcon("C:\\Users\\vovch\\Desktop\\qt_projects\\game_1\\sprites\\mountain_map.png"));
    mountainMap->setIconSize(QSize(160, 160));
    connect(mountainMap, SIGNAL(clicked()), this, SLOT(mountainMapOpened()));

    caveMap = new QPushButton(this);
    caveMap->setFixedSize(160, 160);
    caveMap->setIcon(QIcon("C:\\Users\\vovch\\Desktop\\qt_projects\\game_1\\sprites\\cave_map.png"));
    caveMap->setIconSize(QSize(160, 160));
    connect(caveMap, SIGNAL(clicked()), this, SLOT(caveMapOpened()));

    darkValleyMap = new QPushButton(this);
    darkValleyMap->setFixedSize(160, 160);
    darkValleyMap->setIcon(QIcon("C:\\Users\\vovch\\Desktop\\qt_projects\\game_1\\sprites\\dark_valley_map.png"));
    darkValleyMap->setIconSize(QSize(160, 160));
    connect(darkValleyMap, SIGNAL(clicked()), this, SLOT(darkValleyMapOpened()));

    ancientCastleMap = new QPushButton(this);
    ancientCastleMap->setFixedSize(160, 160);
    ancientCastleMap->setIcon(QIcon("C:\\Users\\vovch\\Desktop\\qt_projects\\game_1\\sprites\\ancient_castle_map.png"));
    ancientCastleMap->setIconSize(QSize(160, 160));
    connect(ancientCastleMap, SIGNAL(clicked()), this, SLOT(ancientCastleMapOpened()));

    diabloThroneMap = new QPushButton("Diablo's Throne", this);
    diabloThroneMap->setMinimumHeight(80);
    connect(diabloThroneMap, SIGNAL(clicked()), this, SLOT(diabloThroneMapOpened()));

    QFont* labelsFont = new QFont("Cambria", 20, QFont::Bold);

    upgradeWindow = new QPushButton("UPGRADE", this);
    upgradeWindow->setMaximumHeight(50);
    upgradeWindow->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    upgradeWindow->setStyleSheet("color: #ffffff; background-color: #404040");
    upgradeWindow->setFont(*labelsFont);

    connect(upgradeWindow, SIGNAL(clicked()), this, SLOT(upgradeOpened()));

    mainLayout = new QVBoxLayout(this);

    ExpLabel = new QLabel(expLabelText(), this);
    ExpLabel->setAlignment(Qt::AlignRight);
    ExpLabel->setStyleSheet("padding-top: 10px; padding-right: 20px; color: #ffffff");
    ExpLabel->setFont(*labelsFont);

    LvlLabel = new QLabel(lvlLabelText(), this);
    LvlLabel->setAlignment(Qt::AlignLeft);
    LvlLabel->setStyleSheet("padding-top: 10px; padding-left: 20px; color: #ffffff");
    LvlLabel->setFont(*labelsFont);

    playerExp = new QHBoxLayout(this);
    playerExp->addWidget(ExpLabel);
    playerExp->addWidget(LvlLabel);

    mapsLayout = new QHBoxLayout(this);
    mapsScrollArea = new QScrollArea(this);
    QScrollBar* mapsScrollAreaBar = new QScrollBar(Qt::Vertical);
    mapsScrollAreaBar->setStyleSheet("QScrollBar:horizontal {"
                                        "    border: 0px solid #c6c6c6;"
                                        "    background: transparent;"
                                        "    height: 13px;    "
                                        "    margin: 0px 0px 0px 0px;"
                                        "}");
    mapsScrollArea->setHorizontalScrollBar(mapsScrollAreaBar);
    mapsScrollArea->setStyleSheet("border: 0px");

    mapsLayout->addWidget(forestMap);
    mapsLayout->addWidget(sewerageMap);
    mapsLayout->addWidget(mountainMap);
    mapsLayout->addWidget(caveMap);
    mapsLayout->addWidget(darkValleyMap);
    mapsLayout->addWidget(ancientCastleMap);
    mapsLayout->addWidget(diabloThroneMap);

    scrollWidget = new QWidget;
    scrollWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    scrollWidget->setLayout(mapsLayout);
    scrollWidget->setStyleSheet("background-color: rgba(0, 0, 0, 0);");

    mapsScrollArea->setWidget(scrollWidget);
    mapsScrollArea->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    mapsScrollArea->setStyleSheet("background-color: rgba(0, 0, 0, 0); border: 0px;");
    //mapsScrollArea->show();

    QLabel* inforamtionLabel = new QLabel("Choose the map", this);
    inforamtionLabel->setAlignment(Qt::AlignCenter);
    inforamtionLabel->setStyleSheet("padding-top: 10px; color: #ffffff");
    inforamtionLabel->setFont(*labelsFont);

    mainLayout->addLayout(playerExp);
    mainLayout->addWidget(inforamtionLabel);
    mainLayout->addWidget(mapsScrollArea);
    mainLayout->addWidget(upgradeWindow);

    //frameLayout->addWidget(leftFrame);
    //frameLayout->addLayout(mainLayout);
    //frameLayout->addWidget(rightFrame);
    //frameLayout->setContentsMargins(0, 0, 0, 0);

    //setLayout(frameLayout);
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

void MapWindow::resizeEvent(QResizeEvent *) {
    qDebug() << this->width() << ' ' << this->height();
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
