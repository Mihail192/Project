#ifndef DRIVERMODEL_H
#define DRIVERMODEL_H

#include <QAbstractListModel>
#include "Users.h"
#include <fstream>

/**
 * @brief Класс модели данных для отображения элементов списка водителей.
 *
 * Этот класс определяет модель данных для отображения элементов списка водителей,
 * которая наследуется от QAbstractListModel.
 */
class DriverModel : public QAbstractListModel
{
    Q_OBJECT

public:
    friend class DriversList;
    friend class MainWindow;
    friend class editdriver;

    /**
     * @brief Конструктор класса.
     *
     * Создает новый объект DriverModel.
     *
     * @param parent Родительский объект.
     */
    explicit DriverModel(QObject *parent = nullptr);

    /**
     * @brief получить данные заголовка модели данных
     * @param section Индекс раздела модели данных
     * @param orientation Ориентация заголовка
     * @param role Роль заголовка
     * @return Данные заголовка для указанной роли, или QVariant(), если данные не найдены
     */
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

    /**
     * @brief Получить количество строк данных.
     *
     * Возвращает количество строк данных.
     *
     * @param parent Родительский элемент.
     * @return Количество строк данных.
     */
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    /**
     * @brief Получить количество столбцов данных.
     *
     * Возвращает количество столбцов данных.
     *
     * @param parent Родительский элемент.
     * @return Количество столбцов данных.
     */
    int columnCount(const QModelIndex &parent) const override;

    /**
     * @brief Получить данные элемента в модели данных.
     *
     * Возвращает данные элемента в модели данных для заданного индекса и роли.
     *
     * @param index Индекс элемента в модели данных.
     * @param role Роль элемента в модели данных.
     * @return Данные элемента в модели данных.
     */
    QVariant data(const QModelIndex &index, int role) const override;

    /**
     * @brief Установить данные для указанного индекса в модели данных.
     *
     * Эта функция устанавливает данные для указанного индекса в модели данных.
     *
     * @param index Индекс элемента данных.
     * @param value Новое значение для элемента данных.
     * @param role Роль элемента данных.
     * @return true, если данные успешно установлены, иначе false.
     */
    bool setData(const QModelIndex &index, const QVariant &value, int role=Qt::EditRole);

    /**
     * @brief Получить флаги элемента данных для указанного индекса.
     *
     * Эта функция возвращает флаги элемента данных для указанного индекса.
     *
     * @param index Индекс элемента данных.
     * @return Флаги элемента данных для указанного индекса.
     */
    Qt::ItemFlags flags(const QModelIndex &index) const;

    /**
     * @brief Метод добавления данных о водителе в модель данных.
     *
     * @param m_fam Фамилия водителя.
     * @param m_name Имя водителя.
     * @param m_och Отчество водителя.
     * @param m_numph Номер телефона водителя.
     * @param m_car Название автомобилия водителя.
     * @param m_regnum Номер автомобилия водителя.
     */
    void add(string,string,string,string,string,string);

    /**
     * @brief Метод удаления данных о водетеле из модели данных.
     */
    void del();

    /**
     * @brief Метод добавления данных о водетеле из файла в модели данных.
     */
    void addfromfile();

private:
    vector<driver> drivers; ///< Вектор данных о водителей
};

#endif // DRIVERMODEL_H
