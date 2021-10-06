#include "gamewindow.h"

GameWindow::GameWindow(QWidget *parent)
    : QMainWindow(parent)
{
    attackButton = new QPushButton("Attack", this);
    connect(attackButton, SIGNAL(clicked()), this, SLOT(attackAction()));
}

GameWindow::~GameWindow()
{
}

void GameWindow::attackAction() {
    qDebug() << "attack";
}
