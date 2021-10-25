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
#include "skillswindow.h"

class MapWindow : public QWidget
{
    Q_OBJECT
public:
    explicit MapWindow(QWidget *parent = nullptr);

private:
    QPushButton* forestMap;
    QPushButton* sewerageMap;
    QPushButton* upgradeWindow;

    QLabel* LvlLabel;
    QLabel* ExpLabel;

    QVBoxLayout* mainLayout;
    QHBoxLayout* mapsLayout;
    QHBoxLayout* playerExp;
    QScrollArea* mapsScrollArea;

    GameWindow* gameTab;
    SkillsWindow* upgradeTab;

    Character* player;

    QString expLabelText();
    QString lvlLabelText();

private slots:
    void mapOpened();
    void showWindow();
    void upgradeOpened();

signals:

};

#endif // MAPWINDOW_H
