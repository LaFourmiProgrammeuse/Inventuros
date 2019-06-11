#include "loginpage.h"
#include "ui_loginpage.h"

LoginPage::LoginPage(QWidget *parent, Interface *interface, User *user) :
    QWidget(parent),
    ui(new Ui::LoginPage)
{
    qDebug() << "Constructor LoginPage";

    ui->setupUi(this);

    this->user = user;
    this->interface = interface;

    LoadUserXmlSavedData();

    //On initialise une connection avec la bdd
    mysql_controller = new MysqlController;
    mysql_controller->InitBddConnection("localhost", "inventuros", "antoine", "151172");

    if(first_connection == false){

        LoadUserProfile();
    }

    InitGraphicalComponent();

    QString css_s;
    QFile css_file("css/login_page.css");

    if(!css_file.open(QIODevice::ReadOnly)){
        qDebug() << "Error during opening of a css file : css/login_page.css";
    }
    else{
        css_s = QString(css_file.readAll());
        this->setStyleSheet(css_s);
    }

    ui->stackedWidget->setCurrentIndex(1);

}

LoginPage::~LoginPage()
{
    qDebug() << "Destructor LoginPage";

    delete mysql_controller;
    delete ui;
}

void LoginPage::LoadUserXmlSavedData(){

    XmlController xml_controller("data.xml");
    QDomDocument *xml_doc = xml_controller.GetDocument();
    QDomElement doc_root = xml_doc->documentElement();

    for(QDomNode n = doc_root.firstChild(); !n.isNull(); n = n.nextSibling()){

        QDomElement e = n.toElement();

        if(e.tagName() == "last_user"){

            //Il y a déjà eu un précedent user donc ce n'est pas la première connection
            first_connection = false;

            for(QDomNode n2 = e.firstChild(); !n2.isNull(); n2 = n2.nextSibling()){

                if(n2.nodeName() == "stay_connected"){

                    if(n2.childNodes().at(0).nodeValue() == "true"){
                        last_usr_stayed_connected = true;
                    }
                    else{
                        last_usr_stayed_connected = false;
                    }
                }
                else if(n2.nodeName() == "id"){
                    user_id = n2.childNodes().at(0).nodeValue();
                }
            }
        }
    }
}

void LoginPage::LoadUserProfile(){

    sql::PreparedQuery *query = mysql_controller->CreatePreparedQuery("SELECT username FROM users WHERE id=?");

    query->setString(1, user_id.toStdString());
    sql::ResultSet *result(query->executeQuery());

    if(result->next()){
        user->SetUsername(QString::fromStdString(result->getString("username")));
    }

    delete query;
    delete result;


}

void LoginPage::InitGraphicalComponent(){

    ui->label_error->setVisible(false);

}

    /* SLOTS */

void LoginPage::on_button_connect_clicked()
{
    std::string login_name = ui->line_edit_login_name->text().toStdString();
    std::string pass = ui->line_edit_pass->text().toStdString();

    //On vérifie que les champs du formulaire soit bien renseignés
    if(login_name == "" || pass == ""){

        QString error = "Veuillez renseigner tout les champs du formulaire";
        ui->label_error->setText(error);
        ui->label_error->setVisible(true);

        return;
    }

    sql::PreparedQuery *query = mysql_controller->CreatePreparedQuery("SELECT username FROM users WHERE username=? && pass=?");
    query->setString(1, login_name);
    query->setString(2, pass);

    sql::ResultSet *q_result = query->executeQuery();

    if(q_result == nullptr){
        std::cout << "Une requête mysql n'a rien renvoyé" << std::endl;
        return;
    }

    if(!q_result->next()){

        sql::PreparedQuery *query_2 = mysql_controller->CreatePreparedQuery("SELECT username FROM users WHERE username=?");
        query_2->setString(1, login_name);

        sql::ResultSet *q_result_2 = query_2->executeQuery();

        if(q_result_2 == nullptr){
            std::cout << "Une requête mysql n'a rien renvoyé" << std::endl;
            return;
        }

        QString error;
        if(!q_result_2->next()){
            error = QString("Le nom d'utilisateur ou l'adresse email n'existe pas");
        }
        else{
            error = QString("Le nom d'utilisateur ou l'adresse email ne correspondent pas au mot de passe");
        }

        ui->label_error->setText(error);
        ui->label_error->setVisible(true);

        delete query_2;
        delete q_result_2;
    }

    delete query;
    delete q_result;


}

void LoginPage::on_button_no_already_account_clicked()
{
    interface->SetInterfacePageIndex(1);
}

void LoginPage::on_button_pass_forgotten_clicked()
{
    interface->SetInterfacePageIndex(2);

}
