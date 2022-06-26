#include "userinterface.h"
#include "ui_userinterface.h"
#include <QFile>
#include <QMessageBox>

class movies{
private:
      QString name;
      QString genre;
      QString director;
public:
      QString getname(){
          return name;
      }
      void setname(QString Name){
          name=Name;
      }
      QString getgenre(){
          return genre;
      }
      void setgenre(QString Genre){
          genre=Genre;
      }
      QString getdir(){
          return director;
      }
      void setdir(QString dir){
          director=dir;
      }
};
class theater{
private:
    int tickets;
    int bookedtickets;
    movies Movie;
public:
    int gettickets(){
        return tickets;
    }
    int getbookedtickets(){
        return bookedtickets;
    }
    movies getMovie(){
        return Movie;
    }
    void settickets(int t){
        tickets=t;
    }
    void setMovie(movies movie){
        Movie=movie;
    }
    void setBookedtickets(int t){
        bookedtickets=t;
    }
    int remainingtickets(){
        return tickets-bookedtickets;
    }

};

void getmovies(theater &paradiso,int num){
    paradiso.settickets(15);
    movies Movie;
    QFile movienames("Names.txt");
    QFile genres("Genres.txt");
    QFile directors("Directors.txt");
    QFile booked("Booked.txt");
    QString name[4];
    QString genre[4];
    QString dir[4];
    QString book[4];
    QTextStream inname(&movienames);
    QTextStream ingenre(&genres);
    QTextStream indirs(&directors);
    QTextStream inbook(&booked);
    movienames.open(QFile::ReadOnly);
    genres.open(QFile::ReadOnly);
    directors.open(QFile::ReadOnly);
    booked.open(QFile::ReadOnly);
    for(int i=0;i<4;i++){
        name[i]=inname.readLine();
        genre[i]=ingenre.readLine();
        dir[i]=indirs.readLine();
        book[i]=inbook.readLine();
    }
    Movie.setdir(dir[num-1]);
    Movie.setname(name[num-1]);
    Movie.setgenre(genre[num-1]);
    paradiso.setBookedtickets(book[num-1].toInt());
    paradiso.setMovie(Movie);
    movienames.close();
    genres.close();
    directors.close();
}

UserInterface::UserInterface(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserInterface)
{
    ui->setupUi(this);
    this->ui->theater1->setHidden(true);
    this->ui->theater2->setHidden(true);
    this->ui->theater3->setHidden(true);
    this->ui->theater4->setHidden(true);
    this->ui->back->setHidden(true);
    this->ui->book->setHidden(true);
    this->ui->comboBox->setHidden(true);
    this->ui->whichtheater->setHidden(true);
    this->ui->howmany->setHidden(true);
    this->ui->howmanytickets->setHidden(true);
    this->ui->BOOK->setHidden(true);
    this->ui->MOVIES->setHidden(true);
    this->ui->remain->setHidden(true);
    this->ui->showremain->setHidden(true);
    this->ui->SearchButton->setHidden(true);
    this->ui->comboBox_2->setHidden(true);
    this->ui->searchobject->setHidden(true);
    this->ui->textBrowser->setHidden(true);
    this->ui->searchobject_2->setHidden(true);
    this->ui->searchline->setHidden(true);
    this->ui->textBrowser_2->setHidden(true);
}

UserInterface::~UserInterface()
{
    delete ui;
}

void UserInterface::on_Exit_clicked()
{
    QApplication::closeAllWindows();
}


void UserInterface::on_Movies_clicked()
{
    this->ui->welcome->setHidden(true);
    this->ui->history->setHidden(true);
    this->ui->BOOK->setHidden(true);
    this->ui->welcome->setHidden(true);
    this->ui->Exit->setHidden(true);
    this->ui->Movies->setHidden(true);
    this->ui->BookTickets->setHidden(true);
    this->ui->Search->setHidden(true);
    this->ui->MOVIES->setHidden(false);
    this->ui->theater1->setHidden(false);
    this->ui->theater2->setHidden(false);
    this->ui->theater3->setHidden(false);
    this->ui->theater4->setHidden(false);
    this->ui->back->setHidden(false);
    theater Theater1;
    getmovies(Theater1,1);
    theater Theater2;
    getmovies(Theater2,2);
    theater Theater3;
    getmovies(Theater3,3);
    theater Theater4;
    getmovies(Theater4,4);
    this->ui->theater1->setText("Name: "+Theater1.getMovie().getname()+" | Genre: "+ Theater1.getMovie().getgenre()+" | Director: "+Theater1.getMovie().getdir());
    this->ui->theater2->setText("Name: "+Theater2.getMovie().getname()+" | Genre: "+ Theater2.getMovie().getgenre()+" | Director: "+Theater2.getMovie().getdir());
    this->ui->theater3->setText("Name: "+Theater3.getMovie().getname()+" | Genre: "+ Theater3.getMovie().getgenre()+" | Director: "+Theater3.getMovie().getdir());
    this->ui->theater4->setText("Name: "+Theater4.getMovie().getname()+" | Genre: "+ Theater4.getMovie().getgenre()+" | Director: "+Theater4.getMovie().getdir());
}


