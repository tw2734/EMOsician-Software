#include "accompany.h"
#include "split.h"
#include "accompany.h"
#include <sstream>
#include <fstream>
#include <bitset>
#include <iomanip>
using namespace std;

Accompany::Accompany(){}

//不同乐器 可 不同和弦，考虑将和弦判断方程分离
void Accompany::init(string genre, string emotion, int saturation, vector<int> template_, int mainTrackNum, int melody)
{
    srand(time(NULL));
    sectionNum = template_.size();
    templateList = template_;
    gen = genre;
    satu = saturation;
    emo = emotion;
    int tem=0;
    int count = 0;
    vector<string> temlist = {};
    vector<int> teml;
    vector<vector<int>> progress;
    mainPitchToTemplate.resize(8);
    mainTempToTemplate.resize(8);
    mainDistri.clear();

//    std::ostringstream mainTrackList;
//    mainTrackList<<std::bitset<3>(mainTrackNum);

//    tem = rand()% 3;
//    for (int i = 0; i < sectionNum; i++) {
//        while (mainTrackList.str()[tem] == '0') {
//            tem = rand()% 3;
//        }
//        mainDistri.push_back(tem);
//    }

    switch(mainTrackNum){
    case 1: mainDistri = randomlisti({2},sectionNum); break;
    case 2: mainDistri = randomlisti({1},sectionNum); break;
    case 3: mainDistri = randomlisti({2,1},sectionNum); break;
    case 4: mainDistri = randomlisti({0},sectionNum); break;
    case 5: mainDistri = randomlisti({0,2},sectionNum); break;
    case 6: mainDistri = randomlisti({1,0},sectionNum); break;
    case 7: mainDistri = randomlisti({0,1,2},sectionNum); break;
    default: break;
    }




    //genre 转换成 和弦进行 >> 一对一关系
    vector<int> temppl = {melody/1000 + 23, melody/100 - (melody/1000)*10 +23,melody/10 - (melody/100)*10 +23, melody- (melody/10)*10 +23};
    notel = (melody == 0) ? getProgress(genre): temppl;
    if(melody != 0) {
        for (int i = 1; i<sectionNum; ++i)
        {
            notel.push_back(temppl[0]);
            notel.push_back(temppl[1]);
            notel.push_back(temppl[2]);
            notel.push_back(temppl[3]);
        }
    }
    else {
        for (int i = 1; i<sectionNum; ++i){
            teml = getProgress(genre);
            while (teml[0] != notel[0]) {
                teml = getProgress(genre);
            }
            for (int k = 0; k < i; ++k) {
                vector<int> newvec(notel.begin()+4 * k,notel.begin()+ 4 * k + 4);
                teml = (template_[i] == template_[k] or
                        (template_[i] ==3 and template_[k] == 2) or
                        (template_[i] ==5 and template_[k] == 4))? newvec :teml;
            }
            notel.push_back(teml[0]);
            notel.push_back(teml[1]);
            notel.push_back(teml[2]);
            notel.push_back(teml[3]);
        }
    }


    //emotion 转换成 和弦类型 >>  一对一关系
    vector<string> temlis;
    for (int p = 0; p < sectionNum; ++p){
        temlis = randomlist(pushinChordList(emotion));
        for (int k = 0; k < p; ++k) {
            vector<string> newvec(chordTypeList.begin()+4 * k,chordTypeList.begin()+ 4 * k + 4);
            temlis = (template_[p] == template_[k] or
                      (template_[p] ==3 and template_[k] == 2) or
                      (template_[p] ==5 and template_[k] == 4))? newvec :temlis;
        }
        for (vector<string>::size_type q = 0; q < temlis.size(); q++) {
            chordTypeList.push_back(temlis[q]);
        }
    }
    mainTrackGenerator();
}

vector<int> Accompany::getProgress(string genre){
    vector<vector<int>> progress;
    switch(toupper(genre[0])){
    case 'P':
        if (rand()%4 < 3)
        {
            progress = {randomlisti({24,27,28,29},4)};
        }
        else
        {
            progress = {{24,27,28,28},{24,29,26,30},{28,28,24,29},{27,29,29,24},{29,28,28,27},{27,26,25,24}};
        }
        break;

    case 'R':
        progress = {{24,27,28,24},{28,29,24,28},{25,27,28,28},{24,27,28,27},{28,27,24,24},{29,28,27,26}
                    ,{29,28,24,27},{25,24,28,30},{25,24,28,28},{25,27,28,28}};
        break;

    case 'J':
        progress = {{25,28,24,24},{24,24,25,28},{24,24,25,25},{24,25,28,27},{24,29,25,28},{26,29,25,28}
                    ,{25,28,25,28}};
        break;

    case 'M':
        progress = {{29,27,24,26},{24,24,28,29},{31,30,27,28},{24,24,29,30},{29,29,31,30},{26,25,24,27}
                    ,{24,29,27,25},{24,27,27,26},{24,24,27,25}};
        break;

    case 'C':
        progress = {{27,28,29,26},{29,28,24,30},{24,30,29,28},{24,27,24,28},{29,25,28,24},{24,25,24,28}
                    ,{24,29,27,25},{24,27,27,26},{24,24,27,25}};
        break;

    case 'F':
        progress = {{24,27,28,24},{24,30,29,30},{26,29,30,30},{30,24,30,24},{24,28,24,28},{27,24,28,24}
                    ,{24,28,27,28},{27,28,24,24}};
        break;
    case 'E':
        if (rand()%4 < 3)
        {
            progress = {randomlisti({24,27,28,29},4)};
        }
        else
        {
            progress = {{24,27,28,28},{24,29,26,30},{28,28,24,29},{28,24,24,29},{27,29,24,24},{29,28,28,27}};
        }
        break;
    }
    return progress[rand()%(progress.size())];
}

