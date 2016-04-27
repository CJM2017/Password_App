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
    const QRect screen = QApplication::desktop()->screenGeometry();
    this->move(screen.center()- this->rect().center());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString username = ui->lineEdit_Username->text();
    QString password = ui->lineEdit_Password->text();
    if(username == "test" && password == "1234")
    {
        first = new Page_1(this);
        connect(first,SIGNAL(send_back_signal1(bool&)),this,SLOT(receive_back_button1(bool&)));
        first->show();
        hide();
    }
    else
    {
        QMessageBox::warning(this,"Logion","Username and password incorrect");              // Function
    }
}

void MainWindow::receive_back_button1(bool &status)
{
    if(status)
    {
        ui->lineEdit_Password->setText("");
        ui->lineEdit_Username->setText("");
        this->show();
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    QMessageBox::information(this,"About","This app has been designed by Dan F., "
                                          "Than T. and Connor M. to provide the end user with a "
                                          "simple method for generating and storing secure passwords");

}
