#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QHBoxLayout>
#include <QDebug>

#include "character.h"

class GameWindow : public QWidget
{
    Q_OBJECT

public:
    GameWindow(QWidget *parent = nullptr);
    ~GameWindow();

private:
    QHBoxLayout* actionButtonsLayout;

    QPushButton* attackButton;
    QPushButton* blockButton;
    QPushButton* dodgeButton;

    Character player;

private slots:
    void attackAction();
    void blockAction();
    void dodgeAction();
};
#endif // GAMEWINDOW_H
