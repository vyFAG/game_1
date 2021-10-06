#include "character.h"

Character::Character(QWidget *parent) : QWidget(parent)
{
    playerHealth = 50;
    palyerDamage = 10;
    palyerDefense = 5;
    palyerAgility = 0.1;

    attackCooldown = 1.5;
    blockCooldown = 1.5;
    dodgeCooldown = 5.0;
}
