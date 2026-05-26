#pragma once
#include "NhanVien.h"
#include <ostream>

class NVKiemChung : public NhanVien {
    int mLoiPhatHienCount;

  public:
    ~NVKiemChung();
    friend istream &operator>>(istream &, NVKiemChung &);
    friend ostream &operator<<(ostream &, NVKiemChung const &);
    void calcLuong() override;
};
