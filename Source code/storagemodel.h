#ifndef STORAGEMODEL_H
#define STORAGEMODEL_H
#include <QAbstractListModel>
#include <string>
#include <fstream>
#include "storage.h"

using namespace std;

class StorageModel : public QAbstractListModel
{
    Q_OBJECT

public:
    enum Roles {
        ColorRole = Qt::UserRole + 1,
        TextRole
    };
    friend class MainWindow;
    friend class editelem;

    int rowCount(const QModelIndex &) const;
    int columnCount(const QModelIndex &) const;
    QVariant headerData(int, Qt::Orientation, int) const;
    bool setData(const QModelIndex &, const QVariant &, int role=Qt::EditRole);
    QVariant data( const QModelIndex &, int) const;
    Qt::ItemFlags flags(const QModelIndex &i) const;

    void add(string, string, int, string, QDate, bool, driver, tenant);
    void del();
    void addfromfile(string);

public slots:
    void sortstorage(int, Qt::SortOrder);

private:
    vector<storage> m_data;
};

#endif // STORAGEMODEL_H
