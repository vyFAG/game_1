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

    double getPlayerExp() const;
    void addPlayerExp(double);

    int getPlayerLvl() const;
    //void addPlayerLvl(double);

    double getPlayerMaxHealth() const;
    double getPlayerHealth() const;
    double getPlayerDamage() const;
    double getPlayerDefense() const;
    double getPlayerAgility() const;

    bool getIsBlocked() const;
    void setIsBlocked(bool value);
    int getIsDodged() const;
    void setIsDodged(int value);

    int getAttackCooldown() const;
    int getBlockCooldown() const;
    int getDodgeCooldown() const;

    Character& operator=(const Character&);

private:
    double playerExp = 0;
    int playerLvl = 1;

    double playerMaxHealth;
    double playerHealth;
    double playerDamage;
    double playerDefense;
    double playerAgility;

    bool isBlocked = 0;
    int isDodged = 2;

    int attackCooldown;
    int blockCooldown;
    int dodgeCooldown;
signals:

};

#endif // CHARACTER_H
