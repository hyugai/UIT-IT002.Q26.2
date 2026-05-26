#pragma once
#include "NVLapTrinh.h"
#include "NVKiemChung.h"
#include <istream>
#include <ostream>

class DanhSachNV {
    int mLapTrinhCount, mKiemChungCount;
    NVLapTrinh *mpLapTrinh{nullptr};
    NVKiemChung *mpKiemChung{nullptr};

  public:
    ~DanhSachNV();
    friend istream &operator>>(istream &, DanhSachNV &);
    friend ostream &operator<<(ostream &, DanhSachNV const &);
    void calcLuong();
    void findNVLuongThapHonTrungBinh(ostream &) const;
    void findNVMaxLuong(ostream &) const;
    void findNVMinLuong(ostream &) const;
    NVLapTrinh findNVLapTrinhMaxLuong() const;
    NVKiemChung findNVKiemChungMinLuong() const;
};
