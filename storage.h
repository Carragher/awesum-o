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
        int waveCreator;
        vector<EnemyGUI*> *engui;
        vector<Entity*> *entities;
        vector<BulletGUI*> *bgui;
        bool isStarted;
        bool end;
        bool FG;
        storage(){
            engui = new vector<EnemyGUI*>();
            entities = new vector<Entity*>();
            bgui = new vector<BulletGUI*>();
            waveCreator = 0;
            isStarted = false;
            FG = true;
            end = false;
        }

public:
    //storage();
    void setFG(bool f) {FG = f;}
    bool getFG() {return FG;}

    void setEnd(bool e) {end = e;  }
    bool getEnd(){return end;}

    void addEngui(EnemyGUI* en) { engui->push_back(en);}
    vector<EnemyGUI*> *getEngui() { return engui; }

    void addEntity(Entity* en) { entities->push_back(en); }
    vector<Entity*> *getEntities() { return entities; }

    void addBgui(BulletGUI* b) {bgui->push_back(b);}
    vector<BulletGUI*> *getBgui() {return bgui;}

    int getWavecreator() {return waveCreator;}
    void incCreator() {waveCreator++;}

    bool getStarted() {return isStarted;}
    void setStarted() {isStarted = true;}


private:
        static storage instance;
public:
        static storage& getInstance()
        {
            return instance;
        }
};

#endif // STORAGE_H
