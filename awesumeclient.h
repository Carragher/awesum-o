#ifndef AWESUMECLIENT_H
#define AWESUMECLIENT_H

#include <QDialog>

namespace Ui {
class AwesumeClient;
}

class AwesumeClient : public QDialog
{
    Q_OBJECT
    
public:
    explicit AwesumeClient(QWidget *parent = 0);
    ~AwesumeClient();
    
private:
    Ui::AwesumeClient *ui;
};

#endif // AWESUMECLIENT_H
