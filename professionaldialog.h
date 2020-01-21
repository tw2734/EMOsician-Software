#ifndef PROFESSIONALDIALOG_H
#define PROFESSIONALDIALOG_H

#include <QDialog>
#include <vector>
#include <string>

extern std::vector<int> tp;
extern double dy;
extern std::string instrument;
extern int tempo;
extern int melody;

namespace Ui {
class professionalDialog;
}

class professionalDialog : public QDialog
{
    Q_OBJECT

public:
    explicit professionalDialog(QWidget *parent = nullptr);
    ~professionalDialog();

private slots:
    void on_tempoSlider_valueChanged(int value);

    void on_tempospinBox_valueChanged(int arg1);

    void on_prookButton_clicked();

    void on_procancelButton_clicked();

private:
    Ui::professionalDialog *ui;
};

#endif // PROFESSIONALDIALOG_H
