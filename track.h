#ifndef TRACK_H
#define TRACK_H
#include <vector>
#include <array>
#include <list>
#include <string>
#include "musicinterpreter.h"
using namespace std;


class Track{

public:
    Track();
    ~Track();
    int instrument = -1;
    int rhythm = 16;
    int pt;
    vector<int> tpl;
    vector<vector<int>> notelist;
    vector<vector<double>> times;
    vector<double> volumes;

//
    // Input functions
    void init(int inst, int rhy, int pty, vector<int> tply); // initialization

    void add(vector<int> notes = {0}, double volume = 1.0, vector<double> time = {0,0}); // add a new note

//    void noteToTrack(vector<int> notes,int i);

    void change(int in, vector<int> notes = {0}, double volume = 10, vector<double> time = {0,0}); // replace a note

    void seti(int in); // reset index

    // Output functions
    vector<int> get_pitch();    //return pitches of current note
    vector<double> t(); //return period of current note
    int get_instrument(); //return instrument name
    int i();
    int r();    //return beat per section
    int size(); //return size of track
    int get_volume(); //return volume of current note
    int get_start_time();  //return start time of notes.
    int get_end_time();  //return end time of notes



/*
 * Sample:
 * track1.seti(0);
 * for (int i = 0; i < track.size(); ++i){
 * vector<int> pitches = track1.get_pitch();   得到音高的vector
 * int startTime = track1.get_start_time();    得到点起始时间
 * int EndTime = track1.get_end_time();        得到点终止时间
 * int vol = track1.get_volume();              得到点音量，请自行测试调整大小
 * int instrument = track1.get_instrument();   得到乐器，integer对应关系参照gm1
 * ......
 * ......
 * newNote();
 * }
 */

    //Others
    void newNote();
    void newSection();
    void setSize();
private:
    int index = 0;
    int tracer = 0;
    int s1ze = 0;
};

#endif // TRACK_H
