#include "../include/cListNhanVienSX.h"
#include <iostream>

using namespace std;

int main() {
    cListNhanVienSX danhSach;

    cout << "===== Nhap danh sach nhan vien =====\n";
    danhSach.nhap();

    cout << "===== Xuat danh sach nhan vien =====\n";
    danhSach.xuat();

    // cout << "===== Nhan vien co luong thap nhat =====\n";
    // cNhanVienSX nv{danhSach.findNhanVienLuongThapNhat()};
    // nv.xuat();

    // cout << "===== Tong luong cong ty phai tra cho nhan vien san xuat
    // =====\n"; cout << danhSach.calcTongLuong() << endl;

    return 0;
}
