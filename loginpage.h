#ifndef LOGINPAGE_H
#define LOGINPAGE_H

class Interface;

#include <QWidget>
#include <QFile>
#include <QPushButton>

#include "xmlcontroller.h"
#include "mysqlcontroller.h"
#include "interface.h"
#include "user.h"
#include "roundedrectwidget.h"


namespace Ui {
class LoginPage;
}

class LoginPage : public QWidget
{
    Q_OBJECT

public:
    explicit LoginPage(QWidget *parent = nullptr, Interface *interface = nullptr, User *user = nullptr);
    ~LoginPage();

    //On regarde si un utilisateur était resté connecté (variable stay connected(xml))
    void LoadUserXmlSavedData(); //xml

    QString GetConnectedUserId(); //xml
    void LoadUserProfile(); //bdd

    bool CreateNewUser(); //bdd

    void InitGraphicalComponent();

private slots:
    void on_button_connect_clicked();

    void on_button_no_already_account_clicked();

private:
    Ui::LoginPage *ui;

    User *user;
    MysqlController *mysql_controller;
    Interface *interface;
    RoundedRectWidget *rounded_rect_widget;

    bool first_connection = true;
    bool last_usr_stayed_connected = false;
    QString user_id;

    QPushButton *button_test;

};

#endif // LOGINPAGE_H