vector<string> Accompany::pushinChordList(string emotion){
    int count;
    vector<string> chordl;
    vector<string> temlist = {};
    switch (toupper(emotion[0])) {
    case 'S':
        count = 0;
        for (int i = 0; i < 4 ; i++) {// 只有4个目前
            if (count == 3){
                chordl.push_back("M");
            }
            else if (4-i + count == 2){
                chordl.push_back("m");
            }
            else {
                if (rand()%4 != 0){
                    chordl.push_back("m");
                    count += 1;
                }
                else {
                    chordl.push_back("M");
                }
            }
        }
        break;

    case 'R':
        for (int i = 0; i < 4 ; i++) {
            chordl.push_back(selectone({"sus2","sus4"}, 2, 1));
        }
        if (rand()%2 == 0) {
            chordl[1 + rand()%3] = "M";
        }
        break;

    case 'H':
        if (rand()%2 == 0){
            temlist = {"M","M"};
        }
        temlist.push_back(selectone({"M", "M7", "M9"}, 3,1,1));
        chordl = randomlist(temlist, 4);
        break;
    case 'E':
        chordl = {"M","M","M","M"};
        break;
    case 'N':
        if (rand()%2 == 0){
            temlist = {"M","M"};
        }
        temlist.push_back(selectone({"M", "Dim", "Aug"}, 3,1,1));
        chordl = randomlist(temlist, 4);
        break;
    case 'B':
        chordl = randomlist({"M","m","sus2","sus4"},4);
        break;
    case 'L':
        if (rand()%2 == 0){
            temlist = {"M","M"};
        }
        temlist.push_back(selectone({"M", "m7"},2,1));
        chordl = randomlist(temlist, 4);
        break;
    }
    return chordl;
}

Track Accompany::piano(int limi)
{
    vector<int> chor;
    vector<int> noteTem;
    vector<vector<int>> pitches;
    int noteNum = chordTypeList.size();
    int type;
    int tem;
    if (limi != 0){
        type = limi;
    }
    else {
//        tem = rand()%3;
//        type = typel[tem];
        type = rand()% 6 ;
//        typel.erase(typel.begin()+tem);
    }


    switch (type)
    {
    case 0: case 1:
        switch (satu)
        {
        case 1: noteTem = {1,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0}; noteNum = 1; break;
        case 2: case 3: noteTem = {1,0,0,0, 0,0,0,0, 1,0,0,0, 0,0,0,0}; noteNum = 2; break;
        case 4: noteTem = {1,0,0,0, 1,0,0,0, 1,0,0,0, 0,0,0,0}; noteNum = 3; break;
        case 5: noteTem = {1,0,0,0, 1,0,0,0, 1,0,0,0, 1,0,0,0}; noteNum = 4; break;
        case 6: case 7: noteTem = {1,0,1,0, 0,0,1,0, 1,0,1,0, 0,0,1,0}; noteNum = 6; break;
        case 8: noteTem = {1,0,1,0, 1,0,1,0, 1,0,1,0, 1,0,1,0}; noteNum = 8; break;
        case 9: case 10: noteTem = {1,0,1,0, 1,0,1,0, 1,0,1,0, 1,0,1,0}; noteNum = 8; break;
        }
        for (int i = 0; i < 4 * sectionNum; i++)
        {
            chor = chord(notel[i],chordTypeList[i]); // 随机把位
            for (int j = 0; j < noteNum; j++)
            {
                 pitches.push_back(chor);// 添加更多规则
            }
        }
        return accompanist(noteTem,pitches);



    case 2: case 3: case 4: case 5:

        switch (satu)
        {
        case 1: case 2: case 3:
            if (rand()% 2 == 0){
                noteTem = {1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0}; noteNum = 4;
                for (int i = 0; i < 4 * sectionNum; i++)
                {
                    chor = chord(notel[i],chordTypeList[i]);
                    pitches.push_back({chor[0]-24});
                    pitches.push_back({chor[1]-24});
                    pitches.push_back({chor[2]-24});
                    pitches.push_back({chor[0]-12});
                }
                break;
            }
            else{
                noteTem = {1,0,1,0,1,0,0,0,0,0,1,0,0,0,0,0}; noteNum = 4;
                for (int i = 0; i < 4 * sectionNum; i++)
                {
                    chor = chord(notel[i],chordTypeList[i]);
                    pitches.push_back({chor[0]-24});
                    pitches.push_back({chor[1]-24});
                    pitches.push_back({chor[2]-24});
                    pitches.push_back({chor[2]-24});
                }
                break;
            }


        case 4: noteTem = {1,0,1,0,1,0,0,0,1,0,1,0,1,0,0,0}; noteNum = 4;
            for (int i = 0; i < 4 * sectionNum; i++)
            {
                chor = chord(notel[i],chordTypeList[i]);
                pitches.push_back({chor[0]-24});
                pitches.push_back({chor[1]-24});
                pitches.push_back({chor[2]-24});
                pitches.push_back({chor[0]-12});
                pitches.push_back({chor[1]-24});
                pitches.push_back({chor[2]-24});
            }
            break;

        case 5: case 6:
            if (rand()% 2 == 0){
                noteTem = {1,0,1,0, 1,0,1,0, 1,0,1,0, 1,0,0,0}; noteNum = 7;
                for (int i = 0; i < 4 * sectionNum; i++)
                {
                    chor = chord(notel[i],chordTypeList[i]);
                    pitches.push_back({chor[0]-12});
                    pitches.push_back({chor[1]-12});
                    pitches.push_back({chor[2]-12});
                    pitches.push_back({chor[1]-12});
                    pitches.push_back({chor[2]-12});
                    pitches.push_back({chor[1]-12});
                    pitches.push_back({chor[2]-12});
                }
                break;
            }
            else if(rand() % 2 == 0 and emo != "nervous" and emo != "lonely" and emo != "blue" and emo != "sad" ){
                noteTem = {1,0,0,0,0,0,1,0,1,0,1,0,1,0,1,0}; noteNum = 6;
                for (int i = 0; i < 4 * sectionNum; i++)
                {
                    chor = chord(notel[i],"M",0);
                    pitches.push_back({chor[0]-12, chor[1]-12, chor[2]-12});
                    pitches.push_back({chor[0]-12, chor[1]-12, chor[2]-12});
                    pitches.push_back({chor[1]-12});
                    pitches.push_back({chor[0]-12});
                    pitches.push_back({chor[0]-12, chor[0]-12+2});
                    pitches.push_back({chor[0]-12});
                }
                return accompanist(noteTem,pitches,0);
            }

            else{
                for (int i = 0; i < 4 * sectionNum; i++)
                {
                    noteTem = {1,0,1,0, 1,0,1,0, 1,0,1,0, 1,0,1,0}; noteNum = 8;
                    chor = chord(notel[i],chordTypeList[i],0);
                    pitches.push_back({chor[0]-24});
                    pitches.push_back({chor[2]-24});
                    pitches.push_back({chor[0]-12});
                    pitches.push_back({chor[1]-12});
                    pitches.push_back({chor[2]-12});
                    pitches.push_back({chor[1]-12});
                    pitches.push_back({chor[0]-12});
                    pitches.push_back({chor[2]-24});
                }
                break;
            }

        case 7: case 8: case 9: case 10: noteTem = {1,0,1,0, 1,0,1,0, 1,0,1,0, 1,0,1,0}; noteNum = 8;
            if (rand()% 2 == 0){
                for (int i = 0; i < 4 * sectionNum; i++)
                {
                chor = chord(notel[i],chordTypeList[i]);
                pitches.push_back({chor[0]-12});
                pitches.push_back({chor[1]-12});
                pitches.push_back({chor[2]-12});
                pitches.push_back({chor[1]-12});

                pitches.push_back({chor[2]-12});
                pitches.push_back({chor[1]-12});
                pitches.push_back({chor[2]-12});
                pitches.push_back({chor[1]-12});
                }break;
            }
            else
                {
                for (int i = 0; i < 4 * sectionNum; i++)
                {
                    chor = chord(notel[i],chordTypeList[i],0);
                    pitches.push_back({chor[0]-24});
                    pitches.push_back({chor[2]-24});
                    pitches.push_back({chor[0]-12});
                    pitches.push_back({chor[1]-12});
                    pitches.push_back({chor[2]-12});
                    pitches.push_back({chor[1]-12});
                    pitches.push_back({chor[0]-12});
                    pitches.push_back({chor[2]-24});
                }
                break;
            }
        }
//        vector<vector<int>> pianoTem = {{1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0},
//                                        {1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0},
//                                        {1,0,1,0,1,0,1,0,1,0,1,0,1,0,0,0}};
//        pianoTra.init("piano",12);
//        noteTem = {1,0,1,0,1,0,1,0,1,0,1,0};
//        noteTem = {1,0,1,0,0,1,1,0,1,0,0,1};
        return accompanist(noteTem,pitches,0,4);
    }
}

