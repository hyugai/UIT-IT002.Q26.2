#include "../include/triangle.hpp"
#include <iostream>

using namespace std;

int main() {
    cTamGiac tri;
    tri.nhap();

    cout << "\n===== Tam giac ABC =====";
    tri.xuat();

    cout << "\n===== Tinh tien =====\n";
    cTamGiac translatedTri{tri.tinhTien()};
    translatedTri.getDangTamGiac();
    translatedTri.xuat();

    cout << "\n===== Quay tam O =====\n";
    cTamGiac rotatedTri{tri.quay()};
    rotatedTri.getDangTamGiac();
    rotatedTri.xuat();

    cout << "\n===== Phong to =====\n";
    cTamGiac scaledUpTri{tri.phongTo()};
    scaledUpTri.getDangTamGiac();
    scaledUpTri.xuat();

    cout << "\n===== Thu nho =====\n";
    cTamGiac scaledDownTri{tri.thuNho()};
    scaledDownTri.getDangTamGiac();
    scaledDownTri.xuat();

    return 0;
}
