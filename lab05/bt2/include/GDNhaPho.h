#pragma once
#include "GiaoDich.h"

enum class LoaiNha { CaoCap, Thuong };

class GDNhaPho : public GiaoDich {
    string mDiaChi;
    LoaiNha mLoaiNha;

  public:
    ~GDNhaPho();
    friend istream &operator>>(istream &, GDNhaPho &);
    friend ostream &operator<<(ostream &, GDNhaPho const &);
    void calcThanhTien() override;
};
