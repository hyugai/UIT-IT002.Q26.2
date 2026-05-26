#include "../include/Date.h"
#include <iomanip>
#include <iostream>
#include <istream>
#include <ostream>

using namespace std;

// Trả về tháng
int Date::getThang() const { return mThang; }

// Trả về năm
int Date::getNam() const { return mNam; }

/* *
 * @brief Overload operator
 * @param is
 * @param rhs
 * @return istream &
 * */
istream &operator>>(istream &is, Date &rhs) {
    do {
        is >> rhs.mNgay >> rhs.mThang >> rhs.mNam;
    } while (!rhs.isNgayHopLe());

    return is;
}

/* *
 * @brief Overload operator
 * @param os
 * @param rhs
 * @return ostream &
 * */
ostream &operator<<(ostream &os, Date const &rhs) {
    os << setw(2) << setfill('0') << rhs.mNgay << '-' << rhs.mThang << '-'
       << rhs.mNam;

    return os;
}

/* *
 * @brief Overload operator
 * @param rhs
 * @return bool
 * */
bool Date::operator>(Date const &rhs) const {
    if (mNam < rhs.mNam)
        return true;

    if (mThang < rhs.mThang)
        return true;

    if (mNgay < rhs.mNgay)
        return true;

    return false;
}
