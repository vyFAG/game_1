#ifndef MAPWINDOW_H
#define MAPWINDOW_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QScrollArea>
#include <character.h>

#include "gamewindow.h"

class MapWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MapWindow(QWidget *parent = nullptr);

private:
    QPushButton* forestMap;
    QPushButton* sewerageMap;

    QLabel* LvlLabel;
    QLabel* ExpLabel;

    QVBoxLayout* mainLayout;
    QHBoxLayout* mapsLayout;
    QHBoxLayout* playerExp;
    QScrollArea* mapsScrollArea;

    GameWindow* game;

    Character* player;

private slots:
    void mapOpened();
    void showWindow();

signals:

};

#endif // MAPWINDOW_H
