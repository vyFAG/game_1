#include "gamewindow.h"

GameWindow::GameWindow(QWidget *parent)
    : QWidget(parent)
{
    this->setMinimumSize(320, 240);
    this->setMaximumSize(640, 480);
    actionButtonsLayout = new QHBoxLayout();
    mainLayout = new QVBoxLayout(this);

    playerChars = new QVBoxLayout();

    playerHealthChar = new QLabel("HP: " + QString::number(player.getPlayerHealth()), this);
    playerDamageChar = new QLabel("DMG: " + QString::number(player.getPlayerDamage()), this);
    playerDefenseChar = new QLabel("DFN: " + QString::number(player.getPlayerDefense()), this);
    playerAgilityChar = new QLabel("AGI: " + QString::number(player.getPlayerAgility()), this);

    playerChars->addWidget(playerHealthChar);
    playerChars->addWidget(playerDamageChar);
    playerChars->addWidget(playerDefenseChar);
    playerChars->addWidget(playerAgilityChar);

    enemyChars = new QVBoxLayout();

    enemyHealthChar = new QLabel("HP: " + QString::number(enemy.getEnemyHealth()), this);
    enemyDamageChar = new QLabel("DMG: " + QString::number(enemy.getEnemyDamage()), this);
    enemyDefenseChar = new QLabel("DFN: " + QString::number(enemy.getEnemyDefense()), this);
    enemyAgilityChar = new QLabel("AGI: " + QString::number(enemy.getEnemyAgility()), this);

    enemyChars->addWidget(enemyHealthChar);
    enemyChars->addWidget(enemyDamageChar);
    enemyChars->addWidget(enemyDefenseChar);
    enemyChars->addWidget(enemyAgilityChar);

    attackButton = new QPushButton("Attack", this);
    attackButton->setMaximumHeight(50);
    attackButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    connect(attackButton, SIGNAL(clicked()), this, SLOT(attackAction()));

    blockButton = new QPushButton("Block", this);
    blockButton->setMaximumHeight(50);
    blockButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    connect(blockButton, SIGNAL(clicked()), this, SLOT(blockAction()));

    dodgeButton = new QPushButton("Dodge", this);
    dodgeButton->setMaximumHeight(50);
    dodgeButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    connect(dodgeButton, SIGNAL(clicked()), this, SLOT(dodgeAction()));

    actionButtonsLayout->addWidget(attackButton);
    actionButtonsLayout->addWidget(blockButton);
    actionButtonsLayout->addWidget(dodgeButton);

    //actionButtonsLayout->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    charsLayout = new QHBoxLayout();

    charsLayout->addLayout(playerChars);
    charsLayout->addLayout(enemyChars);

    mainLayout->addLayout(charsLayout);
    mainLayout->addLayout(actionButtonsLayout);

    this->setLayout(mainLayout);
}

GameWindow::~GameWindow()
{

}

void GameWindow::attackAction() {
    if(std::chrono::high_resolution_clock::now() - attackInterval > std::chrono::milliseconds(player.getAttackCooldown())) {
        attackTimer = new QTimer(this);
        connect(attackTimer, &QTimer::timeout, this, &GameWindow::attackButtonEnable);
        attackInterval = std::chrono::high_resolution_clock::now();
        attackButton->setEnabled(0);
        attackTimer->start(std::chrono::milliseconds(player.getAttackCooldown()));
    }
}

void GameWindow::blockAction() {
    if(std::chrono::high_resolution_clock::now() - blockInterval > std::chrono::milliseconds(player.getBlockCooldown())) {
        blockTimer = new QTimer(this);
        connect(blockTimer, &QTimer::timeout, this, &GameWindow::blockButtonEnable);
        blockInterval = std::chrono::high_resolution_clock::now();
        blockButton->setEnabled(0);
        blockTimer->start(std::chrono::milliseconds(player.getBlockCooldown()));
    }
}

void GameWindow::dodgeAction() {
    if(std::chrono::high_resolution_clock::now() - dodgeInterval > std::chrono::milliseconds(player.getDodgeCooldown())) {
        dodgeTimer = new QTimer(this);
        connect(dodgeTimer, &QTimer::timeout, this, &GameWindow::dodgeButtonEnable);
        dodgeInterval = std::chrono::high_resolution_clock::now();
        dodgeButton->setEnabled(0);
        dodgeTimer->start(std::chrono::milliseconds(player.getDodgeCooldown()));
    }
}

void GameWindow::attackButtonEnable() {
    attackButton->setEnabled(1);
    delete attackTimer;
}

void GameWindow::blockButtonEnable() {
    blockButton->setEnabled(1);
    delete blockTimer;
}

void GameWindow::dodgeButtonEnable() {
    dodgeButton->setEnabled(1);
    delete dodgeTimer;
}
