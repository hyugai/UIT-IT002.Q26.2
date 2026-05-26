#pragma once
#include "KhachHang.h"

using namespace std;

class KHLoaiC : public KhachHang {
  public:
    ~KHLoaiC();
    friend istream &operator>>(istream &, KHLoaiC &);
    friend ostream &operator<<(ostream &, KHLoaiC const &);
    void calcThanhTien() override;
};
