#include <random>
#include <string>
#include <vector>
#include <ctime>
#include <map>
#include "track.h"
#include "chord.h"
using namespace std;
#ifndef ACCOMPANY_H
#define ACCOMPANY_H
/*
 * Class: Accompany
 * ------------------------------
 * Store the accompany.
 * Supposed type: (instrumentCode, (beats per bar, musicType), input tone, tone1, tone2, tone3, tone4...)
 * Or take the format of sheet.
 */

class Accompany
{
public:
    Accompany();
//    Accompany(char genre, char emotion, string instrument, int saturation);
    void init(string genre, string emotion, int saturation, vector<int> template_, int mainTrackNum = 3,int melody = 0);
    Track composer(Track accompanyTrack);

    vector<int> notel;
    vector<string> chordTypeList;
    vector<int> typel = {0,1,2};

    Track piano(int limi = 0);
    Track guitar(int limi = 0);
    Track violinfam(int limi = 0);
    Track bass(int limi = 0);
    Track drum();
    Track mainTrack(int count, int instru);


    vector<int> getNotes(int noteSum, int count, int type = 1);
    vector<int> getTemp(string genre, int flag = 0);
    vector<string> getRule();
    int style = 1;

private:
    string gen; //genre
    string emo; //emotion
    int satu; // saturation j
    int sectionNum;
    vector<vector<vector<int>>> mainPitchToTemplate;
    vector<vector<int>> mainTempToTemplate;
    vector<int> templateList;
    vector<int> mainDistri;

    vector<int> getProgress(string genre);
    vector<string> pushinChordList(string emotion);
    void mainTrackGenerator();

//    map<string,int> genreTrans = {{"pop",'P'},{"rock",'R'},{"jazz",'J'},{"metal",'M'},{"clas",'C'},{"folk", 'F'},{"elec", 'E'}};
//    map<string,int> emotionTrans = {{"sad",'S'},{"relax",'R'},{"happy",'H'},{"excited",'E'},{"nervous",'N'},{"blue", 'B'},{"lonely", 'L'}};
    vector<int> pedalback(vector<int> pitches, int pos);

    //vector<string> randomlist(vector<string> chordlist, int num = 0);
    //int randomi(vector<int> notel, int flag = 0);
    //string randoms(vector<string> notel, int flag = 0);

    Track accompanist(vector<int> noteTem, vector<vector<int>> pitches, int timeset = 0, int volty = 1, int offset = 20, int para = 0);
};




#endif // ACCOMPANY_H
