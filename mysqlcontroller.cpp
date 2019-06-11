#include "mysqlcontroller.h"

MysqlController::MysqlController()
{
    qDebug() << "Constructor MysqlController";
}

MysqlController::~MysqlController()
{
    qDebug() << "Destructor MysqlController";

    connection->close();
    delete connection;
}

void MysqlController::InitBddConnection(std::string host, std::string schema, std::string username, std::string pass){

    try{
       driver= get_driver_instance();
       connection = driver->connect(host,
                         username, pass);
       connection->setAutoCommit(0);
       connection->setSchema(schema);
    }catch(sql::SQLException &ex){
       std::cout << "Exception occurred" << ex.getErrorCode()<< std::endl;
    }


}

void MysqlController::bind(sql::QueryString &query, QStringList l_arg){

    int query_length = query.length();
    for(int i = 0, a = 0; i < query_length; i++){

        if(query[i] == "?"){
            query.replace(i, 1, l_arg[a]);
            i += l_arg[a].length()-1;
            a++;
        }
    }
}

sql::Query *MysqlController::CreateQuery(){
    return connection->createStatement();
}

sql::PreparedQuery *MysqlController::CreatePreparedQuery(std::string sql_query){
    return connection->prepareStatement(sql_query);
}
