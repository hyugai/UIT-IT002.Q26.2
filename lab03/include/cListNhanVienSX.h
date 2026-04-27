#pragma once
#include "cNhanVienSX.h"

class cListNhanVienSX {
    int mSoNhanVien;
    cNhanVienSX *mpNhanVienSX{nullptr};

  public:
    ~cListNhanVienSX();

    void nhap();
    void xuat() const;
    cNhanVienSX findNhanVienLuongThapNhat() const;
    double calcTongLuong() const;
    cNhanVienSX findNhanVienCaoTuoiNhat() const;
    void sortNhanVienTheoLuong();
};
