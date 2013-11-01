#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "world.h"
#include "command.h"
#include "tile.h"
#include "enemygui.h"
#include "storage.h"
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);

    ui->btnAddTower->setCheckable(true);
    ui->btnAddTower->setEnabled(false);
    ui->btnStartLevel->setEnabled(false);

    TIMER = new QTimer(this);
}

MainWindow::~MainWindow() {
    delete ui;
    World::getInstance().reset();
//    delete scene;
//    delete enemy;
}

void MainWindow::timerHit() {
    // get a collection of enemies
    vector<Enemy*> toUpdate = World::getInstance().getEnemies();

    // see if there are any enemies
    if (toUpdate.size() > 0) {
        // for each enemy, update it's position
        for (EnemyGUI* curEnemy : storage::getInstance().getEngui()) {
            curEnemy->getEnemyObj()->updatePosition();
            curEnemy->move(curEnemy->getEnemyObj()->getX(), curEnemy->getEnemyObj()->getY());
        }
    }
}

// return the correct coordinates for the specified slot
int MainWindow::getSlotCoord(int slotNum, string coordType) {
    int x = 0;
    int y = 0;

    for (int i = 0; i < slotNum; ++i) {
        if(i == 16 || i == 32 || i == 48 || i == 64 || i == 80 || i == 96 || i == 112 || i == 128 || i == 144) {
            y += 50;
            x = 0;
        } else if (i != 0) {
            x += 50;
        }
    }

    if (coordType == "y") {
        return y;
    } else if (coordType == "x") {
        return x;
    }

    return 0;
}

// initialize the world by loading all the normal tiles and setting up the timers.
void MainWindow::initWorld() {

    TIMER->setInterval(100);
    connect(TIMER, &QTimer::timeout, this, &MainWindow::timerHit);

    int x = 0;
    int y = 0;

    for (int i = 0; i <= 160; ++i) {
        x = getSlotCoord(i, "x");
        y = getSlotCoord(i, "y");

        stringstream forCreate;
        forCreate << to_string(x) << string(" ") << to_string(y) << string(" tile tile green") << endl;

        doCreate(forCreate);

        // start the timer here...like you would add the beginning of a level.
        TIMER->start();

        // enable the buttons
        ui->btnAddTower->setEnabled(true);
        ui->btnStartLevel->setEnabled(true);
    }
}

void MainWindow::loadPath(string pathString) {
    vector<string> lines;

    stringstream paths(pathString);

    string line;
    getline(paths, line);

    while (paths.rdbuf()->in_avail() != 0) {
        lines.push_back(line);
        getline(paths, line);
    }

    lines.push_back(line);

    // load the path(s)
    for(int d = 0; d < lines.size(); ++d) {
        createPath(lines.at(d));
    }
}

void MainWindow::createPath(string cmd) {
    int slot = stoi(cmd);

    int x = 0;
    int y = 0;

    x = getSlotCoord(slot, "x");
    y = getSlotCoord(slot, "y");

    vector<Tile*> tiles = World::getInstance().getTiles();

    for (int j = 0; j < tiles.size(); ++j) {
        Tile* tile = tiles.at(j);

        if(tile->getX() == x && tile->getY() == y) { // replace the thing!
            // get rid of the old tile
            delete tile;
            tiles.erase(tiles.begin()+j);

            stringstream forCreate;
            forCreate << to_string(x) << string(" ") << to_string(y) << string(" tile path SaddleBrown") << endl;
            doCreate(forCreate);
        }
    }
}

void MainWindow::on_btnLoadLevel_clicked() {
    this->initWorld();
    this->loadPath("1\n2\n3\n4\n5\n6\n7\n8\n9\n10\n11\n12\n13\n14\n15\n16\n32\n48\n47\n46\n45\n44\n43\n42\n41\n40\n39\n38\n37\n36\n35\n34\n33\n47\n49\n65\n66\n67\n68\n69\n70\n71\n72\n73\n74\n75\n76\n77\n78\n79\n80\n96\n97\n98\n99\n100\n101\n102\n103\n104\n105\n106\n107\n108\n109\n110\n111\n112\n113\n129\n130\n131\n132\n133\n134\n135\n136\n137\n138\n139\n140\n141\n142\n143\n144\n160");

    ui->btnLoadLevel->setEnabled(false);
}

void MainWindow::on_btnStartLevel_clicked() {
    ui->btnStartLevel->setEnabled(false); // disable the buttons othe user can't start more things!


    // load the enemy's here!!

    stringstream forCreate;
    forCreate << string("0 0 enemy walker blue") << endl;
    doCreate(forCreate);


}

void MainWindow::on_btnAddTower_clicked() {    
    int ifScore = World::getInstance().getScore();
    if (ifScore > 43){
    World::getInstance().towerBuy(43);
    int test = World::getInstance().getScore();
    QString q = QString::number(test);
    ui->scoreLbl->setText(q);
    }
    World::getInstance().towerBuy(10);

}

void MainWindow::createTower(int x, int y) {

    stringstream forCreate;
    forCreate << to_string(x) << string(" ") << to_string(y) << string(" tile tower black") << endl;
    doCreate(forCreate);
}

bool MainWindow::getCanCreateTower() {
    return ui->btnAddTower->isChecked();
}

void MainWindow::doCreate(stringstream& cmd) {
    string type, specific, image;
    int x, y;
    cmd >> type;
    cmd >> specific;
    cmd >> image;
    cmd >> x;
    cmd >> y;

    if (cmd) {

        // create the object in the model
        CreateCommand *createObj = new CreateCommand(specific, image);
        createObj->execute();

        // build the string for the style
        string style("QLabel { background-color : " + image + "; border-style:dotted; border-width:1px; border-color: black; }");
        QString forStyle(style.c_str()); // convert it so the method will accept the variable

        if (type == "tile") {
            Tile *obj = World::getInstance().getTiles().back();

            obj->setX(x);
            obj->setY(y);
            obj->setImage(image);

            // create the GUI component
            Entity *tile = new Entity(this, obj, ui->graphicsView);
            tile->setScaledContents(true);
            tile->setGeometry(obj->getX(), obj->getY(), 50, 50);
            tile->setStyleSheet(forStyle);
            tile->show();

            tile->setMouseTracking(true); // turn mouse tracking on for mouse over stuff

            delete createObj;

        } else if (type == "enemy") {

            Enemy *texas = World::getInstance().getEnemies().back();

            //test display score
            int test = World::getInstance().getScore();
            QString q = QString::number(test);
            World::getInstance().enemyDeath();
            ui->scoreLbl->setText(q);

            // no need to set x or y since they start at 0


            // create the GUI component
            EnemyGUI *ranger = new EnemyGUI(this, texas, ui->graphicsView);
            ranger->setScaledContents(true);
            ranger->setGeometry(texas->getX(), texas->getY(), 50, 50);
            ranger->setStyleSheet(forStyle);
            ranger->show();

            storage::getInstance().addEngui(ranger);

        }
    }
}

void MainWindow::load() {

}
