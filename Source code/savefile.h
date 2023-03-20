#ifndef SAVEFILE_H
#define SAVEFILE_H

#include <QDialog>
#include <string>
#include <QFile>
#include <QFileInfo>
#include <QMessageBox>

using namespace std;

namespace Ui {
class savefile;
}

class savefile : public QDialog
{
    Q_OBJECT

public:
    explicit savefile(QWidget *parent = nullptr);
    ~savefile();

signals:
    void sendnamefile(string);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void reject();

private:
    Ui::savefile *ui;
};

#endif // SAVEFILE_H
