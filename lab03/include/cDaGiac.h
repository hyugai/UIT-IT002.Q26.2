#pragma once
#include "cDiem.h"

class cDaGiac {
    int mSoDiem;
    cDiem *mpDiem{nullptr};

  public:
    cDaGiac();
    cDaGiac(int, cDiem * = nullptr);
    ~cDaGiac();

    cDiem const *getpDiem() const;

    void nhap();
    void xuat() const;
    double getChuVi() const;
    double getDienTich() const;
    cDaGiac tinhTien() const;
    cDaGiac quay() const;
    cDaGiac phongTo() const;
    cDaGiac thuNho() const;
};

bool isDiemHopLe(cDiem const *, int const &);
