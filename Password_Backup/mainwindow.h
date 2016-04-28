#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "page_1.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow                       // Class for the Main Window Ui
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);               // The constructor
    ~MainWindow();                                          // The Destructor

private slots:
    void on_pushButton_clicked();                           // Login
    void on_pushButton_2_clicked();                         // Info Button
    void on_pushButton_close_clicked();                     // Allows user to exit the program

public slots:
    void receive_back_button1(bool&);                       // Receive signal from Page_1 to display current page

private:
    Ui::MainWindow *ui;                                     // Pointer to the object of this class
    Page_1 *first;                                          // Pointer to the first page (follows this login creen)
};

#endif // MAINWINDOW_H
