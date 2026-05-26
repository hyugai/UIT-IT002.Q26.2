#include "../include/HoTen.h"
#include <istream>
#include <iostream>
#include <string>

/* *
 * @brief
 * @param
 * @return
 * */
istream &operator>>(istream &is, HoTen &rhs) {
    do {
        is.ignore();
        getline(is, rhs.mS);
    } while (!rhs.isTenHopLe());

    return is;
}

/* *
 * @brief
 * @param
 * @return
 * */
ostream &operator<<(ostream &os, HoTen const &rhs) {
    os << rhs.mS;

    return os;
}
