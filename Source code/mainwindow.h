#ifndef MAINWINDOW_H
#define MAINWINDOW_H



#include <QMainWindow>
#include <iostream>
#include <string>
#include <QAbstractListModel>
#include <vector>	
#include <QSortFilterProxyModel>
#include <algorithm>
#include <QDate>
#include <QListWidget>
#include <QCloseEvent>
#include <QProxyStyle>
#include "add.h"
#include "editelem.h"
#include "driverslist.h"
#include "storage.h"
#include "storagemodel.h"
#include "openfile.h"
#include "savefile.h"

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/**
 * @brief Главное окно приложения.
 *
 * Этот класс представляет главное окно приложения.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Конструктор класса.
     *
     * Создает новый экземпляр класса MainWindow.
     *
     * @param parent Родительский объект.
     */
    MainWindow(QWidget *parent = nullptr);
    /**
     * @brief Деструктор класса
     */
    ~MainWindow();
signals:
    /**
     * @brief Сигнал, который будет отправлен при нажатии кнопки "Добавить" в окне добаление товара
     *
     * @param s объкет модели данных склада
     */
    void sendData(StorageModel *s);

    /**
     * @brief Сигнал, который будет отправлен при удалении товара
     */
    void emptystoragesignal();

    /**
     * @brief Сигнал, который будет отправлен при нажатии кнопки "Применить" в окне редактирования товара
     *
     * @param s объкет модели данных склада
     */
    void sendDataE(StorageModel*s);

    /**
     * @brief Сигнал, который будет отправлен при нажатии кнопки "Добавить" в главном окне
     *
     * @param Вектор данных водителей
     */
    void sendDrivers(vector<driver>);

private slots:
    /**
     * @brief Слот для обработки события нажатия на кнопку "Выход"
     */
    void on_pushButton_clicked();

    /**
     * @brief Слот для обработки события нажатия на кнопку "Добавить"
     */
    void on_pushButton_2_clicked();


    /**
     * @brief Слот для обработки сигнала signaladd класса Add
     *
     * Отправляет данные о водителе склада в окно добавления
     */
    void onButtonSend();

    /**
     * @brief Слот для обработки сигнала signaledit класса editelem
     *
     * Проверяет на содержание данных о товарах склада для дальнейшего отображения/скрытия таблицы
     */
    void onButtonSend2();

    /**
     * @brief Слот для обработки сигнала emptystoragesignal класса MainWindow и сигнала signaladd класса Add
     *
     * Проверяет на содержание данных о товарах склада для дальнейшего отображения/скрытия таблицы
     */
    void emptystorage();

    /**
     * @brief Слот для обработки события нажатия на кнопку "Удалить"
     */
    void on_pushButton_3_clicked();

    /**
     * @brief Слот для обработки сигнала двойного нажатия на элемент в моделе данных
     *
     * Открывает окно редактирования товара
     */
    void openedit();

    /**
     * @brief Слот для обработки события нажатия на кнопку "Водители"
     */
    void on_driversButton_clicked();

    /**
     * @brief Слот для обработки события нажатия на панели инструментов Файл->Открыть
     *
     * Открывает окно отображения списка файлов
     */
    void openlistfiles();

    /**
     * @brief Слот для обработки сигнала openfilesignal класса MainWindow
     *
     * Читает данные о товарах из файла
     *
     * @param Название файла
     */
    void openfilestorage(string);

    /**
     * @brief Слот для обработки события нажатия на панели инструментов Файл->Сохранить
     *
     * Сохраняет склад в файл
     */
    void savefilestorage();

    /**
     * @brief Слот для обработки сигнала sendnamefile класса savefile
     *
     * Сохраняет склад в новый файл
     *
     * @param Название файла
     */
    void savenewfilestorage(string);

    /**
     * @brief Слот для обработки события закрытия окна
     */
    void closeEvent(QCloseEvent *);

    /**
     * @brief Слот для обработки события нажатия на панели инструментов Файл->Новый
     *
     * Создаёт пустой склад
     */
    void newstorage();

    /**
     * @brief Слот для обработки события выбора светлой темы
     *
     * Устанавливает светлую тему
     */
    void setLightTheme();

    /**
     * @brief Слот для обработки события выбора тёмной темы
     *
     * Устанавливает тёмную тему
     */
    void setDarkTheme();

private:
    Ui::MainWindow *ui; ///< объект описывающий окно и компоненты окна
    StorageModel *modelstorage; ///< объект модели данных склада
    Add *winadd; ///< объект окна добавления товара
    DriversList *windrivers; ///< объект окна просмотра списка водителей склада
    editelem *winedit; ///< объект окна редактирования товара
    openfile *winopen; ///< объект окна открытия файла
    savefile *winsave; ///< объект окна ввода нового имени файла для сохранения
    bool countbuttondel; ///< флаг, описывающий режим работы нажатия кнопки удаления
    string namefile; ///< название текущего открытого файла
};

#endif // MAINWINDOW_H
