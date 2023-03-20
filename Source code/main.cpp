#include "mainwindow.h"
#include <QScreen>
#include <QApplication>
#include <QStyleFactory>

int storage::s_idgen=1;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    qApp->setStyle(QStyleFactory::create("Fusion"));
    w.setWindowTitle("Storage Manager");
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();
    int x = (screenGeometry.width()-w.width()) / 6;
    int y = (screenGeometry.height()-w.height()) / 6;
    w.move(x, y);
    w.show();
    return a.exec();
}
