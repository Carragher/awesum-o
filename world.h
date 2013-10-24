#ifndef WORLD_H
#define WORLD_H

#include <string>
#include <vector>

#include "tile.h"
#include "enemy.h"

using namespace std;

class World {
    vector<tile*> tiles;
    vector<enemy*> enemys;

public:
    World() { }

    // Creates and returns a tile based on the <type>
    tile *createObject(const string& type);

    // adds <obj> to tiles in world
    void add(tile*);

    // returns tile with <id>, or NULL if none
    tile *getById(int id);

    // returns the vector of tiles
    vector<tile*>& getTiles() { return tiles; }

    // Removes object with <id> from objects and returns it, or returns NULL if not found
    tile *destroy(int id);

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
