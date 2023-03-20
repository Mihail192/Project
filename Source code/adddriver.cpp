#include "adddriver.h"
#include "ui_adddriver.h"
#include <string>

using namespace std;

Adddriver::Adddriver(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Adddriver)
{
    ui->setupUi(this);
    ui->numberphoneEdit->setInputMask("+375000000000");
    connect(ui->numberphoneEdit,SIGNAL(cursorPositionChanged(int,int)),this,SLOT(setCursor(int,int)));
}

Adddriver::~Adddriver()
{
    delete ui;
}

void Adddriver::setCursor(int oldPos, int newPos)
{
    if(newPos>ui->numberphoneEdit->text().size())
        ui->numberphoneEdit->setCursorPosition(ui->numberphoneEdit->text().size());
    if(newPos<4)
        ui->numberphoneEdit->setCursorPosition(4);
}

void Adddriver::on_pushButton_clicked()
{
    ui->lastnameEdit->clear();
    ui->firstnameEdit->clear();
    ui->patronymicEdit->clear();
    ui->numberphoneEdit->clear();
    ui->carEdit->clear();
    ui->regcarEdit->clear();
    close();
}

void Adddriver::recieveDrivers(DriverModel* list)
{
    string fam = ui->lastnameEdit->text().toStdString();
    string name = ui->firstnameEdit->text().toStdString();
    string och = ui->patronymicEdit->text().toStdString();
    string numph = ui->numberphoneEdit->text().toStdString();
    string car = ui->carEdit->text().toStdString();
    string regnum = ui->regcarEdit->text().toStdString();
    list->add(fam,name,och,numph,car,regnum);
}

void Adddriver::on_adddriverButton_clicked()
{
    try {
        if(ui->numberphoneEdit->text().toStdString().length()<13)
            throw 1;
        if(ui->lastnameEdit->text().toStdString().empty() || ui->firstnameEdit->text().toStdString().empty() ||
                ui->patronymicEdit->text().toStdString().empty() || ui->numberphoneEdit->text().toStdString().empty() ||
                ui->carEdit->text().toStdString().empty() || ui->regcarEdit->text().toStdString().empty())
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
    emit signaladddriver();
    ui->lastnameEdit->clear();
    ui->firstnameEdit->clear();
    ui->patronymicEdit->clear();
    ui->numberphoneEdit->clear();
    ui->carEdit->clear();
    ui->regcarEdit->clear();
    close();
}

void Adddriver::reject()
{
    ui->lastnameEdit->clear();
    ui->firstnameEdit->clear();
    ui->patronymicEdit->clear();
    ui->numberphoneEdit->clear();
    ui->carEdit->clear();
    ui->regcarEdit->clear();
    QDialog::reject();
}

