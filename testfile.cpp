
#include <iostream>
#include "musicinterpreter.h"
#include <cstdio>
#include <map>
#include <cmath>
#include "stdlib.h"
#include <string>
#include <random>
#include <ctime>
#include <vector>
#include <fstream>

#include "accompany.h"
#include "track.h"
#include "trackcombine.h"
#include "advancedvdialog.h"

using namespace std;

/* 从Module1 获得的数据：
 * Emotion: S,H,E,L,B,R,N 单个大写首字母 需module1修改下
 * Genre: pop,rock,metal,jazz,classical,folk,electronic --- module 1请写全名写清楚 \(>q<)
 * Satu: 1-9 int
 */

vector<Track> Advance(string emotion,string genre,int satu){

    int pt = pitchtime(gettpo(emotion));    //pitchtime
    vector<int> tpl = gettpl();    //template
    vector<vector<int>> theinst = getinst(genre,satu);
    vector<Track> tracklist = gttrack(theinst,pt,tpl);
    int mainTrackNum = 0;
    mainTrackNum = 4 * int(tracklist[0].get_instrument() != -1) +
                       2 * int(tracklist[1].get_instrument() != -1) +
                           int(tracklist[2].get_instrument() != -1);
    Accompany music1;
    music1.style = (sty == "complex") ? 1:0;
    music1.init(genre,emotion,satu,tpl,mainTrackNum, 0);
    int inst;
    for (int q = 0; q < tracklist.size(); ++q)
    {
        inst = tracklist[q].get_instrument();
        tracklist[q] = (q > 2) ? music1.composer(tracklist[q]) : music1.mainTrack(q,inst);
        tracklist[q].init(inst,16,pt,tpl);
    }
    return tracklist;
//    int t;
//    ifstream log;
//    ofstream login;
//    log.open("/Users/macbook/Downloads/programing_total/c++/kl/log.txt");
//    log>>t;

//    data_to_file(tracklist,pt,tpl,t);
//    t += 1;
//    login.open("/Users/macbook/Downloads/programing_total/c++/kl/log.txt");
//    login << t;

//    login.close();
//    log.close();
}

vector<Track> Simple(string emotion){
    srand(unsigned(time(0)));
    vector<string> A_genre_list = {"pop","metal","rock","classical","jazz","electronic","folk"};
    string genre_t = A_genre_list[rand()%7];
    int satu_t = rand()%7+2;
    return Advance(emotion,genre_t,satu_t);
}


/* Template: 1-16中选择，返回vector<int>填入这个函数中，
 * Tempo: 60-240 int 填入这个函数中，
 * Dynamic-plus: 种类：0.5 1 1.5 2 3 4 5 double 填入这个函数中，
 * Instrument: 种类：piano,guitar,string,FX 中选一个 填入这个函数中,
 */

vector<Track> Professional(vector<int> a_template,int a_tempo,string a_lead_inst,int melody,double dynamic_plus){
    a_tempo = int(a_tempo*dynamic_plus);

    int pt = pitchtime(a_tempo);    //pitchtime
    vector<vector<int>> theinst = proinst(a_lead_inst);
    vector<Track> tracklist = gttrack(theinst,pt,a_template);

    //饶进设计professional的数据
    int mainTrackNum = 4 * int(tracklist[0].get_instrument() != -1) +
                       2 * int(tracklist[1].get_instrument() != -1) +
                           int(tracklist[2].get_instrument() != -1);

    Accompany music1;
    music1.init(randoms({"P","R","M","J","C","E","F"}),randoms({"S","H","E","B","R","L","N"}),
                rand()%5+1,a_template, mainTrackNum, melody);
//    music1.style = (sytle == "complex") ? 1:0;

    music1.style = rand()%2;
    int inst;
    for (int q = 0; q < tracklist.size() - 1; ++q)
    {
        inst = tracklist[q].get_instrument();
        tracklist[q] = (q > 2) ? music1.composer(tracklist[q]) : music1.mainTrack(q,inst);
        //主音总是会生成（即使乐器值为-1），如果想要去掉可以加入乐器值。
        tracklist[q].init(inst,16,pt,a_template);
    }

    // 将本次测试数据存入新的.txt文件
//    int t;
//    ifstream log;
//    ofstream login;
//    log.open("/Users/macbook/Downloads/programing_total/c++/kl/log.txt");
//    log>>t;

//    data_to_file(tracklist,pt,a_template,t);
//    t += 1;
//    login.open("/Users/macbook/Downloads/programing_total/c++/kl/log.txt");
//    login << t;

//    login.close();
//    log.close();
    return tracklist;
}


//vector<Track> main_testfile(){

//    string emotion;
//    string genre;
//    int satu;
////    cout<< "Enter an emotion: (sad,happy,excited,lonely,blue,relaxed,nervous)" << endl;
////    cin>> emotion;
////    cout<< "Enter a genre: (pop,rock,metal,jazz,clas,folk,elec)" << endl;
////    cin>> genre;
////    cout<< "Enter saturation: (1-9)" << endl;
////    cin>> satu;
//    emotion = "happy";
//    genre = "pop";
//    satu = 3;


//    int pt = pitchtime(gettpo(emotion));    //pitchtime
//    vector<int> tpl = gettpl();    //template
//    vector<vector<int>> theinst = getinst(genre,satu);
//    vector<Track> tracklist = gttrack(theinst,pt,tpl);


//    int mainTrackNum = (tracklist[0].get_instrument() != -1) +
//                        (tracklist[1].get_instrument() != -1) +
//                        (tracklist[2].get_instrument() != -1);
//    Accompany music1;
//    music1.init(genre,emotion,satu,tpl, mainTrackNum, 0);
////    music1.style = (sytle == "complex") 1:0;
//    music1.style = 0;
//    int inst;
//    for (int q = 0; q < tracklist.size() - 1; ++q)
//    {
//        inst = tracklist[q].get_instrument();
//        cout<< inst << endl;
//        tracklist[q] = (q > 2) ? music1.composer(tracklist[q]) : music1.mainTrack(q,inst);
//        //主音总是会生成（即使乐器值为-1），如果想要去掉可以加入乐器值。
//        tracklist[q].init(inst,16,pt,tpl);
//    }
//    inst = tracklist[10].get_instrument();
//    cout<< inst << endl;
//    tracklist[9] = music1.composer(tracklist[10]);
//    //主音总是会生成（即使乐器值为-1），如果想要去掉可以加入乐器值。
//   tracklist[9].init(inst,16,pt,tpl);
//   tracklist.pop_back();

//    int t;

//    ifstream log;
//    ofstream login;
//    log.open("E://log.txt");
//    log>>t;

//    data_to_file(tracklist,pt,tpl,t);
//    t += 1;
//    login.open("E://log.txt");
//    login << t;

//    login.close();
//    log.close();

//    return tracklist;
//}

