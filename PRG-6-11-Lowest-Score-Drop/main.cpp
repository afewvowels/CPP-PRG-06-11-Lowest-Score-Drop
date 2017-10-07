//
//  main.cpp
//  PRG-6-11-Lowest-Score-Drop
//
//  Created by Keith Smith on 10/7/17.
//  Copyright © 2017 Keith Smith. All rights reserved.
//
//  Write a program that calculates the average of a group of test scores, where the lowest
//  score in the group is dropped. It should use the following functions:
//
//  * void getScore() should ask the user for a test score, store it in a reference parameter
//    variable, and validate it. The function should be called by main once for each
//    of the five scores to be entered.
//  * void calcAverage() should calculate and display the average of the four highest
//    scores. The function should be called just once by main and should be passed the
//    five scores.
//  * int findLowest() should find and return the lowest of the five scores passed to it.
//    It should be called by calcAverage, which uses the function to determine which of
//    the five scores to drop.
//
//  Input Validation: Do not accept test scores lower than 0 or higher than 100.

#include <iostream>
#include <iomanip>

using namespace std;

void getScore(int &refVar);
void calcAverage(int, int, int, int, int);
int findLowest(int, int, int, int, int);

int main()
{
    int intTestScore1,
        intTestScore2,
        intTestScore3,
        intTestScore4,
        intTestScore5;
    
    getScore(intTestScore1);
    getScore(intTestScore2);
    getScore(intTestScore3);
    getScore(intTestScore4);
    getScore(intTestScore5);
    
    calcAverage(intTestScore1, intTestScore2, intTestScore3,
                intTestScore4, intTestScore5);
    
    return 0;
}

void getScore(int &intTestScoreRef)
{
    cout << "Please enter the test score:\n";
    cin >> intTestScoreRef;
    
    while(!cin || intTestScoreRef < 0 || intTestScoreRef > 100)
    {
        cout << "Please enter a valid test score between 0 and 100";
        cin.clear();
        cin.ignore();
        cin >> intTestScoreRef;
    }
}

void calcAverage(int intTestScore1, int intTestScore2,
                 int intTestScore3, int intTestScore4,
                 int intTestScore5)
{
    float fltTestAverage;
    
    fltTestAverage = 0;
    
    // Nested function call is necessary as per the prompts instructions
    findLowest(intTestScore1, intTestScore2, intTestScore3,
               intTestScore4, intTestScore5);
    
    if(findLowest(intTestScore1, intTestScore2, intTestScore3,
                  intTestScore4, intTestScore5) == intTestScore1)
    {
        cout << "Test score 1 was dropped.\n";
        fltTestAverage = (intTestScore2 + intTestScore3 +
                          intTestScore4 + intTestScore5) / 4.0f;
    }
    else if(findLowest(intTestScore1, intTestScore2, intTestScore3,
                       intTestScore4, intTestScore5) == intTestScore2)
    {
        cout << "Test score 2 was dropped.\n";
        fltTestAverage = (intTestScore1 + intTestScore3 +
                          intTestScore4 + intTestScore5) / 4.0f;
    }
    else if(findLowest(intTestScore1, intTestScore2, intTestScore3,
                       intTestScore4, intTestScore5) == intTestScore3)
    {
        cout << "Test score 3 was dropped.\n";
        fltTestAverage = (intTestScore1 + intTestScore2 +
                          intTestScore4 + intTestScore5) / 4.0f;
    }
    else if(findLowest(intTestScore1, intTestScore2, intTestScore3,
                       intTestScore4, intTestScore5) == intTestScore4)
    {
        cout << "Test score 4 was dropped.\n";
        fltTestAverage = (intTestScore1 + intTestScore2 +
                          intTestScore3 + intTestScore5) / 4.0f;
    }
    else if(findLowest(intTestScore1, intTestScore2, intTestScore3,
                       intTestScore4, intTestScore5) == intTestScore5)
    {
        cout << "Test score 5 was dropped.\n";
        fltTestAverage = (intTestScore1 + intTestScore2 +
                          intTestScore3 + intTestScore4) / 4.0f;
    }
    else
    {
        cout << "ERROR\n";
    }
    
    cout << setprecision(1) << fixed << showpoint;
    cout << "The average test score is " << fltTestAverage << endl;
}

int findLowest(int intTestScore1, int intTestScore2, int intTestScore3,
               int intTestScore4, int intTestScore5)
{
    if(intTestScore1 < intTestScore2 || intTestScore1 < intTestScore3 ||
       intTestScore1 < intTestScore4 || intTestScore1 < intTestScore5)
    {
        return intTestScore1;
    }
    else if(intTestScore2 < intTestScore1 || intTestScore2 < intTestScore3 ||
            intTestScore2 < intTestScore4 || intTestScore2 < intTestScore5)
    {
        return intTestScore2;
    }
    else if(intTestScore3 < intTestScore1 || intTestScore3 < intTestScore2 ||
            intTestScore3 < intTestScore4 || intTestScore3 < intTestScore5)
    {
        return intTestScore3;
    }
    else if(intTestScore4 < intTestScore1 || intTestScore4 < intTestScore2 ||
            intTestScore4 < intTestScore3 || intTestScore4 < intTestScore5)
    {
        return intTestScore4;
    }
    else if(intTestScore5 < intTestScore1 || intTestScore5 < intTestScore2 ||
            intTestScore5 < intTestScore3 || intTestScore5 < intTestScore4)
    {
        return intTestScore5;
    }
    else // Tie score cases
    {
        if(intTestScore1 == intTestScore2 || intTestScore1 == intTestScore3 ||
           intTestScore1 == intTestScore4 || intTestScore1 == intTestScore5)
        {
            return intTestScore1;
        }
        else if(intTestScore2 == intTestScore1 || intTestScore2 == intTestScore3 ||
                intTestScore2 == intTestScore4 || intTestScore2 == intTestScore5)
        {
            return intTestScore2;
        }
        else if(intTestScore3 == intTestScore1 || intTestScore3 == intTestScore2 ||
                intTestScore3 == intTestScore4 || intTestScore3 == intTestScore5)
        {
            return intTestScore3;
        }
        else if(intTestScore4 == intTestScore1 || intTestScore4 == intTestScore2 ||
                intTestScore4 == intTestScore3 || intTestScore4 == intTestScore5)
        {
            return intTestScore4;
        }
        else if(intTestScore5 == intTestScore1 || intTestScore5 == intTestScore2 ||
                intTestScore5 == intTestScore3 || intTestScore5 == intTestScore4)
        {
            return intTestScore5;
        }
        else // Error message if no test score less than the rest or tied with the rest
        {
            cout << "ERROR\n";
        }
    }
    return 0;
}