//guitar，（可）配合accompanist 中 voltype, 制造更多轻重音种类
Track Accompany::guitar(int limi)
{
    vector<int> chor;
    vector<int> noteTem;
    vector<vector<int>> pitches = {};
    int type;
    int noteNum;
    int tem;

    if (limi != 0){
        type = limi;
    }
    else {
//        tem = rand()%3;
//        type = typel[tem];
        type = rand()% 6 ;
//        typel.erase(typel.begin()+tem);
    }

    vector<int> fullTrack = {1,0,1,0, 1,0,1,0, 1,0,1,0, 1,0,1,0};
    vector<int> emptyTrack ={1,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0};
    int pointer = 1+rand()%15;

    switch(type){
    case 0: case 1:
        switch (satu) {
        case 1: noteTem = emptyTrack; noteNum = 1; break;
        case 2: case 3: case 4: case 5: case 6: case 7:
            noteTem = emptyTrack;
            for (int k = 0; k< satu -1; k++){
                while(noteTem[pointer] == 1){
                    pointer = 1+rand()%15;
                }
                noteTem[pointer] = 1;
            }
            noteNum = satu;
            break;
         case 8: case 9: case 10:
            noteTem = fullTrack; noteNum = 8; break;
        }
        for (int i = 0; i < 4 * sectionNum; i++){
            chor = chord(notel[i],chordTypeList[i]); // 随机把位
            pitches.push_back({chor[2]-36, chor[1]-24, chor[0]-12});
            for (int j = 0; j < noteNum - 1; j++) {
                 pitches.push_back({chor[2]-24, chor[1]-12, chor[0]});// 添加更多规则
            }
        }
        return accompanist(noteTem,pitches,0,2);

     case 2: case 3: case 4: case 5:
        noteTem = {1,0,1,0, 1,0,1,0, 1,0,1,0, 1,0,1,0};
        for (int i = 0; i < 4 * sectionNum; i++){
            chor = chord(notel[i],chordTypeList[i],1); // 第一把位
            pitches.push_back({chor[0]-36});
            for (int j = 0; j < 7; j++) {
                pitches.push_back({randomi({chor[1]-36, chor[1]-24, chor[1]-12,
                                          chor[2]-36, chor[2]-24, chor[2]-12,
                                          chor[0]-36, chor[0]-24, chor[0]-12})}); // 添加更多规则
            }
        }
        return accompanist(noteTem,pitches);
    }
}

//violin， 和弦分解
Track Accompany::violinfam(int limi)
{
    vector<int> chor;
    vector<int> noteTem;
    vector<vector<int>> pitches = {};
    int type;
    int tem;

    if (limi != 0){
        type = limi;
    }
    else {
//        tem = rand()%3;
//        type = typel[tem];
        type = rand()% 5 ;
//        typel.erase(typel.begin()+tem);
        }

        // convert function

//    int pointer = 1+rand()%15;
    switch(type){
    case 0: case 1: case 2: case 3:case 4: case 5:
        noteTem = {1,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0};
        for (int i = 0; i < 4 * sectionNum; i++){
            chor = chord(notel[i],chordTypeList[i]); // 随机把位
            pitches.push_back(chor);
        }
        break;
    }
   return accompanist(noteTem,pitches,0,0);
}

// bass， 和弦多押
Track Accompany::bass(int limi)
{
    Track bassTra;
    for (int j = 0; j < 4 * sectionNum; j++)
    {
        for (int i = 0; i < 8; i++)
        {
            bassTra.add({chord(notel[j],"M",1)[0] - 36 + 20}
                ,1 + 0.1 * int(i == 0)
                        ,{2 * i+ 0.0 + 16 * j, 2 * i+1.9+ 16 * j});
        }
    }
    bassTra.setSize();
    bassTra.seti(0);
    return bassTra;
};

