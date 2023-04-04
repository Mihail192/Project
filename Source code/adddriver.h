#ifndef ADDDRIVER_H
#define ADDDRIVER_H

#include <QDialog>
#include <QMessageBox>
#include "drivermodel.h"

namespace Ui {
class Adddriver;
}

/**
 * @brief Класс, представляющий окно добавления водителя
 *
 *  Содержит описание окна и функции добавления водителя. Этот класс наследует QDialog и представляет диалоговое окно
*/
class Adddriver : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Adddriver Конструктор по умолчанию
     *
     * Создаёт новое диалоговое окно QDialog
     *
     * @param parent Родительский объект
     */
    explicit Adddriver(QWidget *parent = nullptr);
    /**
     * @brief Деструктор класса
     */
    ~Adddriver();
signals:
    /**
     * @brief Сигнал, который будет отправлен при нажатии кнопки "Добавить"
     */
    void signaladddriver();

private slots:
    /**
     * @brief Слот для обработки события нажатия на кнопку "Отмена"
     */
    void on_pushButton_clicked();

    /**
     * @brief Слот для обработки сигнала sendDrivers класса MainWindow
     *
     * Получает данные с строк ввода и вызывает метод добавления водителя
     *
     * @param объект модели данных о водителе
     */
    void recieveDrivers(DriverModel*);

    /**
     * @brief Слот для обработки события нажатия на кнопку "Добавить"
     */
    void on_adddriverButton_clicked();

    /**
     * @brief Слот для обработки события изменнения положения курсора в строке
     *
     * @param Старое положение курсора
     * @param Новое положение курсора
     */
    void setCursor(int , int );

    /**
     * @brief Слот для обработки события закрытия окна
     */
    void reject();

private:
    Ui::Adddriver *ui; ///< объект описывающий окно и компоненты окна
};

#endif // ADDDRIVER_H
