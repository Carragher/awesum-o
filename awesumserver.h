#ifndef AWESUMSERVER_H
#define AWESUMSERVER_H

#include <QDialog>
#include <QTcpServer>
#include <QTimer>
#include "world.h"
namespace Ui {
class AwesumServer;
}

class AwesumServer : public QDialog
{
    Q_OBJECT
    QTimer* SCORE;
struct player
{
    World* world;
    QString usr;
    int score;
    player(QString user, World* w):
        usr(user), world(w){}
    void updateScore() {score = world->getScore();}
};

public:
    explicit AwesumServer(QWidget *parent = 0);
    ~AwesumServer();
    vector<player*> players;
    void addToLog(QString msg);
    bool getConnection(){return connection;}
    void timerHit();
    void CreatePlayer(QString);
private slots:
    void clientConnected();
    void dataReceived();
    void clientDisconnected();

    void on_btnDisconnect_clicked();

private:
    Ui::AwesumServer *ui;
    QTcpServer server;
    int usrCount;
    bool connection;
    /*int score;
    QString usr;*/
};

#endif // AWESUMSERVER_H
