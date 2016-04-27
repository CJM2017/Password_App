#include "page_1.h"
#include "ui_page_1.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QDesktopWidget>
#include <QRect>

Page_1::Page_1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Page_1)
{
    ui->setupUi(this);
    const QRect screen = QApplication::desktop()->screenGeometry();
    this->move(screen.center()- this->rect().center());
}

Page_1::~Page_1()
{
    delete ui;
}

void Page_1::on_pushButton_Generate_clicked()
{
    if(numbers && !letters && !characters)
    {
        myPassword.buildNumPassword();
        result = myPassword.password;
        ui->lineEdit_display_password->setText(result);
        ui->lineEdit_display_password->setAlignment(Qt::AlignHCenter);
        accountName = ui->lineEdit_account_name->text();
        username = ui->lineEdit_username->text();
        myPassword.password = "";
    }
    else if(!(letters && !numbers && characters)
                && !(!letters && numbers && characters)
                && !(!letters && !numbers && characters)
                && !(!letters && !numbers && !characters))                                      // This is used to prevent generation when nothing is selcted
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
    else
    {
        QMessageBox::warning(this,"Error","Invalid Password Type");
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

void Page_1::on_checkBox_chars_stateChanged(int arg1)
{
    if(arg1 > 0)
    {
        myPassword.characters = true;
        characters = true;
    }
    else
    {
        myPassword.characters = false;
        characters = false;
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
    if(account != ""  && user !="" && passcode !="")
    {
       QMessageBox::information(this,"Message","Password Saved");
       out << account << "," << user << "," << passcode << endl;
    }
    else
    {
        QMessageBox::warning(this,"Error","Empty Field");
    }
    file.close();
}

void Page_1::on_pushButton_view_passwords_clicked()
{
   second = new Page_2(this);
   connect(second,SIGNAL(send_button_status2(bool&)),this,SLOT(receive_button_status2(bool&)));
   second->show();
   hide();
}

void Page_1::receive_button_status2(bool &status)
{
    if(status)
    {
        ui->lineEdit_account_name_2->setText("");
        ui->lineEdit_username->setText("");
        this->show();
    }
}

