#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include <vector>
#include <pcm_to_wav.h>
#include <Windows.h>


using namespace std;

void HideConsole()
{
    ::ShowWindow(::GetConsoleWindow(), SW_HIDE);
}

int main(int argc, char *argv[])
{
    HideConsole();
    system("C:/Users/Maverick/Documents/build-emptyqmake-Desktop_Qt_5_11_2_MinGW_32bit_468be3-Debug/debug/emptyqmake.exe");

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}

