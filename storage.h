#ifndef STORAGE_H
#define STORAGE_H

#include "enemy.h"
#include "tile.h"
#include "enemygui.h"
#include "entity.h"
#include "bulletgui.h"

//This class is meant to hold all GUI objects
using namespace std;

class storage {
private:
        vector<EnemyGUI*> *engui;
        vector<Entity*> *entities;
        vector<BulletGUI*> *bgui;
        storage(){
            engui = new vector<EnemyGUI*>();
            entities = new vector<Entity*>();
            bgui = new vector<BulletGUI*>();
        }

public:
    //storage();

    void addEngui(EnemyGUI* en) { engui->push_back(en);}
    vector<EnemyGUI*> *getEngui() { return engui; }

    void addEntity(Entity* en) { entities->push_back(en); }
    vector<Entity*> *getEntities() { return entities; }

    void addBgui(BulletGUI* b) {bgui->push_back(b);}
    vector<BulletGUI*> *getBgui() {return bgui;}


private:
        static storage instance;
public:
        static storage& getInstance()
        {
            return instance;
        }
};

#endif // STORAGE_H
