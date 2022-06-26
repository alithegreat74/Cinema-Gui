#ifndef SIGNUPPAGE_H
#define SIGNUPPAGE_H
#include <QDialog>


namespace Ui {
class SignUpPage;
}

class SignUpPage : public QDialog
{
    Q_OBJECT

public:
    explicit SignUpPage(QWidget *parent = nullptr);
    ~SignUpPage();

private slots:
    void on_signup_clicked();

private:
    Ui::SignUpPage *ui;
};

#endif // SIGNUPPAGE_H
