#include "driverinfo.h"
#include "ui_driverinfo.h"

DriverInfo::DriverInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DriverInfo)
{
    ui->setupUi(this);
    ui->famEdit->setReadOnly(true);
    ui->nameEdit->setReadOnly(true);
    ui->ochEdit->setReadOnly(true);
    ui->numphEdit->setReadOnly(true);
    ui->carEdit->setReadOnly(true);
    ui->regnumEdit->setReadOnly(true);
}

DriverInfo::~DriverInfo()
{
    delete ui;
}

void DriverInfo::setdriverinfo(driver man)
{
    ui->famEdit->setText(QString::fromStdString(man.get_fam()));
    ui->nameEdit->setText(QString::fromStdString(man.get_name()));
    ui->ochEdit->setText(QString::fromStdString(man.get_och()));
    ui->numphEdit->setText(QString::fromStdString(man.get_numph()));
    ui->carEdit->setText(QString::fromStdString(man.get_car()));
    ui->regnumEdit->setText(QString::fromStdString(man.get_regnum()));
}

void DriverInfo::on_pushButton_clicked()
{
    close();
}
