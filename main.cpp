#include "mainwindow.h"
#include "enemy.h"
#include <QApplication>
#include <cassert>
void unitTest()
{
    //Enemy unit tests
    Walker* texas = new Walker(0,0);
    assert(texas->getMoveSpeed() == 10);
    assert(texas->getHp() == 50);
    assert(texas->getX() == 0);
    assert(texas->getY() == 0);
    texas->updatePosition();
    assert(texas->getX() == 10);
    assert(texas->getY() == 10);
    texas->setHp(0);
    texas->deathUpdate();
   // assert(texas == 0);

    Sergeant* bilko = new Sergeant(0,0);
    assert(bilko->getMoveSpeed() == 5);
    assert(bilko->getHp() == 100);
    assert(bilko->getX() == 0);
    assert(bilko->getY() == 0);
    bilko->updatePosition();
    assert(bilko->getX() == 5);
    assert(bilko->getY() == 5);
    bilko->setHp(0);
    bilko->deathUpdate();
   // assert(bilko == NULL);

    YOLO* folo = new YOLO(0,0);
    assert(folo->getMoveSpeed() == 20);
    assert(folo->getHp() == 25);
    assert(folo->getX() == 0);
    assert(folo->getY() == 0);
    folo->updatePosition();
    assert(folo->getX() == 20);
    assert(folo->getY() == 20);
    folo->setHp(0);
    folo->deathUpdate();
  //  assert(folo == NULL);
}
int main(int argc, char *argv[])
{
    vector<string> args(argv, argv + argc);
//    if (args.at(1) == "-test")     {
//        unitTest();
//    }
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
