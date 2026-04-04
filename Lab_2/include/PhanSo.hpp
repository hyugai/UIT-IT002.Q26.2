#pragma once

struct PhanSo {
    void Nhap();
    void Xuat();

    PhanSo RutGon();
    PhanSo Tong();
    PhanSo Hieu();
    PhanSo Tich();
    PhanSo Thuong();

    int SoSanh();

  private:
    int iTu;
    int iMau;
};
