#include "mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QApplication>


int main(int argc, char *argv[])
{
    QFile file("UserData.txt");
    file.open(QFile::ReadOnly);
    qint64 filesize=file.size();
    file.close();
    if(filesize==0){
        file.open(QFile::WriteOnly);
        QTextStream in(&file);
        in<<"1\n";
        in<<"admin ";
        in<<"admin ";
        in<<"none\n";
        file.close();
    }
    QFile myfile("Booked.txt");
    myfile.open(QFile::ReadOnly);
    qint64 size=myfile.size();
    myfile.close();
    if(size==0){
        myfile.open(QFile::WriteOnly);
        QTextStream out(&myfile);
        out<<"0\n";
        out<<"0\n";
        out<<"0\n";
        out<<"0";
        file.close();
    }
    QFile names("Names.txt");
    names.open(QFile::ReadOnly);
    qint64 namesize=names.size();
    names.close();
    if(namesize==0){
        names.open(QFile::WriteOnly);
        QTextStream inname(&names);
        for(int i=0;i<4;i++){
            if(i==3){
                inname<<" ";
                break;
            }
            inname<<" \n";
        }
        names.close();
    }
    QFile genres("Genres.txt");
    genres.open(QFile::ReadOnly);
    qint64 genresize=genres.size();
    genres.close();
    if(genresize==0){
        genres.open(QFile::WriteOnly);
        QTextStream ingenre(&genres);
        for(int i=0;i<4;i++){
            if(i==3){
                ingenre<<" ";
                break;
            }
            ingenre<<" \n";
        }
        genres.close();
    }
    QFile directors("Directors.txt");
    directors.open(QFile::ReadOnly);
    qint64 dirsize=directors.size();
    directors.close();
    if(dirsize==0){
        directors.open(QFile::WriteOnly);
        QTextStream indirs(&directors);
        for(int i=0;i<4;i++){
            if(i==3){
                indirs<<" ";
                break;
            }
            indirs<<" \n";
        }
        directors.close();
    }
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
