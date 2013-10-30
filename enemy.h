#ifndef ENEMY_H
#define ENEMY_H

class Enemy {
private:
    int hp;
    int moveSpeed;
    int x;
    int y;
    int id;

    static int nextId;
// branch check
public:
    // creates a new enemy and sets the important info for it
    explicit Enemy(int newHp, int newMoveSpeed, int newX, int newY):
        hp(newHp),
        moveSpeed(newMoveSpeed),
        x(newX),
        y(newY) {}

    // for the command classes
    Enemy(): x(0), y(0) {
        id = ++nextId;
    }

    //set nextId to 0
    static void resetNextId() {
        nextId = 0;
    }

    virtual void deathUpdate(){}

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

    virtual void updatePosition() { }
};

class Walker: public Enemy {

public:
    Walker(int newX, int newY): Enemy(50, 10, newX, newY) { }
    Walker(): Enemy(50, 10, 0, 0) { }

    void deathUpdate(); //destroys enemy when hp reaches 0
    void updatePosition(); // updatets the position
};

class Sergeant: public Enemy {

public:
    Sergeant(int newX, int newY): Enemy(100, 5, newX, newY) { }
    Sergeant(): Enemy(50, 10, 0, 0) { }
    void deathUpdate(); //destroys enemy when hp reaches 0
    void updatePosition(); // updatets the position
};

class YOLO: public Enemy {

public:
    YOLO(int newX, int newY): Enemy(25, 20, newX, newY) { }
    YOLO(): Enemy(25, 20, 0, 0) { }
    void deathUpdate(); //destroys enemy when hp reaches 0
    void updatePosition(); // updatets the position
};


#endif // ENEMY_H