//drum:
Track Accompany::drum(){
    vector<int> noteTem;
    vector<vector<int>> pitches;

    vector<int> noteTeml;
    vector<vector<int>> pitchesl;

    switch (toupper(gen[0])) {
    case 'R':
        for (int i=0;i<int(templateList.size());i++) {
            switch (templateList[i]) {
            case 1:
                noteTem = {1,0,0,0 ,1,0,1,0 ,1,0,0,1 ,1,0,0,0};
                pitches = {{36},{38,46},{36},{36,48},{36},{38,46}};break;
            case 2:
            case 3:
                noteTem = {1,0,1,1 ,1,0,1,1 ,1,0,1,0 ,1,0,1,1};
                pitches = {{36,57},{36,57},{38},{36,57},{57},{38},{36,57},{36,57},{36,57,38},{57},{38}};break;
            case 4:
            case 5:
                noteTem = {1,0,1,1 ,1,0,1,0 ,1,0,1,0 ,1,0,1,1};
                pitches = {{36,51},{36,51},{38},{36,51},{51},{51},{51},{51,38},{51},{38}};break;
            case 6:
                noteTem = {1,0,1,1 ,1,0,1,1 ,1,0,1,0 ,1,0,1,1};
                pitches = {{36,57},{36,57},{38},{36,57},{57},{38},{36,57},{36,57,58},{57},{36,38}};break;
            case 7:
                noteTem = {1,0,1,1 ,1,0,1,0 ,1,0,1,1 ,1,0,1,0};
                pitches = {{36,47},{47},{36},{47,38},{47},{47},{47},{36},{47,38},{47}};break;
            case 8:
                noteTem = {1,0,0,0 ,1,0,1,0 ,1,0,0,1 ,1,0,0,0};
                pitches = {{36},{38,46},{36},{36,46},{36},{38,46}};

            }
            for (int o = 0; o < 4; o++){
                for (int i = 0; i < 16; i++){
                    noteTeml.push_back(noteTem[i]);
                }
                for (int i = 0; i < pitches.size(); i++){
                    pitchesl.push_back(pitches[i]);
                }
            }
        }break;
    case 'C':
        //有待修改
        break;
    case 'P':
        for (int a=0;a<int(templateList.size());a++) {
            switch (templateList[a]) {
            case 1:
                noteTem = {1,0,0,0 ,1,0,0,0 ,1,0,0,0 ,1,0,0,0};
                pitches = {{36},{36},{36},{36}};break;
            case 2:
            case 3:
                noteTem = {1,0,1,0 ,1,0,1,1 ,1,1,1,0 ,1,0,1,1};
                pitches = {{36,51},{36,51},{51,38,42},{36,51},{38},{36,51},{38},{36,51},{51,38,42},{51},{38}};break;
            case 4:
            case 5:
                noteTem = {1,0,1,0 ,1,0,1,0 ,1,0,1,0 ,1,0,1,0};
                pitches = {{36},{42},{38,46},{36,42},{44},{36,42},{38,46},{42}};break;
            case 6:
                noteTem = {1,0,1,0 ,1,0,1,1 ,1,1,1,0 ,1,0,1,1};
                pitches = {{36,51},{36,51},{51,38,42},{36,51},{38},{36,51},{38},{36,51},{51,38,42},{36,51},{38}};break;
            case 7:
                noteTem = {1,0,0,0 ,1,0,1,0 ,0,0,1,0 ,1,0,0,0};
                pitches = {{36},{38,42,46},{38,42},{36,44},{38,42,46}};break;
            case 8:
                noteTem = {1,0,0,0 ,1,0,1,0 ,1,0,0,0 ,1,0,0,0};
                pitches = {{36},{36,38},{38},{36},{36,38}};
            }
            for (int o = 0; o < 4; o++){
                for (int i = 0; i < 16; i++){
                    noteTeml.push_back(noteTem[i]);
                }
                for (int i = 0; i < pitches.size(); i++){
                    pitchesl.push_back(pitches[i]);
                }
            }
        }break;
    case 'E':
        for (int a=0;a<int(templateList.size());a++) {
            switch (templateList[a]) {
            case 1:
                noteTem = {1,0,0,0 ,0,0,0,0 ,1,0,0,0 ,0,0,0,0};
                pitches = {{40},{40}};break;
            case 2:
            case 3:
                noteTem = {1,1,1,0 ,1,0,1,0 ,1,0,1,0 ,1,0,1,1};
                pitches = {{36,44},{44},{39,44},{44},{36,39,44},{40,44},{39},{40,44},{36},{44}};break;
            case 4:
            case 5:
                noteTem = {1,0,0,0 ,1,0,0,0 ,1,0,0,0 ,1,0,0,0};
                pitches = {{36,},{40},{36},{40}};break;
            case 6:
                noteTem = {1,0,0,0 ,1,0,0,0 ,1,0,0,0 ,1,0,0,0};
                pitches = {{36,},{40},{36},{40}};break;
            case 7:
                noteTem = {1,0,0,0 ,1,0,0,0 ,1,0,0,0 ,0,0,0,0};
                pitches = {{36},{36},{57}};break;
            case 8:
                noteTem = {1,0,0,0 ,0,0,0,0 ,1,0,0,0 ,1,0,0,0};
                pitches = {{40},{40},{55}};
            }
            for (int o = 0; o < 4; o++){
                for (int i = 0; i < 16; i++){
                    noteTeml.push_back(noteTem[i]);
                }
                for (int i = 0; i < pitches.size(); i++){
                    pitchesl.push_back(pitches[i]);
                }
            }
        }break;
    case 'F':
        for (int a=0;a<int(templateList.size());a++) {
            switch (templateList[a]) {
            case 1:
                noteTem = {1,0,0,0 ,0,0,0,0 ,1,0,0,0 ,1,0,0,0};
                pitches = {{64},{64},{54}};break;
            case 2:
            case 3:
                noteTem = {1,0,1,1 ,1,0,1,0 ,1,0,1,0 ,1,0,1,0};
                pitches = {{35,54},{54},{35},{54,38},{35,54},{35,54},{54},{54,38},{54}};break;
            case 4:
            case 5:
                noteTem = {1,1,0,0 ,1,0,0,1 ,1,0,1,0 ,1,0,0,0};
                pitches = {{36},{54},{54},{54},{35},{54},{54}};break;
            case 6:
                noteTem = {1,0,1,1 ,1,0,0,0 ,1,0,0,0 ,1,0,0,0};
                pitches = {{36,54},{54},{35},{54,38},{35,54},{35,54},{54},{54,38},{54}};break;
            case 7:
                noteTem = {1,0,1,0 ,1,0,1,0 ,1,0,1,0 ,1,0,1,0};
                pitches = {{35,37},{37},{37},{37},{35,37},{37},{37},{37}};break;
            case 8:
                noteTem = {1,0,0,0 ,1,0,0,0 ,1,0,0,0 ,1,0,0,0};
                pitches = {{64},{64},{64},{54}};
            }
            for (int o = 0; o < 4; o++){
                for (int i = 0; i < 16; i++){
                    noteTeml.push_back(noteTem[i]);
                }
                for (int i = 0; i < pitches.size(); i++){
                    pitchesl.push_back(pitches[i]);
                }
            }
        }break;
    case 'J':
        for (int a=0;a<int(templateList.size());a++) {
            switch (templateList[a]) {
            case 1:
                noteTem = {1,0,1,1 ,1,0,1,1 ,1,1,1,1 ,0,1,0,1};
                pitches = {{36,54},{54},{38},{54},{38,54},{54},{36,54},{38},{36},{54},{54},{54}};break;
            case 2:
            case 3:
                noteTem = {1,1,1,1 ,1,0,1,1 ,1,0,0,0 ,0,1,0,1};
                pitches = {{36,59,42},{40},{59,42},{36},{59,42},{36,59,42},{36},{59,42},{36,59,42},{40}};break;
            case 4:
            case 5:
                noteTem = {1,0,0,0 ,1,0,1,0 ,1,0,0,0 ,1,0,1,0};
                pitches = {{36,59,42},{59,38,42},{59,42},{59,42},{59,38,42},{59,42}};break;
            case 6:
                noteTem = {1,1,1,1 ,1,0,1,1 ,1,0,0,0 ,0,1,0,1};
                pitches = {{36,59,42},{40},{59,42},{36},{59,42},{36,59,42},{36},{59,42},{36,59,42},{40}};break;
            case 7:
                noteTem = {1,0,1,1 ,0,1,0,0 ,1,0,0,1 ,0,1,0,0};
                pitches = {{36},{40},{36},{59},{36,59},{40},{36}};break;
            case 8:
                noteTem = {1,0,1,1 ,1,0,1,1 ,1,1,1,1 ,0,1,0,1};
                pitches = {{36,54},{54},{38},{54},{38,54},{54},{36,54},{38},{36},{36},{54},{54},{54}};
            }
            for (int o = 0; o < 4; o++){
                for (int i = 0; i < 16; i++){
                    noteTeml.push_back(noteTem[i]);
                }
                for (int i = 0; i < pitches.size(); i++){
                    pitchesl.push_back(pitches[i]);
                }
            }
        }break;
    case 'M':
        for (int a=0;a<int(templateList.size());a++) {
            switch (templateList[a]) {
            case 1:
                noteTem = {1,0,0,0 ,0,0,0,0 ,1,0,0,0 ,1,0,0,0};
                pitches = {{36,38,45},{36,45,38},{36,45,38},};break;
            case 2:
            case 3:
                noteTem = {1,1,1,1 ,1,1,1,1 ,1,1,1,1 ,1,1,1,1};
                pitches = {{36},{57},{36},{57},{36},{57},{36,38},{57},{36},{57},{36,38},{57},{36},{57},{36},{57,58}};break;
            case 4:
            case 5:
                noteTem = {1,0,1,0 ,1,0,1,0 ,1,0,1,0 ,1,0,1,0};
                pitches = {{36,57,38},{57},{36,57,38},{57},{36,57,38},{57},{36,57,38},{57}};break;
            case 6:
                noteTem = {1,1,1,1 ,1,1,1,1 ,1,1,1,1 ,1,1,1,1};
                pitches = {{36},{57},{36},{57},{36},{57},{36,38},{57},{36},{57},{36,38},{57},{36},{57},{36},{57,58}};break;
            case 7:
                noteTem = {1,1,0,1 ,0,1,0,0 ,1,0,1,0 ,1,0,0,0};
                pitches = {{36},{45},{47,38},{48},{36,45,38},{47},{36,48,38}};break;
            case 8:
                noteTem = {1,1,1,1 ,1,0,1,0 ,1,1,1,0 ,1,0,1,0};
                pitches = {{36},{38},{36},{38},{36,38},{36,38},{36},{38},{36},{36,38},{36,38}};
            }
            for (int o = 0; o < 4; o++){
                for (int i = 0; i < 16; i++){
                    noteTeml.push_back(noteTem[i]);
                }
                for (int i = 0; i < pitches.size(); i++){
                    pitchesl.push_back(pitches[i]);
                }
            }
        }
    }
    return accompanist(noteTeml,pitchesl,0,1,0);
}

