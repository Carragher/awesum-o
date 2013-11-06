#ifndef Tile_H
#define Tile_H

#include <fstream>
#include <string>
#include "enemy.h"

class Tile {
    int id;
    int x;
    int y;
    int width;
    int height;
    bool placable;
    std::string image;

    static int nextId; // not sure if this is the right way to do this....

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

    //set nextId to 0
    static void resetNextId() {
        nextId = 0;
    }

    // setters
    void setId(int id) { this->id = id; }    
    void setX(int x) { this->x = x; }    
    void setY(int y) { this->y = y; }    
    void setWidth(int width) { this->width = width; }    
    void setHeight(int height) { this->height = height; }    
    void setPlacable(bool placable) { this->placable = placable; }    
    void setImage(std::string image) { this->image = image; }    

    // setters
    int getId() { return this->id; }
    int getX() { return this->x; }
    int getY() { return this->y; }
    int getWidth() { return this->width; }
    int getHeight() { return this->height; }
    bool getPlacable() { return this->placable; }
    std::string getImage() { return this->image; }

    // save the object to a file
    virtual void save(std::ofstream& saveFile) { saveFile << std::to_string(x) << " " << std::to_string(y) << " " << std::string(image) << " tile"; }

    virtual void update() { }
};

class normalTile : public Tile {
public:
    void update() { }

    void save(std::ofstream& saveFile) {
        Tile::save(saveFile);
        saveFile << " tile";
    }

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

    void update() { }

    void save(std::ofstream& saveFile) {
        Tile::save(saveFile);
        saveFile << " path";
    }

};

class towerTile : public Tile {
    int health;
    int fireSpeed;
    int damage;
    int range;
    Enemy* newTarget;

public:
    towerTile(): Tile() {
        newTarget = NULL;
        range = 150;
    }

    towerTile(int newX, int newY, int newWidth, int newHeight, bool newPlacable):
        Tile(newX, newY, newWidth, newHeight, newPlacable) { newTarget = NULL; }

    void deathUpdate();// this method will destroy a tower when it dies

    void setHealth(int health) { this->health = health; }
    int getHealth() { return this->health; }
    void setFireSpeed(int fireSpeed) { this->fireSpeed = fireSpeed; }
    int getFireSpeed() { return this->fireSpeed; }
    void setDamage(int damage) { this->damage = damage; }
    int getDamage() { return this->damage; }
    void setRange(int range) { this->range = range; }
    int getRange() { return this->range; }

    Enemy* getNewTarget() { return newTarget; }
    void resetNewTarget() { newTarget= NULL; } // make it null so next time we can see if we need to launch a bullet

    void update() { }
    void launchMaybe();

    void save(std::ofstream& saveFile) {
        Tile::save(saveFile);
        saveFile << " tower";
    }

    double getDistance(Enemy* compareTo);

    void launchBullet(Enemy* target);
};


#endif // Tile_H
