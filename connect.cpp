#include <iostream>
#include <cstdio>
#include <map>
#include <cmath>
#include "stdlib.h"
#include <string>
#include "random"
#include <ctime>
#include <vector>
#include "track.h"
#include "track_to_midi.cpp"

#include "accompany.h"
#include "mainwindow.h"
#include "chord.h"
#include "musicinterpreter.h"
#include "trackcombine.h"
#include "professionaldialog.h"
#include "advancedvdialog.h"
#include "standarddialog.h"

#include <QApplication>
#include <iostream>
#include <vector>
#include <pcm_to_wav.h>
#include <Windows.h>

using namespace std;
//int version;

//vector<int> tp;
//double dy;
//string instrument;
//int tempo;
//int melody;

//string emotion;
//string genre;
//string sty;
//int saturation;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}


