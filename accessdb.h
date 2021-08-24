#ifndef ACCESSDB_H
#define ACCESSDB_H
#include <QtSql>

#include <QMainWindow>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>


class AccessDB
{
public:
   AccessDB();
   bool connectDB();

   QString getpassword(QString username);
   //bool insertData(const QString &insert);
   QString openDB(const QString& connectName);
   //void closeDB(const QString& connectName);
   QString getroot(QString username,QString password);
   QString closeDB();
   QSqlDatabase connection;
   QSqlQuery *m_query;
   QString idName;
//   QSqlDatabase dbconn;
};


#endif // ACCESSDB_H
