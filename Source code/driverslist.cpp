#include "driverslist.h"
#include "ui_driverslist.h"
#include "mainwindow.h"

DriversList::DriversList(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DriversList)
{
    ui->setupUi(this);
    modeldriver = new DriverModel();
    adddriverwin = new Adddriver(this);
    adddriverwin->setWindowTitle("Add driver");
    editdriverwin = new editdriver(this);
    editdriverwin->setWindowTitle("Edit driver");
    ui->tableView->setModel(modeldriver);
    ui->tableView->setColumnHidden(0, true);
    ui->tableView->setColumnWidth(4,120);
    ui->tableView->resizeColumnToContents(0);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    modeldriver->addfromfile();
    emptydrivers();
    connect(adddriverwin, SIGNAL(signaladddriver()),this,SLOT(onButtonAdd()));
    connect(adddriverwin, SIGNAL(signaladddriver()),this,SLOT(emptydrivers()));
    connect(this, SIGNAL(sendDrivers(DriverModel*)),adddriverwin,SLOT(recieveDrivers(DriverModel*)));
    connect(ui->tableView, SIGNAL(doubleClicked(const QModelIndex &)), editdriverwin, SLOT(seteditdriver(const QModelIndex &)));
    connect(ui->tableView, SIGNAL(doubleClicked(const QModelIndex &)), this, SLOT(openeditdriver()));
    connect(editdriverwin,SIGNAL(signaledit()),this,SLOT(onButtonEdit()));
    connect(this, SIGNAL(sendDriversE(DriverModel*)),editdriverwin,SLOT(editdatadriver(DriverModel*)));
    buttondel = true;
}

DriversList::~DriversList()
{
    delete ui;
}

void DriversList::openeditdriver()
{
    editdriverwin->setdatadrivers(modeldriver);
    editdriverwin->setModal(true);
    editdriverwin->exec();
}

void DriversList::on_closeButton_clicked()
{
    close();
}

void DriversList::on_addButton_clicked()
{
    adddriverwin->setModal(true);
    adddriverwin->exec();
}

void DriversList::onButtonAdd()
{
    emit sendDrivers(modeldriver);
}

void DriversList::onButtonEdit()
{
    emit sendDriversE(modeldriver);
}

void DriversList::emptydrivers()
{
    if(modeldriver->drivers.empty())
    {
        ui->delButton->setEnabled(false);
        ui->tableView->setHidden(true);
        ui->label->setHidden(true);
        ui->label_2->setHidden(false);
        ui->label_2->setText(":(\nList of Drivers is empty");
        resize(200,200);
    }
    else
    {
        ui->delButton->setEnabled(true);
        ui->tableView->setHidden(false);
        ui->label->setHidden(false);
        ui->label_2->setHidden(true);
        resize(700,430);
    }
}

void DriversList::on_delButton_clicked()
{
    if(buttondel==true)
    {
        ui->addButton->setEnabled(false);
        ui->tableView->setColumnHidden(0,false);
        buttondel = false;
    }
    else
    {
        modeldriver->del();
        ui->addButton->setEnabled(true);
        ui->tableView->setColumnHidden(0,true);
        buttondel = true;
        emit emptydrivers();
    }
}



