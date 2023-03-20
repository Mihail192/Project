#include "editelem.h"
#include "ui_editelem.h"
#include "mainwindow.h"

editelem::editelem(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::editelem)
{
    ui->setupUi(this);
    wininfo = new DriverInfo(this);
    QDate todaydate = QDate::currentDate();
    ui->dateEdit->setDate(todaydate);
    ui->numphEdit->setInputMask("+375000000000");
    setMinimumWidth(400);
    connect(ui->numphEdit,SIGNAL(cursorPositionChanged(int,int)),this,SLOT(setCursor(int,int)));
}

editelem::~editelem()
{
    delete ui;
}

void editelem::setCursor(int oldPos, int newPos)
{
    if(newPos>ui->numphEdit->text().size())
        ui->numphEdit->setCursorPosition(ui->numphEdit->text().size());
    if(newPos<4)
        ui->numphEdit->setCursorPosition(4);
}

void editelem::setdatainline(StorageModel *s, vector<driver> drivers)
{
    extradrivers = drivers;
    current_driver = s->m_data[foredit.row()].whoin;
    ui->comboBox->addItem("<Select driver of Storage>");
    if(s->m_data[foredit.row()].whoin.get_name()!="Name" && s->m_data[foredit.row()].whoin.get_fam()!="Name" && s->m_data[foredit.row()].whoin.get_och()!="Name")
    {
        ui->comboBox->setItemText(0,QString::fromStdString(s->m_data[foredit.row()].whoin.get_fam()+" "+s->m_data[foredit.row()].whoin.get_name()+" "+s->m_data[foredit.row()].whoin.get_och()));
        ui->driverinfoButton->setEnabled(true);
        wininfo->setdriverinfo(current_driver);
        ui->comboBox->addItem("<Select driver of Storage>");
    }
    ui->lineEdit->setText(QString::fromStdString(s->m_data[foredit.row()].s_name));
    ui->lineEdit_2->setText(QString::fromStdString(s->m_data[foredit.row()].s_type));
    ui->lineEdit_3->setText(QString::number(s->m_data[foredit.row()].s_kol));
    if(s->m_data[foredit.row()].status==true)
    {
        ui->checkBox->setCheckState(Qt::Checked);
        ui->dateEdit->setHidden(false);
        ui->comboBox->setHidden(false);
        ui->label_15->setHidden(false);
        ui->label_7->setHidden(false);
        ui->driverinfoButton->setHidden(false);
        //setFixedHeight(560);
        adjustSize();
        vector<driver>::iterator i;
        for(i=extradrivers.begin();i!=extradrivers.end();i++)
        {
            if(s->m_data[foredit.row()].whoin==(*i))
            {
                extradrivers.erase(i);
                i--;
            }
            else
                ui->comboBox->addItem(QString::fromStdString((*i).get_fam()+" "+(*i).get_name()+" "+(*i).get_och()));
        }
    }
    else
    {
        ui->checkBox->setCheckState(Qt::Unchecked);
        ui->dateEdit->setHidden(true);
        ui->comboBox->setHidden(true);
        ui->label_15->setHidden(true);
        ui->label_7->setHidden(true);
        ui->driverinfoButton->setHidden(true);
        //setFixedHeight(480);
        adjustSize();
        for(auto i: extradrivers)
            ui->comboBox->addItem(QString::fromStdString(i.get_fam()+" "+i.get_name()+" "+i.get_och()));
    }
    ui->textEdit->setText(QString::fromStdString(s->m_data[foredit.row()].extrainfo));
    ui->famEdit->setText(QString::fromStdString(s->m_data[foredit.row()].whois.get_fam()));
    ui->nameEdit->setText(QString::fromStdString(s->m_data[foredit.row()].whois.get_name()));
    ui->ochEdit->setText(QString::fromStdString(s->m_data[foredit.row()].whois.get_och()));
    ui->numphEdit->setText(QString::fromStdString(s->m_data[foredit.row()].whois.get_numph()));
    ui->companyEdit->setText(QString::fromStdString(s->m_data[foredit.row()].whois.get_company()));
    ui->numpsEdit->setText(QString::fromStdString(s->m_data[foredit.row()].whois.get_numpass()));
}

void editelem::on_pushButton_2_clicked()
{
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->textEdit->clear();
    ui->dateEdit->clear();
    ui->comboBox->clear();
    ui->textEdit->clear();
    ui->famEdit->clear();
    ui->nameEdit->clear();
    ui->ochEdit->clear();
    ui->numphEdit->clear();
    ui->companyEdit->clear();
    ui->numpsEdit->clear();
    close();
}

