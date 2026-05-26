#include "../include/Email.h"
#include <iostream>

// Trả về email
string Email::getS() const { return mS; }

/* *
 * @brief Overload operator
 * @param is
 * @param rhs
 * @return istream &
 * */
istream &operator>>(istream &is, Email &rhs) {
    do {
        is >> rhs.mS;
    } while (!rhs.isValid());

    return is;
}
