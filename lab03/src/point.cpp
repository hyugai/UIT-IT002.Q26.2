#include "../include/point.hpp"
#include <cmath>
#include <iostream>

using namespace std;

// Defaulted Constructor
Point::Point() {}

// Member Initializer List: Khởi tạo 1 điểm với hoành độ (x), tung độ (y)
Point::Point(double x, double y) : x(x), y(y) {}

// Copy Constructor: Khởi tạo 1 điểm bằng 1 điểm khác
Point::Point(Point const &p) : x(p.x), y(p.y) {}

// Trả về hoành độ
double Point::getX() const { return x; }

// Trả về tung độ
double Point::getY() const { return y; }

/* *
 * @brief Nhập vào hoành độ và tung độ cho điểm
 * return void
 * */
void Point::input() {
    cout << "Nhap hoanh do x: ";
    cin >> x;
    cout << "Nhap tung do y: ";
    cin >> y;
}

/* *
 * @brief Tính khoảng cách giữa 2 điểm
 * @param p1 Điểm đầu vector
 * @param p1 Điểm cuối vector
 * @return double Khoảng cách 2 điểm (hay độ dài của vector)
 * */
double Point::calcDistanceTo(const Point &p1, const Point &p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

/* *
 * @brief Tịnh tiến điểm theo 1 vector
 * @param x_vec Hoành độ của vector
 * @param y_vec Tung độ của vector
 * @return Point Điểm mới sau khi tịnh tiến
 * */
Point Point::translate(Point const &v) const { return Point{x + v.x, y + v.y}; }

/* *
 * @brief Thực hiện phép quay tâm 0 theo một góc radian
 * @param rad Số đo góc tính bằng radian
 * @return Point Điểm mới sau khi quay
 * */
Point Point::rotate(double rad) const {
    double new_x{x * cos(rad) - y * sin(rad)};
    double new_y{x * sin(rad) + y * cos(rad)};

    return Point{new_x, new_y};
}

/* *
 * @brief Thực hiện phép thu/phóng k lần
 * @param k Hệ số thu phóng
 * @return Point Điểm mới sau khi thu/phóng
 * */
Point Point::scale(double k) const { return Point{x * k, y * k}; }

/* *
 * @brief Overload toán tử == để so sánh 2 điểm có giống nhau không
 * @param p Điểm cần so sánh
 * @return bool 1(Trùng nhau), 0(Khác nhau)
 * */
bool Point::operator==(Point const &p) const {
    bool res{true};
    if (this->x != p.x || this->y != p.y) {
        res = false;
    }

    return res;
}

/* *
 * @brief Tính vector từ 2 điểm
 * @param head Điểm đầu của vector
 * @param tail Điểm cuối của vector
 * @return Point Trả về một "điểm" chứa tọa độ của vector
 * */
Point operator-(Point const &head, Point const &tail) {
    return Point{tail.x - head.x, tail.y - head.y};
}
