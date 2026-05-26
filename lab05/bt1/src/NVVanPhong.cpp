#include "../include/NVVanPhong.h"
#include <istream>
#include <iostream>

// Destructor
NVVanPhong::~NVVanPhong() {}

/* *
 * @brief Overload operator
 * @param is
 * @param rhs
 * @return istream &
 * */
istream &operator>>(istream &is, NVVanPhong &rhs) {
    is >> static_cast<NhanVien &>(rhs);

    do {
        is >> rhs.mSoNgayLamViec;
    } while (rhs.mSoNgayLamViec <= 0);

    return is;
}

/* *
 * @brief Overload operator
 * @param os
 * @param rhs
 * @return ostream &
 * */
ostream &operator<<(ostream &os, NVVanPhong const &rhs) {
    os << static_cast<NhanVien const &>(rhs) << rhs.mSoNgayLamViec << endl
       << rhs.mLuong << endl;

    return os;
}

/* *
 * @brief Tính lương cho nhân viên
 * @param void
 * @return void
 * */
void NVVanPhong::calcLuong() { mLuong = mSoNgayLamViec * 100000; }
