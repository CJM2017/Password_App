#include "page_2.h"
#include "ui_page_2.h"
#include <QStandardItemModel>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QList>

Page_2::Page_2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Page_2)
{
    ui->setupUi(this);

  // QStandardItemModel *model = new QStandardItemModel();
   model->setRowCount(0);
   ui->LoadPasswords->setModel(model);

   QString filename = "passwords.txt";
   QFile file(filename);
   if(!file.open(QIODevice::ReadOnly)) {
       QMessageBox::information(0,"error",file.errorString());
   }
   QTextStream in(&file);

   while(!in.atEnd()){
       QString line = in.readLine();
       qDebug() << line;
       QStringList fields = line.split(",");
       qDebug() << fields;
       QList<QStandardItem *> list;
       QStandardItem *app = new QStandardItem(fields.at(0));
       QStandardItem *user = new QStandardItem(fields.at(1));
       QStandardItem *passcode = new QStandardItem(fields.at(2));
       list.append(app);
       list.append(user);
       list.append(passcode);
      // qDebug() << item1->text();
       model->setHeaderData(0,Qt::Horizontal,QObject::tr("Account"));
       model->setHeaderData(1,Qt::Horizontal,QObject::tr("Username"));
       model->setHeaderData(2,Qt::Horizontal,QObject::tr("Password"));
       model->appendRow(list);
   }
   file.close();
}

Page_2::~Page_2()
{
    delete ui;
}

void Page_2::on_pushButton_clear_pws_clicked()
{
    QString filename = "passwords.txt";
    QFile file(filename);
    file.remove();
    model->clear();
}
