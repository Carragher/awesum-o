#ifndef HELPFORM_H
#define HELPFORM_H

#include <QWidget>

namespace Ui {
class helpForm;
}

class helpForm : public QWidget
{
    Q_OBJECT
    
public:
    explicit helpForm(QWidget *parent = 0);
    ~helpForm();
    
private:
    Ui::helpForm *ui;
};

#endif // HELPFORM_H
