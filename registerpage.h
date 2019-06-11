#ifndef REGISTERPAGE_H
#define REGISTERPAGE_H

class User;
class Interface;

#include <QWidget>
#include <QDebug>
#include <QFile>
#include <QString>

#include "interface.h"
#include "user.h"

namespace Ui {
class RegisterPage;
}

class RegisterPage : public QWidget
{
    Q_OBJECT

public:
    explicit RegisterPage(QWidget *parent = nullptr, Interface *interface = nullptr, User *user = nullptr);
    ~RegisterPage();

    void InitGraphicalComponenent();

private slots:
    void on_button_already_account_clicked();

private:
    Ui::RegisterPage *ui;

    Interface *interface;
};

#endif // REGISTERPAGE_H
