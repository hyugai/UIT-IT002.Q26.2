#pragma once

class cNgayThangNam {
    int mNgay, mThang, mNam;

  public:
    int getNgay() const;
    int getThang() const;
    int getNam() const;

    void nhap();
    void xuat() const;
    int compareTuoi(cNgayThangNam const &) const;
    int countSoNgayTrongThang() const;
    bool isNamNhuan() const;
};
