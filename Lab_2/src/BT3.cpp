#include "../include/SoPhuc.hpp"
#include <iostream>

using namespace std;

int main() {
    /* Nhập số phức A */
    SoPhuc a;
    cout << "Nhap so phuc A:\n";
    a.Nhap();

    /* Nhập số phức B */
    SoPhuc b;
    cout << "Nhap so phuc B:\n";
    b.Nhap();

    /* Xuất ra A,B */
    cout << "\nSo thuc A: ";
    a.Xuat();
    cout << "So thuc B: ";
    b.Xuat();

    /* Tính toán */
    cout << "\nTong A+B: ";
    SoPhuc tong{a.Tong(b)};
    tong.Xuat();

    cout << "Hieu A-B: ";
    SoPhuc hieu{a.Hieu(b)};
    hieu.Xuat();

    cout << "Tich A.B: ";
    SoPhuc tich{a.Tich(b)};
    tich.Xuat();

    cout << "Thuong A/B: ";
    SoPhuc thuong{a.Thuong(b)};
    thuong.Xuat();
}
