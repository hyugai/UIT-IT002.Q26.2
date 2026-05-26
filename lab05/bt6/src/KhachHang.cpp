#include "../include/KhachHang.h"

/* *
 * @brief Overload operator
 * @param is
 * @param rhs
 * @return istream &
 * */
istream &operator>>(istream &is, KhachHang &rhs) {
    is >> rhs.mHoTen >> rhs.mHangCount >> rhs.mDonGia;

    return is;
}

/* *
 * @brief Overload operator
 * @param os
 * @param rhs
 * @return ostream &
 * */
ostream &operator<<(ostream &os, KhachHang const &rhs) {
    os << rhs.mHoTen.getS() << endl << rhs.mThanhTien << endl;
    return os;
}
