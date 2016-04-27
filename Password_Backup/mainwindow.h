#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "page_1.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

public slots:
    void receive_back_button1(bool&);

private:
    Ui::MainWindow *ui;
    Page_1 *first;
};

#endif // MAINWINDOW_H
