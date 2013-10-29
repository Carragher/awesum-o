#ifndef COMMAND_H
#define COMMAND_H

#include <string>
#include <vector>

#include "enemy.h"
#include "tile.h"


using namespace std;

// An abstract command class
class Command {

public:

    // abstract method to carry out this command; returns true on success
    virtual bool execute() = 0;

    // destructor
    virtual ~Command() { }
};

// A command class that creates a WorldObject
class CreateCommand: public Command {
    string type;  // type of object to create
    string image; // image for new object
    int id; // id for the new object

public:
    CreateCommand(string initType, string initImage):
        type(initType), image(initImage) { }

    // creates a WorldObject using data in instance variables
    bool execute();
};

// A command class that moves an object
class MoveCommand: public Command {
    int id;
    int x;
    int y;

public:
    MoveCommand(int initId, int initX, int initY):
        id(initId), x(initX), y(initY) { }

    // moves the object to the new location
    bool execute();
};

// A command class that destroys objects
class DestroyCommand: public Command {
    int id;


public:
    DestroyCommand(int initId):
        id(initId) { }

    // destroys the object with id
    bool execute();

    // destructor
    ~DestroyCommand();
};


#endif // COMMAND_H
