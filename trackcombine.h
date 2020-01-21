//Module 4 Track generate

#ifndef TRACKCOMBINE_H
#define TRACKCOMBINE_H

#include<iostream>
#include<fstream>
#include<cstdio>
#include<map>
#include<cmath>
#include <vector>
#include"stdlib.h"
#include<string>
#include<random>
#include<ctime>
#include"track.h"
using namespace std;
/* Extern parameters */
//extern int version;

//extern vector<int> tp;
//extern double dy;
//extern string instrument;
//extern int tempo;
//extern int melody;

//extern string emotion;
//extern string genre;
//extern string sty;
//extern int saturation;

/* Function gttrack()
 * usage: Track1 = gttrack()
 * Store info in Track.
 */

vector<Track> gttrack(vector<vector<int>> inst, int pt, vector<int> tpl);

/* Function proinst()
 * usage inst = proinst();
 * get instrument from professional interface.
 */

vector<vector<int>> proinst(string inst);

/* Function data_in_file();
 * usage: data_in_file();
 */

void data_to_file(vector<Track> Tracklist,int pt,vector<int> tpl,int t);

vector<Track> Advance(string emotion,string genre,int satu);
vector<Track> Simple(string emotion);
vector<Track> Professional(vector<int> a_template,int a_tempo,string a_lead_inst,int melody,double dynamic_plus = 1);


#endif // TRACKCOMBINE_H