void editelem::on_pushButton_clicked()
{
    int kol;
    try {
        kol = stoi(ui->lineEdit_3->text().toStdString());
        if(kol<0)
            throw "error negative number";
    }  catch (const std::invalid_argument&) {
        QMessageBox::warning(this,"Entry error","Wrong entry");
        return;
    }
    catch(const char* exception)
    {
        QMessageBox::warning(this,"Entry error","Wrong entry");
        return;
    }
    try {
        if(ui->numphEdit->text().toStdString().length()<13)
            throw 1;
        if(ui->lineEdit->text().toStdString().empty() || ui->lineEdit_2->text().toStdString().empty() ||
                ui->textEdit->text().toStdString().empty() || ui->nameEdit->text().toStdString().empty() ||
                ui->famEdit->text().toStdString().empty() || ui->ochEdit->text().toStdString().empty() ||
                ui->numphEdit->text().toStdString().empty() || ui->companyEdit->text().toStdString().empty() ||
                ui->numpsEdit->text().toStdString().empty())
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
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->textEdit->clear();
    ui->dateEdit->clear();
    ui->comboBox->clear();
    ui->textEdit->clear();
    ui->famEdit->clear();
    ui->nameEdit->clear();
    ui->ochEdit->clear();
    ui->numphEdit->clear();
    ui->companyEdit->clear();
    ui->numpsEdit->clear();
    close();
}

void editelem::setedit(const QModelIndex &index)
{
    foredit = index;
}

void editelem::editdata(StorageModel *s)
{
    s->m_data[foredit.row()].s_name=ui->lineEdit->text().toStdString();
    s->m_data[foredit.row()].s_type=ui->lineEdit_2->text().toStdString();
    s->m_data[foredit.row()].s_kol=stoi(ui->lineEdit_3->text().toStdString());
    s->m_data[foredit.row()].extrainfo=ui->textEdit->text().toStdString();
    if(ui->checkBox->checkState()==Qt::Checked)
    {
        s->m_data[foredit.row()].status=true;
        s->m_data[foredit.row()].in = ui->dateEdit->date();
        if(ui->comboBox->currentIndex()!=0)
        {
            if(ui->comboBox->itemText(1)=="<Select driver of Storage>")
            {
                if(ui->comboBox->currentIndex()==1)
                    s->m_data[foredit.row()].whoin = driver();
                else
                    s->m_data[foredit.row()].whoin=extradrivers[ui->comboBox->currentIndex()-2];
            }
            else
                s->m_data[foredit.row()].whoin=extradrivers[ui->comboBox->currentIndex()-1];
        }
    }
    else
    {
        s->m_data[foredit.row()].status=false;
        s->m_data[foredit.row()].in.currentDate();
        driver set;
        s->m_data[foredit.row()].whoin = set;
    }
    string prName = ui->nameEdit->text().toStdString();
    string prFam=ui->famEdit->text().toStdString();
    string prOch=ui->ochEdit->text().toStdString();
    string prNumph=ui->numphEdit->text().toStdString();
    string prCompany=ui->companyEdit->text().toStdString();
    string prNumps=ui->numpsEdit->text().toStdString();
    tenant n_whois(prName, prFam, prOch, prNumph, prCompany, prNumps);
    s->m_data[foredit.row()].whois=n_whois;
    extradrivers.clear();
}


void editelem::on_checkBox_stateChanged(int arg1)
{
    if (arg1==0)
    {
        ui->comboBox->setHidden(true);
        ui->label_7->setHidden(true);
        ui->dateEdit->setHidden(true);
        ui->label_15->setHidden(true);
        ui->driverinfoButton->setHidden(true);
        //setFixedHeight(480);
        adjustSize();
    }
    if(arg1==2)
    {
        ui->comboBox->setHidden(false);
        ui->label_7->setHidden(false);
        ui->dateEdit->setHidden(false);
        ui->label_15->setHidden(false);
        ui->driverinfoButton->setHidden(false);
        //setFixedHeight(560);
        adjustSize();
    }
}

void editelem::reject()
{
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->textEdit->clear();
    ui->dateEdit->clear();
    ui->comboBox->clear();
    ui->textEdit->clear();
    ui->famEdit->clear();
    ui->nameEdit->clear();
    ui->ochEdit->clear();
    ui->numphEdit->clear();
    ui->companyEdit->clear();
    ui->numpsEdit->clear();
    QDialog::reject();
}


void editelem::on_comboBox_currentIndexChanged(int index)
{
    if(ui->comboBox->itemText(index)=="<Select driver of Storage>")
        ui->driverinfoButton->setEnabled(false);
    else
    {
        ui->driverinfoButton->setEnabled(true);
        if(ui->comboBox->itemText(0)=="<Select driver of Storage>")
        {
            if(index>0)
                wininfo->setdriverinfo(extradrivers[ui->comboBox->currentIndex()-1]);
        }
        else
        {
            if(ui->comboBox->itemText(1)=="<Select driver of Storage>")
            {
                if(index==0)
                    wininfo->setdriverinfo(current_driver);
                if(index >1)
                    wininfo->setdriverinfo(extradrivers[ui->comboBox->currentIndex()-2]);
            }
        }
    }
}


void editelem::on_driverinfoButton_clicked()
{
    wininfo->setModal(true);
    wininfo->exec();
}