//chord()方程会转化至 12 平均律， 因此在此处没有转化
//注意对一下算法是否准确 正确
Track Accompany::accompanist(vector<int> noteTem, vector<vector<int>> pitches, int timeset, int volset, int offset, int para)
{
    Track track;
    vector<double> time;
    vector<int> pitchl;
    int tem;

    if (timeset == 0)
    { // 填充型
        for (int i = 0; i < noteTem.size(); i++)
        {
            int leap = 1;
            if(noteTem[i % noteTem.size()]==1){
            while(noteTem[(i+1)% noteTem.size()]==0 and i + 1 < noteTem.size()){
                leap = leap + 1;
                i = i+1;
            }
            time.push_back(leap-0.1);
            }
//            time.push_back(leap-0.1);
        }
    }

    else if (timeset == 1)
    { // 延音型1
        for (int i = 0; i < pitches.size(); i++)
        {
            time.push_back(15);
        }
    }

    else if (timeset == 2)
    { // 延音型2
         for (int i = 0; i < noteTem.size(); i++)
        {
            if (noteTem[i] == 1){
                time. push_back(16-(i&16));
            }
        }
    }


    else if (timeset == 3)
    { // 跳音型
        for (int i = 0; i < pitches.size(); i++)
        {
            time.push_back(0.3);
        }
    }

    else if (timeset == 4)
    { // 切分型
        bool ls = true;
        for (int i = 0; i < noteTem.size(); i++)
        {
            int leap = 1;
            while(noteTem[i+1]==0)
            {
                leap = leap + 1;
                i = i+1;
            }
            if (ls)
            {
                time.push_back(leap-0.1);
            }
            else
            {
                time.push_back(0.3);
            }
            ls = !ls;
        }

    }


    if (volset == 0){
        if (noteTem.size() == 16)
        {
            tem = 64 * sectionNum;
        }
        else
        {
            tem = noteTem.size();
        }
        int k = 0;
        for (int i = 0; i < tem; i++){
            pitchl.clear();
            if(noteTem[i % noteTem.size()] == 1){
                for (int j=0; j<pitches[k].size(); ++j)
                {
                    pitchl.push_back(pitches[k % pitches.size()][j] + offset);
                }
                if (i % 16 == 0)
                {
                    track.add(pitchl,1.5/(pitches[k].size()),{double(i), double(i+time[k % time.size()])});
                }
                else
                {
                    track.add(pitchl,1.4/(pitches[k].size()),{double(i), double(i+time[k % time.size()])});
                }
                k = k + 1;
            }
        }
        track.setSize();
        track.seti(0);
        return track;
    }
    // 首音 重音型
    if (volset == 1){
        if (noteTem.size() == 16)
        {
            tem = 64 * sectionNum;
        }
        else
        {
            tem = noteTem.size();
        }
        int k = 0;
        for (int i = 0; i < tem; i++){
            pitchl.clear();
            if(noteTem[i % noteTem.size()] == 1){
                for (int j=0; j<pitches[k].size(); ++j)
                {
                    pitchl.push_back(pitches[k % pitches.size()][j] + offset);
                }
                if (i % 16 == 0)
                {
                    track.add(pitchl,1.1,{double(i), double(i+time[k % time.size()])});
                }
                else
                {
                    track.add(pitchl,1.0,{double(i), double(i+time[k % time.size()])});
                }
                k = k + 1;
            }
        }
        track.setSize();
        track.seti(0);
        return track;
    }
    //
    if (volset == 2){
        if (noteTem.size() == 16)
        {
            tem = 64 * sectionNum;
        }
        else
        {
            tem = noteTem.size();
        }
        int k = 0;
        for (int i = 0; i < tem; i++){
            pitchl.clear();
            if(noteTem[i % noteTem.size()] == 1){
                if (i % 16 == 0)
                {
                    for (int j=0; j<pitches[k].size(); ++j)
                    {
                        track.add({pitches[k % pitches.size()][j] + offset},3/pitches[k].size(),{double(i) + 0.25 * j, double(i+15.5)});
                    }
                }
                else
                {
                    for (int j=0; j<pitches[k].size(); ++j)
                    {
                        track.add({pitches[k % pitches.size()][j] + offset},3/pitches[k].size(),{double(i) + 0.25 * j, double(i+time[k % time.size()])});
                    }
                }
                k = k + 1;
            }
        }
        track.setSize();
        track.seti(0);
        return track;
    }
    if (volset == 3){
        if (noteTem.size() == 16)
        {
            tem = 64 * sectionNum;
        }
        else
        {
            tem = noteTem.size();
        }
        int k = 0;
        double t = 0;
        for (int i = 0; i < tem; i++){
            pitchl.clear();
            if(noteTem[i % noteTem.size()] == 1){
                for (int j=0; j<pitches[k].size(); ++j)
                {
                    pitchl.push_back(pitches[k % pitches.size()][j] + offset);
                }
                t = time[k % time.size()];
                if (t > 10) t = 2;
                if (i % 16 == 0)
                {
                    track.add(pitchl,1.1,{double(i), double(i+t)});
                }
                else
                {
                    track.add(pitchl,1.0,{double(i), double(i+t)});
                }
                k = k + 1;
            }
        }
        track.setSize();
        track.seti(0);
        return track;
    }
    if (volset == 4){
        if (noteTem.size() == 16)
        {
            tem = 64 * sectionNum;
        }
        else
        {
            tem = noteTem.size();
        }
        int k = 0;
        for (int i = 0; i < sectionNum * 4; i++){
            if (pitches[k % pitches.size()].back() > 34){
                for (int r = 0; r <16; r++){
                    pitchl.clear();
                    if(noteTem[(i * 16 + r) % noteTem.size()] == 1){
                        for (int pitchSize=0; pitchSize<pitches[k % pitches.size()].size(); ++pitchSize){
                            pitchl.push_back(pitches[k % pitches.size()][pitchSize] + offset -12);
                        }
                        if (r == 0)
                        {
                            track.add(pitchl,1.1,{double(i * 16 + r), double(i * 16 + r + time[k % time.size()])});
                        }
                        else
                        {
                            track.add(pitchl,1.0,{double(i * 16 + r), double(i * 16 + r + time[k % time.size()])});
                        }
                        k = k + 1;
                    }
                }
            }
            else {
                for (int r = 0; r <16; r++){
                    pitchl.clear();
                    if(noteTem[(i * 16 + r) % noteTem.size()] == 1){
                        for (int pitchSize=0; pitchSize<pitches[k % pitches.size()].size(); ++pitchSize){
                            pitchl.push_back(pitches[k % pitches.size()][pitchSize] + offset);
                        }
                        if (r == 0)
                        {
                            track.add(pitchl,1.1,{double(i * 16 + r), double(i * 16 + r + time[k % time.size()])});
                        }
                        else
                        {
                            track.add(pitchl,1.0,{double(i * 16 + r), double(i * 16 + r + time[k % time.size()])});
                        }
                        k = k + 1;
                    }
                }
            }
        }
        track.setSize();
        track.seti(0);
        return track;
    }
    return track;
}

