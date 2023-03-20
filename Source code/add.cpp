#include "add.h"
#include "ui_add.h"
#include "mainwindow.h"

Add::Add(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Add)
{
    ui->setupUi(this);
    //setFixedHeight(460);
    setMinimumWidth(400);
    adjustSize();
    ui->drivercomboBox->setHidden(true);
    ui->label_6->setHidden(true);
    ui->dateEdit->setHidden(true);
    ui->label_7->setHidden(true);
    QDate todaydate = QDate::currentDate();
    ui->dateEdit->setDate(todaydate);
    ui->numphEdit->setInputMask("+375000000000");
    connect(ui->numphEdit,SIGNAL(cursorPositionChanged(int,int)),this,SLOT(setCursor(int,int)));
}

Add::~Add()
{
    delete ui;
}

void Add::setCursor(int oldPos, int newPos)
{
    if(newPos>ui->numphEdit->text().size())
        ui->numphEdit->setCursorPosition(ui->numphEdit->text().size());
    if(newPos<4)
        ui->numphEdit->setCursorPosition(4);
}

void Add::setdriversdata(vector<driver> drivers)
{
    extradrivers = drivers;
    ui->drivercomboBox->addItem("<Select driver of Storage>");
    for(auto i: drivers)
        ui->drivercomboBox->addItem(QString::fromStdString(i.get_fam()+" "+i.get_name()+" "+i.get_och()));
}

void Add::recieveData(StorageModel *s)
{
    string name = ui->nameEdit->text().toStdString();
    string type = ui->typeEdit->text().toStdString();
    int kol;
    try {
        kol = stoi(ui->countEdit->text().toStdString());
        if(kol<0)
            throw "error negative number";
    }  catch (const std::invalid_argument&) {
        QMessageBox::warning(this,"Entry error","Wrong entry");
        return;
    }
    catch(const std::out_of_range)
    {
        QMessageBox::warning(this,"Entry error","Sorry, But out of range.\nYou can only enter a 9 digit number!");
        return;
    }
    catch(const char* exception)
    {
        QMessageBox::warning(this,"Entry error","Wrong entry");
        return;
    }
    string extrainfo = ui->extrainfoEdit->text().toStdString();
    QDate datein = ui->dateEdit->date();
    string prName = ui->nametEdit->text().toStdString();
    string prFam=ui->famEdit->text().toStdString();
    string prOch=ui->ochEdit->text().toStdString();
    string prNumph=ui->numphEdit->text().toStdString();
    string prCompany=ui->companyEdit->text().toStdString();
    string prNumps=ui->numpsEdit->text().toStdString();
    try {
        if(prNumph.length()<13)
            throw 1;
        if(name.empty() || type.empty() || extrainfo.empty() || prName.empty() || prFam.empty() || prOch.empty() || prNumph.empty() || prCompany.empty() || prNumps.empty())
        {
            throw "Empty fields";
        }
    }  catch (const char* exception) {
        QMessageBox::warning(this,"Entry error","There is empty field");
        return;
    }
    catch(int a)
    {
        QMessageBox::warning(this,"Entry error","Wrong input number phone");
        return;
    }
    bool status;
    if(ui->checkBox->checkState()==Qt::Checked)
        status = true;
    else
        status =false;
    driver whoin;
    if(status == true && ui->drivercomboBox->currentIndex()!=0)
        whoin = extradrivers[ui->drivercomboBox->currentIndex()-1];
    tenant whois(prName, prFam, prOch, prNumph, prCompany, prNumps);
    s->add(name,type,kol,extrainfo,datein,status,whoin,whois);
    ui->nameEdit->clear();
    ui->typeEdit->clear();
    ui->countEdit->clear();
    ui->extrainfoEdit->clear();
    ui->dateEdit->clear();
    ui->checkBox->setCheckState(Qt::Unchecked);
    ui->drivercomboBox->clear();
    ui->famEdit->clear();
    ui->nametEdit->clear();
    ui->ochEdit->clear();
    ui->numphEdit->clear();
    ui->companyEdit->clear();
    ui->numpsEdit->clear();
    close();
}


void Add::on_pushButton_clicked()
{
    emit signaladd();
}


void Add::on_pushButton_2_clicked()
{
    ui->nameEdit->clear();
    ui->typeEdit->clear();
    ui->countEdit->clear();
    ui->extrainfoEdit->clear();
    ui->dateEdit->clear();
    ui->checkBox->setCheckState(Qt::Unchecked);
    ui->drivercomboBox->clear();
    ui->famEdit->clear();
    ui->nametEdit->clear();
    ui->ochEdit->clear();
    ui->numphEdit->clear();
    ui->companyEdit->clear();
    ui->numpsEdit->clear();
    close();
}


void Add::on_checkBox_stateChanged(int arg1)
{
    if (arg1==0)
    {
        ui->drivercomboBox->setHidden(true);
        ui->label_6->setHidden(true);
        ui->dateEdit->setHidden(true);
        ui->label_7->setHidden(true);
        //setFixedHeight(460);
        adjustSize();
    }
    if(arg1==2)
    {
        ui->drivercomboBox->setHidden(false);
        ui->label_6->setHidden(false);
        ui->dateEdit->setHidden(false);
        ui->label_7->setHidden(false);
        //setFixedHeight(525);
        adjustSize();
    }
}

void Add::reject()
{
    ui->nameEdit->clear();
    ui->typeEdit->clear();
    ui->countEdit->clear();
    ui->extrainfoEdit->clear();
    ui->dateEdit->clear();
    ui->checkBox->setCheckState(Qt::Unchecked);
    ui->drivercomboBox->clear();
    ui->famEdit->clear();
    ui->nametEdit->clear();
    ui->ochEdit->clear();
    ui->numphEdit->clear();
    ui->companyEdit->clear();
    ui->numpsEdit->clear();
    QDialog::reject();
}

