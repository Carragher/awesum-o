#include "world.h"

// work some singleton magic
World World::instance;


// destructor
World::~World() {
    for (size_t c = 0; c < tiles.size(); c++ ) {
        delete tiles.at(c);
    }
}
