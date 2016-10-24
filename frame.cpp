#include "Frame.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

Frame::Frame()
{
    spare   = false;
    strike  = false;
    throw1  = 0;
    throw2  = 0;
    throw3  = 0;
    score   = 0;
}

//Generate Throw
int Frame::genThrow(int size,int throwIndex)
{
    int randomNumber = getThrowValue(size,throwIndex);
    return randomNumber;
}

//Get the throw value
int Frame::getThrowValue(int frameIndex,int throwIndex)
{
    int inputNumber=0;
    cout << "How many pins did you get for Frame:"<<(frameIndex+1)<<" and throw:"<<throwIndex<<"."<< endl;
    cin >> inputNumber;

    if(inputNumber<0||inputNumber>10){
        cout << "Total number of pins should be between 0 and 10. Enter a correct value."<< endl;
        inputNumber = getThrowValue(frameIndex,throwIndex);
    }
    if(throwIndex==2&&frameIndex!=9){
        if((10-throw1)<inputNumber){
            cout << "Only "<<(10-throw1)<<" pins remaining on the floor. Please enter a proper value"<< endl;
            inputNumber = getThrowValue(frameIndex,throwIndex);
        }
    }
    return inputNumber;
}

//Get first throw
int Frame::getFirstThrow()
{
    return throw1;
}

//Get second throw
int Frame::getSecondThrow()
{
    return throw2;
}

//Get second throw
int Frame::getThirdThrow()
{
    return throw3;
}

//Get the score of both throws
int Frame::getScore()
{
    return score;
}

//Get the score
void Frame::setScore(int value)
{
    score = value;
}

//Get the first throw
void Frame::setFirstThrow(int value1)
{
    throw1 = genThrow(value1,1); //normal generator
}

//set the second throw
void Frame::setSecondThrow(int value2)
{

    throw2 = genThrow(value2,2); //normal generator
}

//set the thrid throw only for last from
void Frame::setThirdThrow(int value3)
{

    throw3 = genThrow(value3,3); //normal generator
}

//set the strike
void Frame::setStrike(bool value)
{
    strike = value;
}

//set the spare
void Frame::setSpare(bool value)
{
    spare = value;
}

//get the strike
bool Frame::getStrike()
{
    return strike;
}

//get the spare
bool Frame::getSpare()
{
    return spare;
}
