#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QDebug>
#include <chrono>

#include "character.h"

class GameWindow : public QWidget
{
    Q_OBJECT

public:
    GameWindow(QWidget *parent = nullptr);
    ~GameWindow();

private:
    QHBoxLayout* actionButtonsLayout;
    QVBoxLayout* mainLayout;

    QPushButton* attackButton;
    QPushButton* blockButton;
    QPushButton* dodgeButton;

    QLabel* graphicsLabel;

    Character player;

    std::chrono::high_resolution_clock::time_point attackInterval = std::chrono::high_resolution_clock::now();
    std::chrono::high_resolution_clock::time_point blockInterval = std::chrono::high_resolution_clock::now();
    std::chrono::high_resolution_clock::time_point dodgeInterval = std::chrono::high_resolution_clock::now();

private slots:
    void attackAction();
    void blockAction();
    void dodgeAction();
};
#endif // GAMEWINDOW_H
