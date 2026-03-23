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
     * @param out/in left operand
     * @param f right operand
     *
     * @return ostream/istream
     * */
    friend ostream &operator<<(ostream &out, const MyDate &date);
    friend istream &operator>>(istream &in, MyDate &date);

    /* *
     * @brief increase current date by n days
     *
     * increase day -> month -> year
     *
     * @param date
     * @param n
     *
     * @return MyDate new date as a result of n days
     * */
    friend MyDate operator+(const MyDate &date, int n);

  private:
    int day, month, year;
};

/* *
 * @brief check if leap year or not
 *
 * divided by 4 AND not by 100, OR divided by 400
 *
 * @param y year
 *
 * @return bool true: leap year, false: otherwise
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
 * y greater than 0, m in range from 1 to 12, d greater than 0 and in range of
 * month
 *
 * @param d day
 * @param m month
 * @param y year
 *
 * @return true: valid date, false: otherwise
 * */
bool isDateValid(int d, int m, int y);
