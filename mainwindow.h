#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QFileDialog>
#include <QMediaPlayer>
#include <QMediaMetaData>
#include <QTime>
#include "../track.h"
#include "../testfile.h"
#include "track_to_midi.h"

extern int version;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


    void stateChanged(QMediaPlayer::State state);
    void positionChanged(qint64 position);

private slots:
    void on_playButton_clicked();

    void on_pauseButton_clicked();

    void on_progressbar_sliderMoved(int position);

    void on_volume_sliderMoved(int position);

    void on_actionOpen_File_triggered();

    void on_standardversionButton_clicked();

    void on_advancedversionButton_clicked();

    void on_generateButton_clicked();

    void on_saveButton_clicked();

    void on_professionalversionButton_clicked();

private:
    Ui::MainWindow *ui;
    QMediaPlayer* player;

};

#endif // MAINWINDOW_H
