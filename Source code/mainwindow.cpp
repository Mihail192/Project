#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QStandardItem>
#include <QScreen>
#include <fstream>
#include <QDir>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    modelstorage = new StorageModel();
    winadd = new Add(this);
    winadd->setWindowTitle("Add");
    windrivers = new DriversList(this);
    windrivers->setWindowTitle("List of drivers");
    winedit = new editelem(this);
    winedit->setWindowTitle("Edit");
    winopen = new openfile(this);
    winopen->setWindowTitle("Open");
    winsave = new savefile(this);
    winsave->setWindowTitle("Save");
    ui->tableView->setSortingEnabled(true);
    ui->tableView->setModel(modelstorage);
    ui->tableView->setColumnHidden(0, true);
    ui->tableView->setColumnWidth(4,100);
    ui->tableView->setColumnWidth(6,100);
    ui->tableView->resizeColumnToContents(0);
    ui->tableView->resizeColumnToContents(1);
    ui->tableView->resizeColumnToContents(5);
    ui->tableView->horizontalHeader()->setSectionResizeMode(2,QHeaderView::Stretch);
    ui->tableView->horizontalHeader()->setSectionResizeMode(3,QHeaderView::Stretch);
    emptystorage();
    connect(winadd,SIGNAL(signaladd()),this,SLOT(onButtonSend()));
    connect(winadd,SIGNAL(signaladd()),this,SLOT(emptystorage()));
    connect(this, SIGNAL(sendData(StorageModel*)),winadd,SLOT(recieveData(StorageModel*)));
    connect(this, SIGNAL(emptystoragesignal()),this,SLOT(emptystorage()));
    connect(ui->tableView, SIGNAL(doubleClicked(const QModelIndex &)), winedit, SLOT(setedit(const QModelIndex &)));
    connect(ui->tableView, SIGNAL(doubleClicked(const QModelIndex &)), this, SLOT(openedit()));
    connect(winedit,SIGNAL(signaledit()),this,SLOT(onButtonSend2()));
    connect(this, SIGNAL(sendDataE(StorageModel*)),winedit,SLOT(editdata(StorageModel*)));
    connect(ui->tableView->horizontalHeader(),SIGNAL(sortIndicatorChanged(int, Qt::SortOrder)),modelstorage,SLOT(sortstorage(int, Qt::SortOrder)));
    connect(this,SIGNAL(sendDrivers(vector<driver>)),winadd,SLOT(setdriversdata(vector<driver>)));
    connect(ui->actionOpen,SIGNAL(triggered()),this,SLOT(openlistfiles()));
    connect(winopen,SIGNAL(openfilesignal(string)),this,SLOT(openfilestorage(string)));
    connect(ui->actionSave,SIGNAL(triggered()),this,SLOT(savefilestorage()));
    connect(winsave, SIGNAL(sendnamefile(string)),this,SLOT(savenewfilestorage(string)));
    connect(ui->actionNew,SIGNAL(triggered()),this,SLOT(newstorage()));
    connect(ui->actionLight,SIGNAL(triggered()),this,SLOT(setLightTheme()));
    connect(ui->actionDark,SIGNAL(triggered()),this,SLOT(setDarkTheme()));
    countbuttondel = true;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setLightTheme()
{
    qApp->setPalette(style()->standardPalette());
}

void MainWindow::setDarkTheme()
{
    QPalette darkPalette;
    darkPalette.setColor(QPalette::Window, QColor(53, 53, 53));
    darkPalette.setColor(QPalette::WindowText, Qt::white);
    darkPalette.setColor(QPalette::Base, QColor(25, 25, 25));
    darkPalette.setColor(QPalette::AlternateBase, QColor(53, 53, 53));
    darkPalette.setColor(QPalette::ToolTipBase, Qt::white);
    darkPalette.setColor(QPalette::ToolTipText, Qt::white);
    darkPalette.setColor(QPalette::Text, Qt::white);
    darkPalette.setColor(QPalette::Button, QColor(53, 53, 53));
    darkPalette.setColor(QPalette::ButtonText, Qt::white);
    darkPalette.setColor(QPalette::BrightText, Qt::red);
    darkPalette.setColor(QPalette::Link, QColor(42, 130, 218));
    darkPalette.setColor(QPalette::Highlight, QColor(42, 130, 218));
    darkPalette.setColor(QPalette::HighlightedText, Qt::black);
    qApp->setPalette(darkPalette);
}

