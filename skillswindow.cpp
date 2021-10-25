#include "skillswindow.h"

SkillsWindow::SkillsWindow(QWidget *parent) : QWidget(parent)
{
    healthUpgradeButton = new QPushButton("Health", this);
    damageUpgradeButton = new QPushButton("Damage", this);
    defenseUpgradeButton = new QPushButton("Defense", this);
    agilityUpgradeButton = new QPushButton("Agility", this);
    attackSpeedUpgrade = new QPushButton("Attack cooldown", this);
    blockSpeedUpgrade = new QPushButton("Block cooldown", this);
    dodgeSpeedUpgrade = new QPushButton("Dodge cooldown", this);

    upgradeButtonsLayout = new QVBoxLayout();
    upgradeButtonsLayout->addWidget(healthUpgradeButton);
    upgradeButtonsLayout->addWidget(damageUpgradeButton);
    upgradeButtonsLayout->addWidget(defenseUpgradeButton);
    upgradeButtonsLayout->addWidget(agilityUpgradeButton);
    upgradeButtonsLayout->addWidget(attackSpeedUpgrade);
    upgradeButtonsLayout->addWidget(blockSpeedUpgrade);
    upgradeButtonsLayout->addWidget(dodgeSpeedUpgrade);

    healthStat = new QLabel("HP", this);
    damageStat = new QLabel("DMG", this);
    defenseStat = new QLabel("DEF", this);
    agilityStat = new QLabel("AGI", this);
    attackCooldownStat = new QLabel("HP", this);
    blockCooldownStat = new QLabel("HP", this);
    dodgeCooldownStat = new QLabel("HP", this);

    statisticLabelLayout = new QVBoxLayout();
    statisticLabelLayout->addWidget(healthStat);
    statisticLabelLayout->addWidget(damageStat);
    statisticLabelLayout->addWidget(defenseStat);
    statisticLabelLayout->addWidget(agilityStat);
    statisticLabelLayout->addWidget(attackCooldownStat);
    statisticLabelLayout->addWidget(blockCooldownStat);
    statisticLabelLayout->addWidget(dodgeCooldownStat);

    mainUpgradeLayout = new QHBoxLayout(this);
    mainUpgradeLayout->addLayout(upgradeButtonsLayout);
    mainUpgradeLayout->addLayout(statisticLabelLayout);

    this->setLayout(mainUpgradeLayout);
}
