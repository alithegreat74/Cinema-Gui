#ifndef FORGOTMYPASSWORD_H
#define FORGOTMYPASSWORD_H

#include <QDialog>

namespace Ui {
class forgotmypassword;
}

class forgotmypassword : public QDialog
{
    Q_OBJECT

public:
    explicit forgotmypassword(QWidget *parent = nullptr);
    ~forgotmypassword();

private slots:
    void on_OK_clicked();

    void on_chagepass_clicked();

private:
    Ui::forgotmypassword *ui;
};

#endif // FORGOTMYPASSWORD_H
