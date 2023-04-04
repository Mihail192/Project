#ifndef OPENFILE_H
#define OPENFILE_H

#include <QDialog>
#include <QDir>
#include <QListWidget>
#include <string>
#include <QMenu>
#include <QMessageBox>

using namespace std;

namespace Ui {
class openfile;
}

/**
 * @brief Класс, представляющий окно отображения файлов
 *
 *  Содержит описание окна отображения списка файлов для открытия. Этот класс наследует QDialog и представляет диалоговое окно
*/
class openfile : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief openfile Конструктор по умолчанию
     *
     * Создаёт новое диалоговое окно QDialog
     *
     * @param parent Родительский объект
     */
    explicit openfile(QWidget *parent = nullptr);

    /**
     * @brief Деструктор класса
     */
    ~openfile();

    /**
     * @brief Метод обновления списка файлов
     */
    void updatelistfiles();

signals:
    /**
     * @brief Сигнал, который будет отправлен при нажатии на название файла
     *
     * @param Название файла
     */
    void openfilesignal(string);

private slots:
    /**
     * @brief Слот для обработки сигнала нажатия на элемент списка
     *
     * Вызывается при клике на элемент списка файлов для дальнейшего его открытия
     *
     * @param item элемент списка
     */
    void on_listWidget_itemClicked(QListWidgetItem *item);

    /**
     * @brief Слот для обработки сигнала нажатия правой кнопкой мыши по элементу списка
     *
     * @param координаты нажатия
     */
    void ProvideContextMenu(const QPoint &);

private:
    Ui::openfile *ui; ///< объект описывающий окно и компоненты окна
};

#endif // OPENFILE_H
