#include "../include/cSoPhuc.h"
#include <cmath>
#include <iostream>
#include <istream>
#include <ostream>
#include <stdexcept>

using namespace std;

#define EPS 1e-8

// Khởi tạo số phức với phần thực và ảo đều bằng 0 (mặc định)
cSoPhuc::cSoPhuc(double t, double a) : mThuc(t), mAo(a) {}

/*
 * @brief Oveload operator >> dùng cho việc nhập
 * @param is
 * @param o Số phức cần được nhập
 * @return istream
 * */
istream &operator>>(istream &is, cSoPhuc &o) {
    cout << "Nhap phan thuc, ao: ";
    is >> o.mThuc >> o.mAo;

    return is;
}

/* *
 * @brief Oveload operator << dùng cho việc xuất
 * @param os
 * @param o Số phức cần được xuất ra màn hình
 * @return ostream
 * */
ostream &operator<<(ostream &os, cSoPhuc const &o) {
    if (o.mThuc)
        os << (o.mThuc < 0 ? "-" : "") << fabs(o.mThuc);

    if (o.mAo) {
        os << (o.mAo < 0 ? " - " : " + ");

        if (fabs(o.mAo) != 1)
            os << fabs(o.mAo);

        os << "i";
    }

    if (!o.mThuc && !o.mAo)
        os << 0;

    os << endl;

    return os;
}

/* *
 * @brief Kiểm tra 2 số phức có bằng nhau hay không
 * @param rhs
 * @return true(Giống nhau), false(Khác nhau)
 * */
bool cSoPhuc::operator==(cSoPhuc const &rhs) const {
    if (fabs(mThuc - rhs.mThuc) <= EPS && fabs(mAo - rhs.mAo) <= EPS)
        return true;

    return false;
}

/* *
 * @brief Kiểm tra 2 số phức có khác nhau hay không
 * @param rhs
 * @return true(Khác nhau), false(Giống nhau)
 * */
bool cSoPhuc::operator!=(cSoPhuc const &rhs) const {
    if (fabs(mThuc - rhs.mThuc) > EPS || fabs(mAo - rhs.mAo) > EPS)
        return true;

    return false;
}

/* *
 * @brief Cộng hai số phức
 * @param rhs
 * @return cSoPhuc
 * */
cSoPhuc cSoPhuc::operator+(cSoPhuc const &rhs) const {
    return cSoPhuc{mThuc + rhs.mThuc, mAo + rhs.mAo};
}

/* *
 * @brief Trừ hai số phức
 * @param rhs
 * @return cSoPhuc
 * */
cSoPhuc cSoPhuc::operator-(cSoPhuc const &rhs) const {
    return cSoPhuc{mThuc - rhs.mThuc, mAo - rhs.mAo};
}

/* *
 * @brief Nhân hai số phức
 * @param rhs
 * @return cSoPhuc
 * */
cSoPhuc cSoPhuc::operator*(cSoPhuc const &rhs) const {
    return cSoPhuc{mThuc * rhs.mThuc - mAo * rhs.mAo,
                   mThuc * rhs.mAo + mAo * rhs.mThuc};
}

/* *
 * @brief Chia hai số phức
 * @param rhs
 * @return cSoPhuc
 * */
cSoPhuc cSoPhuc::operator/(cSoPhuc const &rhs) const {
    double tuThuc, tuAo, mau;

    mau = pow(rhs.mThuc, 2) + pow(rhs.mAo, 2);
    if (fabs(mau) < EPS)
        throw runtime_error("Division by zero");

    tuThuc = mThuc * rhs.mThuc + mAo * rhs.mAo;
    tuAo = mAo * rhs.mThuc - mThuc * rhs.mAo;

    return cSoPhuc{tuThuc / mau, tuAo / mau};
}
