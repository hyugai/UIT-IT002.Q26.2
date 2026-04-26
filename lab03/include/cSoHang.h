#pragma once
class cSoHang {
    int mBac;
    double mHeSo;

  public:
    cSoHang();
    cSoHang(int, double);
    cSoHang(const cSoHang &);

    int getBac() const;
    double getHeSo() const;

    void nhap();
    void xuat() const;
    void xuatSoHangDauTien() const;
    double calcSoHang(double const &) const;
};
