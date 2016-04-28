#ifndef password_h
#define password_h
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <QString>
using namespace std;

class password_one
{
public:
    password_one();
    void rollOne(void);
    void rollTwo(void);
    void coinToss(void);
    void buildPassword(void);
    void buildNumPassword(void);
    void calcStrength(void);

public:                                         // Originally private
    vector<string> table;
    QString password;
    int tableStartValue = 121;                  // For generating the password value
    int dieOne;
    int dieTwo;
    bool coin;
    int passwordLength;
    double strength;
    bool letters = false;                       // From the user clicked box
    bool numbers = false;                       // From user clicked box
    bool characters;                            // from the user click box
};

#endif
