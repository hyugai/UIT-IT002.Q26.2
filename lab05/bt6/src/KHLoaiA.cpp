#include "../include/KHLoaiA.h"

// Destructor
KHLoaiA::~KHLoaiA() {}

/* *
 * @brief Overload operator
 * @param is
 * @param rhs
 * @return istream &
 * */
istream &operator>>(istream &is, KHLoaiA &rhs) {
    is >> static_cast<KhachHang &>(rhs);

    return is;
}

/* *
 * @brief Overload operator
 * @param os
 * @param rhs
 * @return ostream &
 * */
ostream &operator<<(ostream &os, KHLoaiA const &rhs) {
    os << static_cast<KhachHang const &>(rhs) << endl;

    return os;
}

/* *
 * @brief Tính thành tiền cho khách hàng
 * @param void
 * @return void
 * */
void KHLoaiA::calcThanhTien() {
    mThanhTien = mHangCount * mDonGia;
    mThanhTien *= (1 + VAT);
}
