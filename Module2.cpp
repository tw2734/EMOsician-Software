 /*
 * File: Module2.cpp
 * ----------------------
 * Module2 parameters transforming.
 */

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
using namespace std;

/* Function:
 *  getinst()
 */

vector<vector<int>> getinst(string genre,int satu){
    srand(unsigned(time(0)));
    vector<int> mainly;
    vector<int> bass;
    vector<int> midacc;
    vector<int> pianoacc;
    vector<int> addf;
    if (genre == "pop"){
        
        //first main
        vector<int> fp = {0,1,3,27,85};
        int fp1,fp2 = 0;
        satu = (satu == 0) ? rand()%7 + 2: satu;
        switch (satu) {
        case 1:
        case 2:
        case 3:
            mainly.push_back(fp[rand()%5]);
            break;
        case 4:
        case 5:
        case 6:
            fp1 = rand()%5;
            mainly.push_back(fp[fp1]);
            fp.erase(fp.begin()+fp1);
            mainly.push_back(fp[rand()%4]);
            break;
        case 7:
        case 8:
        case 9:
            fp1 = rand()%5;
            mainly.push_back(fp[fp1]);
            fp.erase(fp.begin()+fp1);
            fp2 = rand()%4;
            mainly.push_back(fp[fp2]);
            fp.erase(fp.begin()+fp2);
            mainly.push_back(fp[rand()%3]);

        }
        
        //bass

        bass.push_back(rand()%2+32);

        //medium-accompany
        vector<int> mp = {24,25,30,89,90,94,96,97};
        int mp1,mp2,mp3 = 0;
        switch (satu) {
        case 1:
            break;
        case 2:
            midacc.push_back(mp[rand()%8]);
            break;
        case 3:
        case 4:
        case 5:
            mp1 = rand()%8;
            midacc.push_back(mp[mp1]);
            mp.erase(mp.begin()+mp1);
            midacc.push_back(mp[rand()%7]);
            break;
        case 6:
        case 7:
        case 8:
            mp1 = rand()%8;
            midacc.push_back(mp[mp1]);
            mp.erase(mp.begin()+mp1);
            mp2 = rand()%7;
            midacc.push_back(mp[mp2]);
            mp.erase(mp.begin()+mp2);
            midacc.push_back(mp[rand()%6]);
            break;
        case 9:
            mp1 = rand()%8;
            midacc.push_back(mp[mp1]);
            mp.erase(mp.begin()+mp1);
            mp2 = rand()%7;
            midacc.push_back(mp[mp2]);
            mp.erase(mp.begin()+mp2);
            mp3 = rand()%6;
            midacc.push_back(mp[mp3]);
            mp.erase(mp.begin()+mp3);
            midacc.push_back(mp[rand()%5]);
        }

        //piano-accompany
        switch (satu) {
        case 8:
        case 9:
            pianoacc.push_back(3*(rand()%2));
        }

        //Adding flower


    }
    if (genre == "rock"){

        //first main
        vector<int> fr = {3,27,29,30,87};
        int fr1,fr2 = 0;
        switch (satu) {
        case 1:
        case 2:
        case 3:
            mainly.push_back(fr[rand()%5]);
            break;
        case 4:
        case 5:
        case 6:
            fr1 = rand()%5;
            mainly.push_back(fr[fr1]);
            fr.erase(fr.begin()+fr1);
            mainly.push_back(fr[rand()%4]);
            break;
        case 7:
        case 8:
        case 9:
            fr1 = rand()%5;
            mainly.push_back(fr[fr1]);
            fr.erase(fr.begin()+fr1);
            fr2 = rand()%4;
            mainly.push_back(fr[rand()%4]);
            fr.erase(fr.begin()+fr2);
            mainly.push_back(rand()%3);
            break;}

        //bass
        vector<int> br = {33,34,36,37};
        bass.push_back(br[rand()%4]);

        //medium-accompany
        vector<int> mr = {27,28,29,30,87,93};
        int mr1,mr2,mr3 = 0;
        switch (satu) {
        case 1:
            break;
        case 2:
            midacc.push_back(mr[rand()%6]);
            break;
        case 3:
        case 4:
        case 5:
            mr1 = rand()%6;
            midacc.push_back(mr[mr1]);
            mr.erase(mr.begin()+mr1);
            midacc.push_back(mr[rand()%5]);
            break;
        case 6:
        case 7:
        case 8:
            mr1 = rand()%6;
            midacc.push_back(mr[mr1]);
            mr.erase(mr.begin()+mr1);
            mr2 = rand()%5;
            midacc.push_back(mr[mr2]);
            mr.erase(mr.begin()+mr2);
            midacc.push_back(mr[rand()%4]);
            break;
        case 9:
            mr1 = rand()%6;
            midacc.push_back(mr[mr1]);
            mr.erase(mr.begin()+mr1);
            mr2 = rand()%5;
            midacc.push_back(mr[mr2]);
            mr.erase(mr.begin()+mr2);
            mr3 = rand()%4;
            midacc.push_back(mr[mr3]);
            mr.erase(mr.begin()+mr3);
            midacc.push_back(mr[rand()%3]);
        }

        //piano-accompany
        switch (satu) {
        case 8:
        case 9:
            pianoacc.push_back(3*(rand()%2));
        }

        //Adding flower
        switch (satu) {
        case 6:
        case 7:
        case 8:
        case 9:
            addf.push_back(121);
        }
    }
    if (genre == "metal"){

        //first main        
        mainly.push_back(29);

        //bass
        vector<int> bm = {34,36,37};
        bass.push_back(bm[rand()%3]);

        //medium-accompany
        vector<int> mm = {28,30,87,93};
        int mm1,mm2 = 0;
        switch (satu) {
        case 1:
            break;
        case 2:
            midacc.push_back(mm[rand()%4]);
            break;
        case 3:
        case 4:
        case 5:
            mm1 = rand()%4;
            midacc.push_back(mm[mm1]);
            mm.erase(mm.begin()+mm1);
            midacc.push_back(mm[rand()%3]);
            break;
        case 6:
        case 7:
        case 8:
            mm1 = rand()%4;
            midacc.push_back(mm[mm1]);
            mm.erase(mm.begin()+mm1);
            mm2 = rand()%3;
            midacc.push_back(mm[mm2]);
            mm.erase(mm.begin()+mm2);
            midacc.push_back(mm[rand()%2]);
            break;
        case 9:
            midacc = mm;
        }

        //piano-accompany

        switch (satu) {
        case 8:
        case 9:
            pianoacc.push_back(rand()%2);
        }

        //Adding flower
        switch (satu) {
        case 6:
        case 7:
        case 8:
        case 9:
            addf.push_back(120+7*(rand()%2));
            break;}
    }
    if (genre == "jazz"){

        //first main
        vector<int> fj = {3,36,40,48,64};
        int fj1,fj2 = 0;
        switch (satu) {
        case 1:
        case 2:
        case 3:
            mainly.push_back(fj[rand()%5]);
            break;
        case 4:
        case 5:
        case 6:
            fj1 = rand()%5;
            mainly.push_back(fj[fj1]);
            fj.erase(fj.begin()+fj1);
            mainly.push_back(fj[rand()%4]);
            break;
        case 7:
        case 8:
        case 9:
            fj1 = rand()%5;
            mainly.push_back(fj[fj1]);
            fj.erase(fj.begin()+fj1);
            fj2 = rand()%4;
            mainly.push_back(fj[fj2]);
            fj.erase(fj.begin()+fj2);
            mainly.push_back(fj[rand()%3]);
            break;}

        //bass
        vector<int> bj = {32,34,35,36};
        bass.push_back(bj[rand()%4]);

        //medium-accompany
        vector<int> mj = {24,25,26,48,49,89,99,102};
        int mj1,mj2,mj3 = 0;
        switch (satu) {
        case 1:
            break;
        case 2:
            midacc.push_back(mj[rand()%8]);
            break;
        case 3:
        case 4:
        case 5:
            mj1 = rand()%8;
            midacc.push_back(mj[mj1]);
            mj.erase(mj.begin()+mj1);
            midacc.push_back(mj[rand()%7]);
            break;
        case 6:
        case 7:
        case 8:
            mj1 = rand()%8;
            midacc.push_back(mj[mj1]);
            mj.erase(mj.begin()+mj1);
            mj2 = rand()%7;
            midacc.push_back(mj[mj2]);
            mj.erase(mj.begin()+mj2);
            midacc.push_back(mj[rand()%6]);
            break;
        case 9:
            mj1 = rand()%8;
            midacc.push_back(mj[mj1]);
            mj.erase(mj.begin()+mj1);
            mj2 = rand()%7;
            midacc.push_back(mj[mj2]);
            mj.erase(mj.begin()+mj2);
            mj3 = rand()%6;
            midacc.push_back(mj[mj3]);
            mj.erase(mj.begin()+mj3);
            midacc.push_back(mj[rand()%5]);}

        //piano-accompany
        switch (satu) {
        case 8:
        case 9:
            pianoacc.push_back(3*(rand()%2));
        }

        //Adding flower
        switch (satu) {
        case 6:
        case 7:
        case 8:
        case 9:
            addf.push_back(122);
        }
    }
    if (genre == "classical"){

        //first main
        vector<int> fc = {0,3,40,48,64};
        int fc1,fc2 = 0;
        switch (satu) {
        case 1:
        case 2:
        case 3:
            mainly.push_back(fc[rand()%5]);
            break;
        case 4:
        case 5:
        case 6:
            fc1 = rand()%5;
            mainly.push_back(fc[fc1]);
            fc.erase(fc.begin()+fc1);
            mainly.push_back(fc[rand()%4]);
            break;
        case 7:
        case 8:
        case 9:
            fc1 = rand()%5;
            mainly.push_back(fc[fc1]);
            fc.erase(fc.begin()+fc1);
            fc2 = rand()%4;
            mainly.push_back(fc[fc2]);
            fc.erase(fc.begin()+fc2);
            mainly.push_back(fc[rand()%3]);
            break;
        }

        //bass
        bass.push_back(42);

        //medium-accompany
        vector<int> mc = {48,49,85,91};
        int mc1,mc2 = 0;
        switch (satu) {
        case 1:
            break;
        case 2:
            midacc.push_back(mc[rand()%4]);
            break;
        case 3:
        case 4:
        case 5:
            mc1 = rand()%4;
            midacc.push_back(mc[mc1]);
            mc.erase(mc.begin()+mc1);
            midacc.push_back(mc[rand()%3]);
            break;
        case 6:
        case 7:
        case 8:
            mc1 = rand()%4;
            midacc.push_back(mc[mc1]);
            mc.erase(mc.begin()+mc1);
            mc2 = rand()%3;
            midacc.push_back(mc[mc2]);
            mc.erase(mc.begin()+mc2);
            midacc.push_back(mc[rand()%2]);
            break;
        case 9:
            midacc = mc;}

        //piano-accompany
        switch (satu) {
        case 8:
        case 9:
            pianoacc.push_back(1+2*(rand()%2));
        }

        //Adding flower
    }
    if (genre == "folk"){

        //first main
        vector<int> ff = {3,11,27,89};
        int ff1,ff2 = 0;
        switch (satu) {
        case 1:
        case 2:
        case 3:
            mainly.push_back(ff[rand()%4]);
            break;
        case 4:
        case 5:
        case 6:
            ff1 = rand()%4;
            mainly.push_back(ff[ff1]);
            ff.erase(ff.begin()+ff1);
            mainly.push_back(ff[rand()%3]);
            break;
        case 7:
        case 8:
        case 9:
            ff1 = rand()%4;
            mainly.push_back(ff[ff1]);
            ff.erase(ff.begin()+ff1);
            ff2 = rand()%3;
            mainly.push_back(ff[ff2]);
            ff.erase(ff.begin()+ff2);
            mainly.push_back(ff[rand()%2]);
            break;}

        //bass
        bass.push_back(rand()%3+32);

        //medium-accompany
        vector<int> mf = {11,24,25,26,27,99,102};
        int mf1,mf2,mf3 = 0;
        switch (satu) {
        case 1:
            break;
        case 2:
            midacc.push_back(mf[rand()%7]);
            break;
        case 3:
        case 4:
        case 5:
            mf1 = rand()%7;
            midacc.push_back(mf[mf1]);
            mf.erase(mf.begin()+mf1);
            midacc.push_back(mf[rand()%6]);
            break;
        case 6:
        case 7:
        case 8:
            mf1 = rand()%7;
            midacc.push_back(mf[mf1]);
            mf.erase(mf.begin()+mf1);
            mf2 = rand()%6;
            midacc.push_back(mf[mf2]);
            mf.erase(mf.begin()+mf2);
            midacc.push_back(mf[rand()%5]);
            break;
        case 9:
            mf1 = rand()%7;
            midacc.push_back(mf[mf1]);
            mf.erase(mf.begin()+mf1);
            mf2 = rand()%6;
            midacc.push_back(mf[mf2]);
            mf.erase(mf.begin()+mf2);
            mf3 = rand()%5;
            midacc.push_back(mf[mf3]);
            mf.erase(mf.begin()+mf3);
            midacc.push_back(mf[rand()%4]);}

        //piano-accompany
        switch (satu) {
        case 8:
        case 9:
            pianoacc.push_back(3*(rand()%3));
        }

        //Adding flower
        switch (satu) {
        case 6:
        case 7:
        case 8:
        case 9:
            addf.push_back(123);

        }

    }
    if (genre == "electronic"){

        //first main
        vector<int> fe = {62,87,95,98,103};
        int fe1,fe2 = 0;
        switch (satu) {
        case 1:
        case 2:
        case 3:
            mainly.push_back(fe[rand()%5]);
            break;
        case 4:
        case 5:
        case 6:
            fe1 = rand()%5;
            mainly.push_back(fe[fe1]);
            fe.erase(fe.begin()+fe1);
            mainly.push_back(fe[rand()%4]);
            break;
        case 7:
        case 8:
        case 9:
            fe1 = rand()%5;
            mainly.push_back(fe[fe1]);
            fe.erase(fe.begin()+fe1);
            fe2 = rand()%4;
            mainly.push_back(fe[fe2]);
            fe.erase(fe.begin()+fe2);
            mainly.push_back(fe[rand()%3]);
        }

        //bass
        vector<int> be = {33,38,39};
        bass.push_back(be[rand()%3]);

        //medium-accompany
        vector<int> me = {88,92,93,95,98,99,101,103};
        int me1,me2,me3 = 0;
        switch (satu) {
        case 1:
            break;
        case 2:
            midacc.push_back(me[rand()%8]);
            break;
        case 3:
        case 4:
        case 5:
            me1 = rand()%8;
            midacc.push_back(me[me1]);
            me.erase(me.begin()+me1);
            midacc.push_back(me[rand()%7]);
            break;
        case 6:
        case 7:
        case 8:
            me1 = rand()%8;
            midacc.push_back(me[me1]);
            me.erase(me.begin()+me1);
            me2 = rand()%7;
            midacc.push_back(me[me2]);
            me.erase(me.begin()+me2);
            midacc.push_back(me[rand()%6]);
            break;
        case 9:
            me1 = rand()%8;
            midacc.push_back(me[me1]);
            me.erase(me.begin()+me1);
            me2 = rand()%7;
            midacc.push_back(me[me2]);
            me.erase(me.begin()+me2);
            me3 = rand()%6;
            midacc.push_back(me[me3]);
            me.erase(me.begin()+me3);
            midacc.push_back(me[rand()%5]);}

        //piano-accompany
        switch (satu) {
        case 8:
        case 9:
            addf.push_back(3*(rand()%2));
        }

        //Adding flower
    }
vector<vector<int>> instrument;
instrument.push_back(mainly);
instrument.push_back(bass);
instrument.push_back(midacc);
instrument.push_back(pianoacc);
instrument.push_back(addf);

return instrument;
}

