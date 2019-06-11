#include "passforgottenpage.h"
#include "ui_passforgottenpage.h"

PassForgottenPage::PassForgottenPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PassForgottenPage)
{
    ui->setupUi(this);
}

PassForgottenPage::~PassForgottenPage()
{
    delete ui;
}