// condition function
Track Accompany::composer(Track accompanyTrack)
{
    int inst = accompanyTrack.i();
    Track voidTrack;
    switch(inst)
    {
    case 0: case 1: case 3: case 11: case 85: case 88: case 90: case 91: case 92: case 93:
    case 94: case 95: case 96: case 97: case 98: case 99: case 100: case 101: case 102: case 103:
        return piano();
    case 24: case 25: case 26: case 27: case 28: case 29: case 30: case 87:
        return guitar();
    case 48: case 49: case 89:
        return violinfam();
    case 32: case 33: case 34: case 35: case 36: case 37: case 42:
        return bass();
    case -2: return drum();
    default: return voidTrack;
    }
}


/*
 * A part has 4 sections, section 1, 2 are basically the same as section 3, 4.
 * Section 1 and 2 have some similarity in rhythm type and note progress.
 * The sample are seted to max 16, generally 8 notes a section.
 */


// 概率调整
vector<string> Accompany::getRule()
{
    vector<string> mainTemp;
    mainTemp.push_back(selectone({"sequentia","pedalback"},2,1));
    mainTemp.push_back(selectone({"sequentia","pedalback","random"},5,2,2));
    if(rand()%2 == 1)
    {
        mainTemp.push_back("random");
    }
    mainTemp = randomlist(mainTemp, 4);
    return mainTemp;
}

//int Acompany::randomOn12Key(int lastKey, int mode =  0, int section)
//{
//    int num = rand() % 100;
////    int lastnote = notel[count];
//    int gap = 0;
//    if (section < 4)
//    {
//        switch((lastKey - mode)%12)
//        {
//            case 0:
//            gap = gapGenerator(10,15,20,25,30,35,
//                               40,45,0,55,60,65,
//                               70,
//                               0,60,55,50,45,40,
//                               35,30,25,20,15,10); break;
//            case 1:
//        }
//        lastKey = lastKey + gap;
//        return lastKey;
//    }
//    else
//    {
//        switch((lastKey - mode)%12)
//        {
//            case 0:
//            gap = gapGenerator(30,35,20,25,30,35,
//                               20,25,0,55,60,65,
//                               70,
//                               0,60,55,50,45,40,
//                               35,30,25,20,15,10); break;
//            case 1:
//        }
//        lastKey = lastKey + gap;
//        return lastKey;
//    }
//}

