#include "admininterace.h"
#include "ui_admininterace.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

AdminInterace::AdminInterace(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminInterace)
{
    ui->setupUi(this);
    this->ui->addnewmovie->setHidden(true);
    this->ui->comboBox->setHidden(true);
    this->ui->label_2->setHidden(true);
    this->ui->label_3->setHidden(true);
    this->ui->label_4->setHidden(true);
    this->ui->label_5->setHidden(true);
    this->ui->lineEdit->setHidden(true);
    this->ui->lineEdit_2->setHidden(true);
    this->ui->lineEdit_3->setHidden(true);
    this->ui->label_6->setHidden(true);
    this->ui->removecombobox->setHidden(true);
    this->ui->removethismovie->setHidden(true);
    this->ui->Back->setHidden(true);
    this->ui->label_7->setHidden(true);
    this->ui->label_9->setHidden(true);
    this->ui->label_11->setHidden(true);
    this->ui->label_12->setHidden(true);
    this->ui->textBrowser->setHidden(true);
    this->ui->textBrowser_3->setHidden(true);
    this->ui->textBrowser_5->setHidden(true);
    this->ui->textBrowser_6->setHidden(true);
}

AdminInterace::~AdminInterace()
{
    delete ui;
}

void AdminInterace::on_addorder_clicked()
{
    this->ui->addorder->setHidden(true);
    this->ui->removeorder->setHidden(true);
    this->ui->addnewmovie->setHidden(false);
    this->ui->comboBox->setHidden(false);
    this->ui->label_2->setHidden(false);
    this->ui->label_3->setHidden(false);
    this->ui->label_4->setHidden(false);
    this->ui->label_5->setHidden(false);
    this->ui->lineEdit->setHidden(false);
    this->ui->lineEdit_2->setHidden(false);
    this->ui->lineEdit_3->setHidden(false);
    this->ui->Back->setHidden(false);
    this->ui->Exit->setHidden(true);
    this->ui->showmovies->setHidden(true);

}

void AdminInterace::on_Exit_clicked()
{
    QApplication::closeAllWindows();
}


void AdminInterace::on_removeorder_clicked()
{
    this->ui->addorder->setHidden(true);
    this->ui->removeorder->setHidden(true);
    this->ui->Exit->setHidden(true);
    this->ui->showmovies->setHidden(true);
    this->ui->label_6->setHidden(false);
    this->ui->removecombobox->setHidden(false);
    this->ui->removethismovie->setHidden(false);
    this->ui->Back->setHidden(false);

}


void AdminInterace::on_addnewmovie_clicked()
{
    QFile movienames("Names.txt");
    QFile genres("Genres.txt");
    QFile dirs("Directors.txt");

    QString name[4];
    QString genre[4];
    QString dir[4];

    QTextStream inname(&movienames);
    QTextStream ingenre(&genres);
    QTextStream indirs(&dirs);

    movienames.open(QFile::ReadOnly);
    genres.open(QFile::ReadOnly);
    dirs.open(QFile::ReadOnly);
    for(int i=0;i<4;i++){
        name[i]=inname.readLine();
        genre[i]=ingenre.readLine();
        dir[i]=indirs.readLine();
    }
    movienames.close();
    genres.close();
    dirs.close();
    int theater;
    if(this->ui->comboBox->currentText()=="1")
        theater=0;
    else if(this->ui->comboBox->currentText()=="2")
        theater=1;
    else if(this->ui->comboBox->currentText()=="3")
        theater=2;
    else if(this->ui->comboBox->currentText()=="4")
        theater=3;
    if(this->ui->lineEdit->text()=="" || this->ui->lineEdit_2->text()=="" || this->ui->lineEdit_3->text()=="" || this->ui->comboBox->currentText()=="")
        QMessageBox::StandardButton reply=QMessageBox::information(this,"title","you have to give full information");
    else{
        movienames.open(QFile::WriteOnly);
        genres.open(QFile::WriteOnly);
        dirs.open(QFile::WriteOnly);
        name[theater]=this->ui->lineEdit->text();
        genre[theater]=this->ui->lineEdit_2->text();
        dir[theater]=this->ui->lineEdit_3->text();
        for(int i=0;i<4;i++){
            inname<<name[i]+"\n";
            ingenre<<genre[i]+"\n";
            indirs<<dir[i]+"\n";
        }
        QMessageBox::StandardButton reply=QMessageBox::information(this,"title","your movie added");
        movienames.close();
        genres.close();
        dirs.close();
    }

}


