#include <iostream>
#include "command.h"
#include "world.h"

// creates an object using data in instance variables and returns true or false based on success
bool CreateCommand::execute() {


    if(type == "tile" || type == "path" || type == "tower") {
        Tile *obj = World::getInstance().createTile(type);

        if (obj != NULL) {
            World::getInstance().addTile(obj);

            id = obj->getId();

            cout << "\t-> created id " << to_string(id) << endl;

            return true;
        } else {
            cout << "\t** create failed: unknown type " << type << endl;
            return false;
        }

    } else if(type == "walker" || type == "sergeant" || type == "yolo") {
        Enemy *obj = World::getInstance().createEnemy(type);

        if (obj != NULL) {
            World::getInstance().addEnemy(obj);

            id = obj->getId();

            cout << "\t-> created id " << to_string(id) << endl;

            return true;
        } else {
            cout << "\t** create failed: unknown type " << type << endl;
            return false;
        }
    }

    return false;
}
