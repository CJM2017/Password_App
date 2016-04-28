#include "mainwindow.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QScreen>

int main(int argc, char *argv[])
{
    srand(time(NULL));                              // Used for the random number generator
    QApplication a(argc, argv);                     // Creates the Main Application
    MainWindow w;                                   // Creates the Main Window
    w.show();                                       // Shows the Main Window
    qApp->setQuitOnLastWindowClosed(false);         // Prevents the QMessageBoxes from quitting the program
    return a.exec();
}
