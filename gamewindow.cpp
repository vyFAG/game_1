#include "gamewindow.h"

GameWindow::GameWindow(QWidget *parent)
    : QMainWindow(parent)
{
    attackButton = new QPushButton("Attack", this);
}

GameWindow::~GameWindow()
{
}

