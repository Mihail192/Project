#include "storagemodel.h"

void StorageModel::add(string name, string type, int kol,string extrainfo,QDate date,bool status,driver whoin,tenant whois)
{
    beginInsertRows(QModelIndex(),m_data.size(),m_data.size());
    m_data.push_back(storage(name,type,kol,status, date,whoin,whois,extrainfo));
    endInsertRows();
}

void StorageModel::del()
{
    vector<storage>::iterator it;
    int i;
    for(it=m_data.begin(),i=0;i<m_data.size();i++,it++)
    {
        if(m_data[i].get_flagdel()==true)
        {
            beginRemoveRows(QModelIndex(), i,i);
            m_data.erase(it);
            endRemoveRows();
            it--;
            i--;
        }
    }
}

void StorageModel::addfromfile(string filename)
{
    m_data.clear();
    beginRemoveRows(QModelIndex(),0,rowCount(QModelIndex()));
    endRemoveRows();
    fstream f;
    f.open(filename,ios::in);
    storage temp;
    while(f>>temp)
    {
        if (temp.get_s_name()=="N\\N" && temp.get_s_type()=="N\\N")
        {
            temp.set_idgen(temp.get_s_id());
            break;
        }
        beginInsertRows(QModelIndex(),m_data.size(),m_data.size());
        m_data.push_back(temp);
        endInsertRows();
    }
}

void StorageModel::sortstorage(int column, Qt::SortOrder order)
{
    beginResetModel();
    if(order == Qt::AscendingOrder)
    {
        if(column==0)
            std::sort(m_data.begin(),m_data.end(),[](storage box1,storage box2){return box1.flagdel<box2.flagdel;});
        if(column==1)
            std::sort(m_data.begin(),m_data.end(),[](storage box1,storage box2){return box1.s_name<box2.s_name;});
        if(column==2)
            std::sort(m_data.begin(),m_data.end(),[](storage box1,storage box2){return box1.s_type<box2.s_type;});
        if(column==3)
            std::sort(m_data.begin(),m_data.end(),[](storage box1,storage box2){return box1.s_kol<box2.s_kol;});
        if(column==4)
            std::sort(m_data.begin(),m_data.end(),[](storage box1,storage box2){return box1.extrainfo<box2.extrainfo;});
        endResetModel();
        return;
    }
    if(order == Qt::DescendingOrder)
    {
        if(column==0)
            std::sort(m_data.begin(),m_data.end(),[](storage box1,storage box2){return box1.flagdel>box2.flagdel;});
        if(column==1)
            std::sort(m_data.begin(),m_data.end(),[](storage box1,storage box2){return box1.s_name>box2.s_name;});
        if(column==2)
            std::sort(m_data.begin(),m_data.end(),[](storage box1,storage box2){return box1.s_type>box2.s_type;});
        if(column==3)
            std::sort(m_data.begin(),m_data.end(),[](storage box1,storage box2){return box1.s_kol>box2.s_kol;});
        if(column==4)
            std::sort(m_data.begin(),m_data.end(),[](storage box1,storage box2){return box1.extrainfo>box2.extrainfo;});
        endResetModel();
        return;
    }
}

int StorageModel::rowCount(const QModelIndex &parent) const
{
    return m_data.size();
}

int StorageModel::columnCount(const QModelIndex &parent) const
{
    return 7;
}

QVariant StorageModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::CheckStateRole && (section==0 || section==5))
    {
        return Qt::Unchecked;
    }
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
    {
        switch (section)
        {
            case 1:
                {return(QVariant(tr("ID")));}
            break;
            case 2:
                {return(QVariant(tr("Name")));}
            break;
            case 3:
                {return(QVariant(tr("Type")));}
            break;
            case 4:
                {return(QVariant(tr("Size")));}
            break;
            case 5:
                {return(QVariant(tr("Status")));}
            break;
            case 6:
                {return(QVariant(tr("Data in")));}
            break;
            default:
                {return(QVariant());}
             break;
        }
    }
    else
        {return(QVariant());}
}

bool StorageModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.column()==0 && role == Qt::CheckStateRole)
    {
        if(m_data[index.row()].flagdel==false)
        {
            m_data[index.row()].flagdel=true;
            return true;
        }
        else
        {
            m_data[index.row()].flagdel=false;
            return true;
        }
    }
}

QVariant StorageModel::data( const QModelIndex &index, int role) const
{
    if (role==Qt::CheckStateRole)
    {
        if (index.column()==0)
        {
            if(m_data[index.row()].flagdel==true)
                return Qt::Checked;
            else
                return Qt::Unchecked;
        }
        if (index.column()==5)
        {
            if(m_data[index.row()].status==true)
                return Qt::Checked;
            else
                return Qt::Unchecked;
        }
    }
    if (role==Qt::TextAlignmentRole && index.column()==1)
        return Qt::AlignCenter;
    if (role==Qt::DisplayRole)
    {
       switch(index.column())
       {
       case 1:
           return QString("%1").arg(m_data[index.row()].s_id);
       case 2:
           return QString::fromUtf8(m_data[index.row()].s_name.c_str());
       case 3:
           return QString::fromUtf8(m_data[index.row()].s_type.c_str());
       case 4:
           return QString("%1").arg(m_data[index.row()].s_kol);
       case 6:
           if(m_data[index.row()].status==true)
                return m_data[index.row()].in;
       }
    }
    return(QVariant());
}

Qt::ItemFlags StorageModel::flags(const QModelIndex &index) const
{
    if(index.column()==0)
    {
        return Qt::ItemIsUserCheckable | Qt::ItemIsEnabled |Qt::ItemIsSelectable;
    }
    return Qt::ItemIsEnabled;
}


