#ifndef ENEMY_H
#define ENEMY_H

#include <QWidget>
#include <QRandomGenerator>

class Enemy : public QWidget
{
    Q_OBJECT
public:
    explicit Enemy(int set_multiplier, QWidget *parent = nullptr);

    void getAttacked(double damage, bool playerDodged);

    void enemyKilled();

    double getEnemyHealth() const;
    double getEnemyDamage() const;
    double getEnemyDefense() const;
    double getEnemyAgility() const;
    double getExpGain() const;

    int getAttackCooldown();

private:
    double enemyHealth;
    double enemyDamage;
    double enemyDefense;
    double enemyAgility;
    double enemyExpGain;

    int attackCooldown;

    int multiplier;
signals:

};

#endif // ENEMY_H
