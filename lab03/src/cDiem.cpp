#include "../include/cDiem.h"
#include <cmath>
#include <iostream>

using namespace std;

// Defaulted Constructor
cDiem::cDiem() {}

// Member Initializer List: Khởi tạo 1 điểm với hoành độ (x), tung độ (y)
cDiem::cDiem(double x, double y) : mX(x), mY(y) {}

// Copy Constructor: Khởi tạo 1 điểm bằng 1 điểm khác
cDiem::cDiem(cDiem const &p) : mX(p.mX), mY(p.mY) {}

// Trả về hoành độ
double cDiem::getX() const { return mX; }

// Trả về tung độ
double cDiem::getY() const { return mY; }

/* *
 * @brief Nhập vào hoành độ và tung độ cho điểm
 * return void
 * */
void cDiem::nhap() {
    cout << "Nhap hoanh do x: ";
    cin >> mX;
    cout << "Nhap tung do y: ";
    cin >> mY;
}

/* *
 * @brief Tính khoảng cách giữa 2 điểm
 * @param p1 Điểm đầu vector
 * @param p1 Điểm cuối vector
 * @return double Khoảng cách 2 điểm (hay độ dài của vector)
 * */
double cDiem::calcKhoangCachToiDiem(const cDiem &p1, const cDiem &p2) {
    return sqrt(pow(p2.mX - p1.mX, 2) + pow(p2.mY - p1.mY, 2));
}

/* *
 * @brief Tịnh tiến điểm theo 1 vector
 * @param x_vec Hoành độ của vector
 * @param y_vec Tung độ của vector
 * @return cDiem Điểm mới sau khi tịnh tiến
 * */
cDiem cDiem::tinhTien(cDiem const &v) const {
    return cDiem{mX + v.mX, mY + v.mY};
}

/* *
 * @brief Thực hiện phép quay tâm 0 theo một góc radian
 * @param rad Số đo góc tính bằng radian
 * @return cDiem Điểm mới sau khi quay
 * */
cDiem cDiem::quay(double rad) const {
    double newX{mX * cos(rad) - mY * sin(rad)};
    double newY{mX * sin(rad) + mY * cos(rad)};

    return cDiem{newX, newY};
}

/* *
 * @brief Thực hiện phép thu/phóng k lần
 * @param k Hệ số thu phóng
 * @return cDiem Điểm mới sau khi thu/phóng
 * */
cDiem cDiem::thuPhong(double k) const { return cDiem{mX * k, mY * k}; }

/* *
 * @brief Overload toán tử == để so sánh 2 điểm có giống nhau không
 * @param p Điểm cần so sánh
 * @return bool 1(Trùng nhau), 0(Khác nhau)
 * */
bool cDiem::operator==(cDiem const &p) const {
    bool res{true};
    if (this->mX != p.mX || this->mY != p.mY) {
        res = false;
    }

    return res;
}

/* *
 * @brief Tính vector từ 2 điểm
 * @param head Điểm đầu của vector
 * @param tail Điểm cuối của vector
 * @return cDiem Trả về một "điểm" chứa tọa độ của vector
 * */
cDiem operator-(cDiem const &head, cDiem const &tail) {
    return cDiem{tail.mX - head.mX, tail.mY - head.mY};
}
