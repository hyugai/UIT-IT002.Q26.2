#include "../include/CMatrix.h"
#include <iostream>
#include <stdexcept>

using namespace std;

// Khởi tạo
CMatrix::CMatrix(int r, int c) : mSoDong(r), mSoCot(c) {
    cleanUpMem();

    mPhanTu = new double *[r];
    for (int i{0}; i < r; ++i) {
        mPhanTu[i] = new double[c];
    }
}

// Destructor
CMatrix::~CMatrix() { cleanUpMem(); }

// Trả về số dòng
int CMatrix::getSoDong() const { return mSoDong; }
// Trả về số cột
int CMatrix::getSoCot() const { return mSoCot; }

/*
 * @brief Oveload operator >> dùng cho việc nhập
 * @param is
 * @param rhs Số phức cần được nhập
 * @return istream
 * */
istream &operator>>(istream &is, CMatrix &rhs) {
    do {
        cout << "Nhap so dong, cot: ";
        is >> rhs.mSoDong >> rhs.mSoCot;
    } while (rhs.mSoDong < 1 || rhs.mSoCot < 1);

    int const &r{rhs.mSoDong}, &c{rhs.mSoCot};
    rhs.cleanUpMem();
    rhs.mPhanTu = new double *[r];

    for (int i{0}; i < r; ++i) {
        cout << "Nhap phan tu cho dong " << i + 1 << ": ";

        rhs.mPhanTu[i] = new double[c];

        for (int j{0}; j < c; ++j)
            is >> rhs.mPhanTu[i][j];
    }

    return is;
}

/* *
 * @brief Oveload operator << dùng cho việc xuất
 * @param os
 * @param rhs Số phức cần được xuất ra màn hình
 * @return ostream
 * */
ostream &operator<<(ostream &os, CMatrix const &rhs) {
    for (int i{0}; i < rhs.mSoDong; ++i) {
        for (int j{0}; j < rhs.mSoCot; ++j)
            os << " " << rhs.mPhanTu[i][j] << " ";

        os << endl;
    }
    return os;
}

/* *
 * @brief Cộng hai ma trận
 * @param rhs
 * @return CMatrix
 * */
CMatrix CMatrix::operator+(CMatrix const &rhs) const {
    CMatrix res{mSoDong, rhs.mSoCot};

    if (mSoCot != rhs.mSoCot || mSoDong != rhs.mSoDong) {
        throw runtime_error("Sai kich thuoc ma tran!");
    } else {
        for (int i{0}; i < mSoDong; ++i) {
            for (int j{0}; j < mSoCot; ++j)
                res.mPhanTu[i][j] = mPhanTu[i][j] + rhs.mPhanTu[i][j];
        }
    }

    return res;
}

/* *
 * @brief Trừ hai ma trận
 * @param rhs
 * @return CMatrix
 * */
CMatrix CMatrix::operator-(CMatrix const &rhs) const {
    CMatrix res{mSoDong, mSoCot};

    if (mSoCot != rhs.mSoCot || mSoDong != rhs.mSoDong) {
        throw runtime_error("Sai kich thuoc ma tran!");
    } else {
        for (int i{0}; i < mSoDong; ++i) {
            for (int j{0}; j < mSoCot; ++j)
                res.mPhanTu[i][j] = mPhanTu[i][j] - rhs.mPhanTu[i][j];
        }
    }

    return res;
}

/* *
 * @brief Nhân hai ma trận
 * @param rhs
 * @return CMatrix
 * */
CMatrix CMatrix::operator*(CMatrix const &rhs) const {
    int r{mSoDong}, c{rhs.mSoCot};
    CMatrix res{r, c};

    if (mSoCot != rhs.mSoDong) {
        throw runtime_error("Sai kich thuoc ma tran!");
    } else {

        for (int i{0}; i < r; ++i) {
            for (int j{0}; j < c; ++j) {

                double ele{0};
                for (int k{0}; k < mSoCot; ++k)
                    ele += mPhanTu[i][k] * rhs.mPhanTu[k][j];

                res.mPhanTu[i][j] = ele;
            }
        }
    }

    return res;
}

/* *
 * @brief Nhân ma trận và vector
 * @param rhs
 * @return CMatrix
 * */
CVector CMatrix::operator*(CVector const &rhs) const {
    int r{mSoDong}, c{1};
    double *pToaDo{rhs.getToaDo()};

    CVector res{r};
    double *pToaDoRes{res.getToaDo()};

    if (mSoCot != rhs.getSoChieu()) {
        throw runtime_error("Sai kich thuoc ma tran!");
    } else {

        for (int i{0}; i < r; ++i) {
            for (int j{0}; j < c; ++j) {

                double ele{0};
                for (int k{0}; k < mSoCot; ++k)
                    ele += mPhanTu[i][k] * pToaDo[k];

                pToaDoRes[i] = ele;
            }
        }
    }

    return res;
}
