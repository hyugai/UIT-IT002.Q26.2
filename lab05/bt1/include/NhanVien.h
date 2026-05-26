#pragma once
#include "Date.h"
#include "HoTen.h"
#include <istream>
#include <ostream>
#include <string>

using namespace std;

class NhanVien {
  protected:
    HoTen mHoTen;
    Date mNgaySinh;
    double mLuong;

  public:
    virtual ~NhanVien() = default;

    double getLuong() const;
    Date getNgaySinh() const;

    friend istream &operator>>(istream &, NhanVien &);
    friend ostream &operator<<(ostream &, NhanVien const &);
    virtual void calcLuong() = 0;
};