/* Function:
 * pitchtime();
 */

int pitchtime(int tempo){ //unit of ms  打点时间
    if (tempo == 0) tempo = 80;
    return int(15000/tempo);
}

/* Function for volume.*/
  /*  O - 1,
     C1 - 2,
     C2 - 3,
     V1 - 4,
     V2 - 5,
     Va - 6,
      B - 7,
      E - 8 */

double volgra(int part1, int part2, double sectime){
    int low=0;
    int high=0;

    //reset value.

    switch(part1){
    case 1:low = 50;break;
    case 2:low = 65;break;
    case 3:low = 65;break;
    case 4:low = 75;break;
    case 5:low = 75;break;
    case 6:low = 90;break;
    case 7:low = 60;break;
    case 8:low = 50;}

    switch(part2){
    case 1:high = 50;break;
    case 2:high = 65;break;
    case 3:high = 65;break;
    case 4:high = 75;break;
    case 5:high = 75;break;
    case 6:high = 90;break;
    case 7:high = 60;break;
    case 8:high = 50;}

    //runing function.

    double vol = 0;
    double pai = 3.1416;

    if(sectime <=3.5){vol = low;}
    if(sectime >3.5 && sectime<4.5){vol = ((low+high)/2)+((high-low)/2)*sin(pai*sectime);}
    if(sectime >=4.5){vol = high;}

    return vol;

}

