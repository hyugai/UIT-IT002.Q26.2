#pragma once

struct Date {
    void Nhap();
    void Xuat();
    Date NgayThangNamTiepTheo(const Date &);

  private:
    int iNgay, iThang, iNam;
};

int NgayTrongThang();
bool KiemTraNgay(const int &);
