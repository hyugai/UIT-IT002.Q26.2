#pragma once
#include "CVector.h"
#include <istream>
#include <ostream>

using namespace std;

class CMatrix {
    int mSoDong, mSoCot;
    double **mPhanTu{nullptr};

    void cleanUpMem() {
        if (!mPhanTu)
            return;

        for (int i{0}; i < mSoDong; ++i)
            delete[] mPhanTu[i];

        delete[] mPhanTu;
        mPhanTu = nullptr;
    }

  public:
    CMatrix(int = 1, int = 1);
    ~CMatrix();

    int getSoDong() const;
    int getSoCot() const;

    friend istream &operator>>(istream &, CMatrix &);
    friend ostream &operator<<(ostream &, CMatrix const &);
    CMatrix operator+(CMatrix const &) const;
    CMatrix operator-(CMatrix const &) const;
    CMatrix operator*(CMatrix const &) const;
    CVector operator*(CVector const &) const;
};
