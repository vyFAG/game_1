#include "enemy.h"

Enemy::Enemy(QWidget *parent) : QWidget(parent)
{
    std::uniform_real_distribution<> real_part(0, 1);
    std::uniform_int_distribution<> int_part(1, 5);
    std::uniform_int_distribution<> health_rand(10, 25);

    enemyHealth = health_rand(*QRandomGenerator::global());
    enemyDamage = static_cast<double>(static_cast<int>((real_part(*QRandomGenerator::global()) + int_part(*QRandomGenerator::global())) * 10)) / 10;
    enemyDefense = static_cast<double>(static_cast<int>((real_part(*QRandomGenerator::global()) + int_part(*QRandomGenerator::global())) * 10)) / 10;
    enemyAgility = static_cast<double>(static_cast<int>(real_part(*QRandomGenerator::global()) * 10)) / 10;

    attackCooldown = static_cast<double>(static_cast<int>((real_part(*QRandomGenerator::global()) + int_part(*QRandomGenerator::global())) * 10)) / 10;
    blockCooldown = static_cast<double>(static_cast<int>((real_part(*QRandomGenerator::global()) + int_part(*QRandomGenerator::global())) * 10)) / 10;
    dodgeCooldown = static_cast<double>(static_cast<int>((real_part(*QRandomGenerator::global()) + int_part(*QRandomGenerator::global())) * 10)) / 10;
}

double Enemy::getEnemyHealth() {
    return enemyHealth;
}

double Enemy::getEnemyDamage() {
    return enemyDamage;
}

double Enemy::getEnemyDefense() {
    return enemyDefense;
}

double Enemy::getEnemyAgility() {
    return enemyAgility;
}

int Enemy::getAttackCooldown() {
    return attackCooldown;
}
int Enemy::getBlockCooldown() {
    return blockCooldown;
}
int Enemy::getDodgeCooldown() {
    return dodgeCooldown;
}
