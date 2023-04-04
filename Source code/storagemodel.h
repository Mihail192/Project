#ifndef STORAGEMODEL_H
#define STORAGEMODEL_H
#include <QAbstractListModel>
#include <string>
#include <fstream>
#include "storage.h"

using namespace std;

/**
 * @brief Класс модели данных для отображения элементов списка товаров.
 *
 * Этот класс определяет модель данных для отображения элементов списка товаров,
 * которая наследуется от QAbstractListModel.
 */
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

    /**
     * @brief Получить количество строк данных.
     *
     * Возвращает количество строк данных.
     *
     * @param parent Родительский элемент.
     * @return Количество строк данных.
     */
    int rowCount(const QModelIndex &) const;

    /**
     * @brief Получить количество столбцов данных.
     *
     * Возвращает количество столбцов данных.
     *
     * @param parent Родительский элемент.
     * @return Количество столбцов данных.
     */
    int columnCount(const QModelIndex &) const;

    /**
     * @brief получить данные заголовка модели данных
     * @param section Индекс раздела модели данных
     * @param orientation Ориентация заголовка
     * @param role Роль заголовка
     * @return Данные заголовка для указанной роли, или QVariant(), если данные не найдены
     */
    QVariant headerData(int, Qt::Orientation, int) const;

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
    bool setData(const QModelIndex &, const QVariant &, int role=Qt::EditRole);

    /**
     * @brief Получить данные элемента в модели данных.
     *
     * Возвращает данные элемента в модели данных для заданного индекса и роли.
     *
     * @param index Индекс элемента в модели данных.
     * @param role Роль элемента в модели данных.
     * @return Данные элемента в модели данных.
     */
    QVariant data( const QModelIndex &, int) const;

    /**
     * @brief Получить флаги элемента данных для указанного индекса.
     *
     * Эта функция возвращает флаги элемента данных для указанного индекса.
     *
     * @param index Индекс элемента данных.
     * @return Флаги элемента данных для указанного индекса.
     */
    Qt::ItemFlags flags(const QModelIndex &i) const;

    /**
     * @brief Метод добавления данных о товаре в модель данных.
     *
     * @param name Название товара.
     * @param type Тип товара.
     * @param kol Количество товара.
     * @param extrainfo Дополнительная информация о товаре.
     * @param date Дата привоза товара.
     * @param status Статус товара.
     * @param whoin Водитель.
     * @param whois Собственник товара.
     */
    void add(string, string, int, string, QDate, bool, driver, tenant);

    /**
     * @brief Метод удаления данных о товаре из модели данных.
     */
    void del();

    /**
     * @brief Метод добавления данных о товаре из файла в модели данных.
     *
     * @param Имя файла.
     */
    void addfromfile(string);

public slots:
    /**
     * @brief Слот для обработки события сортировки списка.
     *
     * @param Номер столбца, по которому сортировать.
     * @param Порядок сортировки.
     */
    void sortstorage(int, Qt::SortOrder);

private:
    vector<storage> m_data; ///< Вектор данных склада.
};

#endif // STORAGEMODEL_H
