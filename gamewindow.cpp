#include "gamewindow.h"

GameWindow::GameWindow(Character& set_player, int multiplier, QWidget *parent)
    : QWidget(parent)
{
    absHealth = set_player.getPlayerHealth();

    player = &set_player;
    enemy = new Enemy(multiplier);

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

    enemiesRemaining = new QLabel(this);
    enemiesRemaining->setText(QString::number(passedEnemies) + "/5");
    enemiesRemaining->setAlignment(Qt::AlignCenter);

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

    gameLog = new QTextEdit();
    gameLog->setMaximumHeight(200);
    gameLog->setReadOnly(1);

    actionButtonsLayout->addWidget(attackButton);
    actionButtonsLayout->addWidget(blockButton);
    actionButtonsLayout->addWidget(dodgeButton);

    //actionButtonsLayout->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    charsLayout = new QHBoxLayout();

    charsLayout->addLayout(playerCharsLayout);
    charsLayout->addLayout(enemyCharsLayout);

    mainLayout->addWidget(enemiesRemaining);
    mainLayout->addLayout(charsLayout);
    mainLayout->addLayout(actionButtonsLayout);
    mainLayout->addWidget(gameLog);

    this->setLayout(mainLayout);

    enemyAttackTimer = new QTimer(this);
    connect(enemyAttackTimer, &QTimer::timeout, this, &GameWindow::enemyAttack);
    enemyAttackTimer->start(std::chrono::milliseconds(enemy->getAttackCooldown()));
}

GameWindow::~GameWindow() {
    /*qDebug() << 1;
    delete actionButtonsLayout;
    delete mainLayout;
    delete playerCharsLayout;
    delete enemyCharsLayout;
    delete charsLayout;
    qDebug() << 2;
    delete attackButton;
    delete blockButton;
    delete dodgeButton;
    qDebug() << 3;
    delete playerCharsLabel;
    delete enemyCharsLabel;
    delete enemiesRemaining;
    qDebug() << 4;
    delete gameLog;
    qDebug() << 5;
    delete player;
    delete enemy;
    qDebug() << 6;
    delete attackTimer;
    delete blockTimer;
    delete dodgeTimer;
    qDebug() << 7;
    delete enemyAttackTimer;
    qDebug() << 8;*/
}

void GameWindow::attackAction() {
    if(std::chrono::high_resolution_clock::now() - attackInterval > std::chrono::milliseconds(player->getAttackCooldown())) {
        attackTimer = new QTimer(this);
        connect(attackTimer, &QTimer::timeout, this, &GameWindow::attackButtonEnable);
        attackInterval = std::chrono::high_resolution_clock::now();
        attackButton->setEnabled(0);
        attackTimer->start(std::chrono::milliseconds(player->getAttackCooldown()));

        double pre_attack_health = enemy->getEnemyHealth();
        enemy->getAttacked(player->getPlayerDamage(), player->getIsDodged());
        addToLog(QString("Caused " + QString::number(pre_attack_health - enemy->getEnemyHealth()) + " damage"));
        if(enemy->getEnemyHealth() < 0) {
            addToLog("Enemy died");
            addToLog("You earned " + QString::number(enemy->getExpGain()) + " expirience");
            player->addPlayerExp(enemy->getExpGain());
            passedEnemies += 1;
            enemiesRemaining->setText(QString::number(passedEnemies) + "/5");
            if(passedEnemies == 5) {
                disconnect(enemyAttackTimer, &QTimer::timeout, this, &GameWindow::enemyAttack);
                QMessageBox msgBox;
                msgBox.setWindowTitle("You Won!");
                msgBox.setText("You Won!");
                msgBox.exec();
                this->close();
            }
            else {
                enemy->enemyKilled();
            }
        }
        enemyCharsLabel->setText(createEnemyCharsLabel());
    }
}

void GameWindow::blockAction() {
    if(std::chrono::high_resolution_clock::now() - blockInterval > std::chrono::milliseconds(player->getBlockCooldown())) {
        player->setIsBlocked(1);
        blockTimer = new QTimer(this);
        connect(blockTimer, &QTimer::timeout, this, &GameWindow::blockButtonEnable);
        blockInterval = std::chrono::high_resolution_clock::now();
        blockButton->setEnabled(0);
        blockTimer->start(std::chrono::milliseconds(player->getBlockCooldown()));
    }
}

void GameWindow::dodgeAction() {
    if(std::chrono::high_resolution_clock::now() - dodgeInterval > std::chrono::milliseconds(player->getDodgeCooldown())) {
        dodgeTimer = new QTimer(this);
        connect(dodgeTimer, &QTimer::timeout, this, &GameWindow::dodgeButtonEnable);
        dodgeInterval = std::chrono::high_resolution_clock::now();
        dodgeButton->setEnabled(0);
        dodgeTimer->start(std::chrono::milliseconds(player->getDodgeCooldown()));
        player->isDodgeSuccess();
    }
}

void GameWindow::attackButtonEnable() {
    attackButton->setEnabled(1);
    delete attackTimer;
}

void GameWindow::blockButtonEnable() {
    player->setIsBlocked(0);
    blockButton->setEnabled(1);
    delete blockTimer;
}

void GameWindow::dodgeButtonEnable() {
    player->setIsDodged(2);
    dodgeButton->setEnabled(1);
    delete dodgeTimer;
}

QString GameWindow::createPlayerCharsLabel() {
    return ("HP: " + QString::number(player->getPlayerHealth()) + "\n" +
    "DMG: " + QString::number(player->getPlayerDamage()) + "\n" +
    "DFN: " + QString::number(player->getPlayerDefense()) + "\n" +
    "AGI: " + QString::number(player->getPlayerAgility()));
}

QString GameWindow::createEnemyCharsLabel() {
    return ("HP: " + QString::number(enemy->getEnemyHealth()) + "\n" +
    "DMG: " + QString::number(enemy->getEnemyDamage()) + "\n" +
    "DFN: " + QString::number(enemy->getEnemyDefense()) + "\n" +
    "AGI: " + QString::number(enemy->getEnemyAgility()));
}

void GameWindow::enemyAttack() {
    double pre_attack_health = player->getPlayerHealth();
    player->getAttacked(enemy->getEnemyDamage());
    addToLog(QString("Enemy caused " + QString::number(pre_attack_health - player->getPlayerHealth()) + " damage"));
    playerCharsLabel->setText(createPlayerCharsLabel());

    if(player->getPlayerHealth() < 0) {
        disconnect(enemyAttackTimer, &QTimer::timeout, this, &GameWindow::enemyAttack);
        QMessageBox msgBox;
        msgBox.setWindowTitle("You Lost!");
        msgBox.setText("You were killed");
        msgBox.exec();
        this->close();
    }
}

void GameWindow::addToLog(QString text) {
    gameLog->append(text);
}

void GameWindow::closeEvent(QCloseEvent *event)
{
    delete enemyAttackTimer;

    emit windowClosed();
    event->accept();
}
