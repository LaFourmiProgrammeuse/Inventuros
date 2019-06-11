#include "mainmenupage.h"
#include "ui_mainmenupage.h"

MainMenuPage::MainMenuPage(QWidget *parent, Interface *interface) :
    QWidget(parent),
    ui(new Ui::MainMenuPage)
{
    qDebug() << "Constructor MainMenuPage";

    ui->setupUi(this);

    this->interface = interface;
}

MainMenuPage::~MainMenuPage()
{
    qDebug() << "Destructor MainMenuPage";

    delete ui;
}
