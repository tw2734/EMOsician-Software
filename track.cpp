#include "track.h"


Track::Track(){
    index = 0;
    s1ze = 0;
    notelist.clear();
    times.clear();
    volumes.clear();
};
Track::~Track(){
    notelist.clear();
    times.clear();
    volumes.clear();
}

void Track::init(int inst, int rhy, int pty, vector<int> tply){
    instrument = inst;
    rhythm = rhy;
    pt = pty;
    tpl = tply;
}
// Input functions

void Track::add(vector<int> notes, double volume, vector<double> time){
    notelist.push_back(notes);
    times.push_back(time);
    volumes.push_back(volume);
    index=index+1;
}

void Track::change(int in, vector<int> notes, double volume, vector<double> time){
    notelist[in] = notes;
    times[in] = time;
    volumes[in] = volume;
}

void Track::seti(int in){
    index = in;
}


// Output functions
vector<int> Track::get_pitch(){
    return notelist[index];
}

vector<double> Track::t(){
    return times[index];
}

int Track::get_instrument(){
    return instrument;
}

int Track::i(){
    return get_instrument();
}

int Track::r(){
    return rhythm;
}
int Track::size(){
    return s1ze;
}

int Track::get_volume(){
    double st = t()[0]/rhythm;
    int vol = int((volumes[index])*getvol(st,tpl));
    return vol;
}

int Track::get_start_time(){
    int starttime = int(pt*t()[0]);
    return starttime;
}

int Track::get_end_time(){
    int endtime = int(pt*t()[1]);
    return endtime;
}

void Track::newNote(){
    index += 1;
}
void Track::newSection(){
    tracer += 1;
}
void Track::setSize(){
    s1ze = index;
}
