#ifndef TILE_H
#define TILE_H

class tile {
    int id;
    int x;
    int y;
    int width;
    int height;
    bool placable;

public:
    explicit tile(int newX, int newY, int newWidth, int newHeight, bool newPlacable):
        x(newX),
        y(newY),
        width(newWidth),
        height(newHeight),
        placable(newPlacable) {

        // set the id

    }

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


class pathTile : public tile {
    int nextTile;

public:
    explicit pathTile(int newX, int newY, int newWidth, int newHeight, bool newPlacable, int newNextTile):
        tile(newX, newY, newWidth, newHeight, newPlacable) {

        nextTile = newNextTile;

    }

    void setNextTile(int nextTile) { this->nextTile = nextTile; }
    int getNextTile() { return this->nextTile; }

};

class towerTile : public tile {
    int health;
    int fireSpeed;
    int damage;
    int range;

public:
    void setHealth(int health) { this->health = health; }
    int getHealth() { return this->health; }
    void setFireSpeed(int fireSpeed) { this->fireSpeed = fireSpeed; }
    int getFireSpeed() { return this->fireSpeed; }
    void setDamage(int damage) { this->damage = damage; }
    int getDamage() { return this->damage; }
    void setRange(int range) { this->range = range; }
    int getRange() { return this->range; }

};


#endif // TILE_H
