#include "../include/NhanVien.h"
#include <iomanip>
#include <string>

// Trả về lương cho nhân viên
double NhanVien::getLuong() const { return mLuong; }

/* *
 * @brief Overload operator
 * @param is
 * @param rhs
 * @return istream &
 * */
istream &operator>>(istream &is, NhanVien &rhs) {
    is >> rhs.mMaNhanVien;

    is >> rhs.mHoTen;

    do {
        is >> rhs.mTuoi;
    } while (rhs.mTuoi <= 0);

    is >> rhs.mSoDienThoai;

    is >> rhs.mEmail;

    do {
        is >> rhs.mLuongCoBan;
    } while (rhs.mLuongCoBan <= 0);

    return is;
}

/* *
 * @brief Overload operator
 * @param os
 * @param rhs
 * @return ostream &
 * */
ostream &operator<<(ostream &os, NhanVien const &rhs) {
    os << rhs.mMaNhanVien << endl
       << rhs.mHoTen.getS() << endl
       << rhs.mSoDienThoai.getS() << endl
       << rhs.mEmail.getS() << endl
       << fixed << setprecision(3) << rhs.mLuongCoBan << endl;

    return os;
}
