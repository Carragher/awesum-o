#include "highscore.h"
#include <string>

using namespace std;

highscore::highscore(int initScore, string initName)
{
    score = initScore;
    name = initName;
}

string highscore::toString(){
    string returner;
    returner = name;

    returner = returner + ": " + to_string(score);
    return returner;



}
