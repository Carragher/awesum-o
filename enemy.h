#ifndef ENEMY_H
#define ENEMY_H
#include <string>
using namespace std;
class Enemy {
private:
    int hp;
    int moveSpeed;
    int x;
    int y;
    int id;
    string type;
    static int nextId;
    string direction;

public:
    // creates a new enemy and sets the important info for it
    explicit Enemy(int newHp, int newMoveSpeed, int newX, int newY, string newType, string newDir):
        hp(newHp),
        moveSpeed(newMoveSpeed),
        x(newX),
        y(newY), type(newType), direction(newDir) {}

    // for the command classes
    Enemy(): x(0), y(0) {
        id = ++nextId;
    }

    //set nextId to 0
    static void resetNextId() {
        nextId = 0;
    }

    void deathUpdate();

    void setHp(int hp) { this->hp = hp; }
    int getHp() { return this->hp; }
    void setMoveSpeed(int moveSpeed) { this->moveSpeed = moveSpeed; }
    int getMoveSpeed() { return this->moveSpeed; }
    void setX(int x) { this->x = x; }
    int getX() { return this->x; }
    void setY(int y) { this->y = y; }
    int getY() { return this->y; }
    void setId(int id) { this->id = id; }
    int getId() { return this->id; }
    void setType(string newType) {this->type = newType;}
    string getType() {return this->type;}
    void setDirection(string newDirection){this->direction= newDirection;}
    string getDirection(){return this->direction;}
    void updatePosition();
};

class Walker: public Enemy {

public:
    Walker(int newX, int newY): Enemy(50, 10, newX, newY, "walker", "right") {}
    Walker(): Enemy(50, 10, 0, 0, "walker", "right") { }//was 10

     //destroys enemy when hp reaches 0
   // void updatePosition(); // updatets the position
};

class Sergeant: public Enemy {

public:
    Sergeant(int newX, int newY): Enemy(100, 5, newX, newY, "sergeant", "right") {}
    Sergeant(): Enemy(50, 10, 0, 0, "sergeant", "right") { }
     //destroys enemy when hp reaches 0
    //void updatePosition(); // updatets the position
};

class YOLO: public Enemy {

public:
    YOLO(int newX, int newY): Enemy(25, 20, newX, newY, "YOLO", "right") {}
    YOLO(): Enemy(25, 20, 0, 0, "YOLO", "right") { }
     //destroys enemy when hp reaches 0
   // void updatePosition(); // updatets the position
};


#endif // ENEMY_H