void AdminInterace::on_Back_clicked()
{
    this->ui->addnewmovie->setHidden(true);
    this->ui->comboBox->setHidden(true);
    this->ui->label_2->setHidden(true);
    this->ui->label_3->setHidden(true);
    this->ui->label_4->setHidden(true);
    this->ui->label_5->setHidden(true);
    this->ui->lineEdit->setHidden(true);
    this->ui->lineEdit_2->setHidden(true);
    this->ui->lineEdit_3->setHidden(true);
    this->ui->label_6->setHidden(true);
    this->ui->removecombobox->setHidden(true);
    this->ui->removethismovie->setHidden(true);
    this->ui->Back->setHidden(true);
    this->ui->label_7->setHidden(true);
    this->ui->label_9->setHidden(true);
    this->ui->label_11->setHidden(true);
    this->ui->label_12->setHidden(true);
    this->ui->textBrowser->setHidden(true);
    this->ui->textBrowser_3->setHidden(true);
    this->ui->textBrowser_5->setHidden(true);
    this->ui->textBrowser_6->setHidden(true);
    this->ui->addorder->setHidden(false);
    this->ui->removeorder->setHidden(false);
    this->ui->Exit->setHidden(false);
    this->ui->showmovies->setHidden(false);
}


void AdminInterace::on_removethismovie_clicked()
{
    QFile movienames("Names.txt");
    QFile genres("Genres.txt");
    QFile dirs("Directors.txt");

    QString name[4];
    QString genre[4];
    QString dir[4];

    QTextStream inname(&movienames);
    QTextStream ingenre(&genres);
    QTextStream indirs(&dirs);

    movienames.open(QFile::ReadOnly);
    genres.open(QFile::ReadOnly);
    dirs.open(QFile::ReadOnly);
    for(int i=0;i<4;i++){
        name[i]=inname.readLine();
        genre[i]=ingenre.readLine();
        dir[i]=indirs.readLine();
    }
    movienames.close();
    genres.close();
    dirs.close();
    if(this->ui->removecombobox->currentText()=="")
        QMessageBox::StandardButton reply=QMessageBox::information(this,"title","choose a theater");
    else{
        int theater=this->ui->removecombobox->currentText().toInt();
        theater--;
        name[theater]=" ";
        genre[theater]=" ";
        dir[theater]=" ";
        movienames.open(QFile::WriteOnly);
        genres.open(QFile::WriteOnly);
        dirs.open(QFile::WriteOnly);
        for(int i=0;i<4;i++){
            inname<<name[i]+"\n";
            ingenre<<genre[i]+"\n";
            indirs<<dir[i]+"\n";
        }
        QMessageBox::StandardButton reply=QMessageBox::information(this,"title","your movie is removed");
        movienames.close();
        genres.close();
        dirs.close();
        QFile book("Booked.txt");
        QTextStream inbook(&book);
        book.open(QFile::ReadOnly);
        int a[4];
        for(int i=0;i<4;i++)
            a[i]=inbook.readLine().toInt();
        a[theater]=0;
        book.close();
        book.open(QFile::WriteOnly);
        for(int i=0;i<4;i++){
            if(i==3){
                inbook<<a[i];
                break;
            }
            inbook<<QString::number(a[i])+"\n";
        }
        book.close();
    }





}


void AdminInterace::on_showmovies_clicked()
{
    this->ui->addorder->setHidden(true);
    this->ui->removeorder->setHidden(true);
    this->ui->Exit->setHidden(true);
    this->ui->showmovies->setHidden(true);
    this->ui->Back->setHidden(false);
    this->ui->label_7->setHidden(false);
    this->ui->label_9->setHidden(false);
    this->ui->label_11->setHidden(false);
    this->ui->label_12->setHidden(false);
    this->ui->textBrowser->setHidden(false);
    this->ui->textBrowser_3->setHidden(false);
    this->ui->textBrowser_5->setHidden(false);
    this->ui->textBrowser_6->setHidden(false);

    QFile movienames("Names.txt");
    QFile genres("Genres.txt");
    QFile dirs("Directors.txt");

    QString name[4];
    QString genre[4];
    QString dir[4];

    QTextStream inname(&movienames);
    QTextStream ingenre(&genres);
    QTextStream indirs(&dirs);

    movienames.open(QFile::ReadOnly);
    genres.open(QFile::ReadOnly);
    dirs.open(QFile::ReadOnly);

    for(int i=0;i<4;i++){
        name[i]=inname.readLine();
        genre[i]=ingenre.readLine();
        dir[i]=indirs.readLine();
    }

    movienames.close();
    genres.close();
    dirs.close();

    this->ui->textBrowser->setText("Name: "+ name[0]+ " Genre: "+ genre[0]+ " Director: "+dir[0]);
    this->ui->textBrowser_3->setText("Name: "+ name[1]+ " Genre: "+ genre[1]+ " Director: "+dir[1]);
    this->ui->textBrowser_5->setText("Name: "+ name[2]+ " Genre: "+ genre[2]+ " Director: "+dir[2]);
    this->ui->textBrowser_6->setText("Name: "+ name[3]+ " Genre: "+ genre[3]+ " Director: "+dir[3]);
}

