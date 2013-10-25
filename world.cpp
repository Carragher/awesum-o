#include "world.h"

// work some singleton magic
World World::instance;

void World::reset() {
    for (size_t c = 0; c < tiles.size(); c = c ) {
        delete tiles.at(c);
        tiles.erase(tiles.begin()+c);
    }

    for (size_t d = 0; d < enemies.size(); d = d ) {
        delete enemies.at(d);
        enemies.erase(enemies.begin()+d);
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



// destructor
World::~World() {
    this->reset();
}