//int Accompany::gapGenerator(int intm12,int intm11,int intm10,int intm9,int intm8,int intm7,
//                            int intm6,int intm5,int intm4,int intm3,int intm2, int intm1,
//                            int int0, int int1,int int2,int int3,int int4,int int5,int int6,
//                            int int7,int int8,int int9,int int10,int int11, int int12)
//{
//    srand(unsigned(time(0)));
//    int num = rand() % 1000;
//    int gap = 0;
//    if (num<intm12){gap =-12;return gap;} num -= intm12;
//    if (num<intm11){gap =-11;return gap;} num -= intm11;
//    if (num<intm10){gap =-10;return gap;} num -= intm10;
//    if (num<intm9){gap =-9;return gap;} num -= intm9;
//    if (num<intm8){gap =-8;return gap;} num -= intm8;
//    if (num<intm7){gap =-7;return gap;} num -= intm7;
//    if (num<intm6){gap =-6;return gap;} num -= intm6;
//    if (num<intm5){gap =-5;return gap;} num -= intm5;
//    if (num<intm4){gap =-4;return gap;} num -= intm4;
//    if (num<intm3){gap =-3;return gap;} num -= intm3;
//    if (num<intm2){gap =-2;return gap;} num -= intm2;
//    if (num<intm1){gap =-1;return gap;} num -= intm1;
//    if (num<int0){gap =0;return gap;} num -= int0;
//    if (num<int1){gap =1;return gap;} num -= int1;
//    if (num<int2){gap =2;return gap;} num -= int2;
//    if (num<int3){gap =3;return gap;} num -= int3;
//    if (num<int4){gap =4;return gap;} num -= int4;
//    if (num<int5){gap =5;return gap;} num -= int5;
//    if (num<int6){gap =6;return gap;} num -= int6;
//    if (num<int7){gap =7;return gap;} num -= int7;
//    if (num<int8){gap =8;return gap;} num -= int8;
//    if (num<int9){gap =9;return gap;} num -= int9;
//    if (num<int10){gap =10;return gap;} num -= int10;
//    if (num<int11){gap =11;return gap;} num -= int11;
//    if (num<int12){gap =12;return gap;} num -= int12;
//}


//概率调整， 算法重构
vector<int> Accompany::getNotes(int noteSum, int count, int type)
{

    //！！需要改进
    // 黑键音， O,E 5度内， 非小4度，小2度
    //（可），不与分解撞音

    
    int wards;
    vector<int> randPitches;
//    if(type == 2)
//    {
//        type = rand()%1;
//    }
//    if (type == 0)
//    {

//    }
//    if (type == 1) // 随机
//    {
        for (int i = 0; i < noteSum; i++)
        {
            int num = rand() % 100;
            int lastnote = notel[count];
            int gap = 0;
            if (num<15){}
            
            else if (num<25)
            {
                gap = 1;
            }
            else if (num<40)
            {
                gap = 2;
            }
            else if (num<55)
            {
                gap = 3;
            }
            else if (num<80)
            {
                gap = 4;
            }
            else if (num<90)
            {
                gap = 5;
            }
            else if (num<96)
            {
                gap = 6;
            }
            else if (num<100)
            {
                gap = 7;
            }
            wards = (rand() % 1) * 2 - 1;
            lastnote = lastnote + gap * wards;
            if (type == 1)
                randPitches.push_back(lastnote - 1 + (lastnote-1)/7 * 5 + (lastnote-1)%7 - ((lastnote)%7)/3 + 1);
            else
                randPitches.push_back(lastnote);
            //pitches.push_back(lastnote + lastnote/7 * 5 + (lastnote)%7 - ((lastnote)%7+1)/3 + mode); // True note place
//            for (int i = 0 ;i < ty.size(); i++){
//                mi = ty[i];
//                if (mi.back()== '#'){
//                    mi.erase(mi.end()-1);
//                    keyposi = stoi(mi)+key-1;
//                    notel.push_back(keyposi + keyposi/7 * 5 + (keyposi)%7 - ((keyposi)%7)/3 + modemap[ma]);
//                }
//                else if (mi.back() == 'b'){
//                    mi.erase(mi.end()-1);
//                    keyposi = stoi(mi)+key-1;
//                    notel.push_back(keyposi + keyposi/7 * 5 + (keyposi)%7 - ((keyposi)%7)/3 - 2 + modemap[ma]);
//                }
//                else{
//                    keyposi = stoi(mi)+key-1;
//                    notel.push_back(keyposi + keyposi/7 * 5 + (keyposi)%7 - ((keyposi)%7)/3 - 1 + modemap[ma]);
//                }
//            }
        }
        return randPitches;
    }


