#include "../include/NVLapTrinh.h"

// Destructor
NVLapTrinh::~NVLapTrinh() {}

/* *
 * @brief Overload operator
 * @param is
 * @param rhs
 * @return istream &
 * */
istream &operator>>(istream &is, NVLapTrinh &rhs) {
    is >> static_cast<NhanVien &>(rhs);

    do {
        // cout << "Nhap so gio overtime: ";
        is >> rhs.mOverTimeCount;
    } while (rhs.mOverTimeCount < 0);

    return is;
}

/* *
 * @brief Overload operator
 * @param os
 * @param rhs
 * @return ostream &
 * */
ostream &operator<<(ostream &os, NVLapTrinh const &rhs) {
    os << static_cast<NhanVien const &>(rhs) << rhs.mOverTimeCount << endl;

    return os;
}

/* *
 * @brief Tính lương cho nhân viên
 * @param void
 * @return void
 * */
void NVLapTrinh::calcLuong() {
    mLuong = mLuongCoBan + mOverTimeCount * 200000.0;
}
