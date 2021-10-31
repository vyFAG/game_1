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

    int levelCheck(double exp);

    double getPlayerExp() const;
    void addPlayerExp(double);

    int getUpgradePoints() const;
    void decreaseUpgradePoints();

    int getPlayerLvl() const;
    //void addPlayerLvl(double);

    double getPlayerMaxHealth() const;
    void setPlayerMaxHealth(double);
    double getPlayerHealth() const;
    void setPlayerHealth(double);
    double getPlayerDamage() const;
    void setPlayerDamage(double);
    double getPlayerDefense() const;
    void setPlayerDefense(double);
    double getPlayerAgility() const;
    void setPlayerAgility(double);

    bool getIsBlocked() const;
    void setIsBlocked(bool value);
    int getIsDodged() const;
    void setIsDodged(int value);

    int getAttackCooldown() const;
    void setAttackCooldown(int);
    int getBlockCooldown() const;
    void setBlockCooldown(int);
    int getDodgeCooldown() const;
    void setDodgeCooldown(int);

    Character& operator=(const Character&);

private:
    double playerExp = 0;
    int playerLvl = 1;

    int upgradePoints = 0;

    double playerMaxHealth;
    double playerHealth;
    double playerDamage;
    double playerDefense;
    double playerAgility;

    bool isBlocked = 0;
    int isDodged = 2;

    int attackCooldown;
    int blockCooldown;

signals:

};

#endif // CHARACTER_H
