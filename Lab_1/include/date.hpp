#pragma once

#include <istream>
#include <ostream>

using namespace std;

struct MyDate {
    /*
     * setter
     * */
    void setDay(int);
    void setMonth(int);
    void setYear(int);

    /*
     * `<<, >>` overloaded
     * */
    friend ostream &operator<<(ostream &, const MyDate &);
    friend istream &operator>>(istream &, MyDate &);
    friend MyDate operator+(const MyDate &, int);

  private:
    int day, month, year;
};

/*
 * if year is leap, Ferb has 29 instead of 28
 * */
bool isLeapYear(int);
/*
 * return number of days in month given year
 * */
int getMaxDaysOfMonth(int, int);
/*
 * check if date is valid
 * */
bool isDateValid(int, int, int);
