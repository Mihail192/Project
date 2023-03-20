#ifndef MAINWINDOW_H
#define MAINWINDOW_H



#include <QMainWindow>
#include <iostream>
#include <string>
#include <QAbstractListModel>
#include <vector>	
#include <QSortFilterProxyModel>
#include <algorithm>
#include <QDate>
#include <QListWidget>
#include <QCloseEvent>
#include <QProxyStyle>
#include "add.h"
#include "editelem.h"
#include "driverslist.h"
#include "storage.h"
#include "storagemodel.h"
#include "openfile.h"
#include "savefile.h"

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
signals:
    void sendData(StorageModel *s);
    void emptystoragesignal();
    void sendDataE(StorageModel*s);
    void sendDrivers(vector<driver>);

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void onButtonSend();
    void onButtonSend2();
    void emptystorage();
    void on_pushButton_3_clicked();
    void openedit();
    void on_driversButton_clicked();
    void openlistfiles();
    void openfilestorage(string);
    void savefilestorage();
    void savenewfilestorage(string);
    void closeEvent(QCloseEvent *);
    void newstorage();
    void setLightTheme();
    void setDarkTheme();

private:
    Ui::MainWindow *ui;
    StorageModel *modelstorage;
    Add *winadd;
    DriversList *windrivers;
    editelem *winedit;
    openfile *winopen;
    savefile *winsave;
    bool countbuttondel;
    string namefile;
};

#endif // MAINWINDOW_H
