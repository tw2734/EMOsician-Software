#include <cstdio>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "standarddialog.h"
#include "advancedvdialog.h"
#include "professionaldialog.h"
#include "variable.h"
#include <vector>
#include <pcm_to_wav.h>
#include "windows.h"

//bool ok = false;

//extern int version;
int version;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("EMOcisian");

    /* Initialize the player variable*/
    player = new QMediaPlayer(this);
    dy=1.5;
   // if (ok = true) {
    //pcm_to_wav();
    player -> setMedia(QUrl::fromLocalFile("C:/buildtemp/takeaway/may16.wav"));

   // ok = false;
    player->setVolume(50);
    connect(player, &QMediaPlayer::stateChanged, this, &MainWindow::stateChanged);
    connect(player, &QMediaPlayer::positionChanged, this, &MainWindow::positionChanged);
}

/* stateChanged() signal allow us to obtain information about the current state of the music playing
 * now enable and disable push buttons(generate, play, pause, save)
 */

void MainWindow::stateChanged(QMediaPlayer::State state)
{
    if (state == QMediaPlayer::PlayingState)
    {
            ui->generateButton->setEnabled(true);
            ui->playButton->setEnabled(false);
            ui->pauseButton->setEnabled(true);
            ui->saveButton->setEnabled(true);
    }
    else if (state == QMediaPlayer::PausedState)
    {
            ui->generateButton->setEnabled(true);
            ui->playButton->setEnabled(true);
            ui->pauseButton->setEnabled(false);
            ui->saveButton->setEnabled(true);
    }
}

/*set the timeslider*/
void MainWindow::positionChanged(qint64 position)
{
    if (ui->progressbar->maximum() != player->duration())
        ui->progressbar->setMaximum(player->duration());

    ui->progressbar->setValue(position);

    int seconds = (position/1000) % 60;
    int minutes = (position/60000) % 60;
    int hours = (position/3600000) % 24;
    QTime time(hours, minutes,seconds);
    ui->durationDisplay->setText(time.toString());
}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_playButton_clicked()
{
    player -> play();
}

void MainWindow::on_pauseButton_clicked()
{
    player -> pause();
}

void MainWindow::on_progressbar_sliderMoved(int position)
{
    player -> setPosition(position);
}



void MainWindow::on_volume_sliderMoved(int position)
{
    player -> setVolume(position);
    ui->volume->setValue(position);
}



void MainWindow::on_actionOpen_File_triggered()
{
   QString fileName = QFileDialog::getOpenFileName(this, "Select Audio File", qApp->applicationDirPath(),
                                                   "WAV (*.wav)");
   QFileInfo fileInfo(fileName);

   player->setMedia(QUrl::fromLocalFile(fileName));

   ui->playButton->setEnabled(true);
   ui->playButton->click();
}

void MainWindow::on_standardversionButton_clicked()
{
    version = 1;
    player->pause();
    player->stop();
   // create an object for standardDialog class
    standardDialog standarddialog;
   //use the object to open the second window
    standarddialog.setModal(true);
   //show the window after clicking
    standarddialog.exec();
}

void MainWindow::on_advancedversionButton_clicked()
{
    version = 2;
    player->pause();
    player->stop();
    advancedVDialog advancedvdialog;
    advancedvdialog.setModal(true);
    advancedvdialog.exec();
}

void MainWindow::on_professionalversionButton_clicked()
{
     version = 3;
     player->pause();
     player->stop();
     professionalDialog professionaldialog;
     professionaldialog.setModal(true);
     professionaldialog.exec();
}

//string emotion;
//string genre;
//string sty;
//int saturation;
//vector<int> tp;
//double dy;
//string instrument;
//int tempo;

