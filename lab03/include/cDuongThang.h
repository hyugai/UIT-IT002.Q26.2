#pragma once
#include "cDiem.h"

class cDuongThang {
    double mHeSoX, mHeSoY, mHangSo;

  public:
    cDuongThang();
    cDuongThang(cDiem const &, cDiem const &);

    double getHeSoX() const;
    double getHeSoY() const;
    double getHangSo() const;

    int calcViTriDiem(cDiem const &) const;
};