void UserInterface::on_back_clicked()
{
    this->ui->BOOK->setHidden(true);
    this->ui->MOVIES->setHidden(true);
    this->ui->welcome->setHidden(false);
    this->ui->theater1->setHidden(true);
    this->ui->theater2->setHidden(true);
    this->ui->theater3->setHidden(true);
    this->ui->theater4->setHidden(true);
    this->ui->back->setHidden(true);
    this->ui->welcome->setHidden(false);
    this->ui->Exit->setHidden(false);
    this->ui->Movies->setHidden(false);
    this->ui->Search->setHidden(false);
    this->ui->BookTickets->setHidden(false);
    this->ui->book->setHidden(true);
    this->ui->comboBox->setHidden(true);
    this->ui->whichtheater->setHidden(true);
    this->ui->howmany->setHidden(true);
    this->ui->howmanytickets->setHidden(true);
    this->ui->remain->setHidden(true);
    this->ui->SearchButton->setHidden(true);
    this->ui->comboBox_2->setHidden(true);
    this->ui->searchobject->setHidden(true);
    this->ui->textBrowser->setHidden(true);
    this->ui->searchobject_2->setHidden(true);
    this->ui->searchline->setHidden(true);
    this->ui->showremain->setHidden(true);
    this->ui->textBrowser_2->setHidden(true);
    this->ui->history->setHidden(false);
}


void UserInterface::on_BookTickets_clicked()
{
    this->ui->BOOK->setHidden(false);
    this->ui->history->setHidden(true);
    this->ui->MOVIES->setHidden(true);
    this->ui->welcome->setHidden(true);
    this->ui->Exit->setHidden(true);
    this->ui->Movies->setHidden(true);
    this->ui->BookTickets->setHidden(true);
    this->ui->back->setHidden(false);
    this->ui->book->setHidden(true);
    this->ui->showremain->setHidden(false);
    this->ui->comboBox->setHidden(false);
    this->ui->whichtheater->setHidden(false);

    this->ui->Search->setHidden(true);

}


void UserInterface::on_book_clicked()
{

    int current=this->ui->comboBox->currentText().toInt();
    if(this->ui->howmany->text()=="" || this->ui->howmany->text()==" ")
        QMessageBox::StandardButton reply=QMessageBox::information(this,"title","you have to say the number of tickets you want");
    else{
    QFile booked("Booked.txt");
    QTextStream in(&booked);
    booked.open(QFile::ReadOnly);
    int tickets[4];
    for(int i=0;i<4;i++){
        in>>tickets[i];
    }
    booked.close();
    if(this->ui->comboBox->currentText()==""){
        QMessageBox::StandardButton reply=QMessageBox::information(this,"title","you have to choose a theater");
    }
    else if(this->ui->howmany->text().toInt()>15-tickets[current-1]){
        QMessageBox::StandardButton reply=QMessageBox::information(this,"title","not this many tickets availible");
    }
    else{
        tickets[current-1]+=this->ui->howmany->text().toInt();
        booked.open(QFile::WriteOnly);
        for(int i=0;i<4;i++){
            in<<tickets[i];
            in<<"\n";
        }
        booked.close();
        QMessageBox::StandardButton reply=QMessageBox::information(this,"title","we booked your tickets for you");
        this->ui->remain->setText(QString::number(15-tickets[current-1])+" tickets are left");
        QFile log("Log.txt");
        log.open(QFile::ReadOnly);
        QTextStream inlog(&log);
        QString user;
        inlog>>user;
        log.close();
        log.open(QFile::Append);
        inlog<<user+" booked ";
        inlog<<QString::number(tickets[current-1])+" tickets in theater "+QString::number(current)+"\n";
        log.close();
    }
    }

}


void UserInterface::on_showremain_clicked()
{
    QFile movienames("Names.txt");
    movienames.open(QFile::ReadOnly);
    QTextStream inname(&movienames);
    QString names[4];

    for(int i=0;i<3;i++)
        names[i]=inname.readLine();
    int current=this->ui->comboBox->currentText().toInt();
    if(names[current-1]==" "){
       QMessageBox::StandardButton reply=QMessageBox::information(this,"title","there is no movie in that theater");
    }
    else if(this->ui->comboBox->currentText()==""){
        QMessageBox::StandardButton reply=QMessageBox::information(this,"title","you have to choose a theater");
    }
    else{
        this->ui->remain->setHidden(false);
        QFile book("Booked.txt");
        book.open(QFile::ReadOnly);
        QTextStream in(&book);
        int tick[4];
        int current=this->ui->comboBox->currentText().toInt();
        for(int i=0;i<4;i++)
            in>>tick[i];
        this->ui->remain->setText(QString::number(15-tick[current-1])+" tickets are left");
        book.close();
        this->ui->showremain->setHidden(true);
        this->ui->book->setHidden(false);
        this->ui->howmany->setHidden(false);
        this->ui->howmanytickets->setHidden(false);
    }

}


