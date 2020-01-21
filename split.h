#include <string>
#include <vector>
#include <ctime>
using namespace std;

#ifndef SPLIT_H
#define SPLIT_H


std::vector<std::string> split(const std::string &s, char delim);
std::string extract(std::string &values, int index, char delim = ' ');
vector<string> randomlist(vector<string> chordlist, int num = 0);
vector<int> randomlisti(vector<int> chordlist, int num = 0);
string selectone(vector<string> chordlist, int largernum, int numa, int numb = 0, int numc = 0);

int randomi(vector<int> notel, int flag = 0);
string randoms(vector<string> notel, int flag = 0);
#endif // SPLIT_H
