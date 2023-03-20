#ifndef OPENFILE_H
#define OPENFILE_H

#include <QDialog>
#include <QDir>
#include <QListWidget>
#include <string>
#include <QMenu>
#include <QMessageBox>

using namespace std;

namespace Ui {
class openfile;
}

class openfile : public QDialog
{
    Q_OBJECT

public:
    explicit openfile(QWidget *parent = nullptr);
    ~openfile();
    void updatelistfiles();

signals:
    void openfilesignal(string);

private slots:
    void on_listWidget_itemClicked(QListWidgetItem *item);
    void ProvideContextMenu(const QPoint &);

private:
    Ui::openfile *ui;
};

#endif // OPENFILE_H
