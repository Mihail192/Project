#ifndef EDITELEM_H
#define EDITELEM_H

#include <QDialog>
#include <QModelIndex>
#include "Users.h"
#include "driverinfo.h"

namespace Ui {
class editelem;
}
class StorageModel;

/**
 * @brief Класс, представляющий окно редактирования данных о товаре.
 *
 *  Содержит описание окна и функции редактирования данных о товаре. Этот класс наследует QDialog и представляет диалоговое окно.
*/
class editelem : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief editelem Конструктор по умолчанию
     *
     * Создаёт новое диалоговое окно QDialog
     *
     * @param parent Родительский объект
     */
    explicit editelem(QWidget *parent = nullptr);

    /**
     * @brief Деструктор класса
     */
    ~editelem();

    /**
     * @brief Метод добавление в строки ввода информацию о товаре для дальнейшего редактирования
     *
     * @param Объект модели данных склада
     * @param Вектор данных водителей
     */
    void setdatainline(StorageModel *,vector<driver> );

signals:
    /**
     * @brief Сигнал, который будет отправлен при нажатии кнопки "Применить"
     */
    void signaledit();

private slots:
    /**
     * @brief Слот для обработки события нажатия на кнопку "Отмена"
     */
    void on_pushButton_2_clicked();

    /**
     * @brief Слот для обработки сигнала двойного нажатия на элемент в моделе данных
     *
     * Сохраняет в переиенную foredit класса editelem индекс редактируемого элемента объекта модели данных склада
     *
     * @param индекс в моделе данных
     */
    void setedit(const QModelIndex &);

    /**
     * @brief Слот для обработки события нажатия на кнопку "Применить"
     */
    void on_pushButton_clicked();

    /**
     * @brief Слот для обработки сигнала sendDataE класса MainWindow
     *
     * Получает данные со строк ввода для дальнейшей записи в вектор данных склада
     *
     * @param объект модели данных склада
     */
    void editdata(StorageModel *);

    /**
     * @brief Слот для обработки события изменения положения checkBoxa статуса товара
     *
     * @param arg1 положение checkBoxa
     */
    void on_checkBox_stateChanged(int arg1);

    /**
     * @brief Слот для обработки события закрытия окна
     */
    void reject();

    /**
     * @brief Слот для обработки события выбранного элемента в comboBox
     *
     * @param index индекс текущего выбранного элемента
     */
    void on_comboBox_currentIndexChanged(int index);

    /**
     * @brief Слот для обработки события нажатия на кнопку "Информация о водителе"
     */
    void on_driverinfoButton_clicked();

    /**
     * @brief Слот для обработки события изменнения положения курсора в строке
     *
     * @param Старое положение курсора
     * @param Новое положение курсора
     */
    void setCursor(int, int);

private:
    Ui::editelem *ui; ///< объект описывающий окно и компоненты окна
    QModelIndex foredit; ///< индекс редактируемого товара
    vector<driver> extradrivers; ///< вектор данных водителей склада
    driver current_driver; ///< данные водителя, к-рый содержится в объекте товара
    DriverInfo *wininfo; ///< объект окна отображаюшего информацию о водителе
};

#endif // EDITELEM_H
