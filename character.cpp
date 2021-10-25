#include "character.h"

Character::Character(QWidget *parent) : QWidget(parent)
{
    playerMaxHealth = 50;
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
void Character::addPlayerExp(double value) {
    playerExp += value;
    if(sqrt(playerExp) + 1 > playerLvl) {
        playerLvl += 1;
        upgradePoints += 1;
    }
}

int Character::getUpgradePoints() const {
    return upgradePoints;
}

int Character::getPlayerLvl() const {
    return playerLvl;
}

double Character::getPlayerMaxHealth() const {
    return playerMaxHealth;
}
void Character::setPlayerMaxHealth(double value) {
    playerMaxHealth = static_cast<double>(static_cast<int>(value * 10)) / 10;
}

double Character::getPlayerHealth() const{
    return playerHealth;
}
void Character::setPlayerHealth(double value) {
    playerHealth = static_cast<double>(static_cast<int>(value * 10)) / 10;
}

double Character::getPlayerDamage() const{
    return playerDamage;
}
void Character::setPlayerDamage(double value) {
    playerDamage = static_cast<double>(static_cast<int>(value * 10)) / 10;
}

double Character::getPlayerDefense() const{
    return playerDefense;
}
void Character::setPlayerDefense(double value) {
    playerDefense = static_cast<double>(static_cast<int>(value * 10)) / 10;
}

double Character::getPlayerAgility() const{
    return playerAgility;
}
void Character::setPlayerAgility(double value) {
    playerAgility = static_cast<double>(static_cast<int>(value * 10)) / 10;
}

int Character::getAttackCooldown() const{
    return attackCooldown;
}
void Character::setAttackCooldown(int value) {
    attackCooldown = value;
}

int Character::getBlockCooldown() const{
    return blockCooldown;
}
void Character::setBlockCooldown(int value) {
    blockCooldown = value;
}

int Character::getDodgeCooldown() const{
    return dodgeCooldown;
}
void Character::setDodgeCooldown(int value) {
    dodgeCooldown = value;
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
