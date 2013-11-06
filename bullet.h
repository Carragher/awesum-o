#ifndef BULLET_H
#define BULLET_H
#include "enemy.h"

class Bullet {
    int speed;
    int damage;
    int x;
    int y;
    int id;
    static int nxtId;

    //Enemy *target;// no need

public:

    explicit Bullet(int newSpeed, int newDmg, int newX, int newY):
        speed(newSpeed),
        damage(newDmg),
        x(newX),
        y(newY) {}

    // for the command classes
    Bullet(): x(0), y(0) {
        id = ++nxtId;
    }

    Bullet(int, int);


    void updatePosition();

    int getX() {return x;}
    int getY() {return y;}
    void setX(int newx) {x = newx;}
    void setY(int newy) {y = newy;}
    int getId() {return id;}

};

#endif // BULLET_H
