#include "professionaldialog.h"
#include "ui_professionaldialog.h"
#include <QMessageBox>
#include <iostream>
#include <QSlider>
#include <QSpinBox>
#include "variable.h"
#include <pcm_to_wav.h>
#include <mainwindow.h>

using namespace std;

professionalDialog::professionalDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::professionalDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Professional Version");
}

professionalDialog::~professionalDialog()
{
    delete ui;
}



void professionalDialog::on_tempoSlider_valueChanged(int)
{
     ui->tempoSlider->setRange(60,200);
}

void professionalDialog::on_tempospinBox_valueChanged(int)
{
    ui->tempospinBox->setRange(60,200);
    ui->tempospinBox->setSingleStep(1);
}


vector<int> tp;
double dy;
string instrument;
int tempo;
int melody;

void professionalDialog::on_prookButton_clicked()
{
    if (ui -> VCVCButton -> isChecked()) {
        tp = {4,5,2,3,4,5,2,3};
    }
    else if (ui -> VCVCEButton -> isChecked()) {
        tp = {4,5,2,3,4,5,2,3,8};
    }
    else if (ui -> VBCVBCButton -> isChecked()) {
        tp = {4,5,7,2,3,4,5,7,2,3};
    }
    else if (ui -> VBCVBCEButton -> isChecked()) {
        tp = {4,5,7,2,3,4,5,7,2,3,8};
    }
    else if (ui -> VBCVCButton -> isChecked()) {
        tp = {4,5,7,2,3,4,5,2,3};
    }
    else if (ui -> VBCVCEButton -> isChecked()) {
        tp = {4,5,7,2,3,4,5,2,3,8};
    }
    else if (ui -> VBCVAEButton -> isChecked()) {
        tp = {4,5,7,2,3,6,8};
    }
    else if (ui -> VBCVAVEButton -> isChecked()) {
        tp = {4,5,7,2,3,6,4,5,8};
    }
    else if (ui -> OCVBCButton -> isChecked()) {
        tp = {1,2,3,4,5,7,2,3};
    }
    else if (ui -> OCVBCEButton -> isChecked()) {
        tp = {1,2,3,4,5,7,2,3,8};
    }
    else if (ui -> OCVCEButton -> isChecked()) {
        tp = {1,2,3,4,5,2,3,8};
    }
    else if (ui -> OVBCVBCButton -> isChecked()) {
        tp = {1,4,5,7,2,3,4,5,7,2,3};
    }
    else if (ui -> OVBCVBCEButton -> isChecked()) {
        tp = {1,4,5,7,2,3,4,5,7,2,3,8};
    }
    else if (ui -> OVBCVCButton -> isChecked()) {
        tp = {1,4,5,7,2,3,4,5,2,3};
    }
    else if (ui -> OVBCVCEButton -> isChecked()) {
        tp = {1,4,5,7,2,3,4,5,2,3,8};
    }
    else if (ui -> OVBCVCVAEButton -> isChecked()) {
        tp = {1,4,5,7,2,3,4,5,2,3,6,8};
    }

    else {
        QMessageBox::information(this,"Warning","ERROR");
        this->close();

    }




    if (ui -> dy05Button -> isChecked()) {
       dy = 1.0;
    }
    else if (ui -> dy10Button -> isChecked()) {
       dy = 1.1;
    }
    else if (ui -> dy15Button -> isChecked()) {
       dy = 1.2;
    }
    else if (ui -> dy20Button -> isChecked()) {
       dy = 1.3;
    }
    else if (ui -> dy30Button -> isChecked()) {
       dy = 1.4;
    }
    else if (ui -> dy40Button -> isChecked()) {
       dy = 1.5;
    }
    else if (ui -> dy50Button -> isChecked()) {
       dy = 2.0;
    }
    else {
        QMessageBox::information(this,"Warning","ERROR");
        this->close();

    }




    if (ui -> pianoButton -> isChecked()) {
       instrument = "piano";
    }
    else if (ui -> guitarButton -> isChecked()) {
       instrument = "guitar";
    }
    else if (ui -> stringButton -> isChecked()) {
       instrument = "string";
    }
    else if (ui -> FXButton -> isChecked()) {
       instrument = "FX";
    }
    else {
        QMessageBox::information(this,"Warning","ERROR");
        this->close();

    }


    if (ui -> melody1564Button -> isChecked()) {
       melody = 1564;
    }
    else if (ui -> melody2511Button -> isChecked()) {
       melody = 2511;
    }
    else if (ui -> melody6413Button -> isChecked()) {
       melody = 6413;
    }
    else if (ui -> melody1451Button -> isChecked()) {
       melody = 1451;
    }
    else if (ui -> melody1165Button -> isChecked()) {
       melody = 1165;
    }
    else {
        QMessageBox::information(this,"Warning","ERROR");
        this->close();

    }


    tempo = ui->tempoSlider->value();
// change in this place
    vector<Track> track_list;
    track_list = Professional(tp,tempo,instrument,melody); //professional
//    track_list.pop_back();
    module5(track_list);

    this->close();
}

void professionalDialog::on_procancelButton_clicked()
{
    this->close();
}
