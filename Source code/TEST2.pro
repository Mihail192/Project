QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Users.cpp \
    add.cpp \
    adddriver.cpp \
    driverinfo.cpp \
    drivermodel.cpp \
    driverslist.cpp \
    editdriver.cpp \
    editelem.cpp \
    main.cpp \
    mainwindow.cpp \
    openfile.cpp \
    savefile.cpp \
    storage.cpp \
    storagemodel.cpp

HEADERS += \
    Users.h \
    add.h \
    adddriver.h \
    driverinfo.h \
    drivermodel.h \
    driverslist.h \
    editdriver.h \
    editelem.h \
    mainwindow.h \
    openfile.h \
    savefile.h \
    storage.h \
    storagemodel.h

FORMS += \
    add.ui \
    adddriver.ui \
    driverinfo.ui \
    driverslist.ui \
    editdriver.ui \
    editelem.ui \
    mainwindow.ui \
    openfile.ui \
    savefile.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
