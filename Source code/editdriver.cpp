#include "editdriver.h"
#include "ui_editdriver.h"

editdriver::editdriver(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editdriver)
{
    ui->setupUi(this);
    ui->numberphoneEdit->setInputMask("+375000000000");
    connect(ui->numberphoneEdit,SIGNAL(cursorPositionChanged(int,int)),this,SLOT(setCursor(int,int)));
}

editdriver::~editdriver()
{
    delete ui;
}

void editdriver::setCursor(int oldPos, int newPos)
{
    if(newPos>ui->numberphoneEdit->text().size())
        ui->numberphoneEdit->setCursorPosition(ui->numberphoneEdit->text().size());
    if(newPos<4)
        ui->numberphoneEdit->setCursorPosition(4);
}

void editdriver::seteditdriver(const QModelIndex &index)
{
    foredit = index;
}

void editdriver::setdatadrivers(DriverModel*s)
{
    ui->lastnameEdit->setText(QString::fromStdString(s->drivers[foredit.row()].fam));
    ui->firstnameEdit->setText(QString::fromStdString(s->drivers[foredit.row()].name));
    ui->patronymicEdit->setText(QString::fromStdString(s->drivers[foredit.row()].och));
    ui->numberphoneEdit->setText(QString::fromStdString(s->drivers[foredit.row()].numphone));
    ui->carEdit->setText(QString::fromStdString(s->drivers[foredit.row()].car));
    ui->regcarEdit->setText(QString::fromStdString(s->drivers[foredit.row()].regnum));
}

void editdriver::editdatadriver(DriverModel* s)
{
    s->drivers[foredit.row()].fam=ui->lastnameEdit->text().toStdString();
    s->drivers[foredit.row()].name=ui->firstnameEdit->text().toStdString();
    s->drivers[foredit.row()].och=ui->patronymicEdit->text().toStdString();
    s->drivers[foredit.row()].numphone=ui->numberphoneEdit->text().toStdString();
    s->drivers[foredit.row()].car=ui->carEdit->text().toStdString();
    s->drivers[foredit.row()].regnum=ui->regcarEdit->text().toStdString();
}

void editdriver::on_pushButton_clicked()
{
    ui->lastnameEdit->clear();
    ui->firstnameEdit->clear();
    ui->patronymicEdit->clear();
    ui->numberphoneEdit->clear();
    ui->carEdit->clear();
    ui->regcarEdit->clear();
    close();
}


void editdriver::on_adddriverButton_clicked()
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
    emit signaledit();
    ui->lastnameEdit->clear();
    ui->firstnameEdit->clear();
    ui->patronymicEdit->clear();
    ui->numberphoneEdit->clear();
    ui->carEdit->clear();
    ui->regcarEdit->clear();
    close();
}

void editdriver::reject()
{
    ui->lastnameEdit->clear();
    ui->firstnameEdit->clear();
    ui->patronymicEdit->clear();
    ui->numberphoneEdit->clear();
    ui->carEdit->clear();
    ui->regcarEdit->clear();
    QDialog::reject();
}

