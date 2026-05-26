#include "../include/NVSanXuat.h"
#include <istream>
#include <iostream>

// Destructor
NVSanXuat::~NVSanXuat() {}

/* *
 * @brief Overload operator
 * @param is
 * @param rhs
 * @return istream &
 * */
istream &operator>>(istream &is, NVSanXuat &rhs) {
    is >> static_cast<NhanVien &>(rhs);

    do {
        is >> rhs.mLuongCanBan;
    } while (rhs.mLuongCanBan <= 0);

    do {
        is >> rhs.mSoSanPham;
    } while (rhs.mSoSanPham <= 0);

    return is;
}

/* *
 * @brief Overload operator
 * @param os
 * @param rhs
 * @return ostream &
 * */
ostream &operator<<(ostream &os, NVSanXuat const &rhs) {
    os << static_cast<NhanVien const &>(rhs) << rhs.mLuongCanBan << endl
       << rhs.mSoSanPham << endl
       << rhs.mLuong << endl;

    return os;
}

/* *
 * @brief Tính lương cho nhân viên
 * @param void
 * @return void
 * */
void NVSanXuat::calcLuong() { mLuong = mLuongCanBan * mSoSanPham; }
