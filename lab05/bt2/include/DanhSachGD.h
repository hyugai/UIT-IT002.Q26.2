#pragma once

#include "GDDat.h"
#include "GDNhaPho.h"
#include "GDCanHoChungCu.h"
#include <istream>
#include <ostream>

using namespace std;

class DanhSachGD {
    int mDatCount, mNhaPhoCount, mCanHoChungCuCount;
    GDDat *mpDat{nullptr};
    GDNhaPho *mpNhaPho{nullptr};
    GDCanHoChungCu *mpCanHoChungCu{nullptr};

  public:
    ~DanhSachGD();

    int getDatCount() const;
    int getNhaPhoCount() const;
    int getCanHoChungCuCount() const;

    friend istream &operator>>(istream &, DanhSachGD &);
    friend ostream &operator<<(ostream &, DanhSachGD const &);
    friend ostream &operator<<(ostream &, DanhSachGD const &);
    void calcThanhTienGD();
    double calcAvgThanhTienCanHoChungCu() const;
    GDNhaPho findMaxThanhTienNhaPho() const;
    void findGD(int const &, int const &, ostream &) const;
};
