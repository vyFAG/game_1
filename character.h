#ifndef CHARACTER_H
#define CHARACTER_H

#include <QWidget>
#include <QRandomGenerator>

class Character
{
    //Q_OBJECT
public:
    Character();
    Character(Character& tmp);

    void getAttacked(double damage);

    void isDodgeSuccess();

    double getPlayerHealth();
    void setPlayerHealth(double set_health);
    double getPlayerDamage();
    void setPlayerDamage(double set_damage);
    double getPlayerDefense();
    void setPlayerDefense(double set_defense);
    double getPlayerAgility();
    void setPlayerAgility(double set_agility);

    bool getIsBlocked();
    void setIsBlocked(bool value);
    int getIsDodged();
    void setIsDodged(int value);

    int getAttackCooldown();
    int getBlockCooldown();
    int getDodgeCooldown();

private:
    double playerHealth;
    double playerDamage;
    double playerDefense;
    double playerAgility;

    bool isBlocked = 0;
    int isDodged = 2;

    int attackCooldown;
    int blockCooldown;
    int dodgeCooldown;

};

#endif // CHARACTER_H
