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
     * @brief simlify fraction
     *
     * divide `bot, top` by their GCD(Greatest Common Divisor)
     *
     * @param void
     *
     * @return void
     * */
    void simplify();

    /* *
     * @brief overload input/output operation (>>, <<)
     *
     * @param out/in left operand
     * @param f right operand
     *
     * @return ostream/istream
     * */
    friend ostream &operator<<(ostream &out, const MyFraction &f);
    friend istream &operator>>(istream &, MyFraction &);

    /* *
     * @brief overload arimethic operations (+,-,*,/)
     *
     * @param f1 left operand
     * @param f2 right operand
     *
     * @return MyFraction a new fraction as a result of arimetic operations
     * */
    friend MyFraction operator+(const MyFraction &f1, const MyFraction &f2);
    friend MyFraction operator-(const MyFraction &f1, const MyFraction &f2);
    friend MyFraction operator*(const MyFraction &f1, const MyFraction &f2);
    friend MyFraction operator/(const MyFraction &f1, const MyFraction &f2);

    /* *
     * @brief overload comparision operation (>)
     *
     * @param f1 left operand
     * @param f2 right operand
     *
     * @return bool true: f1>f2, false:f1<=f2
     * */
    friend bool operator>(const MyFraction &, const MyFraction &);

  private:
    int top; ///< numerator
    int bot; ///< denominator
};

/* *
 * @brief validate denominator/numerator
 *
 * ensure only numbers included
 *
 * @param inp input as string
 *
 * @return bool true: stoi(inp) succeed, false: otherwise
 * */
bool isNumber(const string &inp);
