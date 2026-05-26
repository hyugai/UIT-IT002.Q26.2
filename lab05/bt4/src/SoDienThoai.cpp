#include "../include/SoDienThoai.h"
#include <string>
#include <iostream>

// Trả về số điện thoại
string SoDienThoai::getS() const { return mS; }

/* *
 * @brief Overload operator
 * @param is
 * @param rhs
 * @return istream &
 * */
istream &operator>>(istream &is, SoDienThoai &rhs) {
    do {
        is >> rhs.mS;
    } while (!rhs.isValid());

    return is;
}