//概率调整，style 相关, style possibility. Jazz
vector<int> Accompany::getTemp(string genre, int flag)
{
    vector<int> tem;    //{ 1, 0, 1, 0, 1, 1, 0, 1}
    vector<int> notes;
    vector<int> time;

    int s1ze = 0;
    int noteSum = 0;

    int insert_note_num = 0;
    int delete_note_num = 0;

    // random time template
    // Determine "template" of a section.
    // Initialization

/*    switch (genre)
    {
    case 0:       */                  //pop
        if (style == 1)
        {            //noisy     //1,0,1,0....
            // Number of this can change
//            int fill1 = (rand() % 8)*2;
//            int fill2 = (2 + (rand() % 7)*2 + fill1)%16;
//            int fill3 = (rand() % 3)*2;
//            tem[fill1+1] = 1;
//            tem[fill2+1] = 1;
//            tem[fill3+1] = 1;
            for (int i = 0; i < 8; i++)
            {
                tem.push_back(1);
                tem.push_back(0);
            }

            //更换此处完成固定插入数量
            insert_note_num = rand() %4 ;
            delete_note_num = rand() %2 ; // 18morn gaiguo
        }
        else if (style == 0)
        {
            for (int i = 0; i < 4; i++)
            {
                tem.push_back(1);
                tem.push_back(0);
                tem.push_back(0);
                tem.push_back(0);
            }

            insert_note_num = rand() %2;
            delete_note_num = rand() %1; // 18morn gaiguo
        }
        for (int i = 0; i < insert_note_num; i++)
        {
            bool f = true;
            int index = 0;
            while (f)
            {
                f = true;
                index = (style == 1) ? rand() % 16: 2 * rand() % 8;
                if (tem[index] == 0)
                {
                    f = false;
                    tem[index] = 1;
                }
            }
        }
        for (int i = 0; i < delete_note_num; i++)
        {
            bool f = true;
            int index = 0;
            while (!f)
            {
                f = true;
                index = rand() % 16 ;
                if (tem[index] == 1)
                {
                    f = false;
                    tem[index] = 0;
                }
            }
        }
        for (int i = 0; i < tem.size(); i++)
        {
            noteSum += tem[i];
        }

// Change tem for second section
        s1ze = tem.size();
//            for (int i = 0; i < s1ze; i++){
//                tem.push_back(tem[i]);
//            }
//            tem[rand() % 8 + 16] = 0;
//            tem[rand() % 8 + 16] = 1;
//            tem[rand() % 8 + 24] = 0;
//            tem[rand() % 8 + 24] = 1;
//            blank1 = rand() % 6 + 9;
//            tem[blank1+16] = 0;tem[blank1 + 17] = 0;
//            s1ze = tem.size();
//        for (int i = 0; i < s1ze * 3; i++)
//        {
//            tem.push_back(tem[i]);
//        }
//    }
    return tem;



// Pitches generation
// It generate excceed notes..
// Maybe also related to genre


//    gap = rand()%3;
//    pitches[blank1 + 48] += gap;

// Turn into track
//    Track mainTrack;

//    for (int i = 0; i < 64; i++){
//        if(notes[i] != 0){
//            mainTrack.add({notes[i]},10.0,{double(i), double(i+time[i])});
//        }
//}
//    mainTrack.setSize();
//    mainTrack.seti(0);
//    return 0;
}

//摸进
vector<int> sequentia(vector<int> pitches, int times)
{
    vector<int> notelist;
    for (int i=0;i<times;++i)
    {
    notelist.push_back(pitches[(i/2) % pitches.size()]);
    }
    return notelist;
}

//踏板音
vector<int> Accompany::pedalback(vector<int> pitches, int pos)
{
    vector<int> notelist;
    int temint = randomi({0,2});
    for (int i=0;i<pitches.size();++i)
    {
        if (i % 2 == 0){
            notelist.push_back(pitches[i/2]);
        }
        else {
            notelist.push_back(chord(notel[pos],"M",temint)[0]);
        }
    }
    return notelist;
}

//call this
void Accompany::mainTrackGenerator()
{
    vector<string> rules;
    int tem;
    vector<int> teml;
    vector<int> templatel;
    vector<int> templateL;
    vector<vector<int>> mainPitch;
    for(int part=0; part < sectionNum; ++part)
    {
        mainPitch.clear();
        templateL.clear();
        if(mainPitchToTemplate[templateList[part]-1].size() == 0 and
                mainTempToTemplate[templateList[part]-1].size() == 0){
            for (int section = 0; section < 4; ++section)
            {
                templatel = getTemp(gen, style);
                rules = getRule();
                for (int fourNote = 0; fourNote< templatel.size(); fourNote++)
                {
                    templateL.push_back(templatel[fourNote]);
                }
                for (std::vector<int>::size_type fourNote = 0; fourNote < 4; ++fourNote)
                {
                    tem = 0;
                    if (rules[fourNote] == "random")
                    {
                        for (int z = 0; z<4; z++)
                            if (templatel[4*fourNote + z] == 1)
                            {
                            mainPitch.push_back(getNotes(1, section + 4*part));
                            }
                    }
                    else if(rules[fourNote] == "sequentia")
                    {
                        tem += templatel[4*fourNote];
                        tem += templatel[4*fourNote+1];
                        tem += templatel[4*fourNote+2];
                        tem += templatel[4*fourNote+3];
                        while (rules[(fourNote+1) % 4] == "sequentia" && fourNote < 3){
                            fourNote += 1;
                            tem += templatel[4*fourNote];
                            tem += templatel[4*fourNote+1];
                            tem += templatel[4*fourNote+2];
                            tem += templatel[4*fourNote+3];
                        }
                        teml = sequentia(chord(notel[4*part + section],chordTypeList[4*part + section]),tem);
                        for (int l=0; l < tem; l++){
                            mainPitch.push_back({teml[l]});
                        }
                    }
                    else if(rules[fourNote] == "pedalback"){
                        tem = 0;
                        tem += templatel[4*fourNote] + templatel[4*fourNote+1] + templatel[4*fourNote+2] + templatel[4*fourNote+3];
                        teml = pedalback(getNotes(tem,4*part + section), 4*part + section);
                        for (int l=0; l < tem; l++){
                            mainPitch.push_back({teml[l]});
                        }
                    }
                }
            }
            mainPitchToTemplate[templateList[part]-1] = mainPitch;
            mainTempToTemplate[templateList[part]-1] = templateL;
        }
    }
}

Track Accompany::mainTrack(int count, int instru){
    vector<vector<int>> pitch;
    vector<vector<int>> temPitch;
    vector<vector<int>> voidPitch;
    voidPitch.clear();

    if (instru == -1){
        Track voidTrack;
        return voidTrack;
    }

    vector<int> temp;
    vector<int> tempTemp;
    vector<int> voidTemp ={0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0,
                           0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0,
                           0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0,
                           0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0,};
    for (int i = 0; i<sectionNum; i++) {
        temPitch = (count == mainDistri[i]) ? mainPitchToTemplate[templateList[i]-1]:voidPitch;
        for (int j = 0; j < temPitch.size(); j++){
            pitch.push_back(temPitch[j]);
        }

        tempTemp = (count == mainDistri[i]) ? mainTempToTemplate[templateList[i]-1]:voidTemp;
        for (int j = 0; j < 64; j++){
            temp.push_back(tempTemp[j % tempTemp.size()]);
        }
    }
    return accompanist(temp,pitch,0,3);
}

//vector<int> type3(int mode)
//{
//    vector<int> pitchl;
//    pitchl = chord(chordl,randoms({"M7","M","M6","M9"}),3,mode)
//    for (int i=0;i<pitchl.size();++i)
//    {
//    notelist.push_back(pitchel[i]+2);
//    }
//    return notelist;
//}

