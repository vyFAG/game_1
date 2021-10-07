#ifndef CHARACTER_H
#define CHARACTER_H

#include <QWidget>
#include <chrono>

class Character : public QWidget
{
    Q_OBJECT
public:
    explicit Character(QWidget *parent = nullptr);

    double getPlayerHealth();
    double getPlayerDamage();
    double getPlayerDefense();
    double getPlayerAgility();

    int getAttackCooldown();
    int getBlockCooldown();
    int getDodgeCooldown();

private:
    double playerHealth;
    double palyerDamage;
    double palyerDefense;
    double palyerAgility;

    int attackCooldown;
    int blockCooldown;
    int dodgeCooldown;
signals:

};

#endif // CHARACTER_H
