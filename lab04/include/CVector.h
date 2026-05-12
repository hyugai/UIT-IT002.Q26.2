#pragma once
#include <istream>
#include <ostream>

using namespace std;

class CVector {
    int mSoChieu;
    double *mToaDo{nullptr};

  public:
    CVector(int = 1);
    ~CVector();

    int getSoChieu() const;
    double *getToaDo() const;

    friend istream &operator>>(istream &, CVector &);
    friend ostream &operator<<(ostream &, CVector const &);
    CVector operator+(CVector const &) const;
    CVector operator-(CVector const &) const;
    int operator*(CVector const &) const;
};
