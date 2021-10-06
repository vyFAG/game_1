#include "gamewindow.h"

GameWindow::GameWindow(QWidget *parent)
    : QWidget(parent)
{
    this->setMinimumSize(320, 240);
    this->setMaximumSize(640, 480);
    actionButtonsLayout = new QHBoxLayout(this);

    attackButton = new QPushButton("Attack", this);
    connect(attackButton, SIGNAL(clicked()), this, SLOT(attackAction()));

    blockButton = new QPushButton("Block", this);
    connect(blockButton, SIGNAL(clicked()), this, SLOT(blockAction()));

    dodgeButton = new QPushButton("Dodge", this);
    connect(dodgeButton, SIGNAL(clicked()), this, SLOT(dodgeAction()));

    actionButtonsLayout->addWidget(attackButton);
    actionButtonsLayout->addWidget(blockButton);
    actionButtonsLayout->addWidget(dodgeButton);

    this->setLayout(actionButtonsLayout);
}

GameWindow::~GameWindow()
{

}

void GameWindow::attackAction() {
    qDebug() << "attack";
}

void GameWindow::blockAction() {
    qDebug() << "block";
}

void GameWindow::dodgeAction() {
    qDebug() << "dodge";
}
