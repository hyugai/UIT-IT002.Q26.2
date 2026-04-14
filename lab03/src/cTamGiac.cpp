#include "../include/cTamGiac.hpp"
#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;

/* Defaulted constructor */
cDiem::cDiem() {}
/* Member initializer list */
cDiem::cDiem(double x, double y) : x(x), y(y) {}
/* Copy constructor */
cDiem::cDiem(cDiem const &o) : x(o.x), y(o.y) {}
/* Defaulted destructor */
cDiem::~cDiem() {}

/*
 * @brief Nhập tọa độ điểm trong mặt phẳng Oxy
 * @return void
 * */
void cDiem::Nhap() {
    cin.ignore();

    cout << "Nhap toa do x: ";
    cin >> this->x;
    cout << "Nhap toa do y: ";
    cin >> this->y;
}
/*
 * @brief Thực hiện phép tịnh tiến theo vector v
 * @param xVec Hoành độ của v
 * @param yVec Tung độ của v
 * @return 1 điểm mới
 * */
cDiem cDiem::TinhTien(double xVec, double yVec) {
    cDiem kq{this->x + xVec, this->y + yVec};

    return kq;
}
/*
 * @brief Thực hiện phép quay tâm O
 * @param rad Góc quay
 * @return 1 điểm mới
 * */
cDiem cDiem::Quay(double rad) {
    double new_x{this->x * cos(rad) - this->y * sin(rad)};
    double new_y{this->x * sin(rad) + this->y * cos(rad)};
    cDiem kq{new_x, new_y};

    return kq;
}
/*
 * @brief Thực hiện phép thu/phóng
 * @param k Hệ số thu/phóng
 * @return 1 điểm mới
 * */
cDiem cDiem::ThuPhong(double k) {
    cDiem kq{this->x * k, this->y * k};

    return kq;
}
