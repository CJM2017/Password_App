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
    void on_pushButton_clear_pws_clicked();

private:
    Ui::Page_2 *ui;
    QStandardItemModel *model = new QStandardItemModel();
};

#endif // PAGE_2_H
