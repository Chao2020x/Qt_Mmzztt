QT       += core gui network xml xmlpatterns

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++14
QMAKE_CXXFLAGS += -std=c++1y
CONFIG += CONSOLE
TARGET = mmzztt
TEMPLATE = app

CONFIG(debug, debug|release) {
    DESTDIR = $$PWD/bin/debug
    DEFINES += QT_DEPRECATED_WARNINGS
} else {
    DESTDIR = $$PWD/bin/release
    DEFINES += QT_NO_DEBUG_OUTPUT
}
# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.


# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwidget.cpp

HEADERS += \
    mainwidget.h

FORMS += \
    mainwidget.ui

RC_ICONS = ./ui_style/mmzztt.ico

INCLUDEPATH += $$PWD/ui_style
INCLUDEPATH += $$PWD/homePage
INCLUDEPATH += $$PWD/utils
include ($$PWD/ui_style/ui_style.pri)
include ($$PWD/homePage/homePage.pri)
include ($$PWD/utils/utils.pri)


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


#临时文件存放位置
MOC_DIR         = temp/moc  #指定moc命令将含Q_OBJECT的头文件转换成标准.h文件的存放目录
RCC_DIR         = temp/rcc  #指定rcc命令将.qrc文件转换成qrc_*.h文件的存放目录
UI_DIR          = temp/ui   #指定rcc命令将.qrc文件转换成qrc_*.h文件的存放目录
OBJECTS_DIR     = temp/obj  #指定目标文件(obj)的存放目录
