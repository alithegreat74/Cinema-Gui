#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "signuppage.h"
#include "userinterface.h"
#include "forgotmypassword.h"
#include "admininterace.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_Signup_clicked();

    void on_Signin_clicked();

    void on_forgotpassword_clicked();

private:
    Ui::MainWindow *ui;
    SignUpPage signup;
    UserInterface *userinterface;
    forgotmypassword forgot;
    AdminInterace *admin;


};
#endif // MAINWINDOW_H
