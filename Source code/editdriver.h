#ifndef EDITDRIVER_H
#define EDITDRIVER_H

#include <QDialog>
#include <QMessageBox>
#include "drivermodel.h"

namespace Ui {
class editdriver;
}

class editdriver : public QDialog
{
    Q_OBJECT

public:
    explicit editdriver(QWidget *parent = nullptr);
    ~editdriver();

    void setdatadrivers(DriverModel*);

signals:
    void signaledit();

private slots:
    void on_pushButton_clicked();

    void on_adddriverButton_clicked();

    void setCursor(int,int);

    void editdatadriver(DriverModel*);
    void seteditdriver(const QModelIndex &);
    void reject();

private:
    Ui::editdriver *ui;
    QModelIndex foredit;
};

#endif // EDITDRIVER_H
