#include "advancedvdialog.h"
#include "ui_advancedvdialog.h"
#include <QMessageBox>
#include <iostream>
#include <QSlider>
#include <QSpinBox>
#include "variable.h"
#include <pcm_to_wav.h>
#include "mainwindow.h"

using namespace std;



advancedVDialog::advancedVDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::advancedVDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Advanced Version");
}

advancedVDialog::~advancedVDialog()
{
    delete ui;
}


void advancedVDialog::on_saturationSlider_valueChanged(int)
{
    ui->saturationSlider->setRange(1,9);
}



void advancedVDialog::on_saturationspinBox_valueChanged(int)
{
    ui->saturationspinBox->setRange(1,9);
    ui->saturationspinBox->setSingleStep(1);
}

string emotion;
string genre;
string sty;
int saturation;



void advancedVDialog::on_adokButton_clicked()
{
    if (ui -> adhappyButton -> isChecked()) {
       emotion = "happy";
    }
    else if (ui -> adexcitedButton -> isChecked()) {
       emotion = "excited";
    }
    else if (ui -> adrelaxedButton -> isChecked()) {
       emotion = "relaxed";
    }
    else if (ui -> adlonelyButton -> isChecked()) {
       emotion = "lonely";
    }
    else if (ui -> adnervousButton -> isChecked()) {
       emotion = "nervous";
    }
    else if (ui -> adblueButton -> isChecked()) {
       emotion = "blue";
    }
    else if (ui -> adsadButton -> isChecked()) {
       emotion = "sad";
    }
    else {
        QMessageBox::information(this,"Warning","ERROR");
        this->close();

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
        this->close();

    }

    if (ui -> quietButton -> isChecked()) {
       sty = "quiet";
    }
//    else if (ui -> energeticButton -> isChecked()) {
//       sty = "energetic";
//    }
//    else if (ui -> loudButton -> isChecked()) {
//       sty = "loud";
//    }
    else if (ui -> complexButton -> isChecked()) {
       sty = "complex";
    }
    else {
        QMessageBox::information(this,"Warning","ERROR");
        this->close();

    }

    saturation = ui->saturationSlider->value();

  // change in this place
    vector<Track> track_list;
    track_list = Advance(emotion,genre,saturation); //advance
    module5(track_list);

    this->close();
}

void advancedVDialog::on_adcancelButton_clicked()
{
     this->close();
}

