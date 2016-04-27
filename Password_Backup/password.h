//===============================================================
// Name     : password_one.hpp
// Author   : Connor McCann
// Email    : cjmccann@bu.edu
// Date     : 12 Apr 2016
//===============================================================

#ifndef password_h
#define password_h

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
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
    void calcStrength(void);
    void storePassword(string,string);
    void checkUser(string,string);
public:                                         // Originally private
    vector<string> table;
    QString password;
    map<string,string> users;
    int tableStartValue = 121;                   // For generating the password value
    int dieOne;
    int dieTwo;
    bool coin;
    int passwordLength;
    double strength;
    bool letters = false;                              // From the user clicked box
    bool numbers = false;                              // From user clicked box
    bool characters;                            // from the user click box
};

#endif
