#include "../include/triangle.hpp"
#include "../include/line.hpp"
#include <cmath>
#include <cstddef>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

// Defaulted Constructor: Khởi tạo tam giác với 3 điểm "trống"
cTamGiac::cTamGiac() : points(3) {}

// Parameterized Constructor: Khởi tạo 1 tam giác với 3 điểm
cTamGiac::cTamGiac(vector<Point> ps) {
    for (auto p : ps) {
        points.push_back(p);
    }
}

// Copy Constructor: Khởi tạo 1 tam giác là bản sao của 1 tam giác khác
cTamGiac::cTamGiac(cTamGiac const &tri) {
    for (auto p : tri.points) {
        points.push_back(p);
    }
}

// Destructor
cTamGiac::~cTamGiac() {}

/* *
 * @brief Yêu cầu nhập vào 3 điểm đến khi thỏa mãn
 * @return void
 * */
void cTamGiac::input() {
    cout << "Nhap diem thu 1:\n";
    points[0].input();

    do {
        cout << "Nhap diem thu 2:\n";
        points[1].input();
    } while (points[0] == points[1]);

    do {
        cout << "Nhap diem thu 3:\n";
        points[2].input();
        identifyTriangleType();
    } while (type == TriangleType::Unknow);
}

/* *
 * @brief Xuất ra màn hình loại tam giác, độ dài 3 cạnh
 * @return void
 * */
void cTamGiac::output() const {
    switch (type) {
    case TriangleType::Regular:
        cout << "\nTam giac thuong\n";
        break;
    case TriangleType::Equilateral:
        cout << "\nTam giac deu\n";
        break;
    case TriangleType::Right:
        cout << "\nTam giac vuong\n";
        break;
    case TriangleType::Isosceles:
        cout << "\nTam giac can\n";
        break;
    case TriangleType::IsoscelesRight:
        cout << "\nTam giac vuong can\n";
        break;
    case TriangleType::Unknow:
        cout << "\nKhong phai tam giac\n";
        break;
    }
    cout << "Do dai: ";
    for (auto &e : sides_length) {
        cout << setprecision(3) << e << ' ';
    }
    cout << endl;

    cout << "Chu vi: " << setprecision(4) << calcPerimeter() << endl;
    cout << "Dien tich: " << setprecision(4) << calcArea() << endl;
}

/* *
 * @brief Kiểm tra và xác định loại tam giác
 * @return void
 * */
void cTamGiac::identifyTriangleType() {
    Line l01{points[0], points[1]};
    if (!l01.isPointOnLine(points[2])) {
        type = TriangleType::Unknow;
        return; // Không phải tam giác
    }

    sides_length.clear();
    calcCombination(Point::calcDistanceTo, points, sides_length, MAX_SIDES);
    bubbleSort(sides_length);

    vector<short> is_equal; // Các cặp cạnh có bằng nhau không
    calcCombination([&](auto x, auto y) { return (fabs(x - y) < EPS ? 1 : 0); },
                    sides_length, is_equal, MAX_SIDES);
    is_equal[0] += is_equal[1] + is_equal[2];

    if (is_equal[0] == 3) { // 3 cạnh tam giác đều
        type = TriangleType::Equilateral;
        return;
    }

    bool is_right{(pow(sides_length[0], 2) + pow(sides_length[1], 2) -
                   pow(sides_length[2], 2)) < EPS
                      ? true
                      : false}; // Dùng pytago để xác định tam giác vuông

    if (is_right) {
        type = (is_equal[0] > 0 ? TriangleType::IsoscelesRight
                                : TriangleType::Right);
        return;
    }

    type = is_equal[0] > 0 ? TriangleType::Isosceles : TriangleType::Regular;
}

/* *
 * @brief Tính chu vi tam giác
 * @return void
 * */
double cTamGiac::calcPerimeter() const {
    return sides_length.at(0) + sides_length.at(1) + sides_length.at(2);
}

/* *
 * @brief Tính diện tích tam giác bằng công thức Heron
 * @return void
 * */
double cTamGiac::calcArea() const {
    double half_p{calcPerimeter() / 2.0};
    double s = sqrt(half_p * (half_p - sides_length[0]) *
                    (half_p - sides_length[1]) * (half_p - sides_length[2]));

    return s;
}

/* *
 * @brief Tịnh tiến tam giác theo 1 vector v
 * @return cTamGiac Trả về một tam giác mới sau khi tịnh tiến
 * */
cTamGiac cTamGiac::translate() const {
    cout << "Nhap vector tinh tien:\n";
    Point v;
    v.input();

    cTamGiac new_tri;
    for (size_t i{0}; i < MAX_SIDES; i++)
        new_tri.points[i] = points[i].translate(v);

    return new_tri;
}

/* *
 * @brief Quay tam giác theo một góc radian
 * @return cTamGiac Trả về một tam giác mới sau khi quay
 * */
cTamGiac cTamGiac::rotate() const {
    double rad;
    cout << "Nhap goc quay (radian): ";
    cin >> rad;

    cTamGiac new_tri;
    for (size_t i{0}; i < MAX_SIDES; i++)
        new_tri.points[i] = points[i].rotate(rad);

    return new_tri;
}

/* *
 * @brief Phong to tam giac k lan
 * @return cTamGiac Trả về một tam giác mới sau khi phong to
 * */
cTamGiac cTamGiac::scaleUp() const {
    double k;
    do {
        cout << "Nhap he so phong to (lon hon 1): ";
        cin >> k;
    } while (k <= 1);

    cTamGiac new_tri;
    for (size_t i{0}; i < MAX_SIDES; i++)
        new_tri.points[i] = points[i].scale(k);

    return new_tri;
}

/* *
 * @brief Thu nho tam giac k lan
 * @return cTamGiac Trả về một tam giác mới sau khi thu nho
 * */
cTamGiac cTamGiac::scaleDown() const {
    double k;
    do {
        cout << "Nhap he so phong to (lon hon 1): ";
        cin >> k;
    } while (k >= 1);

    cTamGiac new_tri;
    for (size_t i{0}; i < MAX_SIDES; i++)
        new_tri.points[i] = points[i].scale(k);

    return new_tri;
}
