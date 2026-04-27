#include "../include/cNhanVienSX.h"
#include <iostream>
#include <string>

using namespace std;

// Defaulted Constructor
cNhanVienSX::cNhanVienSX() {}

// List Initializer
cNhanVienSX::cNhanVienSX(int id, int soSanPhamGiaCong, string hoTen,
                         cNgayThangNam ngaySinh, double giaMotSanPham)
    : mId(id), mSoSanPhamDaGiaCong(soSanPhamGiaCong), mHoTen(hoTen),
      mNgaySinh(ngaySinh), mGiaMotSanPham(giaMotSanPham) {}

//
int cNhanVienSX::getId() const { return mId; }
//
int cNhanVienSX::getSoSanPhamDaGiaCong() const { return mSoSanPhamDaGiaCong; }
//
string cNhanVienSX::getHoTen() const { return mHoTen; }
//
cNgayThangNam cNhanVienSX::getNgaySinh() const { return mNgaySinh; }
//
double cNhanVienSX::getGiaMotSanPham() const { return mGiaMotSanPham; }

//
void cNhanVienSX::setId(int const &id) { mId = id; }
//
void cNhanVienSX::setSoSanPhamDaGiaCong(int const &soSanPhamGiaCong) {
    mSoSanPhamDaGiaCong = soSanPhamGiaCong;
}
//
void cNhanVienSX::setHoTen(string const &hoTen) { mHoTen = hoTen; }
//
void cNhanVienSX::setNgaySinh(cNgayThangNam ngaySinh) { mNgaySinh = ngaySinh; }
//
void cNhanVienSX::setGiaMotSanPham(double const &giaMotSanPham) {
    mGiaMotSanPham = giaMotSanPham;
}

void cNhanVienSX::nhap() {
    cout << "Nhap ID: ";
    cin >> mId;

    cout << "Nhap ho ten:\n";
    getline(cin, mHoTen);

    cout << "Nhap ngay sinh: ";
    mNgaySinh.nhap();

    cout << "Nhap so san pham da gia cong: ";
    cin >> mSoSanPhamDaGiaCong;

    do {
        cout << "Nhap don gia mot san pham: ";
        cin >> mGiaMotSanPham;
    } while (mGiaMotSanPham <= 0);
}
