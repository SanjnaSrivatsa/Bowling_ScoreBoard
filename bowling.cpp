#include "Bowling.h"
#include <iostream>
using namespace std;

/***
This function Makes the actual Calculation and displays the score after each game is completed
*/
void Bowling::accumulateScore()
{
    int totalSum = 0;
    
    /**
    Loop through first 9 frames and perform sum, since logic for first 9 is same.
    **/
    for (int x = 0; x < 9; x++)
    {
        if (a[x].getFirstThrow() + a[x].getSecondThrow() < 10) //not a strike or spare normal sum for score
        {
            totalSum += a[x].getFirstThrow() + a[x].getSecondThrow();
            a[x].setScore(totalSum);
        }
        else if (a[x].getFirstThrow() == 10) //If strike
        {
            if (x < 9)
            {
                totalSum += 10 + a[x + 1].getFirstThrow() + a[x + 1].getSecondThrow();// Add next two rolls
                if (a[x + 1].getStrike() == true) //If next frame is strike add next+1 frame throws
                {
                    if(a[x + 2].getStrike() == true){ // if next+1 frame is also strike add 10
                        totalSum += 10;
                    }else{
                        totalSum+=a[x + 2].getFirstThrow(); // if next+1 frame is not strike add the first throw
                    }                    
                }                
                a[x].setScore(totalSum);
            }
        }
        else if (a[x].getFirstThrow() + a[x].getSecondThrow() == 10) //IF a spare
        {
            if(x < 9)
            {
                totalSum += 10 + a[x + 1].getFirstThrow();
                a[x].setScore(totalSum);
            }
        }
    }

    //Add the 10th frame to the total score
    totalSum += a[9].getScore();
    a[9].setScore(totalSum);

}

/***
This function gets the results for each throw and stimulates bowl for each player.
*/
void Bowling::bowl()
{
    //generate all throws and store them in the frames
    for (int x = 0; x < 9; x++)
    {
        a[x].setFirstThrow(x);
        if (a[x].getFirstThrow() == 10)
        {
            a[x].setStrike(true);
        }
        if (a[x].getStrike() == false)
        {
            a[x].setSecondThrow(x);
            if (a[x].getFirstThrow() + a[x].getSecondThrow() == 10)
            {
                a[x].setSpare(true);
            }
        }
        a[x].setScore(a[x].getFirstThrow() + a[x].getSecondThrow());
    }

    //Throwing 10th frame
    a[9].setFirstThrow(9);
    if (a[9].getFirstThrow() == 10)
    {
            a[9].setStrike(true);
    }
    a[9].setSecondThrow(9);
    
    // If not a strike then look for spare
    if(a[9].getStrike()==false){
        if (a[9].getFirstThrow() + a[9].getSecondThrow() == 10)
        {
            a[9].setSpare(true);
        }
    }
    
    //IF Spare or Strike then give user the third chance
    if(a[9].getStrike() == true||a[9].getSpare()==true){
        a[9].setThirdThrow(9);
    }
    a[9].setScore(a[9].getFirstThrow() + a[9].getSecondThrow()+a[9].getThirdThrow());//Add all throws. Third throw will be zero in worst case so no problem.
}

/***
This function prints each throw and each frame's score. Total score is last frame's score
*/
void Bowling::printData()
{
    //Print first 9 Frames
    for (int x = 0; x < 9; x++)
    {
        cout << "*****************************" << endl;
        cout << "Frame " << x + 1 << endl;
        cout << "First throw: ";
        if (a[x].getStrike() == true)
        {
            cout << "Strike!" << endl;
        }
        else
        {
            cout << a[x].getFirstThrow() << endl;
        }


        cout << "Second throw: ";
        if (a[x].getStrike() == false)
        {
            if (a[x].getSpare() == true)
            {
                cout << "Spare!" << endl;
            }
            else if(a[x].getSpare() == false)
            {
                cout << a[x].getSecondThrow() << endl;
            }
            else
            {
                cout << endl;
            }
        }else{
            cout << endl;
        }
        cout << "Score: " << a[x].getScore();
        cout << endl;
    }

    // Logic for 10th frame Printing
    cout << "*****************" << endl;
    cout << "Frame 10" << endl;
    cout << "First throw: ";
    if (a[9].getStrike() == true)
    {
        cout << "Strike!" << endl;
    }
    else
    {
        cout << a[9].getFirstThrow() << endl;
    }
    cout << "Second throw: ";

    if (a[9].getSpare() == true)
    {
        cout << "Spare!" << endl;
    }
    else
    {
        cout << a[9].getSecondThrow() << endl;
    }
    
    if ( a[9].getStrike() == true || a[9].getSpare()==true)
    {
        cout << "Third throw: ";
        if (a[10].getThirdThrow() == 10)
        {
            cout << "Strike!" << endl;
        }else{
            cout << a[9].getThirdThrow() << endl;
        }
    }
    
    //Logic for score of Last frame
    cout << "Score: " << a[9].getScore()<< endl;
    // Total Score
    cout << "*****************" << endl;
    cout << "Total Score for the game is " << a[9].getScore();

}
