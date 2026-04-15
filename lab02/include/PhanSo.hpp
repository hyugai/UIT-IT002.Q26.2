#pragma once

struct PhanSo {
    void Nhap();
    void Xuat();
    void RutGon();

    PhanSo Tong(PhanSo const &);
    PhanSo Hieu(PhanSo const &);
    PhanSo Tich(PhanSo const &);
    PhanSo Thuong(PhanSo const &);

    int SoSanh(PhanSo const &);

  private:
    int iTu;
    int iMau;
};
