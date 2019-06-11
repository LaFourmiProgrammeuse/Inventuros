CONFIG += console
QT += widgets
QT += xml
QT += sql

TEMPLATE = app
TARGET = ./Inventuros

LIBS += -L$MYSQL_CONCPP_DIR/lib64 -lmysqlcppconn
INCLUDEPATH += $MYSQL_CPPCONN_DIR/include

SOURCES += \
    main.cpp \
    controller.cpp \
    loginpage.cpp \
    mainmenupage.cpp \
    mysqlcontroller.cpp \
    passforgottenpage.cpp \
    registerpage.cpp \
    roundedrectwidget.cpp \
    xmlcontroller.cpp \
    interface.cpp \
    user.cpp

HEADERS += \
    controller.h \
    loginpage.h \
    mainmenupage.h \
    mysqlcontroller.h \
    passforgottenpage.h \
    registerpage.h \
    roundedrectwidget.h \
    xmlcontroller.h \
    interface.h \
    user.h

FORMS += \
    loginpage.ui \
    mainmenupage.ui \
    passforgottenpage.ui \
    registerpage.ui \
    interface.ui
