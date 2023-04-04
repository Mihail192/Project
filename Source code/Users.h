#pragma once
#include <string>
#include <QDate>
#include <fstream>

using namespace std;

/**
 * @brief Класс, представляющий информацию о человеке.
 *
 * Этот класс хранит информацию о человеке.
 */
class datauser {
    protected:
        string name; ///< Имя.
        string fam; ///< Фамилия.
        string och; ///< Отчество.
        string numphone; ///< Номер телефона.
    public:
        /**
         * @brief Конструктор класса по умолчанию.
         */
        datauser();

        /**
         * @brief Конструктор класса.
         * @param m_name Имя.
         * @param m_fam Фамилия.
         * @param m_och Отчество.
         * @param m_num Номер телефона.
         */
        datauser(string m_name, string m_fam, string m_och, string m_num);

        /**
         * @brief Конструктор класса.
         * @param datauser информация о человеке
         */
        datauser(const datauser&datauser);

        /**
         * @brief Метод получения фамилии.
         * @return Фамилия.
         */
        string get_fam(){return fam;}

        /**
         * @brief Метод получения имени.
         * @return Имя.
         */
        string get_name(){return name;}

        /**
         * @brief Метод получения отчества.
         * @return Отчества.
         */
        string get_och(){return och;}

        /**
         * @brief Метод получения номера телефона.
         * @return Номер телефона.
         */
        string get_numph(){return numphone;}
};

/**
 * @brief Класс, представляющий водителя.
 *
 * Этот класс хранит информацию о водителе.
 */
class driver : public datauser {
    private:
        bool flagdel; ///< Флаг, использующий для удаления из списка водителей(true – для удаления, false – не удаляется)
        string car; ///< Название автомобиля
        string regnum; ///< Автомобильный номер
    public:
        friend class DriverModel;
        friend class editdriver;

        /**
         * @brief Конструктор класса по умолчанию.
         */
        driver();

        /**
         * @brief Конструктор класса.
         *
         * @param m_name Имя водителя.
         * @param m_fam Фамилия водителя.
         * @param m_och Отчества водителя.
         * @param m_num Номер телефона водителя.
         * @param m_car Название автомобиля.
         * @param m_regnum Номер автомобиля.
         */
        driver(string m_name, string m_fam, string m_och, string m_num, string m_car, string m_regnum);

        /**
         * @brief Конструктор класса.
         *
         * @param driver Информация о водителе.
         */
        driver(const driver&driver);

        /**
         * @brief Метод получения флага удаления.
         * @return Флаг удаления.
         */
        bool get_flagdel(){return flagdel;}

        /**
         * @brief Метод получения названия автомобиля.
         * @return Названия автомобиля.
         */
        string get_car(){return car;}

        /**
         * @brief Метод получения номера автомобиля.
         * @return Номер автомобиля.
         */
        string get_regnum(){return regnum;}

        /**
         * @brief Сравнение информации водителей
         * @param Первый водитель
         * @param Второй водитель
         * @return если информация совпадает - true, иначе false.
         */
        friend bool operator==(const driver& left, const driver& right);

        /**
         * @brief Чтение из файла
         * @param f файл
         * @param elem водитель куда запишется информация
         */
        friend fstream&operator>>(fstream&f, driver&elem);

        /**
         * @brief Запись в файл
         * @param f файл
         * @param elem записываемый водитель
         */
        friend fstream&operator<<(fstream&f, driver elem);
};

/**
 * @brief Класс, представляющий поставщика товара.
 *
 * Этот класс хранит информацию о поставщике товара.
 */
class tenant: public datauser
    {
    private:
        string company; ///> Название компании поставщика.
        string numpass; ///> Номер паспорта поставщика.
    public:
        /**
         * @brief Конструктор класса по умолчанию.
         */
        tenant();

        /**
         * @brief Конструктор класса.
         *
         * @param m_name Имя поставщика.
         * @param m_fam Фамилия поставщика.
         * @param m_och Отчества поставщика.
         * @param m_num Номер телефона поставщика.
         * @param m_company Название компании поставщика.
         * @param m_numpass Номер паспорта поставщика.
         */
        tenant(string m_name, string m_fam, string m_och, string m_num, string m_company, string m_numpass);

        /**
         * @brief Конструктор класса.
         * @param tenant Информация о поставщике товара.
         */
        tenant(const tenant &tenant);

        /**
         * @brief Метод получения названия компании поставщика.
         * @return Название компании поставщика.
         */
        string get_company(){return company;}

        /**
         * @brief Метод получения номера паспорта поставщика.
         * @return Номер паспорта поставщика.
         */
        string get_numpass(){return numpass;}

        /**
         * @brief Чтение из файла
         * @param f файл
         * @param elem поставщик куда запишется информация
         */
        friend fstream&operator>>(fstream&f, tenant&elem);

        /**
         * @brief Запись в файл
         * @param f файл
         * @param elem записываемый поставщик
         */
        friend fstream&operator<<(fstream&f, tenant elem);
    };
