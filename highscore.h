#ifndef HIGHSCORE_H
#define HIGHSCORE_H
#include <string>


using namespace std;
class highscore
{
public:
    virtual void updateScore(int s) = 0;
};

#endif // HIGHSCORE_H
