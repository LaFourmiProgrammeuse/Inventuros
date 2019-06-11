#include "passforgottenpage.h"
#include "ui_passforgottenpage.h"

PassForgottenPage::PassForgottenPage(QWidget *parent, Interface *interface) :
    QWidget(parent),
    ui(new Ui::PassForgottenPage)
{
    ui->setupUi(this);

    this->interface = interface;
}

PassForgottenPage::~PassForgottenPage()
{
    delete ui;
}

void PassForgottenPage::on_button_back_clicked()
{
    interface->SetInterfacePageIndex(0);
}
