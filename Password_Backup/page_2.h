#ifndef PAGE_2_H
#define PAGE_2_H

#include <QDialog>
#include <QStandardItemModel>

namespace Ui {
class Page_2;
}

class Page_2 : public QDialog
{
    Q_OBJECT

public:
    explicit Page_2(QWidget *parent = 0);
    ~Page_2();

private slots:
    void on_pushButton_clear_pws_clicked();                             // Deletes the password file
    void on_pushButton_last_back_clicked();                             // Back button to take us back to the password generation page
    void on_pushButton_close_p3_clicked();                              // Allows user to exit the program

signals:
    void send_button_status2(bool&);                                    // Used to signal to the previous page that we want to go back

private:
    Ui::Page_2 *ui;
    QStandardItemModel *model = new QStandardItemModel();
};

#endif // PAGE_2_H
