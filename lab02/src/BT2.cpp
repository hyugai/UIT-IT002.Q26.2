#include "../include/PhanSo.hpp"
#include <iostream>

using namespace std;

int main() {
    /* Nhập phân số A */
    cout << "Nhap phan so A:\n";
    PhanSo a;
    a.Nhap();
    a.RutGon();

    /* Nhập phân số B */
    cout << "Nhap phan so B:\n";
    PhanSo b;
    b.Nhap();
    b.RutGon();

    /* Xuất ra A,B */
    cout << "\nPhan so A: ";
    a.Xuat();
    cout << "Phan so B: ";
    b.Xuat();

    /* Tính toán */
    cout << "\nTong A+B: ";
    PhanSo tong{a.Tong(b)};
    tong.Xuat();

    cout << "Hieu A-B: ";
    PhanSo hieu{a.Hieu(b)};
    hieu.Xuat();

    cout << "Tich A.B: ";
    PhanSo tich{a.Tich(b)};
    tich.Xuat();

    cout << "Thuong A/B: ";
    PhanSo thuong{a.Thuong(b)};
    thuong.Xuat();

    /* So sánh */
    cout << "So sanh A,B: ";
    int kqSoSanh{a.SoSanh(b)};
    if (kqSoSanh == 1) {
        cout << "A > B";
    } else if (kqSoSanh == -1) {
        cout << "A < B";
    } else {
        cout << "A = B";
    }

    cout << endl;
    return 0;
}
