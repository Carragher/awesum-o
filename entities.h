#ifndef ENTITIES_H
#define ENTITIES_H

class entities {
private:
    int hp;
    int moveSpeed;
    int x;
    int y;

public:
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



#endif // ENTITIES_H
