#ifndef DRIVERINFO_H
#define DRIVERINFO_H

#include <QDialog>
#include "Users.h"

namespace Ui {
class DriverInfo;
}

/**
 * @brief Класс, представляющий окно отображения информации о водителях склада
 *
 *  Содержит описание окна отображения списка водителей склада. Этот класс наследует QDialog и представляет диалоговое окно
*/
class DriverInfo : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief DriverInfo Конструктор по умолчанию
     *
     * Создаёт новое диалоговое окно QDialog
     *
     * @param parent Родительский объект
     */
    explicit DriverInfo(QWidget *parent = nullptr);
    /**
     * @brief Деструктор класса
     */
    ~DriverInfo();
    /**
     * @brief Метод добавление в строки ввода информацию о водителе только для чтения
     */
    void setdriverinfo(driver);

private slots:
    /**
     * @brief Слот для обработки события нажатия на кнопку "Закрыть"
     */
    void on_pushButton_clicked();

private:
    Ui::DriverInfo *ui; ///< объект описывающий окно и компоненты окна
};

#endif // DRIVERINFO_H
