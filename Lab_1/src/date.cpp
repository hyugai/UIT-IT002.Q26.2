#include "../include/date.hpp"
#include <iostream>
#include <istream>
#include <ostream>

using namespace std;

void MyDate::setDay(int n) { this->day = n; }
void MyDate::setMonth(int n) { this->month = n; }
void MyDate::setYear(int n) { this->year = n; }

ostream &operator<<(ostream &out, const MyDate &date) {
    if (date.day < 10) {
        out << 0;
    }
    out << date.day << "/";
    if (date.month < 10) {
        out << 0;
    }
    out << date.month << "/" << date.year << endl;

    return out;
}

istream &operator>>(istream &in, MyDate &date) {
    int d, m, y;
    in >> d >> m >> y;

    while (!(isDateValid(d, m, y))) {
        cout << "Enter again: ";
        in >> d >> m >> y;
    }

    date.day = d;
    date.month = m;
    date.year = y;

    return in;
}

MyDate operator+(const MyDate &date, int n) {
    MyDate res;

    int new_days = date.day + 1;
    if (new_days > getMaxDaysOfMonth(date.month, date.year)) {
        res.setDay(1);
        int new_month = date.month + 1;

        if (new_month > 12) {
            res.setMonth(1);
            res.setYear(date.year + 1);
        } else {
            res.setMonth(new_month);
            res.setYear(date.year);
        }
    } else {
        res = date;
        res.setDay(new_days);
    }

    return res;
}

bool isLeapYear(int y) {
    bool res{false};
    if (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0)) {
        res = true;
    }

    return res;
}
int getMaxDaysOfMonth(int m, int y) {
    int res;
    switch (m) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        res = 31;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        res = 30;
        break;
    case 2:
        res = isLeapYear(y) ? 29 : 28;
        break;
    }

    return res;
}
bool isDateValid(int d, int m, int y) {
    bool res{true};
    if (y <= 0) {
        cout << "Invalid year!" << endl;
        res = false;
    } else if (m < 1 || m > 12) {
        cout << "Invalid month!" << endl;
        res = false;
    } else if (d < 1 || d > getMaxDaysOfMonth(m, y)) {
        cout << "Invalid day!" << endl;
        res = false;
    }

    return res;
}
