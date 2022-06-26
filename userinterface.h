#ifndef USERINTERFACE_H
#define USERINTERFACE_H
#include <QDialog>

namespace Ui {
class UserInterface;
}

class UserInterface : public QDialog
{
    Q_OBJECT

public:
    explicit UserInterface(QWidget *parent = nullptr);
    ~UserInterface();

private slots:
    void on_Exit_clicked();

    void on_Movies_clicked();

    void on_back_clicked();

    void on_BookTickets_clicked();

    void on_book_clicked();

    void on_showremain_clicked();

    void on_Search_clicked();

    void on_SearchButton_clicked();

    void on_history_clicked();

private:
    Ui::UserInterface *ui;
};

#endif // USERINTERFACE_H
