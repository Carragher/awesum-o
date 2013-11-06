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

void Bullet::updatePosition() {
    // check and see if the enemy is still alive or has reached the finish line

    // get the enemy position and see if the bullet has reached them if so, destroy them

    // move toward the toward the enemy

    double x1;
    double x2;
    double y1;
    double y2;
    double result;
    double xmid;
    double ymid;
    double penult;
    double distance = 0;
    double lastdistance = 0;
    double loopid;
    double i = 0;
    bool firstgo = true;
    x1 = this->getX();
    y1 = this->getY();
    vector<Enemy*>* fixme = World::getInstance().getEnemies();
    if(fixme->size()>0){
    for (unsigned int i; i< fixme->size(); i++){
        Enemy *wan = new Enemy();
        x2 = wan->getX();
        y2 = wan->getY();
        xmid = (x2 -x1);
        xmid = xmid * xmid;
        ymid = y2-y1;
        ymid = ymid * ymid;
        penult = xmid + ymid;
        distance = sqrt(penult);
        if(distance < lastdistance || firstgo == true){
            lastdistance = distance;
            loopid = i;
        }
        if (firstgo == true){
            lastdistance = distance;
            firstgo = false;
        }

        i++;
    }
    Enemy *FW = fixme->at(loopid);
    x2 = FW->getX();
    y2 = FW->getY();
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
    }

}