double getvol(double section, vector<int> tpl){       //section fomula
            

    double secf=section;

    double vol=0;
    if (secf <= 0.5){vol = volgra(tpl[0],tpl[0],1);}
    if (secf >= 0.5){
        int sec1 = int((secf-0.5)/4);
        double sec2 = (secf-0.5)-sec1*4;
        int secsize = int(tpl.size())-1;
        if (sec1==secsize){vol = volgra(tpl[secsize],tpl[secsize],1);}
        if (sec1<secsize){vol = volgra(tpl[sec1],tpl[sec1+1],sec2+0.5);}

    }

    return vol;
}


int gettpo(string emotion){
    int teml = 0;
    int temr = 0;
    if(emotion == "happy"){teml = 90; temr = 140;}
    if(emotion == "excited"){teml = 110; temr = 200;}
    if(emotion == "nervous"){teml = 120; temr = 200;}
    if(emotion == "sad" or emotion == "relaxed" or emotion == "blue" or emotion == "lonely"){teml = 70; temr = 120;}
    srand(unsigned(time(0)));
    int temo = teml + rand() % (temr-teml);
    return temo;
}


/* Function for volume.*/
  /*  O - 1,
     C1 - 2,
     C2 - 3,
     V1 - 4,
     V2 - 5,
     Va - 6,
      B - 7,
      E - 8 */



