#include "../include/NhanVien.h"
#include <istream>
#include <ostream>

// Trả về lương của nhân viên
double NhanVien::getLuong() const { return mLuong; }

// Trả về ngày sinh nhân viên
Date NhanVien::getNgaySinh() const { return mNgaySinh; }

/* *
 * @brief Overload operator
 * @param is
 * @param rhs
 * @return istream &
 * */
istream &operator>>(istream &is, NhanVien &rhs) {
    is >> rhs.mHoTen >> rhs.mNgaySinh;

    return is;
}

/* *
 * @brief Overload operator
 * @param os
 * @param rhs
 * @return ostream &
 * */
ostream &operator<<(ostream &os, NhanVien const &rhs) {
    os << rhs.mHoTen.getS() << endl << rhs.mNgaySinh << endl;

    return os;
}
