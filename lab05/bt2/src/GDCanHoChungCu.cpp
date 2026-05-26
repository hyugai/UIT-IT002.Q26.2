#include "../include/GDCanHoChungCu.h"
#include <string>
#include <iostream>

// Destructor
GDCanHoChungCu::~GDCanHoChungCu() {}

/* *
 * @brief Overload operator
 * @param is
 * @param rhs
 * @return istream &
 * */
istream &operator>>(istream &is, GDCanHoChungCu &rhs) {
    is >> static_cast<GiaoDich &>(rhs);

    // rhs.mMaGD.setS("GDCHCC");
    // rhs.mMaCan.setS("C");

    do {
        // cout << "nhap vi tri tang: ";
        is >> rhs.mViTriTang;
    } while (rhs.mViTriTang < 1);

    // cout << "nhap ma can: ";
    do {
        is >> rhs.mMaCan;
    } while (rhs.mMaCan.length() <= 0);

    return is;
}

/* *
 * @brief Overload operator
 * @param os
 * @param rhs
 * @return ostream &
 * */
ostream &operator<<(ostream &os, GDCanHoChungCu const &rhs) {
    os << static_cast<GiaoDich const &>(rhs);

    os << rhs.mMaCan << endl << rhs.mViTriTang;

    return os;
}

/* *
 * @brief Tính thành tiền giao dịch
 * @param void
 * @return void
 * */
void GDCanHoChungCu::calcThanhTien() {
    if (mViTriTang == 1)
        mThanhTien = mDonGia * mDienTich * 2.0;
    else if (mViTriTang >= 15)
        mThanhTien = mDonGia * mDienTich * 1.2;
    else
        mThanhTien = mDonGia * mDienTich;
}
