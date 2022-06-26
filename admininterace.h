#ifndef ADMININTERACE_H
#define ADMININTERACE_H

#include <QDialog>

namespace Ui {
class AdminInterace;
}

class AdminInterace : public QDialog
{
    Q_OBJECT

public:
    explicit AdminInterace(QWidget *parent = nullptr);
    ~AdminInterace();

private slots:

    void on_addorder_clicked();

    void on_Exit_clicked();

    void on_removeorder_clicked();

    void on_addnewmovie_clicked();

    void on_Back_clicked();

    void on_removethismovie_clicked();

    void on_showmovies_clicked();

private:
    Ui::AdminInterace *ui;
};

#endif // ADMININTERACE_H
