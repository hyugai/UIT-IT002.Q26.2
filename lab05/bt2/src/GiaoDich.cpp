#include "../include/GiaoDich.h"
#include <istream>
#include <string>
#include <iostream>

// Trả về thành tiền
double GiaoDich::getThanhTien() const { return mThanhTien; }

// Trả về ngày giao dịch
Date GiaoDich::getNgayGD() const { return mNgayGiaoDich; }

/* *
 * @brief Overload operator
 * @param is
 * @param rhs
 * @return istream &
 * */
istream &operator>>(istream &is, GiaoDich &rhs) {
    // cout << "nhap ma giao dich: ";
    is >> rhs.mMaGD;

    // cout << "nhap ngay: ";
    is >> rhs.mNgayGiaoDich;

    do {
        // cout << "nhap don gia: ";
        is >> rhs.mDonGia;
    } while (rhs.mDonGia <= 0);

    do {
        // cout << "nhap dien tich: ";
        is >> rhs.mDienTich;
    } while (rhs.mDienTich <= 0);

    return is;
}

/* *
 * @brief Overload operator
 * @param os
 * @param rhs
 * @return ostream &
 * */
ostream &operator<<(ostream &os, GiaoDich const &rhs) {
    os << rhs.mMaGD << endl
       << rhs.mNgayGiaoDich << endl
       << rhs.mDonGia << endl
       << rhs.mDienTich << endl
       << rhs.mThanhTien << endl;

    return os;
}
