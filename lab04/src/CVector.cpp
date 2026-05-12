#include "../include/CVector.h"
#include <iostream>

using namespace std;

// Constructor
CVector::CVector(int n) : mSoChieu(n) {
    delete[] mToaDo;
    mToaDo = new double[n];
}

// Destructor
CVector::~CVector() { delete[] mToaDo; }

// Trả về số chiều
int CVector::getSoChieu() const { return mSoChieu; }

// Trả về con trỏ tới mảng chứa tọa độ
double *CVector::getToaDo() const { return mToaDo; }

/*
 * @brief Oveload operator >> dùng cho việc nhập
 * @param is
 * @param rhs Số phức cần được nhập
 * @return istream
 * */
istream &operator>>(istream &is, CVector &rhs) {
    cout << "Nhap so chieu: ";
    is >> rhs.mSoChieu;

    delete[] rhs.mToaDo;
    rhs.mToaDo = new double[rhs.mSoChieu];

    cout << "Nhap toa do: ";
    for (int i{0}; i < rhs.mSoChieu; i++)
        is >> rhs.mToaDo[i];

    return is;
}

/* *
 * @brief Oveload operator << dùng cho việc xuất
 * @param os
 * @param rhs Số phức cần được xuất ra màn hình
 * @return ostream
 * */
ostream &operator<<(ostream &os, CVector const &rhs) {
    os << "[";
    for (int i{0}; i < rhs.mSoChieu; i++) {
        os << " " << rhs.mToaDo[i] << " ";
    }
    os << "]" << endl;

    return os;
}

/* *
 * @brief Cộng hai vector
 * @param rhs
 * @return CVector
 * */
CVector CVector::operator+(CVector const &rhs) const {
    CVector res{mSoChieu};

    for (int i{0}; i < mSoChieu; ++i)
        res.mToaDo[i] = mToaDo[i] + rhs.mToaDo[i];

    return res;
}

/* *
 * @brief Trừ hai vector
 * @param rhs
 * @return CVector
 * */
CVector CVector::operator-(CVector const &rhs) const {
    CVector res{mSoChieu};

    for (int i{0}; i < mSoChieu; ++i)
        res.mToaDo[i] = mToaDo[i] - rhs.mToaDo[i];

    return res;
}

/* *
 * @brief Nhân hai vector
 * @param rhs
 * @return CVector
 * */
int CVector::operator*(CVector const &rhs) const {
    int res{0};

    for (int i{0}; i < mSoChieu; ++i)
        res += mToaDo[i] * rhs.mToaDo[i];

    return res;
}
