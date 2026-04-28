#pragma once
#include "cNgayThangNam.h"
#include <cctype>
#include <string>

using namespace std;

class cNhanVienSX {
    int mId, mSoSanPhamDaGiaCong;
    string mHoTen;
    cNgayThangNam mNgaySinh;
    double mGiaMotSanPham;

    /*
     * @brief Kiểm tra mã ID có đủ 5 số và chỉ chứa số nguyên
     * @return bool true(Hợp lê), fasle(Ngược lại)
     * */
    bool isIdHopLe(const string &s) const {
        for (int c : s) {
            if (c < '0' || c > '9')
                return false;
        }
        if (s.length() != 5)
            return false;

        return true;
    }

    /*
     * @brief Kiểm tra xem tên có chứa kí tự đặc biệt hoặc số không
     * @return bool true(Hợp lệ), false(Ngược lại)
     * */
    bool isHoTenHopLe(const string &s) const {
        for (int c : s) {
            int lowered_c{tolower(c)};
            if (lowered_c < 'a' || lowered_c > 'z')
                if (lowered_c != ' ')
                    return false;
        }

        return true;
    }

  public:
    cNhanVienSX();
    cNhanVienSX(int, int, string, cNgayThangNam, double);

    int getId() const;
    int getSoSanPhamDaGiaCong() const;
    string getHoTen() const;
    cNgayThangNam getNgaySinh() const;
    double getGiaMotSanPham() const;

    void setId(const int &);
    void setSoSanPhamDaGiaCong(const int &);
    void setHoTen(const string &);
    void setNgaySinh(cNgayThangNam const &);
    void setGiaMotSanPham(const double &);

    void nhap();
    void xuat() const;
    double calcLuong() const;
};