void MainWindow::on_generateButton_clicked()
{
    player->pause();
    player->stop();

//    if (emotion == "happy") {
//       emotion = "happy";
//    }
//    else if (emotion == "excited") {
//       emotion = "excited";
//    }
//    else if (emotion == "relaxed") {
//       emotion = "relaxed";
//    }
//    else if (emotion == "lonely") {
//       emotion = "lonely";
//    }
//    else if (emotion == "nervous") {
//       emotion = "nervous";
//    }
//    else if (emotion == "blue") {
//       emotion = "blue";
//    }
//    else if (emotion == "sad") {
//       emotion = "sad";
//    }


    //add variables in advanced version

//    if (genre == "pop") {
//       genre = "pop";
//    }
//    else if (genre == "rock") {
//       genre = "rock";
//    }
//    else if (genre == "metal") {
//       genre = "metal";
//    }
//    else if (genre == "jazz") {
//       genre = "jazz";
//    }
//    else if (genre == "classical") {
//       genre = "classical";
//    }
//    else if (genre == "folk") {
//       genre = "folk";
//    }
//    else if (genre == "electronic") {
//       genre = "electronic";
//    }


//    if (sty == "quiet") {
//       sty = "quiet";
//    }
//    else if (sty == "energetic") {
//       sty = "energetic";
//    }
//    else if (sty == "loud") {
//       sty = "loud";
//    }
//    else if (sty == "complex") {
//       sty = "complex";
//    }


//    saturation = saturation;


    //add variables in professional version

//    tp = tp;



//    if (dy == 0.5) {
//       dy = 0.5;
//    }
//    else if (dy == 1.0) {
//       dy = 1.0;
//    }
//    else if (dy == 1.5) {
//       dy = 1.5;
//    }
//    else if (dy == 2.0) {
//       dy = 2.0;
//    }
//    else if (dy == 3.0) {
//       dy = 3.0;
//    }
//    else if (dy == 4.0) {
//       dy = 4.0;
//    }
//    else if (dy == 5.0) {
//       dy = 5.0;
//    }



//    if (instrument == "piano") {
//       instrument = "piano";
//    }
//    else if (instrument == "guitar") {
//       instrument = "guitar";
//    }
//    else if (instrument == "string") {
//       instrument = "string";
//    }
//    else if (instrument == "FX") {
//       instrument = "FX";
//    }


//    tempo = tempo;



//不能用，用了就炸
//    vector<Track> track_list;
//    switch (version) {
//    case 1:
//        track_list = Simple(emotion);break; //simple
//    case 2:
//        track_list = Advance(emotion,genre,saturation);break; //advance
//    case 3:
//        track_list = Professional(tp,tempo,instrument,melody); //professional
//    }

//    module5(track_list);

    player->stop();
    player -> setMedia(QUrl::fromLocalFile("C:/buildtemp/takeaway/may16.wav"));
    remove("C://buildtemp//takeaway//may16.wav");

//    cout<<"5000 ms sleep_begin"<<endl;
    Sleep(5000);
//    cout<<"sleep_end"<<endl;
    pcm_to_wav();
    player -> setMedia(QUrl::fromLocalFile("C:/buildtemp/takeaway/may16.wav"));
}



bool copyFileToPath(QString sourceDir ,QString toDir, bool coverFileIfExist)

{

    toDir.replace("\\","/");

    if (sourceDir == toDir){

        return true;

    }

    if (!QFile::exists(sourceDir)){

        return false;

    }

    QDir *createfile     = new QDir;

    bool exist = createfile->exists(toDir);

    if (exist){

        if(coverFileIfExist){

            createfile->remove(toDir);

        }

    }//end if



    if(!QFile::copy(sourceDir, toDir))

    {
        return false;
    }

    return true;

}





void MainWindow::on_saveButton_clicked()
{
    QString address = QFileDialog::getSaveFileName(this,

    "Select Save Address", qApp->applicationDirPath(),

    "WAV (*.wav)");

    copyFileToPath("C:/buildtemp/takeaway/may16.wav",address, true);

    ui->playButton->setEnabled(true);

    ui->playButton->click();
}




