#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString username = ui->lineEdit_Username->text();
    QString password = ui->lineEdit_Password->text();
    if(username == "" && password == "")
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
        this->show();
    }
}
