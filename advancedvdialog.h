#ifndef ADVANCEDVDIALOG_H
#define ADVANCEDVDIALOG_H

#include "string.h"
#include <QDialog>

extern std::string genre;
extern std::string sty;
extern int saturation;

namespace Ui {
class advancedVDialog;
}

class advancedVDialog : public QDialog
{
    Q_OBJECT

public:
    explicit advancedVDialog(QWidget *parent = nullptr);
    ~advancedVDialog();

private slots:
    void on_adokButton_clicked();

    void on_adcancelButton_clicked();

    void on_saturationSlider_valueChanged(int value);

    void on_saturationspinBox_valueChanged(int);

private:
    Ui::advancedVDialog *ui;
};

#endif // ADVANCEDVDIALOG_H
