#pragma once
#include "SinhVien.h"
#include <istream>
#include <ostream>

class SVDaiHoc : public SinhVien {
    string mTenLuanVan;
    double mDiemLuanVan;

  public:
    ~SVDaiHoc();
    friend istream &operator>>(istream &, SVDaiHoc &);
    friend ostream &operator<<(ostream &, SVDaiHoc const &);
    bool isTotNghiep() const override;
};
