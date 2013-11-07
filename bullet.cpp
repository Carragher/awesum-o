#include "bullet.h"
#include <vector>
#include "enemy.h"
#include "world.h"
#include "math.h"

using namespace std;
int Bullet::nxtId = 0;

Bullet::Bullet(int s, int d)
{
    this->damage = d;
    this->speed = s;

    this->id = this->nxtId;


}
void Bullet::setOb(int tarid) {
    vector<Enemy*>* evec = World::getInstance().getEnemies();
    for(unsigned int i = 0; i < evec->size();i++ ){
        Enemy * enm = evec->at(i);
        if (enm->getId()== tarid) {
            this->findme = enm;
        }

    }



}

void Bullet::updatePosition() {
    // check and see if the enemy is still alive or has reached the finish line

    // get the enemy position and see if the bullet has reached them if so, destroy them

    // move toward the toward the enemy
   // if(this->getme() != NULL){
        double x1;
        double x2;
        double y1;
        double y2;
        x1 = this->getX();
        y1 = this->getY();
        x2 = this->getme()->getX();
        y2 = this->getme()->getY();

        if (x1 < x2){
            this->setX(x1+1);
        } else {
            this->setX(x1-1);
        }
        if (y1 < y2){
            this->setY(y1+1);
        } else {
            this->setY(y1-1);
        }





   // }


}




