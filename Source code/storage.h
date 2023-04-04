
#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <QDate>
#include "Users.h"

using namespace std;

/**
 * @brief Класс, представляющий товар.
 *
 * Этот класс хранит информацию о товаре.
 */
class storage
{
private:
    bool flagdel; ///< флаг, использующий для удаления из списка (true – для удаления, false – не удаляется)
    int s_id; ///< уникальный идентификатор
    static int s_idgen; ///< для генерации значения для поля s_id
    string s_name; ///< наименование товара
    string s_type; ///< тип товара
    int s_kol; ///< количество товара
    bool status; ///< статус товара (true – на складе, false – нет на складе)
    QDate in; ///< дата привоза товара на склад
    driver whoin; ///< водитель, к-рый доставил товар на склад
    tenant whois; ///< поставщик товара
    string extrainfo; ///< дополнительная информация о товаре
public:
    friend class StorageModel;
    friend class editelem;
    /**
     * @brief Конструктор класса по умолчанию.
     */
    storage();

    /**
     * @brief Конструктор класса.
     *
     * @param m_name Название товара.
     * @param m_type Тип товара.
     * @param m_kol Количество товара.
     * @param m_status Статус товара(на складе/не на складе).
     * @param m_in Дата завоза на склад.
     * @param m_whoin Водитель ввозивший товар.
     * @param m_whois Собственник товара.
     * @param m_extrainfo Дополнительная информация о товаре.
     */
    storage(string m_name, string m_type, int m_kol,bool m_status, QDate m_in, driver m_whoin, tenant m_whois, string m_extrainfo);

    /**
     * @brief Деструктор класса.
     */
    ~storage(){}

    /**
     * @brief Метод получения названия товара.
     * @return Название товара.
     */
    string get_s_name(){return s_name;}

    /**
     * @brief Метод получения типа товара.
     * @return Тип товара.
     */
    string get_s_type(){return s_type;}

    /**
     * @brief Метод получения количества товара.
     * @return Количество товара.
     */
    int get_s_kol(){return s_kol;}

    /**
     * @brief Метод получения идентификатора товара.
     * @return Идентификатор товара.
     */
    int get_s_id(){return s_id;}

    /**
     * @brief Метод получения флага удаления товара.
     * @return Флаг удаления товара.
     */
    bool get_flagdel(){return flagdel;}

    /**
     * @brief Метод присвоения флага удаления товару.
     */
    void set_flagdel(bool setfl){flagdel=setfl;}

    /**
     * @brief Метод присвоения идентификатора товара.
     */
    void set_idgen(int nid){s_idgen=nid;}

    /**
     * @brief Чтение из файла
     * @param f файл
     * @param elem элемент склада куда запишется информация
     */
    friend fstream&operator>>(fstream&f, storage&elem);

    /**
     * @brief Запись в файл
     * @param f файл
     * @param elem записываемый элемент склада
     */
    friend fstream&operator<<(fstream&f, storage elem);
};

