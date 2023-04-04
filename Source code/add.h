#ifndef ADD_H
#define ADD_H

#include <QDialog>
#include <vector>
#include "Users.h"
#include <QMessageBox>

namespace Ui {
class Add;
}
class StorageModel;

/**
 * @brief Класс, представляющий окно добавления товара
 *
 *  Содержит описание окна и функции добавления товара на склад. Этот класс наследует QDialog и представляет диалоговое окно
*/
class Add : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Add Конструктор по умолчанию
     *
     * Создаёт новое диалоговое окно QDialog
     *
     * @param parent Родительский объект
     */
    explicit Add(QWidget *parent = nullptr);
    /**
     * @brief Деструктор класса
     */
    ~Add();
    friend class MainWindow;

signals:
    /**
     * @brief Сигнал, который будет отправлен при нажатии кнопки "Добавить"
     */
    void signaladd();

private slots:
    /**
     * @brief Слот для обработки события нажатия на кнопку "Добавить"
     */
    void on_pushButton_clicked();
    /**
     * @brief Слот для обработки сигнала sendData класса MainWindow
     *
     * Получает данные с строк ввода и вызывает метод добавления товара на склад
     *
     * @param s объект модели склада
     */
    void recieveData(StorageModel *s);

    /**
     * @brief Слот для обработки события нажатия на кнопку "Отмена"
     */
    void on_pushButton_2_clicked();

    /**
     * @brief Слот для обработки события изменения положения checkBoxa статуса товара
     * @param arg1 положение checkBoxa
     */
    void on_checkBox_stateChanged(int arg1);

    /**
     * @brief Слот для обработки сигнала sendDrivers класса MainWindow
     *
     * Добавляет данные о водителях склада в combobox
     *
     * @param Данные о водителях
     */
    void setdriversdata(vector<driver>);

    /**
     * @brief Слот для обработки события изменнения положения курсора в строке
     *
     * @param Старое положение курсора
     * @param Новое положение курсора
     */
    void setCursor(int,int);

    /**
     * @brief Слот для обработки события закрытия окна
     */
    void reject();

private:
    Ui::Add *ui; ///< объект описывающий окно и компоненты окна
    vector<driver> extradrivers; ///< хранит информацию о водителей склада
};

#endif // ADD_H
