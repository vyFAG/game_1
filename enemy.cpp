#include "enemy.h"

Enemy::Enemy(int set_multiplier, QWidget *parent) : QWidget(parent), multiplier(set_multiplier)
{
    std::uniform_real_distribution<> real_part(0, 1);

    enemyHealth = static_cast<double>(static_cast<int>(sqrt(real_part(*QRandomGenerator::global())) * multiplier * 3 * 10)) / 10;
    enemyDamage = static_cast<double>(static_cast<int>(sqrt(real_part(*QRandomGenerator::global())) * multiplier * 10)) / 10;
    enemyDefense = static_cast<double>(static_cast<int>(sqrt(real_part(*QRandomGenerator::global())) * multiplier * 10)) / 10;
    enemyAgility = static_cast<double>(static_cast<int>((pow(real_part(*QRandomGenerator::global()) / 1.2, 2) + 0.1) * 10)) / 10;
    enemyExpGain = static_cast<double>(static_cast<int>(sqrt(real_part(*QRandomGenerator::global())) * multiplier * 10)) / 10;

    attackCooldown = static_cast<double>(static_cast<int>(pow(real_part(*QRandomGenerator::global()), 0.25) * 1000 * 5));
}

void Enemy::getAttacked(double damage, bool playerDodged) {

    std::uniform_real_distribution<> real_part(0, 1);
    if(real_part(*QRandomGenerator::global()) <= enemyAgility) {
        damage = 0;
    }

    if(playerDodged == 1) {
        damage *= 2;
    }

    if (damage != 0) {
        damage -= enemyDefense;
    }

    if (damage > 0) {
        enemyHealth -= damage;
    }
}

void Enemy::enemyKilled() {
    std::uniform_real_distribution<> real_part(0, 1);

    enemyHealth = static_cast<double>(static_cast<int>(sqrt(real_part(*QRandomGenerator::global())) * multiplier * 3 * 10)) / 10;
    enemyDamage = static_cast<double>(static_cast<int>(sqrt(real_part(*QRandomGenerator::global())) * multiplier * 10)) / 10;
    enemyDefense = static_cast<double>(static_cast<int>(sqrt(real_part(*QRandomGenerator::global())) * multiplier * 10)) / 10;
    enemyAgility = static_cast<double>(static_cast<int>((pow(real_part(*QRandomGenerator::global()) / 1.2, 2) + 0.1) * 10)) / 10;
    enemyExpGain = static_cast<double>(static_cast<int>(sqrt(real_part(*QRandomGenerator::global())) * multiplier * 10)) / 10;

    attackCooldown = static_cast<double>(static_cast<int>(pow(real_part(*QRandomGenerator::global()), 0.25) * 1000 * 5));
}

double Enemy::getEnemyHealth() const{
    return enemyHealth;
}

double Enemy::getEnemyDamage() const{
    return enemyDamage;
}

double Enemy::getEnemyDefense() const{
    return enemyDefense;
}

double Enemy::getEnemyAgility() const{
    return enemyAgility;
}

double Enemy::getExpGain() const {
    return enemyExpGain;
}

int Enemy::getAttackCooldown() {
    return attackCooldown;
}

