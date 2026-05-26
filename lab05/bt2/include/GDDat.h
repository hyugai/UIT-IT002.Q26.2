#pragma once
#include "GiaoDich.h"
#include <istream>
#include <ostream>

enum class LoaiDat { A, B, C };

class GDDat : public GiaoDich {
    LoaiDat mLoaiDat;

  public:
    ~GDDat();
    friend istream &operator>>(istream &, GDDat &);
    friend ostream &operator<<(ostream &, GDDat const &);

    void calcThanhTien() override;
};
