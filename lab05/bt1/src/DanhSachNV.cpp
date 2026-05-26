#include "../include/DanhSachNV.h"
#include <iomanip>
#include <iostream>
#include <istream>
#include <ostream>

using namespace std;

// Destructor
DanhSachNV::~DanhSachNV() {
    delete[] mpSX;
    delete[] mpVP;
}

/* *
 * @brief Overload operator
 * @param is
 * @param rhs
 * @return istream &
 * */
istream &operator>>(istream &is, DanhSachNV &rhs) {
    do {
        is >> rhs.mSXCount;
    } while (rhs.mSXCount <= 0);

    do {
        is >> rhs.mVPCount;
    } while (rhs.mVPCount <= 0);

    delete[] rhs.mpSX;
    rhs.mpSX = new NVSanXuat[rhs.mSXCount];

    for (int i{0}; i < rhs.mSXCount; ++i)
        is >> rhs.mpSX[i];

    delete[] rhs.mpVP;
    rhs.mpVP = new NVVanPhong[rhs.mVPCount];

    for (int i{0}; i < rhs.mVPCount; ++i)
        is >> rhs.mpVP[i];

    return is;
}

/* *
 * @brief Overload operator
 * @param os
 * @param rhs
 * @return ostream &
 * */
ostream &operator<<(ostream &os, DanhSachNV const &rhs) {
    os << rhs.mSXCount << ' ' << rhs.mVPCount << endl
       << "> Danh sach nhan vien san xuat:\n";
    for (int i{0}; i < rhs.mSXCount; ++i)
        os << fixed << setprecision(2) << rhs.mpSX[i] << endl;

    os << "> Danh sach nhan vien van phong:\n";
    for (int i{0}; i < rhs.mVPCount; ++i)
        os << fixed << setprecision(2) << rhs.mpVP[i] << endl;

    return os;
}

/* *
 * @brief Tính lương cho các nhân viên
 * @param void
 * @return void
 * */
void DanhSachNV::calcLuongNV() {
    for (int i{0}; i < mSXCount; ++i)
        mpSX[i].calcLuong();

    for (int i{0}; i < mVPCount; ++i)
        mpVP[i].calcLuong();
}

/* *
 * @brief Tính tổng lương công ty phải trả
 * @param void
 * @return double
 * */
double DanhSachNV::calcTongLuongNV() const {
    double res{0};

    for (int i{0}; i < mSXCount; ++i)
        res += mpSX[i].getLuong();

    for (int i{0}; i < mVPCount; ++i)
        res += mpVP[i].getLuong();

    return res;
}

/* *
 * @brief Tìm nhân viên sản xuất có lương thấp nhất
 * @param void
 * @return NVSanXuat
 * */
NVSanXuat DanhSachNV::findMinLuongSX() const {
    NVSanXuat res{mpSX[0]};

    for (int i{1}; i < mSXCount; ++i) {
        if (mpSX[i].getLuong() < res.getLuong())
            res = mpSX[i];
    }

    return res;
}

/* *
 * @brief Tìm nhân viên văn phòng cao tuổi nhất
 * @param void
 * @return NVVanPhong
 * */
NVVanPhong DanhSachNV::findMaxTuoiVP() const {
    NVVanPhong res{mpVP[0]};

    for (int i{1}; i < mVPCount; ++i) {
        if (mpVP[i].getNgaySinh() > res.getNgaySinh()) {
            res = mpVP[i];
        }
    }

    return res;
}
