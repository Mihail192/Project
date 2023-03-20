#include "openfile.h"
#include "ui_openfile.h"

openfile::openfile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::openfile)
{
    ui->setupUi(this);
    ui->listWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->listWidget, SIGNAL(customContextMenuRequested(const QPoint &)),
            this, SLOT(ProvideContextMenu(const QPoint &)));
}

openfile::~openfile()
{
    delete ui;
}

void openfile::updatelistfiles()
{
    ui->listWidget->clear();
    QDir files;
    QStringList listf = files.entryList(QStringList() << "*.storage", QDir::Files);
    if(listf.empty())
    {
        ui->listWidget->setHidden(true);
        ui->label->setText(":(\nNo Files");
    }
    else
    {
        ui->listWidget->setHidden(false);
        ui->listWidget->addItems(listf);
        ui->label->setText("Open");
    }
}

void openfile::on_listWidget_itemClicked(QListWidgetItem *item)
{
    QFileInfo check_file(item->text());
    if(check_file.exists())
    {
        emit openfilesignal(item->text().toStdString());
        close();
    }
    else
    {
        QMessageBox::warning(this,"Open failed","File is corrupted or deleted");
        updatelistfiles();
    }
}

void openfile::ProvideContextMenu(const QPoint &pos)
{
    QPoint item = ui->listWidget->mapToGlobal(pos);
    QMenu submenu;
    submenu.addAction("Delete");
    QAction* rightClickItem = submenu.exec(item);
    if (rightClickItem && rightClickItem->text().contains("Delete") )
    {
        QFile file(ui->listWidget->indexAt(pos).data().toString());
        file.remove();
        QListWidgetItem *item = ui->listWidget->takeItem(ui->listWidget->indexAt(pos).row());
        delete item;
        if(ui->listWidget->count()==0)
        {
            ui->listWidget->setHidden(true);
            ui->label->setText(":(\nNo Files");
        }
    }
}

