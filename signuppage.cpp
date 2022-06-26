#include "signuppage.h"
#include "ui_signuppage.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include "mainwindow.h"

SignUpPage::SignUpPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignUpPage)
{
    ui->setupUi(this);

}

SignUpPage::~SignUpPage()
{
    delete ui;
}

void SignUpPage::on_signup_clicked()
{
    QFile file("UserData.txt");
    file.open(QIODevice::ReadOnly);
    int number;
    QTextStream in(&file);
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
    number++;
    QString user=this->ui->username->text();
    QString pass=this->ui->password->text();
    QString idcode=this->ui->idcode->text();
    bool alreadyIN=false;
    for(int j=0;j<number-1;j++){
        if(idcode==ids[j] || user==users[j]){
           alreadyIN=true;
           break;
        }
    }
    if(alreadyIN==true)
         QMessageBox::StandardButton reply=QMessageBox::information(this,"title","An account with this username or id code already exists");
    else{
        file.open(QFile::WriteOnly);
        in<<number;
        in<<'\n';
        for(int i=0;i<number--;i++){
            in<<users[i]+ ' ';
            in<<passes[i]+ ' ';
            in<<ids[i]+ '\n';
        }
        in<<user+ ' ';
        in<<pass+ ' ';
        in<<idcode+ '\n';
        file.close();
        QMessageBox::StandardButton reply=QMessageBox::information(this,"title","your account created sucessfuly");
    }
}

