#ifndef PAGE_1_H
#define PAGE_1_H

#include <QDialog>
#include <string>
#include <map>
#include "password.h"
#include "page_2.h"

namespace Ui {
class Page_1;
}

class Page_1 : public QDialog
{
    Q_OBJECT

public:
    explicit Page_1(QWidget *parent = 0);
    ~Page_1();

public slots:
    void receive_button_status2(bool&);                         // Receives signal from Page_2

private slots:

    void on_pushButton_Generate_clicked();                      // Generate Button
    void on_horizontalSlider_valueChanged(int value);           // Horizontal slider for int value of password length
    void on_checkBox_Letters_stateChanged(int arg1);            // Check box button for letters
    void on_checkBox_Numbers_stateChanged(int arg1);            // Check box button for Numbers
    void on_pushButton_Logout_clicked();                        // Push button to log out
    void on_pushButton_save_password_clicked();                 // Push button to save the password
    void on_pushButton_view_passwords_clicked();                // Push button to see saved passwords
    void on_checkBox_chars_stateChanged(int arg1);              // Check box button for characters
    void on_pushButton_close_P1_clicked();                      // Allows user to exit the program

signals:
    void send_back_signal1(bool&);                              // received signal from page 2 to show itself (moving back)

private:
    Ui::Page_1 *ui;
    Page_2 *second;
    password_one myPassword;                                    // Instance of the password class in our page_1 class
    QString accountName;                                        // Name of the account you are generating the password for
    QString username;                                           // Username fot the account to be saved
    bool letters = false;
    bool numbers = false;
    bool characters = false;
};

#endif // PAGE_1_H
