#pragma once
#include "SinhVien.h"
#include <istream>
#include <ostream>

class SVCaoDang : public SinhVien {
    double mDiemThiTotNghiep;

  public:
    ~SVCaoDang();
    friend istream &operator>>(istream &, SVCaoDang &);
    friend ostream &operator<<(ostream &, SVCaoDang const &);
    bool isTotNghiep() const override;
};
