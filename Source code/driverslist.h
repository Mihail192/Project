#ifndef DRIVERSLIST_H
#define DRIVERSLIST_H

#include <QDialog>
#include "drivermodel.h"
#include "adddriver.h"
#include "editdriver.h"

namespace Ui {
class DriversList;
}

class DriversList : public QDialog
{
    Q_OBJECT

public:
    friend class MainWindow;
    explicit DriversList(QWidget *parent = nullptr);
    ~DriversList();
signals:
    void sendDrivers(DriverModel *);
    void sendDriversE(DriverModel*);

private slots:
    void on_closeButton_clicked();
    void onButtonAdd();
    void onButtonEdit();
    void on_addButton_clicked();
    void emptydrivers();
    void openeditdriver();

    void on_delButton_clicked();

private:
    Ui::DriversList *ui;
    DriverModel *modeldriver;
    Adddriver *adddriverwin;
    editdriver *editdriverwin;
    bool buttondel;
};

#endif // DRIVERSLIST_H
