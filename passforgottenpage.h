#ifndef PASSFORGOTTENPAGE_H
#define PASSFORGOTTENPAGE_H

#include <QWidget>

class Interface;

#include "interface.h"


namespace Ui {
class PassForgottenPage;
}

class PassForgottenPage : public QWidget
{
    Q_OBJECT

public:
    explicit PassForgottenPage(QWidget *parent = nullptr, Interface *interface = nullptr);
    ~PassForgottenPage();

private slots:
    void on_button_back_clicked();

private:
    Ui::PassForgottenPage *ui;

    Interface *interface;
};

#endif // PASSFORGOTTENPAGE_H
