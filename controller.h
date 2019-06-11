#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QDebug>

#include "interface.h"

enum AppStates{Init};

class Controller
{
public:
    Controller();
    ~Controller();

    int InitApplication();

private:
    Interface *interface;
    User *user;
};

#endif // CONTROLLER_H
