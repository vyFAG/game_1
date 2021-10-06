#include "character.h"

Character::Character(QWidget *parent) : QWidget(parent)
{
    playerHealth = 50;
    palyerDamage = 10;
    palyerDefense = 5;
    palyerAgility = 0.1;

    attackCooldown = 1500;
    blockCooldown = 1500;
    dodgeCooldown = 5000;
}

int Character::getAttackCooldown() {
    return attackCooldown;
}
int Character::getBlockCooldown() {
    return blockCooldown;
}
int Character::getDodgeCooldown() {
    return dodgeCooldown;
}
