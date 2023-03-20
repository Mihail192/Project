#ifndef ADD_H
#define ADD_H

#include <QDialog>
#include <vector>
#include "Users.h"
#include <QMessageBox>

namespace Ui {
class Add;
}
class StorageModel;

class Add : public QDialog
{
    Q_OBJECT

public:
    explicit Add(QWidget *parent = nullptr);
    ~Add();
    friend class MainWindow;

signals:
    void signaladd();

private slots:
    void on_pushButton_clicked();
    void recieveData(StorageModel *s);

    void on_pushButton_2_clicked();

    void on_checkBox_stateChanged(int arg1);
    void setdriversdata(vector<driver>);
    void setCursor(int,int);

    void reject();

private:
    Ui::Add *ui;
    vector<driver> extradrivers;
};

#endif // ADD_H
