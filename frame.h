#ifndef FRAME_H
#define FRAME_H
#include <iostream>
using namespace std;

class Frame
{    
private: int throw1;
         int throw2;
         int throw3;
         int score;
         bool spare;
         bool strike;

public: Frame();    
        int genThrow(int size,int throwIndex);
        int getThrowValue(int frameIndex,int throwIndex);    
        int getFirstThrow();
        int getSecondThrow();
        int getThirdThrow();    
        int getScore();    
        void setScore(int);    
        void setFirstThrow(int value1);
        void setSecondThrow(int value2);
        void setThirdThrow(int value3);
        void setStrike(bool value);
        void setSpare(bool value);    
        bool getStrike();
        bool getSpare();        
};
#endif
