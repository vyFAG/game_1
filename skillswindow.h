#ifndef SKILLSWINDOW_H
#define SKILLSWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>

class SkillsWindow : public QWidget
{
    Q_OBJECT
public:
    explicit SkillsWindow(QWidget *parent = nullptr);

private:
    QPushButton* healthUpgradeButton;
    QPushButton* damageUpgradeButton;
    QPushButton* defenseUpgradeButton;
    QPushButton* agilityUpgradeButton;
    QPushButton* attackSpeedUpgrade;
    QPushButton* blockSpeedUpgrade;
    QPushButton* dodgeSpeedUpgrade;

    QLabel* healthStat;
    QLabel* damageStat;
    QLabel* defenseStat;
    QLabel* agilityStat;
    QLabel* attackCooldownStat;
    QLabel* blockCooldownStat;
    QLabel* dodgeCooldownStat;

    QVBoxLayout* upgradeButtonsLayout;
    QVBoxLayout* statisticLabelLayout;
    QHBoxLayout* mainUpgradeLayout;

signals:

};

#endif // SKILLSWINDOW_H
