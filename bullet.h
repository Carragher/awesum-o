#ifndef BULLET_H
#define BULLET_H
#include "enemy.h"

#include <fstream>
#include <string>

class Bullet {
    int speed;
    int damage;
    int x;
    int y;
    int id;
    Enemy *target;
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
        speed = 20;
        id = ++nxtId;
    }

    Bullet(int, int);

    void updatePosition();
    Enemy *getTarget() { return target; }
    void setTarget(int);
    int getX() {return x;}
    int getY() {return y;}
    void setX(int newx) {x = newx;}
    void setY(int newy) {y = newy;}
    int getId() {return id;}

    bool isInTarget();

    // save the object to a file
    virtual void save(std::ofstream& saveFile) { saveFile << std::to_string(x) << " " << std::to_string(y); }

};

#endif // BULLET_H
