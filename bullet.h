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
    int targetId;
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
    int getTargetId() { return targetId; }
    void setTarget(int);
    int getX() {return x;}
    int getY() {return y;}
    void setX(int newx) {x = newx;}
    void setY(int newy) {y = newy;}
    int getId() {return id;}

    void setDamage(int newDamage) { damage = newDamage; }
    int getDamage() { return damage; }

    bool isInTarget();

    // save the object to a file
    void save(std::ofstream& saveFile) { saveFile << std::to_string(x) << " " << std::to_string(y) << " bullet " << to_string(targetId); }

};

#endif // BULLET_H
