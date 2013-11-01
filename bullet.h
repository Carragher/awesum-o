#ifndef BULLET_H
#define BULLET_H
#include "enemy.h"

class Bullet {
    int speed;
    int damage;
    Enemy *target;

public:
    Bullet();

    void updatePosition();
};

#endif // BULLET_H
