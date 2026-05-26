#include "../include/SinhVien.h"
#include <string>
#include <iostream>

// Trả về điểm trung bình của sinh viên
double SinhVien::getDiemTrungBinh() const { return mDiemTrungBinh; }

/* *
 * @brief Overload operator
 * @param is
 * @param rhs
 * @return istream &
 * */
istream &operator>>(istream &is, SinhVien &rhs) {
    is >> rhs.mId;

    // cout << "Nhap ho ten: ";
    is >> rhs.mHoTen;

    do {
        // cout << "Nhap dia chi: ";
        is.ignore();
        getline(is, rhs.mDiaChi);
    } while (rhs.mDiaChi.length() <= 0);

    do {
        // cout << "Nhap so tin chi: ";
        is >> rhs.mTinChiCount;
    } while (rhs.mTinChiCount < 0);

    do {
        // cout << "Nhap diem trung binh: ";
        is >> rhs.mDiemTrungBinh;
    } while (rhs.mDiemTrungBinh < 0);

    return is;
}

/* *
 * @brief Overload operator
 * @param os
 * @param rhs
 * @return ostream &
 * */
ostream &operator<<(ostream &os, SinhVien const &rhs) {
    os << rhs.mId << endl
       << rhs.mHoTen.getS() << endl
       << rhs.mDiaChi << endl
       << rhs.mTinChiCount << endl
       << rhs.mDiemTrungBinh << endl;
    return os;
}
