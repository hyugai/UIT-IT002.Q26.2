#pragma once
#include "HoTen.h"
#include "MaDinhDanh.h"
#include "SoDienThoai.h"
#include "Email.h"
#include <istream>
#include <iostream>
#include <ostream>
#include <string>

class NhanVien {
  protected:
    string mMaNhanVien;
    HoTen mHoTen;
    int mTuoi;
    SoDienThoai mSoDienThoai;
    Email mEmail;
    double mLuongCoBan, mLuong;

  public:
    virtual ~NhanVien() = default;
    friend istream &operator>>(istream &, NhanVien &);
    friend ostream &operator<<(ostream &, NhanVien const &);
    double getLuong() const;
    virtual void calcLuong() = 0;
};
