#ifndef EDITDRIVER_H
#define EDITDRIVER_H

#include <QDialog>
#include <QMessageBox>
#include "drivermodel.h"

namespace Ui {
class editdriver;
}

/**
 * @brief Класс, представляющий окно редактирования данных о водителе
 *
 *  Содержит описание окна и функции редактирования данных о водителе. Этот класс наследует QDialog и представляет диалоговое окно
*/
class editdriver : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief editdriver Конструктор по умолчанию
     *
     * Создаёт новое диалоговое окно QDialog
     *
     * @param parent Родительский объект
     */
    explicit editdriver(QWidget *parent = nullptr);

    /**
     * @brief Деструктор класса
     */
    ~editdriver();

    /**
     * @brief Метод добавления в строки ввода информацию о водителе для дальнейшего редактирования
     *
     * @param Объект модели данных водителей
     */
    void setdatadrivers(DriverModel*);

signals:
    /**
     * @brief Сигнал, который будет отправлен при нажатии кнопки "Применить"
     */
    void signaledit();

private slots:
    /**
     * @brief Слот для обработки события нажатия на кнопку "Отмена"
     */
    void on_pushButton_clicked();

    /**
     * @brief Слот для обработки события нажатия на кнопку "Применить"
     */
    void on_adddriverButton_clicked();

    /**
     * @brief Слот для обработки события изменнения положения курсора в строке
     *
     * @param Старое положение курсора
     * @param Новое положение курсора
     */
    void setCursor(int,int);

    /**
     * @brief Слот для обработки сигнала sendDriversE класса DriversList
     *
     * Получает данные со строк ввода для дальнейшей записи в вектор данных водителей
     *
     * @param объект модели данных водителей
     */
    void editdatadriver(DriverModel*);

    /**
     * @brief Слот для обработки сигнала двойного нажатия на элемент в моделе данных
     *
     * Сохраняет в переиенную foredit класса editdriver индекс редактируемого элемента объекта модели данных водителей
     *
     * @param индекс в моделе данных
     */
    void seteditdriver(const QModelIndex &);

    /**
     * @brief Слот для обработки события закрытия окна
     */
    void reject();

private:
    Ui::editdriver *ui; ///< объект описывающий окно и компоненты окна
    QModelIndex foredit; ///< индекс редактируемого водителя
};

#endif // EDITDRIVER_H
