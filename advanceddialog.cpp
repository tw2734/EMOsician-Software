#include "advanceddialog.h"
#include "ui_advanceddialog.h"
#include <QMessageBox>
#include <iostream>
#include <QSlider>
#include <QSpinBox>

using namespace std;


advancedDialog::advancedDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::advancedDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Advanced Version");
}




advancedDialog::~advancedDialog()
{
    delete ui;
}


void advancedDialog::on_saturationSlider_valueChanged(int value)
{
    ui->saturationSlider->setRange(1,10);

}


    //信号与槽连接
    //QObject::connect(spinBox, SIGNAL(valueChanged(int)), slider, SLOT(setValue(int)));  //连接spinbox和slider
    //QObject::connect(slider, SIGNAL(valueChanged(int)), spinBox, SLOT(setValue(int)));  //连接spinbox和slider

void advancedDialog::on_saturationspinBox_valueChanged(int arg1)
{
    ui->saturationspinBox->setRange(1,10);
    ui->saturationspinBox->setSingleStep(1);
}


string ademotion;
string genre;
string sty;
int saturation;

void advancedDialog::on_adokButton_clicked()
{
    if (ui -> adhappyButton -> isChecked()) {
       ademotion = "happy";
    }
    else if (ui -> adexcitedButton -> isChecked()) {
       ademotion = "excited";
    }
    else if (ui -> adrelaxedButton -> isChecked()) {
       ademotion = "relaxed";
    }
    else if (ui -> adlonelyButton -> isChecked()) {
       ademotion = "lonely";
    }
    else if (ui -> adnervousButton -> isChecked()) {
       ademotion = "nervous";
    }
    else if (ui -> adblueButton -> isChecked()) {
       ademotion = "blue";
    }
    else if (ui -> adsadButton -> isChecked()) {
       ademotion = "sad";
    }
    else {
        QMessageBox::information(this,"Warning","ERROR");
    }

    if (ui -> popButton -> isChecked()) {
       genre = "pop";
    }
    else if (ui -> rockButton -> isChecked()) {
       genre = "rock";
    }
    else if (ui -> metalButton -> isChecked()) {
       genre = "metal";
    }
    else if (ui -> jazzButton -> isChecked()) {
       genre = "jazz";
    }
    else if (ui -> classicalButton -> isChecked()) {
       genre = "classical";
    }
    else if (ui -> folkButton -> isChecked()) {
       genre = "folk";
    }
    else if (ui -> electronicButton -> isChecked()) {
       genre = "electronic";
    }
    else {
        QMessageBox::information(this,"Warning","ERROR");
    }

    if (ui -> quietButton -> isChecked()) {
       sty = "quiet";
    }
    else if (ui -> energeticButton -> isChecked()) {
       sty = "energetic";
    }
    else if (ui -> loudButton -> isChecked()) {
       sty = "loud";
    }
    else if (ui -> complexButton -> isChecked()) {
       sty = "complex";
    }
    else {
        QMessageBox::information(this,"Warning","ERROR");
    }

    saturation = ui->saturationSlider->value();

    this->close();
}

void advancedDialog::on_adcancelButton_clicked()
{
    this->close();
}



