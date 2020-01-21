#include "split.h"
#include <string>
#include <vector>
#include <sstream>
using namespace std;

static void _split(const std::string &s, char delim,
                   std::vector<std::string> &elems) {
    std::stringstream ss(s);
    std::string item;

    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
}

std::vector<std::string> split(const std::string &s, char delim) {
    std::vector<std::string> elems;
    _split(s, delim, elems);
    return elems;
}

std::string extract(std::string &values, int index, char delim) {
    if (values.length() == 0)
        return std::string("");

    std::vector<std::string> x = split(values, delim);
    try {
        return x.at(index);
    } catch(const std::out_of_range& e) {
        return std::string("");  //
    }
}

string selectone(vector<string> chordlist, int largernum, int numa, int numb, int numc)
{
    if (numc != 0 and numb != 0)
    {
        if (rand()%largernum < numa)
        {
            return chordlist[0];
        }
        else if (rand()%(largernum-numa) < numb)
        {
            return chordlist[1];
        }
        else if (rand()%(largernum-numa-numb) < numc)
        {
            return chordlist[2];
        }
        else
        {
            return chordlist[3];
        }
    }
    else if (numb != 0 and numc == 0)
    {
        if (rand()%largernum < numa)
        {
            return chordlist[0];
        }
        else if (rand()%(largernum-numa) < numb)
        {
            return chordlist[1];
        }
        else
        {
            return chordlist[2];
        }
    }
    else
    {
        if (rand()%largernum < numa)
        {
            return chordlist[0];
        }
        else
        {
            return chordlist[1];
        }
    }
}


int randomi(vector<int> notel, int flag)
{
    int out;
    out = rand()%(notel.size());
    return notel[out];
}

string randoms(vector<string> chordtype, int flag)
{
    int out;
    out = rand()%(chordtype.size());
    return chordtype[out];
}

vector<string> randomlist(vector<string> chordlist, int num)
{
    vector<string> templist;
    int tem;
    if (num == 0)
    {
        num = chordlist.size();
    }

    if (num > chordlist.size()){
        for (int i = 0; i < num - chordlist.size(); ++i){
            templist.push_back(randoms(chordlist));
        }
    }

    for (int i =0; i < min(num,int(chordlist.size()+i)); ++i){
        tem = rand()%(chordlist.size());
        templist.push_back(chordlist[tem]);
        chordlist.erase(chordlist.begin() + tem);
    }
    return templist;
}

vector<int> randomlisti(vector<int> chordlist, int num)
{
    vector<int> templist;
    int tem;
    if (num == 0)
    {
        num = chordlist.size();
    }

    if (num > chordlist.size()){
        for (int i = 0; i < num - chordlist.size(); ++i){
            templist.push_back(randomi(chordlist));
        }
    }

    for (int i =0; i < min(num,int(chordlist.size()+i)); ++i){
        tem = rand()%(chordlist.size());
        templist.push_back(chordlist[tem]);
        chordlist.erase(chordlist.begin() + tem);
    }
    return templist;
}
