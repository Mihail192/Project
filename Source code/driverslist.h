#ifndef DRIVERSLIST_H
#define DRIVERSLIST_H

#include <QDialog>
#include "drivermodel.h"
#include "adddriver.h"
#include "editdriver.h"

namespace Ui {
class DriversList;
}

/**
 * @brief Класс, представляющий окно вывода информации о водителях
 *
 *  Содержит описание окна отображения списка водителей склада. Этот класс наследует QDialog и представляет диалоговое окно
*/
class DriversList : public QDialog
{
    Q_OBJECT

public:
    friend class MainWindow;
    /**
     * @brief DriversList Конструктор по умолчанию
     *
     * Создаёт новое диалоговое окно QDialog
     *
     * @param parent Родительский объект
     */
    explicit DriversList(QWidget *parent = nullptr);
    /**
     * @brief Деструктор класса
     */
    ~DriversList();
signals:
    /**
     * @brief Сигнал, который будет отправлен при нажатии кнопки "Добавить" в окне добавления водителя
     *
     * @param Модель данных водителей
     */
    void sendDrivers(DriverModel *);
    /**
     * @brief Сигнал, который будет отправлен при нажатии кнопки "Применить" в окне редактировании данных водителя
     *
     * @param Модель данных водителей
     */
    void sendDriversE(DriverModel*);

private slots:
    /**
     * @brief Слот для обработки события нажатия на кнопку "Закрыть"
     */
    void on_closeButton_clicked();

    /**
     * @brief Слот для обработки сигнала signaladddriver класса Adddriver
     *
     * Отправляет данные о водителе склада в окно добавления
     */
    void onButtonAdd();

    /**
     * @brief Слот для обработки сигнала signaledit класса Editdriver
     *
     * Отправляет данные о водителе склада в окно редактирования
     */
    void onButtonEdit();

    /**
     * @brief Слот для обработки события нажатия на кнопку "Добавить"
     */
    void on_addButton_clicked();

    /**
     * @brief Слот для обработки сигнала signaladddriver класса Adddriver
     *
     * Проверяет на содержание данных о водителях склада для дальнейшего отображения/скрытия таблицы
     */
    void emptydrivers();

    /**
     * @brief Слот для обработки сигнала двойного нажатия на элемент в моделе данных
     *
     * Открывает окно редактирования данных о водителе
     */
    void openeditdriver();

    /**
     * @brief Слот для обработки события нажатия на кнопку "Удалить"
     */
    void on_delButton_clicked();

private:
    Ui::DriversList *ui; ///< объект описывающий окно и компоненты окна
    DriverModel *modeldriver; ///< объект модели данных отображения списка водителей
    Adddriver *adddriverwin; ///< объект окна добавления водителя
    editdriver *editdriverwin; ///< объект окна редактирования водителя
    bool buttondel; ///< флаг, описывающий режим работы нажатия кнопки удаления
};

#endif // DRIVERSLIST_H
