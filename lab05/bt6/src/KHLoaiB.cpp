#include "../include/KHLoaiB.h"

// Destructor
KHLoaiB::~KHLoaiB() {}

/* *
 * @brief Overload operator
 * @param is
 * @param rhs
 * @return istream &
 * */
istream &operator>>(istream &is, KHLoaiB &rhs) {
    is >> static_cast<KhachHang &>(rhs) >> rhs.mNamThanThietCount;

    return is;
}

/* *
 * @brief Overload operator
 * @param os
 * @param rhs
 * @return ostream &
 * */
ostream &operator<<(ostream &os, KHLoaiB const &rhs) {
    os << static_cast<KhachHang const &>(rhs) << endl << endl;

    return os;
}

/* *
 * @brief Tính thành tiền cho khách hàng
 * @param void
 * @return void
 * */
void KHLoaiB::calcThanhTien() {
    mKhuyenMaiPercentage =
        (mNamThanThietCount * 0.05 > 0.5 ? mNamThanThietCount * 0.05 : 0.5);

    mThanhTien = (mHangCount * mDonGia) * (1 - mKhuyenMaiPercentage);
    mThanhTien *= (1 + VAT);
}
