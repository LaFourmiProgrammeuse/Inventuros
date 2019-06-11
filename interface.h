#ifndef INTERFACE_H
#define INTERFACE_H

class LoginPage;
class MainMenuPage;
class RegisterPage;

#include <QMainWindow>
#include <QStackedWidget>
#include <QApplication>
#include <QDesktopWidget>

#include "registerpage.h"
#include "user.h"
#include "loginpage.h"
#include "mainmenupage.h"

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

    LoginPage *login_page;
    RegisterPage *register_page;
    MainMenuPage *main_menu_page;

    //Les valeurs set ici ne seront valable que jusqu'à un redimensionnement d'un user
    int interface_width = 800;
    int interface_height = 600;

};

#endif // INTERFACE_H
