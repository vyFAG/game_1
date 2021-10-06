#include "gamewindow.h"

GameWindow::GameWindow(QWidget *parent)
    : QWidget(parent)
{
    this->setMinimumSize(320, 240);
    this->setMaximumSize(640, 480);
    actionButtonsLayout = new QHBoxLayout();
    mainLayout = new QVBoxLayout(this);

    graphicsLabel = new QLabel("sex", this);
    graphicsLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    attackButton = new QPushButton("Attack", this);
    attackButton->setMaximumHeight(50);
    attackButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    connect(attackButton, SIGNAL(clicked()), this, SLOT(attackAction()));

    blockButton = new QPushButton("Block", this);
    blockButton->setMaximumHeight(50);
    blockButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    connect(blockButton, SIGNAL(clicked()), this, SLOT(blockAction()));

    dodgeButton = new QPushButton("Dodge", this);
    dodgeButton->setMaximumHeight(50);
    dodgeButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    connect(dodgeButton, SIGNAL(clicked()), this, SLOT(dodgeAction()));

    actionButtonsLayout->addWidget(attackButton);
    actionButtonsLayout->addWidget(blockButton);
    actionButtonsLayout->addWidget(dodgeButton);

    //actionButtonsLayout->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    mainLayout->addWidget(graphicsLabel);
    mainLayout->addLayout(actionButtonsLayout);

    this->setLayout(mainLayout);
}

GameWindow::~GameWindow()
{

}

void GameWindow::attackAction() {
    if(std::chrono::high_resolution_clock::now() - attackInterval > std::chrono::milliseconds(player.getAttackCooldown())) {
        qDebug() << "attack";
        attackInterval = std::chrono::high_resolution_clock::now();
    }
}

void GameWindow::blockAction() {
    if(std::chrono::high_resolution_clock::now() - blockInterval > std::chrono::milliseconds(player.getBlockCooldown())) {
        qDebug() << "block";
        blockInterval = std::chrono::high_resolution_clock::now();
    }
}

void GameWindow::dodgeAction() {
    if(std::chrono::high_resolution_clock::now() - dodgeInterval > std::chrono::milliseconds(player.getDodgeCooldown())) {
        qDebug() << "dodge";
        dodgeInterval = std::chrono::high_resolution_clock::now();
    }
}
