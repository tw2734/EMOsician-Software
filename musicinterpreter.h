// Module 2 function head file.

#ifndef MUSICINTERPRETER_H
#define MUSICINTERPRETER_H

#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#include <vector>
#include"stdlib.h"
#include<string>
#include<random>
#include<ctime>

using namespace std;

/* Function getinst(genre,satu);
 * usage: inst = getinst(genre,satu)
 * introduction: Getting instrument combination. 
 */

vector<vector<int>> getinst(string genre,int satu);

/* Function gettpl(genre,satu);
 * usage: tpl = gettpl(genre,satu)
 * introduction: Ramdom generate template. 
 */

vector<int> gettpl(int i = -1);

/* Function pitchtime()
 * usage: pitch = pitchtime
 * introduction: Giving tempo, returning section time.
 * Giving tempo and rhythm, returning pitch time.
 */

int pitchtime(int tempo);

/* Function gettpo()
 * usage: tempo = gettpo();
 * introduction: Giving xxx, returning tempo number.
 */

int gettpo(string emotion);

/* Function getDplus()
 * usage: Dplus = getDplus();
 * introduction: Giving xxx, returning Dynamic-puls.
 */

int getDplus();

/* Function getvol();
 * usage: vol = getvol(int section, int tpl)
 * Introduction: Giving section and tpl, returning volume.
 */

double getvol(double section, vector<int> tpl);
double volgra(int part1, int part2, double sectime);




#endif // MUSICINTERPRETER_H
