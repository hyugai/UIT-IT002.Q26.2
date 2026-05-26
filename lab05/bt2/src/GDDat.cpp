#include "../include/GDDat.h"
#include <istream>
#include <iostream>

// Destructor
GDDat::~GDDat() {}

/* *
 * @brief Overload operator
 * @param is
 * @param rhs
 * @return istream &
 * */
istream &operator>>(istream &is, GDDat &rhs) {
    is >> static_cast<GiaoDich &>(rhs);

    // rhs.mMaGD.setS("");

    int inp;
    do {
        // cout << "nhap loai dat: ";
        is >> inp;
    } while (inp != 0 && inp != 1 && inp != 2);
    rhs.mLoaiDat = static_cast<LoaiDat>(inp);

    return is;
}

/* *
 * @brief Overload operator
 * @param os
 * @param rhs
 * @return ostream &
 * */
ostream &operator<<(ostream &os, GDDat const &rhs) {
    os << static_cast<GiaoDich const &>(rhs);

    if (rhs.mLoaiDat == LoaiDat::A)
        os << "A";
    else if (rhs.mLoaiDat == LoaiDat::B)
        os << "B";
    else
        os << "C";

    return os;
}

/* *
 * @brief Tính thành tiền giao dịch
 * @param void
 * @return void
 * */
void GDDat::calcThanhTien() {
    if (mLoaiDat == LoaiDat::B || mLoaiDat == LoaiDat::C)
        mThanhTien = mDienTich * mDonGia;
    else
        mThanhTien = mDienTich * mDonGia * 1.5;
}
