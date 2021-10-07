#ifndef ENEMY_H
#define ENEMY_H

#include <QWidget>
#include <random>

class Enemy : public QWidget
{
    Q_OBJECT
public:
    explicit Enemy(QWidget *parent = nullptr);

    double getEnemyHealth();
    double getEnemyDamage();
    double getEnemyDefense();
    double getEnemyAgility();

    int getAttackCooldown();
    int getBlockCooldown();
    int getDodgeCooldown();

private:
    double enemyHealth;
    double enemyDamage;
    double enemyDefense;
    double enemyAgility;

    int attackCooldown;
    int blockCooldown;
    int dodgeCooldown;
signals:

};

#endif // ENEMY_H
