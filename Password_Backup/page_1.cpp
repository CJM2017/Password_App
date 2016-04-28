#include "page_1.h"
#include "ui_page_1.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QDesktopWidget>
#include <QRect>

Page_1::Page_1(QWidget *parent) :                                                       // Page 1 constructor
    QDialog(parent),
    ui(new Ui::Page_1)
{
    ui->setupUi(this);
    const QRect screen = QApplication::desktop()->screenGeometry();                     // Centers the dialog window
    this->move(screen.center()- this->rect().center());
}

Page_1::~Page_1()
{
    delete ui;
}

void Page_1::on_pushButton_Generate_clicked()
{
    if(numbers && !letters && !characters)                                              // Generate password when only numbers selected
    {
        myPassword.buildNumPassword();                                                  // Password class method to build the password with class methods
        ui->lineEdit_display_password->setText(myPassword.password);
        ui->lineEdit_display_password->setAlignment(Qt::AlignHCenter);
        accountName = ui->lineEdit_account_name->text();
        username = ui->lineEdit_username->text();
        myPassword.password = "";                                                       // Resets the password string
    }
    else if(!(letters && !numbers && characters)
                && !(!letters && numbers && characters)
                && !(!letters && !numbers && characters)
                && !(!letters && !numbers && !characters))                              // This is used to prevent generation when nothing is selcted
    {
    myPassword.buildPassword();
    ui->lineEdit_display_password->setText(myPassword.password);
    ui->lineEdit_display_password->setAlignment(Qt::AlignHCenter);
    accountName = ui->lineEdit_account_name->text();
    username = ui->lineEdit_username->text();
    myPassword.password = "";
    myPassword.table.clear();                                                           // Resets the password table for generation
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setStyleSheet("QMessageBox { background-color: rgb(255,255,255) }");
        msgBox.setText("Error: Invalid Password Type");
        msgBox.setIcon(QMessageBox::Warning);
        hide();
        msgBox.exec();
        show();
    }
    myPassword.calcStrength();                                                          // Calculates the strength of the password as a password class method
    ui->progressBar->setValue(myPassword.strength);
}

void Page_1::on_horizontalSlider_valueChanged(int value)
{
    myPassword.passwordLength = value;
}

void Page_1::on_checkBox_Letters_stateChanged(int arg1)                                 // For all of these we set boolean variables in this page class and the password class to interpret users parameter selection
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

void Page_1::on_pushButton_Logout_clicked()                                                 // Logout back button takes user to the login screen
{
    bool goBack = true;
    emit send_back_signal1(goBack);
    this->deleteLater();
}

void Page_1::on_pushButton_save_password_clicked()                                          // Save password push button methods
{
    QString account = ui->lineEdit_account_name_2->text();
    QString user = ui->lineEdit_username->text();
    QString passcode = ui->lineEdit_display_password->text();
    QString filename = "passwords.txt";
    QFile file(filename);
if(account != ""  && user !="" && passcode !="")
 {
   if(!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
   {
       QMessageBox msgBox;
       msgBox.setStyleSheet("QMessageBox { background-color: rgb(255,255,255) }");
       msgBox.setText("Error: File not opened");
       msgBox.setIcon(QMessageBox::Warning);
       hide();
       msgBox.exec();
       show();
   }
       QTextStream out(&file);
       QMessageBox msgBox;
       msgBox.setStyleSheet("QMessageBox { background-color: rgb(255,255,255) }");
       msgBox.setText("Password Saved");
       msgBox.setIcon(QMessageBox::Information);
       hide();
       msgBox.exec();
       show();
       out << account << "," << user << "," << passcode << endl;
    }
    else
    {
        QMessageBox msgBox;
        msgBox.setStyleSheet("QMessageBox { background-color: rgb(255,255,255) }");
        msgBox.setText("Error: Empty Field");
        msgBox.setIcon(QMessageBox::Warning);
        hide();
        msgBox.exec();
        show();
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

void Page_1::receive_button_status2(bool &status)                                               // This receives the back button request from Page_2
{
    if(status)
    {
        ui->lineEdit_account_name_2->setText("");
        ui->lineEdit_username->setText("");
        this->show();
    }
}

void Page_1::on_pushButton_close_P1_clicked()
{
    qApp->quit();
}
