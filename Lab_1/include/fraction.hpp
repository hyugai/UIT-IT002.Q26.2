#pragma once // avoid multiple callings

#include <istream>
#include <ostream>
#include <string>

using namespace std;

struct MyFraction {

    /* setter */
    void setTop(int);
    void setBot(int);

    /* simplify fuction*/
    void simplify();

    /* `<<, >>` overloaded
     * `const` avoids any modification
     * `friend` grants permission to outside functions to access private members
     * */
    friend ostream &operator<<(ostream &, const MyFraction &);
    friend istream &operator>>(istream &, MyFraction &);
    friend bool operator>(const MyFraction &, const MyFraction &);
    friend MyFraction operator+(const MyFraction &, const MyFraction &);
    friend MyFraction operator-(const MyFraction &, const MyFraction &);
    friend MyFraction operator*(const MyFraction &, const MyFraction &);
    friend MyFraction operator/(const MyFraction &, const MyFraction &);

  private:
    /*
     * top: numerator
     * bot: denominator
     * */
    int top, bot;
};

/*
 * no letter or special character is included
 * */
bool isNumber(const string &);
