#include "../include/GDNhaPho.h"
#include <iostream>
#include <string>

// Destructor
GDNhaPho::~GDNhaPho() {}

/* *
 * @brief Overload operator
 * @param is
 * @param rhs
 * @return istream &
 * */
istream &operator>>(istream &is, GDNhaPho &rhs) {
    is >> static_cast<GiaoDich &>(rhs);

    // rhs.mMaGD.setS("GDNP");

    // cout << "nhap dia chi: ";
    do {
        is.ignore();
        getline(is, rhs.mDiaChi);
    } while (rhs.mDiaChi.length() <= 0);

    int inp;
    do {
        // cout << "nhap loai nha: ";
        is >> inp;
    } while (inp != 0 && inp != 1);
    rhs.mLoaiNha = static_cast<LoaiNha>(inp);

    return is;
}

/* *
 * @brief Overload operator
 * @param os
 * @param rhs
 * @return ostream &
 * */
ostream &operator<<(ostream &os, GDNhaPho const &rhs) {
    os << static_cast<GiaoDich const &>(rhs);

    if (rhs.mLoaiNha == LoaiNha::CaoCap)
        os << "cao cap";
    else
        os << "thuong";

    os << endl << rhs.mDiaChi;

    return os;
}

/* *
 * @brief Tính thành tiền giao dịch
 * @param void
 * @return void
 * */
void GDNhaPho::calcThanhTien() {
    if (mLoaiNha == LoaiNha::CaoCap)
        mThanhTien = mDonGia * mDienTich;
    else
        mThanhTien = mDonGia * mDienTich * 0.9;
}
