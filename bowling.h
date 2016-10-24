#ifndef BOWLING_H
#define BOWLING_H
#include "Frame.h"
#include<iostream>
using namespace std;

class Bowling 
{
private: Frame a[10];

public: void accumulateScore();
        void bowl();
        void printData();
};
#endif