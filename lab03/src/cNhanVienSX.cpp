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

// Trả về ID
int cNhanVienSX::getId() const { return mId; }

// Trả về số sản phẩm đã gia công
int cNhanVienSX::getSoSanPhamDaGiaCong() const { return mSoSanPhamDaGiaCong; }

// Trả về họ và tên
string cNhanVienSX::getHoTen() const { return mHoTen; }

// Trả về ngày sinh
cNgayThangNam cNhanVienSX::getNgaySinh() const { return mNgaySinh; }

// Trả về giá một sản phẩm
double cNhanVienSX::getGiaMotSanPham() const { return mGiaMotSanPham; }

// Thiết lập giá trị ID
void cNhanVienSX::setId(int const &id) { mId = id; }

// Thiết lập số sản phẩm đã gia công
void cNhanVienSX::setSoSanPhamDaGiaCong(int const &soSanPhamGiaCong) {
    mSoSanPhamDaGiaCong = soSanPhamGiaCong;
}

// Thiết lập họ và tên
void cNhanVienSX::setHoTen(string const &hoTen) { mHoTen = hoTen; }

// Thiết lập ngày sinh
void cNhanVienSX::setNgaySinh(cNgayThangNam ngaySinh) { mNgaySinh = ngaySinh; }

// Thiết lập giá một sản phẩm
void cNhanVienSX::setGiaMotSanPham(double const &giaMotSanPham) {
    mGiaMotSanPham = giaMotSanPham;
}

/* *
 * @brief Nhập vào thông tin nhân viên
 * @return void
 * */
void cNhanVienSX::nhap() {
    cout << "Nhap ID: ";
    cin >> mId;

    cin.ignore();
    do {
        cout << "Nhap ho ten: ";
        getline(cin, mHoTen);
    } while (mHoTen.length() == 0);

    cout << "Nhap ngay sinh:\n";
    mNgaySinh.nhap();

    cout << "Nhap so san pham da gia cong: ";
    cin >> mSoSanPhamDaGiaCong;

    do {
        cout << "Nhap don gia mot san pham (lon hon 0): ";
        cin >> mGiaMotSanPham;
    } while (mGiaMotSanPham <= 0);
}

/* *
 * @brief Xuất ra màn hình các thông tin của nhân viên
 * @return void
 * */
void cNhanVienSX::xuat() const {
    // cout << "ID cua nhan vien: " << mId << endl;

    // cout << "Ho va ten: " << mHoTen << endl;

    // cout << "Ngay sinh: ";
    // mNgaySinh.xuat();
    // cout << endl;

    // cout << "So san pham da gia cong: " << mSoSanPhamDaGiaCong << endl;

    // cout << "Gia mot san pham: " << mGiaMotSanPham << endl;

    cout << mId << '\t' << mHoTen << "\t\t";
    mNgaySinh.xuat();
    cout << '\t' << mSoSanPhamDaGiaCong << "\t\t" << mGiaMotSanPham << endl;
}

/* *
 * @brief Tính lương của nhân viên bằng cách nhân số sản phẩm đã gia công với
 * đơn giá một sản phẩm
 *
 * @return double Tiền lương của nhân viên
 * */
double cNhanVienSX::calcLuong() const {
    return mSoSanPhamDaGiaCong * mGiaMotSanPham;
}
