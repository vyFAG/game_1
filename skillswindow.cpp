#include "skillswindow.h"

SkillsWindow::SkillsWindow(Character& set_player, QWidget *parent) : QWidget(parent)
{
    player = &set_player;

    healthUpgradeButton = new QPushButton("Health", this);
    connect(healthUpgradeButton, SIGNAL(clicked()), this, SLOT(upgradeHealth()));
    damageUpgradeButton = new QPushButton("Damage", this);
    connect(damageUpgradeButton, SIGNAL(clicked()), this, SLOT(upgradeDamage()));
    defenseUpgradeButton = new QPushButton("Defense", this);
    connect(defenseUpgradeButton, SIGNAL(clicked()), this, SLOT(upgradeDefense()));
    agilityUpgradeButton = new QPushButton("Agility", this);
    connect(agilityUpgradeButton, SIGNAL(clicked()), this, SLOT(upgradeAgility()));
    attackSpeedUpgrade = new QPushButton("Attack cooldown", this);
    connect(attackSpeedUpgrade, SIGNAL(clicked()), this, SLOT(upgradeAttackSpeed()));
    blockSpeedUpgrade = new QPushButton("Block cooldown", this);
    connect(blockSpeedUpgrade, SIGNAL(clicked()), this, SLOT(upgradeBlockSpeed()));

    upgradeButtonsLayout = new QVBoxLayout();
    upgradeButtonsLayout->addWidget(healthUpgradeButton);
    upgradeButtonsLayout->addWidget(damageUpgradeButton);
    upgradeButtonsLayout->addWidget(defenseUpgradeButton);
    upgradeButtonsLayout->addWidget(agilityUpgradeButton);
    upgradeButtonsLayout->addWidget(attackSpeedUpgrade);
    upgradeButtonsLayout->addWidget(blockSpeedUpgrade);

    skillPointsLabel = new QLabel("You have " + QString::number(player->getUpgradePoints()) + " skillpoints", this);
    cannotUpgradeLabel = new QLabel("You don't have enough skillpoints", this);

    informationLayout = new QVBoxLayout();
    informationLayout->addWidget(skillPointsLabel);
    informationLayout->addWidget(cannotUpgradeLabel);
    cannotUpgradeLabel->hide();

    healthStat = new QLabel(QString::number(player->getPlayerMaxHealth()), this);
    damageStat = new QLabel(QString::number(player->getPlayerDamage()), this);
    defenseStat = new QLabel(QString::number(player->getPlayerDefense()), this);
    agilityStat = new QLabel(QString::number(player->getPlayerAgility()), this);
    attackCooldownStat = new QLabel(QString::number(player->getAttackCooldown()), this);
    blockCooldownStat = new QLabel(QString::number(player->getBlockCooldown()), this);

    statisticLabelLayout = new QVBoxLayout();
    statisticLabelLayout->addWidget(healthStat);
    statisticLabelLayout->addWidget(damageStat);
    statisticLabelLayout->addWidget(defenseStat);
    statisticLabelLayout->addWidget(agilityStat);
    statisticLabelLayout->addWidget(attackCooldownStat);
    statisticLabelLayout->addWidget(blockCooldownStat);

    mainLayout = new QVBoxLayout(this);

    QLabel* textLabel = new QLabel("Choose option to upgrade", this);
    textLabel->setAlignment(Qt::AlignCenter);

    mainUpgradeLayout = new QHBoxLayout();
    mainUpgradeLayout->addLayout(upgradeButtonsLayout);
    mainUpgradeLayout->addLayout(statisticLabelLayout);

    mainLayout->addWidget(textLabel);
    mainLayout->addLayout(informationLayout);
    mainLayout->addLayout(mainUpgradeLayout);
}

void SkillsWindow::upgradeHealth() {
    if(player->getUpgradePoints() != 0) {
        player->setPlayerMaxHealth(player->getPlayerMaxHealth() * 1.1);
        player->setPlayerHealth(player->getPlayerMaxHealth());

        healthStat->setText(QString::number(player->getPlayerMaxHealth()));

        player->decreaseUpgradePoints();
        skillPointsChanged();
    }
    else {
        cannotUpgradeLabel->show();
    }
}
void SkillsWindow::upgradeDamage() {
    if(player->getUpgradePoints() != 0) {
        player->setPlayerDamage(player->getPlayerDamage() * 1.1);
        damageStat->setText(QString::number(player->getPlayerDamage()));

        player->decreaseUpgradePoints();
        skillPointsChanged();
    }
    else {
        cannotUpgradeLabel->show();
    }
}
void SkillsWindow::upgradeDefense() {
    if(player->getUpgradePoints() != 0) {
        player->setPlayerDefense(player->getPlayerDefense() * 1.1);
        defenseStat->setText(QString::number(player->getPlayerDefense()));

        player->decreaseUpgradePoints();
        skillPointsChanged();
    }
    else {
        cannotUpgradeLabel->show();
    }
}
void SkillsWindow::upgradeAgility() {
    if(player->getUpgradePoints() != 0) {
        player->setPlayerAgility(player->getPlayerAgility() * 1.1);
        agilityStat->setText(QString::number(player->getPlayerAgility()));

        player->decreaseUpgradePoints();
        skillPointsChanged();
    }
    else {
        cannotUpgradeLabel->show();
    }
}
void SkillsWindow::upgradeAttackSpeed() {
    if(player->getUpgradePoints() != 0) {
        player->setAttackCooldown(player->getAttackCooldown() * 0.9);
        attackCooldownStat->setText(QString::number(player->getAttackCooldown()));

        player->decreaseUpgradePoints();
        skillPointsChanged();
    }
    else {
        cannotUpgradeLabel->show();
    }
}
void SkillsWindow::upgradeBlockSpeed() {
    if(player->getUpgradePoints() != 0) {
        player->setBlockCooldown(player->getBlockCooldown() * 0.9);
        blockCooldownStat->setText(QString::number(player->getBlockCooldown()));

        player->decreaseUpgradePoints();
        skillPointsChanged();
    }
    else {
        cannotUpgradeLabel->show();
    }
}

void SkillsWindow::skillPointsChanged() {
    skillPointsLabel->setText("You have " + QString::number(player->getUpgradePoints()) + " skillpoints");
}
