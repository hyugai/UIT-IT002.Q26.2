#pragma once
#include "MaDinhDanh.h"
#include "HoTen.h"
#include <istream>
#include <ostream>
#include <string>

using namespace std;

class SinhVien {
  protected:
    // MaDinhDanh mId;
    string mId;
    HoTen mHoTen;
    // string mHoTen;
    string mDiaChi;
    int mTinChiCount;
    double mDiemTrungBinh;

  public:
    virtual ~SinhVien() = default;
    friend istream &operator>>(istream &, SinhVien &);
    friend ostream &operator<<(ostream &, SinhVien const &);
    double getDiemTrungBinh() const;
    virtual bool isTotNghiep() const = 0;
};
