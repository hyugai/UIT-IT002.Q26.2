#pragma once
#include "NVSanXuat.h"
#include "NVVanPhong.h"
#include <istream>
#include <ostream>

using namespace std;

class DanhSachNV {
    int mSXCount, mVPCount;
    NVSanXuat *mpSX{nullptr};
    NVVanPhong *mpVP{nullptr};

  public:
    ~DanhSachNV();

    friend istream &operator>>(istream &, DanhSachNV &);
    friend ostream &operator<<(ostream &, DanhSachNV const &);
    void calcLuongNV();
    double calcTongLuongNV() const;
    NVSanXuat findMinLuongSX() const;
    NVVanPhong findMaxTuoiVP() const;
};
