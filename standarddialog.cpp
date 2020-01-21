#include "standarddialog.h"
#include "ui_standarddialog.h"
#include <QMessageBox>
#include <iostream>
#include "variable.h"
#include <pcm_to_wav.h>
#include "../track.h"
#include "../testfile.h"
#include "track_to_midi.h"


using namespace std;

standardDialog::standardDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::standardDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Standard Version");
}

standardDialog::~standardDialog()
{
    delete ui;
}


void standardDialog::on_okButton_clicked()
{
    if (ui -> happyButton -> isChecked()) {
       emotion = "happy";
    }
    else if (ui -> excitedButton -> isChecked()) {
       emotion = "excited";
    }
    else if (ui -> relaxedButton -> isChecked()) {
       emotion = "relaxed";
    }
    else if (ui -> lonelyButton -> isChecked()) {
       emotion = "lonely";
    }
    else if (ui -> nervousButton -> isChecked()) {
       emotion = "nervous";
    }
    else if (ui -> blueButton -> isChecked()) {
       emotion = "blue";
    }
    else if (ui -> sadButton -> isChecked()) {
       emotion = "sad";
    }
    else {
        QMessageBox::information(this,"Warning","ERROR");
        this->close();

    }
// change in this place
    vector<Track> track_list;
    track_list = Simple(emotion);
    //track_list.pop_back();
    module5(track_list);

    this->close();
}

void standardDialog::on_cancelButton_clicked()
{
    this->close();
}
