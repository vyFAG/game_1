#ifndef CHARACTER_H
#define CHARACTER_H

#include <QWidget>

class Character : public QWidget
{
    Q_OBJECT
public:
    explicit Character(QWidget *parent = nullptr);

private:
    double playerHealth;
    double palyerDamage;
    double palyerDefense;
    double palyerAgility;

    double attackCooldown;
    double blockCooldown;
    double dodgeCooldown;
signals:

};

#endif // CHARACTER_H
