#ifndef AWESUMSERVER_H
#define AWESUMSERVER_H

#include <QDialog>
#include <QTcpServer>
namespace Ui {
class AwesumServer;
}

class AwesumServer : public QDialog
{
    Q_OBJECT
    
public:
    explicit AwesumServer(QWidget *parent = 0);
    ~AwesumServer();
    void addToLog(QString msg);

    bool getConnection(){return connection;}
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
};

#endif // AWESUMSERVER_H
