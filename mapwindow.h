#ifndef MAPWINDOW_H
#define MAPWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QScrollArea>

#include "gamewindow.h"

class MapWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MapWindow(QWidget *parent = nullptr);

private:
    QPushButton* forestMap;
    QPushButton* sewerageMap;

    QHBoxLayout* mapsLayout;
    QScrollArea* mapsScrollArea;

    GameWindow* game;

private slots:
    void mapOpened();
    void showWindow();

signals:

};

#endif // MAPWINDOW_H
