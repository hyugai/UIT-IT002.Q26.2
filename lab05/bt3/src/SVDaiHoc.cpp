#include "../include/SVDaiHoc.h"
#include <string>

// Destructor
SVDaiHoc::~SVDaiHoc() {}

/* *
 * @brief Overload operator
 * @param is
 * @param rhs
 * @return istream &
 * */
istream &operator>>(istream &is, SVDaiHoc &rhs) {
    is >> static_cast<SinhVien &>(rhs);

    do {
        is.ignore();
        getline(is, rhs.mTenLuanVan);
    } while (rhs.mTenLuanVan.length() <= 0);

    is >> rhs.mDiemLuanVan;

    return is;
}

/* *
 * @brief Overload operator
 * @param os
 * @param rhs
 * @return ostream &
 * */
ostream &operator<<(ostream &os, SVDaiHoc const &rhs) {
    os << static_cast<SinhVien const &>(rhs) << rhs.mTenLuanVan << endl
       << rhs.mDiemLuanVan << endl;

    return os;
}

/* *
 * @brief Kiểm tra xem sinh viên có đủ điều kiện tốt nghiệp không
 * @param void
 * @return bool
 * */
bool SVDaiHoc::isTotNghiep() const {
    return (mTinChiCount >= 120 && mDiemTrungBinh >= 5 && mDiemLuanVan >= 5)
               ? true
               : false;
}
