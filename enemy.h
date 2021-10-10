#ifndef ENEMY_H
#define ENEMY_H

#include <QWidget>
#include <QRandomGenerator>

class Enemy : public QWidget
{
    Q_OBJECT
public:
    explicit Enemy(QWidget *parent = nullptr);

    void getAttacked(double damage, bool playerDodged);

    void enemyKilled();

    double getEnemyHealth();
    double getEnemyDamage();
    double getEnemyDefense();
    double getEnemyAgility();

    int getAttackCooldown();

private:
    double enemyHealth;
    double enemyDamage;
    double enemyDefense;
    double enemyAgility;

    int attackCooldown;
signals:

};

#endif // ENEMY_H