void MainWindow::newstorage()
{
    if(!namefile.empty() || !modelstorage->m_data.empty())
    {
        QMessageBox::StandardButton reply=QMessageBox::question(this, "New", "Do you want to save file?", QMessageBox::Yes | QMessageBox::No |QMessageBox::Cancel);
        if(reply == QMessageBox::Yes)
            savefilestorage();
        if(reply == QMessageBox::Cancel)
            return;
    }
    if(countbuttondel==false)
    {
        ui->pushButton_2->setEnabled(true);
        ui->tableView->setColumnHidden(0, true);
        countbuttondel=true;
    }
    modelstorage->m_data.clear();
    modelstorage->beginRemoveRows(QModelIndex(),0,modelstorage->rowCount(QModelIndex()));
    modelstorage->endRemoveRows();
    namefile.clear();
    emptystorage();
}

void MainWindow::closeEvent (QCloseEvent *event)
{
    fstream fdw;
    fdw.open("storagedrivers",ios::out);
    for(auto data: windrivers->modeldriver->drivers)
        fdw<<data;
    fdw.close();
    if(!namefile.empty() || !modelstorage->m_data.empty())
    {
        QMessageBox::StandardButton reply=QMessageBox::question(this, "Exit", "Do you want to save file?", QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
        if(reply == QMessageBox::Yes)
        {
            savefilestorage();
            event->accept();
        }
        else
        {
            if(reply == QMessageBox::No)
                event->accept();
            else
                event->ignore();
        }
    }
    else
    {
        event->accept();
    }
}

void MainWindow::savenewfilestorage(string namef)
{
    namefile = namef;
}

void MainWindow::savefilestorage()
{
    if(namefile.empty())
    {
        winsave->setModal(true);
        winsave->exec();
    }
    fstream fw;
    fw.open(namefile,ios::out);
    for(auto data:modelstorage->m_data)
        fw<<data;
    storage s_temp;
    fw<<s_temp;
    fw.close();
    emptystorage();
}

void MainWindow::openfilestorage(string nfile)
{
    if(!namefile.empty() || !modelstorage->m_data.empty())
    {
        QMessageBox::StandardButton reply=QMessageBox::question(this, "Open", "Do you want to save file?", QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
        if(reply == QMessageBox::Yes)
            savefilestorage();
        if(reply == QMessageBox::Cancel)
            return;
    }
    if(countbuttondel==false)
    {
        ui->pushButton_2->setEnabled(true);
        ui->tableView->setColumnHidden(0, true);
        countbuttondel=true;
    }
    namefile = nfile;
    modelstorage->addfromfile(namefile);
    emptystorage();
}

void MainWindow::openlistfiles()
{
    winopen->updatelistfiles();
    winopen->setModal(true);
    winopen->exec();
}

void MainWindow::onButtonSend()
{
    emit sendData(modelstorage);
}

void MainWindow::onButtonSend2()
{
    emit sendDataE(modelstorage);
}

void MainWindow::openedit()
{
    winedit->setdatainline(modelstorage, windrivers->modeldriver->drivers);
    winedit->setModal(true);
    winedit->adjustSize();
    winedit->exec();
}

void MainWindow::emptystorage()
{
    int x = width();
    int y=height();
    if(modelstorage->m_data.empty())
    {
        if (windowState()!=Qt::WindowMaximized && !(ui->tableView->isHidden()))
            resize(x/2,y/2.643);
        ui->tableView->setHidden(true);
        ui->pushButton_3->setEnabled(false);
        ui->label->setText(":(\nStorage " +QString::fromStdString(namefile).replace(".storage","") +" is empty");
    }
    else
    {
        if (windowState()!=Qt::WindowMaximized && ui->tableView->isHidden())
            resize(x*2,y*2.643);
        ui->tableView->setHidden(false);
        ui->pushButton_3->setEnabled(true);
        ui->label->setText("Storage "+QString::fromStdString(namefile).replace(".storage",""));
    }
}

void MainWindow::on_pushButton_clicked()
{
    close();
}

void MainWindow::on_pushButton_2_clicked()
{
    emit sendDrivers(windrivers->modeldriver->drivers);
    winadd->setModal(true);
    winadd->adjustSize();
    winadd->exec();
    winadd->close();
}

void MainWindow::on_pushButton_3_clicked()
{
    if(countbuttondel==true)
    {
        ui->pushButton_2->setEnabled(false);
        ui->tableView->setColumnHidden(0, false);
        countbuttondel=false;
    }
    else
    {
        modelstorage->del();
        ui->pushButton_2->setEnabled(true);
        ui->tableView->setColumnHidden(0, true);
        countbuttondel=true;
        emit emptystoragesignal();
    }
}

void MainWindow::on_driversButton_clicked()
{
    windrivers->setModal(true);
    windrivers->exec();
    windrivers->close();
}

