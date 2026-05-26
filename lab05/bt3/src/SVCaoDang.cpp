#include "../include/SVCaoDang.h"

// Destructor
SVCaoDang::~SVCaoDang() {}

/* *
 * @brief Overload operator
 * @param is
 * @param rhs
 * @return istream &
 * */
istream &operator>>(istream &is, SVCaoDang &rhs) {
    is >> static_cast<SinhVien &>(rhs);

    do {
        is >> rhs.mDiemThiTotNghiep;
    } while (rhs.mDiemThiTotNghiep < 0);

    return is;
}

/* *
 * @brief Overload operator
 * @param os
 * @param rhs
 * @return ostream &
 * */
ostream &operator<<(ostream &os, SVCaoDang const &rhs) {
    os << static_cast<SinhVien const &>(rhs) << rhs.mDiemThiTotNghiep << endl;

    return os;
}

/* *
 * @brief Kiểm tra xem sinh viên có đủ điều kiện tốt nghiệp không
 * @param void
 * @return bool
 * */
bool SVCaoDang::isTotNghiep() const {
    return (mTinChiCount >= 120 && mDiemTrungBinh >= 5 &&
            mDiemThiTotNghiep >= 5)
               ? true
               : false;
}
