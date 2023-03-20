#include "savefile.h"
#include "ui_savefile.h"

savefile::savefile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::savefile)
{
    ui->setupUi(this);
}

savefile::~savefile()
{
    delete ui;
}

void savefile::on_pushButton_clicked()
{
    QFileInfo check_file(ui->lineEdit->text()+".storage");
    if(check_file.exists())
    {
        QMessageBox::StandardButton reply=QMessageBox::question(this, "Save", "File with that name\nalready exists. Overwrite it?", QMessageBox::Yes | QMessageBox::No);
        if(reply == QMessageBox::Yes)
        {
            emit sendnamefile(ui->lineEdit->text().toStdString()+".storage");
            ui->lineEdit->clear();
            close();
        }
    }
    else
    {
        emit sendnamefile(ui->lineEdit->text().toStdString()+".storage");
        ui->lineEdit->clear();
        close();
    }
}


void savefile::on_pushButton_2_clicked()
{
    ui->lineEdit->clear();
    close();
}

void savefile::reject()
{
    ui->lineEdit->clear();
    QDialog::reject();
}

