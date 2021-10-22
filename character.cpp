#include "character.h"

Character::Character(QWidget *parent) : QWidget(parent)
{
    playerHealth = 50;
    playerDamage = 10;
    playerDefense = 5;
    playerAgility = 0.1;

    attackCooldown = 1500;
    blockCooldown = 1500;
    dodgeCooldown = 5000;
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

Character& Character::operator=(const Character& left_var) {
    playerHealth = left_var.getPlayerHealth();
    playerDamage = left_var.getPlayerDamage();
    playerDefense = left_var.getPlayerDefense();
    playerAgility = left_var.getPlayerAgility();

    attackCooldown = left_var.getAttackCooldown();
    blockCooldown = left_var.getBlockCooldown();
    dodgeCooldown = left_var.getDodgeCooldown();

    return *this;
}

double Character::getPlayerExp() const {
    return playerExp;
}
void Character::setPlayerExp(double value) {
    playerExp = value;
}

double Character::getPlayerHealth() const{
    return playerHealth;
}

double Character::getPlayerDamage() const{
    return playerDamage;
}

double Character::getPlayerDefense() const{
    return playerDefense;
}

double Character::getPlayerAgility() const{
    return playerAgility;
}

int Character::getAttackCooldown() const{
    return attackCooldown;
}
int Character::getBlockCooldown() const{
    return blockCooldown;
}
int Character::getDodgeCooldown() const{
    return dodgeCooldown;
}

bool Character::getIsBlocked() const{
    return isBlocked;
}
void Character::setIsBlocked(bool value){
    isBlocked = value;
}

int Character::getIsDodged() const{
    return isDodged;
}

void Character::setIsDodged(int value){
    isDodged = value;
}
