#pragma once

#include <istream>
#include <ostream>

using namespace std;

struct MyDate {
    /* *
     * @brief Change private properties
     *
     * @param n must be an integer
     *
     * @return void
     * */
    void setDay(int n);
    void setMonth(int n);
    void setYear(int n);

    /* *
     * @brief overload input/output operation (>>, <<)
     *
     * @param out/in
     * @param f
     *
     * @return ostream&/istrem&
     * */
    friend ostream &operator<<(ostream &out, const MyDate &date);
    friend istream &operator>>(istream &in, MyDate &date);

    friend MyDate operator+(const MyDate &, int);

  private:
    int day, month, year;
};

/* *
 * @brief determine leap year
 *
 * @param y year
 *
 * divided by 4 AND not by 100, OR divided by 400
 *
 * @return bool true: leap year, false: otherwise
 *
 * */
bool isLeapYear(int y);

/* *
 * @brief determine max number of days in a month
 *
 * @param m month
 * @param y year
 *
 * @return int
 * */
int getMaxDaysOfMonth(int m, int y);

/* *
 * @brief validate input date
 *
 * @param d day
 * @param m month
 * @param y year
 *
 * y greater than 0, m in range from 1 to 12, d greater than 0 and in range of
 * month
 *
 * @return true: valid date, false: otherwise
 * */
bool isDateValid(int d, int m, int y);
