#pragma once
#include "KhachHang.h"

using namespace std;

class KHLoaiA : public KhachHang {
  public:
    ~KHLoaiA();
    friend istream &operator>>(istream &, KHLoaiA &);
    friend ostream &operator<<(ostream &, KHLoaiA const &);
    void calcThanhTien() override;
};
