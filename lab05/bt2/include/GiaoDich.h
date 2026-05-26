#pragma once

#include "Date.h"
#include "MaDinhDanh.h"
#include <istream>

class GiaoDich {
  protected:
    string mMaGD;
    Date mNgayGiaoDich;
    double mDienTich, mDonGia, mThanhTien;

  public:
    friend istream &operator>>(istream &, GiaoDich &);
    friend ostream &operator<<(ostream &, GiaoDich const &);
    virtual void calcThanhTien() = 0;
    double getThanhTien() const;
    Date getNgayGD() const;
};
