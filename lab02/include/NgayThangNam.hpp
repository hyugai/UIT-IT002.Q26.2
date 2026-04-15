#pragma once

struct NgayThangNam {
    void Nhap();
    void Xuat();
    NgayThangNam NgayThangNamTiepTheo();

  private:
    int iNgay, iThang, iNam;
};

int GetSoNgay(const int &, const int &);
bool KiemTraNamNhuan(const int &);
bool KiemTraNam(const int &);
bool KiemTraThang(const int &);
bool KiemTraNgay(const int &, const int &, const int &);
