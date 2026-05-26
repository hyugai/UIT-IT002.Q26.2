#pragma once
#include "GiaoDich.h"
#include "MaDinhDanh.h"
#include <string>

class GDCanHoChungCu : public GiaoDich {
    // MaDinhDanh mMaCan;
    string mMaCan;
    int mViTriTang;

  public:
    ~GDCanHoChungCu();
    friend istream &operator>>(istream &, GDCanHoChungCu &);
    friend ostream &operator<<(ostream &, GDCanHoChungCu const &);
    void calcThanhTien() override;
};
