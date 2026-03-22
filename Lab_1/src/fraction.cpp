#include "../include/fraction.hpp"
#include <iostream>
#include <istream>
#include <numeric>
#include <ostream>
#include <stdexcept>
#include <string>

using namespace std;

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

void MyFraction::setTop(int n) { this->top = n; }
void MyFraction::setBot(int n) { this->bot = n; }

void MyFraction::simplify() {
    if (this->top != 0) {
        int gcd_top_bot{gcd(this->top, this->bot)};

        this->top = this->top / gcd_top_bot;
        this->bot = this->bot / gcd_top_bot;
    }
}

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
    getline(in, top);
    getline(in, bot);

    while (!(isNumber(top) && isNumber(bot))) {
        cout << "Enter again:" << endl;
        getline(in, top);
        getline(in, bot);
    }

    f.setTop(stoi(top));
    f.setBot(stoi(bot));
    f.simplify();

    return in;
}

bool operator>(const MyFraction &f1, const MyFraction &f2) {
    bool res{true};
    if (f1.top * f2.bot < f2.top * f1.bot) {
        res = false;
    }

    return res;
}

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
