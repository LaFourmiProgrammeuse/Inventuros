#ifndef MYSQLCONTROLLER_H
#define MYSQLCONTROLLER_H

#include <QString>
#include <QStringList>
#include <QDebug>

#include <mysql_driver.h>
#include <mysql_connection.h>
#include <mysql/mysql.h>

#include <cppconn/connection.h>
#include <cppconn/prepared_statement.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>

//Type
namespace sql {
    using QueryString = QString;
    using Query = sql::Statement;
    using PreparedQuery = sql::PreparedStatement;
}

class MysqlController
{
public:
    MysqlController();
    ~MysqlController();

    void InitBddConnection(std::string host, std::string schema, std::string username, std::string pass);

    sql::Query *CreateQuery();
    sql::PreparedQuery *CreatePreparedQuery(std::string sql_query);
    void bind(sql::QueryString &query, QStringList l_arg);

private:
    sql::Driver *driver;
    sql::Connection *connection;

    //Fonction privée

};

#endif // MYSQLCONTROLLER_H
