#-------------------------------------------------
#
# 软件样式相关
#
#-------------------------------------------------
INCLUDEPATH += $$PWD/navbutton

include ($$PWD/navbutton/navbutton.pri)

SOURCES += \
        $$PWD/navlabel.cpp \
        $$PWD/panelwidget.cpp \
        $$PWD/sliderbar.cpp \
        $$PWD/uistyle.cpp

HEADERS += \
        $$PWD/Global_Style.h \
        $$PWD/navlabel.h \
        $$PWD/panelwidget.h \
        $$PWD/sliderbar.h \
        $$PWD/uistyle.h

RESOURCES += \
    $$PWD/stylesheet.qrc
