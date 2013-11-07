#include "enemy.h"
#include "world.h"

int Enemy::nextId = 0;
void Enemy::updatePosition()
{
    // 750
    int update = this->getMoveSpeed();
    int newX = this->getX();
    int newY = this->getY();
    bool state0 = false;//right
    bool state1 = false;//right down
    bool state2 = false;//left
    bool state3 = false;//left down

    if (newX != 750 && (newY % 200 == 0 || newY == 0)){
        state0 = true;

    }
    else if (newX ==750 && (newY % 100 != 0 || newY == 0)){
        state1 = true;

    } else if (newX != 0 && (newY % 100 == 0 && newY % 200 !=0)){
        state2 = true;

    } else {
        state3 = true;
         }

    if (state0){

        newX+=update;
        //newY+=update;
        this->setX(newX);
       // this->setY(newY);
        this->setDirection("right");
    }
    if (state1){
        newY+=update;
        this->setY(newY);
        this->setDirection("down");

    }
    if (state2){
        newX-=update;
        this->setX(newX);
        this->setDirection("left");
    }
    if (state3){
        newY+=update;
        this->setY(newY);
        this->setDirection("down");
    }
}

int Enemy::deathUpdate(){
    if (hp <= 0) {
        World::getInstance().setScore(25);
        return id;
    }

    return -1;
}

void Enemy::hit(int damage) {
    hp-=damage;
}




