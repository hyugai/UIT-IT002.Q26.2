#include "../include/cPhanSo.h"
#include <iostream>
#include <istream>
#include <ostream>
#include <stdexcept>

using namespace std;

cPhanSo::cPhanSo() {}
cPhanSo::cPhanSo(int t, int m) : mTu(t), mMau(m) {
    while (!mMau) {
        cout << "Nhap lai mau (khac 0): ";
        cin >> mMau;
    }
    simplyPhanSo();
}

/*
 * @brief Oveload operator >> dùng cho việc nhập
 * @param is
 * @param rhs Số phức cần được nhập
 * @return istream
 * */
istream &operator>>(istream &is, cPhanSo &rhs) {
    do {
        cout << "Nhap tu, mau (khac 0): ";
        is >> rhs.mTu >> rhs.mMau;
    } while (!rhs.mMau);

    rhs.simplyPhanSo();

    return is;
}

/* *
 * @brief Oveload operator << dùng cho việc xuất
 * @param os
 * @param rhs Số phức cần được xuất ra màn hình
 * @return ostream
 * */
ostream &operator<<(ostream &os, cPhanSo const &rhs) {
    if (rhs.mMau == 1) {
        os << rhs.mTu << endl;
        return os;
    }

    if (!rhs.mTu && !rhs.mMau) {
        os << 0 << endl;
        return os;
    }

    os << rhs.mTu << "/" << rhs.mMau << endl;

    return os;
}

/* *
 * @brief Kiểm tra 2 phân số có bằng nhau hay không
 * @param rhs
 * @return true(Giống nhau), false(Khác nhau)
 * */
bool cPhanSo::operator==(cPhanSo const &rhs) const {
    if (mTu == rhs.mTu && mMau == rhs.mMau)
        return true;

    return false;
}

/* *
 * @brief Kiểm tra phân số A có lon hon phan so B hay không
 * @param rhs
 * @return true(Lon hon), false(Nho hon)
 * */
bool cPhanSo::operator>(cPhanSo const &rhs) const {
    if (mTu * rhs.mMau > rhs.mTu * mMau)
        return true;

    return false;
}

/* *
 * @brief Kiểm tra phân số A có nho hon phan so B hay không
 * @param rhs
 * @return true(Nho hon), false(Lon hon)
 * */
bool cPhanSo::operator<(cPhanSo const &rhs) const {
    if (mTu * rhs.mMau < rhs.mTu * mMau)
        return true;

    return false;
}

/* *
 * @brief Cộng hai phân số
 * @param rhs
 * @return cPhanSo
 * */
cPhanSo cPhanSo::operator+(cPhanSo const &rhs) const {
    return cPhanSo{mTu * rhs.mMau + rhs.mTu * mMau, mMau * rhs.mMau};
}

/* *
 * @brief Trừ hai phân số
 * @param rhs
 * @return cPhanSo
 * */
cPhanSo cPhanSo::operator-(cPhanSo const &rhs) const {
    return cPhanSo{mTu * rhs.mMau - rhs.mTu * mMau, mMau * rhs.mMau};
}

/* *
 * @brief Nhân hai phân số
 * @param rhs
 * @return cPhanSo
 * */
cPhanSo cPhanSo::operator*(cPhanSo const &rhs) const {
    return cPhanSo{mTu * rhs.mTu, mMau * rhs.mMau};
}

/* *
 * @brief Chia hai phân số
 * @param rhs
 * @return cPhanSo
 * */
cPhanSo cPhanSo::operator/(cPhanSo const &rhs) const {
    if (!rhs.mTu)
        throw runtime_error("Division by zero");

    return cPhanSo{mTu * rhs.mMau, mMau * rhs.mTu};
}
