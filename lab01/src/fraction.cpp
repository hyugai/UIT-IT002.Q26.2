#include "../include/fraction.hpp"
#include <iostream>
#include <istream>
#include <numeric>
#include <ostream>
#include <stdexcept>
#include <string>

using namespace std;

/* *
 * @brief validate denominator/numerator
 *
 * ensure only numbers included
 *
 * @param inp input as string
 *
 * @return bool true: stoi(inp) succeed, false: otherwise
 * */
bool isNumber(const string &inp) {
    bool res{true};
    try {
        stoi(inp);
    } catch (invalid_argument &e) {
        cerr << "Invalid argument: " << e.what() << endl;
        res = false;
    } catch (out_of_range &e) {
        cerr << "Out of range: " << e.what() << endl;
        res = false;
    }

    return res;
}

/* *
 * @brief Change private properies `top, bot`
 *
 * @param n must be an integer
 *
 * @return void
 * */
void MyFraction::setTop(int n) { this->top = n; }
void MyFraction::setBot(int n) { this->bot = n; }

/* *
 * @brief simlify fraction
 *
 * divide `bot, top` by their GCD(Greatest Common Divisor)
 *
 * @param void
 *
 * @return void
 * */
void MyFraction::simplify() {
    if (this->top != 0) {
        int gcd_top_bot{gcd(this->top, this->bot)};

        this->top = this->top / gcd_top_bot;
        this->bot = this->bot / gcd_top_bot;
    }
}

/* *
 * @brief overload input/output operation (>>, <<)
 *
 * @param out/in left operand
 * @param f right operand
 *
 * @return ostream/istream
 * */
ostream &operator<<(ostream &out, const MyFraction &f) {
    if (f.top == 0) {
        out << 0;
    } else if (f.top * f.bot < 0) {
        cout << (f.top < 0 ? 1 : -1) * f.top << "/";
        if (f.bot != 1) {
            cout << (f.bot < 0 ? -1 : 1) * f.bot;
        }
    } else {
        cout << (f.top < 0 ? -1 : 1) * f.top << "/";
        if (f.bot != 1) {
            cout << (f.bot < 0 ? -1 : 1) * f.bot;
        }
    }

    return out;
}

istream &operator>>(istream &in, MyFraction &f) {
    string top, bot;
    cout << "Nhap tu so:\n";
    getline(in, top);
    cout << "Nhap mau so:\n";
    getline(in, bot);

    while (!(isNumber(top) && isNumber(bot))) {
        cout << "Nhap lai tu so:\n";
        getline(in, top);
        cout << "Nhap lai mau so:\n";
        getline(in, bot);
    }

    f.setTop(stoi(top));
    f.setBot(stoi(bot));
    f.simplify();

    return in;
}

/* *
 * @brief overload comparision operation (>)
 *
 * @param f1 left operand
 * @param f2 right operand
 *
 * @return bool true: f1>f2, false:f1<=f2
 * */
bool operator>(const MyFraction &f1, const MyFraction &f2) {
    bool res{true};
    if (f1.top * f2.bot < f2.top * f1.bot) {
        res = false;
    }

    return res;
}

/* *
 * @brief overload arimethic operations (+,-,*,/)
 *
 * @param f1 left operand
 * @param f2 right operand
 *
 * @return MyFraction a new fraction as a result of arimetic operations
 * */
MyFraction operator+(const MyFraction &f1, const MyFraction &f2) {
    MyFraction res;
    res.setTop(f1.top * f2.bot + f2.top * f1.bot);
    res.setBot(f1.bot * f2.bot);
    res.simplify();

    return res;
}

MyFraction operator-(const MyFraction &f1, const MyFraction &f2) {
    MyFraction res;
    res.setTop(f1.top * f2.bot - f2.top * f1.bot);
    res.setBot(f1.bot * f2.bot);
    res.simplify();

    return res;
}

MyFraction operator*(const MyFraction &f1, const MyFraction &f2) {
    MyFraction res;
    res.setTop(f1.top * f2.top);
    res.setBot(f1.bot * f2.bot);
    res.simplify();

    return res;
}

MyFraction operator/(const MyFraction &f1, const MyFraction &f2) {
    MyFraction res;
    res.setTop(f1.top * f2.bot);
    res.setBot(f1.bot * f2.top);
    res.simplify();

    return res;
}
