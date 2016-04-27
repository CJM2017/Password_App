#ifndef PAGE_1_H
#define PAGE_1_H

#include <QDialog>
#include <string>
#include <map>
#include "password.h"
#include "page_2.h"

namespace Ui {
class Page_1;
}

class Page_1 : public QDialog
{
    Q_OBJECT

public:
    explicit Page_1(QWidget *parent = 0);
    ~Page_1();

public slots:
    void receive_button_status2(bool&);

private slots:

    void on_pushButton_Generate_clicked();

    void on_horizontalSlider_valueChanged(int value);

    void on_checkBox_Letters_stateChanged(int arg1);

    void on_checkBox_Numbers_stateChanged(int arg1);

    void on_pushButton_Logout_clicked();

    void on_pushButton_save_password_clicked();

    void on_pushButton_view_passwords_clicked();

    void on_checkBox_chars_stateChanged(int arg1);

signals:
    void send_back_signal1(bool&);

public:
    Ui::Page_1 *ui;
    password_one myPassword;
    QString accountName;
    QString username;
    QString result;
    map<pair<string,string>, string> dictionary;
    bool letters = false;
    bool numbers = false;
    bool characters = false;
private:
    Page_2 *second;

};

#endif // PAGE_1_H
