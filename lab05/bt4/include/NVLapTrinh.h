#pragma once
#include "NhanVien.h"
#include <ostream>

class NVLapTrinh : public NhanVien {
    double mOverTimeCount;

  public:
    ~NVLapTrinh();
    friend istream &operator>>(istream &, NVLapTrinh &);
    friend ostream &operator<<(ostream &, NVLapTrinh const &);
    void calcLuong() override;
};
