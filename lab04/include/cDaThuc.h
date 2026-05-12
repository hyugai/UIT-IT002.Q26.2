#pragma once
#include <istream>
#include <ostream>
using namespace std;

class cDaThuc {
    int mBac{0};
    double *mHeSo{nullptr};

  public:
    cDaThuc(int = 0);
    ~cDaThuc();

    friend istream &operator>>(istream &, cDaThuc &);
    friend ostream &operator<<(ostream &, cDaThuc const &);
    cDaThuc operator+(cDaThuc const &) const;
    cDaThuc operator-(cDaThuc const &) const;
    cDaThuc operator*(cDaThuc const &) const;
};
