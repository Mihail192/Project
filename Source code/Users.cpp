#include "mainwindow.h"

datauser::datauser(){
    name = fam = och = "Name";
    numphone = "+375000000000";
}

datauser::datauser(string m_name, string m_fam, string m_och, string m_num) {
    name = m_name;
    fam = m_fam;
    och = m_och;
    numphone = m_num;
}

datauser::datauser(const datauser &datauser) {
    fam = datauser.fam;
    name = datauser.name;
    och= datauser.och;
    numphone = datauser.numphone;
}

driver::driver():datauser() {
    car = regnum = "N/N";
    flagdel = false;
}

driver::driver( string m_name, string m_fam, string m_och, string m_num, string m_car, string m_regnum): datauser(m_name,m_fam,m_och,m_num) {
    car = m_car;
    regnum = m_regnum;
}

driver::driver(const driver &driver): datauser(driver){
    car = driver.car;
    regnum = driver.regnum;
}

bool operator==(const driver& left, const driver& right)
{
    return left.name==right.name && left.fam==right.fam && left.och==right.och && left.numphone==right.numphone && left.car==right.car && left.regnum==right.regnum;
}

fstream&operator>>(fstream&f, driver&elem)
{
    getline(f,elem.fam);
    getline(f,elem.name);
    getline(f,elem.och);
    getline(f,elem.numphone);
    getline(f,elem.car);
    getline(f,elem.regnum);
}

fstream&operator<<(fstream&f, driver elem)
{
    f<<elem.fam<<"\n"<<elem.name<<"\n"<<elem.och<<"\n"<<elem.numphone<<"\n"<<elem.car<<"\n"<<elem.regnum<<"\n";
}

tenant::tenant():datauser() {
    company = "N/N";
    numpass = "N/N";
}

tenant::tenant(string m_name, string m_fam, string m_och, string m_num, string m_company, string m_numpass): datauser(m_name, m_fam, m_och, m_num) {
    company = m_company;
    numpass = m_numpass;
}

tenant::tenant(const tenant &tenant): datauser(tenant) {
    company = tenant.company;
    numpass = tenant.numpass;
}

fstream&operator>>(fstream&f, tenant&elem)
{
    getline(f,elem.fam);
    getline(f,elem.name);
    getline(f,elem.och);
    getline(f,elem.numphone);
    getline(f,elem.company);
    getline(f,elem.numpass);
}

fstream&operator<<(fstream&f, tenant elem)
{
    f<<elem.fam<<"\n"<<elem.name<<"\n"<<elem.och<<"\n"<<elem.numphone<<"\n"<<elem.company<<"\n"<<elem.numpass<<"\n";
}
