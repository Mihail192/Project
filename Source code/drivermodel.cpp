#include "drivermodel.h"

DriverModel::DriverModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

QVariant DriverModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::CheckStateRole && section==0)
    {
        return Qt::Unchecked;
    }
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
    {
        switch (section)
        {
            case 1:
                {return(QVariant(tr("Last Name")));}
            break;
            case 2:
                {return(QVariant(tr("First Name")));}
            break;
            case 3:
                {return(QVariant(tr("Patronymic")));}
            break;
            case 4:
                {return(QVariant(tr("NumberPhone")));}
            break;
            case 5:
                {return(QVariant(tr("Car")));}
            break;
            case 6:
                {return(QVariant(tr("RegNumber")));}
            break;
            default:
                {return(QVariant());}
             break;
        }
    }
    else
        {return(QVariant());}
}

int DriverModel::rowCount(const QModelIndex &parent) const
{
    return drivers.size();
}

int DriverModel::columnCount(const QModelIndex &parent) const
{
    return 7;
}

QVariant DriverModel::data(const QModelIndex &index, int role) const
{
    if (role==Qt::CheckStateRole)
    {
        if (index.column()==0)
        {
            if(drivers[index.row()].flagdel==true)
                return Qt::Checked;
            else
                return Qt::Unchecked;
        }
    }
    if (role==Qt::DisplayRole)
    {
       switch(index.column())
       {
       case 1:
           return QString::fromUtf8(drivers[index.row()].fam.c_str());
       case 2:
           return QString::fromUtf8(drivers[index.row()].name.c_str());
       case 3:
           return QString::fromUtf8(drivers[index.row()].och.c_str());
       case 4:
           return QString::fromUtf8(drivers[index.row()].numphone.c_str());
       case 5:
           return QString::fromUtf8(drivers[index.row()].car.c_str());
       case 6:
           return QString::fromUtf8(drivers[index.row()].regnum.c_str());
       }
    }
    return(QVariant());
}

bool DriverModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.column()==0 && role == Qt::CheckStateRole)
    {
        if(drivers[index.row()].flagdel==false)
        {
            drivers[index.row()].flagdel=true;
            return true;
        }
        else
        {
            drivers[index.row()].flagdel=false;
            return true;
        }
    }
}

Qt::ItemFlags DriverModel::flags(const QModelIndex &index) const
{
    if(index.column()==0)
    {
        return Qt::ItemIsUserCheckable | Qt::ItemIsEnabled;
    }
    return Qt::ItemIsEnabled;
}

void DriverModel::add(string m_fam, string m_name, string m_och, string m_numph, string m_car, string m_regnum)
{
    beginInsertRows(QModelIndex(),drivers.size(),drivers.size());
    drivers.push_back(driver(m_name,m_fam,m_och,m_numph,m_car,m_regnum));
    endInsertRows();
}

void DriverModel::del()
{
    vector<driver>::iterator it;
    int i;
    for(it=drivers.begin(),i=0;i<drivers.size();i++,it++)
    {
        if(drivers[i].get_flagdel()==true)
        {
            beginRemoveRows(QModelIndex(), i,i);
            drivers.erase(it);
            endRemoveRows();
            it--;
            i--;
        }
    }
}

void DriverModel::addfromfile()
{
    fstream f;
    f.open("storagedrivers",ios::in);
    driver temp;
    while(f>>temp)
    {
        beginInsertRows(QModelIndex(),drivers.size(),drivers.size());
        drivers.push_back(temp);
        endInsertRows();
    }
}
