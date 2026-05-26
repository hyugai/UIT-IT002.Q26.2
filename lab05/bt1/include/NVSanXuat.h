#pragma once
#include "NhanVien.h"
#include <istream>
#include <ostream>

class NVSanXuat : public NhanVien {
    double mLuongCanBan, mSoSanPham;

  public:
    ~NVSanXuat();

    friend istream &operator>>(istream &, NVSanXuat &);
    friend ostream &operator<<(ostream &, NVSanXuat const &);
    void calcLuong() override;
};
