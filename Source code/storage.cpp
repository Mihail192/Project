#include "storage.h"

storage::storage()
{
    flagdel =false;
    s_id=s_idgen++;
    s_name = "N\\N";
    s_type = "N\\N";
    s_kol = 0;
    status = false;
    extrainfo = "-";
}

storage::storage(string m_name, string m_type, int m_kol,bool m_status, QDate m_in, driver m_whoin, tenant m_whois, string m_extrainfo)
{
    flagdel = false;
    s_id=s_idgen++;
    s_name=m_name;
    s_type=m_type;
    s_kol=m_kol;
    status = m_status;
    in = m_in;
    whoin=m_whoin;
    whois=m_whois;
    extrainfo=m_extrainfo;
}

fstream&operator>>(fstream&f, storage&elem)
{
    elem.flagdel = false;
    f>>elem.s_id;
    getline(f,elem.s_name);
    getline(f,elem.s_name);
    getline(f,elem.s_type);
    f>>elem.s_kol;
    f>>elem.status;
    int day = elem.in.day();
    int month = elem.in.month();
    int year = elem.in.year();
    f>>day;
    f>>month;
    f>>year;
    elem.in.setDate(year,month,day);
    getline(f,elem.extrainfo);
    getline(f,elem.extrainfo);
    f>>elem.whoin;
    f>>elem.whois;
}

fstream&operator<<(fstream&f, storage elem)
{
    f<<elem.s_id<<"\n"<<elem.s_name<<"\n"<<elem.s_type<<"\n"<<elem.s_kol<<"\n"<<elem.status<<"\n";
    int day=elem.in.day();
    int month=elem.in.month();
    int year=elem.in.year();
    f<<day<<"\n"<<month<<"\n"<<year<<"\n"<<elem.extrainfo<<"\n";
    f<<elem.whoin;
    f<<elem.whois;
}
