#include "cNgayThangNam.h"
#include <string>

using namespace std;

class cNhanVienSX {
    int mId, mSoSanPhamDaGiaCong;
    string mHoTen;
    cNgayThangNam mNgaySinh;
    double mGiaMotSanPham;

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
    void setNgaySinh(cNgayThangNam);
    void setGiaMotSanPham(const double &);

    void nhap();
    void xuat() const;
    double calcLuong() const;
};
