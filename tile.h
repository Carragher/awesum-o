#ifndef Tile_H
#define Tile_H

class Tile {
    int id;
    int x;
    int y;
    int width;
    int height;
    bool placable;

public:
    Tile(int newX, int newY, int newWidth, int newHeight, bool newPlacable):
        x(newX),
        y(newY),
        width(newWidth),
        height(newHeight),
        placable(newPlacable) {

        id = ++nextId;
    }

    Tile(): x(0), y(0) {
        id = ++nextId;
    }

    static int nextId; // not sure if this is the right way to do this....

    //set nextId to 0
    static void resetNextId() {
        nextId = 0;
    }
    // getters and setters
    void setId(int id) { this->id = id; }
    int getId() { return this->id; }
    void setX(int x) { this->x = x; }
    int getX() { return this->x; }
    void setY(int y) { this->y = y; }
    int getY() { return this->y; }
    void setWidth(int width) { this->width = width; }
    int getWidth() { return this->width; }
    void setHeight(int height) { this->height = height; }
    int getHeight() { return this->height; }
    void setPlacable(bool placable) { this->placable = placable; }
    bool getPlacable() { return this->placable; }
};


class pathTile : public Tile {

    int nextTile;

public:
     pathTile(int newX, int newY, int newWidth, int newHeight, bool newPlacable, int newNextTile):
        Tile(newX, newY, newWidth, newHeight, newPlacable) {
        nextTile = newNextTile;
    }

    pathTile(): Tile() { }

    void setNextTile(int nextTile) { this->nextTile = nextTile; }
    int getNextTile() { return this->nextTile; }

};

class towerTile : public Tile {
    int health;
    int fireSpeed;
    int damage;
    int range;

public:
    towerTile(int newX, int newY, int newWidth, int newHeight, bool newPlacable):
        Tile(newX, newY, newWidth, newHeight, newPlacable) { }

//    towerTile(): Tile() { }

    void deathUpdate();// this method will destroy a tower when it dies

    void setHealth(int health) { this->health = health; }
    int getHealth() { return this->health; }
    void setFireSpeed(int fireSpeed) { this->fireSpeed = fireSpeed; }
    int getFireSpeed() { return this->fireSpeed; }
    void setDamage(int damage) { this->damage = damage; }
    int getDamage() { return this->damage; }
    void setRange(int range) { this->range = range; }
    int getRange() { return this->range; }

    virtual void updateInfo();

};


#endif // Tile_H
