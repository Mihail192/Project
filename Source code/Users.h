#pragma once
#include <string>
#include <QDate>
#include <fstream>

using namespace std;

class datauser {
    protected:
        string name;
        string fam;
        string och;
        string numphone;
    public:
        datauser();
        datauser(string m_name, string m_fam, string m_och, string m_num);
        datauser(const datauser&datauser);
        string get_fam(){return fam;}
        string get_name(){return name;}
        string get_och(){return och;}
        string get_numph(){return numphone;}
};

class driver : public datauser {
    private:
        bool flagdel;
        string car;
        string regnum;
    public:
        friend class DriverModel;
        friend class editdriver;
        driver();
        driver(string m_name, string m_fam, string m_och, string m_num, string m_car, string m_regnum);
        driver(const driver&driver);
        bool get_flagdel(){return flagdel;}
        string get_car(){return car;}
        string get_regnum(){return regnum;}
        friend bool operator==(const driver& left, const driver& right);
        friend fstream&operator>>(fstream&f, driver&elem);
        friend fstream&operator<<(fstream&f, driver elem);
};

class tenant: public datauser
    {
    private:
        string company;
        string numpass;
    public:
        tenant();
        tenant(string m_name, string m_fam, string m_och, string m_num, string m_company, string m_numpass);
        tenant(const tenant &tenant);
        string get_company(){return company;}
        string get_numpass(){return numpass;}
        friend fstream&operator>>(fstream&f, tenant&elem);
        friend fstream&operator<<(fstream&f, tenant elem);
    };
