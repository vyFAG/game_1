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

void Character::isDodgeSuccess() {
    std::uniform_real_distribution<> boolDodge(0, 1);
    if(boolDodge(*QRandomGenerator::global()) <= palyerAgility) {
        isDodged = 1;
    }
    else {
        isDodged = 0;
    }
}

void Character::getAttacked(double damage) {
    if(isDodged == 1) {
        damage = 0;
    }
    if(isBlocked == 1 && damage != 0) {
        damage = damage - getPlayerDefense();
    }
    else {
        damage -= getPlayerDefense() * 0.5;
    }
    if (damage >= 0) {
        playerHealth -= damage;
    }
}

double Character::getPlayerHealth() {
    return playerHealth;
}

double Character::getPlayerDamage() {
    return palyerDamage;
}

double Character::getPlayerDefense() {
    return palyerDefense;
}

double Character::getPlayerAgility() {
    return palyerAgility;
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

bool Character::getIsBlocked() {
    return isBlocked;
}

void Character::setIsBlocked(bool value){
    isBlocked = value;
}

int Character::getIsDodged() {
    return isDodged;
}

void Character::setIsDodged(int value){
    isDodged = value;
}
