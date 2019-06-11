#include "registerpage.h"
#include "ui_registerpage.h"

RegisterPage::RegisterPage(QWidget *parent, Interface *interface, User *users) :
    QWidget(parent),
    ui(new Ui::RegisterPage)
{
    qDebug() << "Constructor RegisterPage";

    ui->setupUi(this);
    this->interface = interface;

    QString css_s;
    QFile css_file("css/register_page.css");

    if(!css_file.open(QIODevice::ReadOnly)){
        qDebug() << "Error during opening of a css file : css/register_page.css";
    }
    else{
        css_s = QString(css_file.readAll());
        this->setStyleSheet(css_s);
    }

    InitGraphicalComponenent();
}

RegisterPage::~RegisterPage()
{
    qDebug() << "Destructor RegisterPage";

    delete ui;
}

void RegisterPage::on_button_already_account_clicked()
{
    interface->SetInterfacePageIndex(0);
}

void RegisterPage::InitGraphicalComponenent(){

    ui->label_info->setVisible(false);
    ui->label_error->setVisible(false);
}
