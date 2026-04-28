#include "../include/cListNhanVienSX.h"
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
    cListNhanVienSX danhSach;

    cout << "===== Nhap danh sach nhan vien =====\n";
    danhSach.nhap();

    cout << "===== Xuat danh sach nhan vien =====\n";
    danhSach.xuat();

    cout << "\n===== Nhan vien co luong thap nhat =====\n";
    cNhanVienSX nv{danhSach.findNhanVienLuongThapNhat()};
    nv.xuat();

    cout << "\n===== Tong luong cong ty phai tra =====\n";
    cout << setprecision(3) << danhSach.calcTongLuong() << endl;

    cout << "\n===== Nhan vien cao tuoi nhat =====\n";
    nv = danhSach.findNhanVienCaoTuoiNhat();
    nv.xuat();

    cout << "\n===== Sap xep danh sach theo luong =====\n";
    danhSach.sortNhanVienTheoLuong();
    danhSach.xuat();

    return 0;
}
