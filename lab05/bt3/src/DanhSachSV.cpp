#include "../include/DanhSachSV.h"
#include <iostream>
#include <ostream>

//
DanhSachSV::~DanhSachSV() {
    delete[] mpCaoDang;
    delete[] mpDaiHoc;
}

/* *
 * @brief Overload operator
 * @param is
 * @param rhs
 * @return istream &
 * */
istream &operator>>(istream &is, DanhSachSV &rhs) {
    is >> rhs.mCaoDangCount >> rhs.mDaiHocCount;

    delete[] rhs.mpCaoDang;
    rhs.mpCaoDang = new SVCaoDang[rhs.mCaoDangCount];
    for (int i{0}; i < rhs.mCaoDangCount; ++i)
        is >> rhs.mpCaoDang[i];

    delete[] rhs.mpDaiHoc;
    rhs.mpDaiHoc = new SVDaiHoc[rhs.mDaiHocCount];
    for (int i{0}; i < rhs.mDaiHocCount; ++i)
        is >> rhs.mpDaiHoc[i];

    return is;
}

/* *
 * @brief Overload operator
 * @param os
 * @param rhs
 * @return ostream &
 * */
ostream &operator<<(ostream &os, DanhSachSV const &rhs) {
    os << "> Danh sach sinh vien cao dang:\n";
    for (int i{0}; i < rhs.mCaoDangCount; ++i)
        os << rhs.mpCaoDang[i] << endl << endl;

    os << "> Danh sach sinh vien dai hoc:\n";
    for (int i{0}; i < rhs.mDaiHocCount; ++i)
        os << rhs.mpDaiHoc[i] << endl << endl;

    return os;
}

/* *
 * @brief Xuất ra các sinh viên đủ điều kiện tốt nghiệp
 * @param void
 * @return void
 * */
void DanhSachSV::findSVTotNghiep(ostream &os) const {
    for (int i{0}; i < mCaoDangCount; ++i) {
        if (mpCaoDang[i].isTotNghiep())
            os << mpCaoDang[i];
    }

    for (int i{0}; i < mDaiHocCount; ++i) {
        if (mpDaiHoc[i].isTotNghiep())
            os << mpDaiHoc[i];
    }
}

/* *
 * @brief Xuất ra các sinh viên không đủ điều kiện tốt nghiệp
 * @param void
 * @return void
 * */
void DanhSachSV::findSVKhongTotNghiep(ostream &os) const {
    for (int i{0}; i < mCaoDangCount; ++i) {
        if (!mpCaoDang[i].isTotNghiep())
            os << mpCaoDang[i];
    }

    for (int i{0}; i < mDaiHocCount; ++i) {
        if (!mpDaiHoc[i].isTotNghiep())
            os << mpDaiHoc[i];
    }
}

/* *
 * @brief Tìm sinh viên Đại học có điểm trung bình cao nhất
 * @param void
 * @return SVDaiHoc
 * */
SVDaiHoc DanhSachSV::findMaxDTBDaiHoc() const {
    SVDaiHoc res{mpDaiHoc[0]};

    for (int i{1}; i < mDaiHocCount; ++i) {
        if (mpDaiHoc[i].getDiemTrungBinh() > res.getDiemTrungBinh())
            res = mpDaiHoc[i];
    }

    return res;
}

/* *
 * @brief Tìm sinh viên Cao đẳng có điểm trung bình cao nhất
 * @param void
 * @return SVCaoDang
 * */
SVCaoDang DanhSachSV::findMaxDTBCaoDang() const {
    SVCaoDang res{mpCaoDang[0]};

    for (int i{1}; i < mCaoDangCount; ++i) {
        if (mpCaoDang[i].getDiemTrungBinh() > res.getDiemTrungBinh())
            res = mpCaoDang[i];
    }

    return res;
}

/* *
 * @brief Đếm số sinh viên Đại học không đủ điều kiện tốt nghiệp
 * @param void
 * @return int
 * */
int DanhSachSV::countDHKhongTotNghiep() const {
    int res{0};
    for (int i{1}; i < mDaiHocCount; ++i) {
        if (!mpDaiHoc[i].isTotNghiep())
            res += 1;
    }

    return res;
}

/* *
 * @brief Đếm số sinh viên Cao đẳng không đủ điều kiện tốt nghiệp
 * @param void
 * @return int
 * */
int DanhSachSV::countCDKhongTotNghiep() const {
    int res{0};

    for (int i{1}; i < mCaoDangCount; ++i) {
        if (!mpCaoDang[i].isTotNghiep())
            res += 1;
    }

    return res;
}
