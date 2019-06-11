#include "interface.h"
#include "ui_interface.h"

Interface::Interface(QWidget *parent, User *user) :
    QMainWindow(parent),
    ui(new Ui::Interface)
{
    ui->setupUi(this);

    central_stacked_widget = ui->stackedWidget;
    this->user = user;

    QDesktopWidget *desktop = QApplication::desktop();
    QRect desktop_geometry = desktop->screenGeometry();
    this->setBaseSize(interface_width, interface_height);
    this->move(desktop->screenGeometry().width()/2 - interface_width/2, desktop->screenGeometry().height()/2 - interface_height/2);

    login_page = new LoginPage(this, this, user);
    register_page = new RegisterPage(this, this, user);
    main_menu_page = new MainMenuPage(this, this);
    pass_forgotten_page = new PassForgottenPage(this, this);

    central_stacked_widget->addWidget(login_page);
    central_stacked_widget->addWidget(register_page);
    central_stacked_widget->addWidget(pass_forgotten_page);
    
    central_stacked_widget->setCurrentIndex(1);

}

Interface::~Interface()
{
    qDebug() << "Destructor Interface";

    delete ui;

    delete login_page;
    delete register_page;
    delete main_menu_page;
    delete pass_forgotten_page;
}

int Interface::GetWidthInterface(){
    return interface_width;
}

int Interface::GetHeightInterface(){
    return interface_height;
}

void Interface::SetWidthInterface(int width){
    interface_width = width;
}

void Interface::SetHeightInterface(int height){
    interface_height = height;
}

void Interface::SetInterfacePageIndex(int index){
    ui->stackedWidget->setCurrentIndex(index);
}


