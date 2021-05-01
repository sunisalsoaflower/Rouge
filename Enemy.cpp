
#include<random>
#include<ctime>

#include "Enemy.h"
#include"Player.h"

Enemy::Enemy(string name,char tile, int health, int attack,int defense)

{
    _name = name;
    _health = health;
    _attack = attack;
    _tile = tile;
    _defense = defense;
}


int Enemy::takeDamage(int attack) {
    attack -= _defense;
    //checks if attack does damage
    if (attack > 0) {
        _health -= attack;
        
        //checks if enemy died
        if (_health <= 0) {
            return _score++;
        }
    }


}


char Enemy::getname() {
    return this->_name[0];
}