#ifndef SKILLSWINDOW_H
#define SKILLSWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include "character.h"

class SkillsWindow : public QWidget
{
    Q_OBJECT
public:
    explicit SkillsWindow(Character& set_player, QWidget *parent = nullptr);
    void skillPointsChanged();

private:
    QPushButton* healthUpgradeButton;
    QPushButton* damageUpgradeButton;
    QPushButton* defenseUpgradeButton;
    QPushButton* agilityUpgradeButton;
    QPushButton* attackSpeedUpgrade;
    QPushButton* blockSpeedUpgrade;

    QLabel* healthStat;
    QLabel* damageStat;
    QLabel* defenseStat;
    QLabel* agilityStat;
    QLabel* attackCooldownStat;
    QLabel* blockCooldownStat;

    QLabel* skillPointsLabel;
    QLabel* cannotUpgradeLabel;

    QVBoxLayout* upgradeButtonsLayout;
    QVBoxLayout* statisticLabelLayout;
    QVBoxLayout* informationLayout;
    QHBoxLayout* mainUpgradeLayout;
    QVBoxLayout* mainLayout;

    Character* player;

signals:

private slots:
    void upgradeHealth();
    void upgradeDamage();
    void upgradeDefense();
    void upgradeAgility();
    void upgradeAttackSpeed();
    void upgradeBlockSpeed();

};

#endif // SKILLSWINDOW_H
