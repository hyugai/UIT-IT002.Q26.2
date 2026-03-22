#pragma once // avoid multiple callings

#include <istream>
#include <ostream>
#include <string>

using namespace std;

struct MyStudent {
    /*
     *`<<, >>`  overloaded
     * */
    friend ostream &operator<<(ostream &, const MyStudent &);
    friend istream &operator>>(istream &, MyStudent &);

  private:
    string name;
    double math, literature;
};

/*
 *no number or special character included in student's name
 * */
bool isNameValid(string);
/*
 *score MUST range from 0-10
 * */
bool isScoreValid(double);
