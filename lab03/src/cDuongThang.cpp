#include "../include/cDuongThang.h"

// #include <iostream>
// using namespace std;

// Defaulted constructor
cDuongThang::cDuongThang() {}

// Parameterized constructor: Khởi tạo đường thẳng với 2 điểm cho trước
cDuongThang::cDuongThang(cDiem const &p1, cDiem const &p2) {
    cDiem direction_vector{p2.calcVector(p1)};
    mHeSoX = -direction_vector.getY();
    mHeSoY = direction_vector.getX();

    mHangSo = mHeSoX * (-p1.getX()) + mHeSoY * (-p1.getY());
}

// Trả về hệ số A trong (d): Ax + By + C = 0
double cDuongThang::getHeSoX() const { return mHeSoX; }

// Trả về hệ số B trong (d): Ax + By + C = 0
double cDuongThang::getHeSoY() const { return mHeSoY; }

// Trả về hằng số số C trong (d): Ax + By + C = 0
double cDuongThang::getHangSo() const { return mHangSo; }

/* *
 * @brief Kiểm tra điểm có thuộc đường thẳng không
 * @param p Điểm cần kiểm tra
 * @return int -1(trái), 0(thuộc đường thẳng), 1(phải)
 * */
int cDuongThang::calcViTriDiem(cDiem const &p) const {
    double val{mHeSoX * p.getX() + mHeSoY * p.getY() + mHangSo};

    if (val >= 0 && val < 1e-8)
        return 0;

    return (val < 0 ? -1 : 1);
}
