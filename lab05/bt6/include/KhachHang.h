#pragma once
#include "HoTen.h"
#include <istream>
#include <ostream>

using namespace std;

class KhachHang {
  protected:
    static constexpr double VAT = 0.1;
    HoTen mHoTen;
    int mHangCount;
    double mDonGia, mThanhTien;

  public:
    virtual ~KhachHang() = default;
    friend istream &operator>>(istream &, KhachHang &);
    friend ostream &operator<<(ostream &, KhachHang const &);
    virtual void calcThanhTien() = 0;
};
