#include "../include/NVKiemChung.h"

// Destructor
NVKiemChung::~NVKiemChung() {}

/* *
 * @brief Overload operator
 * @param is
 * @param rhs
 * @return istream &
 * */
istream &operator>>(istream &is, NVKiemChung &rhs) {
    is >> static_cast<NhanVien &>(rhs);

    do {
        // cout << "Nhap so loi phat hien duoc: ";
        is >> rhs.mLoiPhatHienCount;
    } while (rhs.mLoiPhatHienCount < 0);

    return is;
}

/* *
 * @brief Overload operator
 * @param os
 * @param rhs
 * @return ostream &
 * */
ostream &operator<<(ostream &os, NVKiemChung const &rhs) {
    os << static_cast<NhanVien const &>(rhs) << rhs.mLoiPhatHienCount << endl;

    return os;
}

/* *
 * @brief Tính lương cho nhân viên
 * @param void
 * @return void
 * */
void NVKiemChung::calcLuong() {
    mLuong = mLuongCoBan + mLoiPhatHienCount * 50000.0;
}
