#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QDebug>

class GameWindow : public QMainWindow
{
    Q_OBJECT

public:
    GameWindow(QWidget *parent = nullptr);
    ~GameWindow();

private:
    QPushButton* attackButton;

private slots:
    void attackAction();
};
#endif // GAMEWINDOW_H
