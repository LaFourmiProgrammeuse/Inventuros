#include <QApplication>
#include <QDir>
#include <QDebug>

#include "controller.h"
#include "xmlcontroller.h"
#include "loginpage.h"

int main(int argc, char *argv[]){

    QApplication app(argc, argv);

    Controller controller;
    if(controller.InitApplication() != 1){
        qDebug() << "Error during application init";
    }

    return app.exec();
}
