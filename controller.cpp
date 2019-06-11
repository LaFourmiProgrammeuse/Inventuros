#include "controller.h"

Controller::Controller()
{
    qDebug() << "Constructor Controller";

    user = new User;
    interface = new Interface(nullptr, user);
}

Controller::~Controller()
{
    qDebug() << "Destructor Controller";

    delete interface;
    delete user;
}

int Controller::InitApplication(){

    interface->show();

    return 1;
}
