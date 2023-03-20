#ifndef EDITELEM_H
#define EDITELEM_H

#include <QDialog>
#include <QModelIndex>
#include "Users.h"
#include "driverinfo.h"

namespace Ui {
class editelem;
}
class StorageModel;
class editelem : public QDialog
{
    Q_OBJECT

public:
    explicit editelem(QWidget *parent = nullptr);
    ~editelem();

    void setdatainline(StorageModel *,vector<driver> );

signals:
    void signaledit();

private slots:
    void on_pushButton_2_clicked();
    void setedit(const QModelIndex &);
    void on_pushButton_clicked();
    void editdata(StorageModel *);
    void on_checkBox_stateChanged(int arg1);
    void reject();

    void on_comboBox_currentIndexChanged(int index);

    void on_driverinfoButton_clicked();

    void setCursor(int, int);

private:
    Ui::editelem *ui;
    QModelIndex foredit;
    vector<driver> extradrivers;
    driver current_driver;
    DriverInfo *wininfo;
};

#endif // EDITELEM_H
