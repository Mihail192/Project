
#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <QDate>
#include "Users.h"

using namespace std;

class storage
{
private:
    bool flagdel;
    int s_id;
    static int s_idgen;
    string s_name;
    string s_type;
    int s_kol;
    bool status;
    QDate in;
    driver whoin;
    tenant whois;
    string extrainfo;
public:
    friend class StorageModel;
    friend class editelem;
    storage();
    storage(string m_name, string m_type, int m_kol,bool m_status, QDate m_in, driver m_whoin, tenant m_whois, string m_extrainfo);
    ~storage(){}
    string get_s_name(){return s_name;}
    string get_s_type(){return s_type;}
    int get_s_kol(){return s_kol;}
    int get_s_id(){return s_id;}
    bool get_flagdel(){return flagdel;}
    void set_flagdel(bool setfl){flagdel=setfl;}
    void set_idgen(int nid){s_idgen=nid;}
    friend fstream&operator>>(fstream&f, storage&elem);
    friend fstream&operator<<(fstream&f, storage elem);
};

