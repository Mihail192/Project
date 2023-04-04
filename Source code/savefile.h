#ifndef SAVEFILE_H
#define SAVEFILE_H

#include <QDialog>
#include <string>
#include <QFile>
#include <QFileInfo>
#include <QMessageBox>

using namespace std;

namespace Ui {
class savefile;
}

/**
 * @brief Класс, представляющий окно ввода названия срхраняющего файла
 *
 *  Содержит описание окна ввода имени файла. Этот класс наследует QDialog и представляет диалоговое окно
*/
class savefile : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief savefile Конструктор по умолчанию
     *
     * Создаёт новое диалоговое окно QDialog
     *
     * @param parent Родительский объект
     */
    explicit savefile(QWidget *parent = nullptr);

    /**
     * @brief Деструктор класса
     */
    ~savefile();

signals:
    /**
     * @brief Сигнал, который будет отправлен при нажатии кнопки "Ввод"
     *
     * @param Название файла
     */
    void sendnamefile(string);

private slots:
    /**
     * @brief Слот для обработки события нажатия на кнопку "Ввод"
     */
    void on_pushButton_clicked();

    /**
     * @brief Слот для обработки события нажатия на кнопку "Отмена"
     */
    void on_pushButton_2_clicked();

    /**
     * @brief Слот для обработки события закрытия окна
     */
    void reject();

private:
    Ui::savefile *ui; ///< объект описывающий окно и компоненты окна
};

#endif // SAVEFILE_H
