#include "password.h"
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

password_one::password_one()                                                        // Main Constructor
{

}

//===============================================================
//                        Class Methods
//===============================================================

void password_one::rollOne(void)                                                    // Simulates roll of the first die
{
    if(letters && !numbers)
    {
        dieOne = rand() % 5;
    }
    else if(letters && numbers && characters)
    {
        dieOne = rand() % 9;
    }
    else
    {
        dieOne = rand() % 6;
    }
}

void password_one::rollTwo(void)                                                    // Simulates the second roll
{
    if(letters && !numbers)
    {
        dieTwo = rand() % 5;
        if(dieOne > 3 && dieTwo > 1)
        {
            dieTwo = rand() % 2;
        }
    }
    else
    {
        dieTwo = rand() % 6;
    }
}

void password_one::coinToss(void)                                                   // Simulates a 1/2 coin toss
{
    coin = rand() % 2 ;
}

void password_one::buildNumPassword(void)
{
    for(int i = 0; i < passwordLength; i++)
    {
        int ranNum = rand() % 10;
//        cout << ranNum << endl;
        char toAdd = '0' + ranNum;
//        cout << toAdd << endl;
        password += toAdd;
    }
}

void password_one::buildPassword(void)                                               // Function to build the password form the table using the above 3 parameters
{
    if(letters && numbers && characters)
    {
            string aLine;                                                            // Buffer to build each loop
            int value = 96;                                                          // Use 32 for more characters
            bool flag = false;
            string myChar;                                                          // Character element to add to the buffer
            for(int i = 0; i < 9;i++)
            {
                for(int j = 0; j < 6; j++)                                          // Builds vector instead of direct input
                {
                    if(flag)
                    {
                        value = 32;
                        flag = false;
                    }
                    value++;
                    if(value == 'z')
                    {
                        flag = true;
                    }
                    myChar = (char)value;
                    if(value < 10)
                    {
                        myChar = to_string(value);
                    }
                    aLine += myChar;
                }
                table.push_back(aLine);                                     // Builds vector of strings = 2D array
                aLine = "";
            }
                                                                              // Build PW in constructor
    }
    else if(letters && !numbers && !characters)
    {
        string aLine;                                                   // Buffer to build each loop
        int value = 96;                                                 // Use 32 for more characters
        bool flag = false;
        string myChar;                                                  // Character element to add to the buffer
        for(int i = 0; i < 5;i++)
        {
            for(int j = 0; j < 6; j++)                                  // Builds vector instead of direct input
            {
                if(flag)
                {
                    break;
                }
                value++;
                if(value == 'z')
                {
                    flag = true;
                }
                myChar = (char)value;
                aLine += myChar;
            }
            table.push_back(aLine);                                     // Builds vector of strings = 2D array
            aLine = "";
        }
    }
    else if(letters && numbers && !characters)
    {
    string aLine;                                                   // Buffer to build each loop
    int value = 96;                                                 // Use 32 for more characters
    bool flag = false;
    string myChar;                                                  // Character element to add to the buffer
    for(int i = 0; i < 6;i++)
        {
        for(int j = 0; j < 6; j++)                                  // Builds vector instead of direct input
        {
            if(flag)
            {
                value = -1;
                flag = false;
            }
            value++;
            if(value == 'z')
            {
                flag = true;
            }
            myChar = (char)value;
            if(value < 10)
            {
                myChar = to_string(value);
            }
            aLine += myChar;
        }
        table.push_back(aLine);                                     // Builds vector of strings = 2D array
        aLine = "";
        }
   }
    char element;
    for(int i = 0; i < passwordLength; i++)
    {
        rollOne();
        rollTwo();                                                  // Use the above functions to gnerate the PW
        coinToss();
        element = table[dieOne][dieTwo];
//        cout << element << endl;
//        cout << dieOne << "     " << dieTwo << endl;
        if(coin)
        {
            element = toupper(element);
        }
        else
        {
            element = tolower(element);
        }
        password += element;                                        // Build the PW elements by element
    }
    for(int i = 0; i < table.size(); i++)                           // Prints the table we just built
    {
//        cout << table[i] << endl;
    }
    table.clear();
}


void password_one::calcStrength(void)                               // Uses natural log base 2 to calc the strength
{
    int N;
    if(numbers && letters && characters)
    {
        N = 54;
    }
    else if(numbers && letters)
    {
        N = 35;
    }
    else if(numbers)
    {
        N = 9;
    }
    else if(letters)
    {
        N = 26;
    }
    else
    {
        N = 0;
    }
    strength = passwordLength * log2(N);
//    cout<< N <<"|" << strength<< endl;
}









