#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QDebug>
#include <QTimer>
#include <chrono>

#include "character.h"
#include "enemy.h"

class GameWindow : public QWidget
{
    Q_OBJECT

public:
    GameWindow(QWidget *parent = nullptr);
    ~GameWindow();

private:
    QHBoxLayout* actionButtonsLayout;
    QVBoxLayout* mainLayout;
    QVBoxLayout* playerChars;
    QVBoxLayout* enemyChars;
    QHBoxLayout* charsLayout;

    QPushButton* attackButton;
    QPushButton* blockButton;
    QPushButton* dodgeButton;

    QLabel* playerHealthChar;
    QLabel* playerDamageChar;
    QLabel* playerDefenseChar;
    QLabel* playerAgilityChar;

    QLabel* enemyHealthChar;
    QLabel* enemyDamageChar;
    QLabel* enemyDefenseChar;
    QLabel* enemyAgilityChar;

    Character player;
    Enemy enemy;

    std::chrono::high_resolution_clock::time_point attackInterval = std::chrono::high_resolution_clock::now();
    std::chrono::high_resolution_clock::time_point blockInterval = std::chrono::high_resolution_clock::now();
    std::chrono::high_resolution_clock::time_point dodgeInterval = std::chrono::high_resolution_clock::now();

    QTimer *attackTimer;
    QTimer *blockTimer;
    QTimer *dodgeTimer;

private slots:
    void attackAction();
    void blockAction();
    void dodgeAction();

    void attackButtonEnable();
    void blockButtonEnable();
    void dodgeButtonEnable();
};
#endif // GAMEWINDOW_H
