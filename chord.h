#include "split.h"
#include <vector>
#include <string>
#include <map>
#include <iostream>
using namespace std;
#ifndef CHORD_H
#define CHORD_H


/*
 * Example: chord(25, "sus2", 0),  25 -- re in C major, mi in D major, pos are 0 - 3 when not given.
 * output: {44, 46, 51}
 */
vector<int> chord(int key, string type, int pos = 3, string mod = "C Major");


#endif // CHORD_H
