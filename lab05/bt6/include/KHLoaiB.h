#pragma once
#include "KhachHang.h"

using namespace std;

class KHLoaiB : public KhachHang {
    int mNamThanThietCount;
    double mKhuyenMaiPercentage;

  public:
    ~KHLoaiB();
    friend istream &operator>>(istream &, KHLoaiB &);
    friend ostream &operator<<(ostream &, KHLoaiB const &);
    void calcThanhTien() override;
};
