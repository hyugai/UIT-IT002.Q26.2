#include "../include/cDaGiac.h"
#include <iostream>

using namespace std;

int main() {
    cDaGiac poly;
    poly.nhap();

    cout << "\n===== Da Giac =====\n";
    poly.xuat();

    cout << "\n===== Tinh Tien =====\n";
    cDaGiac translatedPoly{poly.tinhTien()};
    translatedPoly.xuat();

    cout << "\n===== Quay =====\n";
    cDaGiac rotatedPoly{poly.quay()};
    rotatedPoly.xuat();

    cout << "\n===== Phong To =====\n";
    cDaGiac scaledUpPoly{poly.phongTo()};
    scaledUpPoly.xuat();

    cout << "\n===== Thu Nho =====\n";
    cDaGiac scaledDown{poly.thuNho()};
    scaledDown.xuat();

    return 0;
}
