#include "world.h"

// work some singleton magic
World World::instance;

//Adds enemy to enemy vector
void World::addEnemy(Enemy* enemy) {
    enemies->push_back(enemy);
}

void World::removeEnemy(int id) {
    for(unsigned int i = 0; i < enemies->size(); i++ ){
        Enemy *enm = enemies->at(i);
        if (enm->getId()== id) {
            enemies->erase(enemies->begin()+i);
            delete enm;
        }

    }
}

//Adds tile to tile vector
void World::addTile(Tile* tile) {
    tiles->push_back(tile);
}

void World::addBullet(Bullet* b) {
    bullets->push_back(b);
}

void World::reset() {
    for (size_t c = 0; c < tiles->size(); c = c ) {
        Tile *tile = tiles->at(c);
//        delete tiles.at(c);
        tiles->erase(tiles->begin()+c);
        delete tile;
    }

    for (size_t d = 0; d < enemies->size(); d = d ) {
        delete enemies->at(d);
        enemies->erase(enemies->begin()+d);
    }

    Tile::resetNextId();
    Enemy::resetNextId();
}

void World::enemyDeath() {score += 25;}

bool World::towerBuy(int amount) {
    if (amount <= score){
        score  -= amount;
        return true;
    }
    return false;

}

Tile *World::createTile(const string &type) {
    if (type.find("tile") == 0)
        return new normalTile;
    else if (type.find("path") == 0)
        return new pathTile;
    else if (type.find("tower") == 0)
        return new towerTile;
    else
        return NULL;
}


Enemy *World::createEnemy(const string &type) {
    if (type.find("walker") == 0)
        return new Walker;
    else if (type.find("sergeant") == 0)
        return new Sergeant;
    else if (type.find("yolo") == 0)
        return new YOLO;
    else
        return NULL;
}

Bullet *World::createBullet(const string &type) {
    if (type.find("bullet") == 0){
        return new Bullet;
    } else {
        return NULL;
    }


}

// destructor
World::~World() {
    this->reset();
}
