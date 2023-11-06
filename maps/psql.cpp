#include "psql.h"

//#define DEBUG


bool Psql::createConnection()
{
    db = QSqlDatabase::addDatabase("QPSQL");
    db.setPort(this->port_number);
    db.setHostName(this->hostname);
    db.setDatabaseName(this->database_name);
    db.setUserName(this->username);
    db.setPassword(this->password);
    if (!db.open())
    {
        QMessageBox::warning(0,"Error with db", db.lastError().text());
        return false;
    } else
    {
        QMessageBox::information(0,"Complete","Connection with db");
        return true;
    }
}

void Psql::Request_DB(const QString &&request)
{
#ifdef DEBUG
    QStringList lst =db.tables();
    foreach (QString str, lst) {
        qDebug() << str;
    }
#endif
    if (!query.exec(request))
    {
       QMessageBox::warning(0,"Unable to select a table", query.lastError().text());
    }
}

QSqlDatabase Psql::GetDatabase()
{
    return db;
}
