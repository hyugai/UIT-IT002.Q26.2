#include "../include/triangle.hpp"
#include "../include/line.hpp"
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

// Defaulted Constructor: Khởi tạo tam giác với 3 điểm "trống"
cTamGiac::cTamGiac() : points(3) {}

// Parameterized Constructor: Khởi tạo 1 tam giác với 3 điểm
cTamGiac::cTamGiac(Point const &p1, Point const &p2, Point const &p3) {
    points.clear();

    points.push_back(p1);
    points.push_back(p2);
    points.push_back(p3);
}

// Copy Constructor: Khởi tạo 1 tam giác là bản sao của 1 tam giác khác
cTamGiac::cTamGiac(cTamGiac const &tri) {
    for (int i{0}; i < MAX_SIDES; i++)
        points[i] = tri.points[i];
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
    double p{calcPerimeter() / 2.0};
    double s = sqrt(p * (p - sides_length[0]) * (p - sides_length[1]) *
                    (p - sides_length[2]));

    return s;
}
