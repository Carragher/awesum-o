#ifndef HIGHSCORE_H
#define HIGHSCORE_H
#include <string>


using namespace std;
class highscore
{
    int score;
    string name;

public:
    highscore(int, string);

    string toString();


};

#endif // HIGHSCORE_H
