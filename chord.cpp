 #include "chord.h"
using namespace std;

vector<int> chord(int key, string type, int pos);
string mode;
std::map<string,vector<string>> chordl = {{"M",{"1 3 5","3 5 8","5 8 10"}},
                                          {"m",{"1 3b 5", "3b 5 8", "5 8 10b"}},
                                          {"Aug",{"1 3 5#","3 5# 8","5# 8 10"}},
                                          {"Dim",{"1 3b 5b","3b 5b 8","5b 8 10b"}},
                                          {"sus2",{"1 2 5","2 5 8","5 8 9"}},
                                          {"sus4",{"1 4 5","4 5 8","5 8 11"}},
                                          {"7",{"1 3 5 7b","3 5 7b 8", "5 7b 8 10"}},
                                          {"6",{"1 3 5 6","3 5 6 8","5 6 8 10"}},
                                          {"M7",{"1 3 5 7","3 5 7 8", "5 7 8 10"}},
                                          {"m7",{"1 3b 5 7b","3b 5 7b 8", "5 7b 8 10"}},
                                          {"9",{"1 3 5 9b","3 5 9b 8", "5 9b 8 10"}},
                                          {"M9",{"1 3 5 7 9","3 5 7 8 9", "5 7 8 9 10"}},
                                          {"m9",{"1 3b 5 7b","3b 5 7b 8", "5 7b 8 10"}},
                                          {"b5",{"1 3 5b","3 5b 8", "5b 8 10"}}};
map<string, int> modemap = {{"Cb", -1},{"C",0},{"C#", 1},
                           {"Db", 1},{"D", 2},{"D#", 3},
                           {"Eb", 3},{"E", 4},
                           {"F", 5},{"F#", 6},
                           {"Gb", 6},{"G", -5},{"G#", -4},
                           {"Ab", -4},{"A", -3},{"A#", -2},
                           {"Bb", -2},{"B",-1}};


vector<int> chord(int key, string type, int pos, string mod){
    mode = mod;
    string ma = extract(mode, 0);
    string mi = extract(mode, 1);
    vector<string> ty;
    vector<int> notel;
    int keyposi;
    if (pos == 3){
        pos = rand()%3;
    }
    ty = split(chordl[type][pos], ' ');

    if (mi == "Major"|mi == " "){
        for (int i = 0 ;i < ty.size(); i++){
            mi = ty[i];
            if (mi.back()== '#'){
                mi.erase(mi.end()-1);
                keyposi = stoi(mi)+key-1;
                notel.push_back(keyposi + keyposi/7 * 5 + (keyposi)%7 - ((keyposi)%7)/3 + modemap[ma]);
            }
            else if (mi.back() == 'b'){
                mi.erase(mi.end()-1);
                keyposi = stoi(mi)+key-1;
                notel.push_back(keyposi + keyposi/7 * 5 + (keyposi)%7 - ((keyposi)%7)/3 - 2 + modemap[ma]);
            }
            else{
                keyposi = stoi(mi)+key-1;
                notel.push_back(keyposi + keyposi/7 * 5 + (keyposi)%7 - ((keyposi)%7)/3 - 1 + modemap[ma]);
            }
        }
    }

    else if (mi == "Minor") {
        for (int i=0 ;i < ty.size(); i++){
            mi = ty[i];
            if (mi.back() == '#'){
                mi.erase(mi.end()-1);
                keyposi = stoi(mi)+key-1;
                notel.push_back(keyposi + keyposi/7 * 5 + (keyposi)%7 - ((keyposi)%7)/3 + modemap[ma]
                                +((keyposi-2)%7)/3-((keyposi-2)%7)/4);
            }
            else if (mi.back() == 'b'){
                mi.erase(mi.end()-1);
                keyposi = stoi(mi)+key-1;
                notel.push_back(keyposi + keyposi/7 * 5 + (keyposi)%7 - ((keyposi)%7)/3 - 2 + modemap[ma]
                                +((keyposi-2)%7)/3-((keyposi-2)%7)/4);
            }
            else{
                keyposi = stoi(mi)+key-1;
                notel.push_back(keyposi + keyposi/7 * 5 + (keyposi)%7 - ((keyposi)%7)/3 - 1 + modemap[ma]
                                +((keyposi-2)%7)/3-((keyposi-2)%7)/4);
            }
        }
    }
    return notel;
}


