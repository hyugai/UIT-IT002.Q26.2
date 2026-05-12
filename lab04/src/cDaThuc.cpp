#include "../include/cDaThuc.h"
#include <cmath>
#include <iostream>
#include <istream>
#include <ostream>

using namespace std;

//
cDaThuc::cDaThuc(int n) : mBac(n) { mHeSo = new double[n + 1]; }
//
cDaThuc::~cDaThuc() { delete[] mHeSo; }

/*
 * @brief Oveload operator >> dùng cho việc nhập
 * @param is
 * @param rhs Số phức cần được nhập
 * @return istream
 * */
istream &operator>>(istream &is, cDaThuc &rhs) {
    cout << "Nhap bac n: ";
    is >> rhs.mBac;

    delete[] rhs.mHeSo;
    rhs.mHeSo = new double[rhs.mBac + 1];

    cout << "Nhap he so (cao den thap): ";
    for (int i{rhs.mBac}; i >= 0; --i)
        is >> rhs.mHeSo[i];

    return is;
}

/* *
 * @brief Oveload operator << dùng cho việc xuất
 * @param os
 * @param rhs Số phức cần được xuất ra màn hình
 * @return ostream
 * */
ostream &operator<<(ostream &os, cDaThuc const &rhs) {
    bool flag{true};

    for (int i{rhs.mBac}; i >= 0; --i) {
        double const &heSo = rhs.mHeSo[i];

        if (heSo) {
            os << (heSo < 0 ? " - " : " + ");
            if (fabs(heSo) != 1)
                os << fabs(heSo);
            else if (!i)
                os << fabs(heSo);

            os << (i ? "x" : "");
            if (i > 1)
                os << "^" << i;

            flag = false;
        }
    }

    os << (flag ? " 0" : "") << endl;

    return os;
}

/* *
 * @brief Cộng hai đa thức
 * @param rhs
 * @return cDaThuc
 * */
cDaThuc cDaThuc::operator+(cDaThuc const &rhs) const {
    int maxBac{mBac > rhs.mBac ? mBac : rhs.mBac};
    cDaThuc res{maxBac};

    for (int i{0}; i <= maxBac; i++)
        res.mHeSo[i] =
            (mBac >= i ? mHeSo[i] : 0) + (rhs.mBac >= i ? rhs.mHeSo[i] : 0);

    return res;
}

/* *
 * @brief Trừ hai đa thức
 * @param rhs
 * @return cDaThuc
 * */
cDaThuc cDaThuc::operator-(cDaThuc const &rhs) const {
    int maxBac{mBac > rhs.mBac ? mBac : rhs.mBac};
    cDaThuc res{maxBac};

    for (int i{0}; i <= maxBac; i++)
        res.mHeSo[i] =
            (mBac >= i ? mHeSo[i] : 0) - (rhs.mBac >= i ? rhs.mHeSo[i] : 0);

    return res;
}
