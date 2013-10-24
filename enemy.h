#ifndef ENEMY_H
#define ENEMY_H

class Enemy {
private:
    int hp;
    int moveSpeed;
    int x;
    int y;

    static int nextId;

public:
    // creates a new enemy and sets the important info for it
    explicit Enemy(int newHp, int newMoveSpeed, int newX, int newY):
        hp(newHp),
        moveSpeed(newMoveSpeed),
        x(newX),
        y(newY) { }

    //set nextId to 0
    static void resetNextId() {
        nextId = 0;
    }

    void setHp(int hp) { this->hp = hp; }
    int getHp() { return this->hp; }
    void setMoveSpeed(int moveSpeed) { this->moveSpeed = moveSpeed; }
    int getMoveSpeed() { return this->moveSpeed; }
    void setX(int x) { this->x = x; }
    int getX() { return this->x; }
    void setY(int y) { this->y = y; }
    int getY() { return this->y; }

    virtual void updatePosition() { }
};



#endif // ENEMY_H
