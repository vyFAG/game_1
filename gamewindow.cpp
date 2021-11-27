#include "gamewindow.h"

GameWindow::GameWindow(Character& set_player, int multiplier, QWidget *parent)
    : QWidget(parent)
{
    absHealth = set_player.getPlayerHealth();

    qDebug() << QFileInfo(QCoreApplication::applicationDirPath()).absoluteFilePath();

    QFile backgroundImageFile(QCoreApplication::applicationDirPath() + "/sprites/map_background_image.png");
    QFileInfo* fileInfoPath = new QFileInfo(backgroundImageFile);

    if(!backgroundImageFile.exists()) {
        qDebug() << 1;
    }

    QPixmap* backgroundImage = new QPixmap(fileInfoPath->absoluteFilePath());
    QPalette* palette = new QPalette();
    palette->setBrush(QPalette::Window, *backgroundImage);
    this->setPalette(*palette);

    QFont* labelsFont = new QFont("Cambria", 20, QFont::Bold);

    player = &set_player;
    enemy = new Enemy(multiplier);

    this->setFixedSize(640, 480);
    actionButtonsLayout = new QHBoxLayout();
    mainLayout = new QVBoxLayout(this);

    playerCharsLayout = new QVBoxLayout();
    playerCharsLabel = new QLabel(createPlayerCharsLabel(), this);
    playerCharsLabel->setAlignment(Qt::AlignCenter);
    playerCharsLabel->setFont(*labelsFont);
    playerCharsLabel->setStyleSheet("color: #ffffff");
    playerCharsLayout->addWidget(playerCharsLabel);

    enemyCharsLayout = new QVBoxLayout();
    enemyCharsLabel = new QLabel(createEnemyCharsLabel(), this);
    enemyCharsLabel->setAlignment(Qt::AlignCenter);
    enemyCharsLabel->setFont(*labelsFont);
    enemyCharsLabel->setStyleSheet("color: #ffffff");
    enemyCharsLayout->addWidget(enemyCharsLabel);

    enemiesRemaining = new QLabel(this);
    enemiesRemaining->setText("Enemies to kill: " + QString::number(passedEnemies) + "/5");
    enemiesRemaining->setFont(*labelsFont);
    enemiesRemaining->setStyleSheet("color: #ffffff");
    enemiesRemaining->setAlignment(Qt::AlignCenter);

    attackButton = new QPushButton("Attack", this);
    attackButton->setMaximumHeight(50);
    attackButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    attackButton->setStyleSheet("color: #ffffff; background-color: #404040");
    attackButton->setFont(*labelsFont);
    connect(attackButton, SIGNAL(clicked()), this, SLOT(attackAction()));

    blockButton = new QPushButton("Block", this);
    blockButton->setMaximumHeight(50);
    blockButton->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    blockButton->setStyleSheet("color: #ffffff; background-color: #404040");
    blockButton->setFont(*labelsFont);
    connect(blockButton, SIGNAL(clicked()), this, SLOT(blockAction()));

    gameLog = new QTextEdit();
    gameLog->setMaximumHeight(200);
    gameLog->setFont(*labelsFont);
    gameLog->setStyleSheet("background-color: #404040; color: #ffffff");
    gameLog->setReadOnly(1);

    actionButtonsLayout->addWidget(attackButton);
    actionButtonsLayout->addWidget(blockButton);

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
        attackButton->setStyleSheet("color: #505050; background-color: #404040");
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
            enemiesRemaining->setText("Enemies to kill: " + QString::number(passedEnemies) + "/5");
            if(passedEnemies == 5) {
                disconnect(enemyAttackTimer, &QTimer::timeout, this, &GameWindow::enemyAttack);
                QMessageBox msgBox;
                msgBox.setWindowTitle("You Won!");
                msgBox.setText("You Won!");
                msgBox.setStyleSheet("background-color: #404040");
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
        blockButton->setStyleSheet("color: #505050; background-color: #404040");
        blockButton->setEnabled(0);
        blockTimer->start(std::chrono::milliseconds(player->getBlockCooldown()));
    }
}

void GameWindow::attackButtonEnable() {
    attackButton->setStyleSheet("color: #ffffff; background-color: #404040");
    attackButton->setEnabled(1);
    delete attackTimer;
}

void GameWindow::blockButtonEnable() {
    player->setIsBlocked(0);
    blockButton->setStyleSheet("color: #ffffff; background-color: #404040");
    blockButton->setEnabled(1);
    delete blockTimer;
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
