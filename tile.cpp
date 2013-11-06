#include "tile.h"
#include "world.h"
#include <cmath>

int Tile::nextId = 0;

// returns a double with a distance value from <compreTo> to the tracker
double towerTile::getDistance(Enemy* compareTo) {
    int xd, yd;

    xd = getX()-compareTo->getX();
    yd = getY()-compareTo->getY();

    return sqrt(xd*xd + yd*yd);
}

void towerTile::launchMaybe() {
    vector<Enemy*> *enemies = World::getInstance().getEnemies();
    Enemy* closest;
    double shortestDistance; // holds the shortest distance for comparison
    double curDistance;
    bool firstVariable = true; // to tell if this is the first run
    bool noEnemies = true;

    // figure out which object is closest to the current object
    for (unsigned int t = 0; t < enemies->size(); ++t) {
        // perform the math to go toward the closest

        curDistance = getDistance(enemies->at(t));

        // see if hte enemy is in range
        if (curDistance <= range) {
            noEnemies = false;

            if (firstVariable) { // if this is the first variable, store it since it has nothing to compare to
                closest = enemies->at(t);
                shortestDistance = curDistance;
                firstVariable = false;
            }

            if (curDistance < shortestDistance) { // if the current object is closer that the current closest object, update the current closest
                shortestDistance = curDistance;
                closest = enemies->at(t);
            }
        }
    }

    // set the new coordinates to that they are closer to the closest wanderer
    if (!noEnemies) {
//        launchBullet(closest);
        newTarget = closest;
    }

}
