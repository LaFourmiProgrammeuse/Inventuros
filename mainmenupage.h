#ifndef MAINMENUPAGE_H
#define MAINMENUPAGE_H

class Interface;

#include <QWidget>
#include <QDebug>

#include "interface.h"

namespace Ui {
class MainMenuPage;
}

class MainMenuPage : public QWidget
{
    Q_OBJECT

public:
    explicit MainMenuPage(QWidget *parent = nullptr, Interface *interface = nullptr);
    ~MainMenuPage();

private:
    Ui::MainMenuPage *ui;

    Interface *interface;
};

#endif // MAINMENUPAGE_H
