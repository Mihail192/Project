#ifndef DRIVERINFO_H
#define DRIVERINFO_H

#include <QDialog>
#include "Users.h"

namespace Ui {
class DriverInfo;
}

class DriverInfo : public QDialog
{
    Q_OBJECT

public:
    explicit DriverInfo(QWidget *parent = nullptr);
    ~DriverInfo();
    void setdriverinfo(driver);

private slots:
    void on_pushButton_clicked();

private:
    Ui::DriverInfo *ui;
};

#endif // DRIVERINFO_H
