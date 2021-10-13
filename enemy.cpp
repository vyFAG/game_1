#include "enemy.h"

Enemy::Enemy(QWidget *parent) : QWidget(parent)
{
    std::uniform_real_distribution<> real_part(0, 1);

    enemyHealth = static_cast<double>(static_cast<int>(pow(real_part(*QRandomGenerator::global()), 2) * 7 * 3 * 10)) / 10;
    enemyDamage = static_cast<double>(static_cast<int>(pow(real_part(*QRandomGenerator::global()), 2) * 7 * 10)) / 10;
    enemyDefense = static_cast<double>(static_cast<int>(pow(real_part(*QRandomGenerator::global()), 2) * 7 * 10)) / 10;
    enemyAgility = static_cast<double>(static_cast<int>(pow(real_part(*QRandomGenerator::global()), 2) * 7)) / 10;

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

    enemyHealth -= damage;
}

void Enemy::enemyKilled() {
    std::uniform_real_distribution<> real_part(0, 1);

    enemyHealth = static_cast<double>(static_cast<int>(pow(real_part(*QRandomGenerator::global()), 2) * 7 * 3 * 10)) / 10;
    enemyDamage = static_cast<double>(static_cast<int>(pow(real_part(*QRandomGenerator::global()), 2) * 7 * 10)) / 10;
    enemyDefense = static_cast<double>(static_cast<int>(pow(real_part(*QRandomGenerator::global()), 2) * 7 * 10)) / 10;
    enemyAgility = static_cast<double>(static_cast<int>(pow(real_part(*QRandomGenerator::global()), 2) * 7)) / 10;

    attackCooldown = static_cast<double>(static_cast<int>(pow(real_part(*QRandomGenerator::global()), 0.25) * 1000 * 5));
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

