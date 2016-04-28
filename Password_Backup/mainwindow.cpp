#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDesktopWidget>
#include <QWidget>
#include <QRect>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    const QRect screen = QApplication::desktop()->screenGeometry();                                     // Centers the screen on users window
    this->move(screen.center()- this->rect().center());
}

MainWindow::~MainWindow()
{
    delete ui;
}

//===============================================================
//                        Button Methods
//===============================================================

void MainWindow::on_pushButton_clicked()                                                                // Login button and method
{
    QString username = ui->lineEdit_Username->text();
    QString password = ui->lineEdit_Password->text();
    if(username == "test" && password == "1234")
    {
        first = new Page_1(this);                                                                       // Creates the next window
        connect(first,SIGNAL(send_back_signal1(bool&)),this,SLOT(receive_back_button1(bool&)));         // Connects theese two windows for back button communication
        first->show();
        hide();
    }
    else
    {
        QMessageBox msgBox;                                                                             // This is how we wrote all of the message boxes that help error check for the user
        msgBox.setStyleSheet("QMessageBox { background-color: rgb(255,255,255) }");
        msgBox.setText("Username and password incorrect");
        msgBox.setIcon(QMessageBox::Warning);
        hide();
        msgBox.exec();
        show();
    }
}

void MainWindow::receive_back_button1(bool &status)                                                     // The receive signal for the back button
{
    if(status)
    {
        ui->lineEdit_Password->setText("");
        ui->lineEdit_Username->setText("");
        this->show();                                                                                   // The next window is deleted and this window goes from hiding to bein shown
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    QMessageBox msgBox;
    msgBox.setStyleSheet("QMessageBox { background-color: rgb(255,255,255) }");
    msgBox.setText("This app has been designed by Dan F.,"
                   "Than T. and Connor M. to provide the end user with a "
                    "simple method for generating and storing secure passwords");
    msgBox.setIcon(QMessageBox::Information);
    hide();
    msgBox.exec();
    show();
}

void MainWindow::on_pushButton_close_clicked()
{
    qApp->quit();
}
