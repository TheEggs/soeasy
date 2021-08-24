#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "secondwin.h"
#include "ui_secondwin.h"

#include <QFileDialog>
#include <QtWidgets/QMessageBox>
#include "accessdb.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

//    AccessDB* db = new AccessDB();
//    QString idname=db->openDB("D:\\QT_user.mdb");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_load_clicked()
{
//QS    tring password;
    QString Root;
    QString usrnm=ui->username->text();
    QString usrpw=ui->password->text();

//    connect( ui->username,SIGNAL(returnPressed()), ui->load, SIGNAL(clicked()), Qt::UniqueConnection);
//    connect( ui->password,SIGNAL(returnPressed()), ui->load, SIGNAL(clicked()), Qt::UniqueConnection);

    AccessDB* get = new AccessDB();
    QString password = get->getpassword(usrnm);

    AccessDB* rt = new AccessDB();
    Root = rt->getroot(usrnm,usrpw);
    ui->label_25->setText(Root);

    if( password == usrpw && password != "")
    {
        ui->label_33->setText(QString::fromLocal8Bit("登录成功！"));
//        QMessageBox::information(nullptr, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("登陆成功"));

        this->hide();              //屏蔽登陆界面
        emit loadsuccess();        //激活信号

    }
    else
    {
        QMessageBox::information(nullptr, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("登陆失败"));
    }
}

void MainWindow::on_unload_clicked()
{
    AccessDB* close = new AccessDB();
    close->closeDB();

    ui->username->setText(QString::fromLocal8Bit("请输入用户名"));
    ui->password->setText(QString::fromLocal8Bit("XXX"));
    ui->label_25->setText(QString::fromLocal8Bit("已登出"));

    QMessageBox::information(nullptr, QString::fromLocal8Bit("提示"), QString::fromLocal8Bit("登出成功"));
}

QString rooted(QString name,QString word)
{
    QString value = "empty";
    AccessDB* rt = new AccessDB();
    QString Root = rt->getroot(name,word);
    if(!Root.isEmpty())
    {
        return Root;
    }
    else
    {
        return value;
    }
}
