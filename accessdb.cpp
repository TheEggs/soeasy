#include "accessdb.h"
#include <QMessageBox>

#include "mainwindow.h"
#include "ui_mainwindow.h"

AccessDB::AccessDB()
{}

static QSqlDatabase dbconn= QSqlDatabase::addDatabase("QODBC", "D:\\QT_user.mdb");

bool AccessDB::connectDB()
{
//获取是否存在有数据库连接
//    dbconn = QSqlDatabase::database("D:\\QT_test\\access\\QT_user.mdb", false);

    if(dbconn.isValid())//存在连接直接退出
    {
        return true;
    }
    return true;
}


QString AccessDB::getpassword(QString username)
{
    QString dsn = QString("DRIVER={Microsoft Access Driver (*.mdb, *.accdb)};FIL={MS Access};DBQ=%1;UID=;PWD=%2")
            .arg("D:\\QT_user.mdb");
    dbconn.setDatabaseName(dsn);
    dbconn.open();

    QSqlQueryModel *model = new QSqlQueryModel;
    QString a = "SELECT password FROM QT where ID = '"+username+"'";

    QSqlQueryModel *model2 = new QSqlQueryModel;
    QString b = "SELECT root FROM QT where ID = '"+username+"'";

//    qDebug() << a;

    model->setQuery(QObject::tr(a.toStdString().c_str()),dbconn);
    model2->setQuery(QObject::tr(b.toStdString().c_str()),dbconn);

//    QTableView *view = new QTableView;
//    view->setModel(model);
//    view->show();

    QSqlQuery query = model->query();

    QString name = model->record(0).value("ID").toString();
    QString word = model->record(0).value("password").toString();

    QSqlQuery query2 = model2->query();
    QString root = model2->record(0).value("root").toString();

//    qDebug() << username;
//    qDebug() << word;
//    qDebug() << root;

    return word;
}

QString AccessDB::getroot(QString username,QString password)
{
    QString dsn = QString("DRIVER={Microsoft Access Driver (*.mdb, *.accdb)};FIL={MS Access};DBQ=%1;UID=;PWD=%2")
            .arg("D:\\QT_user.mdb");
    dbconn.setDatabaseName(dsn);
    dbconn.open();

    QSqlQueryModel *model = new QSqlQueryModel;
    QString a = "SELECT root FROM QT where ID = '"+username+"'";
    model->setQuery(QObject::tr(a.toStdString().c_str()),dbconn);
    QSqlQuery query = model->query();
    QString root = model->record(0).value("root").toString();

    QSqlQueryModel *model2 = new QSqlQueryModel;
    QString b = "SELECT password FROM QT where ID = '"+username+"'";
    model2->setQuery(QObject::tr(b.toStdString().c_str()),dbconn);
    QSqlQuery query2 = model2->query();
    QString pw = model2->record(0).value("password").toString();

//    qDebug() << root;
//    qDebug() << password;
//    qDebug() << pw;

    QString ot = "error";

    if(pw == password)
    {
        return root;
    }
    else
    {
        return ot;
    }
}

QString AccessDB::openDB(const QString& connectName)
{
    idName = connectName;
    if(!connectDB())
    {
        QMessageBox msgBox;
        msgBox.setText(QString::fromLocal8Bit("数据库连接失败"));
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.exec();
        return idName+"11111";
    }
    else
    {
        return idName;
    }

}

QString AccessDB::closeDB()
{
    const QString connID(idName);
    connection.close();
    connection.removeDatabase(connID);

    return idName;
}
