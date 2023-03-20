#ifndef ADDDRIVER_H
#define ADDDRIVER_H

#include <QDialog>
#include <QMessageBox>
#include "drivermodel.h"

namespace Ui {
class Adddriver;
}

class Adddriver : public QDialog
{
    Q_OBJECT

public:
    explicit Adddriver(QWidget *parent = nullptr);
    ~Adddriver();
signals:
    void signaladddriver();

private slots:
    void on_pushButton_clicked();
    void recieveDrivers(DriverModel*);

    void on_adddriverButton_clicked();
    void setCursor(int , int );

    void reject();

private:
    Ui::Adddriver *ui;
};

#endif // ADDDRIVER_H
