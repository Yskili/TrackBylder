#ifndef PSQL_H
#define PSQL_H

#include <QMessageBox>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include <QSqlQuery>


class Psql
{
    QSqlDatabase db;
    QSqlQuery query;
    int unsigned port_number;
    QString hostname, database_name, username, password;

public:
    Psql(QString _hostname, QString _database_name, QString _username, QString password, int unsigned _port_number = 5432):
        hostname(_hostname), database_name(_database_name), username(_username), password(password), port_number(_port_number){}
    bool createConnection();
    void Request_DB(const QString &&request);
    QSqlDatabase GetDatabase();
    ~Psql(){}
};


#endif // PSQL_H
