#ifndef USER_H
#define USER_H

#include <QString>
#include <QDebug>

class User
{
public:
    User();
    ~User();

    //getters
    QString GetUsername();

    //setters
    void SetUsername(QString username);

private:
    QString username;

};

#endif // USER_H
