#ifndef CHARACTER_H
#define CHARACTER_H

#include <QWidget>
#include <QRandomGenerator>

class Character : public QWidget
{
    Q_OBJECT
public:
    explicit Character(QWidget *parent = nullptr);

    void getAttacked(double damage);

    void isDodgeSuccess();

    double getPlayerHealth();
    double getPlayerDamage();
    double getPlayerDefense();
    double getPlayerAgility();

    bool getIsBlocked();
    void setIsBlocked(bool value);
    int getIsDodged();
    void setIsDodged(int value);

    int getAttackCooldown();
    int getBlockCooldown();
    int getDodgeCooldown();

private:
    double playerHealth;
    double palyerDamage;
    double palyerDefense;
    double palyerAgility;

    bool isBlocked = 0;
    int isDodged = 2;

    int attackCooldown;
    int blockCooldown;
    int dodgeCooldown;
signals:

};

#endif // CHARACTER_H
