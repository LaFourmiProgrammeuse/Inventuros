#ifndef INTERFACE_H
#define INTERFACE_H

class LoginPage;
class MainMenuPage;
class RegisterPage;
class PassForgottenPage;

#include <QMainWindow>
#include <QStackedWidget>
#include <QApplication>
#include <QDesktopWidget>

#include "registerpage.h"
#include "user.h"
#include "loginpage.h"
#include "mainmenupage.h"
#include "passforgottenpage.h"

namespace Ui {
class Interface;
}

class Interface : public QMainWindow
{
    Q_OBJECT

public:
    explicit Interface(QWidget *parent = nullptr, User *user = nullptr);
    ~Interface();

    //getters
    int GetWidthInterface();
    int GetHeightInterface();

    //setters
    void SetWidthInterface(int width);
    void SetHeightInterface(int height);

    void SetInterfacePageIndex(int index);

public slots:


private:
    Ui::Interface *ui;
    User *user;

    QStackedWidget *central_stacked_widget;

    LoginPage *login_page = nullptr;
    RegisterPage *register_page = nullptr;
    MainMenuPage *main_menu_page = nullptr;
    PassForgottenPage *pass_forgotten_page = nullptr;

    //Les valeurs set ici ne seront valable que jusqu'à un redimensionnement d'un user
    int interface_width = 800;
    int interface_height = 600;

};

#endif // INTERFACE_H
