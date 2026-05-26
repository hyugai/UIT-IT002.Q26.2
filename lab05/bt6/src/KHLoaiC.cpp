#include "../include/KHLoaiC.h"

// Destructor
KHLoaiC::~KHLoaiC() {}

/* *
 * @brief Overload operator
 * @param is
 * @param rhs
 * @return istream &
 * */
istream &operator>>(istream &is, KHLoaiC &rhs) {
    is >> static_cast<KhachHang &>(rhs);

    return is;
}

/* *
 * @brief Overload operator
 * @param os
 * @param rhs
 * @return ostream &
 * */
ostream &operator<<(ostream &os, KHLoaiC const &rhs) {
    os << static_cast<KhachHang const &>(rhs) << endl;

    return os;
}

/* *
 * @brief Tính thành tiền cho khách hàng
 * @param void
 * @return void
 * */
void KHLoaiC::calcThanhTien() {
    mThanhTien = (mHangCount * mDonGia) * 0.5;
    mThanhTien *= (1 + VAT);
}
