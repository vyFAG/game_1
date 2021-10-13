#include "character.h"

Character::Character() {
    playerHealth = 50;
    playerDamage = 10;
    playerDefense = 5;
    playerAgility = 0.1;

    attackCooldown = 1500;
    blockCooldown = 1500;
    dodgeCooldown = 5000;
}

Character::Character(Character& tmp) {
    playerHealth = tmp.playerHealth;
    playerDamage = tmp.playerDamage;
    playerDefense = tmp.playerDefense;
    playerAgility = tmp.playerAgility;

    attackCooldown = tmp.attackCooldown;
    blockCooldown = tmp.blockCooldown;
    dodgeCooldown = tmp.dodgeCooldown;
}

void Character::isDodgeSuccess() {
    std::uniform_real_distribution<> boolDodge(0, 1);
    if(boolDodge(*QRandomGenerator::global()) <= playerAgility) {
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
void Character::setPlayerHealth(double set_health) {
    playerHealth = set_health;
}

double Character::getPlayerDamage() {
    return playerDamage;
}
void Character::setPlayerDamage(double set_damage) {
    playerDamage = set_damage;
}

double Character::getPlayerDefense() {
    return playerDefense;
}
void Character::setPlayerDefense(double set_defense) {
    playerDefense = set_defense;
}

double Character::getPlayerAgility() {
    return playerAgility;
}
void Character::setPlayerAgility(double set_agility) {
    playerAgility = set_agility;
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

/*Character& Character::operator=(Character other) {
    playerHealth = other.playerHealth;
    playerDamage = other.playerDamage;
    playerDefense = other.playerDefense;
    playerAgility = other.playerAgility;

    attackCooldown = other.attackCooldown;
    blockCooldown = other.blockCooldown;
    dodgeCooldown = other.dodgeCooldown;
}*/
