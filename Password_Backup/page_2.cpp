#include "page_2.h"
#include "ui_page_2.h"
#include <QStandardItemModel>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QList>
#include <QDesktopWidget>
#include <QRect>

Page_2::Page_2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Page_2)
{
    ui->setupUi(this);
    const QRect screen = QApplication::desktop()->screenGeometry();                     // Sets the window to the center of our screen
    this->move(screen.center()- this->rect().center());
    model->setRowCount(0);
    ui->LoadPasswords->setModel(model);

   QString filename = "passwords.txt";                                                  // This allows us to setup a file to save passwords in the constructor of the second page class
   QFile file(filename);
   if(!file.open(QIODevice::ReadOnly))
   {
       QMessageBox msgBox;
       msgBox.setStyleSheet("QMessageBox { background-color: rgb(255,255,255) }");
       msgBox.setText("Error: No File Detected");
       msgBox.setIcon(QMessageBox::Warning);
       hide();
       msgBox.exec();
       show();
   }
   QTextStream in(&file);

   while(!in.atEnd()){
       QString line = in.readLine();
       qDebug() << line;
       QStringList fields = line.split(",");
       qDebug() << fields;
       QList<QStandardItem *> list;
       QStandardItem *app = new QStandardItem(fields.at(0));                            // Reads the file into a tableview to be displayed on this page
       QStandardItem *user = new QStandardItem(fields.at(1));
       QStandardItem *passcode = new QStandardItem(fields.at(2));
       list.append(app);
       list.append(user);                                                               // Appends the file
       list.append(passcode);
       model->appendRow(list);
   }
   model->setHeaderData(0,Qt::Horizontal,QObject::tr("Account"));                       // Sets the category of each row to be displayed on this page
   model->setHeaderData(1,Qt::Horizontal,QObject::tr("Username"));
   model->setHeaderData(2,Qt::Horizontal,QObject::tr("Password"));
   file.close();
}

Page_2::~Page_2()
{
    delete ui;
}

//===============================================================
//                        Button Methods
//===============================================================

void Page_2::on_pushButton_clear_pws_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this,"",
                                  "Click yes to delete all passwords",
                                  QMessageBox::No | QMessageBox::Yes);
    if(reply == QMessageBox::Yes)                                                           // Clears our file and table view if yes is selected on our toggle message box
    {
        QString filename = "passwords.txt";
        QFile file(filename);
        file.remove();
        model->clear();
    }
}

void Page_2::on_pushButton_last_back_clicked()                                              // Deletes this page and emits a signal back to Page_1 when the back button pressed
{
    bool goBack = true;
    emit send_button_status2(goBack);
    this->deleteLater();
}

void Page_2::on_pushButton_close_p3_clicked()
{
    qApp->quit();
}
