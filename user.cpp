#include "user.h"

User::User()
{
    qDebug() << "Constructor User";
}

User::~User(){
    qDebug() << "Destructor User";
}

void User::SetUsername(QString username){
    this->username = username;
}

QString User::GetUsername(){
    return username;
}
