#include "forgotmypassword.h"
#include "ui_forgotmypassword.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

forgotmypassword::forgotmypassword(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::forgotmypassword)
{
    ui->setupUi(this);
    this->ui->chagepass->setHidden(true);
    this->ui->Newpasslabel->setHidden(true);
    this->ui->newpassentery->setHidden(true);
}

forgotmypassword::~forgotmypassword()
{
    delete ui;
}

void forgotmypassword::on_OK_clicked()
{
    QFile file("UserData.txt");
    file.open(QFile::ReadOnly);
    int number;
    QTextStream in(&file);
    in>>number;
    QString users[number];
    QString passes[number];
    QString IDCodes[number];
    for(int i=0;i<number;i++){
        in>>users[i];
        in>>passes[i];
        in>>IDCodes[i];
    }
    file.close();
    bool is_member=false;
    int i;
    for(i=0;i<number;i++){
        if(users[i]==this->ui->lineEdit->text()){
            is_member=true;
            break;
        }
    }
    if(is_member==false)
        QMessageBox::StandardButton reply= QMessageBox::information(this,"title","your Username is not correct");
    else if(IDCodes[i]!=this->ui->lineEdit_2->text())
        QMessageBox::StandardButton reply= QMessageBox::information(this,"title","your ID Code is not correct");
    else{
        this->ui->chagepass->setHidden(false);
        this->ui->Newpasslabel->setHidden(false);
        this->ui->newpassentery->setHidden(false);
        this->ui->OK->setHidden(true);
    }

}


void forgotmypassword::on_chagepass_clicked()
{
    QFile file("UserData.txt");
    file.open(QFile::ReadOnly);
    int number;
    QTextStream in(&file);
    in>>number;
    QString users[number];
    QString passes[number];
    QString IDCodes[number];
    for(int i=0;i<number;i++){
        in>>users[i];
        in>>passes[i];
        in>>IDCodes[i];
    }
    file.close();
    int i;
    for(i=0;i<number;i++){
        if(users[i]==this->ui->lineEdit->text())
            break;
    }
    if(this->ui->newpassentery->text()==passes[i] || this->ui->newpassentery->text()=="" ){
        QMessageBox::StandardButton reply=QMessageBox::information(this,"title","your password is not acceptable");
    }
    else{
        passes[i]=this->ui->newpassentery->text();
        file.open(QFile::WriteOnly);
        in<<number;
        in<<"\n";
        for(int j=0;j<number;j++){
            in<<users[j]+" ";
            in<<passes[j]+" ";
            in<<IDCodes[j]+"\n";
        }
        QMessageBox::StandardButton reply=QMessageBox::information(this,"title","your password changed sucessfuly");
    }
}