void UserInterface::on_Search_clicked()
{
    this->ui->MOVIES->setHidden(true);
    this->ui->history->setHidden(true);
    this->ui->welcome->setHidden(true);
    this->ui->Exit->setHidden(true);
    this->ui->Movies->setHidden(true);
    this->ui->BookTickets->setHidden(true);
    this->ui->back->setHidden(false);
    this->ui->SearchButton->setHidden(false);
    this->ui->comboBox_2->setHidden(false);
    this->ui->searchobject->setHidden(false);
    this->ui->textBrowser->setHidden(false);
    this->ui->searchobject_2->setHidden(false);
    this->ui->searchline->setHidden(false);
    this->ui->Search->setHidden(true);
}


void UserInterface::on_SearchButton_clicked()
{
    theater Theater1;
    getmovies(Theater1,1);
    theater Theater2;
    getmovies(Theater2,2);
    theater Theater3;
    getmovies(Theater3,3);
    theater Theater4;
    getmovies(Theater4,4);

    QString searchmethod=this->ui->comboBox_2->currentText();
    QString line=this->ui->searchline->text();
    if(searchmethod==""){
        QMessageBox::StandardButton reply=QMessageBox::information(this,"title","you have to choose a search method");
    }
    else if(searchmethod=="by name"){
        if(line==Theater1.getMovie().getname())
            this->ui->textBrowser->append("Theater1, Name: "+Theater1.getMovie().getname()+" genre: "+Theater1.getMovie().getname()+" director: "+Theater1.getMovie().getdir());
        else if(line==Theater2.getMovie().getname())
            this->ui->textBrowser->append("Theater2, Name: "+Theater2.getMovie().getname()+" genre: "+Theater2.getMovie().getname()+" director: "+Theater2.getMovie().getdir());
        else if(line==Theater3.getMovie().getname())
            this->ui->textBrowser->append("Theater3, Name: "+Theater3.getMovie().getname()+" genre: "+Theater3.getMovie().getname()+" director: "+Theater3.getMovie().getdir());
        else if(line==Theater4.getMovie().getname())
            this->ui->textBrowser->append("Theater4, Name: "+Theater4.getMovie().getname()+" genre: "+Theater4.getMovie().getname()+" director: "+Theater4.getMovie().getdir());
        else
            this->ui->textBrowser->setText("No Movies found");
    }
    else if(searchmethod=="by genre"){
        if(line==Theater1.getMovie().getgenre())
            this->ui->textBrowser->append("Theater1, Name: "+Theater1.getMovie().getname()+" genre: "+Theater1.getMovie().getname()+" director: "+Theater1.getMovie().getdir());
        else if(line==Theater2.getMovie().getgenre())
            this->ui->textBrowser->append("Theater2, Name: "+Theater2.getMovie().getname()+" genre: "+Theater2.getMovie().getname()+" director: "+Theater2.getMovie().getdir());
        else if(line==Theater3.getMovie().getgenre())
            this->ui->textBrowser->append("Theater3, Name: "+Theater3.getMovie().getname()+" genre: "+Theater3.getMovie().getname()+" director: "+Theater3.getMovie().getdir());
        else if(line==Theater4.getMovie().getgenre())
            this->ui->textBrowser->append("Theater4, Name: "+Theater4.getMovie().getname()+" genre: "+Theater4.getMovie().getname()+" director: "+Theater4.getMovie().getdir());
        else
            this->ui->textBrowser->setText("No Movies found");
    }
    else{
        if(line==Theater1.getMovie().getdir())
            this->ui->textBrowser->append("Theater1, Name: "+Theater1.getMovie().getname()+" genre: "+Theater1.getMovie().getname()+" director: "+Theater1.getMovie().getdir());
        else if(line==Theater2.getMovie().getdir())
            this->ui->textBrowser->append("Theater2, Name: "+Theater2.getMovie().getname()+" genre: "+Theater2.getMovie().getname()+" director: "+Theater2.getMovie().getdir());
        else if(line==Theater3.getMovie().getdir())
            this->ui->textBrowser->append("Theater3, Name: "+Theater3.getMovie().getname()+" genre: "+Theater3.getMovie().getname()+" director: "+Theater3.getMovie().getdir());
        else if(line==Theater4.getMovie().getdir())
            this->ui->textBrowser->append("Theater4, Name: "+Theater4.getMovie().getname()+" genre: "+Theater4.getMovie().getname()+" director: "+Theater4.getMovie().getdir());
        else
            this->ui->textBrowser->setText("No Movies found");
    }


}


void UserInterface::on_history_clicked()
{
    this->ui->MOVIES->setHidden(true);
    this->ui->welcome->setHidden(true);
    this->ui->Exit->setHidden(true);
    this->ui->Movies->setHidden(true);
    this->ui->BOOK->setHidden(true);
    this->ui->BookTickets->setHidden(true);
    this->ui->Search->setHidden(true);
    this->ui->back->setHidden(false);
    this->ui->textBrowser_2->setHidden(false);
    QFile log("Log.txt");
    log.open(QFile::ReadOnly);
    QTextStream in(&log);
    QString note=in.readAll();
    this->ui->textBrowser_2->setText(note);
}

