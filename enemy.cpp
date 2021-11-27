#include "enemy.h"

Enemy::Enemy(int set_multiplier, QWidget *parent) : QWidget(parent), multiplier(set_multiplier)
{
    std::uniform_real_distribution<> real_part(0, 1);
    std::uniform_int_distribution<> int_part(1, 5);
    std::uniform_int_distribution<> health_rand(10, 25);
    std::uniform_int_distribution<> attackCooldownRand(500, 2500);

    enemyHealth = health_rand(*QRandomGenerator::global());
    enemyDamage = static_cast<double>(static_cast<int>((real_part(*QRandomGenerator::global()) + int_part(*QRandomGenerator::global())) * 10)) / 10;
    enemyDefense = static_cast<double>(static_cast<int>((real_part(*QRandomGenerator::global()) + int_part(*QRandomGenerator::global())) * 10)) / 10;
    enemyAgility = static_cast<double>(static_cast<int>(real_part(*QRandomGenerator::global()) * 10)) / 10;

    attackCooldown = attackCooldownRand(*QRandomGenerator::global());
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
    std::uniform_int_distribution<> int_part(1, 5);
    std::uniform_int_distribution<> health_rand(10, 25);
    std::uniform_int_distribution<> attackCooldownRand(500, 2500);

    enemyHealth = health_rand(*QRandomGenerator::global());
    enemyDamage = static_cast<double>(static_cast<int>((real_part(*QRandomGenerator::global()) + int_part(*QRandomGenerator::global())) * 10)) / 10;
    enemyDefense = static_cast<double>(static_cast<int>((real_part(*QRandomGenerator::global()) + int_part(*QRandomGenerator::global())) * 10)) / 10;
    enemyAgility = static_cast<double>(static_cast<int>(real_part(*QRandomGenerator::global()) * 10)) / 10;

    attackCooldown = attackCooldownRand(*QRandomGenerator::global());
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

