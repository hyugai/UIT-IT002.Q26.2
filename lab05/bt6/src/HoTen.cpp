#include "../include/HoTen.h"
#include <istream>
#include <iostream>
#include <string>

// Trả về tên
string HoTen::getS() const { return mS; }

/* *
 * @brief Overload operator
 * @param is
 * @param rhs
 * @return istream &
 * */
istream &operator>>(istream &is, HoTen &rhs) {
    do {
        is.ignore();
        getline(is, rhs.mS);
    } while (!rhs.isTenHopLe());

    return is;
}
