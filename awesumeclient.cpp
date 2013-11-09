#include "awesumeclient.h"
#include "ui_awesumeclient.h"
#include <QMessageBox>
//thread to handle connectivity
void ConnectThread::run()
{
    socket = new QTcpSocket();
    success = true;
    errorMsg = "Connected";

    if (hostname.size() == 0) {
        success = false;
        errorMsg = "Please specify name of chat server.";
        return;
    }

    socket->connectToHost(hostname, 5000);
    if (!socket->waitForConnected())  {
        success = false;
        errorMsg = "Unable to connect to server";
        return;
    }

    QString data = QString("*USER ") + usr + "\n";
    qDebug() << "Sending " << data;
    socket->write(data.toStdString().c_str());

    // wait for response from server
    while (!socket->canReadLine() && socket->state() == QAbstractSocket::ConnectedState) {
        socket->waitForReadyRead();
    }

    if (socket->state() != QAbstractSocket::ConnectedState) {
        success = false;
        errorMsg = "Server disconnected.";
        socket->deleteLater();
        return;
    }

    data = socket->readLine().trimmed();

    if (data != "+OK") {
        success = false;
        errorMsg = "Username not valid.";
        socket->deleteLater();
        return;
    }

    data = QString("*PASS ") + pwd + "\n";
    qDebug() << "Sending " << data;
    socket->write(data.toStdString().c_str());

    // wait for response from server
    while (!socket->canReadLine() && socket->state() == QAbstractSocket::ConnectedState) {
        socket->waitForReadyRead();
    }

    if (socket->state() != QAbstractSocket::ConnectedState) {
        success = false;
        errorMsg = "Server disconnected.";
        socket->deleteLater();
        return;
    }

    data = socket->readLine().trimmed();
    if (data != "+OK") {
        success = false;
        errorMsg = "Password not valid.";
        socket->deleteLater();
        return;
    }

    socket->moveToThread(QApplication::instance()->thread());
}

AwesumeClient::AwesumeClient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AwesumeClient)
{
    ui->setupUi(this);
}

AwesumeClient::~AwesumeClient()
{
    delete ui;
}
//get user information and pass into thread
void AwesumeClient::on_btnConnect_clicked()
{
    QString hostname = ui->hostname->text();
    QString user = ui->username->text();
    QString password = ui->password->text();

    thread = new ConnectThread(hostname, user, password);
    connect(thread, SIGNAL(finished()), this, SLOT(connectFinished()));
    thread->start();
}
//display chat information
void AwesumeClient::dataReceived() {

    while (socket->canReadLine()) {
        QString str = socket->readLine();
        QString username = "unknown";
        QString msg;

        // get username, text
        int colonPos = str.indexOf(':');
        if (colonPos >= 0) {
            username = str.left(colonPos);
            msg = str.mid(colonPos + 1);
        } else {
            msg = str;
        }

        ui->chatWindow->insertHtml("<b>" + username + "</b>: " + msg + "<br><br>");
    }

}
//handle disconnection from server
void AwesumeClient::serverDisconnected()
{
     ui->btnConnect->setEnabled(true);
     ui->btnSend->setEnabled(false);

     socket->deleteLater();
}
//send user chat input
void AwesumeClient::on_btnSend_clicked()
{
    QString username = ui->username->text();
    QString msg;
    if (username.size() > 0) {
        msg = username + ":" + ui->msgWindow->toPlainText() + "\n";
    } else {
        msg = ui->msgWindow->toPlainText() + "\n";
    }

    ui->msgWindow->document()->setPlainText("");

    socket->write(msg.toStdString().c_str());

    ui->msgWindow->setFocus();
}
//handle connecting to server
void AwesumeClient::connectFinished()
{
    success = thread->getResult();
    QString errorMsg = thread->getMsg();
    if (success == true)
    {
        socket = thread->getSocket();
        connect(socket, SIGNAL(readyRead()), this, SLOT(dataReceived()));
        connect(socket, SIGNAL(disconnected()), this, SLOT(serverDisconnected()));
        QMessageBox::information(this, "Connection", errorMsg);
        ui->btnSend->setEnabled(true);
    }
    else
    {
        QMessageBox::warning(this, "Uh oh", errorMsg);
    }

}
