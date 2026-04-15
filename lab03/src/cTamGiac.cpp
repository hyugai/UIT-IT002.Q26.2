#include "../include/cTamGiac.hpp"
#include <cmath>
#include <iostream>

using namespace std;

cTamGiac::~cTamGiac() {
    if (!ds) {
        delete[] ds;
    }
}

void cTamGiac::Nhap() {
    cDiem *ds = new cDiem[3];

    cout << "Nhap diem A:\n";
    ds[0].Nhap();

    cout << "Nhap diem B:\n";
    ds[1].Nhap();

    do {
        cout << "Nhap diem B:\n";
        ds[2].Nhap();
    } while (!isValidTriangle(ds));
    cout << "Tam giac hop le!";
}

void cTamGiac::Xuat() {
    // cout << "Tam giac ABC la tam giac " << getTriangleType(ds) << endl;
}

LoaiTamGiac getTriangleType(cDiem const *ds) {
    LoaiTamGiac kq{isEquilateralTriangle(ds) ? LoaiTamGiac::Deu
                                             : LoaiTamGiac::Thuong};

    return kq;
}

double calDist(const cDiem &p1, const cDiem &p2) {
    double kq;
    kq = sqrt(pow(p2.getX() - p1.getX(), 2) + pow(p2.getY() - p1.getY(), 2));

    return kq;
}

bool isValidTriangle(const cDiem *ds) {
    bool kq{true};
    double d1{calDist(ds[0], ds[1])};
    double d2{calDist(ds[0], ds[2])};
    double d3{calDist(ds[1], ds[2])};

    kq = (d1 + d2 > d3) && (d2 + d3 > d1) && (d2 + d3 > d1);

    return kq;
}
