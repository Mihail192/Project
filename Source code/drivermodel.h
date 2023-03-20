#ifndef DRIVERMODEL_H
#define DRIVERMODEL_H

#include <QAbstractListModel>
#include "Users.h"
#include <fstream>

class DriverModel : public QAbstractListModel
{
    Q_OBJECT

public:
    friend class DriversList;
    friend class MainWindow;
    friend class editdriver;

    explicit DriverModel(QObject *parent = nullptr);

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent) const override;

    QVariant data(const QModelIndex &index, int role) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role=Qt::EditRole);
    Qt::ItemFlags flags(const QModelIndex &index) const;

    void add(string,string,string,string,string,string);
    void del();
    void addfromfile();

private:
    vector<driver> drivers;
};

#endif // DRIVERMODEL_H
