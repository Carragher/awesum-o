#include "storage.h"

storage storage::instance;

void storage::reset() {
    // delete all the entities
    for (size_t d = 0; d < entities->size(); d = d ) {
        delete entities->at(d);
        entities->erase(entities->begin()+d);
    }

    // delete all the enemies
    for (size_t e = 0; e < engui->size(); e = e ) {
        delete engui->at(e);
        engui->erase(engui->begin()+e);
    }

    // delete all the bullets
    for (size_t f = 0; f < bgui->size(); f = f ) {
        delete bgui->at(f);
        bgui->erase(bgui->begin()+f);
    }

}
