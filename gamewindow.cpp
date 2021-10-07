#include "gamewindow.h"

GameWindow::GameWindow(QWidget *parent)
    : QWidget(parent)
{
    this->setMinimumSize(320, 240);
    this->setMaximumSize(640, 480);
    actionButtonsLayout = new QHBoxLayout();
    mainLayout = new QVBoxLayout(this);

    playerCharsLayout = new QVBoxLayout();
    playerCharsLabel = new QLabel(createPlayerCharsLabel(), this);
    playerCharsLabel->setAlignment(Qt::AlignCenter);
    playerCharsLayout->addWidget(playerCharsLabel);

    enemyCharsLayout = new QVBoxLayout();
    enemyCharsLabel = new QLabel(createEnemyCharsLabel(), this);
    enemyCharsLabel->setAlignment(Qt::AlignCenter);
    enemyCharsLayout->addWidget(enemyCharsLabel);

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

    charsLayout->addLayout(playerCharsLayout);
    charsLayout->addLayout(enemyCharsLayout);

    mainLayout->addLayout(charsLayout);
    mainLayout->addLayout(actionButtonsLayout);

    this->setLayout(mainLayout);
}

GameWindow::~GameWindow() {

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

QString GameWindow::createPlayerCharsLabel() {
    return ("HP: " + QString::number(player.getPlayerHealth()) + "\n" +
    "DMG: " + QString::number(player.getPlayerDamage()) + "\n" +
    "DFN: " + QString::number(player.getPlayerDefense()) + "\n" +
    "AGI: " + QString::number(player.getPlayerAgility()));
}

QString GameWindow::createEnemyCharsLabel() {
    return ("HP: " + QString::number(enemy.getEnemyHealth()) + "\n" +
    "DMG: " + QString::number(enemy.getEnemyDamage()) + "\n" +
    "DFN: " + QString::number(enemy.getEnemyDefense()) + "\n" +
    "AGI: " + QString::number(enemy.getEnemyAgility()));
}
