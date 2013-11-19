#ifndef WORLD_H
#define WORLD_H

#include <string>
#include <vector>

#include "tile.h"
#include "enemy.h"
#include "bullet.h"

using namespace std;

class World {
    vector<Tile*> *tiles;
    vector<Enemy*> *enemies;
    vector<Bullet*> *bullets;
    int score;
    int lives;
    int diff1;
    int diff2;
    int diff3;

public:
    World(){
        tiles = new vector<Tile*>();
        enemies = new vector<Enemy*>();
        bullets = new vector<Bullet*>();
        score = 200;
        lives = 20;
        diff1 = 15;
        diff2 = 10;
        diff3 = 1;
    }

    int getDiff1() {return diff1; }
    int getDiff2() {return diff2;}
    int getDiff3() {return diff3;}

    void setScore(int s) {score +=s; }
    int initScore(int s) { this->score = s; }
    int getScore() { return score;}

    void decLives() {lives--;}
    int setLives(int l) {this->lives = l;}
    int getLives() {return lives;}

    //is the method that adds score when an enemy is killed
    void enemyDeath();

    // allows the user to buy a tower and returns a bool to determine if succeessfull
    bool towerBuy(int);

    // Creates and returns a tile based on the <type>
    Tile *createTile(const string& type);
    Enemy *createEnemy(const string& type);
    Bullet *createBullet(const string &type);

    // adds <obj> to tiles in world
    void addTile(Tile*);
    void addEnemy(Enemy*);
    void addBullet(Bullet*);

    Enemy *getEnemyById(int id);

    // returns tile with <id>, or NULL if none
//    Tile *getById(int id);

    void removeEnemy(int);
    void removeBullet(int);

    // returns the vector of tiles
    vector<Tile*> *getTiles() { return tiles; }
    vector<Enemy*> *getEnemies() { return enemies; }
    vector<Bullet*> *getBullets() {return bullets; }

    // Resets world
    void reset();

    // Destroy objects
    ~World();

    /***** singleton implementation ****/
private:
    // the main instance
    static World instance;

public:
    // returns the instance
    static World& getInstance() {
        return instance;
    }

};

#endif // WORLD_H
