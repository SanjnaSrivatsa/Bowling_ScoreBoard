#include "Bowling.h"
#include<iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    
    //create two players that can bowl
    Bowling player1;
    Bowling player2;

    //have the players bowl their throws before accumulating score
    player1.bowl();
    player2.bowl();
    //accumulate the score after all of the throws have been done
    player1.accumulateScore();
    player2.accumulateScore();
    //print player 1 data
    cout << "Here are the throws and score for the  player: " << endl;
    player1.printData();
    cout << "Here are the throws and score for the Second player: " << endl;
    player2.printData();
    //spacing
    cout << endl << endl;
    return 0;
}
