#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QTextEdit>
#include <QMessageBox>
#include <QDebug>
#include <QTimer>
#include <chrono>
#include <QCloseEvent>

#include "character.h"
#include "enemy.h"

class GameWindow : public QWidget
{
    Q_OBJECT

public:
    GameWindow(Character& set_player, QWidget *parent = nullptr);
    ~GameWindow();
    void addToLog(QString);
    void closeEvent(QCloseEvent *event);

private:
    QHBoxLayout* actionButtonsLayout;
    QVBoxLayout* mainLayout;
    QVBoxLayout* playerCharsLayout;
    QVBoxLayout* enemyCharsLayout;
    QHBoxLayout* charsLayout;

    QPushButton* attackButton;
    QPushButton* blockButton;
    QPushButton* dodgeButton;

    QLabel* playerCharsLabel;
    QLabel* enemyCharsLabel;
    QLabel* enemiesRemaining;

    QTextEdit* gameLog;

    Character* player;
    Enemy enemy;

    std::chrono::high_resolution_clock::time_point attackInterval = std::chrono::high_resolution_clock::now();
    std::chrono::high_resolution_clock::time_point blockInterval = std::chrono::high_resolution_clock::now();
    std::chrono::high_resolution_clock::time_point dodgeInterval = std::chrono::high_resolution_clock::now();

    QTimer *attackTimer;
    QTimer *blockTimer;
    QTimer *dodgeTimer;

    QTimer *enemyAttackTimer;

    QString createPlayerCharsLabel();
    QString createEnemyCharsLabel();

    int passedEnemies = 0;

    double expGained = 0;
    double absHealth = 0;

signals:
    void windowClosed();

private slots:
    void attackAction();
    void blockAction();
    void dodgeAction();

    void attackButtonEnable();
    void blockButtonEnable();
    void dodgeButtonEnable();

    void enemyAttack();
};
#endif // GAMEWINDOW_H