vector<int> gettpl(int i){
    srand(unsigned(time(0)));
    vector<int> tp1 = {4,5,2,3,4,5,2,3};
    vector<int> tp2 = {4,5,2,3,4,5,2,3,8};
    vector<int> tp3 = {4,5,7,2,3,4,5,7,2,3};
    vector<int> tp4 = {4,5,7,2,3,4,5,7,2,3,8};
    vector<int> tp5 = {4,5,7,2,3,4,5,2,3};
    vector<int> tp6 = {4,5,7,2,3,4,5,2,3,8};
    vector<int> tp7 = {4,5,7,2,3,6,8};
    vector<int> tp8 = {4,5,7,2,3,6,4,5,8};
    vector<int> tp9 = {1,2,3,4,5,7,2,3};
    vector<int> tp10 = {1,2,3,4,5,7,2,3,8};
    vector<int> tp11 = {1,2,3,4,5,2,3,8};
    vector<int> tp12 = {1,4,5,7,2,3,4,5,7,2,3};
    vector<int> tp13 = {1,4,5,7,2,3,4,5,7,2,3,8};
    vector<int> tp14 = {1,4,5,7,2,3,4,5,2,3};
    vector<int> tp15 = {1,4,5,7,2,3,4,5,2,3,8};
    vector<int> tp16 = {1,4,5,7,2,3,4,5,2,3,6,8};
    vector<vector<int>> tptotal = {tp1,tp2,tp3,tp4,tp5,tp6,tp7,tp8,tp9,tp10,tp11,tp12,tp13,tp14,tp15,tp16};
    vector<int> tpl;
    if (i == -1){
        tpl = tptotal[rand()%16];
    }
    if (i != -1){
        tpl = tptotal[i];
    }
    return tpl;
}







