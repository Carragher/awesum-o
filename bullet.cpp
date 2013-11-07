#include "bullet.h"
#include <vector>
#include "enemy.h"
#include "world.h"
#include "math.h"

using namespace std;
int Bullet::nxtId = 0;

Bullet::Bullet(int s, int d) {
    this->damage = d;
    this->speed = s;

    this->id = this->nxtId;
}

void Bullet::setTarget(int tarid) {
    vector<Enemy*>* evec = World::getInstance().getEnemies();
    for(unsigned int i = 0; i < evec->size();i++ ){
        Enemy * enm = evec->at(i);
        if (enm->getId()== tarid) {
            this->target = enm;
        }

    }
}

void Bullet::updatePosition() {
    // check and see if the enemy is still alive or has reached the finish line

    // get the enemy position and see if the bullet has reached them if so, destroy them

    // move toward the toward the enemy
    if (x < target->getX() + 25) {
        x+= speed;
    } else if (x > target->getX() + 25){
        x-= speed;
    }

    if (y < target->getY() + 25) {
        y+= speed;
    } else if (y > target->getY() + 25){
        y-= speed;
    }
}

bool Bullet::isInTarget() {
    if(x >= target->getX() && x <= target->getX() + 50 && y >= target->getY() && y <= target->getY() + 50) {
        target->hit(damage);
        return true;
    }

    return false;
}
