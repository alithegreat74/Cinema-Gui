#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QPixmap"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Signup_clicked()
{
   SignUpPage signup;
   signup.setModal(true);
   signup.exec();
}


void MainWindow::on_Signin_clicked()
{
    QFile file("UserData.txt");
    file.open(QFile::ReadOnly|QFile::Text);
    QTextStream in(&file);
    int number;
    in>>number;
    QString users[number];
    QString passes[number];
    QString ids[number];
    for(int i=0;i<number;i++){
        in>>users[i];
        in>>passes[i];
        in>>ids[i];
    }
    file.close();
    bool is_member=false;
    int i;
    for(i=0;i<number;i++){
        if(users[i]==this->ui->username->text() && passes[i]==this->ui->password->text()){
            is_member=true;
            break;
        }
    }
    if(is_member==true){
        if(users[i]=="admin"){
            hide();
            admin=new AdminInterace(this);
            admin->show();
        }
        else{
            QFile log("Log.txt");
            QTextStream go(&log);
                log.open(QFile::WriteOnly);
                go<<users[i];
                go<<" entered\n";
                log.close();
                hide();
                userinterface=new UserInterface(this);
                userinterface->show();
            }
    }
    else{
        QMessageBox::StandardButton reply=QMessageBox::information(this,"title","your username or password is incorect");
    }

}


void MainWindow::on_forgotpassword_clicked()
{
    forgotmypassword newwin;
    newwin.setModal(true);
    newwin.exec();
}

