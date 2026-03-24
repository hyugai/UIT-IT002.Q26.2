#pragma once // avoid multiple callings

#include <istream>
#include <ostream>
#include <string>

using namespace std;

struct MyFraction {

    void setTop(int);
    void setBot(int);

    void simplify();

    friend ostream &operator<<(ostream &, const MyFraction &);
    friend istream &operator>>(istream &, MyFraction &);

    friend MyFraction operator+(const MyFraction &, const MyFraction &);
    friend MyFraction operator-(const MyFraction &, const MyFraction &);
    friend MyFraction operator*(const MyFraction &, const MyFraction &);
    friend MyFraction operator/(const MyFraction &, const MyFraction &);

    friend bool operator>(const MyFraction &, const MyFraction &);

  private:
    int top; ///< numerator
    int bot; ///< denominator
};

bool isNumber(const string &inp);
