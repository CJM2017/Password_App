#include "page_1.h"
#include "ui_page_1.h"

#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QDebug>

Page_1::Page_1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Page_1)
{
    ui->setupUi(this);
}

Page_1::~Page_1()
{
    delete ui;
}

void Page_1::on_pushButton_Generate_clicked()
{
    if(letters || numbers)                                      // This is used to prevent generation when nothing is selcted
    {
    myPassword.buildPassword();
    result = myPassword.password;
    ui->lineEdit_display_password->setText(result);
    ui->lineEdit_display_password->setAlignment(Qt::AlignHCenter);
    accountName = ui->lineEdit_account_name->text();
    username = ui->lineEdit_username->text();
    myPassword.password = "";
/*    myPassword.letters = false;
    myPassword.numbers = false;*/                                // RESET the parameters
    myPassword.table.clear();
    cout << "generated clicked"<< endl;
    }
}

void Page_1::on_horizontalSlider_valueChanged(int value)
{
    myPassword.passwordLength = value;
}


void Page_1::on_checkBox_Letters_stateChanged(int arg1)
{
    if(arg1 > 0)
    {
        myPassword.letters = true;
        letters = true;
    }
    else
    {
        myPassword.letters = false;
        letters = false;
    }

}

void Page_1::on_checkBox_Numbers_stateChanged(int arg1)
{
    if(arg1 > 0)
    {
        myPassword.numbers = true;
        numbers = true;
    }
    else
    {
        myPassword.numbers = false;
        numbers = false;
    }
}

void Page_1::on_pushButton_Logout_clicked()
{
    bool goBack = true;
    emit send_back_signal1(goBack);
    this->deleteLater();
}

void Page_1::on_pushButton_save_password_clicked()
{
    cout << "pushed button" << endl;
    QString account = ui->lineEdit_account_name_2->text();
    QString user = ui->lineEdit_username->text();
    QString passcode = ui->lineEdit_display_password->text();
    QString filename = "passwords.txt";
    QFile file(filename);
   if(!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
   {
       QMessageBox::warning(this,"error","File not opened");
   }
    QTextStream out(&file);
    out << account << "," << user << "," << passcode << endl;
    file.close();
}

void Page_1::on_pushButton_view_passwords_clicked()
{
   second = new Page_2(this);
   second->show();
   hide();
}
