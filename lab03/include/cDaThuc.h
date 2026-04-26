#pragma once
#include "cSoHang.h"

class cDaThuc {
    int mBac;
    cSoHang *mpSoHang{nullptr};

  public:
    cDaThuc();
    cDaThuc(int);
    ~cDaThuc();

    void nhap();
    void xuat() const;
    void setBac(int const &);
    double calcDaThuc(double const &) const;
    cDaThuc addDaThuc(cDaThuc const &) const;
    cDaThuc subDaThuc(cDaThuc const &) const;
};
