#include <iostream>
#include "musicinterpreter.h"
#include "trackcombine.h"
#include <cstdio>
#include <map>
#include <cmath>
#include "stdlib.h"
#include <string>
#include <random>
#include <ctime>
#include <vector>
#include "track.h"
#include <iomanip>
using namespace std;

/* Function gttrack();*/

vector<Track> gttrack(vector<vector<int>> inst, int pt, vector<int> tpl){
    Track T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T0;
    vector<Track> Tracklist = {T1,T2,T3,T4,T5,T6,T7,T8,T9,T10,T0};
    vector<int> tinst;
    int m;

    //lead
    tinst = inst[0];
    for (m=0;m<int(tinst.size());m++) {
        Tracklist[m].init((tinst[m]-1+min(tinst[m],1)),16,pt,tpl);
    }

    //bass
    tinst = inst[1];
    Tracklist[3].init(tinst[0],16,pt,tpl);

    //mid
    tinst = inst[2];
    for (m = 0; m <int(tinst.size());m++){
        Tracklist[m+4].init((tinst[m]-1+min(tinst[m],1)),16,pt,tpl); // (tinst[m]-1+min(tinst[m],1))
    }

    //piano
    tinst = inst[3];
    Tracklist[8].init(tinst[0],16,pt,tpl);

    //flower
    tinst = inst[4];
    if (tinst.empty()){;}
    else{Tracklist[9].init(tinst[0],16,pt,tpl);}

    //drum
    Tracklist[10].init(-2,16,pt,tpl);

    return Tracklist;
}

vector<vector<int>> proinst(string leadi){
    srand(unsigned(time(0)));
    string gen;
    int satu = 1 + rand()%9;
    vector<int> leadt;
    vector<string> gens;
    if (leadi == "piano"){      //执行：先随机gen，再填充leadt的乐器
        gens = {"pop","rock","classical","folk"};
        gen = gens[rand()%int(gens.size())];
        leadt = {0,1,3,11};

    }
    if (leadi == "guitar"){
        gens = {"pop","rock","metal","folk"};
        gen = gens[rand()%int(gens.size())];
        leadt = {27,29,30};

    }
    if (leadi == "string"){
        gens = {"jazz","classical"};
        gen = gens[rand()%int(gens.size())];
        leadt = {40,48,49};

    }
    if (leadi == "FX"){
        gens = {"pop","rock","electronic","folk"};
        gen = gens[rand()%int(gens.size())];
        leadt = {62,85,87,89,98,103};

    }
    vector<int> ym;
    int ym1,ym2;
    switch (satu) {
    case 1:
    case 2:
    case 3:
        ym.push_back(leadt[rand()%int(leadt.size())]);
        break;
    case 4:
    case 5:
    case 6:
        ym1 = rand()%int(leadt.size());
        ym.push_back(leadt[ym1]);
//        ym.erase(leadt.begin()+ym1);
        leadt.erase(leadt.begin()+ym1);
        ym.push_back(leadt[rand()%int(leadt.size())]);
        break;
    case 7:
    case 8:
    case 9:
        ym1 = rand()%int(leadt.size());
        ym.push_back(leadt[ym1]);
/*        ym.erase(leadt.begin()+ym1);ym1 = rand()%int(leadt.size());*/ // 出错啦，erase[begin +3] 当 ym.size = 1;
        leadt.erase(leadt.begin()+ym1);ym1 = rand()%int(leadt.size());
        ym2 = rand()%int(leadt.size());
        ym.push_back(leadt[ym2]);
//        ym.erase(leadt.begin()+ym2);
        leadt.erase(leadt.begin()+ym2);
        ym.push_back(leadt[rand()%int(leadt.size())]);
    }
    vector<vector<int>> instrument = getinst(gen,satu);
    instrument[0] = ym;
    return instrument;
}


void data_to_file(vector<Track> Tracklist,int pt,vector<int> tpl,int t){

    ofstream fout;
    string bb="";
    bb = to_string(t);
//    fout.open("/Users/macbook/Downloads/programing_total/c++/kl/music"+bb+".txt");
    fout.open("E://music"+bb+".txt");
    fout << "Music_output ------------------------" << "\n";
    fout << "Template: ";
    for (int a = 0;a < int(tpl.size()); a++) {
        fout << tpl[a];
    }
    fout << "*" << endl;
    fout << "Pitch_time: " << pt << endl;
    fout << "Track_data -------------------" << endl;
    Track t_test;
    for (int b = 0;b < int(Tracklist.size()); b++) {
        fout << "Track" << std::right<<std::setfill('0')<<std::setw(2)<< b+1 << ": " << endl;
        t_test = Tracklist[b];
        t_test.seti(0);
        fout << "Instrument: " << t_test.get_instrument() << endl;
        for (int c = 0;c < t_test.size();c++) {
            vector<int> pitch = t_test.get_pitch();
            int starttime = t_test.get_start_time();
            int endtime = t_test.get_end_time();
            int vol = t_test.get_volume();

            fout << std::right<<std::setfill('0')<<std::setw(3)<< vol << ",";
            fout << std::right<<std::setfill('0')<<std::setw(6)<< starttime << ",";
            fout << std::right<<std::setfill('0')<<std::setw(6)<< endtime <<",";

            for (int d = 0;d < int(pitch.size());d++) {
                int pi = pitch[d];
                fout << std::right<<std::setfill('0')<<std::setw(3)<<pi<<"|";
            }
            fout << "::" << endl;
            fout << " " << endl;
            t_test.newNote();
        }
    }

    /*
     * Sample:
     * track1.seti(0);
     * for (int i = 0; i < track.size(); ++i){
     * vector<int> pitches = track1.n();
     * int startTime = track1.st(pt);
     * int EndTime = track1.et(pt);
     * int vol = track1.vol(tpl);
     * ......
     * ......
     * newNote();
     * }
     */
}




