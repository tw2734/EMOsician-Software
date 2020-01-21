#ifndef STANDARDDIALOG_H
#define STANDARDDIALOG_H

#include <QDialog>
#include <iostream>
#include <string>
#include "advancedvdialog.h"


using namespace std;

extern std::string emotion;

namespace Ui {
class standardDialog;
}

class standardDialog : public QDialog
{
    Q_OBJECT

public:
    explicit standardDialog(QWidget *parent = nullptr);
    ~standardDialog();


private slots:
    void on_okButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::standardDialog *ui;
};

#endif // STANDARDDIALOG_H
