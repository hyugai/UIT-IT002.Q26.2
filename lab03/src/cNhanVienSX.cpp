#include "../include/cNhanVienSX.h"
#include <iomanip>
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
void cNhanVienSX::setNgaySinh(cNgayThangNam const &ngaySinh) {
    mNgaySinh = ngaySinh;
}

// Thiết lập giá một sản phẩm
void cNhanVienSX::setGiaMotSanPham(double const &giaMotSanPham) {
    mGiaMotSanPham = giaMotSanPham;
}

/* *
 * @brief Nhập vào thông tin nhân viên
 * @return void
 * */
void cNhanVienSX::nhap() {
    string inp;
    do {
        cout << "Nhap ma ID (5 so nguyen duong): ";
        cin >> inp;
    } while (!isIdHopLe(inp));
    mId = stoi(inp);

    cin.ignore();
    do {
        cout << "Nhap ho ten: ";
        getline(cin, inp);
    } while (!isHoTenHopLe(inp));
    mHoTen = inp;

    cout << "Nhap ngay sinh:\n";
    mNgaySinh.nhap();

    do {
        cout << "Nhap so san pham da gia cong (khong am): ";
        cin >> mSoSanPhamDaGiaCong;
    } while (mSoSanPhamDaGiaCong < 0);

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
    cout << mId << ", " << mHoTen << ", ";
    mNgaySinh.xuat();
    cout << ", " << setprecision(3) << fixed << mSoSanPhamDaGiaCong << ", "
         << fixed << mGiaMotSanPham << endl;
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
