#pragma once // avoid multiple callings

#include <istream>
#include <ostream>
#include <string>

using namespace std;

struct MyFraction {

    /* *
     * @brief Change private properties
     *
     * @param n must be an integer
     *
     * @return void
     * */
    void setTop(int n);
    void setBot(int n);

    /* *
     * @brief divide `bot, top` by their GCD to acheve simplest form
     *
     * @param void
     *
     * @return void
     * */
    void simplify();

    /* *
     * @brief overload input/output operation (>>, <<)
     *
     * @param out/in
     * @param f
     *
     * @return ostream&/istream&
     * */
    friend ostream &operator<<(ostream &out, const MyFraction &f);
    friend istream &operator>>(istream &, MyFraction &);

    /* *
     * @brief overload arimethic operations (+,-,*,/)
     *
     * @param f1
     * @param f2
     *
     * @return MyFraction a new fraction
     * */
    friend MyFraction operator+(const MyFraction &f1, const MyFraction &f2);
    friend MyFraction operator-(const MyFraction &f1, const MyFraction &f2);
    friend MyFraction operator*(const MyFraction &f1, const MyFraction &f2);
    friend MyFraction operator/(const MyFraction &f1, const MyFraction &f2);

    /* *
     * @brief overload comparision operation (>)
     *
     * @param f1
     * @param f2
     *
     * @return bool true: f1>f2, false:f1<=f2
     * */
    friend bool operator>(const MyFraction &, const MyFraction &);

  private:
    int top, bot;
};

/* *
 * @brief check if input include ONLY number
 *
 * @param inp input as string
 *
 * @return bool true: stoi(inp) succeed, false: otherwise
 * */
bool isNumber(const string &inp);
